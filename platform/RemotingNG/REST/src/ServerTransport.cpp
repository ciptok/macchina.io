// Library: RemotingNG/REST
// Package: REST
// Module:  ServerTransport
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/ServerTransport.h"
#include "Poco/RemotingNG/REST/Listener.h"
#include "Poco/RemotingNG/ORB.h"
#include "Poco/RemotingNG/Context.h"
#include "Poco/StringTokenizer.h"


namespace Poco {
namespace RemotingNG {
namespace REST {


ServerTransport::ServerTransport(Poco::Net::HTTPServerRequest& httpServerRequest):
	_httpServerRequest(httpServerRequest),
	_logger(Poco::Logger::get("RemotingNG.REST.ServerTransport")),
	_pReplyStream(new std::ostringstream())
{
	const std::string& contentType = httpServerRequest.getContentType();
	if (contentType == "text/xml")
	{
		_deserializer = new XMLDeserializer();
		_serializer = new XMLSerializer(*_pReplyStream);
	}
	else
	{
		_deserializer = new ManualDeserializer();
		_serializer = new ManualSerializer();
	}

}

ServerTransport::~ServerTransport()
{
}

Deserializer& ServerTransport::beginRequest()
{
	if (_logger.debug())
	{
		_logger.debug("Beginning request...");
	}

	return *_deserializer;
}


Serializer& ServerTransport::sendReply(SerializerBase::MessageType messageType)
{
	if (_logger.debug())
	{
		_logger.debug("Sending reply...");
	}

	_serializer->setup(*_pReplyStream);

	return *_serializer;
}


void ServerTransport::endRequest()
{
	if (_logger.debug())
	{
		_logger.debug("Request done.");
	}
}


std::string ServerTransport::RunRequest()
{
	_deserializer->setup(_httpServerRequest.stream());

	// We need to call URI: protocol + endpoint + TypeId + ObjectId - separated by '/'
	// Everything more is part of URI template
	std::string path = Listener::PROTOCOL_HTTP;
	path += '/';
	path += _httpServerRequest.getHost();

	Poco::StringTokenizer tok(_httpServerRequest.getURI(), "/", Poco::StringTokenizer::TOK_IGNORE_EMPTY);
	if (tok.count() > 2)
	{
		path += "/";
		path += tok[0];
		path += "/";
		path += tok[1];

		for (int i = 2; i < tok.count(); ++i)
		{
			_uriPath += "/";
			_uriPath += tok[i];
		}
	}
	else
	{
		path += _httpServerRequest.getURI();
	}

	std::istreambuf_iterator<char> eos;
	std::string requestBody(std::istreambuf_iterator<char>(_httpServerRequest.stream()), eos);
	_method = _httpServerRequest.getMethod();

	Poco::RemotingNG::ScopedContext scopedContext;
	scopedContext.context()->setValue("path", _uriPath);
	scopedContext.context()->setValue("method", _method);
	scopedContext.context()->setValue("transport", Listener::PROTOCOL_HTTP);
	scopedContext.context()->setValue("remoteAddress", _httpServerRequest.clientAddress());
	scopedContext.context()->setValue("localAddress", _httpServerRequest.serverAddress());
	scopedContext.context()->setValue("requestbody", requestBody);

	Poco::RemotingNG::ORB& orb = Poco::RemotingNG::ORB::instance();

	if (_logger.debug())
	{
		_logger.debug("Dispatching request to service object: " + path);
	}

	bool serviceFound = orb.invoke(path, *this);
	if (!serviceFound)
	{
		_logger.error("Unknown service object: " + path);
		RemotingException exc("Unknown service");
		sendReply(Poco::RemotingNG::SerializerBase::MESSAGE_FAULT).serializeFaultMessage("fault", exc);
		endRequest();
	}

	return _pReplyStream->str();
}

SerializerBase::MessageType ServerTransport::findMessage(std::string& name)
{
	//TODO: Pass path and method in better way
	name = _uriPath + ";" + _method;
	return SerializerBase::MESSAGE_REQUEST;
}


} } } // namespace Poco::RemotingNG::REST

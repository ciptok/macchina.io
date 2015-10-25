// Library: RemotingNG/REST
// Package: REST
// Module:  Listener
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/Listener.h"
#include "Poco/RemotingNG/REST/RequestHandler.h"
#include "Poco/NumberFormatter.h"
#include "Poco/NumberParser.h"
#include <string>


namespace Poco {
namespace RemotingNG {
namespace REST {


const std::string Listener::PROTOCOL_HTTP = "http";

Listener::Listener(const std::string& endPoint, Poco::Net::HTTPServerParams::Ptr pParams)
  : Poco::RemotingNG::Listener(endPoint)
{
	UInt16 port = 80;

	size_t found = endPoint.find_last_of(':');
	if (found != std::string::npos)
	{
		port = NumberParser::parse(endPoint.substr(found + 1));
	}

	_pHTTPServer = new Poco::Net::HTTPServer(new RequestHandlerFactory(), port, pParams);
}

Listener::~Listener()
{

}

void Listener::start()
{
	_pHTTPServer->start();
}

void Listener::stop()
{
	_pHTTPServer->stop();
}

const std::string& Listener::protocol() const
{
	return PROTOCOL_HTTP;
}

std::string Listener::createURI(const Poco::RemotingNG::Identifiable::TypeId& typeId, const Poco::RemotingNG::Identifiable::ObjectId& objectId)
{
	std::string uri(protocol());
	uri += ("://");
	uri += endPoint();
	uri += '/';
	uri += typeId;
	uri += '/';
	uri += objectId;
	return uri;
}

bool Listener::handlesURI(const std::string& uri)
{
	return false;
}

void Listener::registerObject(Poco::RemotingNG::RemoteObject::Ptr pRemoteObject, Poco::RemotingNG::Skeleton::Ptr pSkeleton)
{

}

void Listener::unregisterObject(Poco::RemotingNG::RemoteObject::Ptr pRemoteObject)
{

}


} } } // namespace Poco::RemotingNG::REST

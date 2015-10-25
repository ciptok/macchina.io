//
// Skeleton.cpp
//
// $Id: //poco/1.6/RemotingNG/src/Skeleton.cpp#1 $
//
// Library: RemotingNG
// Package: ORB
// Module:  Skeleton
//
// Copyright (c) 2006-2014, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/Skeleton.h"
#include "Poco/RemotingNG/Serializer.h"
#include "Poco/RemotingNG/Deserializer.h"
#include "Poco/RemotingNG/MethodHandler.h"
#include "Poco/RemotingNG/ServerTransport.h"
#include "Poco/RemotingNG/RemotingException.h"
#include "Poco/RemotingNG/Context.h"
#include "Poco/StringTokenizer.h"
#include "Poco/String.h"


namespace Poco {
namespace RemotingNG {


Skeleton::Skeleton()
{
}


Skeleton::~Skeleton()
{
}


bool Skeleton::invoke(ServerTransport& transport, RemoteObject::Ptr pRemoteObject)
{
	bool result = true;
	Deserializer& deser = transport.beginRequest();
	std::string messageName, method;
	SerializerBase::MessageType messageType = transport.findMessage(messageName);
	if (messageType != SerializerBase::MESSAGE_REQUEST && messageType != SerializerBase::MESSAGE_EVENT)
		throw UnexpectedMessageException("request or event message expected");

	Skeleton::MethodHandlers::iterator it = _handlers.end();
	Skeleton::RESTMethodHandlers::iterator itR = _restHandlers.end();

	if (!messageName.empty() && messageName[0] == '/') // Handle REST request
	{
		std::string requestedPath;
		std::string requestedMethod;

		Poco::StringTokenizer tok(messageName, ";", Poco::StringTokenizer::TOK_IGNORE_EMPTY);
		if (tok.count() == 2)
		{
			requestedPath = tok[0];
			requestedMethod = tok[1];
		}

		//TODO: Handle comparing URI path properly
		for (itR = _restHandlers.begin(); itR != _restHandlers.end(); ++itR)
		{
			std::string method = itR->first.first;
			std::string path =  itR->first.second;

			if (Poco::icompare(requestedMethod, method))
			{
				continue;
			}

			if (requestedPath == path)
			{
				itR = itR;
				break;
			}
		}
	}
	else
	{
		it = _handlers.find(messageName);
	}

	if (it != _handlers.end())
	{
		it->second->invoke(transport, deser, pRemoteObject);
	}
	else if (itR != _restHandlers.end())
	{
		itR->second->invoke(transport, deser, pRemoteObject);
	}
	else
	{
		result = false;
		RemotingNG::Serializer& ser = transport.sendReply(SerializerBase::MESSAGE_FAULT);
		MethodNotFoundException exc(messageName);
		ser.serializeFaultMessage(messageName, exc);
	}
	transport.endRequest();
	return result;
}


void Skeleton::addMethodHandler(const std::string& name, MethodHandler::Ptr pMethodHandler)
{
	_handlers[name] = pMethodHandler;
}

void Skeleton::addMethodHandler(const std::string& method, const std::string& path, MethodHandler::Ptr pMethodHandler)
{
	_restHandlers[std::pair<std::string, std::string>(method, path)] = pMethodHandler;
}


} } // namespace Poco::RemotingNG

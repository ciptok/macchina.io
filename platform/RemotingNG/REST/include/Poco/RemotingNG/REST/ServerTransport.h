// Library: RemotingNG/REST
// Package: REST
// Module:  ServerTransport
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#ifndef RemotingNG_REST_ServerTransport_INCLUDED
#define RemotingNG_REST_ServerTransport_INCLUDED

#include "Poco/RemotingNG/REST/REST.h"
#include "Poco/RemotingNG/ServerTransport.h"
#include "Poco/RemotingNG/REST/XMLSerializer.h"
#include "Poco/RemotingNG/REST/XMLDeserializer.h"
#include "Poco/RemotingNG/REST/ManualDeserializer.h"
#include "Poco/RemotingNG/REST/ManualSerializer.h"
#include "Poco/InflatingStream.h"
#include "Poco/DeflatingStream.h"
#include "Poco/AutoPtr.h"
#include "Poco/SharedPtr.h"
#include "Poco/Logger.h"
#include "Poco/Net/HTTPServerRequest.h"
#include <sstream>


namespace Poco {
namespace RemotingNG {
namespace REST {


class Listener;


class RemotingNGREST_API ServerTransport: public Poco::RemotingNG::ServerTransport, public Poco::RefCountedObject
{
public:
	typedef Poco::AutoPtr<ServerTransport> Ptr;

	ServerTransport(Poco::Net::HTTPServerRequest& request);
	~ServerTransport();

	std::string RunRequest();

	// Poco::RemotingNG::ServerTransport
	Deserializer& beginRequest();
	Serializer& sendReply(SerializerBase::MessageType messageType);
	void endRequest();

	virtual SerializerBase::MessageType findMessage(std::string& name);

private:
	Poco::Net::HTTPServerRequest& _httpServerRequest;
	Poco::SharedPtr<std::ostringstream> _pReplyStream;
	Poco::SharedPtr<Deserializer> _deserializer;
	Poco::SharedPtr<Serializer> _serializer;
	Poco::Logger& _logger;

	std::string _uriPath;
	std::string _method;
};


} } } // namespace Poco::RemotingNG::REST


#endif // RemotingNG_REST_ServerTransport_INCLUDED

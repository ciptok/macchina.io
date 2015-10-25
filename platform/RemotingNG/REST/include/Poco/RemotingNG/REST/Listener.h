// Library: RemotingNG/REST
// Package: REST
// Module:  Listener
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#ifndef RemotingNG_REST_Listener_INCLUDED
#define RemotingNG_REST_Listener_INCLUDED

#include "Poco/RemotingNG/REST/REST.h"
#include "Poco/RemotingNG/Listener.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/SharedPtr.h"


namespace Poco {
namespace RemotingNG {
namespace REST {


class RemotingNGREST_API Listener: public Poco::RemotingNG::Listener
{
public:
	static const std::string PROTOCOL_HTTP;

	typedef Poco::AutoPtr<Listener> Ptr;

	Listener(const std::string& endPoint, Poco::Net::HTTPServerParams::Ptr pParams = new Poco::Net::HTTPServerParams);

	~Listener();

	// Poco::RemotingNG::Listener
	void start();
	void stop();
	const std::string& protocol() const;
	std::string createURI(const Poco::RemotingNG::Identifiable::TypeId& typeId, const Poco::RemotingNG::Identifiable::ObjectId& objectId);
	bool handlesURI(const std::string& uri);
	void registerObject(Poco::RemotingNG::RemoteObject::Ptr pRemoteObject, Poco::RemotingNG::Skeleton::Ptr pSkeleton);
	void unregisterObject(Poco::RemotingNG::RemoteObject::Ptr pRemoteObject);

private:
	Poco::SharedPtr<Poco::Net::HTTPServer> _pHTTPServer;
};


} } } // namespace Poco::RemotingNG::REST


#endif // RemotingNG_REST_Listener_INCLUDED

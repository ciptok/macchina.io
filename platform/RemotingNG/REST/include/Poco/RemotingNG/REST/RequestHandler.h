// Library: RemotingNG/REST
// Package: REST
// Module:  RequestHandler
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#ifndef RemotingNG_REST_RequestHandler_INCLUDED
#define RemotingNG_REST_RequestHandler_INCLUDED


#include "Poco/RemotingNG/REST/REST.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"


namespace Poco {
namespace RemotingNG {
namespace REST {


class RemotingNGREST_API RequestHandler: public Poco::Net::HTTPRequestHandler
{
public:
	RequestHandler();

	~RequestHandler();

	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};

class RequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {
public:
    RequestHandlerFactory(){}
    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request)
    {
        return new RequestHandler();
    }
};


} } } // namespace Poco::RemotingNG::REST


#endif // RemotingNG_REST_RequestHandler_INCLUDED

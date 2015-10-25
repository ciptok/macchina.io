// Library: RemotingNG/REST
// Package: REST
// Module:  RequestHandler
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/RequestHandler.h"
#include "Poco/RemotingNG/REST/ServerTransport.h"


namespace Poco {
namespace RemotingNG {
namespace REST {


RequestHandler::RequestHandler()
{

}

RequestHandler::~RequestHandler()
{

}

void RequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	ServerTransport serverTransport(request);
	std::string responseBody = serverTransport.RunRequest();

	response.setChunkedTransferEncoding(true);
	response.setContentType(request.getContentType());

	std::ostream& ostr = response.send();
	ostr << responseBody;
}


} } } // namespace Poco::RemotingNG::REST
//
// ServerTransport.cpp
//
// $Id: //poco/1.6/RemotingNG/src/ServerTransport.cpp#1 $
//
// Library: RemotingNG
// Package: Transport
// Module:  ServerTransport
//
// Copyright (c) 2006-2014, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/ServerTransport.h"
#include "Poco/RemotingNG/Deserializer.h"


namespace Poco {
namespace RemotingNG {


ServerTransport::ServerTransport()
{
}


ServerTransport::~ServerTransport()
{
}

SerializerBase::MessageType ServerTransport::findMessage(std::string& name)
{
	return beginRequest().findMessage(name);
}


} } // namespace Poco::RemotingNG

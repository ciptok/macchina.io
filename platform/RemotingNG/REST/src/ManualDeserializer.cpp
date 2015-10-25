// Library: RemotingNG/REST
// Package: REST
// Module:  ManualDeserializer
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/ManualDeserializer.h"
#include "Poco/RemotingNG/REST/ServerTransport.h"
#include "Poco/RemotingNG/Context.h"
#include "Poco/NumberParser.h"


namespace Poco {
namespace RemotingNG {
namespace REST {


ManualDeserializer::ManualDeserializer() :
	_logger(Poco::Logger::get("RemotingNG.REST.ManualDeserializer"))
{
}


ManualDeserializer::~ManualDeserializer()
{
}

SerializerBase::MessageType ManualDeserializer::findMessage(std::string& name)
{
	return MESSAGE_REQUEST;
}


void ManualDeserializer::deserializeMessageBegin(const std::string& name, SerializerBase::MessageType type)
{
}


void ManualDeserializer::deserializeMessageEnd(const std::string& name, SerializerBase::MessageType type)
{
}


bool ManualDeserializer::deserializeStructBegin(const std::string& name, bool isMandatory)
{
}


void ManualDeserializer::deserializeStructEnd(const std::string& name)
{
}


bool ManualDeserializer::deserializeSequenceBegin(const std::string& name, bool isMandatory, Poco::UInt32& lengthHint)
{

}


void ManualDeserializer::deserializeSequenceEnd(const std::string& name)
{

}


bool ManualDeserializer::deserializeNullableBegin(const std::string& name, bool isMandatory, bool& isNull)
{

}


void ManualDeserializer::deserializeNullableEnd(const std::string& name)
{
}

bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::Int8& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::UInt8& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::Int16& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::UInt16& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::Int32& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::UInt32& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, long& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, unsigned long& value)
{
	return true;
}


#ifndef POCO_LONG_IS_64_BIT
bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::Int64& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::UInt64& value)
{
	return true;
}
#endif


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, float& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, double& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, bool& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, char& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, std::string& value)
{
	return true;
}


bool ManualDeserializer::deserialize(const std::string& name, bool isMandatory, std::vector<char>& value)
{
	return true;
}

void ManualDeserializer::resetImpl()
{

}

void ManualDeserializer::setupImpl(std::istream& istr)
{

}


} } } // namespace Poco::Remoting::REST

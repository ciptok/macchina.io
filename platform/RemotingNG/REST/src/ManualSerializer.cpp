// Library: RemotingNG/REST
// Package: REST
// Module:  ManualSerializer
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/ManualSerializer.h"
#include "Poco/RemotingNG/Context.h"
#include "Poco/DOM/Text.h"
#include <sstream>

namespace Poco {
namespace RemotingNG {
namespace REST {


ManualSerializer::ManualSerializer() :
	_logger(Poco::Logger::get("RemotingNG.REST.ManualSerializer"))
{
}


ManualSerializer::~ManualSerializer()
{
}


void ManualSerializer::serializeMessageBegin(const std::string& name, SerializerBase::MessageType type)
{

	switch (type)
	{
		case SerializerBase::MESSAGE_REPLY:
		{
			break;
		}
		case SerializerBase::MESSAGE_FAULT:
		{
			break;
		}
		default:
			poco_bugcheck();
	}
}


void ManualSerializer::serializeMessageEnd(const std::string& name, SerializerBase::MessageType type)
{
	if (type == MESSAGE_REPLY)
	{
		Poco::RemotingNG::Context::Ptr pContext = Poco::RemotingNG::Context::get();

		if (pContext)
		{
			if (pContext->has("responsebody"))
			{
				*_outStream << pContext->getValue<std::string>("responsebody");
			}
		}
	}
}


void ManualSerializer::serializeFaultMessage(const std::string& name, Poco::Exception& exc)
{
	serializeMessageBegin(name, SerializerBase::MESSAGE_FAULT);
	*_outStream << exc.name() << exc.message() << std::string(typeid(exc).name());
	serializeMessageEnd(name, SerializerBase::MESSAGE_FAULT);
}


void ManualSerializer::serializeStructBegin(const std::string& name)
{
}


void ManualSerializer::serializeStructEnd(const std::string& name)
{
}


void ManualSerializer::serializeSequenceBegin(const std::string& name, Poco::UInt32 length)
{
}


void ManualSerializer::serializeSequenceEnd(const std::string& name)
{
}


void ManualSerializer::serializeNullableBegin(const std::string& name, bool isNull)
{
}


void ManualSerializer::serializeNullableEnd(const std::string& name)
{
}


void ManualSerializer::serialize(const std::string& name, Poco::Int8 value)
{
}


void ManualSerializer::serialize(const std::string& name, Poco::UInt8 value)
{
}


void ManualSerializer::serialize(const std::string& name, Poco::Int16 value)
{
}


void ManualSerializer::serialize(const std::string& name, Poco::UInt16 value)
{
}


void ManualSerializer::serialize(const std::string& name, Poco::Int32 value)
{
}


void ManualSerializer::serialize(const std::string& name, Poco::UInt32 value)
{
}


void ManualSerializer::serialize(const std::string& name, long value)
{
}


void ManualSerializer::serialize(const std::string& name, unsigned long value)
{
}


#ifndef POCO_LONG_IS_64_BIT
void ManualSerializer::serialize(const std::string& name, Poco::Int64 value)
{
}


void ManualSerializer::serialize(const std::string& name, Poco::UInt64 value)
{
}
#endif


void ManualSerializer::serialize(const std::string& name, float value)
{
}


void ManualSerializer::serialize(const std::string& name, double value)
{
}


void ManualSerializer::serialize(const std::string& name, bool value)
{
}


void ManualSerializer::serialize(const std::string& name, char value)
{
}


void ManualSerializer::serialize(const std::string& name, const std::string& value)
{
}


void ManualSerializer::serialize(const std::string& name, const std::vector<char>& value)
{
}


void ManualSerializer::resetImpl()
{
}


void ManualSerializer::setupImpl(std::ostream& ostr)
{
	_outStream = new PlainWriter(ostr);
}


} } } // namespace Poco::RemotingNG::REST

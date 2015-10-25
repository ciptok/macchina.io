// Library: RemotingNG/REST
// Package: REST
// Module:  XMLSerializer
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/XMLSerializer.h"
#include "Poco/NumberFormatter.h"
#include "Poco/DOM/Text.h"
#include "Poco/DOM/DOMWriter.h"

namespace Poco {
namespace RemotingNG {
namespace REST {


XMLSerializer::XMLSerializer(std::ostream &ostr)
{
	_pDocument = new Poco::XML::Document;
}


XMLSerializer::~XMLSerializer()
{
}


void XMLSerializer::serializeMessageBegin(const std::string& name, SerializerBase::MessageType type)
{

	switch (type)
	{
	case SerializerBase::MESSAGE_REPLY:
	{
		AutoPtr<Poco::XML::Element> pRoot = _pDocument->createElement(name);
		_pDocument->appendChild(pRoot);
		_pCurrentElement = pRoot;

		break;
	}
	case SerializerBase::MESSAGE_FAULT:
	{
		AutoPtr<Poco::XML::Element> pRoot = _pDocument->createElement(name);
		_pDocument->appendChild(pRoot);
		break;
	}
	default:
		poco_bugcheck();
	}
}


void XMLSerializer::serializeMessageEnd(const std::string& name, SerializerBase::MessageType type)
{
	Poco::XML::DOMWriter writer;
	writer.setNewLine("\n");
	writer.setOptions(Poco::XML::XMLWriter::PRETTY_PRINT);
	writer.writeNode(_outStream->getOut(), _pDocument);
}


void XMLSerializer::serializeFaultMessage(const std::string& name, Poco::Exception& exc)
{
	serializeMessageBegin(name, SerializerBase::MESSAGE_FAULT);

	serializeMessageEnd(name, SerializerBase::MESSAGE_FAULT);
}


void XMLSerializer::serializeStructBegin(const std::string& name)
{
	//TODO: Implement
}


void XMLSerializer::serializeStructEnd(const std::string& name)
{
	//TODO: Implement
}


void XMLSerializer::serializeSequenceBegin(const std::string& name, Poco::UInt32 length)
{
	//TODO: Implement
}


void XMLSerializer::serializeSequenceEnd(const std::string& name)
{
	//TODO: Implement
}


void XMLSerializer::serializeNullableBegin(const std::string& name, bool isNull)
{
	//TODO: Implement
}


void XMLSerializer::serializeNullableEnd(const std::string& name)
{
	//TODO: Implement
}


void XMLSerializer::serialize(const std::string& name, Poco::Int8 value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, Poco::UInt8 value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, Poco::Int16 value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, Poco::UInt16 value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, Poco::Int32 value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, Poco::UInt32 value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, long value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, unsigned long value)
{
	generateNode(name, NumberFormatter::format(value));
}


#ifndef POCO_LONG_IS_64_BIT
void XMLSerializer::serialize(const std::string& name, Poco::Int64 value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, Poco::UInt64 value)
{
	generateNode(name, NumberFormatter::format(value));
}
#endif


void XMLSerializer::serialize(const std::string& name, float value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, double value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, bool value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, char value)
{
	generateNode(name, NumberFormatter::format(value));
}


void XMLSerializer::serialize(const std::string& name, const std::string& value)
{
	generateNode(name, value);
}


void XMLSerializer::serialize(const std::string& name, const std::vector<char>& value)
{
	//TODO: Implement
}


void XMLSerializer::resetImpl()
{
}


void XMLSerializer::setupImpl(std::ostream& ostr)
{
	_outStream = new PlainWriter(ostr);
}

void XMLSerializer::generateNode(const std::string &name, const std::string &value)
{
	AutoPtr<Poco::XML::Element> pChild = _pDocument->createElement(name);
	AutoPtr<Poco::XML::Text> pText = _pDocument->createTextNode(value);
	pChild->appendChild(pText);
	_pCurrentElement->appendChild(pChild);
}


} } } // namespace Poco::RemotingNG::REST

// Library: RemotingNG/REST
// Package: REST
// Module:  XMLDeserializer
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/XMLDeserializer.h"
#include "Poco/RemotingNG/REST/ServerTransport.h"
#include "Poco/RemotingNG/Context.h"
#include "Poco/SAX/WhitespaceFilter.h"
#include "Poco/SAX/InputSource.h"
#include "Poco/SAX/SAXParser.h"
#include "Poco/NumberParser.h"


namespace Poco {
namespace RemotingNG {
namespace REST {


const std::string XMLDeserializer::EMPTY_NAMESPACE = "";

XMLDeserializer::XMLDeserializer() :
	_logger(Poco::Logger::get("RemotingNG.REST.XMLDeserializer"))
{
}


XMLDeserializer::~XMLDeserializer()
{
}

SerializerBase::MessageType XMLDeserializer::findMessage(std::string& name)
{
	name = _contentHandler.getMessageName();

	return MESSAGE_REQUEST;
}


void XMLDeserializer::deserializeMessageBegin(const std::string& name, SerializerBase::MessageType type)
{
	//TODO: Implement
}


void XMLDeserializer::deserializeMessageEnd(const std::string& name, SerializerBase::MessageType type)
{
	//TODO: Implement
}


bool XMLDeserializer::deserializeStructBegin(const std::string& name, bool isMandatory)
{
	//TODO: Implement
}


void XMLDeserializer::deserializeStructEnd(const std::string& name)
{
	//TODO: Implement
}


bool XMLDeserializer::deserializeSequenceBegin(const std::string& name, bool isMandatory, Poco::UInt32& lengthHint)
{
	//TODO: Implement
}


void XMLDeserializer::deserializeSequenceEnd(const std::string& name)
{
	//TODO: Implement
}


bool XMLDeserializer::deserializeNullableBegin(const std::string& name, bool isMandatory, bool& isNull)
{
	//TODO: Implement
}


void XMLDeserializer::deserializeNullableEnd(const std::string& name)
{
	//TODO: Implement
}

bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::Int8& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		int tmpValue;
		bool ret = NumberParser::tryParse(node->_value, tmpValue);

		value = tmpValue;
		return ret;
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::UInt8& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		unsigned int tmpValue;
		bool ret = NumberParser::tryParseUnsigned(node->_value, tmpValue);

		value = tmpValue;
		return ret;
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::Int16& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		int tmpValue;
		bool ret = NumberParser::tryParse(node->_value, tmpValue);

		value = tmpValue;
		return ret;
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::UInt16& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		unsigned int tmpValue;
		bool ret = NumberParser::tryParseUnsigned(node->_value, tmpValue);

		value = tmpValue;
		return ret;
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::Int32& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		return NumberParser::tryParse(node->_value, value);
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::UInt32& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		return NumberParser::tryParseUnsigned(node->_value, value);
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, long& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		int tmpValue;
		bool ret = NumberParser::tryParse(node->_value, tmpValue);

		value = tmpValue;
		return ret;
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, unsigned long& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		unsigned int tmpValue;
		bool ret = NumberParser::tryParseUnsigned(node->_value, tmpValue);

		value = tmpValue;
		return ret;
	}

	return false;
}


#ifndef POCO_LONG_IS_64_BIT
bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::Int64& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		return NumberParser::tryParse64(node->_value, value);
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, Poco::UInt64& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		return NumberParser::tryParseUnsigned64(node->_value, value);
	}

	return false;
}
#endif


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, float& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		double tmpValue;
		bool ret = NumberParser::tryParseFloat(node->_value, tmpValue);

		value = tmpValue;
		return ret;
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, double& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		return NumberParser::tryParseFloat(node->_value, value);
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, bool& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		return NumberParser::tryParseBool(node->_value, value);
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, char& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		value = node->_value[0];
		return true;
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, std::string& value)
{
	const XMLContentHandler::Node* node = _contentHandler.getNode(EMPTY_NAMESPACE, name);

	if (node)
	{
		value = node->_value;
		return true;
	}

	return false;
}


bool XMLDeserializer::deserialize(const std::string& name, bool isMandatory, std::vector<char>& value)
{
	//TODO: Implement
}

void XMLDeserializer::resetImpl()
{
	//TODO: Implement
}

void XMLDeserializer::setupImpl(std::istream& istr)
{
	Poco::XML::SAXParser parser;

	Poco::XML::WhitespaceFilter filter(&parser);
	filter.setContentHandler(&_contentHandler);

	try
	{
		Poco::XML::InputSource source(istr);
		filter.parse(&source);
	}
	catch (Poco::Exception& e)
	{
		if(_logger.error())
		{
			_logger.error(e.displayText());
		}
	}
}


} } } // namespace Poco::Remoting::REST

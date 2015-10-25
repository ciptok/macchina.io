// Library: RemotingNG/REST
// Package: REST
// Module:  XMLDeserializer
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#ifndef RemotingNG_REST_XMLDeserializer_INCLUDED
#define RemotingNG_REST_XMLDeserializer_INCLUDED

#include "Poco/RemotingNG/REST/REST.h"
#include "Poco/RemotingNG/REST/XMLContentHandler.h"
#include "Poco/RemotingNG/Deserializer.h"
#include "Poco/RemotingNG/RemotingException.h"


namespace Poco {
namespace RemotingNG {
namespace REST {


class RemotingNGREST_API XMLDeserializer : public Poco::RemotingNG::Deserializer
{
public:
	static const std::string EMPTY_NAMESPACE;

	XMLDeserializer();

	~XMLDeserializer();

	//Poco::RemotingNG::Deserializer
	SerializerBase::MessageType findMessage(std::string& name);
	void deserializeMessageBegin(const std::string& name, SerializerBase::MessageType type);
	void deserializeMessageEnd(const std::string& name, SerializerBase::MessageType type);
	bool deserializeStructBegin(const std::string& name, bool isMandatory);
	void deserializeStructEnd(const std::string& name);
	bool deserializeSequenceBegin(const std::string& name, bool isMandatory, Poco::UInt32& lengthHint);
	void deserializeSequenceEnd(const std::string& name);
	bool deserializeNullableBegin(const std::string& name, bool isMandatory, bool& isNull);
	void deserializeNullableEnd(const std::string& name);
	bool deserialize(const std::string& name, bool isMandatory, Poco::Int8& value);
	bool deserialize(const std::string& name, bool isMandatory, Poco::UInt8& value);
	bool deserialize(const std::string& name, bool isMandatory, Poco::Int16& value);
	bool deserialize(const std::string& name, bool isMandatory, Poco::UInt16& value);
	bool deserialize(const std::string& name, bool isMandatory, Poco::Int32& value);
	bool deserialize(const std::string& name, bool isMandatory, Poco::UInt32& value);
	bool deserialize(const std::string& name, bool isMandatory, long& value);
	bool deserialize(const std::string& name, bool isMandatory, unsigned long& value);
#ifndef POCO_LONG_IS_64_BIT
	bool deserialize(const std::string& name, bool isMandatory, Poco::Int64& value);
	bool deserialize(const std::string& name, bool isMandatory, Poco::UInt64& value);
#endif
	bool deserialize(const std::string& name, bool isMandatory, float& value);
	bool deserialize(const std::string& name, bool isMandatory, double& value);
	bool deserialize(const std::string& name, bool isMandatory, bool& value);
	bool deserialize(const std::string& name, bool isMandatory, char& value);
	bool deserialize(const std::string& name, bool isMandatory, std::string& value);
	bool deserialize(const std::string& name, bool isMandatory, std::vector<char>& value);

protected:
	//Poco::RemotingNG::Deserializer
	void setupImpl(std::istream& istr);
	void resetImpl();

private:
	Poco::Logger& _logger;
	XMLContentHandler _contentHandler;
};


//
// inlines
//


} } } // namespace Poco::RemotingNG::REST


#endif // RemotingNG_REST_XMLDeserializer_INCLUDED

// Library: RemotingNG/REST
// Package: REST
// Module:  DefaultSerializer
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#ifndef RemotingNG_REST_XMLSerializer_INCLUDED
#define RemotingNG_REST_XMLSerializer_INCLUDED


#include "Poco/RemotingNG/Serializer.h"
#include "Poco/RemotingNG/REST/PlainWriter.h"
#include "Poco/XML/XMLWriter.h"
#include "Poco/DOM/Document.h"
#include "Poco/DOM/Element.h"
#include "Poco/AutoPtr.h"
#include "Poco/SharedPtr.h"
#include <memory>


namespace Poco {
namespace RemotingNG {
namespace REST {


class RemotingNG_API XMLSerializer: public Poco::RemotingNG::Serializer
{
public:
	XMLSerializer(std::ostream &ostr);

	~XMLSerializer();

	// Poco::RemotingNG::Serializer
	void serializeMessageBegin(const std::string& name, SerializerBase::MessageType type);
	void serializeMessageEnd(const std::string& name, SerializerBase::MessageType type);
	void serializeFaultMessage(const std::string& name, Poco::Exception& exc);
	void serializeStructBegin(const std::string& name);
	void serializeStructEnd(const std::string& name);
	void serializeSequenceBegin(const std::string& name, Poco::UInt32 length);
	void serializeSequenceEnd(const std::string& name);
	void serializeNullableBegin(const std::string& name, bool isNull);
	void serializeNullableEnd(const std::string& name);
	void serialize(const std::string& name, Poco::Int8 value);
	void serialize(const std::string& name, Poco::UInt8 value);
	void serialize(const std::string& name, Poco::Int16 value);
	void serialize(const std::string& name, Poco::UInt16 value);
	void serialize(const std::string& name, Poco::Int32 value);
	void serialize(const std::string& name, Poco::UInt32 value);
	void serialize(const std::string& name, long value);
	void serialize(const std::string& name, unsigned long value);
#ifndef POCO_LONG_IS_64_BIT
	void serialize(const std::string& name, Poco::Int64 value);
	void serialize(const std::string& name, Poco::UInt64 value);
#endif
	void serialize(const std::string& name, float value);
	void serialize(const std::string& name, double value);
	void serialize(const std::string& name, bool value);
	void serialize(const std::string& name, char value);
	void serialize(const std::string& name, const std::string& value);
	void serialize(const std::string& name, const std::vector<char>& value);

protected:
	void resetImpl();
	void setupImpl(std::ostream& ostr);

private:
	Poco::SharedPtr<PlainWriter> _outStream;
	Poco::AutoPtr<Poco::XML::Document> _pDocument;
	Poco::XML::Element *_pCurrentElement;

	friend class XMLDeserializer;

	void generateNode(const std::string &name, const std::string &value);
};


} } } // namespace Poco::RemotingNG::REST


#endif // RemotingNG_REST_XMLSerializer_INCLUDED

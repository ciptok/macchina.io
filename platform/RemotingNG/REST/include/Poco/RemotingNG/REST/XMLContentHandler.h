// Library: RemotingNG/REST
// Package: REST
// Module:  XMLContentHandler
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#ifndef RemotingNG_REST_XMLContentHandler_INCLUDED
#define RemotingNG_REST_XMLContentHandler_INCLUDED


#include "Poco/Logger.h"
#include "Poco/SAX/ContentHandler.h"
#include "Poco/SAX/Locator.h"
#include "Poco/SAX/Attributes.h"
#include "Poco/XML/Name.h"
#include <list>
#include <stack>


namespace Poco {
namespace RemotingNG {
namespace REST {


class XMLContentHandler : public Poco::XML::ContentHandler
{
public:
	struct Node
	{
		std::string _name;
		std::string _value;
		std::list<Node> _child;
	};

	XMLContentHandler();
	~XMLContentHandler();

	//Poco::XML::ContentHandler
	void setDocumentLocator(const XML::Locator* loc);
	void startDocument();
	void endDocument();
	void startElement(const XML::XMLString& uri, const XML::XMLString& localName, const XML::XMLString& qname, const XML::Attributes& attrList);
	void endElement(const XML::XMLString& uri, const XML::XMLString& localName, const XML::XMLString& qname);
	void characters(const XML::XMLChar ch[], int start, int length);
	void ignorableWhitespace(const XML::XMLChar ch[], int start, int length);
	void processingInstruction(const XML::XMLString& target, const XML::XMLString& data);
	void startPrefixMapping(const XML::XMLString& prefix, const XML::XMLString& uri);
	void endPrefixMapping(const XML::XMLString& prefix);
	void skippedEntity(const XML::XMLString& name);

	const Node& getNodes() const { return _nodes; }
	const Node* getNode(const std::string uri, const std::string name) const;
	const std::string getMessageName() const;

private:
	Poco::Logger& _logger;
	Node _nodes;
	std::stack<Node*> _nodesStack;

	//Key(uri, name) with value pairs
	typedef std::pair <std::string, std::string> UriNamePair;
	std::map<UriNamePair, Node*> _nodesMap;

	const Node* findNodeByName(const std::string name) const;
	const Node* findNodeByName(const Node& node, const std::string name) const;
};


} } } // namespace Poco::RemotingNG::REST

#endif // RemotingNG_REST_XMLContentHandler_INCLUDED

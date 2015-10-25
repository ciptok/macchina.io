// Library: RemotingNG/REST
// Package: REST
// Module:  XMLContentHandler
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/XMLContentHandler.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/AutoPtr.h"
#include <sstream>

namespace Poco {
namespace RemotingNG {
namespace REST {

XMLContentHandler::XMLContentHandler() :
	_logger(Poco::Logger::get("RemotingNG.REST.XMLContentHandler"))
{
}

XMLContentHandler::~XMLContentHandler()
{
}

void XMLContentHandler::setDocumentLocator(const XML::Locator* loc)
{
}

void XMLContentHandler::startDocument()
{
	if (_logger.debug())
	{
		_logger.debug("XML Start Document...");
	}
}

void XMLContentHandler::endDocument()
{
}

void XMLContentHandler::startElement(const XML::XMLString& uri, const XML::XMLString& localName, const XML::XMLString& qname, const XML::Attributes& attrList)
{
	Node node;
	node._name = localName;

	if (_nodesStack.empty()) //first node
	{
		_nodes = node;
		_nodesStack.push(&_nodes);
	}
	else
	{
		Node *topNode = _nodesStack.top();
		topNode->_child.push_back(node);
		_nodesStack.push(&topNode->_child.back());
	}

	UriNamePair key = UriNamePair(uri, localName);
	_nodesMap[key] = _nodesStack.top();

	if (_logger.debug())
	{
		std::stringstream infoStream;
		infoStream << "Start element" << "(" << uri + "): " << localName;
		_logger.debug(infoStream.str());
	}
}

void XMLContentHandler::endElement(const XML::XMLString& uri, const XML::XMLString& localName, const XML::XMLString& qname)
{
	_nodesStack.pop();

	if (_logger.debug())
	{
		_logger.debug("End element: " + localName);
	}
}

void XMLContentHandler::characters(const XML::XMLChar ch[], int start, int length)
{
	std::string value;
	value.assign(ch + start, length);

	_nodesStack.top()->_value = value;

	if (_logger.debug())
	{
		_logger.debug("Value: " + value);
	}
}

void XMLContentHandler::ignorableWhitespace(const XML::XMLChar ch[], int start, int length)
{
}

void XMLContentHandler::processingInstruction(const XML::XMLString& target, const XML::XMLString& data)
{
}

void XMLContentHandler::startPrefixMapping(const XML::XMLString& prefix, const XML::XMLString& uri)
{
}

void XMLContentHandler::endPrefixMapping(const XML::XMLString& prefix)
{
}

void XMLContentHandler::skippedEntity(const XML::XMLString& name)
{
}

const XMLContentHandler::Node* XMLContentHandler::getNode(const std::string uri, const std::string name) const
{
	std::map<UriNamePair, Node*>::const_iterator it = _nodesMap.find(UriNamePair(uri, name));

	if (it != _nodesMap.end())
	{
		return it->second;
	}

	return NULL;
}

const std::string XMLContentHandler::getMessageName() const
{
	//TODO: Handle it properly
	return _nodes._name;
}

const XMLContentHandler::Node* XMLContentHandler::findNodeByName(const std::string name) const
{
	return findNodeByName(_nodes, name);
}

const XMLContentHandler::Node* XMLContentHandler::findNodeByName(const Node& node, const std::string name) const
{
	if(node._name == name)
	{
		return &node;
	}

	const Node* pNode = NULL;
	for (std::list<Node>::const_iterator it = node._child.begin();
			it != node._child.end();
			++it)
	{
		pNode = findNodeByName(*it, name);

		if (pNode != NULL)
		{
			return pNode;
		}
	}

	return pNode;
}


} } } // namespace Poco::RemotingNG::REST

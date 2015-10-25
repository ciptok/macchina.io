// Library: RemotingNG/REST
// Package: REST
// Module:  PlainWriter
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#include "Poco/RemotingNG/REST/PlainWriter.h"

namespace Poco {
namespace RemotingNG {
namespace REST {


PlainWriter::PlainWriter(std::ostream &ostr)
	: _ostr(ostr)
{

}

PlainWriter& PlainWriter::operator << (std::string value)
{
	_ostr << value;
	return *this;
}


} } } // namespace Poco::RemotingNG::REST
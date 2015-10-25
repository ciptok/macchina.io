// Library: RemotingNG/REST
// Package: REST
// Module:  PlainWriter
//
// Copyright (c) 2015, Kamil Grzebien
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//


#ifndef RemotingNG_REST_PlainWriter_INCLUDED
#define RemotingNG_REST_PlainWriter_INCLUDED

#include <ostream>


namespace Poco {
namespace RemotingNG {
namespace REST {


//TODO: Temporary class
class PlainWriter
{
public:
	PlainWriter(std::ostream &ostr);

	PlainWriter& operator << (std::string value);

	std::ostream& getOut() { return _ostr; }

private:
	std::ostream& _ostr;
};

} } } // namespace Poco::RemotingNG::REST

#endif // RemotingNG_REST_PlainWriter_INCLUDED


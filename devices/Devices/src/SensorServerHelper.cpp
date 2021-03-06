//
// SensorServerHelper.cpp
//
// Library: IoT/Devices
// Package: Generated
// Module:  SensorServerHelper
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2014-2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "IoT/Devices/SensorServerHelper.h"
#include "IoT/Devices/SensorEventDispatcher.h"
#include "IoT/Devices/SensorSkeleton.h"
#include "Poco/RemotingNG/URIUtility.h"
#include "Poco/SingletonHolder.h"


namespace IoT {
namespace Devices {


namespace
{
	static Poco::SingletonHolder<SensorServerHelper> shSensorServerHelper;
}


SensorServerHelper::SensorServerHelper():
	_pORB(0)
{
	_pORB = &Poco::RemotingNG::ORB::instance();
	_pORB->registerSkeleton("Sensor", new SensorSkeleton);
}


SensorServerHelper::~SensorServerHelper()
{
	try
	{
		_pORB->unregisterSkeleton("Sensor", true);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


std::string SensorServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::Devices::SensorRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return SensorServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}


Poco::AutoPtr<IoT::Devices::SensorRemoteObject> SensorServerHelper::createRemoteObjectImpl(Poco::SharedPtr<IoT::Devices::Sensor> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return new SensorRemoteObject(oid, pServiceObject);
}


void SensorServerHelper::enableEventsImpl(const std::string& uri, const std::string& protocol)
{
	Poco::RemotingNG::Identifiable::Ptr pIdentifiable = _pORB->findObject(uri);
	Poco::AutoPtr<SensorRemoteObject> pRemoteObject = pIdentifiable.cast<SensorRemoteObject>();
	if (pRemoteObject)
	{
		pRemoteObject->remoting__enableRemoteEvents(protocol);
	}
	else throw Poco::NotFoundException("remote object", uri);
}


SensorServerHelper& SensorServerHelper::instance()
{
	return *shSensorServerHelper.get();
}


std::string SensorServerHelper::registerObjectImpl(Poco::AutoPtr<IoT::Devices::SensorRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return _pORB->registerObject(pRemoteObject, listenerId);
}


void SensorServerHelper::unregisterObjectImpl(const std::string& uri)
{
	_pORB->unregisterObject(uri);
}


} // namespace Devices
} // namespace IoT


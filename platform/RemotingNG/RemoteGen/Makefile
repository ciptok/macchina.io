#
# Makefile
#
# $Id: //poco/1.6/RemotingNG/RemoteGen/Makefile#1 $
#
# Makefile for RemoteGenNG
#

include $(POCO_BASE)/build/rules/global

objects = AbstractGenerator ProxyFactoryGenerator SerializerGenerator XSDGenerator \
	ClientHelperGenerator ProxyGenerator ServerHelperGenerator \
	BundleActivatorGenerator ExtensionsGenerator \
	DeserializerGenerator RemoteGen SkeletonGenerator \
	InterfaceGenerator RemoteObjectGenerator WSDLGenerator GenUtility \
	EventDispatcherGenerator EventSubscriberGenerator

target         = RemoteGenNG
target_version = 1
target_libs    = PocoRemotingNG PocoCodeGeneration PocoNet PocoUtil PocoCppParser PocoXML PocoFoundation $(POCO_LICENSING)

include $(POCO_BASE)/build/rules/exec

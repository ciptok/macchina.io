#
# Makefile
#
# $Id: //poco/1.6/OSP/Data/Makefile#1 $
#
# Makefile for Data Bundle
#

BUNDLE_TOOL = $(POCO_BASE)/OSP/BundleCreator/$(POCO_HOST_BINDIR)/bundle

include $(POCO_BASE)/build/rules/global

objects = DataBundleActivator

target         = poco.data
target_version = 1
target_libs    = PocoOSP PocoData PocoUtil PocoXML PocoFoundation

postbuild      = $(BUNDLE_TOOL) -n$(OSNAME) -a$(OSARCH) -o../bundles Data.bndlspec

include $(POCO_BASE)/build/rules/dylib

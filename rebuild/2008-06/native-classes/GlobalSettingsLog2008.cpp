// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr-len /I{headers}/std-noinline-string
// 2008-06 native (inactive): the settings dump CRobloxApp::initializeSettings ends with, 0044c620 (OpenRBX Roblox.cpp
// FUN_004500e0): log "GlobalSettings ---", visit every child writing "\t<name>" and each string-valued property as
// "\t\t<category>.<name>: <value>" (callback 0044c4d0, property helper inlined), then "End GlobalSettings ---".
// The exe symbol is unknown (nativeLogGlobalSettings stands in for it).
#include <algorithm>
#include <G3D/format.h>
#include "v8datamodel/GlobalSettings.h"
#include "util/Log.h"
#include "reflection/reflection.h"
#include "v8tree/Instance.h"

namespace
{
	void logProperty(RBX::Reflection::ConstProperty property)
	{
		if (property.getDescriptor().hasStringValue())
		{
			RBX::Log::current()->writeEntry(RBX::Log::Information,
				G3D::format("\t\t%s.%s: %s", property.getDescriptor().category.c_str(), property.getDescriptor().name.c_str(),
					property.getStringValue().c_str()).c_str());
		}
	}

	void logChild(boost::shared_ptr<RBX::Instance> instance)
	{
		RBX::Log::current()->writeEntry(RBX::Log::Information, G3D::format("\t%s", instance->getName().c_str()).c_str());
		std::for_each(instance->properties_begin(), instance->properties_end(), logProperty);
	}
}

void nativeLogGlobalSettings()
{
	RBX::Log::current()->writeEntry(RBX::Log::Information, G3D::format("GlobalSettings ---------------------------------------").c_str());
	RBX::GlobalSettings::singleton()->visitChildren(logChild);
	RBX::Log::current()->writeEntry(RBX::Log::Information, G3D::format("End GlobalSettings -----------------------------------").c_str());
}

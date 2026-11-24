// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr-len /I{headers}/std-noinline-string
// 2008-06 native (inactive): the machine-configuration upload InitInstance runs after initializeSettings, 0044cbb0
// (InitInstance's placeholder name nativeInitializeCallbacks). Structure from OpenRBX Roblox.cpp FUN_00450e30 + FUN_0044edf0
// (read for evidence), checked against the 2008 disassembly: POST "<base url>/Game/MachineConfiguration.ashx" with
// "name:value;" for every DebugSettings property of category "Profile" and every CRenderSettings property of category
// "General"; any std::exception is swallowed. The category compare, writer 0044ac80 and for_each 0044bff0 are the exe's.
// INFERRED: the exe symbol names (nativeInitializeCallbacks stands in for the real one).
#undef _RELEASEASSERT // 0044bff0 builds each Property without RBXASSERT(isMemberOf) (as NetworkReplicator2008StatsItem.cpp)
#include <afxwin.h>
#include <algorithm>
#include <sstream>
#include <boost/bind.hpp>
#include "v8datamodel/DebugSettings.h"
#include "../native-headers/CRenderSettings.h"
#include "util/Http.h"
#include "reflection/reflection.h"

CString applicationBaseUrl();

// 0044bff0 (for_each over the property iterator) increments inline (add edi, 4 after the checked-iterator compare):
// unit-local inline specialization, the HistoryItemState.cpp pattern.
template<>
inline RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor>::Iterator&
RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor>::Iterator::operator++()
{
	++iter;
	return *this;
}

namespace
{
	void writeCategory(const char* category, std::stringstream* stream, const RBX::Reflection::ConstProperty& property)
	{
		if (property.getDescriptor().category == category)
		{
			*stream << property.getDescriptor().name.c_str();
			*stream << ':';
			*stream << property.getStringValue();
			*stream << ';';
		}
	}
}

void nativeInitializeCallbacks()
{
	CString url = applicationBaseUrl() + "/Game/MachineConfiguration.ashx";
	std::string urlText(url);
	std::string response;
	try
	{
		std::stringstream stream;
		RBX::DebugSettings& debugSettings = RBX::DebugSettings::singleton();
		std::for_each(debugSettings.properties_begin(), debugSettings.properties_end(), boost::bind(writeCategory, "Profile", &stream, _1));
		CRenderSettings& renderSettings = CRenderSettings::singleton();
		std::for_each(renderSettings.properties_begin(), renderSettings.properties_end(), boost::bind(writeCategory, "General", &stream, _1));
		stream.flush();
		RBX::Http(urlText).post(stream, false, response);
	}
	catch (std::exception&)
	{
	}
}

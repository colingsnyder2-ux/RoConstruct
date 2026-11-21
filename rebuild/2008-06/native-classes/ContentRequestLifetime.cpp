// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 RBX::ContentRequest special members (inactive), util/ContentProvider.cpp range (00560ea0 / 00560fa0 /
// 00561020, next to the std::list<ContentRequest> members). util/NativeContentProvider.h (core, read-only) declares
// all three out of line (header-gap entries backed by the registry names); flags line from
// ContentProviderLoadContent.cpp without its content-cache-inline variant, which does not declare them.
#include "util/NativeContentProvider.h"

namespace RBX
{
	// 00560ea0 ??0ContentRequest@RBX@@QAE@ABU01@@Z (registry): ContentId copy (basic_string copy import, +0x1c
	// dword), then std::vector<RequestCallback> copy 00560a70 on +0x20 under the EH state of id. Caller:
	// std::list<ContentRequest>::_Buynode 00561490.
	ContentRequest::ContentRequest(const ContentRequest& other)
		: id(other.id),
		  callbacks(other.callbacks)
	{
	}

	// 00560fa0 ??0ContentRequest@RBX@@QAE@XZ (registry): ContentId() then the empty vector.
	ContentRequest::ContentRequest()
	{
	}

	// 00561020 ??1ContentRequest@RBX@@QAE@XZ (registry): ~vector 00560b60 on +0x20, then the id string.
	ContentRequest::~ContentRequest()
	{
	}
}

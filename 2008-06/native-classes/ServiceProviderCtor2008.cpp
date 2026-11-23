// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native (inactive): ServiceProvider::ServiceProvider() 00568bf0. Base DescribedNonCreatable ctor 00568a50, the three
// Notifier bases (Closing +0x130, ServiceAdded +0x150, ServiceRemoving +0x170, each 005e9ec0), then the members
// serviceArray (+0x190, checked-iterator proxy 006a0920) and serviceMap (+0x1a8, 00589190).
#include "v8tree/Service.h"

namespace RBX
{
	ServiceProvider::ServiceProvider()
	{
	}
}

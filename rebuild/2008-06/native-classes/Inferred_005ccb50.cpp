// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005ccb50: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/ICameraSubject.h"
#include "v8datamodel/Camera.h"
#include "util/Name.h"

namespace RBX {

void __thiscall Camera::updateFocus(void)
{
	if (cameraSubject)
	{
		cameraFocus = dynamic_cast<ICameraSubject*>(cameraSubject.get())->getLocation();
	}
}

}

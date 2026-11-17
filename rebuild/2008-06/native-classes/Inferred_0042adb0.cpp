// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0042adb0 (placeholder name for 0042adb0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <windows.h>
#include <oaidl.h>
#include "util/Name.h"

HRESULT __stdcall sub_0042adb0(IUnknown* self, REFIID riid, void** ppv)
{
	HRESULT hr = 0;
	*ppv = 0;
	if (IsEqualGUID(riid, IID_IUnknown))
		*ppv = self;
	else if (IsEqualGUID(riid, IID_IDispatch))
		*ppv = self;
	else
		hr = (HRESULT)0x80004002L;
	if (hr >= 0)
		self->AddRef();
	return hr;
}

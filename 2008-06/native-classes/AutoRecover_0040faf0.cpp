// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <ole2.h>
#include <oleidl.h>

// INFERRED: minimal class layout from XTDropSource.h (vptr at 0, ref count at +4).
class CXTDropSource : public IDropSource
{
public:
	virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppReturn);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();
	virtual HRESULT __stdcall QueryContinueDrag(BOOL bEsc, DWORD dwKeyState);
	virtual HRESULT __stdcall GiveFeedback(DWORD dwEffect);

protected:
	ULONG m_uiRefCount;
};

ULONG __stdcall CXTDropSource::AddRef()
{
	return ++m_uiRefCount;
}

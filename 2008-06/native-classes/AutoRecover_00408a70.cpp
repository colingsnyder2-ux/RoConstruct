// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afx.h>
#include <atlutil.h>
#include <exception>
#include <string>
#include "CApp2008.h"
#include "v8datamodel/DebugSettings.h"
#include "util/StandardOut.h"

// INFERRED: free function at 0x00429360, cdecl, defined elsewhere.
long reportWorkspaceSiteError(const _GUID& guid, const std::exception& e);

// INFERRED: free function at 0x004060d0, cdecl, returns CString by hidden pointer (global namespace).
CString applicationBaseUrl();

// INFERRED: constructor at 0x004097a0 (the disassembly names it with an unrelated mangled name).
extern "C" int __fastcall fn_004097a0(void* self, int unusedEdx, const char* host);
// INFERRED: 0x004097c0 takes 3 stack args (std::string* result, url, ticket); the declared
// 2-arg form does not match the three pushes in the disassembly.
extern "C" int __fastcall fn_004097c0(void* self, int unusedEdx, void* resultString, const char* url, const char* ticket);
// INFERRED: destructor of the object built by fn_004097a0; no stack arg is pushed in the disassembly.
extern "C" int __fastcall fn_0068b7e0(void* self, int unusedEdx);

STDMETHODIMP CApp::RobloxAuthenticate(BSTR url, BSTR ticket)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());

    RBX::StandardOut::singleton()->print(
        RBX::MESSAGE_INFO,
        "CApp::RobloxAuthenticate %s %s",
        static_cast<LPCSTR>(CString(url)),
        static_cast<LPCSTR>(CString(ticket)));

    try {
        CUrl crackedUrl;
        crackedUrl.CrackUrl(applicationBaseUrl(), 0);

        // INFERRED: 0x1c-byte authenticator object, opaque.
        char authenticator[0x1c];
        fn_004097a0(authenticator, 0, crackedUrl.GetHostName());

        // INFERRED: result string storage written by the callee, destroyed afterwards.
        union {
            char raw[sizeof(std::string)];
            double align;
        } result;
        fn_004097c0(authenticator, 0, result.raw,
                    static_cast<LPCSTR>(CString(url)),
                    static_cast<LPCSTR>(CString(ticket)));
        reinterpret_cast<std::string*>(result.raw)->~basic_string();

        fn_0068b7e0(authenticator, 0);
    }
    catch (std::exception& e) {
        return reportWorkspaceSiteError(CLSID_App, e);
    }

    return S_OK;
}

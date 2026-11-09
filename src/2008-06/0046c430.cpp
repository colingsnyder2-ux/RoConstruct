// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_unit_11cb71645bae7820.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <atlbase.h>
#include <string>
#include <sstream>
#include <memory>
#include <exception>

template<class E> struct ImpStr : std::basic_string<E> { __declspec(noinline) const E* c_str() const { return std::basic_string<E>::c_str(); } };
extern template struct __declspec(dllimport) ImpStr<char>;
static inline const char* cstr(const std::string& x) { return static_cast<const ImpStr<char>&>(x).c_str(); }
namespace G3D { std::string __cdecl format(const char* fmt, ...); }
HRESULT __cdecl ReportError(const GUID& iid, const char* msg, HRESULT hr);
extern const GUID IID_IWorkspace;

struct PathString {
    char* m_pszData;
    __declspec(dllimport) PathString(const wchar_t* psz);
    __declspec(dllimport) operator const char*() const throw();
    __declspec(dllimport) ~PathString() throw();
};

namespace RBX {
class Name { public: static const Name& getNullName(); };
class ContentId {
public:
    ContentId(const char* id) : id(id), mimeTypePtr(&Name::getNullName()) {}
private:
    std::string id;
    const Name* mimeTypePtr;
};
class ContentProvider {
public:
    std::auto_ptr<std::istream> getContent(ContentId ticket);
};
class DataModel { public: ContentProvider* contentProvider(); };
inline ContentProvider* contentProvider(DataModel* dm) { return dm ? dm->contentProvider() : 0; }
void __cdecl copyStream(std::istream&, std::ostream&, int);
}

struct WorkspaceHead { void* a; void* b; };
struct SiteCheck { HRESULT CheckSite(); };

class VCWorkspace : public WorkspaceHead, public SiteCheck {
public:
    char pad[0x24 - 8];
    RBX::DataModel* dataModel;
    HRESULT execScript(const char* script, VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, IDispatch** result);
    HRESULT __stdcall ExecUrlScript(BSTR url, VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, IDispatch** result) throw();
};

HRESULT __stdcall VCWorkspace::ExecUrlScript(BSTR url, VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, IDispatch** result) throw()
{
    try {
        AFX_MANAGE_STATE(AfxGetAppModuleState());
        std::ostringstream stream;
        try {
            PathString s(url);
            std::auto_ptr<std::istream> content(RBX::contentProvider(dataModel)->getContent(RBX::ContentId(s)));
            RBX::copyStream(*content, stream, 4096);
        } catch (std::exception& e) {
            std::string message = G3D::format("Failed to get URL, %s", e.what());
            return ReportError(IID_IWorkspace, static_cast<const ImpStr<char>&>(message).c_str(), 0);
        }
        return execScript(cstr(stream.str()), arg1, arg2, arg3, arg4, result);
    } catch (CException* e) {
        char buffer[255];
        e->GetErrorMessage(buffer, 255);
        std::string message = G3D::format("CException %s", buffer);
        return ReportError(IID_IWorkspace, static_cast<const ImpStr<char>&>(message).c_str(), 0);
    } catch (ATL::CAtlException e) {
        std::string message = G3D::format("CAtlException %d", e.m_hr);
        return ReportError(IID_IWorkspace, static_cast<const ImpStr<char>&>(message).c_str(), 0);
    } catch (...) {
        return ReportError(IID_IWorkspace, "Unexpected exception", 0);
    }
}

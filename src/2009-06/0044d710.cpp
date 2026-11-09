// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace ATL {
class CAtlModule {
public:
	virtual ~CAtlModule() throw();
	virtual long Lock() throw();
	virtual long Unlock() throw();
};
extern CAtlModule* _pAtlModule;
class CComObjectRootBase { public: long m_dwRef; void FinalRelease() {} };
class CComObjectRootEx : public CComObjectRootBase {};
}
struct IWorkspace { virtual long __stdcall QueryInterface(const void*, void**) = 0; virtual unsigned long __stdcall AddRef() = 0; virtual unsigned long __stdcall Release() = 0; };
struct ISupportErrorInfo { virtual long __stdcall QueryInterface(const void*, void**) = 0; virtual unsigned long __stdcall AddRef() = 0; virtual unsigned long __stdcall Release() = 0; };
struct IObjectSafety { virtual long __stdcall QueryInterface(const void*, void**) = 0; virtual unsigned long __stdcall AddRef() = 0; virtual unsigned long __stdcall Release() = 0; };
struct IObjectWithSite { virtual long __stdcall QueryInterface(const void*, void**) = 0; virtual unsigned long __stdcall AddRef() = 0; virtual unsigned long __stdcall Release() = 0; };
class IObjectSafetyRobloxImpl : public IObjectSafety { public: unsigned long m_dwCurrentSafety; };
class IObjectWithSiteImpl : public IObjectWithSite { public: void* m_spUnkSite; };
class CWorkspace : public IWorkspace, public ATL::CComObjectRootEx, public ISupportErrorInfo, public IObjectSafetyRobloxImpl, public IObjectWithSiteImpl {
public:
	~CWorkspace();
	void FinalRelease();
};
namespace ATL {
template<class Base> class CComObject : public Base {
public:
	virtual ~CComObject() throw()
	{
		this->m_dwRef = -(0x7fffffff/2);
		this->FinalRelease();
		_pAtlModule->Unlock();
	}
	long __stdcall QueryInterface(const void*, void**);
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();
};
template class CComObject<CWorkspace>;
}

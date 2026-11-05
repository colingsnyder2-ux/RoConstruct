// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace std {
template<class E> struct char_traits {};
template<class E> class allocator {};
template<class E, class T = char_traits<E>, class A = allocator<E> >
class basic_string {
public:
    __declspec(noinline) basic_string() { storage[0] = 0; }
    __declspec(noinline) ~basic_string() { storage[1] = 0; }
    __declspec(noinline) const E* c_str() const { return (const E*)storage; }
private:
    char storage[0x1c];
};
extern template class __declspec(dllimport) basic_string<char>;
typedef basic_string<char> string;
}
namespace ATL {
template<class T> class ChTraitsCRT {};
}
template<class T, class U> class StrTraitMFC_DLL {};
namespace ATL {
template<class T, class Traits> class CStringT {
public:
    __declspec(noinline) CStringT(const T* s) : m_pszData((T*)s) {}
    __declspec(noinline) ~CStringT() throw() { m_pszData = 0; }
private:
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT<char, StrTraitMFC_DLL<char, ChTraitsCRT<char> > >;
}
typedef ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char> > > CString;
namespace G3D { class System { public: static void describeSystem(std::string& s); }; }
extern std::string versionString;
class CDataExchange { public: int m_bSaveAndValidate; };
class CDHtmlDialog {
public:
    virtual void DoDataExchange(CDataExchange* pDX);
    void DDX_DHtml_ElementText(CDataExchange* pDX, const char* szId, long dispid, CString& value);
};
class CAboutDlg : public CDHtmlDialog {
public:
    virtual void DoDataExchange(CDataExchange* pDX);
};
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    if (!pDX->m_bSaveAndValidate) {
        CString version(versionString.c_str());
        DDX_DHtml_ElementText(pDX, "Version", 0x80010402, version);
        std::string info;
        G3D::System::describeSystem(info);
        DDX_DHtml_ElementText(pDX, "systemInfo", 0x80010402, CString(info.c_str()));
    }
}

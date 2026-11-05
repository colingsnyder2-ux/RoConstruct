// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
#include <time.h>

typedef wchar_t* BSTR;
typedef long HRESULT;
extern "C" __declspec(dllimport) BSTR __stdcall SysAllocString(const wchar_t*);
extern "C" __declspec(dllimport) void __stdcall SysFreeString(BSTR);

namespace ATL {
__declspec(noreturn) void __stdcall AtlThrowImpl(HRESULT hr);
}

template <class T> class CStringT_ {
public:
    __declspec(noinline) CStringT_() { m_pszData = 0; }
    __declspec(noinline) CStringT_(const char* p) { m_pszData = 0; }
    __declspec(noinline) ~CStringT_() throw() { m_pszData = 0; }
    __declspec(noinline) T* GetBuffer(int n) { return m_pszData; }
    __declspec(noinline) void ReleaseBuffer(int n = -1) { }
    __declspec(noinline) CStringT_& operator=(const char* p) { return *this; }
    __declspec(noinline) CStringT_& operator+=(const char* p) { return *this; }
    __declspec(noinline) CStringT_& operator+=(const CStringT_& p) { return *this; }
    operator const T*() const throw() { return m_pszData; }
    int GetLength() const throw() { return ((const int*)m_pszData)[-3]; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT_<wchar_t>;
typedef CStringT_<wchar_t> CString;

namespace ATL {
class CComBSTR {
public:
    BSTR m_str;
    CComBSTR(const char* p);
    CComBSTR(const wchar_t* p)
    {
        if (p == 0)
            m_str = 0;
        else {
            m_str = SysAllocString(p);
            if (m_str == 0)
                AtlThrowImpl(0x8007000E);
        }
    }
    ~CComBSTR() throw() { SysFreeString(m_str); }
    operator BSTR() const throw() { return m_str; }
};

template <class T> class CComPtr {
public:
    T* p;
    CComPtr() throw() : p(0) {}
    ~CComPtr() throw() { if (p) p->Release(); }
    operator T*() const throw() { return p; }
    T** operator&() throw() { return &p; }
    T* operator->() const throw() { return p; }
};
}

int __cdecl EscapeXML(const wchar_t* szIn, int nSrcLen, wchar_t* szEsc, int nDestLen, unsigned long dwFlags);

struct IHTMLElement {
    virtual HRESULT __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall slot3() = 0; virtual void __stdcall slot4() = 0; virtual void __stdcall slot5() = 0;
    virtual void __stdcall slot6() = 0; virtual void __stdcall slot7() = 0; virtual void __stdcall slot8() = 0;
    virtual void __stdcall slot9() = 0; virtual void __stdcall slot10() = 0; virtual void __stdcall slot11() = 0;
    virtual void __stdcall slot12() = 0; virtual void __stdcall slot13() = 0; virtual void __stdcall slot14() = 0;
    virtual void __stdcall slot15() = 0; virtual void __stdcall slot16() = 0; virtual void __stdcall slot17() = 0;
    virtual void __stdcall slot18() = 0; virtual void __stdcall slot19() = 0; virtual void __stdcall slot20() = 0;
    virtual void __stdcall slot21() = 0; virtual void __stdcall slot22() = 0; virtual void __stdcall slot23() = 0;
    virtual void __stdcall slot24() = 0; virtual void __stdcall slot25() = 0; virtual void __stdcall slot26() = 0;
    virtual void __stdcall slot27() = 0; virtual void __stdcall slot28() = 0; virtual void __stdcall slot29() = 0;
    virtual void __stdcall slot30() = 0; virtual void __stdcall slot31() = 0; virtual void __stdcall slot32() = 0;
    virtual void __stdcall slot33() = 0; virtual void __stdcall slot34() = 0; virtual void __stdcall slot35() = 0;
    virtual void __stdcall slot36() = 0; virtual void __stdcall slot37() = 0; virtual void __stdcall slot38() = 0;
    virtual void __stdcall slot39() = 0; virtual void __stdcall slot40() = 0; virtual void __stdcall slot41() = 0;
    virtual void __stdcall slot42() = 0; virtual void __stdcall slot43() = 0; virtual void __stdcall slot44() = 0;
    virtual void __stdcall slot45() = 0; virtual void __stdcall slot46() = 0; virtual void __stdcall slot47() = 0;
    virtual void __stdcall slot48() = 0; virtual void __stdcall slot49() = 0; virtual void __stdcall slot50() = 0;
    virtual void __stdcall slot51() = 0; virtual void __stdcall slot52() = 0; virtual void __stdcall slot53() = 0;
    virtual void __stdcall slot54() = 0; virtual void __stdcall slot55() = 0; virtual void __stdcall slot56() = 0;
    virtual HRESULT __stdcall put_innerHTML(BSTR v) = 0;
};

struct IHTMLDocument2 {
    virtual void __stdcall s0() = 0; virtual void __stdcall s1() = 0; virtual void __stdcall s2() = 0;
    virtual void __stdcall s3() = 0; virtual void __stdcall s4() = 0; virtual void __stdcall s5() = 0;
    virtual void __stdcall s6() = 0; virtual void __stdcall s7() = 0; virtual void __stdcall s8() = 0;
    virtual void __stdcall s9() = 0; virtual void __stdcall s10() = 0; virtual void __stdcall s11() = 0;
    virtual void __stdcall s12() = 0; virtual void __stdcall s13() = 0; virtual void __stdcall s14() = 0;
    virtual void __stdcall s15() = 0; virtual void __stdcall s16() = 0; virtual void __stdcall s17() = 0;
    virtual void __stdcall s18() = 0; virtual void __stdcall s19() = 0; virtual void __stdcall s20() = 0;
    virtual void __stdcall s21() = 0; virtual void __stdcall s22() = 0; virtual void __stdcall s23() = 0;
    virtual void __stdcall s24() = 0; virtual void __stdcall s25() = 0; virtual void __stdcall s26() = 0;
    virtual void __stdcall s27() = 0; virtual void __stdcall s28() = 0; virtual void __stdcall s29() = 0;
    virtual void __stdcall s30() = 0; virtual void __stdcall s31() = 0; virtual void __stdcall s32() = 0;
    virtual void __stdcall s33() = 0; virtual void __stdcall s34() = 0; virtual void __stdcall s35() = 0;
    virtual void __stdcall s36() = 0; virtual void __stdcall s37() = 0; virtual void __stdcall s38() = 0;
    virtual void __stdcall s39() = 0; virtual void __stdcall s40() = 0; virtual void __stdcall s41() = 0;
    virtual void __stdcall s42() = 0; virtual void __stdcall s43() = 0; virtual void __stdcall s44() = 0;
    virtual void __stdcall s45() = 0; virtual void __stdcall s46() = 0; virtual void __stdcall s47() = 0;
    virtual void __stdcall s48() = 0; virtual void __stdcall s49() = 0; virtual void __stdcall s50() = 0;
    virtual void __stdcall s51() = 0; virtual void __stdcall s52() = 0; virtual void __stdcall s53() = 0;
    virtual void __stdcall s54() = 0; virtual void __stdcall s55() = 0; virtual void __stdcall s56() = 0;
    virtual void __stdcall s57() = 0; virtual void __stdcall s58() = 0; virtual void __stdcall s59() = 0;
    virtual void __stdcall s60() = 0; virtual void __stdcall s61() = 0; virtual void __stdcall s62() = 0;
    virtual void __stdcall s63() = 0; virtual void __stdcall s64() = 0; virtual void __stdcall s65() = 0;
    virtual void __stdcall s66() = 0; virtual void __stdcall s67() = 0; virtual void __stdcall s68() = 0;
    virtual void __stdcall s69() = 0; virtual void __stdcall s70() = 0; virtual void __stdcall s71() = 0;
    virtual HRESULT __stdcall createElement(BSTR eTag, IHTMLElement** newElem) = 0;
};

class COutputView {
public:
    char pad[0x118];
    IHTMLDocument2* m_pDocument;
    void appendElement(IHTMLElement* element);
};

class CStandardOutputView : public COutputView {
public:
    void appendText(int type, const char* text, __time64_t time);
};

void CStandardOutputView::appendText(int type, const char* text, __time64_t time)
{
    CString message(text);
    CString escaped;
    int length = EscapeXML(message, message.GetLength(), 0, 0, 0);
    EscapeXML(message, message.GetLength(), escaped.GetBuffer(length), length, 0);
    escaped.ReleaseBuffer();

    CString html;
    if (type != 0 && time != 0) {
        char buffer[32];
        _ctime64_s(buffer, 32, &time);
        html = buffer;
        html += " - ";
    }

    switch (type) {
    case 1:
        html += "<FONT color=\"blue\">";
        html += escaped;
        html += "</FONT>";
        break;
    case 2:
        html += "<STRONG><FONT color=\"orange\">";
        html += escaped;
        html += "</FONT>";
        break;
    case 3:
        html += "<STRONG><FONT color=\"red\">";
        html += escaped;
        html += "</FONT>";
        break;
    case 0:
        html += escaped;
        break;
    }

    ATL::CComPtr<IHTMLElement> element;
    IHTMLDocument2* document = m_pDocument;
    if (document) {
        document->createElement(ATL::CComBSTR("DIV"), &element);
        element->put_innerHTML(ATL::CComBSTR((const wchar_t*)html));
        appendElement(element);
    }
}

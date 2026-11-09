// from server: 100% by Yeetserama
// roc 2010-06 00431e50  unit: RBX::$$A6AXABUStandardOutMessage::?$signal::slot  size: 588 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00431e50
//
// 00431e50  6aff                 push -1
// 00431e52  6893069800           push 0x980693
// 00431e57  64a100000000         mov eax, dword ptr fs:[0]
// 00431e5d  50                   push eax
// 00431e5e  64892500000000       mov dword ptr fs:[0], esp
// 00431e65  83ec2c               sub esp, 0x2c
// 00431e68  8b442440             mov eax, dword ptr [esp + 0x40]
// 00431e6c  53                   push ebx
// 00431e6d  55                   push ebp
// 00431e6e  56                   push esi
// 00431e6f  57                   push edi
// 00431e70  8be9                 mov ebp, ecx
// 00431e72  50                   push eax
// 00431e73  8d4c241c             lea ecx, [esp + 0x1c]
// 00431e77  ff1574c19e00         call dword ptr [0x9ec174]
// 00431e7d  8d4c2410             lea ecx, [esp + 0x10]
// 00431e81  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00431e89  ff1578c19e00         call dword ptr [0x9ec178]
// 00431e8f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00431e93  8b48f4               mov ecx, dword ptr [eax - 0xc]
// 00431e96  6a00                 push 0
// 00431e98  6a00                 push 0
// 00431e9a  6a00                 push 0
// 00431e9c  51                   push ecx
// 00431e9d  50                   push eax
// 00431e9e  c644245801           mov byte ptr [esp + 0x58], 1
// 00431ea3  e8b8ecffff           call 0x430b60
// 00431ea8  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00431eac  8b71f4               mov esi, dword ptr [ecx - 0xc]
// 00431eaf  83c414               add esp, 0x14
// 00431eb2  6a00                 push 0
// 00431eb4  50                   push eax
// 00431eb5  8bf9                 mov edi, ecx
// 00431eb7  50                   push eax
// 00431eb8  8d4c241c             lea ecx, [esp + 0x1c]
// 00431ebc  ff157cc19e00         call dword ptr [0x9ec17c]
// 00431ec2  50                   push eax
// 00431ec3  56                   push esi
// 00431ec4  57                   push edi
// 00431ec5  e896ecffff           call 0x430b60
// 00431eca  83c414               add esp, 0x14
// 00431ecd  6aff                 push -1
// 00431ecf  8d4c2414             lea ecx, [esp + 0x14]
// 00431ed3  ff1580c19e00         call dword ptr [0x9ec180]
// 00431ed9  8d4c2450             lea ecx, [esp + 0x50]
// 00431edd  ff1578c19e00         call dword ptr [0x9ec178]
// 00431ee3  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 00431ee7  c644244402           mov byte ptr [esp + 0x44], 2
// 00431eec  85f6                 test esi, esi
// 00431eee  743d                 je 0x431f2d
// 00431ef0  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00431ef4  0b4c2458             or ecx, dword ptr [esp + 0x58]
// 00431ef8  7433                 je 0x431f2d
// 00431efa  8d542454             lea edx, [esp + 0x54]
// 00431efe  52                   push edx
// 00431eff  8d442420             lea eax, [esp + 0x20]
// 00431f03  6a20                 push 0x20
// 00431f05  50                   push eax
// 00431f06  ff156ca89e00         call dword ptr [0x9ea86c]
// 00431f0c  83c40c               add esp, 0xc
// 00431f0f  8d4c241c             lea ecx, [esp + 0x1c]
// 00431f13  51                   push ecx
// 00431f14  8d4c2454             lea ecx, [esp + 0x54]
// 00431f18  ff1584c19e00         call dword ptr [0x9ec184]
// 00431f1e  682073a000           push 0xa07320
// 00431f23  8d4c2454             lea ecx, [esp + 0x54]
// 00431f27  ff1588c19e00         call dword ptr [0x9ec188]
// 00431f2d  83fe03               cmp esi, 3
// 00431f30  7771                 ja 0x431fa3
// 00431f32  ff24b58c204300       jmp dword ptr [esi*4 + 0x43208c]
// 00431f39  680c73a000           push 0xa0730c
// 00431f3e  8d4c2454             lea ecx, [esp + 0x54]
// 00431f42  ff1588c19e00         call dword ptr [0x9ec188]
// 00431f48  8d542410             lea edx, [esp + 0x10]
// 00431f4c  52                   push edx
// 00431f4d  8d4c2454             lea ecx, [esp + 0x54]
// 00431f51  ff158cc19e00         call dword ptr [0x9ec18c]
// 00431f57  680473a000           push 0xa07304
// 00431f5c  8d4c2454             lea ecx, [esp + 0x54]
// 00431f60  ff1588c19e00         call dword ptr [0x9ec188]
// 00431f66  eb3b                 jmp 0x431fa3
// 00431f68  68e472a000           push 0xa072e4
// 00431f6d  8d4c2454             lea ecx, [esp + 0x54]
// 00431f71  ff1588c19e00         call dword ptr [0x9ec188]
// 00431f77  8d442410             lea eax, [esp + 0x10]
// 00431f7b  50                   push eax
// 00431f7c  ebcf                 jmp 0x431f4d
// 00431f7e  68c872a000           push 0xa072c8
// 00431f83  8d4c2454             lea ecx, [esp + 0x54]
// 00431f87  ff1588c19e00         call dword ptr [0x9ec188]
// 00431f8d  8d4c2410             lea ecx, [esp + 0x10]
// 00431f91  51                   push ecx
// 00431f92  ebb9                 jmp 0x431f4d
// 00431f94  8d542410             lea edx, [esp + 0x10]
// 00431f98  52                   push edx
// 00431f99  8d4c2454             lea ecx, [esp + 0x54]
// 00431f9d  ff158cc19e00         call dword ptr [0x9ec18c]
// 00431fa3  33c0                 xor eax, eax
// 00431fa5  89442414             mov dword ptr [esp + 0x14], eax
// 00431fa9  8bb518010000         mov esi, dword ptr [ebp + 0x118]
// 00431faf  c644244403           mov byte ptr [esp + 0x44], 3
// 00431fb4  85f6                 test esi, esi
// 00431fb6  7473                 je 0x43202b
// 00431fb8  68c472a000           push 0xa072c4
// 00431fbd  8d4c2450             lea ecx, [esp + 0x50]
// 00431fc1  e82a1cfdff           call 0x403bf0
// 00431fc6  8b00                 mov eax, dword ptr [eax]
// 00431fc8  8b0e                 mov ecx, dword ptr [esi]
// 00431fca  8d542414             lea edx, [esp + 0x14]
// 00431fce  52                   push edx
// 00431fcf  50                   push eax
// 00431fd0  8b8120010000         mov eax, dword ptr [ecx + 0x120]
// 00431fd6  56                   push esi
// 00431fd7  c644245004           mov byte ptr [esp + 0x50], 4
// 00431fdc  ffd0                 call eax
// 00431fde  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00431fe2  8b1d40aa9e00         mov ebx, dword ptr [0x9eaa40]
// 00431fe8  51                   push ecx
// 00431fe9  c644244803           mov byte ptr [esp + 0x48], 3
// 00431fee  ffd3                 call ebx
// 00431ff0  8b442450             mov eax, dword ptr [esp + 0x50]
// 00431ff4  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00431ff8  85c0                 test eax, eax
// 00431ffa  7573                 jne 0x43206f
// 00431ffc  33f6                 xor esi, esi
// 00431ffe  8974244c             mov dword ptr [esp + 0x4c], esi
// 00432002  8b17                 mov edx, dword ptr [edi]
// 00432004  8b82e4000000         mov eax, dword ptr [edx + 0xe4]
// 0043200a  56                   push esi
// 0043200b  57                   push edi
// 0043200c  c644244c05           mov byte ptr [esp + 0x4c], 5
// 00432011  ffd0                 call eax
// 00432013  56                   push esi
// 00432014  c644244803           mov byte ptr [esp + 0x48], 3
// 00432019  ffd3                 call ebx
// 0043201b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043201f  51                   push ecx
// 00432020  8bcd                 mov ecx, ebp
// 00432022  e849f9ffff           call 0x431970
// 00432027  8b442414             mov eax, dword ptr [esp + 0x14]
// 0043202b  c644244402           mov byte ptr [esp + 0x44], 2
// 00432030  85c0                 test eax, eax
// 00432032  7408                 je 0x43203c
// 00432034  8b10                 mov edx, dword ptr [eax]
// 00432036  50                   push eax
// 00432037  8b4208               mov eax, dword ptr [edx + 8]
// 0043203a  ffd0                 call eax
// 0043203c  8d4c2450             lea ecx, [esp + 0x50]
// 00432040  ff1590c19e00         call dword ptr [0x9ec190]
// 00432046  8d4c2410             lea ecx, [esp + 0x10]
// 0043204a  ff1590c19e00         call dword ptr [0x9ec190]
// 00432050  8d4c2418             lea ecx, [esp + 0x18]
// 00432054  ff1590c19e00         call dword ptr [0x9ec190]
// 0043205a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0043205e  5f                   pop edi
// 0043205f  5e                   pop esi
// 00432060  5d                   pop ebp
// 00432061  5b                   pop ebx
// 00432062  64890d00000000       mov dword ptr fs:[0], ecx
// 00432069  83c438               add esp, 0x38
// 0043206c  c21000               ret 0x10
// 0043206f  50                   push eax
// 00432070  ff1580aa9e00         call dword ptr [0x9eaa80]
// 00432076  8bf0                 mov esi, eax
// 00432078  8974244c             mov dword ptr [esp + 0x4c], esi
// 0043207c  85f6                 test esi, esi
// 0043207e  7582                 jne 0x432002
// 00432080  680e000780           push 0x8007000e
// 00432085  e8460bfdff           call 0x402bd0
// 0043208a  8bff                 mov edi, edi
// 0043208c  94                   xchg esp, eax
// 0043208d  1f                   pop ds
// 0043208e  43                   inc ebx
// 0043208f  0039                 add byte ptr [ecx], bh
// 00432091  1f                   pop ds
// 00432092  43                   inc ebx
// 00432093  00681f               add byte ptr [eax + 0x1f], ch
// 00432096  43                   inc ebx
// 00432097  007e1f               add byte ptr [esi + 0x1f], bh
// 0043209a  43                   inc ebx
// copied from an identical function in another client (function ?appendText@CStandardOutputView@@QAEXHPBD_J@Z)

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
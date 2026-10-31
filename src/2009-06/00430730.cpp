// from server: 100% by EspClaude
// roc 2009-06 00430730  unit: RBX::$$A6AXABUStandardOutMessage::?$signal::slot  size: 588 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00430730
//
// 00430730  6aff                 push -1
// 00430732  6823f78400           push 0x84f723
// 00430737  64a100000000         mov eax, dword ptr fs:[0]
// 0043073d  50                   push eax
// 0043073e  64892500000000       mov dword ptr fs:[0], esp
// 00430745  83ec2c               sub esp, 0x2c
// 00430748  8b442440             mov eax, dword ptr [esp + 0x40]
// 0043074c  53                   push ebx
// 0043074d  55                   push ebp
// 0043074e  56                   push esi
// 0043074f  57                   push edi
// 00430750  8be9                 mov ebp, ecx
// 00430752  50                   push eax
// 00430753  8d4c241c             lea ecx, [esp + 0x1c]
// 00430757  ff1544f28900         call dword ptr [0x89f244]
// 0043075d  8d4c2410             lea ecx, [esp + 0x10]
// 00430761  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00430769  ff1540f28900         call dword ptr [0x89f240]
// 0043076f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00430773  8b48f4               mov ecx, dword ptr [eax - 0xc]
// 00430776  6a00                 push 0
// 00430778  6a00                 push 0
// 0043077a  6a00                 push 0
// 0043077c  51                   push ecx
// 0043077d  50                   push eax
// 0043077e  c644245801           mov byte ptr [esp + 0x58], 1
// 00430783  e8a8edffff           call 0x42f530
// 00430788  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0043078c  8b71f4               mov esi, dword ptr [ecx - 0xc]
// 0043078f  83c414               add esp, 0x14
// 00430792  6a00                 push 0
// 00430794  50                   push eax
// 00430795  8bf9                 mov edi, ecx
// 00430797  50                   push eax
// 00430798  8d4c241c             lea ecx, [esp + 0x1c]
// 0043079c  ff153cf28900         call dword ptr [0x89f23c]
// 004307a2  50                   push eax
// 004307a3  56                   push esi
// 004307a4  57                   push edi
// 004307a5  e886edffff           call 0x42f530
// 004307aa  83c414               add esp, 0x14
// 004307ad  6aff                 push -1
// 004307af  8d4c2414             lea ecx, [esp + 0x14]
// 004307b3  ff1538f28900         call dword ptr [0x89f238]
// 004307b9  8d4c2450             lea ecx, [esp + 0x50]
// 004307bd  ff1540f28900         call dword ptr [0x89f240]
// 004307c3  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 004307c7  c644244402           mov byte ptr [esp + 0x44], 2
// 004307cc  85f6                 test esi, esi
// 004307ce  743d                 je 0x43080d
// 004307d0  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004307d4  0b4c2458             or ecx, dword ptr [esp + 0x58]
// 004307d8  7433                 je 0x43080d
// 004307da  8d542454             lea edx, [esp + 0x54]
// 004307de  52                   push edx
// 004307df  8d442420             lea eax, [esp + 0x20]
// 004307e3  6a20                 push 0x20
// 004307e5  50                   push eax
// 004307e6  ff1540e98900         call dword ptr [0x89e940]
// 004307ec  83c40c               add esp, 0xc
// 004307ef  8d4c241c             lea ecx, [esp + 0x1c]
// 004307f3  51                   push ecx
// 004307f4  8d4c2454             lea ecx, [esp + 0x54]
// 004307f8  ff1534f28900         call dword ptr [0x89f234]
// 004307fe  6830388b00           push 0x8b3830
// 00430803  8d4c2454             lea ecx, [esp + 0x54]
// 00430807  ff1530f28900         call dword ptr [0x89f230]
// 0043080d  83fe03               cmp esi, 3
// 00430810  7771                 ja 0x430883
// 00430812  ff24b56c094300       jmp dword ptr [esi*4 + 0x43096c]
// 00430819  681c388b00           push 0x8b381c
// 0043081e  8d4c2454             lea ecx, [esp + 0x54]
// 00430822  ff1530f28900         call dword ptr [0x89f230]
// 00430828  8d542410             lea edx, [esp + 0x10]
// 0043082c  52                   push edx
// 0043082d  8d4c2454             lea ecx, [esp + 0x54]
// 00430831  ff152cf28900         call dword ptr [0x89f22c]
// 00430837  6814388b00           push 0x8b3814
// 0043083c  8d4c2454             lea ecx, [esp + 0x54]
// 00430840  ff1530f28900         call dword ptr [0x89f230]
// 00430846  eb3b                 jmp 0x430883
// 00430848  68f4378b00           push 0x8b37f4
// 0043084d  8d4c2454             lea ecx, [esp + 0x54]
// 00430851  ff1530f28900         call dword ptr [0x89f230]
// 00430857  8d442410             lea eax, [esp + 0x10]
// 0043085b  50                   push eax
// 0043085c  ebcf                 jmp 0x43082d
// 0043085e  68d8378b00           push 0x8b37d8
// 00430863  8d4c2454             lea ecx, [esp + 0x54]
// 00430867  ff1530f28900         call dword ptr [0x89f230]
// 0043086d  8d4c2410             lea ecx, [esp + 0x10]
// 00430871  51                   push ecx
// 00430872  ebb9                 jmp 0x43082d
// 00430874  8d542410             lea edx, [esp + 0x10]
// 00430878  52                   push edx
// 00430879  8d4c2454             lea ecx, [esp + 0x54]
// 0043087d  ff152cf28900         call dword ptr [0x89f22c]
// 00430883  33c0                 xor eax, eax
// 00430885  89442414             mov dword ptr [esp + 0x14], eax
// 00430889  8bb518010000         mov esi, dword ptr [ebp + 0x118]
// 0043088f  c644244403           mov byte ptr [esp + 0x44], 3
// 00430894  85f6                 test esi, esi
// 00430896  7473                 je 0x43090b
// 00430898  68d4378b00           push 0x8b37d4
// 0043089d  8d4c2450             lea ecx, [esp + 0x50]
// 004308a1  e82a36fdff           call 0x403ed0
// 004308a6  8b00                 mov eax, dword ptr [eax]
// 004308a8  8b0e                 mov ecx, dword ptr [esi]
// 004308aa  8d542414             lea edx, [esp + 0x14]
// 004308ae  52                   push edx
// 004308af  50                   push eax
// 004308b0  8b8120010000         mov eax, dword ptr [ecx + 0x120]
// 004308b6  56                   push esi
// 004308b7  c644245004           mov byte ptr [esp + 0x50], 4
// 004308bc  ffd0                 call eax
// 004308be  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004308c2  8b1d3cea8900         mov ebx, dword ptr [0x89ea3c]
// 004308c8  51                   push ecx
// 004308c9  c644244803           mov byte ptr [esp + 0x48], 3
// 004308ce  ffd3                 call ebx
// 004308d0  8b442450             mov eax, dword ptr [esp + 0x50]
// 004308d4  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004308d8  85c0                 test eax, eax
// 004308da  7573                 jne 0x43094f
// 004308dc  33f6                 xor esi, esi
// 004308de  8974244c             mov dword ptr [esp + 0x4c], esi
// 004308e2  8b17                 mov edx, dword ptr [edi]
// 004308e4  8b82e4000000         mov eax, dword ptr [edx + 0xe4]
// 004308ea  56                   push esi
// 004308eb  57                   push edi
// 004308ec  c644244c05           mov byte ptr [esp + 0x4c], 5
// 004308f1  ffd0                 call eax
// 004308f3  56                   push esi
// 004308f4  c644244803           mov byte ptr [esp + 0x48], 3
// 004308f9  ffd3                 call ebx
// 004308fb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004308ff  51                   push ecx
// 00430900  8bcd                 mov ecx, ebp
// 00430902  e839f9ffff           call 0x430240
// 00430907  8b442414             mov eax, dword ptr [esp + 0x14]
// 0043090b  c644244402           mov byte ptr [esp + 0x44], 2
// 00430910  85c0                 test eax, eax
// 00430912  7408                 je 0x43091c
// 00430914  8b10                 mov edx, dword ptr [eax]
// 00430916  50                   push eax
// 00430917  8b4208               mov eax, dword ptr [edx + 8]
// 0043091a  ffd0                 call eax
// 0043091c  8d4c2450             lea ecx, [esp + 0x50]
// 00430920  ff1528f28900         call dword ptr [0x89f228]
// 00430926  8d4c2410             lea ecx, [esp + 0x10]
// 0043092a  ff1528f28900         call dword ptr [0x89f228]
// 00430930  8d4c2418             lea ecx, [esp + 0x18]
// 00430934  ff1528f28900         call dword ptr [0x89f228]
// 0043093a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0043093e  5f                   pop edi
// 0043093f  5e                   pop esi
// 00430940  5d                   pop ebp
// 00430941  5b                   pop ebx
// 00430942  64890d00000000       mov dword ptr fs:[0], ecx
// 00430949  83c438               add esp, 0x38
// 0043094c  c21000               ret 0x10
// 0043094f  50                   push eax
// 00430950  ff15d8e98900         call dword ptr [0x89e9d8]
// 00430956  8bf0                 mov esi, eax
// 00430958  8974244c             mov dword ptr [esp + 0x4c], esi
// 0043095c  85f6                 test esi, esi
// 0043095e  7582                 jne 0x4308e2
// 00430960  680e000780           push 0x8007000e
// 00430965  e84625fdff           call 0x402eb0
// 0043096a  8bff                 mov edi, edi
// 0043096c  7408                 je 0x430976
// 0043096e  43                   inc ebx
// 0043096f  0019                 add byte ptr [ecx], bl
// 00430971  084300               or byte ptr [ebx], al
// 00430974  48                   dec eax
// 00430975  084300               or byte ptr [ebx], al
// 00430978  5e                   pop esi
// 00430979  084300               or byte ptr [ebx], al
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
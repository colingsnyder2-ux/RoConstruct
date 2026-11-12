// from server: 45% by EspClaude
// from server: 44% by colin
// roc 2007-08 0044cd90  unit: CRobloxDHtmlDialog  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044cd90
//
// 0044cd90  6aff                 push -1
// 0044cd92  6849317600           push 0x763149
// 0044cd97  64a100000000         mov eax, dword ptr fs:[0]
// 0044cd9d  50                   push eax
// 0044cd9e  56                   push esi
// 0044cd9f  57                   push edi
// 0044cda0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044cda5  33c4                 xor eax, esp
// 0044cda7  50                   push eax
// 0044cda8  8d44240c             lea eax, [esp + 0xc]
// 0044cdac  64a300000000         mov dword ptr fs:[0], eax
// 0044cdb2  8bf1                 mov esi, ecx
// 0044cdb4  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044cdb8  8b4808               mov ecx, dword ptr [eax + 8]
// 0044cdbb  51                   push ecx
// 0044cdbc  8d4c2424             lea ecx, [esp + 0x24]
// 0044cdc0  ff1590dd7700         call dword ptr [0x77dd90]
// 0044cdc6  8d4c2420             lea ecx, [esp + 0x20]
// 0044cdca  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044cdd2  ff1598dd7700         call dword ptr [0x77dd98]
// 0044cdd8  50                   push eax
// 0044cdd9  e882effcff           call 0x41bd60
// 0044cdde  83c404               add esp, 4
// 0044cde1  85c0                 test eax, eax
// 0044cde3  740c                 je 0x44cdf1
// 0044cde5  8b542434             mov edx, dword ptr [esp + 0x34]
// 0044cde9  c70201000000         mov dword ptr [edx], 1
// 0044cdef  eb1c                 jmp 0x44ce0d
// 0044cdf1  8b3e                 mov edi, dword ptr [esi]
// 0044cdf3  8d4c2420             lea ecx, [esp + 0x20]
// 0044cdf7  ff1598dd7700         call dword ptr [0x77dd98]
// 0044cdfd  8b9768010000         mov edx, dword ptr [edi + 0x168]
// 0044ce03  50                   push eax
// 0044ce04  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044ce08  50                   push eax
// 0044ce09  8bce                 mov ecx, esi
// 0044ce0b  ffd2                 call edx
// 0044ce0d  8d4c2420             lea ecx, [esp + 0x20]
// 0044ce11  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0044ce17  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044ce1b  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ce22  59                   pop ecx
// 0044ce23  5f                   pop edi
// 0044ce24  5e                   pop esi
// 0044ce25  83c40c               add esp, 0xc
// 0044ce28  c21c00               ret 0x1c

typedef unsigned short wchar;
struct VARIANT_ { unsigned short vt; unsigned short r1, r2, r3; wchar* bstrVal; };
struct IDispatch;

class CStr {
public:
    __declspec(dllimport) CStr(const wchar* p);
    __declspec(dllimport) ~CStr() throw();
    __declspec(dllimport) operator const char*() const;
private:
    char* m_p;
};

int IsSpecialUrl(const char* url);

class CRobloxDHtmlDialog {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void Navigate(IDispatch* pDisp, const char* url); // slot 0x168
    void OnBeforeNavigate(IDispatch* pDisp, VARIANT_* URL, VARIANT_* Flags, VARIANT_* Target,
                          VARIANT_* PostData, VARIANT_* Headers, int* Cancel);
};

void CRobloxDHtmlDialog::OnBeforeNavigate(IDispatch* pDisp, VARIANT_* URL, VARIANT_* Flags, VARIANT_* Target,
                                          VARIANT_* PostData, VARIANT_* Headers, int* Cancel)
{
    CStr url(URL->bstrVal);
    if (IsSpecialUrl(url))
        *Cancel = 1;
    else
        Navigate(pDisp, url);
}

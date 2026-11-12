// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 0040c970  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 409 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040c970
//
// 0040c970  6aff                 push -1
// 0040c972  68599c7300           push 0x739c59
// 0040c977  64a100000000         mov eax, dword ptr fs:[0]
// 0040c97d  50                   push eax
// 0040c97e  83ec14               sub esp, 0x14
// 0040c981  53                   push ebx
// 0040c982  56                   push esi
// 0040c983  57                   push edi
// 0040c984  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040c989  33c4                 xor eax, esp
// 0040c98b  50                   push eax
// 0040c98c  8d442424             lea eax, [esp + 0x24]
// 0040c990  64a300000000         mov dword ptr fs:[0], eax
// 0040c996  e8a9352200           call 0x62ff44
// 0040c99b  50                   push eax
// 0040c99c  8d4c2418             lea ecx, [esp + 0x18]
// 0040c9a0  e899352200           call 0x62ff3e
// 0040c9a5  33db                 xor ebx, ebx
// 0040c9a7  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0040c9ab  895c2410             mov dword ptr [esp + 0x10], ebx
// 0040c9af  8d442410             lea eax, [esp + 0x10]
// 0040c9b3  50                   push eax
// 0040c9b4  683c527800           push 0x78523c
// 0040c9b9  6a17                 push 0x17
// 0040c9bb  53                   push ebx
// 0040c9bc  6890027900           push 0x790290
// 0040c9c1  c644244001           mov byte ptr [esp + 0x40], 1
// 0040c9c6  ff1518f07700         call dword ptr [0x77f018]
// 0040c9cc  8bf0                 mov esi, eax
// 0040c9ce  3bf3                 cmp esi, ebx
// 0040c9d0  0f849b000000         je 0x40ca71
// 0040c9d6  8d4c2438             lea ecx, [esp + 0x38]
// 0040c9da  ff15acdd7700         call dword ptr [0x77ddac]
// 0040c9e0  56                   push esi
// 0040c9e1  8d4c243c             lea ecx, [esp + 0x3c]
// 0040c9e5  6808647800           push 0x786408
// 0040c9ea  51                   push ecx
// 0040c9eb  c644243802           mov byte ptr [esp + 0x38], 2
// 0040c9f0  ff1594dd7700         call dword ptr [0x77dd94]
// 0040c9f6  83c40c               add esp, 0xc
// 0040c9f9  56                   push esi
// 0040c9fa  8d4c243c             lea ecx, [esp + 0x3c]
// 0040c9fe  ff1598dd7700         call dword ptr [0x77dd98]
// 0040ca04  50                   push eax
// 0040ca05  68d0027900           push 0x7902d0
// 0040ca0a  e811c80100           call 0x429220
// 0040ca0f  83c40c               add esp, 0xc
// 0040ca12  8d4c2438             lea ecx, [esp + 0x38]
// 0040ca16  8bf0                 mov esi, eax
// 0040ca18  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0040ca1e  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040ca22  3bc3                 cmp eax, ebx
// 0040ca24  885c242c             mov byte ptr [esp + 0x2c], bl
// 0040ca28  7408                 je 0x40ca32
// 0040ca2a  8b10                 mov edx, dword ptr [eax]
// 0040ca2c  50                   push eax
// 0040ca2d  8b4208               mov eax, dword ptr [edx + 8]
// 0040ca30  ffd0                 call eax
// 0040ca32  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040ca36  3bc3                 cmp eax, ebx
// 0040ca38  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0040ca40  7407                 je 0x40ca49
// 0040ca42  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040ca46  894804               mov dword ptr [eax + 4], ecx
// 0040ca49  395c2420             cmp dword ptr [esp + 0x20], ebx
// 0040ca4d  740b                 je 0x40ca5a
// 0040ca4f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040ca53  52                   push edx
// 0040ca54  53                   push ebx
// 0040ca55  e8de342200           call 0x62ff38
// 0040ca5a  8bc6                 mov eax, esi
// 0040ca5c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0040ca60  64890d00000000       mov dword ptr fs:[0], ecx
// 0040ca67  59                   pop ecx
// 0040ca68  5f                   pop edi
// 0040ca69  5e                   pop esi
// 0040ca6a  5b                   pop ebx
// 0040ca6b  83c420               add esp, 0x20
// 0040ca6e  c20800               ret 8
// 0040ca71  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040ca75  3bc3                 cmp eax, ebx
// 0040ca77  8bf0                 mov esi, eax
// 0040ca79  740c                 je 0x40ca87
// 0040ca7b  8b08                 mov ecx, dword ptr [eax]
// 0040ca7d  8b5104               mov edx, dword ptr [ecx + 4]
// 0040ca80  50                   push eax
// 0040ca81  ffd2                 call edx
// 0040ca83  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040ca87  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0040ca8b  3bcb                 cmp ecx, ebx
// 0040ca8d  7507                 jne 0x40ca96
// 0040ca8f  bf03400080           mov edi, 0x80004003
// 0040ca94  eb14                 jmp 0x40caaa
// 0040ca96  3bf3                 cmp esi, ebx
// 0040ca98  8931                 mov dword ptr [ecx], esi
// 0040ca9a  740c                 je 0x40caa8
// 0040ca9c  8b06                 mov eax, dword ptr [esi]
// 0040ca9e  8b4804               mov ecx, dword ptr [eax + 4]
// 0040caa1  56                   push esi
// 0040caa2  ffd1                 call ecx
// 0040caa4  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040caa8  33ff                 xor edi, edi
// 0040caaa  3bf3                 cmp esi, ebx
// 0040caac  740c                 je 0x40caba
// 0040caae  8b16                 mov edx, dword ptr [esi]
// 0040cab0  8b4208               mov eax, dword ptr [edx + 8]
// 0040cab3  56                   push esi
// 0040cab4  ffd0                 call eax
// 0040cab6  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040caba  3bc3                 cmp eax, ebx
// 0040cabc  885c242c             mov byte ptr [esp + 0x2c], bl
// 0040cac0  7408                 je 0x40caca
// 0040cac2  8b08                 mov ecx, dword ptr [eax]
// 0040cac4  8b5108               mov edx, dword ptr [ecx + 8]
// 0040cac7  50                   push eax
// 0040cac8  ffd2                 call edx
// 0040caca  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040cace  3bc3                 cmp eax, ebx
// 0040cad0  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0040cad8  7407                 je 0x40cae1
// 0040cada  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040cade  894804               mov dword ptr [eax + 4], ecx
// 0040cae1  395c2420             cmp dword ptr [esp + 0x20], ebx
// 0040cae5  740b                 je 0x40caf2
// 0040cae7  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040caeb  52                   push edx
// 0040caec  53                   push ebx
// 0040caed  e846342200           call 0x62ff38
// 0040caf2  8bc7                 mov eax, edi
// 0040caf4  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0040caf8  64890d00000000       mov dword ptr fs:[0], ecx
// 0040caff  59                   pop ecx
// 0040cb00  5f                   pop edi
// 0040cb01  5e                   pop esi
// 0040cb02  5b                   pop ebx
// 0040cb03  83c420               add esp, 0x20
// 0040cb06  c20800               ret 8

struct GUID { unsigned long d1; unsigned short d2, d3; unsigned char d4[8]; };

extern "C" __declspec(dllimport) long __stdcall CoCreateInstance(const GUID& rclsid, void* pUnkOuter, unsigned long dwClsContext, const GUID& riid, void** ppv);

struct IUnk {
    virtual long __stdcall QueryInterface(const GUID& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

template <class T> struct ComPtr {
    T* p;
    ComPtr() throw() : p(0) {}
    ComPtr(T* lp) throw() : p(lp) { if (p) p->AddRef(); }
    ~ComPtr() throw() { if (p) p->Release(); }
    long CopyTo(T** pp) throw() {
        if (pp == 0) return 0x80004003L;
        *pp = p;
        if (p) p->AddRef();
        return 0;
    }
};

// AFX_MAINTAIN_STATE2-shaped guard (16 bytes, fields read off the inlined dtor)
struct Link { void* unused; void* previous; };
extern "C" void* __cdecl get_state();                       // 0x62ff44
void __stdcall release_state(int, void*);        // 0x62ff38
struct State {
    void* previous;
    Link* link;
    void* context;
    int active;
    State(void*);                                           // 0x62ff3e
    ~State() {
        if (link) link->previous = previous;
        if (active) release_state(0, context);
    }
};

struct Text {
    char* m_psz;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) void __cdecl Format(const char* fmt, ...);
    __declspec(dllimport) const char* GetString() const;
};

extern const GUID appClsid;    // 0x790290
extern const GUID appIid;      // 0x78523c
extern const GUID ownClsid;    // 0x7902d0
extern "C" long __cdecl ReportError(const GUID& clsid, const char* desc, long hr);  // 0x429220

struct BrowserViewExternal {
    long __stdcall GetApp(IUnk** pp);
};

long __stdcall BrowserViewExternal::GetApp(IUnk** pp)
{
    State state(get_state());
    ComPtr<IUnk> app;
    long hr = CoCreateInstance(appClsid, 0, 0x17, appIid, (void**)&app.p);
    if (hr != 0) {
        Text msg;
        msg.Format("IBrowserViewExternal::GetApp-0x%X", hr);
        return ReportError(ownClsid, msg.GetString(), hr);
    }
    return ComPtr<IUnk>(app.p).CopyTo(pp);
}

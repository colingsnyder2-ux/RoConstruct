// from server: 100% by EspClaude
// from server: 98% by colin
// roc 2008-06 0042ae50  unit: EventHandler  size: 312 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042ae50
//
// 0042ae50  6aff                 push -1
// 0042ae52  68baf47b00           push 0x7bf4ba
// 0042ae57  64a100000000         mov eax, dword ptr fs:[0]
// 0042ae5d  50                   push eax
// 0042ae5e  64892500000000       mov dword ptr fs:[0], esp
// 0042ae65  83ec4c               sub esp, 0x4c
// 0042ae68  e813612700           call 0x6a0f80
// 0042ae6d  33c9                 xor ecx, ecx
// 0042ae6f  894c2404             mov dword ptr [esp + 4], ecx
// 0042ae73  85c0                 test eax, eax
// 0042ae75  7415                 je 0x42ae8c
// 0042ae77  8b08                 mov ecx, dword ptr [eax]
// 0042ae79  8d542404             lea edx, [esp + 4]
// 0042ae7d  52                   push edx
// 0042ae7e  686c058100           push 0x81056c
// 0042ae83  50                   push eax
// 0042ae84  8b01                 mov eax, dword ptr [ecx]
// 0042ae86  ffd0                 call eax
// 0042ae88  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042ae8c  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0042ae94  85c9                 test ecx, ecx
// 0042ae96  7531                 jne 0x42aec9
// 0042ae98  68e0058100           push 0x8105e0
// 0042ae9d  8d4c240c             lea ecx, [esp + 0xc]
// 0042aea1  ff1558248000         call dword ptr [0x802458]
// 0042aea7  8d4c2408             lea ecx, [esp + 8]
// 0042aeab  51                   push ecx
// 0042aeac  8d4c2428             lea ecx, [esp + 0x28]
// 0042aeb0  c644245801           mov byte ptr [esp + 0x58], 1
// 0042aeb5  e896eefdff           call 0x409d50
// 0042aeba  68c81b8d00           push 0x8d1bc8
// 0042aebf  8d542428             lea edx, [esp + 0x28]
// 0042aec3  52                   push edx
// 0042aec4  e8c3662700           call 0x6a158c
// 0042aec9  56                   push esi
// 0042aeca  c744240400000000     mov dword ptr [esp + 4], 0
// 0042aed2  8b01                 mov eax, dword ptr [ecx]
// 0042aed4  8b4024               mov eax, dword ptr [eax + 0x24]
// 0042aed7  8d542404             lea edx, [esp + 4]
// 0042aedb  52                   push edx
// 0042aedc  51                   push ecx
// 0042aedd  c644246002           mov byte ptr [esp + 0x60], 2
// 0042aee2  ffd0                 call eax
// 0042aee4  8b742404             mov esi, dword ptr [esp + 4]
// 0042aee8  85f6                 test esi, esi
// 0042aeea  7531                 jne 0x42af1d
// 0042aeec  68b4058100           push 0x8105b4
// 0042aef1  8d4c2410             lea ecx, [esp + 0x10]
// 0042aef5  ff1558248000         call dword ptr [0x802458]
// 0042aefb  8d4c240c             lea ecx, [esp + 0xc]
// 0042aeff  51                   push ecx
// 0042af00  8d4c242c             lea ecx, [esp + 0x2c]
// 0042af04  c644245c03           mov byte ptr [esp + 0x5c], 3
// 0042af09  e842eefdff           call 0x409d50
// 0042af0e  68c81b8d00           push 0x8d1bc8
// 0042af13  8d54242c             lea edx, [esp + 0x2c]
// 0042af17  52                   push edx
// 0042af18  e86f662700           call 0x6a158c
// 0042af1d  8b442460             mov eax, dword ptr [esp + 0x60]
// 0042af21  50                   push eax
// 0042af22  8d4c2464             lea ecx, [esp + 0x64]
// 0042af26  e85562fdff           call 0x401180
// 0042af2b  8b00                 mov eax, dword ptr [eax]
// 0042af2d  8b0e                 mov ecx, dword ptr [esi]
// 0042af2f  8b91e4000000         mov edx, dword ptr [ecx + 0xe4]
// 0042af35  50                   push eax
// 0042af36  56                   push esi
// 0042af37  c644246004           mov byte ptr [esp + 0x60], 4
// 0042af3c  ffd2                 call edx
// 0042af3e  8b442460             mov eax, dword ptr [esp + 0x60]
// 0042af42  50                   push eax
// 0042af43  ff1544298000         call dword ptr [0x802944]
// 0042af49  8b442404             mov eax, dword ptr [esp + 4]
// 0042af4d  c644245800           mov byte ptr [esp + 0x58], 0
// 0042af52  85c0                 test eax, eax
// 0042af54  7408                 je 0x42af5e
// 0042af56  8b08                 mov ecx, dword ptr [eax]
// 0042af58  8b5108               mov edx, dword ptr [ecx + 8]
// 0042af5b  50                   push eax
// 0042af5c  ffd2                 call edx
// 0042af5e  8b442408             mov eax, dword ptr [esp + 8]
// 0042af62  c7442458ffffffff     mov dword ptr [esp + 0x58], 0xffffffff
// 0042af6a  85c0                 test eax, eax
// 0042af6c  7408                 je 0x42af76
// 0042af6e  8b08                 mov ecx, dword ptr [eax]
// 0042af70  8b5108               mov edx, dword ptr [ecx + 8]
// 0042af73  50                   push eax
// 0042af74  ffd2                 call edx
// 0042af76  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0042af7a  5e                   pop esi
// 0042af7b  64890d00000000       mov dword ptr fs:[0], ecx
// 0042af82  83c458               add esp, 0x58
// 0042af85  c20400               ret 4

// from server: 95% by king_originala
// roc 2008-06 0042ae50  unit: EventHandler  size: 312 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042ae50
//
// 0042ae50  6aff                 push -1
// 0042ae52  68baf47b00           push 0x7bf4ba
// 0042ae57  64a100000000         mov eax, dword ptr fs:[0]
// 0042ae5d  50                   push eax
// 0042ae5e  64892500000000       mov dword ptr fs:[0], esp
// 0042ae65  83ec4c               sub esp, 0x4c
// 0042ae68  e813612700           call 0x6a0f80
// 0042ae6d  33c9                 xor ecx, ecx
// 0042ae6f  894c2404             mov dword ptr [esp + 4], ecx
// 0042ae73  85c0                 test eax, eax
// 0042ae75  7415                 je 0x42ae8c
// 0042ae77  8b08                 mov ecx, dword ptr [eax]
// 0042ae79  8d542404             lea edx, [esp + 4]
// 0042ae7d  52                   push edx
// 0042ae7e  686c058100           push 0x81056c
// 0042ae83  50                   push eax
// 0042ae84  8b01                 mov eax, dword ptr [ecx]
// 0042ae86  ffd0                 call eax
// 0042ae88  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042ae8c  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0042ae94  85c9                 test ecx, ecx
// 0042ae96  7531                 jne 0x42aec9
// 0042ae98  68e0058100           push 0x8105e0
// 0042ae9d  8d4c240c             lea ecx, [esp + 0xc]
// 0042aea1  ff1558248000         call dword ptr [0x802458]
// 0042aea7  8d4c2408             lea ecx, [esp + 8]
// 0042aeab  51                   push ecx
// 0042aeac  8d4c2428             lea ecx, [esp + 0x28]
// 0042aeb0  c644245801           mov byte ptr [esp + 0x58], 1
// 0042aeb5  e896eefdff           call 0x409d50
// 0042aeba  68c81b8d00           push 0x8d1bc8
// 0042aebf  8d542428             lea edx, [esp + 0x28]
// 0042aec3  52                   push edx
// 0042aec4  e8c3662700           call 0x6a158c
// 0042aec9  56                   push esi
// 0042aeca  c744240400000000     mov dword ptr [esp + 4], 0
// 0042aed2  8b01                 mov eax, dword ptr [ecx]
// 0042aed4  8b4024               mov eax, dword ptr [eax + 0x24]
// 0042aed7  8d542404             lea edx, [esp + 4]
// 0042aedb  52                   push edx
// 0042aedc  51                   push ecx
// 0042aedd  c644246002           mov byte ptr [esp + 0x60], 2
// 0042aee2  ffd0                 call eax
// 0042aee4  8b742404             mov esi, dword ptr [esp + 4]
// 0042aee8  85f6                 test esi, esi
// 0042aeea  7531                 jne 0x42af1d
// 0042aeec  68b4058100           push 0x8105b4
// 0042aef1  8d4c2410             lea ecx, [esp + 0x10]
// 0042aef5  ff1558248000         call dword ptr [0x802458]
// 0042aefb  8d4c240c             lea ecx, [esp + 0xc]
// 0042aeff  51                   push ecx
// 0042af00  8d4c242c             lea ecx, [esp + 0x2c]
// 0042af04  c644245c03           mov byte ptr [esp + 0x5c], 3
// 0042af09  e842eefdff           call 0x409d50
// 0042af0e  68c81b8d00           push 0x8d1bc8
// 0042af13  8d54242c             lea edx, [esp + 0x2c]
// 0042af17  52                   push edx
// 0042af18  e86f662700           call 0x6a158c
// 0042af1d  8b442460             mov eax, dword ptr [esp + 0x60]
// 0042af21  50                   push eax
// 0042af22  8d4c2464             lea ecx, [esp + 0x64]
// 0042af26  e85562fdff           call 0x401180
// 0042af2b  8b00                 mov eax, dword ptr [eax]
// 0042af2d  8b0e                 mov ecx, dword ptr [esi]
// 0042af2f  8b91e4000000         mov edx, dword ptr [ecx + 0xe4]
// 0042af35  50                   push eax
// 0042af36  56                   push esi
// 0042af37  c644246004           mov byte ptr [esp + 0x60], 4
// 0042af3c  ffd2                 call edx
// 0042af3e  8b442460             mov eax, dword ptr [esp + 0x60]
// 0042af42  50                   push eax
// 0042af43  ff1544298000         call dword ptr [0x802944]
// 0042af49  8b442404             mov eax, dword ptr [esp + 4]
// 0042af4d  c644245800           mov byte ptr [esp + 0x58], 0
// 0042af52  85c0                 test eax, eax
// 0042af54  7408                 je 0x42af5e
// 0042af56  8b08                 mov ecx, dword ptr [eax]
// 0042af58  8b5108               mov edx, dword ptr [ecx + 8]
// 0042af5b  50                   push eax
// 0042af5c  ffd2                 call edx
// 0042af5e  8b442408             mov eax, dword ptr [esp + 8]
// 0042af62  c7442458ffffffff     mov dword ptr [esp + 0x58], 0xffffffff
// 0042af6a  85c0                 test eax, eax
// 0042af6c  7408                 je 0x42af76
// 0042af6e  8b08                 mov ecx, dword ptr [eax]
// 0042af70  8b5108               mov edx, dword ptr [ecx + 8]
// 0042af73  50                   push eax
// 0042af74  ffd2                 call edx
// 0042af76  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0042af7a  5e                   pop esi
// 0042af7b  64890d00000000       mov dword ptr fs:[0], ecx
// 0042af82  83c458               add esp, 0x58
// 0042af85  c20400               ret 4

struct String;
extern void (__thiscall* constructString)(String*, const char*);

struct String {
    char storage[28];
    String(const char* text) { constructString(this, text); }
    ~String();
};

struct Error {
    char storage[40];
    Error(const String&);
    Error(const Error&);
    ~Error();
};

extern "C" __declspec(dllimport) void __stdcall SysFreeString(unsigned short*);

struct BString {
    unsigned short* data;
    BString(const char*);
    ~BString() { SysFreeString(data); }
    operator unsigned short*() const { return data; }
};

struct Interface;

struct InterfaceTable {
    long (__stdcall* query)(Interface*, const void*, Interface**);
    unsigned long (__stdcall* addRef)(Interface*);
    unsigned long (__stdcall* release)(Interface*);
    void* reserved0[6];
    long (__stdcall* getBody)(Interface*, Interface**);
    void* reserved1[47];
    long (__stdcall* putHtml)(Interface*, unsigned short*);
};

struct Interface {
    InterfaceTable* table;
};

extern Interface* __cdecl getDocument();
extern const unsigned char documentInterfaceId[16];

struct InterfacePtr {
    Interface* value;

    InterfacePtr() : value(0) {}

    InterfacePtr(Interface* source) : value(0)
    {
        if (source)
            source->table->query(source, documentInterfaceId, &value);
    }

    ~InterfacePtr()
    {
        if (value)
            value->table->release(value);
    }
};

void __stdcall f(const char* text)
{
    InterfacePtr document(getDocument());

    if (!document.value)
        throw Error(String("The HtmlDocument is not loaded"));

    InterfacePtr body;
    document.value->table->getBody(document.value, &body.value);

    Interface* element = body.value;
    if (!element)
        throw Error(String("The HtmlDocument does not contain a body"));

    element->table->putHtml(element, BString(text));
}

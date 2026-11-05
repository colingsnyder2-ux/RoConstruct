// from server: 100% by EspClaude
// roc 2009-06 00405c80  unit: ATL::CRegObject  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00405c80
//
// 00405c80  64a100000000         mov eax, dword ptr fs:[0]
// 00405c86  6aff                 push -1
// 00405c88  6842cc8400           push 0x84cc42
// 00405c8d  50                   push eax
// 00405c8e  64892500000000       mov dword ptr fs:[0], esp
// 00405c95  83ec14               sub esp, 0x14
// 00405c98  56                   push esi
// 00405c99  85c9                 test ecx, ecx
// 00405c9b  7405                 je 0x405ca2
// 00405c9d  8d71fc               lea esi, [ecx - 4]
// 00405ca0  eb02                 jmp 0x405ca4
// 00405ca2  33f6                 xor esi, esi
// 00405ca4  c744240800000000     mov dword ptr [esp + 8], 0
// 00405cac  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00405caf  8d542408             lea edx, [esp + 8]
// 00405cb3  52                   push edx
// 00405cb4  8d460c               lea eax, [esi + 0xc]
// 00405cb7  6810128f00           push 0x8f1210
// 00405cbc  50                   push eax
// 00405cbd  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00405cc0  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00405cc8  ffd0                 call eax
// 00405cca  85c0                 test eax, eax
// 00405ccc  8b442408             mov eax, dword ptr [esp + 8]
// 00405cd0  0f8513010000         jne 0x405de9
// 00405cd6  85c0                 test eax, eax
// 00405cd8  0f840b010000         je 0x405de9
// 00405cde  c744240400000000     mov dword ptr [esp + 4], 0
// 00405ce6  8d4c2410             lea ecx, [esp + 0x10]
// 00405cea  51                   push ecx
// 00405ceb  8d542408             lea edx, [esp + 8]
// 00405cef  52                   push edx
// 00405cf0  8d4e04               lea ecx, [esi + 4]
// 00405cf3  c644242801           mov byte ptr [esp + 0x28], 1
// 00405cf8  e853efffff           call 0x404c50
// 00405cfd  85c0                 test eax, eax
// 00405cff  744a                 je 0x405d4b
// 00405d01  50                   push eax
// 00405d02  68d8ce8a00           push 0x8aced8
// 00405d07  68f8698b00           push 0x8b69f8
// 00405d0c  e8efe20100           call 0x424000
// 00405d11  8bf0                 mov esi, eax
// 00405d13  8b442410             mov eax, dword ptr [esp + 0x10]
// 00405d17  83c40c               add esp, 0xc
// 00405d1a  50                   push eax
// 00405d1b  ff153cea8900         call dword ptr [0x89ea3c]
// 00405d21  8b442408             mov eax, dword ptr [esp + 8]
// 00405d25  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00405d2d  85c0                 test eax, eax
// 00405d2f  7408                 je 0x405d39
// 00405d31  8b08                 mov ecx, dword ptr [eax]
// 00405d33  8b5108               mov edx, dword ptr [ecx + 8]
// 00405d36  50                   push eax
// 00405d37  ffd2                 call edx
// 00405d39  8bc6                 mov eax, esi
// 00405d3b  5e                   pop esi
// 00405d3c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00405d40  64890d00000000       mov dword ptr fs:[0], ecx
// 00405d47  83c420               add esp, 0x20
// 00405d4a  c3                   ret 
// 00405d4b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00405d4f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00405d53  50                   push eax
// 00405d54  51                   push ecx
// 00405d55  e856340100           call 0x4191b0
// 00405d5a  8bf0                 mov esi, eax
// 00405d5c  83c408               add esp, 8
// 00405d5f  85f6                 test esi, esi
// 00405d61  7477                 je 0x405dda
// 00405d63  8d4c240c             lea ecx, [esp + 0xc]
// 00405d67  ff15bcfc8900         call dword ptr [0x89fcbc]
// 00405d6d  8b542404             mov edx, dword ptr [esp + 4]
// 00405d71  52                   push edx
// 00405d72  8d4c2418             lea ecx, [esp + 0x18]
// 00405d76  c644242402           mov byte ptr [esp + 0x24], 2
// 00405d7b  ff15c0fc8900         call dword ptr [0x89fcc0]
// 00405d81  8b00                 mov eax, dword ptr [eax]
// 00405d83  50                   push eax
// 00405d84  8d4c2410             lea ecx, [esp + 0x10]
// 00405d88  68c4ce8a00           push 0x8acec4
// 00405d8d  51                   push ecx
// 00405d8e  c644242c03           mov byte ptr [esp + 0x2c], 3
// 00405d93  ff15c4fc8900         call dword ptr [0x89fcc4]
// 00405d99  83c40c               add esp, 0xc
// 00405d9c  8d4c2414             lea ecx, [esp + 0x14]
// 00405da0  c644242002           mov byte ptr [esp + 0x20], 2
// 00405da5  ff1510fd8900         call dword ptr [0x89fd10]
// 00405dab  56                   push esi
// 00405dac  8d4c2410             lea ecx, [esp + 0x10]
// 00405db0  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00405db6  50                   push eax
// 00405db7  68f8698b00           push 0x8b69f8
// 00405dbc  e83fe20100           call 0x424000
// 00405dc1  83c40c               add esp, 0xc
// 00405dc4  8d4c240c             lea ecx, [esp + 0xc]
// 00405dc8  8bf0                 mov esi, eax
// 00405dca  ff1510fd8900         call dword ptr [0x89fd10]
// 00405dd0  8b542404             mov edx, dword ptr [esp + 4]
// 00405dd4  52                   push edx
// 00405dd5  e941ffffff           jmp 0x405d1b
// 00405dda  8b442404             mov eax, dword ptr [esp + 4]
// 00405dde  50                   push eax
// 00405ddf  ff153cea8900         call dword ptr [0x89ea3c]
// 00405de5  8b442408             mov eax, dword ptr [esp + 8]
// 00405de9  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00405df1  85c0                 test eax, eax
// 00405df3  7408                 je 0x405dfd
// 00405df5  8b08                 mov ecx, dword ptr [eax]
// 00405df7  8b5108               mov edx, dword ptr [ecx + 8]
// 00405dfa  50                   push eax
// 00405dfb  ffd2                 call edx
// 00405dfd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00405e01  33c0                 xor eax, eax
// 00405e03  5e                   pop esi
// 00405e04  64890d00000000       mov dword ptr fs:[0], ecx
// 00405e0b  83c420               add esp, 0x20
// 00405e0e  c3                   ret 
// copied from an identical function in another client (function ?checkSite@S@ns_ROCX00003e@@QAEHXZ)

namespace ns_ROCX00003e {
typedef unsigned short WCHAR;

extern "C" __declspec(dllimport) void __stdcall SysFreeString(WCHAR *);
extern "C" int __cdecl function(void *, int);
extern "C" int __cdecl logMessage(int, const char *, int);

extern const int errorContext;
extern const char failedSiteUrl[];
extern const char untrustedSite[];
extern const unsigned char siteIID[];

struct Unknown;

struct UnknownTable {
    int (__stdcall *query)(Unknown *, const void *, void **);
    unsigned long (__stdcall *addRef)(Unknown *);
    unsigned long (__stdcall *release)(Unknown *);
};

struct Unknown {
    UnknownTable *table;
};

struct Site;

struct SiteTable {
    void *unused[4];
    int (__stdcall *getSite)(Site *, const void *, Unknown **);
};

struct Site {
    SiteTable *table;
};

struct ComPtr {
    Unknown *value;
    ComPtr();
    ~ComPtr();
};

inline ComPtr::ComPtr() : value(0) {}

inline ComPtr::~ComPtr()
{
    Unknown *p = value;
    if (p)
        p->table->release(p);
}

struct Bstr {
    WCHAR *value;
    Bstr();
    ~Bstr() { SysFreeString(value); }
};

inline Bstr::Bstr() : value(0) {}

struct String {
    char *value;
    String();
    String(const WCHAR *, String *&);
    ~String();
};

extern void (__thiscall *stringConstruct)(String *);
extern String *(__thiscall *stringConvert)(String *, const WCHAR *);
extern void (__thiscall *stringDestroy)(String *);
extern const char *(__thiscall *stringText)(const String *);
extern void (__cdecl *stringFormat)(String *, const char *, ...);

inline String::String()
{
    stringConstruct(this);
}

inline String::String(const WCHAR *s, String *&result)
{
    result = stringConvert(this, s);
}

inline String::~String()
{
    stringDestroy(this);
}

struct Message {
    char *value;
    Message() { stringConstruct(reinterpret_cast<String *>(this)); }
    __declspec(dllimport) ~Message() throw();
};

struct S {
    unsigned char storage[8];
    int checkSite();
    int getSiteUrl(WCHAR **, int *);
};

struct Owner {
    unsigned char storage[4];
    S object;
    Site site;
};

int S::checkSite()
{
    Owner *owner = this
        ? reinterpret_cast<Owner *>(reinterpret_cast<char *>(this) - 4)
        : 0;

    ComPtr site;
    if (owner->site.table->getSite(&owner->site, siteIID, &site.value) == 0 && site.value) {
        Bstr url;
        String *convertedResult;
        int kind;
        int result = owner->object.getSiteUrl(&url.value, &kind);
        if (result)
            return logMessage(reinterpret_cast<int>(&errorContext),
                              failedSiteUrl, result);

        result = function(url.value, kind);
        if (result) {
            Message message;
            {
                String converted(url.value, convertedResult);
                stringFormat(reinterpret_cast<String *>(&message), untrustedSite, convertedResult->value);
            }
            return logMessage(reinterpret_cast<int>(&errorContext),
                              stringText(reinterpret_cast<String *>(&message)), result);
        }
    }

    return 0;
}
}

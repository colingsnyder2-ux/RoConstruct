// from server: 100% by Xemicl
// roc 2012-06 00406c80  unit: ATL::CRegObject  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00406c80
//
// 00406c80  64a100000000         mov eax, dword ptr fs:[0]
// 00406c86  6aff                 push -1
// 00406c88  681216aa00           push 0xaa1612
// 00406c8d  50                   push eax
// 00406c8e  64892500000000       mov dword ptr fs:[0], esp
// 00406c95  83ec14               sub esp, 0x14
// 00406c98  56                   push esi
// 00406c99  85c9                 test ecx, ecx
// 00406c9b  7405                 je 0x406ca2
// 00406c9d  8d71fc               lea esi, [ecx - 4]
// 00406ca0  eb02                 jmp 0x406ca4
// 00406ca2  33f6                 xor esi, esi
// 00406ca4  c744240800000000     mov dword ptr [esp + 8], 0
// 00406cac  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00406caf  8d542408             lea edx, [esp + 8]
// 00406cb3  52                   push edx
// 00406cb4  8d460c               lea eax, [esi + 0xc]
// 00406cb7  6808cdc000           push 0xc0cd08
// 00406cbc  50                   push eax
// 00406cbd  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00406cc0  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00406cc8  ffd0                 call eax
// 00406cca  85c0                 test eax, eax
// 00406ccc  8b442408             mov eax, dword ptr [esp + 8]
// 00406cd0  0f8513010000         jne 0x406de9
// 00406cd6  85c0                 test eax, eax
// 00406cd8  0f840b010000         je 0x406de9
// 00406cde  c744240400000000     mov dword ptr [esp + 4], 0
// 00406ce6  8d4c2410             lea ecx, [esp + 0x10]
// 00406cea  51                   push ecx
// 00406ceb  8d542408             lea edx, [esp + 8]
// 00406cef  52                   push edx
// 00406cf0  8d4e04               lea ecx, [esi + 4]
// 00406cf3  c644242801           mov byte ptr [esp + 0x28], 1
// 00406cf8  e833f0ffff           call 0x405d30
// 00406cfd  85c0                 test eax, eax
// 00406cff  744a                 je 0x406d4b
// 00406d01  50                   push eax
// 00406d02  686839b400           push 0xb43968
// 00406d07  685c94b500           push 0xb5945c
// 00406d0c  e82fbc0200           call 0x432940
// 00406d11  8bf0                 mov esi, eax
// 00406d13  8b442410             mov eax, dword ptr [esp + 0x10]
// 00406d17  83c40c               add esp, 0xc
// 00406d1a  50                   push eax
// 00406d1b  ff15042bb200         call dword ptr [0xb22b04]
// 00406d21  8b442408             mov eax, dword ptr [esp + 8]
// 00406d25  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00406d2d  85c0                 test eax, eax
// 00406d2f  7408                 je 0x406d39
// 00406d31  8b08                 mov ecx, dword ptr [eax]
// 00406d33  8b5108               mov edx, dword ptr [ecx + 8]
// 00406d36  50                   push eax
// 00406d37  ffd2                 call edx
// 00406d39  8bc6                 mov eax, esi
// 00406d3b  5e                   pop esi
// 00406d3c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00406d40  64890d00000000       mov dword ptr fs:[0], ecx
// 00406d47  83c420               add esp, 0x20
// 00406d4a  c3                   ret 
// 00406d4b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00406d4f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00406d53  50                   push eax
// 00406d54  51                   push ecx
// 00406d55  e8f6fe0100           call 0x426c50
// 00406d5a  8bf0                 mov esi, eax
// 00406d5c  83c408               add esp, 8
// 00406d5f  85f6                 test esi, esi
// 00406d61  7477                 je 0x406dda
// 00406d63  8d4c240c             lea ecx, [esp + 0xc]
// 00406d67  ff158447b200         call dword ptr [0xb24784]
// 00406d6d  8b542404             mov edx, dword ptr [esp + 4]
// 00406d71  52                   push edx
// 00406d72  8d4c2418             lea ecx, [esp + 0x18]
// 00406d76  c644242402           mov byte ptr [esp + 0x24], 2
// 00406d7b  ff159447b200         call dword ptr [0xb24794]
// 00406d81  8b00                 mov eax, dword ptr [eax]
// 00406d83  50                   push eax
// 00406d84  8d4c2410             lea ecx, [esp + 0x10]
// 00406d88  685439b400           push 0xb43954
// 00406d8d  51                   push ecx
// 00406d8e  c644242c03           mov byte ptr [esp + 0x2c], 3
// 00406d93  ff158847b200         call dword ptr [0xb24788]
// 00406d99  83c40c               add esp, 0xc
// 00406d9c  8d4c2414             lea ecx, [esp + 0x14]
// 00406da0  c644242002           mov byte ptr [esp + 0x20], 2
// 00406da5  ff15d047b200         call dword ptr [0xb247d0]
// 00406dab  56                   push esi
// 00406dac  8d4c2410             lea ecx, [esp + 0x10]
// 00406db0  ff159847b200         call dword ptr [0xb24798]
// 00406db6  50                   push eax
// 00406db7  685c94b500           push 0xb5945c
// 00406dbc  e87fbb0200           call 0x432940
// 00406dc1  83c40c               add esp, 0xc
// 00406dc4  8d4c240c             lea ecx, [esp + 0xc]
// 00406dc8  8bf0                 mov esi, eax
// 00406dca  ff15d047b200         call dword ptr [0xb247d0]
// 00406dd0  8b542404             mov edx, dword ptr [esp + 4]
// 00406dd4  52                   push edx
// 00406dd5  e941ffffff           jmp 0x406d1b
// 00406dda  8b442404             mov eax, dword ptr [esp + 4]
// 00406dde  50                   push eax
// 00406ddf  ff15042bb200         call dword ptr [0xb22b04]
// 00406de5  8b442408             mov eax, dword ptr [esp + 8]
// 00406de9  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00406df1  85c0                 test eax, eax
// 00406df3  7408                 je 0x406dfd
// 00406df5  8b08                 mov ecx, dword ptr [eax]
// 00406df7  8b5108               mov edx, dword ptr [ecx + 8]
// 00406dfa  50                   push eax
// 00406dfb  ffd2                 call edx
// 00406dfd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00406e01  33c0                 xor eax, eax
// 00406e03  5e                   pop esi
// 00406e04  64890d00000000       mov dword ptr fs:[0], ecx
// 00406e0b  83c420               add esp, 0x20
// 00406e0e  c3                   ret 
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
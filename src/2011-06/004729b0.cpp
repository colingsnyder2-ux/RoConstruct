// from server: 100% by Yeetserama
// roc 2011-06 004729b0  unit: VCRobloxDoc::?$VerbBinder  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004729b0
//
// 004729b0  64a100000000         mov eax, dword ptr fs:[0]
// 004729b6  6aff                 push -1
// 004729b8  6852249d00           push 0x9d2452
// 004729bd  50                   push eax
// 004729be  64892500000000       mov dword ptr fs:[0], esp
// 004729c5  83ec14               sub esp, 0x14
// 004729c8  56                   push esi
// 004729c9  85c9                 test ecx, ecx
// 004729cb  7405                 je 0x4729d2
// 004729cd  8d71f8               lea esi, [ecx - 8]
// 004729d0  eb02                 jmp 0x4729d4
// 004729d2  33f6                 xor esi, esi
// 004729d4  c744240800000000     mov dword ptr [esp + 8], 0
// 004729dc  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004729df  8d542408             lea edx, [esp + 8]
// 004729e3  52                   push edx
// 004729e4  8d4610               lea eax, [esi + 0x10]
// 004729e7  682816ac00           push 0xac1628
// 004729ec  50                   push eax
// 004729ed  8b4110               mov eax, dword ptr [ecx + 0x10]
// 004729f0  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004729f8  ffd0                 call eax
// 004729fa  85c0                 test eax, eax
// 004729fc  8b442408             mov eax, dword ptr [esp + 8]
// 00472a00  0f8513010000         jne 0x472b19
// 00472a06  85c0                 test eax, eax
// 00472a08  0f840b010000         je 0x472b19
// 00472a0e  c744240400000000     mov dword ptr [esp + 4], 0
// 00472a16  8d4c2410             lea ecx, [esp + 0x10]
// 00472a1a  51                   push ecx
// 00472a1b  8d542408             lea edx, [esp + 8]
// 00472a1f  52                   push edx
// 00472a20  8d4e08               lea ecx, [esi + 8]
// 00472a23  c644242801           mov byte ptr [esp + 0x28], 1
// 00472a28  e853f6ffff           call 0x472080
// 00472a2d  85c0                 test eax, eax
// 00472a2f  744a                 je 0x472a7b
// 00472a31  50                   push eax
// 00472a32  6890bba500           push 0xa5bb90
// 00472a37  68f4daa600           push 0xa6daf4
// 00472a3c  e8ffb5fbff           call 0x42e040
// 00472a41  8bf0                 mov esi, eax
// 00472a43  8b442410             mov eax, dword ptr [esp + 0x10]
// 00472a47  83c40c               add esp, 0xc
// 00472a4a  50                   push eax
// 00472a4b  ff15000ba400         call dword ptr [0xa40b00]
// 00472a51  8b442408             mov eax, dword ptr [esp + 8]
// 00472a55  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00472a5d  85c0                 test eax, eax
// 00472a5f  7408                 je 0x472a69
// 00472a61  8b08                 mov ecx, dword ptr [eax]
// 00472a63  8b5108               mov edx, dword ptr [ecx + 8]
// 00472a66  50                   push eax
// 00472a67  ffd2                 call edx
// 00472a69  8bc6                 mov eax, esi
// 00472a6b  5e                   pop esi
// 00472a6c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00472a70  64890d00000000       mov dword ptr fs:[0], ecx
// 00472a77  83c420               add esp, 0x20
// 00472a7a  c3                   ret 
// 00472a7b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00472a7f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00472a83  50                   push eax
// 00472a84  51                   push ecx
// 00472a85  e83608fbff           call 0x4232c0
// 00472a8a  8bf0                 mov esi, eax
// 00472a8c  83c408               add esp, 8
// 00472a8f  85f6                 test esi, esi
// 00472a91  7477                 je 0x472b0a
// 00472a93  8d4c240c             lea ecx, [esp + 0xc]
// 00472a97  ff15b42da400         call dword ptr [0xa42db4]
// 00472a9d  8b542404             mov edx, dword ptr [esp + 4]
// 00472aa1  52                   push edx
// 00472aa2  8d4c2418             lea ecx, [esp + 0x18]
// 00472aa6  c644242402           mov byte ptr [esp + 0x24], 2
// 00472aab  ff15b82da400         call dword ptr [0xa42db8]
// 00472ab1  8b00                 mov eax, dword ptr [eax]
// 00472ab3  50                   push eax
// 00472ab4  8d4c2410             lea ecx, [esp + 0x10]
// 00472ab8  687cbba500           push 0xa5bb7c
// 00472abd  51                   push ecx
// 00472abe  c644242c03           mov byte ptr [esp + 0x2c], 3
// 00472ac3  ff15bc2da400         call dword ptr [0xa42dbc]
// 00472ac9  83c40c               add esp, 0xc
// 00472acc  8d4c2414             lea ecx, [esp + 0x14]
// 00472ad0  c644242002           mov byte ptr [esp + 0x20], 2
// 00472ad5  ff15082ea400         call dword ptr [0xa42e08]
// 00472adb  56                   push esi
// 00472adc  8d4c2410             lea ecx, [esp + 0x10]
// 00472ae0  ff15c82da400         call dword ptr [0xa42dc8]
// 00472ae6  50                   push eax
// 00472ae7  68f4daa600           push 0xa6daf4
// 00472aec  e84fb5fbff           call 0x42e040
// 00472af1  83c40c               add esp, 0xc
// 00472af4  8d4c240c             lea ecx, [esp + 0xc]
// 00472af8  8bf0                 mov esi, eax
// 00472afa  ff15082ea400         call dword ptr [0xa42e08]
// 00472b00  8b542404             mov edx, dword ptr [esp + 4]
// 00472b04  52                   push edx
// 00472b05  e941ffffff           jmp 0x472a4b
// 00472b0a  8b442404             mov eax, dword ptr [esp + 4]
// 00472b0e  50                   push eax
// 00472b0f  ff15000ba400         call dword ptr [0xa40b00]
// 00472b15  8b442408             mov eax, dword ptr [esp + 8]
// 00472b19  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00472b21  85c0                 test eax, eax
// 00472b23  7408                 je 0x472b2d
// 00472b25  8b08                 mov ecx, dword ptr [eax]
// 00472b27  8b5108               mov edx, dword ptr [ecx + 8]
// 00472b2a  50                   push eax
// 00472b2b  ffd2                 call edx
// 00472b2d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00472b31  33c0                 xor eax, eax
// 00472b33  5e                   pop esi
// 00472b34  64890d00000000       mov dword ptr fs:[0], ecx
// 00472b3b  83c420               add esp, 0x20
// 00472b3e  c3                   ret 
// copied from an identical function in another client (function ?checkSite@S@ns_ROCX00001c@@QAEHXZ)

namespace ns_ROCX00001c {
// from server: 88% by colin
// roc 2008-06 00403b60  unit: ATL::CComClassFactory  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403b60
//

// from server: 80% by colin
// roc 2008-06 00403b60  unit: ATL::CComClassFactory  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403b60
//

// from server: 70% by king_originala
// roc 2008-06 00403b60  unit: ATL::CComClassFactory  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403b60
//

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
    unsigned char storage[8];
    S object;
    Site site;
};

int S::checkSite()
{
    Owner *owner = this
        ? reinterpret_cast<Owner *>(reinterpret_cast<char *>(this) - 8)
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

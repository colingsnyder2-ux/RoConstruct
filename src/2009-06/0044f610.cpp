// from server: 100% by EspClaude
// roc 2009-06 0044f610  unit: VCWorkspace::?$CComObject  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044f610
//
// 0044f610  64a100000000         mov eax, dword ptr fs:[0]
// 0044f616  6aff                 push -1
// 0044f618  6842cc8400           push 0x84cc42
// 0044f61d  50                   push eax
// 0044f61e  64892500000000       mov dword ptr fs:[0], esp
// 0044f625  83ec14               sub esp, 0x14
// 0044f628  56                   push esi
// 0044f629  85c9                 test ecx, ecx
// 0044f62b  7405                 je 0x44f632
// 0044f62d  8d71f8               lea esi, [ecx - 8]
// 0044f630  eb02                 jmp 0x44f634
// 0044f632  33f6                 xor esi, esi
// 0044f634  c744240800000000     mov dword ptr [esp + 8], 0
// 0044f63c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0044f63f  8d542408             lea edx, [esp + 8]
// 0044f643  52                   push edx
// 0044f644  8d4610               lea eax, [esi + 0x10]
// 0044f647  6810128f00           push 0x8f1210
// 0044f64c  50                   push eax
// 0044f64d  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0044f650  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0044f658  ffd0                 call eax
// 0044f65a  85c0                 test eax, eax
// 0044f65c  8b442408             mov eax, dword ptr [esp + 8]
// 0044f660  0f8513010000         jne 0x44f779
// 0044f666  85c0                 test eax, eax
// 0044f668  0f840b010000         je 0x44f779
// 0044f66e  c744240400000000     mov dword ptr [esp + 4], 0
// 0044f676  8d4c2410             lea ecx, [esp + 0x10]
// 0044f67a  51                   push ecx
// 0044f67b  8d542408             lea edx, [esp + 8]
// 0044f67f  52                   push edx
// 0044f680  8d4e08               lea ecx, [esi + 8]
// 0044f683  c644242801           mov byte ptr [esp + 0x28], 1
// 0044f688  e853fcffff           call 0x44f2e0
// 0044f68d  85c0                 test eax, eax
// 0044f68f  744a                 je 0x44f6db
// 0044f691  50                   push eax
// 0044f692  68d8ce8a00           push 0x8aced8
// 0044f697  68e8698b00           push 0x8b69e8
// 0044f69c  e85f49fdff           call 0x424000
// 0044f6a1  8bf0                 mov esi, eax
// 0044f6a3  8b442410             mov eax, dword ptr [esp + 0x10]
// 0044f6a7  83c40c               add esp, 0xc
// 0044f6aa  50                   push eax
// 0044f6ab  ff153cea8900         call dword ptr [0x89ea3c]
// 0044f6b1  8b442408             mov eax, dword ptr [esp + 8]
// 0044f6b5  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0044f6bd  85c0                 test eax, eax
// 0044f6bf  7408                 je 0x44f6c9
// 0044f6c1  8b08                 mov ecx, dword ptr [eax]
// 0044f6c3  8b5108               mov edx, dword ptr [ecx + 8]
// 0044f6c6  50                   push eax
// 0044f6c7  ffd2                 call edx
// 0044f6c9  8bc6                 mov eax, esi
// 0044f6cb  5e                   pop esi
// 0044f6cc  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044f6d0  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f6d7  83c420               add esp, 0x20
// 0044f6da  c3                   ret 
// 0044f6db  8b442410             mov eax, dword ptr [esp + 0x10]
// 0044f6df  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044f6e3  50                   push eax
// 0044f6e4  51                   push ecx
// 0044f6e5  e8c69afcff           call 0x4191b0
// 0044f6ea  8bf0                 mov esi, eax
// 0044f6ec  83c408               add esp, 8
// 0044f6ef  85f6                 test esi, esi
// 0044f6f1  7477                 je 0x44f76a
// 0044f6f3  8d4c240c             lea ecx, [esp + 0xc]
// 0044f6f7  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0044f6fd  8b542404             mov edx, dword ptr [esp + 4]
// 0044f701  52                   push edx
// 0044f702  8d4c2418             lea ecx, [esp + 0x18]
// 0044f706  c644242402           mov byte ptr [esp + 0x24], 2
// 0044f70b  ff15c0fc8900         call dword ptr [0x89fcc0]
// 0044f711  8b00                 mov eax, dword ptr [eax]
// 0044f713  50                   push eax
// 0044f714  8d4c2410             lea ecx, [esp + 0x10]
// 0044f718  68c4ce8a00           push 0x8acec4
// 0044f71d  51                   push ecx
// 0044f71e  c644242c03           mov byte ptr [esp + 0x2c], 3
// 0044f723  ff15c4fc8900         call dword ptr [0x89fcc4]
// 0044f729  83c40c               add esp, 0xc
// 0044f72c  8d4c2414             lea ecx, [esp + 0x14]
// 0044f730  c644242002           mov byte ptr [esp + 0x20], 2
// 0044f735  ff1510fd8900         call dword ptr [0x89fd10]
// 0044f73b  56                   push esi
// 0044f73c  8d4c2410             lea ecx, [esp + 0x10]
// 0044f740  ff15d0fc8900         call dword ptr [0x89fcd0]
// 0044f746  50                   push eax
// 0044f747  68e8698b00           push 0x8b69e8
// 0044f74c  e8af48fdff           call 0x424000
// 0044f751  83c40c               add esp, 0xc
// 0044f754  8d4c240c             lea ecx, [esp + 0xc]
// 0044f758  8bf0                 mov esi, eax
// 0044f75a  ff1510fd8900         call dword ptr [0x89fd10]
// 0044f760  8b542404             mov edx, dword ptr [esp + 4]
// 0044f764  52                   push edx
// 0044f765  e941ffffff           jmp 0x44f6ab
// 0044f76a  8b442404             mov eax, dword ptr [esp + 4]
// 0044f76e  50                   push eax
// 0044f76f  ff153cea8900         call dword ptr [0x89ea3c]
// 0044f775  8b442408             mov eax, dword ptr [esp + 8]
// 0044f779  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0044f781  85c0                 test eax, eax
// 0044f783  7408                 je 0x44f78d
// 0044f785  8b08                 mov ecx, dword ptr [eax]
// 0044f787  8b5108               mov edx, dword ptr [ecx + 8]
// 0044f78a  50                   push eax
// 0044f78b  ffd2                 call edx
// 0044f78d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044f791  33c0                 xor eax, eax
// 0044f793  5e                   pop esi
// 0044f794  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f79b  83c420               add esp, 0x20
// 0044f79e  c3                   ret 
// copied from an identical function in another client (function ?checkSite@S@ns_ROCX00001c@@QAEHXZ)

namespace ns_ROCX00001c {
// from server: 99% by colin
// roc 2008-06 00403b60  unit: ATL::CComClassFactory  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403b60
//
// 00403b60  64a100000000         mov eax, dword ptr fs:[0]
// 00403b66  6aff                 push -1
// 00403b68  6882cc7b00           push 0x7bcc82
// 00403b6d  50                   push eax
// 00403b6e  64892500000000       mov dword ptr fs:[0], esp
// 00403b75  83ec14               sub esp, 0x14
// 00403b78  56                   push esi
// 00403b79  85c9                 test ecx, ecx
// 00403b7b  7405                 je 0x403b82
// 00403b7d  8d71f8               lea esi, [ecx - 8]
// 00403b80  eb02                 jmp 0x403b84
// 00403b82  33f6                 xor esi, esi
// 00403b84  c744240800000000     mov dword ptr [esp + 8], 0
// 00403b8c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00403b8f  8d542408             lea edx, [esp + 8]
// 00403b93  52                   push edx
// 00403b94  8d4610               lea eax, [esi + 0x10]
// 00403b97  68cc018500           push 0x8501cc
// 00403b9c  50                   push eax
// 00403b9d  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00403ba0  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00403ba8  ffd0                 call eax
// 00403baa  85c0                 test eax, eax
// 00403bac  8b442408             mov eax, dword ptr [esp + 8]
// 00403bb0  0f8513010000         jne 0x403cc9
// 00403bb6  85c0                 test eax, eax
// 00403bb8  0f840b010000         je 0x403cc9
// 00403bbe  c744240400000000     mov dword ptr [esp + 4], 0
// 00403bc6  8d4c2410             lea ecx, [esp + 0x10]
// 00403bca  51                   push ecx
// 00403bcb  8d542408             lea edx, [esp + 8]
// 00403bcf  52                   push edx
// 00403bd0  8d4e08               lea ecx, [esi + 8]
// 00403bd3  c644242801           mov byte ptr [esp + 0x28], 1
// 00403bd8  e833f6ffff           call 0x403210
// 00403bdd  85c0                 test eax, eax
// 00403bdf  744a                 je 0x403c2b
// 00403be1  50                   push eax
// 00403be2  6814b28000           push 0x80b214
// 00403be7  68f8648100           push 0x8164f8
// 00403bec  e83f570200           call 0x429330
// 00403bf1  8bf0                 mov esi, eax
// 00403bf3  8b442410             mov eax, dword ptr [esp + 0x10]
// 00403bf7  83c40c               add esp, 0xc
// 00403bfa  50                   push eax
// 00403bfb  ff1544298000         call dword ptr [0x802944]
// 00403c01  8b442408             mov eax, dword ptr [esp + 8]
// 00403c05  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00403c0d  85c0                 test eax, eax
// 00403c0f  7408                 je 0x403c19
// 00403c11  8b08                 mov ecx, dword ptr [eax]
// 00403c13  8b5108               mov edx, dword ptr [ecx + 8]
// 00403c16  50                   push eax
// 00403c17  ffd2                 call edx
// 00403c19  8bc6                 mov eax, esi
// 00403c1b  5e                   pop esi
// 00403c1c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00403c20  64890d00000000       mov dword ptr fs:[0], ecx
// 00403c27  83c420               add esp, 0x20
// 00403c2a  c3                   ret 
// 00403c2b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00403c2f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00403c33  50                   push eax
// 00403c34  51                   push ecx
// 00403c35  e806a10100           call 0x41dd40
// 00403c3a  8bf0                 mov esi, eax
// 00403c3c  83c408               add esp, 8
// 00403c3f  85f6                 test esi, esi
// 00403c41  7477                 je 0x403cba
// 00403c43  8d4c240c             lea ecx, [esp + 0xc]
// 00403c47  ff15043f8000         call dword ptr [0x803f04]
// 00403c4d  8b542404             mov edx, dword ptr [esp + 4]
// 00403c51  52                   push edx
// 00403c52  8d4c2418             lea ecx, [esp + 0x18]
// 00403c56  c644242402           mov byte ptr [esp + 0x24], 2
// 00403c5b  ff15d83e8000         call dword ptr [0x803ed8]
// 00403c61  8b00                 mov eax, dword ptr [eax]
// 00403c63  50                   push eax
// 00403c64  8d4c2410             lea ecx, [esp + 0x10]
// 00403c68  6800b28000           push 0x80b200
// 00403c6d  51                   push ecx
// 00403c6e  c644242c03           mov byte ptr [esp + 0x2c], 3
// 00403c73  ff15dc3e8000         call dword ptr [0x803edc]
// 00403c79  83c40c               add esp, 0xc
// 00403c7c  8d4c2414             lea ecx, [esp + 0x14]
// 00403c80  c644242002           mov byte ptr [esp + 0x20], 2
// 00403c85  ff15143f8000         call dword ptr [0x803f14]
// 00403c8b  56                   push esi
// 00403c8c  8d4c2410             lea ecx, [esp + 0x10]
// 00403c90  ff15e03e8000         call dword ptr [0x803ee0]
// 00403c96  50                   push eax
// 00403c97  68f8648100           push 0x8164f8
// 00403c9c  e88f560200           call 0x429330
// 00403ca1  83c40c               add esp, 0xc
// 00403ca4  8d4c240c             lea ecx, [esp + 0xc]
// 00403ca8  8bf0                 mov esi, eax
// 00403caa  ff15143f8000         call dword ptr [0x803f14]
// 00403cb0  8b542404             mov edx, dword ptr [esp + 4]
// 00403cb4  52                   push edx
// 00403cb5  e941ffffff           jmp 0x403bfb
// 00403cba  8b442404             mov eax, dword ptr [esp + 4]
// 00403cbe  50                   push eax
// 00403cbf  ff1544298000         call dword ptr [0x802944]
// 00403cc5  8b442408             mov eax, dword ptr [esp + 8]
// 00403cc9  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00403cd1  85c0                 test eax, eax
// 00403cd3  7408                 je 0x403cdd
// 00403cd5  8b08                 mov ecx, dword ptr [eax]
// 00403cd7  8b5108               mov edx, dword ptr [ecx + 8]
// 00403cda  50                   push eax
// 00403cdb  ffd2                 call edx
// 00403cdd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00403ce1  33c0                 xor eax, eax
// 00403ce3  5e                   pop esi
// 00403ce4  64890d00000000       mov dword ptr fs:[0], ecx
// 00403ceb  83c420               add esp, 0x20
// 00403cee  c3                   ret 

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

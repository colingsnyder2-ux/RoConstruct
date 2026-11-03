// from server: 99% by EspClaude
// from server: 100% by Espeon
// roc 2008-06 00407500  unit: VCApp::?$CComObject  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00407500
//
// 00407500  64a100000000         mov eax, dword ptr fs:[0]
// 00407506  6aff                 push -1
// 00407508  6882cc7b00           push 0x7bcc82
// 0040750d  50                   push eax
// 0040750e  64892500000000       mov dword ptr fs:[0], esp
// 00407515  83ec14               sub esp, 0x14
// 00407518  56                   push esi
// 00407519  85c9                 test ecx, ecx
// 0040751b  7405                 je 0x407522
// 0040751d  8d71fc               lea esi, [ecx - 4]
// 00407520  eb02                 jmp 0x407524
// 00407522  33f6                 xor esi, esi
// 00407524  c744240800000000     mov dword ptr [esp + 8], 0
// 0040752c  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0040752f  8d542408             lea edx, [esp + 8]
// 00407533  52                   push edx
// 00407534  8d460c               lea eax, [esi + 0xc]
// 00407537  68cc018500           push 0x8501cc
// 0040753c  50                   push eax
// 0040753d  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00407540  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00407548  ffd0                 call eax
// 0040754a  85c0                 test eax, eax
// 0040754c  8b442408             mov eax, dword ptr [esp + 8]
// 00407550  0f8513010000         jne 0x407669
// 00407556  85c0                 test eax, eax
// 00407558  0f840b010000         je 0x407669
// 0040755e  c744240400000000     mov dword ptr [esp + 4], 0
// 00407566  8d4c2410             lea ecx, [esp + 0x10]
// 0040756a  51                   push ecx
// 0040756b  8d542408             lea edx, [esp + 8]
// 0040756f  52                   push edx
// 00407570  8d4e04               lea ecx, [esi + 4]
// 00407573  c644242801           mov byte ptr [esp + 0x28], 1
// 00407578  e803fcffff           call 0x407180
// 0040757d  85c0                 test eax, eax
// 0040757f  744a                 je 0x4075cb
// 00407581  50                   push eax
// 00407582  6814b28000           push 0x80b214
// 00407587  6808658100           push 0x816508
// 0040758c  e89f1d0200           call 0x429330
// 00407591  8bf0                 mov esi, eax
// 00407593  8b442410             mov eax, dword ptr [esp + 0x10]
// 00407597  83c40c               add esp, 0xc
// 0040759a  50                   push eax
// 0040759b  ff1544298000         call dword ptr [0x802944]
// 004075a1  8b442408             mov eax, dword ptr [esp + 8]
// 004075a5  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004075ad  85c0                 test eax, eax
// 004075af  7408                 je 0x4075b9
// 004075b1  8b08                 mov ecx, dword ptr [eax]
// 004075b3  8b5108               mov edx, dword ptr [ecx + 8]
// 004075b6  50                   push eax
// 004075b7  ffd2                 call edx
// 004075b9  8bc6                 mov eax, esi
// 004075bb  5e                   pop esi
// 004075bc  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004075c0  64890d00000000       mov dword ptr fs:[0], ecx
// 004075c7  83c420               add esp, 0x20
// 004075ca  c3                   ret 
// 004075cb  8b442410             mov eax, dword ptr [esp + 0x10]
// 004075cf  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004075d3  50                   push eax
// 004075d4  51                   push ecx
// 004075d5  e866670100           call 0x41dd40
// 004075da  8bf0                 mov esi, eax
// 004075dc  83c408               add esp, 8
// 004075df  85f6                 test esi, esi
// 004075e1  7477                 je 0x40765a
// 004075e3  8d4c240c             lea ecx, [esp + 0xc]
// 004075e7  ff15043f8000         call dword ptr [0x803f04]
// 004075ed  8b542404             mov edx, dword ptr [esp + 4]
// 004075f1  52                   push edx
// 004075f2  8d4c2418             lea ecx, [esp + 0x18]
// 004075f6  c644242402           mov byte ptr [esp + 0x24], 2
// 004075fb  ff15d83e8000         call dword ptr [0x803ed8]
// 00407601  8b00                 mov eax, dword ptr [eax]
// 00407603  50                   push eax
// 00407604  8d4c2410             lea ecx, [esp + 0x10]
// 00407608  6800b28000           push 0x80b200
// 0040760d  51                   push ecx
// 0040760e  c644242c03           mov byte ptr [esp + 0x2c], 3
// 00407613  ff15dc3e8000         call dword ptr [0x803edc]
// 00407619  83c40c               add esp, 0xc
// 0040761c  8d4c2414             lea ecx, [esp + 0x14]
// 00407620  c644242002           mov byte ptr [esp + 0x20], 2
// 00407625  ff15143f8000         call dword ptr [0x803f14]
// 0040762b  56                   push esi
// 0040762c  8d4c2410             lea ecx, [esp + 0x10]
// 00407630  ff15e03e8000         call dword ptr [0x803ee0]
// 00407636  50                   push eax
// 00407637  6808658100           push 0x816508
// 0040763c  e8ef1c0200           call 0x429330
// 00407641  83c40c               add esp, 0xc
// 00407644  8d4c240c             lea ecx, [esp + 0xc]
// 00407648  8bf0                 mov esi, eax
// 0040764a  ff15143f8000         call dword ptr [0x803f14]
// 00407650  8b542404             mov edx, dword ptr [esp + 4]
// 00407654  52                   push edx
// 00407655  e941ffffff           jmp 0x40759b
// 0040765a  8b442404             mov eax, dword ptr [esp + 4]
// 0040765e  50                   push eax
// 0040765f  ff1544298000         call dword ptr [0x802944]
// 00407665  8b442408             mov eax, dword ptr [esp + 8]
// 00407669  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00407671  85c0                 test eax, eax
// 00407673  7408                 je 0x40767d
// 00407675  8b08                 mov ecx, dword ptr [eax]
// 00407677  8b5108               mov edx, dword ptr [ecx + 8]
// 0040767a  50                   push eax
// 0040767b  ffd2                 call edx
// 0040767d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00407681  33c0                 xor eax, eax
// 00407683  5e                   pop esi
// 00407684  64890d00000000       mov dword ptr fs:[0], ecx
// 0040768b  83c420               add esp, 0x20
// 0040768e  c3                   ret 







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
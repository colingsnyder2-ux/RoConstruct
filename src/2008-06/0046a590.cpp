// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 0046a590  unit: CWebToolbox  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046a590
//
// 0046a590  6aff                 push -1
// 0046a592  6822387c00           push 0x7c3822
// 0046a597  64a100000000         mov eax, dword ptr fs:[0]
// 0046a59d  50                   push eax
// 0046a59e  64892500000000       mov dword ptr fs:[0], esp
// 0046a5a5  83ec08               sub esp, 8
// 0046a5a8  56                   push esi
// 0046a5a9  8bf1                 mov esi, ecx
// 0046a5ab  8d4c2404             lea ecx, [esp + 4]
// 0046a5af  ff15043f8000         call dword ptr [0x803f04]
// 0046a5b5  8d442408             lea eax, [esp + 8]
// 0046a5b9  50                   push eax
// 0046a5ba  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0046a5c2  e809bbf9ff           call 0x4060d0
// 0046a5c7  83c404               add esp, 4
// 0046a5ca  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046a5ce  51                   push ecx
// 0046a5cf  8bc8                 mov ecx, eax
// 0046a5d1  c644241801           mov byte ptr [esp + 0x18], 1
// 0046a5d6  ff15e03e8000         call dword ptr [0x803ee0]
// 0046a5dc  50                   push eax
// 0046a5dd  8d54240c             lea edx, [esp + 0xc]
// 0046a5e1  68c4c48100           push 0x81c4c4
// 0046a5e6  52                   push edx
// 0046a5e7  ff15dc3e8000         call dword ptr [0x803edc]
// 0046a5ed  83c410               add esp, 0x10
// 0046a5f0  8d4c2408             lea ecx, [esp + 8]
// 0046a5f4  c644241400           mov byte ptr [esp + 0x14], 0
// 0046a5f9  ff15143f8000         call dword ptr [0x803f14]
// 0046a5ff  6a00                 push 0
// 0046a601  6a00                 push 0
// 0046a603  6a00                 push 0
// 0046a605  6a00                 push 0
// 0046a607  6a00                 push 0
// 0046a609  8d4c2418             lea ecx, [esp + 0x18]
// 0046a60d  ff15e03e8000         call dword ptr [0x803ee0]
// 0046a613  50                   push eax
// 0046a614  8bce                 mov ecx, esi
// 0046a616  e85f632300           call 0x6a097a
// 0046a61b  8d4c2404             lea ecx, [esp + 4]
// 0046a61f  ff15143f8000         call dword ptr [0x803f14]
// 0046a625  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046a629  5e                   pop esi
// 0046a62a  64890d00000000       mov dword ptr fs:[0], ecx
// 0046a631  83c414               add esp, 0x14
// 0046a634  c20400               ret 4

typedef void (__thiscall *StringConstructor)(void *);
typedef void (__thiscall *StringDestructor)(void *);
typedef const char *(__thiscall *StringText)(const void *);
typedef void (__cdecl *StringFormat)(void *, const char *, ...);

extern StringConstructor stringConstructor;
extern StringDestructor stringDestructor;
extern StringText stringText;
extern StringFormat stringFormat;
extern const char formatString[];

struct String
{
    void *data;

    String();
    __declspec(dllimport) ~String() throw();
    const char *text() const;
};

struct TempString
{
    void *data;
    ~TempString() throw();
    const char *text() const;
};

__forceinline TempString::~TempString() throw()
{
    stringDestructor(this);
}

__forceinline const char *TempString::text() const
{
    return stringText(this);
}

extern TempString __cdecl make_exception();

__forceinline String::String()
{
    stringConstructor(this);
}


__forceinline const char *String::text() const
{
    return stringText(this);
}

struct CWebToolbox
{
    void navigate(const char *, int, int, int, int, int);
    void setCategory(int);
};

void CWebToolbox::setCategory(int category)
{
    String url;
    stringFormat(&url, formatString, make_exception().text(), category);
    navigate(url.text(), 0, 0, 0, 0, 0);
}

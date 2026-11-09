// from server: 100% by Yeetserama
// roc 2011-06 0049bad0  unit: CWebToolbox  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0049bad0
//
// 0049bad0  6aff                 push -1
// 0049bad2  68826e9d00           push 0x9d6e82
// 0049bad7  64a100000000         mov eax, dword ptr fs:[0]
// 0049badd  50                   push eax
// 0049bade  64892500000000       mov dword ptr fs:[0], esp
// 0049bae5  83ec08               sub esp, 8
// 0049bae8  56                   push esi
// 0049bae9  8bf1                 mov esi, ecx
// 0049baeb  e8cae93600           call 0x80a4ba
// 0049baf0  8d442408             lea eax, [esp + 8]
// 0049baf4  50                   push eax
// 0049baf5  e8e67bf6ff           call 0x4036e0
// 0049bafa  68d460a700           push 0xa760d4
// 0049baff  50                   push eax
// 0049bb00  8d4c2410             lea ecx, [esp + 0x10]
// 0049bb04  51                   push ecx
// 0049bb05  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0049bb0d  e8de6df7ff           call 0x4128f0
// 0049bb12  83c410               add esp, 0x10
// 0049bb15  8d4c2408             lea ecx, [esp + 8]
// 0049bb19  c644241402           mov byte ptr [esp + 0x14], 2
// 0049bb1e  ff15082ea400         call dword ptr [0xa42e08]
// 0049bb24  6a00                 push 0
// 0049bb26  6a00                 push 0
// 0049bb28  6a00                 push 0
// 0049bb2a  6a00                 push 0
// 0049bb2c  6a00                 push 0
// 0049bb2e  8d4c2418             lea ecx, [esp + 0x18]
// 0049bb32  ff15c82da400         call dword ptr [0xa42dc8]
// 0049bb38  50                   push eax
// 0049bb39  8bce                 mov ecx, esi
// 0049bb3b  e812e83600           call 0x80a352
// 0049bb40  8d4c2404             lea ecx, [esp + 4]
// 0049bb44  ff15082ea400         call dword ptr [0xa42e08]
// 0049bb4a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049bb4e  5e                   pop esi
// 0049bb4f  64890d00000000       mov dword ptr fs:[0], ecx
// 0049bb56  83c414               add esp, 0x14
// 0049bb59  c3                   ret 
// copied from an identical function in another client (function ?open@CWebToolbox@ns_ROCX00001f@@QAEXXZ)

namespace ns_ROCX00001f {
typedef void (__thiscall *StringDestructor)(void*);
typedef const char* (__thiscall *StringConversion)(const void*);

extern StringDestructor destroyString;
extern StringConversion convertString;

struct String
{
    void* data;

    ~String();
    operator const char*() const;
};

inline String::~String()
{
    destroyString(this);
}

inline String::operator const char*() const
{
    return convertString(this);
}

struct ImportedString
{
    void* data;

    __declspec(dllimport) ~ImportedString() throw();
    operator const char*() const;
};

inline ImportedString::operator const char*() const
{
    return convertString(this);
}

extern String __cdecl makeString();
extern ImportedString __cdecl concatenate(const String&, const char*);

struct CWebToolbox
{
    void prepare();
    void navigate(const char*, int, int, int, int, int);
    void open();
};

void CWebToolbox::open()
{
    prepare();
    const ImportedString& address = concatenate(makeString(), "/IDE/ClientToolbox.aspx");
    navigate(address, 0, 0, 0, 0, 0);
}
}

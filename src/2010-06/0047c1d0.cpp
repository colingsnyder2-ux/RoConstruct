// from server: 100% by Yeetserama
// roc 2010-06 0047c1d0  unit: CWebToolbox  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047c1d0
//
// 0047c1d0  6aff                 push -1
// 0047c1d2  68a2509800           push 0x9850a2
// 0047c1d7  64a100000000         mov eax, dword ptr fs:[0]
// 0047c1dd  50                   push eax
// 0047c1de  64892500000000       mov dword ptr fs:[0], esp
// 0047c1e5  83ec08               sub esp, 8
// 0047c1e8  56                   push esi
// 0047c1e9  8bf1                 mov esi, ecx
// 0047c1eb  e80cbc3200           call 0x7a7dfc
// 0047c1f0  8d442408             lea eax, [esp + 8]
// 0047c1f4  50                   push eax
// 0047c1f5  e8166bf8ff           call 0x402d10
// 0047c1fa  68142ba100           push 0xa12b14
// 0047c1ff  50                   push eax
// 0047c200  8d4c2410             lea ecx, [esp + 0x10]
// 0047c204  51                   push ecx
// 0047c205  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0047c20d  e8fe10f9ff           call 0x40d310
// 0047c212  83c410               add esp, 0x10
// 0047c215  8d4c2408             lea ecx, [esp + 8]
// 0047c219  c644241402           mov byte ptr [esp + 0x14], 2
// 0047c21e  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0047c224  6a00                 push 0
// 0047c226  6a00                 push 0
// 0047c228  6a00                 push 0
// 0047c22a  6a00                 push 0
// 0047c22c  6a00                 push 0
// 0047c22e  8d4c2418             lea ecx, [esp + 0x18]
// 0047c232  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 0047c238  50                   push eax
// 0047c239  8bce                 mov ecx, esi
// 0047c23b  e854ba3200           call 0x7a7c94
// 0047c240  8d4c2404             lea ecx, [esp + 4]
// 0047c244  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0047c24a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047c24e  5e                   pop esi
// 0047c24f  64890d00000000       mov dword ptr fs:[0], ecx
// 0047c256  83c414               add esp, 0x14
// 0047c259  c3                   ret 
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

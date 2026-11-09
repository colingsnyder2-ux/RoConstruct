// from server: 100% by Yeetserama
// roc 2010-06 0047c050  unit: CWebToolbox  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047c050
//
// 0047c050  6aff                 push -1
// 0047c052  6842fa9700           push 0x97fa42
// 0047c057  64a100000000         mov eax, dword ptr fs:[0]
// 0047c05d  50                   push eax
// 0047c05e  64892500000000       mov dword ptr fs:[0], esp
// 0047c065  83ec08               sub esp, 8
// 0047c068  56                   push esi
// 0047c069  8bf1                 mov esi, ecx
// 0047c06b  8d4c2404             lea ecx, [esp + 4]
// 0047c06f  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 0047c075  8d442408             lea eax, [esp + 8]
// 0047c079  50                   push eax
// 0047c07a  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0047c082  e8896cf8ff           call 0x402d10
// 0047c087  83c404               add esp, 4
// 0047c08a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0047c08e  51                   push ecx
// 0047c08f  8bc8                 mov ecx, eax
// 0047c091  c644241801           mov byte ptr [esp + 0x18], 1
// 0047c096  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 0047c09c  50                   push eax
// 0047c09d  8d54240c             lea edx, [esp + 0xc]
// 0047c0a1  68b028a100           push 0xa128b0
// 0047c0a6  52                   push edx
// 0047c0a7  ff15acce9e00         call dword ptr [0x9eceac]
// 0047c0ad  83c410               add esp, 0x10
// 0047c0b0  8d4c2408             lea ecx, [esp + 8]
// 0047c0b4  c644241400           mov byte ptr [esp + 0x14], 0
// 0047c0b9  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0047c0bf  6a00                 push 0
// 0047c0c1  6a00                 push 0
// 0047c0c3  6a00                 push 0
// 0047c0c5  6a00                 push 0
// 0047c0c7  6a00                 push 0
// 0047c0c9  8d4c2418             lea ecx, [esp + 0x18]
// 0047c0cd  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 0047c0d3  50                   push eax
// 0047c0d4  8bce                 mov ecx, esi
// 0047c0d6  e8b9bb3200           call 0x7a7c94
// 0047c0db  8d4c2404             lea ecx, [esp + 4]
// 0047c0df  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0047c0e5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047c0e9  5e                   pop esi
// 0047c0ea  64890d00000000       mov dword ptr fs:[0], ecx
// 0047c0f1  83c414               add esp, 0x14
// 0047c0f4  c20400               ret 4
// copied from an identical function in another client (function ?setCategory@CWebToolbox@ns_ROCX000019@@QAEXH@Z)

namespace ns_ROCX000019 {
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
}

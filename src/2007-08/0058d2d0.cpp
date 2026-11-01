// from server: 100% by colin
// roc 2007-08 0058d2d0  unit: RBX::SoundService  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0058d2d0
//
// 0058d2d0  83ec44               sub esp, 0x44
// 0058d2d3  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0058d2d7  d94008               fld dword ptr [eax + 8]
// 0058d2da  56                   push esi
// 0058d2db  83ec18               sub esp, 0x18
// 0058d2de  dd5c2410             fstp qword ptr [esp + 0x10]
// 0058d2e2  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0058d2ea  d94004               fld dword ptr [eax + 4]
// 0058d2ed  dd5c2408             fstp qword ptr [esp + 8]
// 0058d2f1  d900                 fld dword ptr [eax]
// 0058d2f3  8d442420             lea eax, [esp + 0x20]
// 0058d2f7  dd1c24               fstp qword ptr [esp]
// 0058d2fa  68a4f67a00           push 0x7af6a4
// 0058d2ff  6a40                 push 0x40
// 0058d301  50                   push eax
// 0058d302  ff155ce87700         call dword ptr [0x77e85c]
// 0058d308  8b742470             mov esi, dword ptr [esp + 0x70]
// 0058d30c  83c424               add esp, 0x24
// 0058d30f  8d4c2408             lea ecx, [esp + 8]
// 0058d313  51                   push ecx
// 0058d314  8bce                 mov ecx, esi
// 0058d316  ff1598e67700         call dword ptr [0x77e698]
// 0058d31c  8bc6                 mov eax, esi
// 0058d31e  5e                   pop esi
// 0058d31f  83c444               add esp, 0x44
// 0058d322  c3                   ret 
// copied from an identical function in another client (function ?f@@YA?AUString@@ABUVector@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String;

typedef int (__cdecl *FormatFunction)(char*, unsigned int, const char*, ...);
typedef void (__thiscall *StringConstructor)(String*, const char*);

extern FormatFunction formatFunction;
extern StringConstructor stringConstructor;

struct Vector {
    float x, y, z;
};

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

__forceinline String::String(const char* text)
{
    stringConstructor(this, text);
}

String __cdecl f(const Vector& value)
{
    char buffer[64];
    formatFunction(buffer, 64, "%g, %g, %g",
                   value.x, value.y, value.z);
    return String(buffer);
}
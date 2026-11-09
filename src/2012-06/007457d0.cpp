// roc 2012-06 007457d0  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007457d0
//
// 007457d0  83ec44               sub esp, 0x44
// 007457d3  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007457d7  d94008               fld dword ptr [eax + 8]
// 007457da  56                   push esi
// 007457db  83ec18               sub esp, 0x18
// 007457de  dd5c2410             fstp qword ptr [esp + 0x10]
// 007457e2  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 007457ea  d94004               fld dword ptr [eax + 4]
// 007457ed  dd5c2408             fstp qword ptr [esp + 8]
// 007457f1  d900                 fld dword ptr [eax]
// 007457f3  8d442420             lea eax, [esp + 0x20]
// 007457f7  dd1c24               fstp qword ptr [esp]
// 007457fa  6888a9ba00           push 0xbaa988
// 007457ff  6a40                 push 0x40
// 00745801  50                   push eax
// 00745802  ff15482ab200         call dword ptr [0xb22a48]
// 00745808  8b742470             mov esi, dword ptr [esp + 0x70]
// 0074580c  83c424               add esp, 0x24
// 0074580f  8d4c2408             lea ecx, [esp + 8]
// 00745813  51                   push ecx
// 00745814  8bce                 mov ecx, esi
// 00745816  ff154826b200         call dword ptr [0xb22648]
// 0074581c  8bc6                 mov eax, esi
// 0074581e  5e                   pop esi
// 0074581f  83c444               add esp, 0x44
// 00745822  c3                   ret 
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
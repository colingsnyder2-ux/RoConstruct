// from server: 100% by colin
// roc 2007-08 00434340  unit: CObjectBrowser  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434340
//
// 00434340  53                   push ebx
// 00434341  56                   push esi
// 00434342  57                   push edi
// 00434343  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00434347  8bf7                 mov esi, edi
// 00434349  e822ffffff           call 0x434270
// 0043434e  8b742414             mov esi, dword ptr [esp + 0x14]
// 00434352  8bd8                 mov ebx, eax
// 00434354  e817ffffff           call 0x434270
// 00434359  8bc8                 mov ecx, eax
// 0043435b  3bd9                 cmp ebx, ecx
// 0043435d  740a                 je 0x434369
// 0043435f  5f                   pop edi
// 00434360  8bc3                 mov eax, ebx
// 00434362  5e                   pop esi
// 00434363  2bc1                 sub eax, ecx
// 00434365  5b                   pop ebx
// 00434366  c20c00               ret 0xc
// 00434369  8b4604               mov eax, dword ptr [esi + 4]
// 0043436c  8d4804               lea ecx, [eax + 4]
// 0043436f  ff15a8e67700         call dword ptr [0x77e6a8]
// 00434375  8b4f04               mov ecx, dword ptr [edi + 4]
// 00434378  83c104               add ecx, 4
// 0043437b  8bf0                 mov esi, eax
// 0043437d  ff15a8e67700         call dword ptr [0x77e6a8]
// 00434383  8a08                 mov cl, byte ptr [eax]
// 00434385  3a0e                 cmp cl, byte ptr [esi]
// 00434387  751e                 jne 0x4343a7
// 00434389  84c9                 test cl, cl
// 0043438b  7412                 je 0x43439f
// 0043438d  8a4801               mov cl, byte ptr [eax + 1]
// 00434390  3a4e01               cmp cl, byte ptr [esi + 1]
// 00434393  7512                 jne 0x4343a7
// 00434395  83c002               add eax, 2
// 00434398  83c602               add esi, 2
// 0043439b  84c9                 test cl, cl
// 0043439d  75e4                 jne 0x434383
// 0043439f  5f                   pop edi
// 004343a0  5e                   pop esi
// 004343a1  33c0                 xor eax, eax
// 004343a3  5b                   pop ebx
// 004343a4  c20c00               ret 0xc
// 004343a7  5f                   pop edi
// 004343a8  1bc0                 sbb eax, eax
// 004343aa  5e                   pop esi
// 004343ab  83d8ff               sbb eax, -1
// 004343ae  5b                   pop ebx
// 004343af  c20c00               ret 0xc
// copied from an identical function in another client (function ?fn_ROCX000000@@YGHRBUItem@@PBU1@J@Z)

// from server: 93% by colin
#include <string.h>

struct String
{
    typedef const char* (__thiscall *CStr)(const String*);
    static CStr c_str;
};

struct Object
{
    unsigned char unknown[4];
    String name;
};

struct Item
{
    unsigned char unknown[4];
    Object* object;
};

extern int __stdcall G1_impl(const Item*);
extern int __stdcall G1_check(const Item*);

static __declspec(noinline) int G1(const Item* item)
{
    if (G1_check(item))
        return 0;
    return G1_impl(item);
}

int __stdcall func_004335d0(const Item* volatile input, const Item* second, long)
{
    const Item* first=input;
    int a = G1(first);
    int b = G1(second);

    if (a != b)
        return a - b;

    Object* object = second->object;
    const char* secondName = String::c_str(&object->name);
    return strcmp(String::c_str(&first->object->name), secondName);
}
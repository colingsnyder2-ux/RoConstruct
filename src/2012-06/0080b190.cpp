// roc 2012-06 0080b190  unit: RBX::P8GuiTextMixin::?$GetSetImpl  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0080b190
//
// 0080b190  8b442404             mov eax, dword ptr [esp + 4]
// 0080b194  8bd1                 mov edx, ecx
// 0080b196  85c0                 test eax, eax
// 0080b198  7405                 je 0x80b19f
// 0080b19a  83c0e4               add eax, -0x1c
// 0080b19d  eb02                 jmp 0x80b1a1
// 0080b19f  33c0                 xor eax, eax
// 0080b1a1  51                   push ecx
// 0080b1a2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0080b1a6  d901                 fld dword ptr [ecx]
// 0080b1a8  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 0080b1ab  8b5208               mov edx, dword ptr [edx + 8]
// 0080b1ae  d91c24               fstp dword ptr [esp]
// 0080b1b1  03c8                 add ecx, eax
// 0080b1b3  ffd2                 call edx
// 0080b1b5  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000014@@QAEXPAXPAM@Z)

namespace ns_ROCX000014 {
struct S
{
    void f(void*, float*);
};

void S::f(void* object, float* value)
{
    char* base = (char*)object;
    if (base != 0)
        base -= 0x1c;
    else
        base = 0;

    void** table = *(void*** )((char*)this + 8);
    char* target = *(char**)((char*)this + 0xc);
    ((void (__thiscall *)(char*, float))table)(target + (int)base, *value);
}
}

// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00563ad0  unit: RBX::P8DebugSettings::?$GetSetImpl  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00563ad0
//
// 00563ad0  8b442404             mov eax, dword ptr [esp + 4]
// 00563ad4  8bd1                 mov edx, ecx
// 00563ad6  85c0                 test eax, eax
// 00563ad8  7405                 je 0x563adf
// 00563ada  83c0ec               add eax, -0x14
// 00563add  eb02                 jmp 0x563ae1
// 00563adf  33c0                 xor eax, eax
// 00563ae1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00563ae5  dd01                 fld qword ptr [ecx]
// 00563ae7  8b4a14               mov ecx, dword ptr [edx + 0x14]
// 00563aea  8b5210               mov edx, dword ptr [edx + 0x10]
// 00563aed  83ec08               sub esp, 8
// 00563af0  03c8                 add ecx, eax
// 00563af2  dd1c24               fstp qword ptr [esp]
// 00563af5  ffd2                 call edx
// 00563af7  c20800               ret 8

struct Base1 { int a; };
struct Base2 { int b; };
struct Object : Base1, Base2 {};

struct S {
    char padding[16];
    void (Object::*setter)(double);
    void f(void* object, const double& value);
};

void S::f(void* object, const double& value)
{
    Object* target = object
        ? reinterpret_cast<Object*>(static_cast<char*>(object) - 24)
        : 0;
    (target->*setter)(value);
}

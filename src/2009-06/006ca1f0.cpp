// from server: 100% by EspClaude
// roc 2009-06 006ca1f0  unit: RBX::AnchorTool  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ca1f0
//
// 006ca1f0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006ca1f3  85c0                 test eax, eax
// 006ca1f5  742b                 je 0x6ca222
// 006ca1f7  6a00                 push 0
// 006ca1f9  68e0289f00           push 0x9f28e0
// 006ca1fe  6840be9d00           push 0x9dbe40
// 006ca203  6a00                 push 0
// 006ca205  50                   push eax
// 006ca206  e86ffa0400           call 0x719c7a
// 006ca20b  83c414               add esp, 0x14
// 006ca20e  85c0                 test eax, eax
// 006ca210  7410                 je 0x6ca222
// 006ca212  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006ca216  8b10                 mov edx, dword ptr [eax]
// 006ca218  8b5210               mov edx, dword ptr [edx + 0x10]
// 006ca21b  6a00                 push 0
// 006ca21d  51                   push ecx
// 006ca21e  8bc8                 mov ecx, eax
// 006ca220  ffd2                 call edx
// 006ca222  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000014@@QAEXPAX@Z)

namespace ns_ROCX000014 {
extern char sourceType[];
extern char targetType[];

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct Renderable {
    typedef void (__thiscall *Method)(Renderable*, void*, int);
    Method* vtable;
};

struct S {
    char padding[24];
    void* instance;
    void f(void* argument);
};

void S::f(void* argument)
{
    if (instance) {
        Renderable* object = static_cast<Renderable*>(
            __RTDynamicCast(instance, 0, sourceType, targetType, 0));
        if (object)
            object->vtable[4](object, argument, 0);
    }
}
}

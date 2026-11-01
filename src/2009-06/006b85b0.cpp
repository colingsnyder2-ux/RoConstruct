// from server: 100% by EspClaude
// roc 2009-06 006b85b0  unit: RBX::GlueTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b85b0
//
// 006b85b0  56                   push esi
// 006b85b1  8b742408             mov esi, dword ptr [esp + 8]
// 006b85b5  57                   push edi
// 006b85b6  8bf9                 mov edi, ecx
// 006b85b8  8b0e                 mov ecx, dword ptr [esi]
// 006b85ba  e8d13cfaff           call 0x65c290
// 006b85bf  8bce                 mov ecx, esi
// 006b85c1  e88aa2fcff           call 0x682850
// 006b85c6  6a01                 push 1
// 006b85c8  8bce                 mov ecx, esi
// 006b85ca  e8c1a0fcff           call 0x682690
// 006b85cf  8b0e                 mov ecx, dword ptr [esi]
// 006b85d1  e8da3cfaff           call 0x65c2b0
// 006b85d6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b85d9  6a08                 push 8
// 006b85db  50                   push eax
// 006b85dc  e84f52f5ff           call 0x60d830
// 006b85e1  83c404               add esp, 4
// 006b85e4  8bc8                 mov ecx, eax
// 006b85e6  e8c519f9ff           call 0x649fb0
// 006b85eb  5f                   pop edi
// 006b85ec  5e                   pop esi
// 006b85ed  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000004_00619f70@GlueTool@ns_ROCX000004@@QAEXPAUArgument@2@@Z)

namespace ns_ROCX000004 {
namespace RBX {
struct Instance;
struct ServiceProvider {
    void fn_ROCX000004_005bd820(int value);
};
}

extern RBX::ServiceProvider* __cdecl fn_ROCX000004_005807b0(RBX::Instance* object);

struct S {
    void fn_ROCX000004_00598c70();
    void fn_ROCX000004_00598c90();
};

struct Argument {
    S* object;
    void fn_ROCX000004_005f1690();
    void fn_ROCX000004_005f13e0(int value);
};

struct GlueTool {
    char padding[0x18];
    RBX::Instance* instance;
    void fn_ROCX000004_00619f70(Argument* argument);
};

void GlueTool::fn_ROCX000004_00619f70(Argument* argument)
{
    argument->object->fn_ROCX000004_00598c70();
    argument->fn_ROCX000004_005f1690();
    argument->fn_ROCX000004_005f13e0(1);
    argument->object->fn_ROCX000004_00598c90();
    fn_ROCX000004_005807b0(instance)->fn_ROCX000004_005bd820(8);
}
}

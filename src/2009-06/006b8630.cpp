// from server: 100% by EspClaude
// roc 2009-06 006b8630  unit: RBX::StudsTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8630
//
// 006b8630  56                   push esi
// 006b8631  8b742408             mov esi, dword ptr [esp + 8]
// 006b8635  57                   push edi
// 006b8636  8bf9                 mov edi, ecx
// 006b8638  8b0e                 mov ecx, dword ptr [esi]
// 006b863a  e8513cfaff           call 0x65c290
// 006b863f  8bce                 mov ecx, esi
// 006b8641  e80aa2fcff           call 0x682850
// 006b8646  6a03                 push 3
// 006b8648  8bce                 mov ecx, esi
// 006b864a  e841a0fcff           call 0x682690
// 006b864f  8b0e                 mov ecx, dword ptr [esi]
// 006b8651  e85a3cfaff           call 0x65c2b0
// 006b8656  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b8659  6a08                 push 8
// 006b865b  50                   push eax
// 006b865c  e8cf51f5ff           call 0x60d830
// 006b8661  83c404               add esp, 4
// 006b8664  8bc8                 mov ecx, eax
// 006b8666  e84519f9ff           call 0x649fb0
// 006b866b  5f                   pop edi
// 006b866c  5e                   pop esi
// 006b866d  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000006_00619ff0@S@ns_ROCX000006@@QAEXPAUArgument@2@@Z)

namespace ns_ROCX000006 {
struct Object
{
    void fn_ROCX000006_00598c70();
    void fn_ROCX000006_00598c90();
};

struct Argument
{
    Object* object;
    void fn_ROCX000006_005f1690();
    void fn_ROCX000006_005f13e0(int value);
};

namespace RBX
{
    struct Instance;
    struct ServiceProvider
    {
        void fn_ROCX000006_005bd820(int value);
    };
}

extern RBX::ServiceProvider* __cdecl fn_ROCX000006_005807b0(RBX::Instance* object);

struct S
{
    char padding[0x18];
    RBX::Instance* object;
    void fn_ROCX000006_00619ff0(Argument* argument);
};

void S::fn_ROCX000006_00619ff0(Argument* argument)
{
    argument->object->fn_ROCX000006_00598c70();
    argument->fn_ROCX000006_005f1690();
    argument->fn_ROCX000006_005f13e0(3);
    argument->object->fn_ROCX000006_00598c90();
    fn_ROCX000006_005807b0(object)->fn_ROCX000006_005bd820(8);
}
}

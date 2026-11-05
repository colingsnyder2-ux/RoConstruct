// from server: 100% by EspClaude
// roc 2009-06 006b8670  unit: RBX::InletTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8670
//
// 006b8670  56                   push esi
// 006b8671  8b742408             mov esi, dword ptr [esp + 8]
// 006b8675  57                   push edi
// 006b8676  8bf9                 mov edi, ecx
// 006b8678  8b0e                 mov ecx, dword ptr [esi]
// 006b867a  e8113cfaff           call 0x65c290
// 006b867f  8bce                 mov ecx, esi
// 006b8681  e8caa1fcff           call 0x682850
// 006b8686  6a04                 push 4
// 006b8688  8bce                 mov ecx, esi
// 006b868a  e801a0fcff           call 0x682690
// 006b868f  8b0e                 mov ecx, dword ptr [esi]
// 006b8691  e81a3cfaff           call 0x65c2b0
// 006b8696  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b8699  6a08                 push 8
// 006b869b  50                   push eax
// 006b869c  e88f51f5ff           call 0x60d830
// 006b86a1  83c404               add esp, 4
// 006b86a4  8bc8                 mov ecx, eax
// 006b86a6  e80519f9ff           call 0x649fb0
// 006b86ab  5f                   pop edi
// 006b86ac  5e                   pop esi
// 006b86ad  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000007_0061a030@InletTool@ns_ROCX000007@@QAEXPAUArgument@2@@Z)

namespace ns_ROCX000007 {
namespace RBX
{
    class Instance;
    class ServiceProvider
    {
    public:
        void fn_ROCX000007_005bd820(int);
    };
}

extern RBX::ServiceProvider* __cdecl fn_ROCX000007_005807b0(RBX::Instance*);

struct S
{
    void fn_ROCX000007_00598c70();
    void fn_ROCX000007_00598c90();
};

struct Argument
{
    S* object;
    void fn_ROCX000007_005f1690();
    void fn_ROCX000007_005f13e0(int);
};

struct InletTool
{
    char padding[0x18];
    RBX::Instance* instance;
    void fn_ROCX000007_0061a030(Argument*);
};

void InletTool::fn_ROCX000007_0061a030(Argument* argument)
{
    argument->object->fn_ROCX000007_00598c70();
    argument->fn_ROCX000007_005f1690();
    argument->fn_ROCX000007_005f13e0(4);
    argument->object->fn_ROCX000007_00598c90();
    fn_ROCX000007_005807b0(instance)->fn_ROCX000007_005bd820(8);
}
}

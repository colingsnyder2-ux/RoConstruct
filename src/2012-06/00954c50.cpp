// roc 2012-06 00954c50  unit: RBX::MechToAssemblyStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00954c50
//
// 00954c50  56                   push esi
// 00954c51  57                   push edi
// 00954c52  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00954c56  8bf1                 mov esi, ecx
// 00954c58  8b4e08               mov ecx, dword ptr [esi + 8]
// 00954c5b  57                   push edi
// 00954c5c  e81f0ffdff           call 0x925b80
// 00954c61  56                   push esi
// 00954c62  8bcf                 mov ecx, edi
// 00954c64  e8f728fcff           call 0x917560
// 00954c69  5f                   pop edi
// 00954c6a  5e                   pop esi
// 00954c6b  c20400               ret 4
// copied from an identical function in another client (function ?construct@GettingUp@ns_ROCX000002@@QAEXPAX@Z)

namespace ns_ROCX000002 {
struct SubA {
    void methodA(int);
};

struct SubB {
    void methodB(void*);
};

struct GettingUp {
    char pad[8];
    SubA* subA;
    void construct(void*);
};

void GettingUp::construct(void* arg)
{
    subA->methodA((int)arg);
    ((SubB*)arg)->methodB(this);
}
}

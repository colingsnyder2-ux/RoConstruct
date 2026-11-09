// roc 2012-06 009286b0  unit: RBX::StepJointsStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009286b0
//
// 009286b0  56                   push esi
// 009286b1  57                   push edi
// 009286b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 009286b6  8bf1                 mov esi, ecx
// 009286b8  8b4e08               mov ecx, dword ptr [esi + 8]
// 009286bb  57                   push edi
// 009286bc  e8cffbffff           call 0x928290
// 009286c1  56                   push esi
// 009286c2  8bcf                 mov ecx, edi
// 009286c4  e897eefeff           call 0x917560
// 009286c9  5f                   pop edi
// 009286ca  5e                   pop esi
// 009286cb  c20400               ret 4
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

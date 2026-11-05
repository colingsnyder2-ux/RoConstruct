// roc 2012-06 00928290  unit: RBX::TreeStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00928290
//
// 00928290  56                   push esi
// 00928291  57                   push edi
// 00928292  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00928296  8bf1                 mov esi, ecx
// 00928298  8b4e08               mov ecx, dword ptr [esi + 8]
// 0092829b  57                   push edi
// 0092829c  e85fc40300           call 0x964700
// 009282a1  56                   push esi
// 009282a2  8bcf                 mov ecx, edi
// 009282a4  e8b7f2feff           call 0x917560
// 009282a9  5f                   pop edi
// 009282aa  5e                   pop esi
// 009282ab  c20400               ret 4
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

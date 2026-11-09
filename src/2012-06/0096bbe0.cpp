// roc 2012-06 0096bbe0  unit: RBX::ContactStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096bbe0
//
// 0096bbe0  56                   push esi
// 0096bbe1  57                   push edi
// 0096bbe2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0096bbe6  8bf1                 mov esi, ecx
// 0096bbe8  8b4e08               mov ecx, dword ptr [esi + 8]
// 0096bbeb  57                   push edi
// 0096bbec  e82fb2fbff           call 0x926e20
// 0096bbf1  56                   push esi
// 0096bbf2  8bcf                 mov ecx, edi
// 0096bbf4  e867b9faff           call 0x917560
// 0096bbf9  5f                   pop edi
// 0096bbfa  5e                   pop esi
// 0096bbfb  c20400               ret 4
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

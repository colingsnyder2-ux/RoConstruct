// roc 2012-06 00963640  unit: RBX::EdgeStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00963640
//
// 00963640  56                   push esi
// 00963641  57                   push edi
// 00963642  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00963646  8bf1                 mov esi, ecx
// 00963648  8b4e08               mov ecx, dword ptr [esi + 8]
// 0096364b  57                   push edi
// 0096364c  e88f850000           call 0x96bbe0
// 00963651  56                   push esi
// 00963652  8bcf                 mov ecx, edi
// 00963654  e8073ffbff           call 0x917560
// 00963659  5f                   pop edi
// 0096365a  5e                   pop esi
// 0096365b  c20400               ret 4
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

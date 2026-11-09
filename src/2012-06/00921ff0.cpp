// roc 2012-06 00921ff0  unit: RBX::CleanStage  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00921ff0
//
// 00921ff0  56                   push esi
// 00921ff1  57                   push edi
// 00921ff2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00921ff6  8bf1                 mov esi, ecx
// 00921ff8  8b4e08               mov ecx, dword ptr [esi + 8]
// 00921ffb  57                   push edi
// 00921ffc  e8ff040400           call 0x962500
// 00922001  56                   push esi
// 00922002  8bcf                 mov ecx, edi
// 00922004  e84753ffff           call 0x917350
// 00922009  5f                   pop edi
// 0092200a  5e                   pop esi
// 0092200b  c20400               ret 4
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

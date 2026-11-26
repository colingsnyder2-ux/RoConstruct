// from server: 100% by Xemicl
// roc 2012-06 004a0680  unit: CScriptEditor  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0680
//
// 004a0680  56                   push esi
// 004a0681  8b742408             mov esi, dword ptr [esp + 8]
// 004a0685  57                   push edi
// 004a0686  8b3e                 mov edi, dword ptr [esi]
// 004a0688  6a01                 push 1
// 004a068a  6a02                 push 2
// 004a068c  e8ff350500           call 0x4f3c90
// 004a0691  8bc8                 mov ecx, eax
// 004a0693  e8d8c8ffff           call 0x49cf70
// 004a0698  f7d8                 neg eax
// 004a069a  1bc0                 sbb eax, eax
// 004a069c  f7d8                 neg eax
// 004a069e  50                   push eax
// 004a069f  8b4704               mov eax, dword ptr [edi + 4]
// 004a06a2  8bce                 mov ecx, esi
// 004a06a4  ffd0                 call eax
// 004a06a6  5f                   pop edi
// 004a06a7  5e                   pop esi
// 004a06a8  c20400               ret 4
// copied from an identical function in another client (function ?update@S@ns_ROCX00000a@@QAEXPAUTarget@2@@Z)

namespace ns_ROCX00000a {
struct Control {
    int query(int, int);
};

struct Target {
    virtual void slot0();
    virtual void setEnabled(int);
};

struct S {
    char pad0[88];
    int m_x;
    int* f();
    void update(Target*);
};

void S::update(Target* target)
{
    target->setEnabled(reinterpret_cast<Control*>(f())->query(2, 1) != 0);
}
}

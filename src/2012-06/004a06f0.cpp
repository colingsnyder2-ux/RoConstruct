// from server: 100% by Xemicl
// roc 2012-06 004a06f0  unit: CScriptEditor  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a06f0
//
// 004a06f0  56                   push esi
// 004a06f1  8b742408             mov esi, dword ptr [esp + 8]
// 004a06f5  57                   push edi
// 004a06f6  8b3e                 mov edi, dword ptr [esi]
// 004a06f8  6a01                 push 1
// 004a06fa  6a01                 push 1
// 004a06fc  e88f350500           call 0x4f3c90
// 004a0701  8bc8                 mov ecx, eax
// 004a0703  e868c8ffff           call 0x49cf70
// 004a0708  f7d8                 neg eax
// 004a070a  1bc0                 sbb eax, eax
// 004a070c  f7d8                 neg eax
// 004a070e  50                   push eax
// 004a070f  8b4704               mov eax, dword ptr [edi + 4]
// 004a0712  8bce                 mov ecx, esi
// 004a0714  ffd0                 call eax
// 004a0716  5f                   pop edi
// 004a0717  5e                   pop esi
// 004a0718  c20400               ret 4
// copied from an identical function in another client (function ?update@S@ns_ROCX00000c@@QAEXPAUTarget@2@@Z)

namespace ns_ROCX00000c {
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
    target->setEnabled(reinterpret_cast<Control*>(f())->query(1, 1) != 0);
}
}

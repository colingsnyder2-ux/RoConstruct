// from server: 100% by Xemicl
// roc 2012-06 004a0760  unit: CScriptEditor  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0760
//
// 004a0760  56                   push esi
// 004a0761  8b742408             mov esi, dword ptr [esp + 8]
// 004a0765  57                   push edi
// 004a0766  8b3e                 mov edi, dword ptr [esi]
// 004a0768  6a01                 push 1
// 004a076a  6a00                 push 0
// 004a076c  e81f350500           call 0x4f3c90
// 004a0771  8bc8                 mov ecx, eax
// 004a0773  e8f8c7ffff           call 0x49cf70
// 004a0778  f7d8                 neg eax
// 004a077a  1bc0                 sbb eax, eax
// 004a077c  f7d8                 neg eax
// 004a077e  50                   push eax
// 004a077f  8b4704               mov eax, dword ptr [edi + 4]
// 004a0782  8bce                 mov ecx, esi
// 004a0784  ffd0                 call eax
// 004a0786  5f                   pop edi
// 004a0787  5e                   pop esi
// 004a0788  c20400               ret 4
// copied from an identical function in another client (function ?update@S@ns_ROCX00000e@@QAEXPAUTarget@2@@Z)

namespace ns_ROCX00000e {
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
    target->setEnabled(reinterpret_cast<Control*>(f())->query(0, 1) != 0);
}
}

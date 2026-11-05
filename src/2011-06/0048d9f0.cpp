// from server: 100% by Yeetserama
// roc 2011-06 0048d9f0  unit: CScriptEditor  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048d9f0
//
// 0048d9f0  56                   push esi
// 0048d9f1  8b742408             mov esi, dword ptr [esp + 8]
// 0048d9f5  57                   push edi
// 0048d9f6  8b3e                 mov edi, dword ptr [esi]
// 0048d9f8  6a01                 push 1
// 0048d9fa  6a01                 push 1
// 0048d9fc  e8efd5ffff           call 0x48aff0
// 0048da01  8bc8                 mov ecx, eax
// 0048da03  e838c8ffff           call 0x48a240
// 0048da08  f7d8                 neg eax
// 0048da0a  1bc0                 sbb eax, eax
// 0048da0c  f7d8                 neg eax
// 0048da0e  50                   push eax
// 0048da0f  8b4704               mov eax, dword ptr [edi + 4]
// 0048da12  8bce                 mov ecx, esi
// 0048da14  ffd0                 call eax
// 0048da16  5f                   pop edi
// 0048da17  5e                   pop esi
// 0048da18  c20400               ret 4
// copied from an identical function in another client (function ?update@S@ns_ROCX00001f@@QAEXPAUTarget@2@@Z)

namespace ns_ROCX00001f {
// from server: 100% by king_originala
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

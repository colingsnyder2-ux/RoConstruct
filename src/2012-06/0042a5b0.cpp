// from server: 100% by Xemicl
// roc 2012-06 0042a5b0  unit: CXTTreeCtrl  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a5b0
//
// 0042a5b0  6aff                 push -1
// 0042a5b2  687835aa00           push 0xaa3578
// 0042a5b7  64a100000000         mov eax, dword ptr fs:[0]
// 0042a5bd  50                   push eax
// 0042a5be  64892500000000       mov dword ptr fs:[0], esp
// 0042a5c5  83ec54               sub esp, 0x54
// 0042a5c8  56                   push esi
// 0042a5c9  8bf1                 mov esi, ecx
// 0042a5cb  56                   push esi
// 0042a5cc  8d4c2408             lea ecx, [esp + 8]
// 0042a5d0  e899845500           call 0x982a6e
// 0042a5d5  8b4654               mov eax, dword ptr [esi + 0x54]
// 0042a5d8  8b406c               mov eax, dword ptr [eax + 0x6c]
// 0042a5db  8d4e54               lea ecx, [esi + 0x54]
// 0042a5de  6a01                 push 1
// 0042a5e0  8d542408             lea edx, [esp + 8]
// 0042a5e4  52                   push edx
// 0042a5e5  c744246800000000     mov dword ptr [esp + 0x68], 0
// 0042a5ed  ffd0                 call eax
// 0042a5ef  8d4c2404             lea ecx, [esp + 4]
// 0042a5f3  c7442460ffffffff     mov dword ptr [esp + 0x60], 0xffffffff
// 0042a5fb  e868845500           call 0x982a68
// 0042a600  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0042a604  5e                   pop esi
// 0042a605  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a60c  83c460               add esp, 0x60
// 0042a60f  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000078@@QAEXXZ)

namespace ns_ROCX000078 {
struct S;

struct Context
{
    char storage[0x54];
    Context(S*);
    ~Context();
};

struct View;

struct ViewTable
{
    void* reserved[27];
    void (__thiscall *draw)(View*, Context*, int);
};

struct View
{
    ViewTable* table;
};

struct S
{
    char reserved[0x54];
    View view;

    void f();
};

void S::f()
{
    Context context(this);
    view.table->draw(&view, &context, 1);
}
}
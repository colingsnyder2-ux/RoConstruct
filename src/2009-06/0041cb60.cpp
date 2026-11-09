// from server: 100% by EspClaude
// roc 2009-06 0041cb60  unit: CXTTreeCtrl  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cb60
//
// 0041cb60  6aff                 push -1
// 0041cb62  68b8258500           push 0x8525b8
// 0041cb67  64a100000000         mov eax, dword ptr fs:[0]
// 0041cb6d  50                   push eax
// 0041cb6e  64892500000000       mov dword ptr fs:[0], esp
// 0041cb75  83ec54               sub esp, 0x54
// 0041cb78  56                   push esi
// 0041cb79  8bf1                 mov esi, ecx
// 0041cb7b  56                   push esi
// 0041cb7c  8d4c2408             lea ecx, [esp + 8]
// 0041cb80  e843c82f00           call 0x7193c8
// 0041cb85  8b4654               mov eax, dword ptr [esi + 0x54]
// 0041cb88  8b406c               mov eax, dword ptr [eax + 0x6c]
// 0041cb8b  8d4e54               lea ecx, [esi + 0x54]
// 0041cb8e  6a01                 push 1
// 0041cb90  8d542408             lea edx, [esp + 8]
// 0041cb94  52                   push edx
// 0041cb95  c744246800000000     mov dword ptr [esp + 0x68], 0
// 0041cb9d  ffd0                 call eax
// 0041cb9f  8d4c2404             lea ecx, [esp + 4]
// 0041cba3  c7442460ffffffff     mov dword ptr [esp + 0x60], 0xffffffff
// 0041cbab  e812c82f00           call 0x7193c2
// 0041cbb0  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0041cbb4  5e                   pop esi
// 0041cbb5  64890d00000000       mov dword ptr fs:[0], ecx
// 0041cbbc  83c460               add esp, 0x60
// 0041cbbf  c3                   ret 
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

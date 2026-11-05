// from server: 99% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00422a50  unit: CXTTreeCtrl  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00422a50
//
// 00422a50  6aff                 push -1
// 00422a52  68382f7c00           push 0x7c2f38
// 00422a57  64a100000000         mov eax, dword ptr fs:[0]
// 00422a5d  50                   push eax
// 00422a5e  64892500000000       mov dword ptr fs:[0], esp
// 00422a65  83ec54               sub esp, 0x54
// 00422a68  56                   push esi
// 00422a69  8bf1                 mov esi, ecx
// 00422a6b  56                   push esi
// 00422a6c  8d4c2408             lea ecx, [esp + 8]
// 00422a70  e8cfe42700           call 0x6a0f44
// 00422a75  8b4654               mov eax, dword ptr [esi + 0x54]
// 00422a78  8b406c               mov eax, dword ptr [eax + 0x6c]
// 00422a7b  8d4e54               lea ecx, [esi + 0x54]
// 00422a7e  6a01                 push 1
// 00422a80  8d542408             lea edx, [esp + 8]
// 00422a84  52                   push edx
// 00422a85  c744246800000000     mov dword ptr [esp + 0x68], 0
// 00422a8d  ffd0                 call eax
// 00422a8f  8d4c2404             lea ecx, [esp + 4]
// 00422a93  c7442460ffffffff     mov dword ptr [esp + 0x60], 0xffffffff
// 00422a9b  e89ee42700           call 0x6a0f3e
// 00422aa0  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00422aa4  5e                   pop esi
// 00422aa5  64890d00000000       mov dword ptr fs:[0], ecx
// 00422aac  83c460               add esp, 0x60
// 00422aaf  c3                   ret 

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

// from server: 83% by EspClaude
// roc-cl: 50727
// from server: 100% by tester
// roc 2008-06 004310f0  unit: CDataModelPropGrid  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004310f0
//
// 004310f0  6aff                 push -1
// 004310f2  6878fb7b00           push 0x7bfb78
// 004310f7  64a100000000         mov eax, dword ptr fs:[0]
// 004310fd  50                   push eax
// 004310fe  64892500000000       mov dword ptr fs:[0], esp
// 00431105  51                   push ecx
// 00431106  56                   push esi
// 00431107  8bf1                 mov esi, ecx
// 00431109  89742404             mov dword ptr [esp + 4], esi
// 0043110d  8d8e44020000         lea ecx, [esi + 0x244]
// 00431113  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0043111b  e8604cfdff           call 0x405d80
// 00431120  8bce                 mov ecx, esi
// 00431122  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0043112a  e8d1f5ffff           call 0x430700
// 0043112f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00431133  5e                   pop esi
// 00431134  64890d00000000       mov dword ptr fs:[0], ecx
// 0043113b  83c410               add esp, 0x10
// 0043113e  c3                   ret 

struct Base {
    char data[0x244];
    ~Base();
};

struct Member {
    ~Member();
};

struct ImageKeyButton : Base {
    Member member;
    ~ImageKeyButton();
};

ImageKeyButton::~ImageKeyButton()
{
}

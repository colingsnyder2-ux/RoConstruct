// from server: 100% by EspClaude
// from server: 53% by Intel
// roc 2007-08 0044a960  unit: CRobloxApp  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044a960
//
// 0044a960  6aff                 push -1
// 0044a962  6858ff7300           push 0x73ff58
// 0044a967  64a100000000         mov eax, dword ptr fs:[0]
// 0044a96d  50                   push eax
// 0044a96e  51                   push ecx
// 0044a96f  56                   push esi
// 0044a970  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044a975  33c4                 xor eax, esp
// 0044a977  50                   push eax
// 0044a978  8d44240c             lea eax, [esp + 0xc]
// 0044a97c  64a300000000         mov dword ptr fs:[0], eax
// 0044a982  8bf1                 mov esi, ecx
// 0044a984  89742408             mov dword ptr [esp + 8], esi
// 0044a988  8d4e28               lea ecx, [esi + 0x28]
// 0044a98b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044a993  e8c8f8fbff           call 0x40a260
// 0044a998  8bce                 mov ecx, esi
// 0044a99a  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0044a9a2  e8cd5e1e00           call 0x630874
// 0044a9a7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044a9ab  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a9b2  59                   pop ecx
// 0044a9b3  5e                   pop esi
// 0044a9b4  83c410               add esp, 0x10
// 0044a9b7  c3                   ret 

// Destructor shape: member at +0x28 destroyed under EH state 0 (call 0x40a260,
// thiscall on esi+0x28), then base-class destructor (call 0x630874, thiscall on this).
struct Base0630874 {
    char pad[0x28];
    ~Base0630874();
};
struct Member040a260 {
    ~Member040a260();
};
struct CRobloxApp : Base0630874 {
    Member040a260 m28;
    ~CRobloxApp();
};

CRobloxApp::~CRobloxApp() {
}

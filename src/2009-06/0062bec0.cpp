// from server: 90% by EspClaude
// from server: 100% by tester
// roc 2008-06 005a2730  unit: RBX::Workspace  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a2730
//
// 005a2730  56                   push esi
// 005a2731  8bf1                 mov esi, ecx
// 005a2733  8b8eb4030000         mov ecx, dword ptr [esi + 0x3b4]
// 005a2739  85c9                 test ecx, ecx
// 005a273b  7409                 je 0x5a2746
// 005a273d  8b01                 mov eax, dword ptr [ecx]
// 005a273f  8b5030               mov edx, dword ptr [eax + 0x30]
// 005a2742  6a01                 push 1
// 005a2744  ffd2                 call edx
// 005a2746  6a00                 push 0
// 005a2748  8bce                 mov ecx, esi
// 005a274a  c786b403000000000000 mov dword ptr [esi + 0x3b4], 0
// 005a2754  e867f8ffff           call 0x5a1fc0
// 005a2759  5e                   pop esi
// 005a275a  c3                   ret 

struct Workspace {
    char pad[0x3b4];
    void* field_31c;
    void func_57c3e0(int);
    void func_57ce80();
};

void Workspace::func_57ce80()
{
    void* p = field_31c;
    if (p) {
        void** vtable = *(void***)p;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vtable[0x30 / 4];
        fn(p, 1);
    }
    field_31c = 0;
    func_57c3e0(0);
}

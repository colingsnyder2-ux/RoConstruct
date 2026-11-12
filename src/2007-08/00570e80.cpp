// from server: 75% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 58% by colin
// roc 2007-08 00570e80  unit: RBX::Reflection::ClassDescriptor  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00570e80
//
// 00570e80  55                   push ebp
// 00570e81  8bec                 mov ebp, esp
// 00570e83  6aff                 push -1
// 00570e85  6840df8500           push 0x85df40
// 00570e8a  686a136300           push 0x63136a
// 00570e8f  64a100000000         mov eax, dword ptr fs:[0]
// 00570e95  50                   push eax
// 00570e96  64892500000000       mov dword ptr fs:[0], esp
// 00570e9d  83ec08               sub esp, 8
// 00570ea0  53                   push ebx
// 00570ea1  56                   push esi
// 00570ea2  57                   push edi
// 00570ea3  8965e8               mov dword ptr [ebp - 0x18], esp
// 00570ea6  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00570ead  eb07                 jmp 0x570eb6

struct RBX_Reflection_ClassDescriptor {
    void ClassDescriptor();
};

void RBX_Reflection_ClassDescriptor::ClassDescriptor()
{
    __try {
        int local = 0;
        (void)local;
    } __except (-1) {
    }
}

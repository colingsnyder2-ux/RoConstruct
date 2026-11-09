// from server: 100% by auto
// roc 2009-06 0043ea50  unit: RBX::MergeBinder  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043ea50
//
// 0043ea50  6aff                 push -1
// 0043ea52  6878ef8600           push 0x86ef78
// 0043ea57  64a100000000         mov eax, dword ptr fs:[0]
// 0043ea5d  50                   push eax
// 0043ea5e  64892500000000       mov dword ptr fs:[0], esp
// 0043ea65  51                   push ecx
// 0043ea66  56                   push esi
// 0043ea67  57                   push edi
// 0043ea68  8bf9                 mov edi, ecx
// 0043ea6a  6a04                 push 4
// 0043ea6c  c707705f8b00         mov dword ptr [edi], 0x8b5f70
// 0043ea72  8d7704               lea esi, [edi + 4]
// 0043ea75  e8be9f2d00           call 0x718a38
// 0043ea7a  33c9                 xor ecx, ecx
// 0043ea7c  83c404               add esp, 4
// 0043ea7f  3bc1                 cmp eax, ecx
// 0043ea81  7404                 je 0x43ea87
// 0043ea83  8930                 mov dword ptr [eax], esi
// 0043ea85  eb02                 jmp 0x43ea89
// 0043ea87  33c0                 xor eax, eax
// 0043ea89  8906                 mov dword ptr [esi], eax
// 0043ea8b  894e0c               mov dword ptr [esi + 0xc], ecx
// 0043ea8e  894e10               mov dword ptr [esi + 0x10], ecx
// 0043ea91  894e14               mov dword ptr [esi + 0x14], ecx
// 0043ea94  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043ea98  8bc7                 mov eax, edi
// 0043ea9a  5f                   pop edi
// 0043ea9b  5e                   pop esi
// 0043ea9c  64890d00000000       mov dword ptr fs:[0], ecx
// 0043eaa3  83c410               add esp, 0x10
// 0043eaa6  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp

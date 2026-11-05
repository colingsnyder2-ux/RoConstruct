// from server: 100% by auto
// roc 2008-06 00443e50  unit: RBX::MergeBinder  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00443e50
//
// 00443e50  6aff                 push -1
// 00443e52  68e8727d00           push 0x7d72e8
// 00443e57  64a100000000         mov eax, dword ptr fs:[0]
// 00443e5d  50                   push eax
// 00443e5e  64892500000000       mov dword ptr fs:[0], esp
// 00443e65  51                   push ecx
// 00443e66  56                   push esi
// 00443e67  57                   push edi
// 00443e68  8bf9                 mov edi, ecx
// 00443e6a  6a04                 push 4
// 00443e6c  c7073c598100         mov dword ptr [edi], 0x81593c
// 00443e72  8d7704               lea esi, [edi + 4]
// 00443e75  e8a6ca2500           call 0x6a0920
// 00443e7a  33c9                 xor ecx, ecx
// 00443e7c  83c404               add esp, 4
// 00443e7f  3bc1                 cmp eax, ecx
// 00443e81  7404                 je 0x443e87
// 00443e83  8930                 mov dword ptr [eax], esi
// 00443e85  eb02                 jmp 0x443e89
// 00443e87  33c0                 xor eax, eax
// 00443e89  8906                 mov dword ptr [esi], eax
// 00443e8b  894e0c               mov dword ptr [esi + 0xc], ecx
// 00443e8e  894e10               mov dword ptr [esi + 0x10], ecx
// 00443e91  894e14               mov dword ptr [esi + 0x14], ecx
// 00443e94  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00443e98  8bc7                 mov eax, edi
// 00443e9a  5f                   pop edi
// 00443e9b  5e                   pop esi
// 00443e9c  64890d00000000       mov dword ptr fs:[0], ecx
// 00443ea3  83c410               add esp, 0x10
// 00443ea6  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp

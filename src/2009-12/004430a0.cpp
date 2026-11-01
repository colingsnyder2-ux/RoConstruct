// from server: 100% by auto
// roc 2009-12 004430a0  unit: RBX::MergeBinder  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004430a0
//
// 004430a0  6aff                 push -1
// 004430a2  68d8c59300           push 0x93c5d8
// 004430a7  64a100000000         mov eax, dword ptr fs:[0]
// 004430ad  50                   push eax
// 004430ae  64892500000000       mov dword ptr fs:[0], esp
// 004430b5  51                   push ecx
// 004430b6  56                   push esi
// 004430b7  57                   push edi
// 004430b8  8bf9                 mov edi, ecx
// 004430ba  6a04                 push 4
// 004430bc  c7078c9f9a00         mov dword ptr [edi], 0x9a9f8c
// 004430c2  8d7704               lea esi, [edi + 4]
// 004430c5  e896073b00           call 0x7f3860
// 004430ca  33c9                 xor ecx, ecx
// 004430cc  83c404               add esp, 4
// 004430cf  3bc1                 cmp eax, ecx
// 004430d1  7404                 je 0x4430d7
// 004430d3  8930                 mov dword ptr [eax], esi
// 004430d5  eb02                 jmp 0x4430d9
// 004430d7  33c0                 xor eax, eax
// 004430d9  8906                 mov dword ptr [esi], eax
// 004430db  894e0c               mov dword ptr [esi + 0xc], ecx
// 004430de  894e10               mov dword ptr [esi + 0x10], ecx
// 004430e1  894e14               mov dword ptr [esi + 0x14], ecx
// 004430e4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004430e8  8bc7                 mov eax, edi
// 004430ea  5f                   pop edi
// 004430eb  5e                   pop esi
// 004430ec  64890d00000000       mov dword ptr fs:[0], ecx
// 004430f3  83c410               add esp, 0x10
// 004430f6  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp

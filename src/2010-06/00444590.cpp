// from server: 100% by auto
// roc 2010-06 00444590  unit: RBX::MergeBinder  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00444590
//
// 00444590  6aff                 push -1
// 00444592  6858a29900           push 0x99a258
// 00444597  64a100000000         mov eax, dword ptr fs:[0]
// 0044459d  50                   push eax
// 0044459e  64892500000000       mov dword ptr fs:[0], esp
// 004445a5  51                   push ecx
// 004445a6  56                   push esi
// 004445a7  57                   push edi
// 004445a8  8bf9                 mov edi, ecx
// 004445aa  6a04                 push 4
// 004445ac  c70734ada000         mov dword ptr [edi], 0xa0ad34
// 004445b2  8d7704               lea esi, [edi + 4]
// 004445b5  e8e6333600           call 0x7a79a0
// 004445ba  33c9                 xor ecx, ecx
// 004445bc  83c404               add esp, 4
// 004445bf  3bc1                 cmp eax, ecx
// 004445c1  7404                 je 0x4445c7
// 004445c3  8930                 mov dword ptr [eax], esi
// 004445c5  eb02                 jmp 0x4445c9
// 004445c7  33c0                 xor eax, eax
// 004445c9  8906                 mov dword ptr [esi], eax
// 004445cb  894e0c               mov dword ptr [esi + 0xc], ecx
// 004445ce  894e10               mov dword ptr [esi + 0x10], ecx
// 004445d1  894e14               mov dword ptr [esi + 0x14], ecx
// 004445d4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004445d8  8bc7                 mov eax, edi
// 004445da  5f                   pop edi
// 004445db  5e                   pop esi
// 004445dc  64890d00000000       mov dword ptr fs:[0], ecx
// 004445e3  83c410               add esp, 0x10
// 004445e6  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp

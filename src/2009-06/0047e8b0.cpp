// from server: 100% by auto
// roc 2009-06 0047e8b0  unit: rbx::signals::$$A6AXXZ::?$signal::slot  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047e8b0
//
// 0047e8b0  6aff                 push -1
// 0047e8b2  6878ef8600           push 0x86ef78
// 0047e8b7  64a100000000         mov eax, dword ptr fs:[0]
// 0047e8bd  50                   push eax
// 0047e8be  64892500000000       mov dword ptr fs:[0], esp
// 0047e8c5  51                   push ecx
// 0047e8c6  56                   push esi
// 0047e8c7  57                   push edi
// 0047e8c8  8bf9                 mov edi, ecx
// 0047e8ca  6a04                 push 4
// 0047e8cc  c70701000000         mov dword ptr [edi], 1
// 0047e8d2  8d7704               lea esi, [edi + 4]
// 0047e8d5  e85ea12900           call 0x718a38
// 0047e8da  33c9                 xor ecx, ecx
// 0047e8dc  83c404               add esp, 4
// 0047e8df  3bc1                 cmp eax, ecx
// 0047e8e1  7404                 je 0x47e8e7
// 0047e8e3  8930                 mov dword ptr [eax], esi
// 0047e8e5  eb02                 jmp 0x47e8e9
// 0047e8e7  33c0                 xor eax, eax
// 0047e8e9  8906                 mov dword ptr [esi], eax
// 0047e8eb  894e0c               mov dword ptr [esi + 0xc], ecx
// 0047e8ee  894e10               mov dword ptr [esi + 0x10], ecx
// 0047e8f1  894e14               mov dword ptr [esi + 0x14], ecx
// 0047e8f4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047e8f8  8bc7                 mov eax, edi
// 0047e8fa  5f                   pop edi
// 0047e8fb  5e                   pop esi
// 0047e8fc  64890d00000000       mov dword ptr fs:[0], ecx
// 0047e903  83c410               add esp, 0x10
// 0047e906  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp

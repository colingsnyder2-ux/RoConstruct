// from server: 100% by auto
// roc 2010-06 005321d0  unit: rbx::signals::Z::$$A6AXM::?$signal::slot  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005321d0
//
// 005321d0  6aff                 push -1
// 005321d2  6858a29900           push 0x99a258
// 005321d7  64a100000000         mov eax, dword ptr fs:[0]
// 005321dd  50                   push eax
// 005321de  64892500000000       mov dword ptr fs:[0], esp
// 005321e5  51                   push ecx
// 005321e6  56                   push esi
// 005321e7  57                   push edi
// 005321e8  8bf9                 mov edi, ecx
// 005321ea  6a04                 push 4
// 005321ec  c70701000000         mov dword ptr [edi], 1
// 005321f2  8d7704               lea esi, [edi + 4]
// 005321f5  e8a6572700           call 0x7a79a0
// 005321fa  33c9                 xor ecx, ecx
// 005321fc  83c404               add esp, 4
// 005321ff  3bc1                 cmp eax, ecx
// 00532201  7404                 je 0x532207
// 00532203  8930                 mov dword ptr [eax], esi
// 00532205  eb02                 jmp 0x532209
// 00532207  33c0                 xor eax, eax
// 00532209  8906                 mov dword ptr [esi], eax
// 0053220b  894e0c               mov dword ptr [esi + 0xc], ecx
// 0053220e  894e10               mov dword ptr [esi + 0x10], ecx
// 00532211  894e14               mov dword ptr [esi + 0x14], ecx
// 00532214  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00532218  8bc7                 mov eax, edi
// 0053221a  5f                   pop edi
// 0053221b  5e                   pop esi
// 0053221c  64890d00000000       mov dword ptr fs:[0], ecx
// 00532223  83c410               add esp, 0x10
// 00532226  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp

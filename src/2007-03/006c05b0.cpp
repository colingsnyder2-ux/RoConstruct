// from server: 100% by auto
// roc 2007-03 006c05b0  unit: seg_006c0000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c05b0
//
// 006c05b0  8b4124               mov eax, dword ptr [ecx + 0x24]
// 006c05b3  8b5120               mov edx, dword ptr [ecx + 0x20]
// 006c05b6  53                   push ebx
// 006c05b7  8b5918               mov ebx, dword ptr [ecx + 0x18]
// 006c05ba  56                   push esi
// 006c05bb  8b7110               mov esi, dword ptr [ecx + 0x10]
// 006c05be  57                   push edi
// 006c05bf  8b791c               mov edi, dword ptr [ecx + 0x1c]
// 006c05c2  2bc7                 sub eax, edi
// 006c05c4  2bd3                 sub edx, ebx
// 006c05c6  85f6                 test esi, esi
// 006c05c8  7403                 je 0x6c05cd
// 006c05ca  8b7604               mov esi, dword ptr [esi + 4]
// 006c05cd  682000cc00           push 0xcc0020
// 006c05d2  57                   push edi
// 006c05d3  53                   push ebx
// 006c05d4  56                   push esi
// 006c05d5  50                   push eax
// 006c05d6  8b4104               mov eax, dword ptr [ecx + 4]
// 006c05d9  52                   push edx
// 006c05da  6a00                 push 0
// 006c05dc  6a00                 push 0
// 006c05de  50                   push eax
// 006c05df  ff15e4d07700         call dword ptr [0x77d0e4]
// 006c05e5  5f                   pop edi
// 006c05e6  5e                   pop esi
// 006c05e7  5b                   pop ebx
// 006c05e8  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTMemDC.cpp (function ?FromDC@CXTMemDC@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTMemDC.cpp

// from server: 100% by auto
// roc 2009-12 008f3e00  unit: CXTMemDC  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f3e00
//
// 008f3e00  8b4124               mov eax, dword ptr [ecx + 0x24]
// 008f3e03  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008f3e06  53                   push ebx
// 008f3e07  8b5918               mov ebx, dword ptr [ecx + 0x18]
// 008f3e0a  56                   push esi
// 008f3e0b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 008f3e0e  57                   push edi
// 008f3e0f  8b791c               mov edi, dword ptr [ecx + 0x1c]
// 008f3e12  2bc7                 sub eax, edi
// 008f3e14  2bd3                 sub edx, ebx
// 008f3e16  85f6                 test esi, esi
// 008f3e18  7403                 je 0x8f3e1d
// 008f3e1a  8b7604               mov esi, dword ptr [esi + 4]
// 008f3e1d  682000cc00           push 0xcc0020
// 008f3e22  57                   push edi
// 008f3e23  53                   push ebx
// 008f3e24  56                   push esi
// 008f3e25  50                   push eax
// 008f3e26  8b4104               mov eax, dword ptr [ecx + 4]
// 008f3e29  52                   push edx
// 008f3e2a  6a00                 push 0
// 008f3e2c  6a00                 push 0
// 008f3e2e  50                   push eax
// 008f3e2f  ff1548b19800         call dword ptr [0x98b148]
// 008f3e35  5f                   pop edi
// 008f3e36  5e                   pop esi
// 008f3e37  5b                   pop ebx
// 008f3e38  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTMemDC.cpp (function ?FromDC@CXTMemDC@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTMemDC.cpp

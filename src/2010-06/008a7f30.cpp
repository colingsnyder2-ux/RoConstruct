// from server: 100% by auto
// roc 2010-06 008a7f30  unit: CXTMemDC  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a7f30
//
// 008a7f30  8b4124               mov eax, dword ptr [ecx + 0x24]
// 008a7f33  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008a7f36  53                   push ebx
// 008a7f37  8b5918               mov ebx, dword ptr [ecx + 0x18]
// 008a7f3a  56                   push esi
// 008a7f3b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 008a7f3e  57                   push edi
// 008a7f3f  8b791c               mov edi, dword ptr [ecx + 0x1c]
// 008a7f42  2bc7                 sub eax, edi
// 008a7f44  2bd3                 sub edx, ebx
// 008a7f46  85f6                 test esi, esi
// 008a7f48  7403                 je 0x8a7f4d
// 008a7f4a  8b7604               mov esi, dword ptr [esi + 4]
// 008a7f4d  682000cc00           push 0xcc0020
// 008a7f52  57                   push edi
// 008a7f53  53                   push ebx
// 008a7f54  56                   push esi
// 008a7f55  50                   push eax
// 008a7f56  8b4104               mov eax, dword ptr [ecx + 4]
// 008a7f59  52                   push edx
// 008a7f5a  6a00                 push 0
// 008a7f5c  6a00                 push 0
// 008a7f5e  50                   push eax
// 008a7f5f  ff15c0a09e00         call dword ptr [0x9ea0c0]
// 008a7f65  5f                   pop edi
// 008a7f66  5e                   pop esi
// 008a7f67  5b                   pop ebx
// 008a7f68  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTMemDC.cpp (function ?FromDC@CXTMemDC@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTMemDC.cpp

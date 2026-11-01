// from server: 100% by auto
// roc 2009-06 00819110  unit: CXTMemDC  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00819110
//
// 00819110  8b4124               mov eax, dword ptr [ecx + 0x24]
// 00819113  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00819116  53                   push ebx
// 00819117  8b5918               mov ebx, dword ptr [ecx + 0x18]
// 0081911a  56                   push esi
// 0081911b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0081911e  57                   push edi
// 0081911f  8b791c               mov edi, dword ptr [ecx + 0x1c]
// 00819122  2bc7                 sub eax, edi
// 00819124  2bd3                 sub edx, ebx
// 00819126  85f6                 test esi, esi
// 00819128  7403                 je 0x81912d
// 0081912a  8b7604               mov esi, dword ptr [esi + 4]
// 0081912d  682000cc00           push 0xcc0020
// 00819132  57                   push edi
// 00819133  53                   push ebx
// 00819134  56                   push esi
// 00819135  50                   push eax
// 00819136  8b4104               mov eax, dword ptr [ecx + 4]
// 00819139  52                   push edx
// 0081913a  6a00                 push 0
// 0081913c  6a00                 push 0
// 0081913e  50                   push eax
// 0081913f  ff15e0e08900         call dword ptr [0x89e0e0]
// 00819145  5f                   pop edi
// 00819146  5e                   pop esi
// 00819147  5b                   pop ebx
// 00819148  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTMemDC.cpp (function ?FromDC@CXTMemDC@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTMemDC.cpp

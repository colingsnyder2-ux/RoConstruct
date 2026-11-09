// from server: 100% by auto
// roc 2010-06 007e5990  unit: CXTTreeBase  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5990
//
// 007e5990  53                   push ebx
// 007e5991  56                   push esi
// 007e5992  8bf1                 mov esi, ecx
// 007e5994  57                   push edi
// 007e5995  8b7e04               mov edi, dword ptr [esi + 4]
// 007e5998  33db                 xor ebx, ebx
// 007e599a  3bfb                 cmp edi, ebx
// 007e599c  7421                 je 0x7e59bf
// 007e599e  395e08               cmp dword ptr [esi + 8], ebx
// 007e59a1  761c                 jbe 0x7e59bf
// 007e59a3  8b5608               mov edx, dword ptr [esi + 8]
// 007e59a6  8bcf                 mov ecx, edi
// 007e59a8  8b01                 mov eax, dword ptr [ecx]
// 007e59aa  3bc3                 cmp eax, ebx
// 007e59ac  7409                 je 0x7e59b7
// 007e59ae  8bff                 mov edi, edi
// 007e59b0  8b4048               mov eax, dword ptr [eax + 0x48]
// 007e59b3  3bc3                 cmp eax, ebx
// 007e59b5  75f9                 jne 0x7e59b0
// 007e59b7  83c104               add ecx, 4
// 007e59ba  83ea01               sub edx, 1
// 007e59bd  75e9                 jne 0x7e59a8
// 007e59bf  57                   push edi
// 007e59c0  e88122fcff           call 0x7a7c46
// 007e59c5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007e59c8  83c404               add esp, 4
// 007e59cb  895e04               mov dword ptr [esi + 4], ebx
// 007e59ce  895e0c               mov dword ptr [esi + 0xc], ebx
// 007e59d1  895e10               mov dword ptr [esi + 0x10], ebx
// 007e59d4  e82b2bfcff           call 0x7a8504
// 007e59d9  5f                   pop edi
// 007e59da  895e14               mov dword ptr [esi + 0x14], ebx
// 007e59dd  5e                   pop esi
// 007e59de  5b                   pop ebx
// 007e59df  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?RemoveAll@?$CMap@PAXPAXUCLRFONT@CXTTreeBase@@AAU12@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp

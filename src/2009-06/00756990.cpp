// from server: 100% by auto
// roc 2009-06 00756990  unit: CXTTreeBase  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756990
//
// 00756990  53                   push ebx
// 00756991  56                   push esi
// 00756992  8bf1                 mov esi, ecx
// 00756994  57                   push edi
// 00756995  8b7e04               mov edi, dword ptr [esi + 4]
// 00756998  33db                 xor ebx, ebx
// 0075699a  3bfb                 cmp edi, ebx
// 0075699c  7421                 je 0x7569bf
// 0075699e  395e08               cmp dword ptr [esi + 8], ebx
// 007569a1  761c                 jbe 0x7569bf
// 007569a3  8b5608               mov edx, dword ptr [esi + 8]
// 007569a6  8bcf                 mov ecx, edi
// 007569a8  8b01                 mov eax, dword ptr [ecx]
// 007569aa  3bc3                 cmp eax, ebx
// 007569ac  7409                 je 0x7569b7
// 007569ae  8bff                 mov edi, edi
// 007569b0  8b4048               mov eax, dword ptr [eax + 0x48]
// 007569b3  3bc3                 cmp eax, ebx
// 007569b5  75f9                 jne 0x7569b0
// 007569b7  83c104               add ecx, 4
// 007569ba  83ea01               sub edx, 1
// 007569bd  75e9                 jne 0x7569a8
// 007569bf  57                   push edi
// 007569c0  e81923fcff           call 0x718cde
// 007569c5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007569c8  83c404               add esp, 4
// 007569cb  895e04               mov dword ptr [esi + 4], ebx
// 007569ce  895e0c               mov dword ptr [esi + 0xc], ebx
// 007569d1  895e10               mov dword ptr [esi + 0x10], ebx
// 007569d4  e8bd2bfcff           call 0x719596
// 007569d9  5f                   pop edi
// 007569da  895e14               mov dword ptr [esi + 0x14], ebx
// 007569dd  5e                   pop esi
// 007569de  5b                   pop ebx
// 007569df  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?RemoveAll@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp

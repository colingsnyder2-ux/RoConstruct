// from server: 100% by auto
// roc 2009-12 0079a6f0  unit: lua_exception  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a6f0
//
// 0079a6f0  8b4804               mov ecx, dword ptr [eax + 4]
// 0079a6f3  83790806             cmp dword ptr [ecx + 8], 6
// 0079a6f7  7528                 jne 0x79a721
// 0079a6f9  56                   push esi
// 0079a6fa  8b31                 mov esi, dword ptr [ecx]
// 0079a6fc  807e0600             cmp byte ptr [esi + 6], 0
// 0079a700  5e                   pop esi
// 0079a701  751e                 jne 0x79a721
// 0079a703  3b4214               cmp eax, dword ptr [edx + 0x14]
// 0079a706  7506                 jne 0x79a70e
// 0079a708  8b5218               mov edx, dword ptr [edx + 0x18]
// 0079a70b  89500c               mov dword ptr [eax + 0xc], edx
// 0079a70e  8b09                 mov ecx, dword ptr [ecx]
// 0079a710  8b400c               mov eax, dword ptr [eax + 0xc]
// 0079a713  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0079a716  2b410c               sub eax, dword ptr [ecx + 0xc]
// 0079a719  c1f802               sar eax, 2
// 0079a71c  83e801               sub eax, 1
// 0079a71f  7904                 jns 0x79a725
// 0079a721  83c8ff               or eax, 0xffffffff
// 0079a724  c3                   ret 
// 0079a725  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 0079a728  85c9                 test ecx, ecx
// 0079a72a  7404                 je 0x79a730
// 0079a72c  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0079a72f  c3                   ret 
// 0079a730  33c0                 xor eax, eax
// 0079a732  c3                   ret 
// library lua-5.1/ldebug.c (function _currentline)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c

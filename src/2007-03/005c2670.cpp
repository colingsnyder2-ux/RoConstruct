// from server: 100% by auto
// roc 2007-03 005c2670  unit: seg_005c0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2670
//
// 005c2670  8b4804               mov ecx, dword ptr [eax + 4]
// 005c2673  83790806             cmp dword ptr [ecx + 8], 6
// 005c2677  7528                 jne 0x5c26a1
// 005c2679  56                   push esi
// 005c267a  8b31                 mov esi, dword ptr [ecx]
// 005c267c  807e0600             cmp byte ptr [esi + 6], 0
// 005c2680  5e                   pop esi
// 005c2681  751e                 jne 0x5c26a1
// 005c2683  3b4214               cmp eax, dword ptr [edx + 0x14]
// 005c2686  7506                 jne 0x5c268e
// 005c2688  8b5218               mov edx, dword ptr [edx + 0x18]
// 005c268b  89500c               mov dword ptr [eax + 0xc], edx
// 005c268e  8b09                 mov ecx, dword ptr [ecx]
// 005c2690  8b400c               mov eax, dword ptr [eax + 0xc]
// 005c2693  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 005c2696  2b410c               sub eax, dword ptr [ecx + 0xc]
// 005c2699  c1f802               sar eax, 2
// 005c269c  83e801               sub eax, 1
// 005c269f  7904                 jns 0x5c26a5
// 005c26a1  83c8ff               or eax, 0xffffffff
// 005c26a4  c3                   ret 
// 005c26a5  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005c26a8  85c9                 test ecx, ecx
// 005c26aa  7404                 je 0x5c26b0
// 005c26ac  8b0481               mov eax, dword ptr [ecx + eax*4]
// 005c26af  c3                   ret 
// 005c26b0  33c0                 xor eax, eax
// 005c26b2  c3                   ret 
// library lua-5.1.1/ldebug.c (function _currentline)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c

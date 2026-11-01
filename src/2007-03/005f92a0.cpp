// from server: 100% by auto
// roc 2007-03 005f92a0  unit: seg_005f0000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f92a0
//
// 005f92a0  56                   push esi
// 005f92a1  8b7310               mov esi, dword ptr [ebx + 0x10]
// 005f92a4  8b4e08               mov ecx, dword ptr [esi + 8]
// 005f92a7  8bc1                 mov eax, ecx
// 005f92a9  99                   cdq 
// 005f92aa  83e203               and edx, 3
// 005f92ad  03c2                 add eax, edx
// 005f92af  c1f802               sar eax, 2
// 005f92b2  394604               cmp dword ptr [esi + 4], eax
// 005f92b5  7316                 jae 0x5f92cd
// 005f92b7  83f940               cmp ecx, 0x40
// 005f92ba  7e11                 jle 0x5f92cd
// 005f92bc  8bc1                 mov eax, ecx
// 005f92be  99                   cdq 
// 005f92bf  2bc2                 sub eax, edx
// 005f92c1  d1f8                 sar eax, 1
// 005f92c3  50                   push eax
// 005f92c4  53                   push ebx
// 005f92c5  e8f6320000           call 0x5fc5c0
// 005f92ca  83c408               add esp, 8
// 005f92cd  8b463c               mov eax, dword ptr [esi + 0x3c]
// 005f92d0  83f840               cmp eax, 0x40
// 005f92d3  7635                 jbe 0x5f930a
// 005f92d5  57                   push edi
// 005f92d6  8bf8                 mov edi, eax
// 005f92d8  d1ef                 shr edi, 1
// 005f92da  8d4f01               lea ecx, [edi + 1]
// 005f92dd  83f9fd               cmp ecx, -3
// 005f92e0  7718                 ja 0x5f92fa
// 005f92e2  8b5634               mov edx, dword ptr [esi + 0x34]
// 005f92e5  57                   push edi
// 005f92e6  50                   push eax
// 005f92e7  52                   push edx
// 005f92e8  53                   push ebx
// 005f92e9  e8b2400000           call 0x5fd3a0
// 005f92ee  83c410               add esp, 0x10
// 005f92f1  897e3c               mov dword ptr [esi + 0x3c], edi
// 005f92f4  5f                   pop edi
// 005f92f5  894634               mov dword ptr [esi + 0x34], eax
// 005f92f8  5e                   pop esi
// 005f92f9  c3                   ret 
// 005f92fa  53                   push ebx
// 005f92fb  e880400000           call 0x5fd380
// 005f9300  83c404               add esp, 4
// 005f9303  897e3c               mov dword ptr [esi + 0x3c], edi
// 005f9306  894634               mov dword ptr [esi + 0x34], eax
// 005f9309  5f                   pop edi
// 005f930a  5e                   pop esi
// 005f930b  c3                   ret 
// library lua-5.1.1/lgc.c (function _checkSizes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c

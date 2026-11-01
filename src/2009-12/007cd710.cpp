// from server: 100% by auto
// roc 2009-12 007cd710  unit: RBX::PartDropTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd710
//
// 007cd710  56                   push esi
// 007cd711  8b7310               mov esi, dword ptr [ebx + 0x10]
// 007cd714  8b4e08               mov ecx, dword ptr [esi + 8]
// 007cd717  8bc1                 mov eax, ecx
// 007cd719  99                   cdq 
// 007cd71a  83e203               and edx, 3
// 007cd71d  03c2                 add eax, edx
// 007cd71f  c1f802               sar eax, 2
// 007cd722  394604               cmp dword ptr [esi + 4], eax
// 007cd725  7316                 jae 0x7cd73d
// 007cd727  83f940               cmp ecx, 0x40
// 007cd72a  7e11                 jle 0x7cd73d
// 007cd72c  8bc1                 mov eax, ecx
// 007cd72e  99                   cdq 
// 007cd72f  2bc2                 sub eax, edx
// 007cd731  d1f8                 sar eax, 1
// 007cd733  50                   push eax
// 007cd734  53                   push ebx
// 007cd735  e8f6320000           call 0x7d0a30
// 007cd73a  83c408               add esp, 8
// 007cd73d  8b463c               mov eax, dword ptr [esi + 0x3c]
// 007cd740  83f840               cmp eax, 0x40
// 007cd743  7635                 jbe 0x7cd77a
// 007cd745  57                   push edi
// 007cd746  8bf8                 mov edi, eax
// 007cd748  d1ef                 shr edi, 1
// 007cd74a  8d4f01               lea ecx, [edi + 1]
// 007cd74d  83f9fd               cmp ecx, -3
// 007cd750  7718                 ja 0x7cd76a
// 007cd752  8b5634               mov edx, dword ptr [esi + 0x34]
// 007cd755  57                   push edi
// 007cd756  50                   push eax
// 007cd757  52                   push edx
// 007cd758  53                   push ebx
// 007cd759  e852400000           call 0x7d17b0
// 007cd75e  83c410               add esp, 0x10
// 007cd761  897e3c               mov dword ptr [esi + 0x3c], edi
// 007cd764  5f                   pop edi
// 007cd765  894634               mov dword ptr [esi + 0x34], eax
// 007cd768  5e                   pop esi
// 007cd769  c3                   ret 
// 007cd76a  53                   push ebx
// 007cd76b  e820400000           call 0x7d1790
// 007cd770  83c404               add esp, 4
// 007cd773  897e3c               mov dword ptr [esi + 0x3c], edi
// 007cd776  894634               mov dword ptr [esi + 0x34], eax
// 007cd779  5f                   pop edi
// 007cd77a  5e                   pop esi
// 007cd77b  c3                   ret 
// library lua-5.1/lgc.c (function _checkSizes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c

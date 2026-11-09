// from server: 100% by auto
// roc 2009-12 00488710  unit: Ogre::GfxClustererPart  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00488710
//
// 00488710  6aff                 push -1
// 00488712  68d8c59300           push 0x93c5d8
// 00488717  64a100000000         mov eax, dword ptr fs:[0]
// 0048871d  50                   push eax
// 0048871e  64892500000000       mov dword ptr fs:[0], esp
// 00488725  51                   push ecx
// 00488726  56                   push esi
// 00488727  57                   push edi
// 00488728  8bf9                 mov edi, ecx
// 0048872a  6a04                 push 4
// 0048872c  c70701000000         mov dword ptr [edi], 1
// 00488732  8d7704               lea esi, [edi + 4]
// 00488735  e826b13600           call 0x7f3860
// 0048873a  33c9                 xor ecx, ecx
// 0048873c  83c404               add esp, 4
// 0048873f  3bc1                 cmp eax, ecx
// 00488741  7404                 je 0x488747
// 00488743  8930                 mov dword ptr [eax], esi
// 00488745  eb02                 jmp 0x488749
// 00488747  33c0                 xor eax, eax
// 00488749  8906                 mov dword ptr [esi], eax
// 0048874b  894e0c               mov dword ptr [esi + 0xc], ecx
// 0048874e  894e10               mov dword ptr [esi + 0x10], ecx
// 00488751  894e14               mov dword ptr [esi + 0x14], ecx
// 00488754  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00488758  8bc7                 mov eax, edi
// 0048875a  5f                   pop edi
// 0048875b  5e                   pop esi
// 0048875c  64890d00000000       mov dword ptr fs:[0], ecx
// 00488763  83c410               add esp, 0x10
// 00488766  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp

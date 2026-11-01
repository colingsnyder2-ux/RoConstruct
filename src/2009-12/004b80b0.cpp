// from server: 100% by auto
// roc 2009-12 004b80b0  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b80b0
//
// 004b80b0  55                   push ebp
// 004b80b1  8bec                 mov ebp, esp
// 004b80b3  6aff                 push -1
// 004b80b5  68911c9300           push 0x931c91
// 004b80ba  64a100000000         mov eax, dword ptr fs:[0]
// 004b80c0  50                   push eax
// 004b80c1  64892500000000       mov dword ptr fs:[0], esp
// 004b80c8  83ec0c               sub esp, 0xc
// 004b80cb  53                   push ebx
// 004b80cc  56                   push esi
// 004b80cd  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004b80d0  57                   push edi
// 004b80d1  8b7d08               mov edi, dword ptr [ebp + 8]
// 004b80d4  33db                 xor ebx, ebx
// 004b80d6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004b80d9  8975ec               mov dword ptr [ebp - 0x14], esi
// 004b80dc  895dfc               mov dword ptr [ebp - 4], ebx
// 004b80df  90                   nop 
// 004b80e0  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 004b80e3  7445                 je 0x4b812a
// 004b80e5  897508               mov dword ptr [ebp + 8], esi
// 004b80e8  8975e8               mov dword ptr [ebp - 0x18], esi
// 004b80eb  c645fc01             mov byte ptr [ebp - 4], 1
// 004b80ef  3bf3                 cmp esi, ebx
// 004b80f1  7408                 je 0x4b80fb
// 004b80f3  57                   push edi
// 004b80f4  8bce                 mov ecx, esi
// 004b80f6  e8c5f8ffff           call 0x4b79c0
// 004b80fb  83c660               add esi, 0x60
// 004b80fe  885dfc               mov byte ptr [ebp - 4], bl
// 004b8101  897510               mov dword ptr [ebp + 0x10], esi
// 004b8104  83c760               add edi, 0x60
// 004b8107  ebd7                 jmp 0x4b80e0
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??$_Uninit_copy@PBUFileInfo@Ogre@@PAU12@V?$allocator@UFileInfo@Ogre@@@std@@@std@@YAPAUFileInfo@Ogre@@PBU12@0PAU12@AAV?$allocator@UFileInfo@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp

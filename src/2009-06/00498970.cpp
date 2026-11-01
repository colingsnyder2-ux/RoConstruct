// from server: 100% by auto
// roc 2009-06 00498970  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498970
//
// 00498970  55                   push ebp
// 00498971  8bec                 mov ebp, esp
// 00498973  6aff                 push -1
// 00498975  68f1688500           push 0x8568f1
// 0049897a  64a100000000         mov eax, dword ptr fs:[0]
// 00498980  50                   push eax
// 00498981  64892500000000       mov dword ptr fs:[0], esp
// 00498988  83ec0c               sub esp, 0xc
// 0049898b  53                   push ebx
// 0049898c  56                   push esi
// 0049898d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00498990  57                   push edi
// 00498991  8b7d08               mov edi, dword ptr [ebp + 8]
// 00498994  33db                 xor ebx, ebx
// 00498996  8965f0               mov dword ptr [ebp - 0x10], esp
// 00498999  8975ec               mov dword ptr [ebp - 0x14], esi
// 0049899c  895dfc               mov dword ptr [ebp - 4], ebx
// 0049899f  90                   nop 
// 004989a0  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 004989a3  7445                 je 0x4989ea
// 004989a5  897508               mov dword ptr [ebp + 8], esi
// 004989a8  8975e8               mov dword ptr [ebp - 0x18], esi
// 004989ab  c645fc01             mov byte ptr [ebp - 4], 1
// 004989af  3bf3                 cmp esi, ebx
// 004989b1  7408                 je 0x4989bb
// 004989b3  57                   push edi
// 004989b4  8bce                 mov ecx, esi
// 004989b6  e8b5f8ffff           call 0x498270
// 004989bb  83c660               add esi, 0x60
// 004989be  885dfc               mov byte ptr [ebp - 4], bl
// 004989c1  897510               mov dword ptr [ebp + 0x10], esi
// 004989c4  83c760               add edi, 0x60
// 004989c7  ebd7                 jmp 0x4989a0
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??$_Uninit_copy@PBUFileInfo@Ogre@@PAU12@V?$allocator@UFileInfo@Ogre@@@std@@@std@@YAPAUFileInfo@Ogre@@PBU12@0PAU12@AAV?$allocator@UFileInfo@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp

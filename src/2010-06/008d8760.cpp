// from server: 100% by auto
// roc 2010-06 008d8760  unit: Ogre::RbxTextureCompositorSceneManager  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d8760
//
// 008d8760  55                   push ebp
// 008d8761  8bec                 mov ebp, esp
// 008d8763  6aff                 push -1
// 008d8765  68b1e89b00           push 0x9be8b1
// 008d876a  64a100000000         mov eax, dword ptr fs:[0]
// 008d8770  50                   push eax
// 008d8771  64892500000000       mov dword ptr fs:[0], esp
// 008d8778  83ec0c               sub esp, 0xc
// 008d877b  53                   push ebx
// 008d877c  56                   push esi
// 008d877d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 008d8780  57                   push edi
// 008d8781  8b7d08               mov edi, dword ptr [ebp + 8]
// 008d8784  33db                 xor ebx, ebx
// 008d8786  8965f0               mov dword ptr [ebp - 0x10], esp
// 008d8789  8975ec               mov dword ptr [ebp - 0x14], esi
// 008d878c  895dfc               mov dword ptr [ebp - 4], ebx
// 008d878f  90                   nop 
// 008d8790  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 008d8793  7445                 je 0x8d87da
// 008d8795  897508               mov dword ptr [ebp + 8], esi
// 008d8798  8975e8               mov dword ptr [ebp - 0x18], esi
// 008d879b  c645fc01             mov byte ptr [ebp - 4], 1
// 008d879f  3bf3                 cmp esi, ebx
// 008d87a1  7408                 je 0x8d87ab
// 008d87a3  57                   push edi
// 008d87a4  8bce                 mov ecx, esi
// 008d87a6  e865e9ffff           call 0x8d7110
// 008d87ab  83c648               add esi, 0x48
// 008d87ae  885dfc               mov byte ptr [ebp - 4], bl
// 008d87b1  897510               mov dword ptr [ebp + 0x10], esi
// 008d87b4  83c748               add edi, 0x48
// 008d87b7  ebd7                 jmp 0x8d8790
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??$_Uninit_copy@PAUPMWorkingData@ProgressiveMesh@Ogre@@PAU123@V?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@std@@@std@@YAPAUPMWorkingData@ProgressiveMesh@Ogre@@PAU123@00AAV?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp

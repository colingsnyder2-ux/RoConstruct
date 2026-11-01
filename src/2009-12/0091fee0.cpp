// from server: 100% by auto
// roc 2009-12 0091fee0  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0091fee0
//
// 0091fee0  55                   push ebp
// 0091fee1  8bec                 mov ebp, esp
// 0091fee3  83ec08               sub esp, 8
// 0091fee6  894df8               mov dword ptr [ebp - 8], ecx
// 0091fee9  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0091feec  e8df0e0000           call 0x920dd0
// 0091fef1  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0091fef4  894118               mov dword ptr [ecx + 0x18], eax
// 0091fef7  8b55f8               mov edx, dword ptr [ebp - 8]
// 0091fefa  8b4218               mov eax, dword ptr [edx + 0x18]
// 0091fefd  c6401501             mov byte ptr [eax + 0x15], 1
// 0091ff01  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0091ff04  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0091ff07  8b45f8               mov eax, dword ptr [ebp - 8]
// 0091ff0a  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0091ff0d  894a04               mov dword ptr [edx + 4], ecx
// 0091ff10  8b55f8               mov edx, dword ptr [ebp - 8]
// 0091ff13  8b4218               mov eax, dword ptr [edx + 0x18]
// 0091ff16  8945fc               mov dword ptr [ebp - 4], eax
// 0091ff19  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0091ff1c  8b55f8               mov edx, dword ptr [ebp - 8]
// 0091ff1f  8b4218               mov eax, dword ptr [edx + 0x18]
// 0091ff22  8901                 mov dword ptr [ecx], eax
// 0091ff24  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0091ff27  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0091ff2a  8b45f8               mov eax, dword ptr [ebp - 8]
// 0091ff2d  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0091ff30  894a08               mov dword ptr [edx + 8], ecx
// 0091ff33  8b55f8               mov edx, dword ptr [ebp - 8]
// 0091ff36  c7421c00000000       mov dword ptr [edx + 0x1c], 0
// 0091ff3d  8be5                 mov esp, ebp
// 0091ff3f  5d                   pop ebp
// 0091ff40  c3                   ret 
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?_Init@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp

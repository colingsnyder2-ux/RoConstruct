// from server: 100% by auto
// roc 2009-12 00920370  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00920370
//
// 00920370  55                   push ebp
// 00920371  8bec                 mov ebp, esp
// 00920373  83ec24               sub esp, 0x24
// 00920376  894ddc               mov dword ptr [ebp - 0x24], ecx
// 00920379  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0092037c  83780c00             cmp dword ptr [eax + 0xc], 0
// 00920380  7466                 je 0x9203e8
// 00920382  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 00920385  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00920388  8955e8               mov dword ptr [ebp - 0x18], edx
// 0092038b  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0092038e  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00920391  894dec               mov dword ptr [ebp - 0x14], ecx
// 00920394  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 00920397  8955f0               mov dword ptr [ebp - 0x10], edx
// 0092039a  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0092039d  8945f4               mov dword ptr [ebp - 0xc], eax
// 009203a0  8a4dfe               mov cl, byte ptr [ebp - 2]
// 009203a3  884dff               mov byte ptr [ebp - 1], cl
// 009203a6  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 009203a9  8955f8               mov dword ptr [ebp - 8], edx
// 009203ac  eb09                 jmp 0x9203b7
// 009203ae  8b45f8               mov eax, dword ptr [ebp - 8]
// 009203b1  83c008               add eax, 8
// 009203b4  8945f8               mov dword ptr [ebp - 8], eax
// 009203b7  8b4df8               mov ecx, dword ptr [ebp - 8]
// 009203ba  3b4df0               cmp ecx, dword ptr [ebp - 0x10]
// 009203bd  7402                 je 0x9203c1
// 009203bf  ebed                 jmp 0x9203ae
// 009203c1  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 009203c4  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 009203c7  8b4a14               mov ecx, dword ptr [edx + 0x14]
// 009203ca  2b480c               sub ecx, dword ptr [eax + 0xc]
// 009203cd  c1f903               sar ecx, 3
// 009203d0  894de0               mov dword ptr [ebp - 0x20], ecx
// 009203d3  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 009203d6  8b420c               mov eax, dword ptr [edx + 0xc]
// 009203d9  8945e4               mov dword ptr [ebp - 0x1c], eax
// 009203dc  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 009203df  51                   push ecx
// 009203e0  e87534edff           call 0x7f385a
// 009203e5  83c404               add esp, 4
// 009203e8  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 009203eb  c7420c00000000       mov dword ptr [edx + 0xc], 0
// 009203f2  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 009203f5  c7401000000000       mov dword ptr [eax + 0x10], 0
// 009203fc  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 009203ff  c7411400000000       mov dword ptr [ecx + 0x14], 0
// 00920406  8be5                 mov esp, ebp
// 00920408  5d                   pop ebp
// 00920409  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ?_Tidy@?$vector@V?$Vector2@M@Wml@@V?$allocator@V?$Vector2@M@Wml@@@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp

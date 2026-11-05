// from server: 100% by auto
// roc 2009-12 00920bb0  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00920bb0
//
// 00920bb0  55                   push ebp
// 00920bb1  8bec                 mov ebp, esp
// 00920bb3  6aff                 push -1
// 00920bb5  68007b9600           push 0x967b00
// 00920bba  64a100000000         mov eax, dword ptr fs:[0]
// 00920bc0  50                   push eax
// 00920bc1  64892500000000       mov dword ptr fs:[0], esp
// 00920bc8  51                   push ecx
// 00920bc9  83ec50               sub esp, 0x50
// 00920bcc  53                   push ebx
// 00920bcd  56                   push esi
// 00920bce  57                   push edi
// 00920bcf  8965f0               mov dword ptr [ebp - 0x10], esp
// 00920bd2  894dac               mov dword ptr [ebp - 0x54], ecx
// 00920bd5  6a01                 push 1
// 00920bd7  8b4dac               mov ecx, dword ptr [ebp - 0x54]
// 00920bda  83c10c               add ecx, 0xc
// 00920bdd  e85e070000           call 0x921340
// 00920be2  8945e8               mov dword ptr [ebp - 0x18], eax
// 00920be5  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00920bec  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00920bf3  c745e400000000       mov dword ptr [ebp - 0x1c], 0
// 00920bfa  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00920bfd  8945c4               mov dword ptr [ebp - 0x3c], eax
// 00920c00  8b4dc4               mov ecx, dword ptr [ebp - 0x3c]
// 00920c03  894dc0               mov dword ptr [ebp - 0x40], ecx
// 00920c06  837dc000             cmp dword ptr [ebp - 0x40], 0
// 00920c0a  7410                 je 0x920c1c
// 00920c0c  8b55c0               mov edx, dword ptr [ebp - 0x40]
// 00920c0f  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 00920c12  8902                 mov dword ptr [edx], eax
// 00920c14  8b4dc0               mov ecx, dword ptr [ebp - 0x40]
// 00920c17  894da8               mov dword ptr [ebp - 0x58], ecx
// 00920c1a  eb07                 jmp 0x920c23
// 00920c1c  c745a800000000       mov dword ptr [ebp - 0x58], 0
// 00920c23  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00920c26  83c201               add edx, 1
// 00920c29  8955ec               mov dword ptr [ebp - 0x14], edx
// 00920c2c  c745e000000000       mov dword ptr [ebp - 0x20], 0
// 00920c33  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00920c36  83c004               add eax, 4
// 00920c39  8945bc               mov dword ptr [ebp - 0x44], eax
// 00920c3c  8b4dbc               mov ecx, dword ptr [ebp - 0x44]
// 00920c3f  894db8               mov dword ptr [ebp - 0x48], ecx
// 00920c42  837db800             cmp dword ptr [ebp - 0x48], 0
// 00920c46  7410                 je 0x920c58
// 00920c48  8b55b8               mov edx, dword ptr [ebp - 0x48]
// 00920c4b  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 00920c4e  8902                 mov dword ptr [edx], eax
// 00920c50  8b4db8               mov ecx, dword ptr [ebp - 0x48]
// 00920c53  894da4               mov dword ptr [ebp - 0x5c], ecx
// 00920c56  eb07                 jmp 0x920c5f
// 00920c58  c745a400000000       mov dword ptr [ebp - 0x5c], 0
// 00920c5f  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00920c62  83c201               add edx, 1
// 00920c65  8955ec               mov dword ptr [ebp - 0x14], edx
// 00920c68  c745dc00000000       mov dword ptr [ebp - 0x24], 0
// 00920c6f  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00920c72  83c008               add eax, 8
// 00920c75  8945b4               mov dword ptr [ebp - 0x4c], eax
// 00920c78  8b4db4               mov ecx, dword ptr [ebp - 0x4c]
// 00920c7b  894db0               mov dword ptr [ebp - 0x50], ecx
// 00920c7e  837db000             cmp dword ptr [ebp - 0x50], 0
// 00920c82  7410                 je 0x920c94
// 00920c84  8b55b0               mov edx, dword ptr [ebp - 0x50]
// 00920c87  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 00920c8a  8902                 mov dword ptr [edx], eax
// 00920c8c  8b4db0               mov ecx, dword ptr [ebp - 0x50]
// 00920c8f  894da0               mov dword ptr [ebp - 0x60], ecx
// 00920c92  eb07                 jmp 0x920c9b
// 00920c94  c745a000000000       mov dword ptr [ebp - 0x60], 0
// 00920c9b  eb22                 jmp 0x920cbf
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?_Buynode@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp

// from server: 100% by auto
// roc 2009-12 004ec850  unit: seg_004e0000  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ec850
//
// 004ec850  55                   push ebp
// 004ec851  8bec                 mov ebp, esp
// 004ec853  6aff                 push -1
// 004ec855  68204f9300           push 0x934f20
// 004ec85a  64a100000000         mov eax, dword ptr fs:[0]
// 004ec860  50                   push eax
// 004ec861  64892500000000       mov dword ptr fs:[0], esp
// 004ec868  51                   push ecx
// 004ec869  83ec50               sub esp, 0x50
// 004ec86c  53                   push ebx
// 004ec86d  56                   push esi
// 004ec86e  57                   push edi
// 004ec86f  8965f0               mov dword ptr [ebp - 0x10], esp
// 004ec872  894dac               mov dword ptr [ebp - 0x54], ecx
// 004ec875  6a01                 push 1
// 004ec877  8b4dac               mov ecx, dword ptr [ebp - 0x54]
// 004ec87a  83c10c               add ecx, 0xc
// 004ec87d  e8ee020000           call 0x4ecb70
// 004ec882  8945e8               mov dword ptr [ebp - 0x18], eax
// 004ec885  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 004ec88c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004ec893  c745e400000000       mov dword ptr [ebp - 0x1c], 0
// 004ec89a  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004ec89d  8945c4               mov dword ptr [ebp - 0x3c], eax
// 004ec8a0  8b4dc4               mov ecx, dword ptr [ebp - 0x3c]
// 004ec8a3  894dc0               mov dword ptr [ebp - 0x40], ecx
// 004ec8a6  837dc000             cmp dword ptr [ebp - 0x40], 0
// 004ec8aa  7410                 je 0x4ec8bc
// 004ec8ac  8b55c0               mov edx, dword ptr [ebp - 0x40]
// 004ec8af  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 004ec8b2  8902                 mov dword ptr [edx], eax
// 004ec8b4  8b4dc0               mov ecx, dword ptr [ebp - 0x40]
// 004ec8b7  894da8               mov dword ptr [ebp - 0x58], ecx
// 004ec8ba  eb07                 jmp 0x4ec8c3
// 004ec8bc  c745a800000000       mov dword ptr [ebp - 0x58], 0
// 004ec8c3  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004ec8c6  83c201               add edx, 1
// 004ec8c9  8955ec               mov dword ptr [ebp - 0x14], edx
// 004ec8cc  c745e000000000       mov dword ptr [ebp - 0x20], 0
// 004ec8d3  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004ec8d6  83c004               add eax, 4
// 004ec8d9  8945bc               mov dword ptr [ebp - 0x44], eax
// 004ec8dc  8b4dbc               mov ecx, dword ptr [ebp - 0x44]
// 004ec8df  894db8               mov dword ptr [ebp - 0x48], ecx
// 004ec8e2  837db800             cmp dword ptr [ebp - 0x48], 0
// 004ec8e6  7410                 je 0x4ec8f8
// 004ec8e8  8b55b8               mov edx, dword ptr [ebp - 0x48]
// 004ec8eb  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 004ec8ee  8902                 mov dword ptr [edx], eax
// 004ec8f0  8b4db8               mov ecx, dword ptr [ebp - 0x48]
// 004ec8f3  894da4               mov dword ptr [ebp - 0x5c], ecx
// 004ec8f6  eb07                 jmp 0x4ec8ff
// 004ec8f8  c745a400000000       mov dword ptr [ebp - 0x5c], 0
// 004ec8ff  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004ec902  83c201               add edx, 1
// 004ec905  8955ec               mov dword ptr [ebp - 0x14], edx
// 004ec908  c745dc00000000       mov dword ptr [ebp - 0x24], 0
// 004ec90f  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004ec912  83c008               add eax, 8
// 004ec915  8945b4               mov dword ptr [ebp - 0x4c], eax
// 004ec918  8b4db4               mov ecx, dword ptr [ebp - 0x4c]
// 004ec91b  894db0               mov dword ptr [ebp - 0x50], ecx
// 004ec91e  837db000             cmp dword ptr [ebp - 0x50], 0
// 004ec922  7410                 je 0x4ec934
// 004ec924  8b55b0               mov edx, dword ptr [ebp - 0x50]
// 004ec927  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 004ec92a  8902                 mov dword ptr [edx], eax
// 004ec92c  8b4db0               mov ecx, dword ptr [ebp - 0x50]
// 004ec92f  894da0               mov dword ptr [ebp - 0x60], ecx
// 004ec932  eb07                 jmp 0x4ec93b
// 004ec934  c745a000000000       mov dword ptr [ebp - 0x60], 0
// 004ec93b  eb22                 jmp 0x4ec95f
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?_Buynode@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp

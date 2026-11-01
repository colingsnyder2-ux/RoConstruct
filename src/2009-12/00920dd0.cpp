// from server: 100% by auto
// roc 2009-12 00920dd0  unit: seg_00920000  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00920dd0
//
// 00920dd0  55                   push ebp
// 00920dd1  8bec                 mov ebp, esp
// 00920dd3  6aff                 push -1
// 00920dd5  68307b9600           push 0x967b30
// 00920dda  64a100000000         mov eax, dword ptr fs:[0]
// 00920de0  50                   push eax
// 00920de1  64892500000000       mov dword ptr fs:[0], esp
// 00920de8  51                   push ecx
// 00920de9  83ec50               sub esp, 0x50
// 00920dec  53                   push ebx
// 00920ded  56                   push esi
// 00920dee  57                   push edi
// 00920def  8965f0               mov dword ptr [ebp - 0x10], esp
// 00920df2  894dac               mov dword ptr [ebp - 0x54], ecx
// 00920df5  6a01                 push 1
// 00920df7  8b4dac               mov ecx, dword ptr [ebp - 0x54]
// 00920dfa  83c10c               add ecx, 0xc
// 00920dfd  e8ee78bcff           call 0x4e86f0
// 00920e02  8945e8               mov dword ptr [ebp - 0x18], eax
// 00920e05  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00920e0c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00920e13  c745e400000000       mov dword ptr [ebp - 0x1c], 0
// 00920e1a  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00920e1d  8945c4               mov dword ptr [ebp - 0x3c], eax
// 00920e20  8b4dc4               mov ecx, dword ptr [ebp - 0x3c]
// 00920e23  894dc0               mov dword ptr [ebp - 0x40], ecx
// 00920e26  837dc000             cmp dword ptr [ebp - 0x40], 0
// 00920e2a  7410                 je 0x920e3c
// 00920e2c  8b55c0               mov edx, dword ptr [ebp - 0x40]
// 00920e2f  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 00920e32  8902                 mov dword ptr [edx], eax
// 00920e34  8b4dc0               mov ecx, dword ptr [ebp - 0x40]
// 00920e37  894da8               mov dword ptr [ebp - 0x58], ecx
// 00920e3a  eb07                 jmp 0x920e43
// 00920e3c  c745a800000000       mov dword ptr [ebp - 0x58], 0
// 00920e43  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00920e46  83c201               add edx, 1
// 00920e49  8955ec               mov dword ptr [ebp - 0x14], edx
// 00920e4c  c745e000000000       mov dword ptr [ebp - 0x20], 0
// 00920e53  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00920e56  83c004               add eax, 4
// 00920e59  8945bc               mov dword ptr [ebp - 0x44], eax
// 00920e5c  8b4dbc               mov ecx, dword ptr [ebp - 0x44]
// 00920e5f  894db8               mov dword ptr [ebp - 0x48], ecx
// 00920e62  837db800             cmp dword ptr [ebp - 0x48], 0
// 00920e66  7410                 je 0x920e78
// 00920e68  8b55b8               mov edx, dword ptr [ebp - 0x48]
// 00920e6b  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 00920e6e  8902                 mov dword ptr [edx], eax
// 00920e70  8b4db8               mov ecx, dword ptr [ebp - 0x48]
// 00920e73  894da4               mov dword ptr [ebp - 0x5c], ecx
// 00920e76  eb07                 jmp 0x920e7f
// 00920e78  c745a400000000       mov dword ptr [ebp - 0x5c], 0
// 00920e7f  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00920e82  83c201               add edx, 1
// 00920e85  8955ec               mov dword ptr [ebp - 0x14], edx
// 00920e88  c745dc00000000       mov dword ptr [ebp - 0x24], 0
// 00920e8f  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00920e92  83c008               add eax, 8
// 00920e95  8945b4               mov dword ptr [ebp - 0x4c], eax
// 00920e98  8b4db4               mov ecx, dword ptr [ebp - 0x4c]
// 00920e9b  894db0               mov dword ptr [ebp - 0x50], ecx
// 00920e9e  837db000             cmp dword ptr [ebp - 0x50], 0
// 00920ea2  7410                 je 0x920eb4
// 00920ea4  8b55b0               mov edx, dword ptr [ebp - 0x50]
// 00920ea7  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 00920eaa  8902                 mov dword ptr [edx], eax
// 00920eac  8b4db0               mov ecx, dword ptr [ebp - 0x50]
// 00920eaf  894da0               mov dword ptr [ebp - 0x60], ecx
// 00920eb2  eb07                 jmp 0x920ebb
// 00920eb4  c745a000000000       mov dword ptr [ebp - 0x60], 0
// 00920ebb  eb22                 jmp 0x920edf
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?_Buynode@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp

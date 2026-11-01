// from server: 100% by auto
// roc 2010-06 004a0070  unit: seg_004a0000  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004a0070
//
// 004a0070  55                   push ebp
// 004a0071  8bec                 mov ebp, esp
// 004a0073  6aff                 push -1
// 004a0075  68e0789800           push 0x9878e0
// 004a007a  64a100000000         mov eax, dword ptr fs:[0]
// 004a0080  50                   push eax
// 004a0081  64892500000000       mov dword ptr fs:[0], esp
// 004a0088  51                   push ecx
// 004a0089  83ec50               sub esp, 0x50
// 004a008c  53                   push ebx
// 004a008d  56                   push esi
// 004a008e  57                   push edi
// 004a008f  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a0092  894dac               mov dword ptr [ebp - 0x54], ecx
// 004a0095  6a01                 push 1
// 004a0097  8b4dac               mov ecx, dword ptr [ebp - 0x54]
// 004a009a  83c10c               add ecx, 0xc
// 004a009d  e8ee020000           call 0x4a0390
// 004a00a2  8945e8               mov dword ptr [ebp - 0x18], eax
// 004a00a5  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 004a00ac  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a00b3  c745e400000000       mov dword ptr [ebp - 0x1c], 0
// 004a00ba  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004a00bd  8945c4               mov dword ptr [ebp - 0x3c], eax
// 004a00c0  8b4dc4               mov ecx, dword ptr [ebp - 0x3c]
// 004a00c3  894dc0               mov dword ptr [ebp - 0x40], ecx
// 004a00c6  837dc000             cmp dword ptr [ebp - 0x40], 0
// 004a00ca  7410                 je 0x4a00dc
// 004a00cc  8b55c0               mov edx, dword ptr [ebp - 0x40]
// 004a00cf  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 004a00d2  8902                 mov dword ptr [edx], eax
// 004a00d4  8b4dc0               mov ecx, dword ptr [ebp - 0x40]
// 004a00d7  894da8               mov dword ptr [ebp - 0x58], ecx
// 004a00da  eb07                 jmp 0x4a00e3
// 004a00dc  c745a800000000       mov dword ptr [ebp - 0x58], 0
// 004a00e3  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004a00e6  83c201               add edx, 1
// 004a00e9  8955ec               mov dword ptr [ebp - 0x14], edx
// 004a00ec  c745e000000000       mov dword ptr [ebp - 0x20], 0
// 004a00f3  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004a00f6  83c004               add eax, 4
// 004a00f9  8945bc               mov dword ptr [ebp - 0x44], eax
// 004a00fc  8b4dbc               mov ecx, dword ptr [ebp - 0x44]
// 004a00ff  894db8               mov dword ptr [ebp - 0x48], ecx
// 004a0102  837db800             cmp dword ptr [ebp - 0x48], 0
// 004a0106  7410                 je 0x4a0118
// 004a0108  8b55b8               mov edx, dword ptr [ebp - 0x48]
// 004a010b  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 004a010e  8902                 mov dword ptr [edx], eax
// 004a0110  8b4db8               mov ecx, dword ptr [ebp - 0x48]
// 004a0113  894da4               mov dword ptr [ebp - 0x5c], ecx
// 004a0116  eb07                 jmp 0x4a011f
// 004a0118  c745a400000000       mov dword ptr [ebp - 0x5c], 0
// 004a011f  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004a0122  83c201               add edx, 1
// 004a0125  8955ec               mov dword ptr [ebp - 0x14], edx
// 004a0128  c745dc00000000       mov dword ptr [ebp - 0x24], 0
// 004a012f  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004a0132  83c008               add eax, 8
// 004a0135  8945b4               mov dword ptr [ebp - 0x4c], eax
// 004a0138  8b4db4               mov ecx, dword ptr [ebp - 0x4c]
// 004a013b  894db0               mov dword ptr [ebp - 0x50], ecx
// 004a013e  837db000             cmp dword ptr [ebp - 0x50], 0
// 004a0142  7410                 je 0x4a0154
// 004a0144  8b55b0               mov edx, dword ptr [ebp - 0x50]
// 004a0147  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 004a014a  8902                 mov dword ptr [edx], eax
// 004a014c  8b4db0               mov ecx, dword ptr [ebp - 0x50]
// 004a014f  894da0               mov dword ptr [ebp - 0x60], ecx
// 004a0152  eb07                 jmp 0x4a015b
// 004a0154  c745a000000000       mov dword ptr [ebp - 0x60], 0
// 004a015b  eb22                 jmp 0x4a017f
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?_Buynode@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp

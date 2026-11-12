// from server: 100% by auto
// roc 2008-06 004c3c80  unit: ProfiledRakPeer  size: 257 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c3c80
//
// 004c3c80  8b442404             mov eax, dword ptr [esp + 4]
// 004c3c84  55                   push ebp
// 004c3c85  8be9                 mov ebp, ecx
// 004c3c87  85c0                 test eax, eax
// 004c3c89  0f84ec000000         je 0x4c3d7b
// 004c3c8f  8a4d04               mov cl, byte ptr [ebp + 4]
// 004c3c92  84c9                 test cl, cl
// 004c3c94  0f85e1000000         jne 0x4c3d7b
// 004c3c9a  8b542418             mov edx, dword ptr [esp + 0x18]
// 004c3c9e  3b9518070000         cmp edx, dword ptr [ebp + 0x718]
// 004c3ca4  0f83d1000000         jae 0x4c3d7b
// 004c3caa  57                   push edi
// 004c3cab  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004c3caf  81ffff000000         cmp edi, 0xff
// 004c3cb5  7e05                 jle 0x4c3cbc
// 004c3cb7  bfff000000           mov edi, 0xff
// 004c3cbc  837c241400           cmp dword ptr [esp + 0x14], 0
// 004c3cc1  7502                 jne 0x4c3cc5
// 004c3cc3  33ff                 xor edi, edi
// 004c3cc5  8a08                 mov cl, byte ptr [eax]
// 004c3cc7  80f930               cmp cl, 0x30
// 004c3cca  7c05                 jl 0x4c3cd1
// 004c3ccc  80f932               cmp cl, 0x32
// 004c3ccf  7e16                 jle 0x4c3ce7
// 004c3cd1  50                   push eax
// 004c3cd2  b9311d9700           mov ecx, 0x971d31
// 004c3cd7  e8a4a90000           call 0x4ce680
// 004c3cdc  85c0                 test eax, eax
// 004c3cde  7507                 jne 0x4c3ce7
// 004c3ce0  5f                   pop edi
// 004c3ce1  32c0                 xor al, al
// 004c3ce3  5d                   pop ebp
// 004c3ce4  c21400               ret 0x14
// 004c3ce7  bae82c8200           mov edx, 0x822ce8
// 004c3cec  8bc8                 mov ecx, eax
// 004c3cee  53                   push ebx
// 004c3cef  90                   nop 
// 004c3cf0  8a19                 mov bl, byte ptr [ecx]
// 004c3cf2  3a1a                 cmp bl, byte ptr [edx]
// 004c3cf4  751a                 jne 0x4c3d10
// 004c3cf6  84db                 test bl, bl
// 004c3cf8  7412                 je 0x4c3d0c
// 004c3cfa  8a5901               mov bl, byte ptr [ecx + 1]
// 004c3cfd  3a5a01               cmp bl, byte ptr [edx + 1]
// 004c3d00  750e                 jne 0x4c3d10
// 004c3d02  83c102               add ecx, 2
// 004c3d05  83c202               add edx, 2
// 004c3d08  84db                 test bl, bl
// 004c3d0a  75e4                 jne 0x4c3cf0
// 004c3d0c  33c9                 xor ecx, ecx
// 004c3d0e  eb05                 jmp 0x4c3d15
// 004c3d10  1bc9                 sbb ecx, ecx
// 004c3d12  83d9ff               sbb ecx, -1
// 004c3d15  56                   push esi
// 004c3d16  8b742418             mov esi, dword ptr [esp + 0x18]
// 004c3d1a  85c9                 test ecx, ecx
// 004c3d1c  7430                 je 0x4c3d4e
// 004c3d1e  bad0658200           mov edx, 0x8265d0
// 004c3d23  8bc8                 mov ecx, eax
// 004c3d25  8a19                 mov bl, byte ptr [ecx]
// 004c3d27  3a1a                 cmp bl, byte ptr [edx]
// 004c3d29  751a                 jne 0x4c3d45
// 004c3d2b  84db                 test bl, bl
// 004c3d2d  7412                 je 0x4c3d41
// 004c3d2f  8a5901               mov bl, byte ptr [ecx + 1]
// 004c3d32  3a5a01               cmp bl, byte ptr [edx + 1]
// 004c3d35  750e                 jne 0x4c3d45
// 004c3d37  83c102               add ecx, 2
// 004c3d3a  83c202               add edx, 2
// 004c3d3d  84db                 test bl, bl
// 004c3d3f  75e4                 jne 0x4c3d25
// 004c3d41  33c9                 xor ecx, ecx
// 004c3d43  eb05                 jmp 0x4c3d4a
// 004c3d45  1bc9                 sbb ecx, ecx
// 004c3d47  83d9ff               sbb ecx, -1
// 004c3d4a  85c9                 test ecx, ecx
// 004c3d4c  7512                 jne 0x4c3d60
// 004c3d4e  663bb524010000       cmp si, word ptr [ebp + 0x124]
// 004c3d55  7509                 jne 0x4c3d60
// 004c3d57  5e                   pop esi
// 004c3d58  5b                   pop ebx
// 004c3d59  5f                   pop edi
// 004c3d5a  32c0                 xor al, al
// 004c3d5c  5d                   pop ebp
// 004c3d5d  c21400               ret 0x14
// 004c3d60  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c3d64  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004c3d68  51                   push ecx
// 004c3d69  57                   push edi
// 004c3d6a  52                   push edx
// 004c3d6b  56                   push esi
// 004c3d6c  50                   push eax
// 004c3d6d  8bcd                 mov ecx, ebp
// 004c3d6f  e8bce2ffff           call 0x4c2030
// 004c3d74  5e                   pop esi
// 004c3d75  5b                   pop ebx
// 004c3d76  5f                   pop edi
// 004c3d77  5d                   pop ebp
// 004c3d78  c21400               ret 0x14
// 004c3d7b  32c0                 xor al, al
// 004c3d7d  5d                   pop ebp
// 004c3d7e  c21400               ret 0x14
// library openrbx-raknet/RakPeer.cpp (function ?Connect@RakPeer@@UAE_NPBDG0HI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp

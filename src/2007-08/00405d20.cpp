// from server: 100% by auto
// roc 2007-08 00405d20  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 382 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00405d20
//
// 00405d20  83ec0c               sub esp, 0xc
// 00405d23  57                   push edi
// 00405d24  8bf9                 mov edi, ecx
// 00405d26  33c0                 xor eax, eax
// 00405d28  39470c               cmp dword ptr [edi + 0xc], eax
// 00405d2b  897c2404             mov dword ptr [esp + 4], edi
// 00405d2f  7405                 je 0x405d36
// 00405d31  394714               cmp dword ptr [edi + 0x14], eax
// 00405d34  750a                 jne 0x405d40
// 00405d36  8b442420             mov eax, dword ptr [esp + 0x20]
// 00405d3a  50                   push eax
// 00405d3b  e8b0f8ffff           call 0x4055f0
// 00405d40  837f0c00             cmp dword ptr [edi + 0xc], 0
// 00405d44  0f8430010000         je 0x405e7a
// 00405d4a  837f1400             cmp dword ptr [edi + 0x14], 0
// 00405d4e  53                   push ebx
// 00405d4f  55                   push ebp
// 00405d50  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00405d54  56                   push esi
// 00405d55  0f8406010000         je 0x405e61
// 00405d5b  837c242801           cmp dword ptr [esp + 0x28], 1
// 00405d60  0f85fb000000         jne 0x405e61
// 00405d66  8b4500               mov eax, dword ptr [ebp]
// 00405d69  50                   push eax
// 00405d6a  ff1510d37700         call dword ptr [0x77d310]
// 00405d70  8b5f18               mov ebx, dword ptr [edi + 0x18]
// 00405d73  83eb01               sub ebx, 1
// 00405d76  89442414             mov dword ptr [esp + 0x14], eax
// 00405d7a  0f88e1000000         js 0x405e61
// 00405d80  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00405d83  8d045b               lea eax, [ebx + ebx*2]
// 00405d86  03c0                 add eax, eax
// 00405d88  03c0                 add eax, eax
// 00405d8a  894c2418             mov dword ptr [esp + 0x18], ecx
// 00405d8e  8d4c0804             lea ecx, [eax + ecx + 4]
// 00405d92  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00405d96  eb08                 jmp 0x405da0
// 00405d98  8da42400000000       lea esp, [esp]
// 00405d9f  90                   nop 
// 00405da0  8b542414             mov edx, dword ptr [esp + 0x14]
// 00405da4  3b11                 cmp edx, dword ptr [ecx]
// 00405da6  0f859c000000         jne 0x405e48
// 00405dac  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00405daf  8b5500               mov edx, dword ptr [ebp]
// 00405db2  8d3408               lea esi, [eax + ecx]
// 00405db5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00405db8  8b36                 mov esi, dword ptr [esi]
// 00405dba  03c9                 add ecx, ecx
// 00405dbc  83f904               cmp ecx, 4
// 00405dbf  7214                 jb 0x405dd5
// 00405dc1  8b2e                 mov ebp, dword ptr [esi]
// 00405dc3  3b2a                 cmp ebp, dword ptr [edx]
// 00405dc5  7512                 jne 0x405dd9
// 00405dc7  83e904               sub ecx, 4
// 00405dca  83c204               add edx, 4
// 00405dcd  83c604               add esi, 4
// 00405dd0  83f904               cmp ecx, 4
// 00405dd3  73ec                 jae 0x405dc1
// 00405dd5  85c9                 test ecx, ecx
// 00405dd7  7465                 je 0x405e3e
// 00405dd9  0fb63e               movzx edi, byte ptr [esi]
// 00405ddc  0fb62a               movzx ebp, byte ptr [edx]
// 00405ddf  2bfd                 sub edi, ebp
// 00405de1  7545                 jne 0x405e28
// 00405de3  83e901               sub ecx, 1
// 00405de6  83c201               add edx, 1
// 00405de9  83c601               add esi, 1
// 00405dec  85c9                 test ecx, ecx
// 00405dee  744a                 je 0x405e3a
// 00405df0  0fb63e               movzx edi, byte ptr [esi]
// 00405df3  0fb62a               movzx ebp, byte ptr [edx]
// 00405df6  2bfd                 sub edi, ebp
// 00405df8  752e                 jne 0x405e28
// 00405dfa  83e901               sub ecx, 1
// 00405dfd  83c201               add edx, 1
// 00405e00  83c601               add esi, 1
// 00405e03  85c9                 test ecx, ecx
// 00405e05  7433                 je 0x405e3a
// 00405e07  0fb63e               movzx edi, byte ptr [esi]
// 00405e0a  0fb62a               movzx ebp, byte ptr [edx]
// 00405e0d  2bfd                 sub edi, ebp
// 00405e0f  7517                 jne 0x405e28
// 00405e11  83e901               sub ecx, 1
// 00405e14  83c201               add edx, 1
// 00405e17  83c601               add esi, 1
// 00405e1a  85c9                 test ecx, ecx
// 00405e1c  741c                 je 0x405e3a
// 00405e1e  0fb63e               movzx edi, byte ptr [esi]
// 00405e21  0fb612               movzx edx, byte ptr [edx]
// 00405e24  2bfa                 sub edi, edx
// 00405e26  7412                 je 0x405e3a
// 00405e28  85ff                 test edi, edi
// 00405e2a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00405e2e  b901000000           mov ecx, 1
// 00405e33  7f0b                 jg 0x405e40
// 00405e35  83c9ff               or ecx, 0xffffffff
// 00405e38  eb06                 jmp 0x405e40
// 00405e3a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00405e3e  33c9                 xor ecx, ecx
// 00405e40  85c9                 test ecx, ecx
// 00405e42  743d                 je 0x405e81
// 00405e44  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00405e48  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00405e4c  83eb01               sub ebx, 1
// 00405e4f  83e90c               sub ecx, 0xc
// 00405e52  83e80c               sub eax, 0xc
// 00405e55  85db                 test ebx, ebx
// 00405e57  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00405e5b  0f8d3fffffff         jge 0x405da0
// 00405e61  8b542430             mov edx, dword ptr [esp + 0x30]
// 00405e65  8b470c               mov eax, dword ptr [edi + 0xc]
// 00405e68  8b08                 mov ecx, dword ptr [eax]
// 00405e6a  52                   push edx
// 00405e6b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00405e6f  52                   push edx
// 00405e70  55                   push ebp
// 00405e71  50                   push eax
// 00405e72  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00405e75  ffd0                 call eax
// 00405e77  5e                   pop esi
// 00405e78  5d                   pop ebp
// 00405e79  5b                   pop ebx
// 00405e7a  5f                   pop edi
// 00405e7b  83c40c               add esp, 0xc
// 00405e7e  c21400               ret 0x14
// 00405e81  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00405e85  8d045b               lea eax, [ebx + ebx*2]
// 00405e88  8b548108             mov edx, dword ptr [ecx + eax*4 + 8]
// 00405e8c  8b442430             mov eax, dword ptr [esp + 0x30]
// 00405e90  5e                   pop esi
// 00405e91  5d                   pop ebp
// 00405e92  5b                   pop ebx
// 00405e93  8910                 mov dword ptr [eax], edx
// 00405e95  33c0                 xor eax, eax
// 00405e97  5f                   pop edi
// 00405e98  83c40c               add esp, 0xc
// 00405e9b  c21400               ret 0x14
// library atl-8.0/atl.cpp (function ?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp

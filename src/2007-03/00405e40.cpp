// from server: 100% by auto
// roc 2007-03 00405e40  unit: seg_00400000  size: 382 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00405e40
//
// 00405e40  83ec0c               sub esp, 0xc
// 00405e43  57                   push edi
// 00405e44  8bf9                 mov edi, ecx
// 00405e46  33c0                 xor eax, eax
// 00405e48  39470c               cmp dword ptr [edi + 0xc], eax
// 00405e4b  897c2404             mov dword ptr [esp + 4], edi
// 00405e4f  7405                 je 0x405e56
// 00405e51  394714               cmp dword ptr [edi + 0x14], eax
// 00405e54  750a                 jne 0x405e60
// 00405e56  8b442420             mov eax, dword ptr [esp + 0x20]
// 00405e5a  50                   push eax
// 00405e5b  e890f6ffff           call 0x4054f0
// 00405e60  837f0c00             cmp dword ptr [edi + 0xc], 0
// 00405e64  0f8430010000         je 0x405f9a
// 00405e6a  837f1400             cmp dword ptr [edi + 0x14], 0
// 00405e6e  53                   push ebx
// 00405e6f  55                   push ebp
// 00405e70  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00405e74  56                   push esi
// 00405e75  0f8406010000         je 0x405f81
// 00405e7b  837c242801           cmp dword ptr [esp + 0x28], 1
// 00405e80  0f85fb000000         jne 0x405f81
// 00405e86  8b4500               mov eax, dword ptr [ebp]
// 00405e89  50                   push eax
// 00405e8a  ff15d0d27700         call dword ptr [0x77d2d0]
// 00405e90  8b5f18               mov ebx, dword ptr [edi + 0x18]
// 00405e93  83eb01               sub ebx, 1
// 00405e96  89442414             mov dword ptr [esp + 0x14], eax
// 00405e9a  0f88e1000000         js 0x405f81
// 00405ea0  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00405ea3  8d045b               lea eax, [ebx + ebx*2]
// 00405ea6  03c0                 add eax, eax
// 00405ea8  03c0                 add eax, eax
// 00405eaa  894c2418             mov dword ptr [esp + 0x18], ecx
// 00405eae  8d4c0804             lea ecx, [eax + ecx + 4]
// 00405eb2  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00405eb6  eb08                 jmp 0x405ec0
// 00405eb8  8da42400000000       lea esp, [esp]
// 00405ebf  90                   nop 
// 00405ec0  8b542414             mov edx, dword ptr [esp + 0x14]
// 00405ec4  3b11                 cmp edx, dword ptr [ecx]
// 00405ec6  0f859c000000         jne 0x405f68
// 00405ecc  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00405ecf  8b5500               mov edx, dword ptr [ebp]
// 00405ed2  8d3408               lea esi, [eax + ecx]
// 00405ed5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00405ed8  8b36                 mov esi, dword ptr [esi]
// 00405eda  03c9                 add ecx, ecx
// 00405edc  83f904               cmp ecx, 4
// 00405edf  7214                 jb 0x405ef5
// 00405ee1  8b2e                 mov ebp, dword ptr [esi]
// 00405ee3  3b2a                 cmp ebp, dword ptr [edx]
// 00405ee5  7512                 jne 0x405ef9
// 00405ee7  83e904               sub ecx, 4
// 00405eea  83c204               add edx, 4
// 00405eed  83c604               add esi, 4
// 00405ef0  83f904               cmp ecx, 4
// 00405ef3  73ec                 jae 0x405ee1
// 00405ef5  85c9                 test ecx, ecx
// 00405ef7  7465                 je 0x405f5e
// 00405ef9  0fb63e               movzx edi, byte ptr [esi]
// 00405efc  0fb62a               movzx ebp, byte ptr [edx]
// 00405eff  2bfd                 sub edi, ebp
// 00405f01  7545                 jne 0x405f48
// 00405f03  83e901               sub ecx, 1
// 00405f06  83c201               add edx, 1
// 00405f09  83c601               add esi, 1
// 00405f0c  85c9                 test ecx, ecx
// 00405f0e  744a                 je 0x405f5a
// 00405f10  0fb63e               movzx edi, byte ptr [esi]
// 00405f13  0fb62a               movzx ebp, byte ptr [edx]
// 00405f16  2bfd                 sub edi, ebp
// 00405f18  752e                 jne 0x405f48
// 00405f1a  83e901               sub ecx, 1
// 00405f1d  83c201               add edx, 1
// 00405f20  83c601               add esi, 1
// 00405f23  85c9                 test ecx, ecx
// 00405f25  7433                 je 0x405f5a
// 00405f27  0fb63e               movzx edi, byte ptr [esi]
// 00405f2a  0fb62a               movzx ebp, byte ptr [edx]
// 00405f2d  2bfd                 sub edi, ebp
// 00405f2f  7517                 jne 0x405f48
// 00405f31  83e901               sub ecx, 1
// 00405f34  83c201               add edx, 1
// 00405f37  83c601               add esi, 1
// 00405f3a  85c9                 test ecx, ecx
// 00405f3c  741c                 je 0x405f5a
// 00405f3e  0fb63e               movzx edi, byte ptr [esi]
// 00405f41  0fb612               movzx edx, byte ptr [edx]
// 00405f44  2bfa                 sub edi, edx
// 00405f46  7412                 je 0x405f5a
// 00405f48  85ff                 test edi, edi
// 00405f4a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00405f4e  b901000000           mov ecx, 1
// 00405f53  7f0b                 jg 0x405f60
// 00405f55  83c9ff               or ecx, 0xffffffff
// 00405f58  eb06                 jmp 0x405f60
// 00405f5a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00405f5e  33c9                 xor ecx, ecx
// 00405f60  85c9                 test ecx, ecx
// 00405f62  743d                 je 0x405fa1
// 00405f64  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00405f68  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00405f6c  83eb01               sub ebx, 1
// 00405f6f  83e90c               sub ecx, 0xc
// 00405f72  83e80c               sub eax, 0xc
// 00405f75  85db                 test ebx, ebx
// 00405f77  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00405f7b  0f8d3fffffff         jge 0x405ec0
// 00405f81  8b542430             mov edx, dword ptr [esp + 0x30]
// 00405f85  8b470c               mov eax, dword ptr [edi + 0xc]
// 00405f88  8b08                 mov ecx, dword ptr [eax]
// 00405f8a  52                   push edx
// 00405f8b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00405f8f  52                   push edx
// 00405f90  55                   push ebp
// 00405f91  50                   push eax
// 00405f92  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00405f95  ffd0                 call eax
// 00405f97  5e                   pop esi
// 00405f98  5d                   pop ebp
// 00405f99  5b                   pop ebx
// 00405f9a  5f                   pop edi
// 00405f9b  83c40c               add esp, 0xc
// 00405f9e  c21400               ret 0x14
// 00405fa1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00405fa5  8d045b               lea eax, [ebx + ebx*2]
// 00405fa8  8b548108             mov edx, dword ptr [ecx + eax*4 + 8]
// 00405fac  8b442430             mov eax, dword ptr [esp + 0x30]
// 00405fb0  5e                   pop esi
// 00405fb1  5d                   pop ebp
// 00405fb2  5b                   pop ebx
// 00405fb3  8910                 mov dword ptr [eax], edx
// 00405fb5  33c0                 xor eax, eax
// 00405fb7  5f                   pop edi
// 00405fb8  83c40c               add esp, 0xc
// 00405fbb  c21400               ret 0x14
// library atl-8.0/atl.cpp (function ?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp

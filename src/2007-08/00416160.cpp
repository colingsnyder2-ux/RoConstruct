// from server: 100% by auto
// roc 2007-08 00416160  unit: VCLuaFunction::?$CComAggObject  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00416160
//
// 00416160  56                   push esi
// 00416161  8bf1                 mov esi, ecx
// 00416163  837e1400             cmp dword ptr [esi + 0x14], 0
// 00416167  750c                 jne 0x416175
// 00416169  e8c9f23000           call 0x725437
// 0041616e  85c0                 test eax, eax
// 00416170  894614               mov dword ptr [esi + 0x14], eax
// 00416173  7440                 je 0x4161b5
// 00416175  8b4614               mov eax, dword ptr [esi + 0x14]
// 00416178  b9f3ffffff           mov ecx, 0xfffffff3
// 0041617d  6a0d                 push 0xd
// 0041617f  2bc8                 sub ecx, eax
// 00416181  50                   push eax
// 00416182  c700c7442404         mov dword ptr [eax], 0x42444c7
// 00416188  c7400400000000       mov dword ptr [eax + 4], 0
// 0041618f  c64008e9             mov byte ptr [eax + 8], 0xe9
// 00416193  894809               mov dword ptr [eax + 9], ecx
// 00416196  ff1594d27700         call dword ptr [0x77d294]
// 0041619c  50                   push eax
// 0041619d  ff1598d27700         call dword ptr [0x77d298]
// 004161a3  55                   push ebp
// 004161a4  668b6c2424           mov bp, word ptr [esp + 0x24]
// 004161a9  6685ed               test bp, bp
// 004161ac  7515                 jne 0x4161c3
// 004161ae  5d                   pop ebp
// 004161af  33c0                 xor eax, eax
// 004161b1  5e                   pop esi
// 004161b2  c22000               ret 0x20
// 004161b5  6a0e                 push 0xe
// 004161b7  ff1590d27700         call dword ptr [0x77d290]
// 004161bd  33c0                 xor eax, eax
// 004161bf  5e                   pop esi
// 004161c0  c22000               ret 0x20
// 004161c3  53                   push ebx
// 004161c4  57                   push edi
// 004161c5  56                   push esi
// 004161c6  8d5608               lea edx, [esi + 8]
// 004161c9  52                   push edx
// 004161ca  6860988c00           push 0x8c9860
// 004161cf  e80ce7ffff           call 0x4148e0
// 004161d4  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004161d8  85ff                 test edi, edi
// 004161da  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004161de  750a                 jne 0x4161ea
// 004161e0  f7c300000040         test ebx, 0x40000000
// 004161e6  7402                 je 0x4161ea
// 004161e8  8bfe                 mov edi, esi
// 004161ea  8b442418             mov eax, dword ptr [esp + 0x18]
// 004161ee  85c0                 test eax, eax
// 004161f0  7505                 jne 0x4161f7
// 004161f2  b87c018800           mov eax, 0x88017c
// 004161f7  8b742430             mov esi, dword ptr [esp + 0x30]
// 004161fb  8b4804               mov ecx, dword ptr [eax + 4]
// 004161fe  8b10                 mov edx, dword ptr [eax]
// 00416200  56                   push esi
// 00416201  8b3528988c00         mov esi, dword ptr [0x8c9828]
// 00416207  56                   push esi
// 00416208  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0041620c  57                   push edi
// 0041620d  56                   push esi
// 0041620e  8b700c               mov esi, dword ptr [eax + 0xc]
// 00416211  8b4008               mov eax, dword ptr [eax + 8]
// 00416214  2bf1                 sub esi, ecx
// 00416216  56                   push esi
// 00416217  2bc2                 sub eax, edx
// 00416219  50                   push eax
// 0041621a  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0041621e  51                   push ecx
// 0041621f  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00416223  52                   push edx
// 00416224  53                   push ebx
// 00416225  0fb7d5               movzx edx, bp
// 00416228  51                   push ecx
// 00416229  52                   push edx
// 0041622a  50                   push eax
// 0041622b  ff1530ec7700         call dword ptr [0x77ec30]
// 00416231  5f                   pop edi
// 00416232  5b                   pop ebx
// 00416233  5d                   pop ebp
// 00416234  5e                   pop esi
// 00416235  c22000               ret 0x20
// library atl-8.0/atl.cpp (function ?Create@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@QAEPAUHWND__@@PAU3@V_U_RECT@2@PBDKKV_U_MENUorID@2@GPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp

// from server: 100% by auto
// roc 2008-06 004bbe70  unit: ProfiledRakPeer  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbe70
//
// 004bbe70  56                   push esi
// 004bbe71  8bf1                 mov esi, ecx
// 004bbe73  83be2c02000000       cmp dword ptr [esi + 0x22c], 0
// 004bbe7a  7446                 je 0x4bbec2
// 004bbe7c  57                   push edi
// 004bbe7d  33c0                 xor eax, eax
// 004bbe7f  33ff                 xor edi, edi
// 004bbe81  663b4608             cmp ax, word ptr [esi + 8]
// 004bbe85  733a                 jae 0x4bbec1
// 004bbe87  53                   push ebx
// 004bbe88  0fb75c241c           movzx ebx, word ptr [esp + 0x1c]
// 004bbe8d  8d4900               lea ecx, [ecx]
// 004bbe90  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 004bbe95  dd442410             fld qword ptr [esp + 0x10]
// 004bbe99  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 004bbe9f  0fb7cf               movzx ecx, di
// 004bbea2  69c950080000         imul ecx, ecx, 0x850
// 004bbea8  53                   push ebx
// 004bbea9  50                   push eax
// 004bbeaa  83ec08               sub esp, 8
// 004bbead  8d4c1118             lea ecx, [ecx + edx + 0x18]
// 004bbeb1  dd1c24               fstp qword ptr [esp]
// 004bbeb4  e8472d0100           call 0x4cec00
// 004bbeb9  47                   inc edi
// 004bbeba  663b7e08             cmp di, word ptr [esi + 8]
// 004bbebe  72d0                 jb 0x4bbe90
// 004bbec0  5b                   pop ebx
// 004bbec1  5f                   pop edi
// 004bbec2  dd442408             fld qword ptr [esp + 8]
// 004bbec6  668b442410           mov ax, word ptr [esp + 0x10]
// 004bbecb  668b4c2414           mov cx, word ptr [esp + 0x14]
// 004bbed0  dd9e38070000         fstp qword ptr [esi + 0x738]
// 004bbed6  66898640070000       mov word ptr [esi + 0x740], ax
// 004bbedd  66898e42070000       mov word ptr [esi + 0x742], cx
// 004bbee4  5e                   pop esi
// 004bbee5  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?ApplyNetworkSimulator@RakPeer@@UAEXNGG@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp

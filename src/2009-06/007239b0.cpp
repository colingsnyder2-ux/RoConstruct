// from server: 100% by auto
// roc 2009-06 007239b0  unit: RBX::Network::Players::Plugin  size: 289 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007239b0
//
// 007239b0  51                   push ecx
// 007239b1  d9ee                 fldz 
// 007239b3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007239b7  dd44241c             fld qword ptr [esp + 0x1c]
// 007239bb  d8d1                 fcom st(1)
// 007239bd  dfe0                 fnstsw ax
// 007239bf  ddd9                 fstp st(1)
// 007239c1  f6c405               test ah, 5
// 007239c4  7a04                 jp 0x7239ca
// 007239c6  d9e0                 fchs 
// 007239c8  eb20                 jmp 0x7239ea
// 007239ca  8b442410             mov eax, dword ptr [esp + 0x10]
// 007239ce  ddd8                 fstp st(0)
// 007239d0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007239d4  8b542408             mov edx, dword ptr [esp + 8]
// 007239d8  50                   push eax
// 007239d9  8b4204               mov eax, dword ptr [edx + 4]
// 007239dc  51                   push ecx
// 007239dd  50                   push eax
// 007239de  ff15d8e08900         call dword ptr [0x89e0d8]
// 007239e4  dd44241c             fld qword ptr [esp + 0x1c]
// 007239e8  8bc8                 mov ecx, eax
// 007239ea  8b442414             mov eax, dword ptr [esp + 0x14]
// 007239ee  8bd0                 mov edx, eax
// 007239f0  56                   push esi
// 007239f1  c1ea10               shr edx, 0x10
// 007239f4  0fb6f2               movzx esi, dl
// 007239f7  8bd0                 mov edx, eax
// 007239f9  57                   push edi
// 007239fa  0fb6f8               movzx edi, al
// 007239fd  8bc1                 mov eax, ecx
// 007239ff  c1e810               shr eax, 0x10
// 00723a02  0fb6c0               movzx eax, al
// 00723a05  2bc6                 sub eax, esi
// 00723a07  89442420             mov dword ptr [esp + 0x20], eax
// 00723a0b  8974241c             mov dword ptr [esp + 0x1c], esi
// 00723a0f  c1ea08               shr edx, 8
// 00723a12  db442420             fild dword ptr [esp + 0x20]
// 00723a16  0fb6d2               movzx edx, dl
// 00723a19  d97c2420             fnstcw word ptr [esp + 0x20]
// 00723a1d  d8c9                 fmul st(1)
// 00723a1f  0fb7442420           movzx eax, word ptr [esp + 0x20]
// 00723a24  da44241c             fiadd dword ptr [esp + 0x1c]
// 00723a28  0d000c0000           or eax, 0xc00
// 00723a2d  8944241c             mov dword ptr [esp + 0x1c], eax
// 00723a31  d96c241c             fldcw word ptr [esp + 0x1c]
// 00723a35  89542424             mov dword ptr [esp + 0x24], edx
// 00723a39  897c2408             mov dword ptr [esp + 8], edi
// 00723a3d  db5c241c             fistp dword ptr [esp + 0x1c]
// 00723a41  8a44241c             mov al, byte ptr [esp + 0x1c]
// 00723a45  0fb6f0               movzx esi, al
// 00723a48  8bc1                 mov eax, ecx
// 00723a4a  d96c2420             fldcw word ptr [esp + 0x20]
// 00723a4e  c1e808               shr eax, 8
// 00723a51  0fb6c0               movzx eax, al
// 00723a54  2bc2                 sub eax, edx
// 00723a56  89442420             mov dword ptr [esp + 0x20], eax
// 00723a5a  0fb6c9               movzx ecx, cl
// 00723a5d  db442420             fild dword ptr [esp + 0x20]
// 00723a61  d97c2420             fnstcw word ptr [esp + 0x20]
// 00723a65  0fb7442420           movzx eax, word ptr [esp + 0x20]
// 00723a6a  d8c9                 fmul st(1)
// 00723a6c  0d000c0000           or eax, 0xc00
// 00723a71  8944241c             mov dword ptr [esp + 0x1c], eax
// 00723a75  2bcf                 sub ecx, edi
// 00723a77  da442424             fiadd dword ptr [esp + 0x24]
// 00723a7b  c1e608               shl esi, 8
// 00723a7e  5f                   pop edi
// 00723a7f  d96c2418             fldcw word ptr [esp + 0x18]
// 00723a83  db5c2418             fistp dword ptr [esp + 0x18]
// 00723a87  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 00723a8c  0fb6c2               movzx eax, dl
// 00723a8f  d96c241c             fldcw word ptr [esp + 0x1c]
// 00723a93  0bf0                 or esi, eax
// 00723a95  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00723a99  c1e608               shl esi, 8
// 00723a9c  db44241c             fild dword ptr [esp + 0x1c]
// 00723aa0  d97c241c             fnstcw word ptr [esp + 0x1c]
// 00723aa4  dec9                 fmulp st(1)
// 00723aa6  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 00723aab  0d000c0000           or eax, 0xc00
// 00723ab0  89442418             mov dword ptr [esp + 0x18], eax
// 00723ab4  da442404             fiadd dword ptr [esp + 4]
// 00723ab8  d96c2418             fldcw word ptr [esp + 0x18]
// 00723abc  db5c2418             fistp dword ptr [esp + 0x18]
// 00723ac0  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 00723ac5  0fb6c2               movzx eax, dl
// 00723ac8  d96c241c             fldcw word ptr [esp + 0x1c]
// 00723acc  0bc6                 or eax, esi
// 00723ace  5e                   pop esi
// 00723acf  59                   pop ecx
// 00723ad0  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Mix@@YAKPAVCDC@@HHKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp

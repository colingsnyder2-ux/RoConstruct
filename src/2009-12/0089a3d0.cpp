// from server: 100% by auto
// roc 2009-12 0089a3d0  unit: CXTPRibbonBar  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a3d0
//
// 0089a3d0  83ec08               sub esp, 8
// 0089a3d3  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0089a3d7  53                   push ebx
// 0089a3d8  56                   push esi
// 0089a3d9  0fb6f2               movzx esi, dl
// 0089a3dc  8bc2                 mov eax, edx
// 0089a3de  c1e810               shr eax, 0x10
// 0089a3e1  0fb6c0               movzx eax, al
// 0089a3e4  89442414             mov dword ptr [esp + 0x14], eax
// 0089a3e8  8bca                 mov ecx, edx
// 0089a3ea  8b542418             mov edx, dword ptr [esp + 0x18]
// 0089a3ee  db442414             fild dword ptr [esp + 0x14]
// 0089a3f2  57                   push edi
// 0089a3f3  8bda                 mov ebx, edx
// 0089a3f5  c1eb10               shr ebx, 0x10
// 0089a3f8  0fb6fb               movzx edi, bl
// 0089a3fb  2bc7                 sub eax, edi
// 0089a3fd  89442418             mov dword ptr [esp + 0x18], eax
// 0089a401  c1e908               shr ecx, 8
// 0089a404  0fb6c9               movzx ecx, cl
// 0089a407  db442418             fild dword ptr [esp + 0x18]
// 0089a40b  dd442420             fld qword ptr [esp + 0x20]
// 0089a40f  d97c2418             fnstcw word ptr [esp + 0x18]
// 0089a413  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0089a418  dcc9                 fmul st(1), st(0)
// 0089a41a  d9ca                 fxch st(2)
// 0089a41c  0d000c0000           or eax, 0xc00
// 0089a421  8944241c             mov dword ptr [esp + 0x1c], eax
// 0089a425  dee1                 fsubrp st(1)
// 0089a427  894c240c             mov dword ptr [esp + 0xc], ecx
// 0089a42b  89742410             mov dword ptr [esp + 0x10], esi
// 0089a42f  d96c241c             fldcw word ptr [esp + 0x1c]
// 0089a433  db5c241c             fistp dword ptr [esp + 0x1c]
// 0089a437  8a44241c             mov al, byte ptr [esp + 0x1c]
// 0089a43b  0fb6f8               movzx edi, al
// 0089a43e  8bc2                 mov eax, edx
// 0089a440  d96c2418             fldcw word ptr [esp + 0x18]
// 0089a444  c1e808               shr eax, 8
// 0089a447  0fb6c0               movzx eax, al
// 0089a44a  2bc8                 sub ecx, eax
// 0089a44c  894c2418             mov dword ptr [esp + 0x18], ecx
// 0089a450  c1e708               shl edi, 8
// 0089a453  db44240c             fild dword ptr [esp + 0xc]
// 0089a457  db442418             fild dword ptr [esp + 0x18]
// 0089a45b  d97c2418             fnstcw word ptr [esp + 0x18]
// 0089a45f  d8ca                 fmul st(2)
// 0089a461  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0089a466  0d000c0000           or eax, 0xc00
// 0089a46b  8944241c             mov dword ptr [esp + 0x1c], eax
// 0089a46f  dee9                 fsubp st(1)
// 0089a471  d96c241c             fldcw word ptr [esp + 0x1c]
// 0089a475  db5c241c             fistp dword ptr [esp + 0x1c]
// 0089a479  8a4c241c             mov cl, byte ptr [esp + 0x1c]
// 0089a47d  0fb6c1               movzx eax, cl
// 0089a480  0fb6ca               movzx ecx, dl
// 0089a483  d96c2418             fldcw word ptr [esp + 0x18]
// 0089a487  2bf1                 sub esi, ecx
// 0089a489  89742418             mov dword ptr [esp + 0x18], esi
// 0089a48d  0bf8                 or edi, eax
// 0089a48f  c1e708               shl edi, 8
// 0089a492  db442410             fild dword ptr [esp + 0x10]
// 0089a496  db442418             fild dword ptr [esp + 0x18]
// 0089a49a  d97c2418             fnstcw word ptr [esp + 0x18]
// 0089a49e  deca                 fmulp st(2)
// 0089a4a0  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0089a4a5  0d000c0000           or eax, 0xc00
// 0089a4aa  8944241c             mov dword ptr [esp + 0x1c], eax
// 0089a4ae  dee1                 fsubrp st(1)
// 0089a4b0  d96c241c             fldcw word ptr [esp + 0x1c]
// 0089a4b4  db5c241c             fistp dword ptr [esp + 0x1c]
// 0089a4b8  8a54241c             mov dl, byte ptr [esp + 0x1c]
// 0089a4bc  0fb6c2               movzx eax, dl
// 0089a4bf  0bc7                 or eax, edi
// 0089a4c1  d96c2418             fldcw word ptr [esp + 0x18]
// 0089a4c5  5f                   pop edi
// 0089a4c6  5e                   pop esi
// 0089a4c7  5b                   pop ebx
// 0089a4c8  83c408               add esp, 8
// 0089a4cb  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Header\XTPHeaderCtrlTheme.cpp (function ?MixColor@CXTPHeaderCtrlThemeOffice2003@@AAEKKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Header/XTPHeaderCtrlTheme.cpp

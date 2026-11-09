// from server: 100% by auto
// roc 2010-06 0084e560  unit: CXTPRibbonBar  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e560
//
// 0084e560  83ec08               sub esp, 8
// 0084e563  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0084e567  53                   push ebx
// 0084e568  56                   push esi
// 0084e569  0fb6f2               movzx esi, dl
// 0084e56c  8bc2                 mov eax, edx
// 0084e56e  c1e810               shr eax, 0x10
// 0084e571  0fb6c0               movzx eax, al
// 0084e574  89442414             mov dword ptr [esp + 0x14], eax
// 0084e578  8bca                 mov ecx, edx
// 0084e57a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0084e57e  db442414             fild dword ptr [esp + 0x14]
// 0084e582  57                   push edi
// 0084e583  8bda                 mov ebx, edx
// 0084e585  c1eb10               shr ebx, 0x10
// 0084e588  0fb6fb               movzx edi, bl
// 0084e58b  2bc7                 sub eax, edi
// 0084e58d  89442418             mov dword ptr [esp + 0x18], eax
// 0084e591  c1e908               shr ecx, 8
// 0084e594  0fb6c9               movzx ecx, cl
// 0084e597  db442418             fild dword ptr [esp + 0x18]
// 0084e59b  dd442420             fld qword ptr [esp + 0x20]
// 0084e59f  d97c2418             fnstcw word ptr [esp + 0x18]
// 0084e5a3  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0084e5a8  dcc9                 fmul st(1), st(0)
// 0084e5aa  d9ca                 fxch st(2)
// 0084e5ac  0d000c0000           or eax, 0xc00
// 0084e5b1  8944241c             mov dword ptr [esp + 0x1c], eax
// 0084e5b5  dee1                 fsubrp st(1)
// 0084e5b7  894c240c             mov dword ptr [esp + 0xc], ecx
// 0084e5bb  89742410             mov dword ptr [esp + 0x10], esi
// 0084e5bf  d96c241c             fldcw word ptr [esp + 0x1c]
// 0084e5c3  db5c241c             fistp dword ptr [esp + 0x1c]
// 0084e5c7  8a44241c             mov al, byte ptr [esp + 0x1c]
// 0084e5cb  0fb6f8               movzx edi, al
// 0084e5ce  8bc2                 mov eax, edx
// 0084e5d0  d96c2418             fldcw word ptr [esp + 0x18]
// 0084e5d4  c1e808               shr eax, 8
// 0084e5d7  0fb6c0               movzx eax, al
// 0084e5da  2bc8                 sub ecx, eax
// 0084e5dc  894c2418             mov dword ptr [esp + 0x18], ecx
// 0084e5e0  c1e708               shl edi, 8
// 0084e5e3  db44240c             fild dword ptr [esp + 0xc]
// 0084e5e7  db442418             fild dword ptr [esp + 0x18]
// 0084e5eb  d97c2418             fnstcw word ptr [esp + 0x18]
// 0084e5ef  d8ca                 fmul st(2)
// 0084e5f1  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0084e5f6  0d000c0000           or eax, 0xc00
// 0084e5fb  8944241c             mov dword ptr [esp + 0x1c], eax
// 0084e5ff  dee9                 fsubp st(1)
// 0084e601  d96c241c             fldcw word ptr [esp + 0x1c]
// 0084e605  db5c241c             fistp dword ptr [esp + 0x1c]
// 0084e609  8a4c241c             mov cl, byte ptr [esp + 0x1c]
// 0084e60d  0fb6c1               movzx eax, cl
// 0084e610  0fb6ca               movzx ecx, dl
// 0084e613  d96c2418             fldcw word ptr [esp + 0x18]
// 0084e617  2bf1                 sub esi, ecx
// 0084e619  89742418             mov dword ptr [esp + 0x18], esi
// 0084e61d  0bf8                 or edi, eax
// 0084e61f  c1e708               shl edi, 8
// 0084e622  db442410             fild dword ptr [esp + 0x10]
// 0084e626  db442418             fild dword ptr [esp + 0x18]
// 0084e62a  d97c2418             fnstcw word ptr [esp + 0x18]
// 0084e62e  deca                 fmulp st(2)
// 0084e630  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0084e635  0d000c0000           or eax, 0xc00
// 0084e63a  8944241c             mov dword ptr [esp + 0x1c], eax
// 0084e63e  dee1                 fsubrp st(1)
// 0084e640  d96c241c             fldcw word ptr [esp + 0x1c]
// 0084e644  db5c241c             fistp dword ptr [esp + 0x1c]
// 0084e648  8a54241c             mov dl, byte ptr [esp + 0x1c]
// 0084e64c  0fb6c2               movzx eax, dl
// 0084e64f  0bc7                 or eax, edi
// 0084e651  d96c2418             fldcw word ptr [esp + 0x18]
// 0084e655  5f                   pop edi
// 0084e656  5e                   pop esi
// 0084e657  5b                   pop ebx
// 0084e658  83c408               add esp, 8
// 0084e65b  c21000               ret 0x10
// library xtp-13.2.1/Source\Controls\XTHeaderCtrlTheme.cpp (function ?MixColor@CXTHeaderCtrlThemeOffice2003@@AAEKKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTHeaderCtrlTheme.cpp

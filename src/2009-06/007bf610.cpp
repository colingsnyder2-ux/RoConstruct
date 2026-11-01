// from server: 100% by auto
// roc 2009-06 007bf610  unit: CXTPDockContext  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf610
//
// 007bf610  83ec08               sub esp, 8
// 007bf613  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bf617  53                   push ebx
// 007bf618  56                   push esi
// 007bf619  0fb6f2               movzx esi, dl
// 007bf61c  8bc2                 mov eax, edx
// 007bf61e  c1e810               shr eax, 0x10
// 007bf621  0fb6c0               movzx eax, al
// 007bf624  89442414             mov dword ptr [esp + 0x14], eax
// 007bf628  8bca                 mov ecx, edx
// 007bf62a  8b542418             mov edx, dword ptr [esp + 0x18]
// 007bf62e  db442414             fild dword ptr [esp + 0x14]
// 007bf632  57                   push edi
// 007bf633  8bda                 mov ebx, edx
// 007bf635  c1eb10               shr ebx, 0x10
// 007bf638  0fb6fb               movzx edi, bl
// 007bf63b  2bc7                 sub eax, edi
// 007bf63d  89442418             mov dword ptr [esp + 0x18], eax
// 007bf641  c1e908               shr ecx, 8
// 007bf644  0fb6c9               movzx ecx, cl
// 007bf647  db442418             fild dword ptr [esp + 0x18]
// 007bf64b  dd442420             fld qword ptr [esp + 0x20]
// 007bf64f  d97c2418             fnstcw word ptr [esp + 0x18]
// 007bf653  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 007bf658  dcc9                 fmul st(1), st(0)
// 007bf65a  d9ca                 fxch st(2)
// 007bf65c  0d000c0000           or eax, 0xc00
// 007bf661  8944241c             mov dword ptr [esp + 0x1c], eax
// 007bf665  dee1                 fsubrp st(1)
// 007bf667  894c240c             mov dword ptr [esp + 0xc], ecx
// 007bf66b  89742410             mov dword ptr [esp + 0x10], esi
// 007bf66f  d96c241c             fldcw word ptr [esp + 0x1c]
// 007bf673  db5c241c             fistp dword ptr [esp + 0x1c]
// 007bf677  8a44241c             mov al, byte ptr [esp + 0x1c]
// 007bf67b  0fb6f8               movzx edi, al
// 007bf67e  8bc2                 mov eax, edx
// 007bf680  d96c2418             fldcw word ptr [esp + 0x18]
// 007bf684  c1e808               shr eax, 8
// 007bf687  0fb6c0               movzx eax, al
// 007bf68a  2bc8                 sub ecx, eax
// 007bf68c  894c2418             mov dword ptr [esp + 0x18], ecx
// 007bf690  c1e708               shl edi, 8
// 007bf693  db44240c             fild dword ptr [esp + 0xc]
// 007bf697  db442418             fild dword ptr [esp + 0x18]
// 007bf69b  d97c2418             fnstcw word ptr [esp + 0x18]
// 007bf69f  d8ca                 fmul st(2)
// 007bf6a1  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 007bf6a6  0d000c0000           or eax, 0xc00
// 007bf6ab  8944241c             mov dword ptr [esp + 0x1c], eax
// 007bf6af  dee9                 fsubp st(1)
// 007bf6b1  d96c241c             fldcw word ptr [esp + 0x1c]
// 007bf6b5  db5c241c             fistp dword ptr [esp + 0x1c]
// 007bf6b9  8a4c241c             mov cl, byte ptr [esp + 0x1c]
// 007bf6bd  0fb6c1               movzx eax, cl
// 007bf6c0  0fb6ca               movzx ecx, dl
// 007bf6c3  d96c2418             fldcw word ptr [esp + 0x18]
// 007bf6c7  2bf1                 sub esi, ecx
// 007bf6c9  89742418             mov dword ptr [esp + 0x18], esi
// 007bf6cd  0bf8                 or edi, eax
// 007bf6cf  c1e708               shl edi, 8
// 007bf6d2  db442410             fild dword ptr [esp + 0x10]
// 007bf6d6  db442418             fild dword ptr [esp + 0x18]
// 007bf6da  d97c2418             fnstcw word ptr [esp + 0x18]
// 007bf6de  deca                 fmulp st(2)
// 007bf6e0  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 007bf6e5  0d000c0000           or eax, 0xc00
// 007bf6ea  8944241c             mov dword ptr [esp + 0x1c], eax
// 007bf6ee  dee1                 fsubrp st(1)
// 007bf6f0  d96c241c             fldcw word ptr [esp + 0x1c]
// 007bf6f4  db5c241c             fistp dword ptr [esp + 0x1c]
// 007bf6f8  8a54241c             mov dl, byte ptr [esp + 0x1c]
// 007bf6fc  0fb6c2               movzx eax, dl
// 007bf6ff  0bc7                 or eax, edi
// 007bf701  d96c2418             fldcw word ptr [esp + 0x18]
// 007bf705  5f                   pop edi
// 007bf706  5e                   pop esi
// 007bf707  5b                   pop ebx
// 007bf708  83c408               add esp, 8
// 007bf70b  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Header\XTPHeaderCtrlTheme.cpp (function ?MixColor@CXTPHeaderCtrlThemeOffice2003@@AAEKKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Header/XTPHeaderCtrlTheme.cpp

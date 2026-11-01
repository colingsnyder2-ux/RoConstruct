// from server: 100% by auto
// roc 2007-03 006158b0  unit: seg_00610000  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006158b0
//
// 006158b0  55                   push ebp
// 006158b1  57                   push edi
// 006158b2  53                   push ebx
// 006158b3  56                   push esi
// 006158b4  8bf8                 mov edi, eax
// 006158b6  e8f5f9ffff           call 0x6152b0
// 006158bb  57                   push edi
// 006158bc  56                   push esi
// 006158bd  8be8                 mov ebp, eax
// 006158bf  e8ecf9ffff           call 0x6152b0
// 006158c4  83c410               add esp, 0x10
// 006158c7  83caff               or edx, 0xffffffff
// 006158ca  833f0c               cmp dword ptr [edi], 0xc
// 006158cd  7516                 jne 0x6158e5
// 006158cf  8b7f08               mov edi, dword ptr [edi + 8]
// 006158d2  f7c700010000         test edi, 0x100
// 006158d8  750b                 jne 0x6158e5
// 006158da  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 006158de  3bf9                 cmp edi, ecx
// 006158e0  7c03                 jl 0x6158e5
// 006158e2  015624               add dword ptr [esi + 0x24], edx
// 006158e5  833b0c               cmp dword ptr [ebx], 0xc
// 006158e8  7516                 jne 0x615900
// 006158ea  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006158ed  f7c100010000         test ecx, 0x100
// 006158f3  750b                 jne 0x615900
// 006158f5  0fb67e32             movzx edi, byte ptr [esi + 0x32]
// 006158f9  3bcf                 cmp ecx, edi
// 006158fb  7c03                 jl 0x615900
// 006158fd  015624               add dword ptr [esi + 0x24], edx
// 00615900  837c241000           cmp dword ptr [esp + 0x10], 0
// 00615905  7515                 jne 0x61591c
// 00615907  837c240c17           cmp dword ptr [esp + 0xc], 0x17
// 0061590c  740e                 je 0x61591c
// 0061590e  8bcd                 mov ecx, ebp
// 00615910  8be8                 mov ebp, eax
// 00615912  8bc1                 mov eax, ecx
// 00615914  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0061591c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00615920  50                   push eax
// 00615921  8b442410             mov eax, dword ptr [esp + 0x10]
// 00615925  52                   push edx
// 00615926  50                   push eax
// 00615927  8bc5                 mov eax, ebp
// 00615929  8bce                 mov ecx, esi
// 0061592b  e880f4ffff           call 0x614db0
// 00615930  83c40c               add esp, 0xc
// 00615933  5f                   pop edi
// 00615934  894308               mov dword ptr [ebx + 8], eax
// 00615937  c7030a000000         mov dword ptr [ebx], 0xa
// 0061593d  5d                   pop ebp
// 0061593e  c3                   ret 
// library lua-5.1.1/lcode.c (function _codecomp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c

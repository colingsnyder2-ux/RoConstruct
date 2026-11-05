// from server: 100% by auto
// roc 2010-06 007e0300  unit: CXTPReportRecordItemVariant  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e0300
//
// 007e0300  83ec10               sub esp, 0x10
// 007e0303  83790800             cmp dword ptr [ecx + 8], 0
// 007e0307  56                   push esi
// 007e0308  757e                 jne 0x7e0388
// 007e030a  8b742418             mov esi, dword ptr [esp + 0x18]
// 007e030e  837e0800             cmp dword ptr [esi + 8], 0
// 007e0312  7574                 jne 0x7e0388
// 007e0314  dd01                 fld qword ptr [ecx]
// 007e0316  dd542404             fst qword ptr [esp + 4]
// 007e031a  d9ee                 fldz 
// 007e031c  d8d9                 fcomp st(1)
// 007e031e  dfe0                 fnstsw ax
// 007e0320  f6c441               test ah, 0x41
// 007e0323  7b17                 jnp 0x7e033c
// 007e0325  83ec08               sub esp, 8
// 007e0328  dd1c24               fstp qword ptr [esp]
// 007e032b  ff1554a79e00         call dword ptr [0x9ea754]
// 007e0331  dd44240c             fld qword ptr [esp + 0xc]
// 007e0335  83c408               add esp, 8
// 007e0338  d8e1                 fsub st(1)
// 007e033a  dee9                 fsubp st(1)
// 007e033c  dd5c2404             fstp qword ptr [esp + 4]
// 007e0340  dd06                 fld qword ptr [esi]
// 007e0342  dd54240c             fst qword ptr [esp + 0xc]
// 007e0346  d9ee                 fldz 
// 007e0348  d8d9                 fcomp st(1)
// 007e034a  dfe0                 fnstsw ax
// 007e034c  f6c441               test ah, 0x41
// 007e034f  7b17                 jnp 0x7e0368
// 007e0351  83ec08               sub esp, 8
// 007e0354  dd1c24               fstp qword ptr [esp]
// 007e0357  ff1554a79e00         call dword ptr [0x9ea754]
// 007e035d  dd442414             fld qword ptr [esp + 0x14]
// 007e0361  83c408               add esp, 8
// 007e0364  d8e1                 fsub st(1)
// 007e0366  dee9                 fsubp st(1)
// 007e0368  dc5c2404             fcomp qword ptr [esp + 4]
// 007e036c  dfe0                 fnstsw ax
// 007e036e  f6c405               test ah, 5
// 007e0371  7a0c                 jp 0x7e037f
// 007e0373  b801000000           mov eax, 1
// 007e0378  5e                   pop esi
// 007e0379  83c410               add esp, 0x10
// 007e037c  c20400               ret 4
// 007e037f  33c0                 xor eax, eax
// 007e0381  5e                   pop esi
// 007e0382  83c410               add esp, 0x10
// 007e0385  c20400               ret 4
// 007e0388  32c0                 xor al, al
// 007e038a  5e                   pop esi
// 007e038b  83c410               add esp, 0x10
// 007e038e  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarController.cpp (function ??OCOleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarController.cpp

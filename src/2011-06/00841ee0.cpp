// from server: 100% by auto
// roc 2011-06 00841ee0  unit: CXTPReportRecordItemVariant  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00841ee0
//
// 00841ee0  83ec10               sub esp, 0x10
// 00841ee3  83790800             cmp dword ptr [ecx + 8], 0
// 00841ee7  56                   push esi
// 00841ee8  757e                 jne 0x841f68
// 00841eea  8b742418             mov esi, dword ptr [esp + 0x18]
// 00841eee  837e0800             cmp dword ptr [esi + 8], 0
// 00841ef2  7574                 jne 0x841f68
// 00841ef4  dd01                 fld qword ptr [ecx]
// 00841ef6  dd542404             fst qword ptr [esp + 4]
// 00841efa  d9ee                 fldz 
// 00841efc  d8d9                 fcomp st(1)
// 00841efe  dfe0                 fnstsw ax
// 00841f00  f6c441               test ah, 0x41
// 00841f03  7b17                 jnp 0x841f1c
// 00841f05  83ec08               sub esp, 8
// 00841f08  dd1c24               fstp qword ptr [esp]
// 00841f0b  ff156409a400         call dword ptr [0xa40964]
// 00841f11  dd44240c             fld qword ptr [esp + 0xc]
// 00841f15  83c408               add esp, 8
// 00841f18  d8e1                 fsub st(1)
// 00841f1a  dee9                 fsubp st(1)
// 00841f1c  dd5c2404             fstp qword ptr [esp + 4]
// 00841f20  dd06                 fld qword ptr [esi]
// 00841f22  dd54240c             fst qword ptr [esp + 0xc]
// 00841f26  d9ee                 fldz 
// 00841f28  d8d9                 fcomp st(1)
// 00841f2a  dfe0                 fnstsw ax
// 00841f2c  f6c441               test ah, 0x41
// 00841f2f  7b17                 jnp 0x841f48
// 00841f31  83ec08               sub esp, 8
// 00841f34  dd1c24               fstp qword ptr [esp]
// 00841f37  ff156409a400         call dword ptr [0xa40964]
// 00841f3d  dd442414             fld qword ptr [esp + 0x14]
// 00841f41  83c408               add esp, 8
// 00841f44  d8e1                 fsub st(1)
// 00841f46  dee9                 fsubp st(1)
// 00841f48  dc5c2404             fcomp qword ptr [esp + 4]
// 00841f4c  dfe0                 fnstsw ax
// 00841f4e  f6c405               test ah, 5
// 00841f51  7a0c                 jp 0x841f5f
// 00841f53  b801000000           mov eax, 1
// 00841f58  5e                   pop esi
// 00841f59  83c410               add esp, 0x10
// 00841f5c  c20400               ret 4
// 00841f5f  33c0                 xor eax, eax
// 00841f61  5e                   pop esi
// 00841f62  83c410               add esp, 0x10
// 00841f65  c20400               ret 4
// 00841f68  32c0                 xor al, al
// 00841f6a  5e                   pop esi
// 00841f6b  83c410               add esp, 0x10
// 00841f6e  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarControlView.cpp (function ??OCOleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarControlView.cpp

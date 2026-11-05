// from server: 100% by auto
// roc 2010-06 00410fd0  unit: CRbxChildFrame  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00410fd0
//
// 00410fd0  0fb7442408           movzx eax, word ptr [esp + 8]
// 00410fd5  83c0fe               add eax, -2
// 00410fd8  83f809               cmp eax, 9
// 00410fdb  7731                 ja 0x41100e
// 00410fdd  0fb68020104100       movzx eax, byte ptr [eax + 0x411020]
// 00410fe4  ff248514104100       jmp dword ptr [eax*4 + 0x411014]
// 00410feb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00410fef  51                   push ecx
// 00410ff0  e89bffffff           call 0x410f90
// 00410ff5  83c404               add esp, 4
// 00410ff8  84c0                 test al, al
// 00410ffa  7406                 je 0x411002
// 00410ffc  b81d000000           mov eax, 0x1d
// 00411001  c3                   ret 
// 00411002  b81c000000           mov eax, 0x1c
// 00411007  c3                   ret 
// 00411008  b81e000000           mov eax, 0x1e
// 0041100d  c3                   ret 
// 0041100e  b81f000000           mov eax, 0x1f
// 00411013  c3                   ret 
// 00411014  eb0f                 jmp 0x411025
// 00411016  41                   inc ecx
// 00411017  0008                 add byte ptr [eax], cl
// 00411019  104100               adc byte ptr [ecx], al
// 0041101c  0e                   push cs
// 0041101d  104100               adc byte ptr [ecx], al
// 00411020  0002                 add byte ptr [edx], al
// 00411022  0102                 add dword ptr [edx], eax
// 00411024  0102                 add dword ptr [edx], eax
// 00411026  0201                 add al, byte ptr [ecx]
// 00411028  0201                 add al, byte ptr [ecx]
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?end_of_month_day@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAGVgreg_year@gregorian@3@Vgreg_month@53@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

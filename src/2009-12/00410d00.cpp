// from server: 100% by auto
// roc 2009-12 00410d00  unit: CRbxChildFrame  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410d00
//
// 00410d00  0fb7442408           movzx eax, word ptr [esp + 8]
// 00410d05  83c0fe               add eax, -2
// 00410d08  83f809               cmp eax, 9
// 00410d0b  7731                 ja 0x410d3e
// 00410d0d  0fb680500d4100       movzx eax, byte ptr [eax + 0x410d50]
// 00410d14  ff2485440d4100       jmp dword ptr [eax*4 + 0x410d44]
// 00410d1b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00410d1f  51                   push ecx
// 00410d20  e89bffffff           call 0x410cc0
// 00410d25  83c404               add esp, 4
// 00410d28  84c0                 test al, al
// 00410d2a  7406                 je 0x410d32
// 00410d2c  b81d000000           mov eax, 0x1d
// 00410d31  c3                   ret 
// 00410d32  b81c000000           mov eax, 0x1c
// 00410d37  c3                   ret 
// 00410d38  b81e000000           mov eax, 0x1e
// 00410d3d  c3                   ret 
// 00410d3e  b81f000000           mov eax, 0x1f
// 00410d43  c3                   ret 
// 00410d44  1b0d4100380d         sbb ecx, dword ptr [0xd380041]
// 00410d4a  41                   inc ecx
// 00410d4b  003e                 add byte ptr [esi], bh
// 00410d4d  0d41000002           or eax, 0x2000041
// 00410d52  0102                 add dword ptr [edx], eax
// 00410d54  0102                 add dword ptr [edx], eax
// 00410d56  0201                 add al, byte ptr [ecx]
// 00410d58  0201                 add al, byte ptr [ecx]
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?end_of_month_day@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAGVgreg_year@gregorian@3@Vgreg_month@53@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

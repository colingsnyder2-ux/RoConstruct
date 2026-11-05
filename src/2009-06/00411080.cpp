// from server: 100% by auto
// roc 2009-06 00411080  unit: CRbxChildFrame  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411080
//
// 00411080  0fb7442408           movzx eax, word ptr [esp + 8]
// 00411085  83c0fe               add eax, -2
// 00411088  83f809               cmp eax, 9
// 0041108b  7731                 ja 0x4110be
// 0041108d  0fb680d0104100       movzx eax, byte ptr [eax + 0x4110d0]
// 00411094  ff2485c4104100       jmp dword ptr [eax*4 + 0x4110c4]
// 0041109b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041109f  51                   push ecx
// 004110a0  e89bffffff           call 0x411040
// 004110a5  83c404               add esp, 4
// 004110a8  84c0                 test al, al
// 004110aa  7406                 je 0x4110b2
// 004110ac  b81d000000           mov eax, 0x1d
// 004110b1  c3                   ret 
// 004110b2  b81c000000           mov eax, 0x1c
// 004110b7  c3                   ret 
// 004110b8  b81e000000           mov eax, 0x1e
// 004110bd  c3                   ret 
// 004110be  b81f000000           mov eax, 0x1f
// 004110c3  c3                   ret 
// 004110c4  9b                   wait 
// 004110c5  104100               adc byte ptr [ecx], al
// 004110c8  b8104100be           mov eax, 0xbe004110
// 004110cd  104100               adc byte ptr [ecx], al
// 004110d0  0002                 add byte ptr [edx], al
// 004110d2  0102                 add dword ptr [edx], eax
// 004110d4  0102                 add dword ptr [edx], eax
// 004110d6  0201                 add al, byte ptr [ecx]
// 004110d8  0201                 add al, byte ptr [ecx]
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?end_of_month_day@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAGVgreg_year@gregorian@3@Vgreg_month@53@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

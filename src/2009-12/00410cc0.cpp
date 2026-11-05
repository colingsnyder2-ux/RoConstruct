// from server: 100% by auto
// roc 2009-12 00410cc0  unit: CRbxChildFrame  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410cc0
//
// 00410cc0  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 00410cc5  8bc1                 mov eax, ecx
// 00410cc7  2503000080           and eax, 0x80000003
// 00410ccc  7905                 jns 0x410cd3
// 00410cce  48                   dec eax
// 00410ccf  83c8fc               or eax, 0xfffffffc
// 00410cd2  40                   inc eax
// 00410cd3  7524                 jne 0x410cf9
// 00410cd5  8bc1                 mov eax, ecx
// 00410cd7  56                   push esi
// 00410cd8  99                   cdq 
// 00410cd9  be64000000           mov esi, 0x64
// 00410cde  f7fe                 idiv esi
// 00410ce0  5e                   pop esi
// 00410ce1  85d2                 test edx, edx
// 00410ce3  750e                 jne 0x410cf3
// 00410ce5  8bc1                 mov eax, ecx
// 00410ce7  99                   cdq 
// 00410ce8  b990010000           mov ecx, 0x190
// 00410ced  f7f9                 idiv ecx
// 00410cef  85d2                 test edx, edx
// 00410cf1  7506                 jne 0x410cf9
// 00410cf3  b801000000           mov eax, 1
// 00410cf8  c3                   ret 
// 00410cf9  33c0                 xor eax, eax
// 00410cfb  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_leap_year@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SA_NVgreg_year@gregorian@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

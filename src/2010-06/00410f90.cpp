// from server: 100% by auto
// roc 2010-06 00410f90  unit: CRbxChildFrame  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00410f90
//
// 00410f90  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 00410f95  8bc1                 mov eax, ecx
// 00410f97  2503000080           and eax, 0x80000003
// 00410f9c  7905                 jns 0x410fa3
// 00410f9e  48                   dec eax
// 00410f9f  83c8fc               or eax, 0xfffffffc
// 00410fa2  40                   inc eax
// 00410fa3  7524                 jne 0x410fc9
// 00410fa5  8bc1                 mov eax, ecx
// 00410fa7  56                   push esi
// 00410fa8  99                   cdq 
// 00410fa9  be64000000           mov esi, 0x64
// 00410fae  f7fe                 idiv esi
// 00410fb0  5e                   pop esi
// 00410fb1  85d2                 test edx, edx
// 00410fb3  750e                 jne 0x410fc3
// 00410fb5  8bc1                 mov eax, ecx
// 00410fb7  99                   cdq 
// 00410fb8  b990010000           mov ecx, 0x190
// 00410fbd  f7f9                 idiv ecx
// 00410fbf  85d2                 test edx, edx
// 00410fc1  7506                 jne 0x410fc9
// 00410fc3  b801000000           mov eax, 1
// 00410fc8  c3                   ret 
// 00410fc9  33c0                 xor eax, eax
// 00410fcb  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_leap_year@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SA_NVgreg_year@gregorian@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

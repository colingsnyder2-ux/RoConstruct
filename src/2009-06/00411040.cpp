// from server: 100% by auto
// roc 2009-06 00411040  unit: CRbxChildFrame  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411040
//
// 00411040  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 00411045  8bc1                 mov eax, ecx
// 00411047  2503000080           and eax, 0x80000003
// 0041104c  7905                 jns 0x411053
// 0041104e  48                   dec eax
// 0041104f  83c8fc               or eax, 0xfffffffc
// 00411052  40                   inc eax
// 00411053  7524                 jne 0x411079
// 00411055  8bc1                 mov eax, ecx
// 00411057  56                   push esi
// 00411058  99                   cdq 
// 00411059  be64000000           mov esi, 0x64
// 0041105e  f7fe                 idiv esi
// 00411060  5e                   pop esi
// 00411061  85d2                 test edx, edx
// 00411063  750e                 jne 0x411073
// 00411065  8bc1                 mov eax, ecx
// 00411067  99                   cdq 
// 00411068  b990010000           mov ecx, 0x190
// 0041106d  f7f9                 idiv ecx
// 0041106f  85d2                 test edx, edx
// 00411071  7506                 jne 0x411079
// 00411073  b801000000           mov eax, 1
// 00411078  c3                   ret 
// 00411079  33c0                 xor eax, eax
// 0041107b  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_leap_year@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SA_NVgreg_year@gregorian@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

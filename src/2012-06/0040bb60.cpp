// from server: 100% by auto
// roc 2012-06 0040bb60  unit: boost::exception_detail::clone_base  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040bb60
//
// 0040bb60  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 0040bb65  8bc1                 mov eax, ecx
// 0040bb67  2503000080           and eax, 0x80000003
// 0040bb6c  7905                 jns 0x40bb73
// 0040bb6e  48                   dec eax
// 0040bb6f  83c8fc               or eax, 0xfffffffc
// 0040bb72  40                   inc eax
// 0040bb73  7524                 jne 0x40bb99
// 0040bb75  8bc1                 mov eax, ecx
// 0040bb77  56                   push esi
// 0040bb78  99                   cdq 
// 0040bb79  be64000000           mov esi, 0x64
// 0040bb7e  f7fe                 idiv esi
// 0040bb80  5e                   pop esi
// 0040bb81  85d2                 test edx, edx
// 0040bb83  750e                 jne 0x40bb93
// 0040bb85  8bc1                 mov eax, ecx
// 0040bb87  99                   cdq 
// 0040bb88  b990010000           mov ecx, 0x190
// 0040bb8d  f7f9                 idiv ecx
// 0040bb8f  85d2                 test edx, edx
// 0040bb91  7506                 jne 0x40bb99
// 0040bb93  b801000000           mov eax, 1
// 0040bb98  c3                   ret 
// 0040bb99  33c0                 xor eax, eax
// 0040bb9b  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_leap_year@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SA_NVgreg_year@gregorian@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

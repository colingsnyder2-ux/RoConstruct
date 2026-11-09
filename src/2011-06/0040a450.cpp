// from server: 100% by auto
// roc 2011-06 0040a450  unit: boost::exception_detail::clone_base  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040a450
//
// 0040a450  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 0040a455  8bc1                 mov eax, ecx
// 0040a457  2503000080           and eax, 0x80000003
// 0040a45c  7905                 jns 0x40a463
// 0040a45e  48                   dec eax
// 0040a45f  83c8fc               or eax, 0xfffffffc
// 0040a462  40                   inc eax
// 0040a463  7524                 jne 0x40a489
// 0040a465  8bc1                 mov eax, ecx
// 0040a467  56                   push esi
// 0040a468  99                   cdq 
// 0040a469  be64000000           mov esi, 0x64
// 0040a46e  f7fe                 idiv esi
// 0040a470  5e                   pop esi
// 0040a471  85d2                 test edx, edx
// 0040a473  750e                 jne 0x40a483
// 0040a475  8bc1                 mov eax, ecx
// 0040a477  99                   cdq 
// 0040a478  b990010000           mov ecx, 0x190
// 0040a47d  f7f9                 idiv ecx
// 0040a47f  85d2                 test edx, edx
// 0040a481  7506                 jne 0x40a489
// 0040a483  b801000000           mov eax, 1
// 0040a488  c3                   ret 
// 0040a489  33c0                 xor eax, eax
// 0040a48b  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_leap_year@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SA_NVgreg_year@gregorian@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

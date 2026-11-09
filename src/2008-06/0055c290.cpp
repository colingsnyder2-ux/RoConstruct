// from server: 100% by auto
// roc 2008-06 0055c290  unit: RBX::VInstance::?$SignalDesc  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c290
//
// 0055c290  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 0055c295  8bc1                 mov eax, ecx
// 0055c297  2503000080           and eax, 0x80000003
// 0055c29c  7905                 jns 0x55c2a3
// 0055c29e  48                   dec eax
// 0055c29f  83c8fc               or eax, 0xfffffffc
// 0055c2a2  40                   inc eax
// 0055c2a3  7524                 jne 0x55c2c9
// 0055c2a5  8bc1                 mov eax, ecx
// 0055c2a7  56                   push esi
// 0055c2a8  99                   cdq 
// 0055c2a9  be64000000           mov esi, 0x64
// 0055c2ae  f7fe                 idiv esi
// 0055c2b0  5e                   pop esi
// 0055c2b1  85d2                 test edx, edx
// 0055c2b3  750e                 jne 0x55c2c3
// 0055c2b5  8bc1                 mov eax, ecx
// 0055c2b7  99                   cdq 
// 0055c2b8  b990010000           mov ecx, 0x190
// 0055c2bd  f7f9                 idiv ecx
// 0055c2bf  85d2                 test edx, edx
// 0055c2c1  7506                 jne 0x55c2c9
// 0055c2c3  b801000000           mov eax, 1
// 0055c2c8  c3                   ret 
// 0055c2c9  33c0                 xor eax, eax
// 0055c2cb  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_leap_year@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SA_NVgreg_year@gregorian@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

// from server: 100% by auto
// roc 2007-08 005346e0  unit: RBX::ScriptContext  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005346e0
//
// 005346e0  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 005346e5  8bc1                 mov eax, ecx
// 005346e7  2503000080           and eax, 0x80000003
// 005346ec  7905                 jns 0x5346f3
// 005346ee  48                   dec eax
// 005346ef  83c8fc               or eax, 0xfffffffc
// 005346f2  40                   inc eax
// 005346f3  7524                 jne 0x534719
// 005346f5  8bc1                 mov eax, ecx
// 005346f7  56                   push esi
// 005346f8  99                   cdq 
// 005346f9  be64000000           mov esi, 0x64
// 005346fe  f7fe                 idiv esi
// 00534700  5e                   pop esi
// 00534701  85d2                 test edx, edx
// 00534703  750e                 jne 0x534713
// 00534705  8bc1                 mov eax, ecx
// 00534707  99                   cdq 
// 00534708  b990010000           mov ecx, 0x190
// 0053470d  f7f9                 idiv ecx
// 0053470f  85d2                 test edx, edx
// 00534711  7506                 jne 0x534719
// 00534713  b801000000           mov eax, 1
// 00534718  c3                   ret 
// 00534719  33c0                 xor eax, eax
// 0053471b  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_leap_year@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SA_NVgreg_year@gregorian@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

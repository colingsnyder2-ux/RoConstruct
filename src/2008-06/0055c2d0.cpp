// from server: 100% by auto
// roc 2008-06 0055c2d0  unit: RBX::VInstance::?$SignalDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c2d0
//
// 0055c2d0  0fb7442408           movzx eax, word ptr [esp + 8]
// 0055c2d5  83c0fe               add eax, -2
// 0055c2d8  83f809               cmp eax, 9
// 0055c2db  7731                 ja 0x55c30e
// 0055c2dd  0fb68020c35500       movzx eax, byte ptr [eax + 0x55c320]
// 0055c2e4  ff248514c35500       jmp dword ptr [eax*4 + 0x55c314]
// 0055c2eb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055c2ef  51                   push ecx
// 0055c2f0  e89bffffff           call 0x55c290
// 0055c2f5  83c404               add esp, 4
// 0055c2f8  84c0                 test al, al
// 0055c2fa  7406                 je 0x55c302
// 0055c2fc  b81d000000           mov eax, 0x1d
// 0055c301  c3                   ret 
// 0055c302  b81c000000           mov eax, 0x1c
// 0055c307  c3                   ret 
// 0055c308  b81e000000           mov eax, 0x1e
// 0055c30d  c3                   ret 
// 0055c30e  b81f000000           mov eax, 0x1f
// 0055c313  c3                   ret 
// 0055c314  ebc2                 jmp 0x55c2d8
// 0055c316  55                   push ebp
// 0055c317  0008                 add byte ptr [eax], cl
// 0055c319  c3                   ret 
// 0055c31a  55                   push ebp
// 0055c31b  000e                 add byte ptr [esi], cl
// 0055c31d  c3                   ret 
// 0055c31e  55                   push ebp
// 0055c31f  0000                 add byte ptr [eax], al
// 0055c321  0201                 add al, byte ptr [ecx]
// 0055c323  0201                 add al, byte ptr [ecx]
// 0055c325  0202                 add al, byte ptr [edx]
// 0055c327  0102                 add dword ptr [edx], eax
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?end_of_month_day@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAGVgreg_year@gregorian@3@Vgreg_month@53@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp

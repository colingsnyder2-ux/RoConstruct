// from server: 100% by auto
// roc 2007-03 00722490  unit: seg_00720000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00722490
//
// 00722490  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 00722493  85c0                 test eax, eax
// 00722495  7406                 je 0x72249d
// 00722497  83780400             cmp dword ptr [eax + 4], 0
// 0072249b  7523                 jne 0x7224c0
// 0072249d  8b442404             mov eax, dword ptr [esp + 4]
// 007224a1  85c0                 test eax, eax
// 007224a3  7419                 je 0x7224be
// 007224a5  8b4020               mov eax, dword ptr [eax + 0x20]
// 007224a8  6a00                 push 0
// 007224aa  6a00                 push 0
// 007224ac  6a31                 push 0x31
// 007224ae  50                   push eax
// 007224af  ff1550ee7700         call dword ptr [0x77ee50]
// 007224b5  89442404             mov dword ptr [esp + 4], eax
// 007224b9  e90ec2efff           jmp 0x61e6cc
// 007224be  33c0                 xor eax, eax
// 007224c0  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetThemeFont@CXTButtonTheme@@UBEPAVCFont@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp

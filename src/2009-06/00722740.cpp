// from server: 100% by auto
// roc 2009-06 00722740  unit: CRobloxControlColorSelector  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00722740
//
// 00722740  8b8158040000         mov eax, dword ptr [ecx + 0x458]
// 00722746  83f807               cmp eax, 7
// 00722749  751f                 jne 0x72276a
// 0072274b  e8d0230300           call 0x754b20
// 00722750  8bc8                 mov ecx, eax
// 00722752  e8291e0300           call 0x754580
// 00722757  85c0                 test eax, eax
// 00722759  7403                 je 0x72275e
// 0072275b  33c0                 xor eax, eax
// 0072275d  c3                   ret 
// 0072275e  e8bd230300           call 0x754b20
// 00722763  8bc8                 mov ecx, eax
// 00722765  e966210300           jmp 0x7548d0
// 0072276a  83f806               cmp eax, 6
// 0072276d  75ee                 jne 0x72275d
// 0072276f  e8ac230300           call 0x754b20
// 00722774  8bc8                 mov ecx, eax
// 00722776  e9151e0300           jmp 0x754590
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GetCurrentSystemTheme@CXTPPaintManager@@QAE?AW4XTPCurrentSystemTheme@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp

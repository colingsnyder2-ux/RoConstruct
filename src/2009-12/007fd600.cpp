// from server: 100% by auto
// roc 2009-12 007fd600  unit: CXTPControlComboBoxAutoCompleteWnd  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fd600
//
// 007fd600  8b8158040000         mov eax, dword ptr [ecx + 0x458]
// 007fd606  83f807               cmp eax, 7
// 007fd609  751f                 jne 0x7fd62a
// 007fd60b  e8c0230300           call 0x82f9d0
// 007fd610  8bc8                 mov ecx, eax
// 007fd612  e8c91d0300           call 0x82f3e0
// 007fd617  85c0                 test eax, eax
// 007fd619  7403                 je 0x7fd61e
// 007fd61b  33c0                 xor eax, eax
// 007fd61d  c3                   ret 
// 007fd61e  e8ad230300           call 0x82f9d0
// 007fd623  8bc8                 mov ecx, eax
// 007fd625  e906210300           jmp 0x82f730
// 007fd62a  83f806               cmp eax, 6
// 007fd62d  75ee                 jne 0x7fd61d
// 007fd62f  e89c230300           call 0x82f9d0
// 007fd634  8bc8                 mov ecx, eax
// 007fd636  e9b51d0300           jmp 0x82f3f0
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GetCurrentSystemTheme@CXTPPaintManager@@QAE?AW4XTPCurrentSystemTheme@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp

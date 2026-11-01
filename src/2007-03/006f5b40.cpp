// from server: 100% by auto
// roc 2007-03 006f5b40  unit: seg_006f0000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f5b40
//
// 006f5b40  8b442404             mov eax, dword ptr [esp + 4]
// 006f5b44  85c0                 test eax, eax
// 006f5b46  7508                 jne 0x6f5b50
// 006f5b48  b805400080           mov eax, 0x80004005
// 006f5b4d  c21c00               ret 0x1c
// 006f5b50  50                   push eax
// 006f5b51  e87abcf8ff           call 0x6817d0
// 006f5b56  8bc8                 mov ecx, eax
// 006f5b58  e813adf8ff           call 0x680870
// 006f5b5d  85c0                 test eax, eax
// 006f5b5f  74e7                 je 0x6f5b48
// 006f5b61  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006f5b65  8b542418             mov edx, dword ptr [esp + 0x18]
// 006f5b69  51                   push ecx
// 006f5b6a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006f5b6e  52                   push edx
// 006f5b6f  8b542418             mov edx, dword ptr [esp + 0x18]
// 006f5b73  51                   push ecx
// 006f5b74  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006f5b78  52                   push edx
// 006f5b79  51                   push ecx
// 006f5b7a  8bc8                 mov ecx, eax
// 006f5b7c  e83fbff8ff           call 0x681ac0
// 006f5b81  f7d8                 neg eax
// 006f5b83  1bc0                 sbb eax, eax
// 006f5b85  25fbbfff7f           and eax, 0x7fffbffb
// 006f5b8a  0505400080           add eax, 0x80004005
// 006f5b8f  c21c00               ret 0x1c
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerApiHook.cpp (function ?OnHookGetThemePartSize@CXTPSkinManagerApiHook@@CGJPAXPAUHDC__@@HHPAUtagRECT@@W4THEMESIZE@@PAUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerApiHook.cpp

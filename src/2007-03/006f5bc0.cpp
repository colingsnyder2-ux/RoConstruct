// from server: 100% by auto
// roc 2007-03 006f5bc0  unit: seg_006f0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f5bc0
//
// 006f5bc0  8b442408             mov eax, dword ptr [esp + 8]
// 006f5bc4  50                   push eax
// 006f5bc5  e806bcf8ff           call 0x6817d0
// 006f5bca  8bc8                 mov ecx, eax
// 006f5bcc  e86faaf8ff           call 0x680640
// 006f5bd1  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerApiHook.cpp (function ?OnHookGetThemeSysBool@CXTPSkinManagerApiHook@@CGHPAXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerApiHook.cpp

// from server: 100% by auto
// roc 2007-03 00681990  unit: seg_00680000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00681990
//
// 00681990  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00681994  8b542408             mov edx, dword ptr [esp + 8]
// 00681998  50                   push eax
// 00681999  8b442408             mov eax, dword ptr [esp + 8]
// 0068199d  52                   push edx
// 0068199e  50                   push eax
// 0068199f  6a02                 push 2
// 006819a1  e8aafeffff           call 0x681850
// 006819a6  85c0                 test eax, eax
// 006819a8  7507                 jne 0x6819b1
// 006819aa  8b442410             mov eax, dword ptr [esp + 0x10]
// 006819ae  c21000               ret 0x10
// 006819b1  8b4008               mov eax, dword ptr [eax + 8]
// 006819b4  c21000               ret 0x10
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ?GetThemeInt@CXTPSkinManagerClass@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp

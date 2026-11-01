// from server: 100% by auto
// roc 2007-03 00681a40  unit: seg_00680000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00681a40
//
// 00681a40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00681a44  8b542408             mov edx, dword ptr [esp + 8]
// 00681a48  50                   push eax
// 00681a49  8b442408             mov eax, dword ptr [esp + 8]
// 00681a4d  52                   push edx
// 00681a4e  50                   push eax
// 00681a4f  6a08                 push 8
// 00681a51  e8fafdffff           call 0x681850
// 00681a56  85c0                 test eax, eax
// 00681a58  7507                 jne 0x681a61
// 00681a5a  8b442410             mov eax, dword ptr [esp + 0x10]
// 00681a5e  c21000               ret 0x10
// 00681a61  8b4008               mov eax, dword ptr [eax + 8]
// 00681a64  c21000               ret 0x10
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ?GetThemeEnumValue@CXTPSkinManagerClass@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp

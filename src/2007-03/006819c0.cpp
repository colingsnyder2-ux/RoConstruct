// from server: 100% by auto
// roc 2007-03 006819c0  unit: seg_00680000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006819c0
//
// 006819c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006819c4  8b542408             mov edx, dword ptr [esp + 8]
// 006819c8  50                   push eax
// 006819c9  8b442408             mov eax, dword ptr [esp + 8]
// 006819cd  52                   push edx
// 006819ce  50                   push eax
// 006819cf  6a03                 push 3
// 006819d1  e87afeffff           call 0x681850
// 006819d6  85c0                 test eax, eax
// 006819d8  7507                 jne 0x6819e1
// 006819da  8b442410             mov eax, dword ptr [esp + 0x10]
// 006819de  c21000               ret 0x10
// 006819e1  8b4008               mov eax, dword ptr [eax + 8]
// 006819e4  c21000               ret 0x10
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ?GetThemeBool@CXTPSkinManagerClass@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp

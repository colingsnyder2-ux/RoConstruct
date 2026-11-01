// from server: 100% by auto
// roc 2007-03 00681a70  unit: seg_00680000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00681a70
//
// 00681a70  8b442410             mov eax, dword ptr [esp + 0x10]
// 00681a74  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00681a78  50                   push eax
// 00681a79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00681a7d  52                   push edx
// 00681a7e  50                   push eax
// 00681a7f  6a09                 push 9
// 00681a81  e8cafdffff           call 0x681850
// 00681a86  85c0                 test eax, eax
// 00681a88  7514                 jne 0x681a9e
// 00681a8a  8b442404             mov eax, dword ptr [esp + 4]
// 00681a8e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00681a92  8b542418             mov edx, dword ptr [esp + 0x18]
// 00681a96  8908                 mov dword ptr [eax], ecx
// 00681a98  895004               mov dword ptr [eax + 4], edx
// 00681a9b  c21800               ret 0x18
// 00681a9e  8b5008               mov edx, dword ptr [eax + 8]
// 00681aa1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00681aa5  8b400c               mov eax, dword ptr [eax + 0xc]
// 00681aa8  894104               mov dword ptr [ecx + 4], eax
// 00681aab  8911                 mov dword ptr [ecx], edx
// 00681aad  8bc1                 mov eax, ecx
// 00681aaf  c21800               ret 0x18
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ?GetThemeSize@CXTPSkinManagerClass@@QAE?AVCSize@@HHHV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp

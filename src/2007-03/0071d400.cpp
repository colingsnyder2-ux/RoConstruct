// from server: 100% by auto
// roc 2007-03 0071d400  unit: seg_00710000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071d400
//
// 0071d400  83ec10               sub esp, 0x10
// 0071d403  51                   push ecx
// 0071d404  8d4c2404             lea ecx, [esp + 4]
// 0071d408  e853e4f4ff           call 0x66b860
// 0071d40d  6a02                 push 2
// 0071d40f  ff15bced7700         call dword ptr [0x77edbc]
// 0071d415  8b542408             mov edx, dword ptr [esp + 8]
// 0071d419  8bca                 mov ecx, edx
// 0071d41b  2bc8                 sub ecx, eax
// 0071d41d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0071d421  8908                 mov dword ptr [eax], ecx
// 0071d423  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071d427  894804               mov dword ptr [eax + 4], ecx
// 0071d42a  895008               mov dword ptr [eax + 8], edx
// 0071d42d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0071d431  89500c               mov dword ptr [eax + 0xc], edx
// 0071d434  83c410               add esp, 0x10
// 0071d437  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectComboBox.cpp (function ?GetButtonRect@CXTPSkinObjectDateTime@@QAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectComboBox.cpp

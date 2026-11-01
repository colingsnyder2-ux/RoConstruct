// from server: 100% by auto
// roc 2007-03 0071bf20  unit: seg_00710000  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071bf20
//
// 0071bf20  53                   push ebx
// 0071bf21  56                   push esi
// 0071bf22  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0071bf26  837e0400             cmp dword ptr [esi + 4], 0
// 0071bf2a  57                   push edi
// 0071bf2b  8d7e08               lea edi, [esi + 8]
// 0071bf2e  8bdf                 mov ebx, edi
// 0071bf30  740d                 je 0x71bf3f
// 0071bf32  6a09                 push 9
// 0071bf34  ff15bced7700         call dword ptr [0x77edbc]
// 0071bf3a  83c704               add edi, 4
// 0071bf3d  eb0b                 jmp 0x71bf4a
// 0071bf3f  6a0a                 push 0xa
// 0071bf41  ff15bced7700         call dword ptr [0x77edbc]
// 0071bf47  8d5f04               lea ebx, [edi + 4]
// 0071bf4a  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0071bf4d  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0071bf50  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 0071bf53  2bca                 sub ecx, edx
// 0071bf55  03c9                 add ecx, ecx
// 0071bf57  03c9                 add ecx, ecx
// 0071bf59  03c9                 add ecx, ecx
// 0071bf5b  2bd1                 sub edx, ecx
// 0071bf5d  8913                 mov dword ptr [ebx], edx
// 0071bf5f  8b5644               mov edx, dword ptr [esi + 0x44]
// 0071bf62  8b5210               mov edx, dword ptr [edx + 0x10]
// 0071bf65  03c0                 add eax, eax
// 0071bf67  2bd0                 sub edx, eax
// 0071bf69  8917                 mov dword ptr [edi], edx
// 0071bf6b  8b5644               mov edx, dword ptr [esi + 0x44]
// 0071bf6e  8b521c               mov edx, dword ptr [edx + 0x1c]
// 0071bf71  03d1                 add edx, ecx
// 0071bf73  895308               mov dword ptr [ebx + 8], edx
// 0071bf76  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0071bf79  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0071bf7c  03d0                 add edx, eax
// 0071bf7e  895708               mov dword ptr [edi + 8], edx
// 0071bf81  5f                   pop edi
// 0071bf82  5e                   pop esi
// 0071bf83  5b                   pop ebx
// 0071bf84  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectScrollBar.cpp (function ?XTPSkinCalcTrackDragRect@@YAXPAUXTP_SKINSCROLLBARTRACKINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectScrollBar.cpp

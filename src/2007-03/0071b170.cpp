// from server: 100% by auto
// roc 2007-03 0071b170  unit: seg_00710000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071b170
//
// 0071b170  83ec10               sub esp, 0x10
// 0071b173  8b442414             mov eax, dword ptr [esp + 0x14]
// 0071b177  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0071b17a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0071b17e  890424               mov dword ptr [esp], eax
// 0071b181  8d0424               lea eax, [esp]
// 0071b184  50                   push eax
// 0071b185  6a00                 push 0
// 0071b187  6806120000           push 0x1206
// 0071b18c  51                   push ecx
// 0071b18d  89542414             mov dword ptr [esp + 0x14], edx
// 0071b191  ff1550ee7700         call dword ptr [0x77ee50]
// 0071b197  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0071b19b  85c9                 test ecx, ecx
// 0071b19d  7406                 je 0x71b1a5
// 0071b19f  8b542408             mov edx, dword ptr [esp + 8]
// 0071b1a3  8911                 mov dword ptr [ecx], edx
// 0071b1a5  83c410               add esp, 0x10
// 0071b1a8  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Header\XTPHeaderCtrl.cpp (function ?HitTest@CXTPHeaderCtrl@@QBEHVCPoint@@PAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Header/XTPHeaderCtrl.cpp

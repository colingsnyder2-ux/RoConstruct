// from server: 100% by auto
// roc 2007-03 00625de0  unit: seg_00620000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625de0
//
// 00625de0  83ec08               sub esp, 8
// 00625de3  33c0                 xor eax, eax
// 00625de5  890424               mov dword ptr [esp], eax
// 00625de8  89442404             mov dword ptr [esp + 4], eax
// 00625dec  8d442404             lea eax, [esp + 4]
// 00625df0  50                   push eax
// 00625df1  8b01                 mov eax, dword ptr [ecx]
// 00625df3  8d542404             lea edx, [esp + 4]
// 00625df7  52                   push edx
// 00625df8  50                   push eax
// 00625df9  ff153cd07700         call dword ptr [0x77d03c]
// 00625dff  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00625e03  8b0c24               mov ecx, dword ptr [esp]
// 00625e06  8b542404             mov edx, dword ptr [esp + 4]
// 00625e0a  8908                 mov dword ptr [eax], ecx
// 00625e0c  895004               mov dword ptr [eax + 4], edx
// 00625e0f  83c408               add esp, 8
// 00625e12  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetIconSize@CXTPImageManagerImageList@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

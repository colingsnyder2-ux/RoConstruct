// from server: 100% by auto
// roc 2010-06 007be490  unit: CXTPImageManagerResource::CBitmapDC  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007be490
//
// 007be490  83ec08               sub esp, 8
// 007be493  33c0                 xor eax, eax
// 007be495  890424               mov dword ptr [esp], eax
// 007be498  89442404             mov dword ptr [esp + 4], eax
// 007be49c  8d442404             lea eax, [esp + 4]
// 007be4a0  50                   push eax
// 007be4a1  8b01                 mov eax, dword ptr [ecx]
// 007be4a3  8d542404             lea edx, [esp + 4]
// 007be4a7  52                   push edx
// 007be4a8  50                   push eax
// 007be4a9  ff1560a09e00         call dword ptr [0x9ea060]
// 007be4af  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007be4b3  8b0c24               mov ecx, dword ptr [esp]
// 007be4b6  8b542404             mov edx, dword ptr [esp + 4]
// 007be4ba  8908                 mov dword ptr [eax], ecx
// 007be4bc  895004               mov dword ptr [eax + 4], edx
// 007be4bf  83c408               add esp, 8
// 007be4c2  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?GetIconSize@CXTPImageManagerImageList@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp

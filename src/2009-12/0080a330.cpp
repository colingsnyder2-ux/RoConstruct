// from server: 100% by auto
// roc 2009-12 0080a330  unit: CXTPImageManagerResource::CBitmapDC  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080a330
//
// 0080a330  83ec08               sub esp, 8
// 0080a333  33c0                 xor eax, eax
// 0080a335  890424               mov dword ptr [esp], eax
// 0080a338  89442404             mov dword ptr [esp + 4], eax
// 0080a33c  8d442404             lea eax, [esp + 4]
// 0080a340  50                   push eax
// 0080a341  8b01                 mov eax, dword ptr [ecx]
// 0080a343  8d542404             lea edx, [esp + 4]
// 0080a347  52                   push edx
// 0080a348  50                   push eax
// 0080a349  ff1570b09800         call dword ptr [0x98b070]
// 0080a34f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0080a353  8b0c24               mov ecx, dword ptr [esp]
// 0080a356  8b542404             mov edx, dword ptr [esp + 4]
// 0080a35a  8908                 mov dword ptr [eax], ecx
// 0080a35c  895004               mov dword ptr [eax + 4], edx
// 0080a35f  83c408               add esp, 8
// 0080a362  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetIconSize@CXTPImageManagerImageList@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

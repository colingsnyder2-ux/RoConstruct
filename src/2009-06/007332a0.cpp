// from server: 100% by auto
// roc 2009-06 007332a0  unit: CXTPImageManagerResource::CBitmapDC  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007332a0
//
// 007332a0  83ec08               sub esp, 8
// 007332a3  33c0                 xor eax, eax
// 007332a5  890424               mov dword ptr [esp], eax
// 007332a8  89442404             mov dword ptr [esp + 4], eax
// 007332ac  8d442404             lea eax, [esp + 4]
// 007332b0  50                   push eax
// 007332b1  8b01                 mov eax, dword ptr [ecx]
// 007332b3  8d542404             lea edx, [esp + 4]
// 007332b7  52                   push edx
// 007332b8  50                   push eax
// 007332b9  ff1560e08900         call dword ptr [0x89e060]
// 007332bf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007332c3  8b0c24               mov ecx, dword ptr [esp]
// 007332c6  8b542404             mov edx, dword ptr [esp + 4]
// 007332ca  8908                 mov dword ptr [eax], ecx
// 007332cc  895004               mov dword ptr [eax + 4], edx
// 007332cf  83c408               add esp, 8
// 007332d2  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetIconSize@CXTPImageManagerImageList@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

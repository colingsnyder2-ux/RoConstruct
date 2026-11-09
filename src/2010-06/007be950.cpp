// from server: 100% by auto
// roc 2010-06 007be950  unit: CXTPImageManagerResource::CBitmapDC  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007be950
//
// 007be950  33c0                 xor eax, eax
// 007be952  33d2                 xor edx, edx
// 007be954  8901                 mov dword ptr [ecx], eax
// 007be956  894104               mov dword ptr [ecx + 4], eax
// 007be959  894108               mov dword ptr [ecx + 8], eax
// 007be95c  89410c               mov dword ptr [ecx + 0xc], eax
// 007be95f  894110               mov dword ptr [ecx + 0x10], eax
// 007be962  894114               mov dword ptr [ecx + 0x14], eax
// 007be965  895118               mov dword ptr [ecx + 0x18], edx
// 007be968  89411c               mov dword ptr [ecx + 0x1c], eax
// 007be96b  c7412001000000       mov dword ptr [ecx + 0x20], 1
// 007be972  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?Init@CXTPImageManagerIconHandle@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp

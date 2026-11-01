// from server: 100% by auto
// roc 2009-12 0080a800  unit: CXTPImageManagerResource::CBitmapDC  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080a800
//
// 0080a800  33c0                 xor eax, eax
// 0080a802  33d2                 xor edx, edx
// 0080a804  8901                 mov dword ptr [ecx], eax
// 0080a806  894104               mov dword ptr [ecx + 4], eax
// 0080a809  894108               mov dword ptr [ecx + 8], eax
// 0080a80c  89410c               mov dword ptr [ecx + 0xc], eax
// 0080a80f  894110               mov dword ptr [ecx + 0x10], eax
// 0080a812  894114               mov dword ptr [ecx + 0x14], eax
// 0080a815  895118               mov dword ptr [ecx + 0x18], edx
// 0080a818  89411c               mov dword ptr [ecx + 0x1c], eax
// 0080a81b  c7412001000000       mov dword ptr [ecx + 0x20], 1
// 0080a822  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Init@CXTPImageManagerIconHandle@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

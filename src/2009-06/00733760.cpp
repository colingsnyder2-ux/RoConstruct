// from server: 100% by auto
// roc 2009-06 00733760  unit: CXTPImageManagerResource::CBitmapDC  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00733760
//
// 00733760  33c0                 xor eax, eax
// 00733762  33d2                 xor edx, edx
// 00733764  8901                 mov dword ptr [ecx], eax
// 00733766  894104               mov dword ptr [ecx + 4], eax
// 00733769  894108               mov dword ptr [ecx + 8], eax
// 0073376c  89410c               mov dword ptr [ecx + 0xc], eax
// 0073376f  894110               mov dword ptr [ecx + 0x10], eax
// 00733772  894114               mov dword ptr [ecx + 0x14], eax
// 00733775  895118               mov dword ptr [ecx + 0x18], edx
// 00733778  89411c               mov dword ptr [ecx + 0x1c], eax
// 0073377b  c7412001000000       mov dword ptr [ecx + 0x20], 1
// 00733782  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Init@CXTPImageManagerIconHandle@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

// from server: 100% by auto
// roc 2009-12 0080a8a0  unit: CXTPImageManagerResource::CBitmapDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080a8a0
//
// 0080a8a0  833900               cmp dword ptr [ecx], 0
// 0080a8a3  750c                 jne 0x80a8b1
// 0080a8a5  83790400             cmp dword ptr [ecx + 4], 0
// 0080a8a9  7506                 jne 0x80a8b1
// 0080a8ab  83791400             cmp dword ptr [ecx + 0x14], 0
// 0080a8af  740f                 je 0x80a8c0
// 0080a8b1  83791800             cmp dword ptr [ecx + 0x18], 0
// 0080a8b5  7506                 jne 0x80a8bd
// 0080a8b7  83791c00             cmp dword ptr [ecx + 0x1c], 0
// 0080a8bb  7403                 je 0x80a8c0
// 0080a8bd  33c0                 xor eax, eax
// 0080a8bf  c3                   ret 
// 0080a8c0  b801000000           mov eax, 1
// 0080a8c5  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsEmpty@CXTPImageManagerIconHandle@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

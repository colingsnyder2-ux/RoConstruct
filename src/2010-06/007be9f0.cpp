// from server: 100% by auto
// roc 2010-06 007be9f0  unit: CXTPImageManagerResource::CBitmapDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007be9f0
//
// 007be9f0  833900               cmp dword ptr [ecx], 0
// 007be9f3  750c                 jne 0x7bea01
// 007be9f5  83790400             cmp dword ptr [ecx + 4], 0
// 007be9f9  7506                 jne 0x7bea01
// 007be9fb  83791400             cmp dword ptr [ecx + 0x14], 0
// 007be9ff  740f                 je 0x7bea10
// 007bea01  83791800             cmp dword ptr [ecx + 0x18], 0
// 007bea05  7506                 jne 0x7bea0d
// 007bea07  83791c00             cmp dword ptr [ecx + 0x1c], 0
// 007bea0b  7403                 je 0x7bea10
// 007bea0d  33c0                 xor eax, eax
// 007bea0f  c3                   ret 
// 007bea10  b801000000           mov eax, 1
// 007bea15  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?IsEmpty@CXTPImageManagerIconHandle@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp

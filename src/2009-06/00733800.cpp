// from server: 100% by auto
// roc 2009-06 00733800  unit: CXTPImageManagerResource::CBitmapDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00733800
//
// 00733800  833900               cmp dword ptr [ecx], 0
// 00733803  750c                 jne 0x733811
// 00733805  83790400             cmp dword ptr [ecx + 4], 0
// 00733809  7506                 jne 0x733811
// 0073380b  83791400             cmp dword ptr [ecx + 0x14], 0
// 0073380f  740f                 je 0x733820
// 00733811  83791800             cmp dword ptr [ecx + 0x18], 0
// 00733815  7506                 jne 0x73381d
// 00733817  83791c00             cmp dword ptr [ecx + 0x1c], 0
// 0073381b  7403                 je 0x733820
// 0073381d  33c0                 xor eax, eax
// 0073381f  c3                   ret 
// 00733820  b801000000           mov eax, 1
// 00733825  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsEmpty@CXTPImageManagerIconHandle@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

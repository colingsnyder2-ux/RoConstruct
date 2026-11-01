// from server: 100% by auto
// roc 2009-06 00733790  unit: CXTPImageManagerResource::CBitmapDC  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00733790
//
// 00733790  e8cbffffff           call 0x733760
// 00733795  8bc1                 mov eax, ecx
// 00733797  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??0CXTPImageManagerIconHandle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

// from server: 100% by auto
// roc 2010-06 007be980  unit: CXTPImageManagerResource::CBitmapDC  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007be980
//
// 007be980  e8cbffffff           call 0x7be950
// 007be985  8bc1                 mov eax, ecx
// 007be987  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ??0CXTPImageManagerIconHandle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp

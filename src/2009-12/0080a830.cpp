// from server: 100% by auto
// roc 2009-12 0080a830  unit: CXTPImageManagerResource::CBitmapDC  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080a830
//
// 0080a830  e8cbffffff           call 0x80a800
// 0080a835  8bc1                 mov eax, ecx
// 0080a837  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??0CXTPImageManagerIconHandle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

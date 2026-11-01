// from server: 100% by auto
// roc 2009-12 00810150  unit: CXTPImageManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00810150
//
// 00810150  56                   push esi
// 00810151  8bf1                 mov esi, ecx
// 00810153  57                   push edi
// 00810154  8d7e54               lea edi, [esi + 0x54]
// 00810157  8bcf                 mov ecx, edi
// 00810159  e842a7ffff           call 0x80a8a0
// 0081015e  85c0                 test eax, eax
// 00810160  7407                 je 0x810169
// 00810162  8bce                 mov ecx, esi
// 00810164  e8e7ddffff           call 0x80df50
// 00810169  8bcf                 mov ecx, edi
// 0081016b  e830a7ffff           call 0x80a8a0
// 00810170  85c0                 test eax, eax
// 00810172  8d4630               lea eax, [esi + 0x30]
// 00810175  7502                 jne 0x810179
// 00810177  8bc7                 mov eax, edi
// 00810179  5f                   pop edi
// 0081017a  5e                   pop esi
// 0081017b  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetFadedIcon@CXTPImageManagerIcon@@QAEAAVCXTPImageManagerIconHandle@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

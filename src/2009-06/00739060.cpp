// from server: 100% by auto
// roc 2009-06 00739060  unit: CXTPImageManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00739060
//
// 00739060  56                   push esi
// 00739061  8bf1                 mov esi, ecx
// 00739063  57                   push edi
// 00739064  8d7e54               lea edi, [esi + 0x54]
// 00739067  8bcf                 mov ecx, edi
// 00739069  e892a7ffff           call 0x733800
// 0073906e  85c0                 test eax, eax
// 00739070  7407                 je 0x739079
// 00739072  8bce                 mov ecx, esi
// 00739074  e8e7ddffff           call 0x736e60
// 00739079  8bcf                 mov ecx, edi
// 0073907b  e880a7ffff           call 0x733800
// 00739080  85c0                 test eax, eax
// 00739082  8d4630               lea eax, [esi + 0x30]
// 00739085  7502                 jne 0x739089
// 00739087  8bc7                 mov eax, edi
// 00739089  5f                   pop edi
// 0073908a  5e                   pop esi
// 0073908b  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetFadedIcon@CXTPImageManagerIcon@@QAEAAVCXTPImageManagerIconHandle@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

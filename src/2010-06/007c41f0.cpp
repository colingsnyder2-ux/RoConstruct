// from server: 100% by auto
// roc 2010-06 007c41f0  unit: CXTPImageManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c41f0
//
// 007c41f0  56                   push esi
// 007c41f1  8bf1                 mov esi, ecx
// 007c41f3  57                   push edi
// 007c41f4  8d7e54               lea edi, [esi + 0x54]
// 007c41f7  8bcf                 mov ecx, edi
// 007c41f9  e8f2a7ffff           call 0x7be9f0
// 007c41fe  85c0                 test eax, eax
// 007c4200  7407                 je 0x7c4209
// 007c4202  8bce                 mov ecx, esi
// 007c4204  e8e7ddffff           call 0x7c1ff0
// 007c4209  8bcf                 mov ecx, edi
// 007c420b  e8e0a7ffff           call 0x7be9f0
// 007c4210  85c0                 test eax, eax
// 007c4212  8d4630               lea eax, [esi + 0x30]
// 007c4215  7502                 jne 0x7c4219
// 007c4217  8bc7                 mov eax, edi
// 007c4219  5f                   pop edi
// 007c421a  5e                   pop esi
// 007c421b  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?GetFadedIcon@CXTPImageManagerIcon@@QAEAAVCXTPImageManagerIconHandle@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp

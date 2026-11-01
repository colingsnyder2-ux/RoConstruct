// from server: 100% by auto
// roc 2012-06 00418c90  unit: CRbxChildFrame  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00418c90
//
// 00418c90  8b442408             mov eax, dword ptr [esp + 8]
// 00418c94  56                   push esi
// 00418c95  85c0                 test eax, eax
// 00418c97  7504                 jne 0x418c9d
// 00418c99  33f6                 xor esi, esi
// 00418c9b  eb03                 jmp 0x418ca0
// 00418c9d  8b7004               mov esi, dword ptr [eax + 4]
// 00418ca0  8b442408             mov eax, dword ptr [esp + 8]
// 00418ca4  85c0                 test eax, eax
// 00418ca6  7504                 jne 0x418cac
// 00418ca8  33d2                 xor edx, edx
// 00418caa  eb03                 jmp 0x418caf
// 00418cac  8b5004               mov edx, dword ptr [eax + 4]
// 00418caf  8b4104               mov eax, dword ptr [ecx + 4]
// 00418cb2  56                   push esi
// 00418cb3  52                   push edx
// 00418cb4  50                   push eax
// 00418cb5  e818975600           call 0x9823d2
// 00418cba  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00418cc0  8b08                 mov ecx, dword ptr [eax]
// 00418cc2  e8c9fdffff           call 0x418a90
// 00418cc7  5e                   pop esi
// 00418cc8  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\Common\XTPImageManager.cpp (function ?Add@CImageList@@QAEHPAVCBitmap@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPImageManager.cpp

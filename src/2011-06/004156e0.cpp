// from server: 100% by auto
// roc 2011-06 004156e0  unit: CRbxChildFrame  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004156e0
//
// 004156e0  8b442408             mov eax, dword ptr [esp + 8]
// 004156e4  56                   push esi
// 004156e5  85c0                 test eax, eax
// 004156e7  7504                 jne 0x4156ed
// 004156e9  33f6                 xor esi, esi
// 004156eb  eb03                 jmp 0x4156f0
// 004156ed  8b7004               mov esi, dword ptr [eax + 4]
// 004156f0  8b442408             mov eax, dword ptr [esp + 8]
// 004156f4  85c0                 test eax, eax
// 004156f6  7504                 jne 0x4156fc
// 004156f8  33d2                 xor edx, edx
// 004156fa  eb03                 jmp 0x4156ff
// 004156fc  8b5004               mov edx, dword ptr [eax + 4]
// 004156ff  8b4104               mov eax, dword ptr [ecx + 4]
// 00415702  56                   push esi
// 00415703  52                   push edx
// 00415704  50                   push eax
// 00415705  e8124c3f00           call 0x80a31c
// 0041570a  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00415710  8b08                 mov ecx, dword ptr [eax]
// 00415712  e8c9fdffff           call 0x4154e0
// 00415717  5e                   pop esi
// 00415718  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\Common\XTPImageManager.cpp (function ?Add@CImageList@@QAEHPAVCBitmap@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPImageManager.cpp

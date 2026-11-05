// from server: 100% by auto
// roc 2010-06 007bc7d0  unit: CXTPCommandBar  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bc7d0
//
// 007bc7d0  8b442404             mov eax, dword ptr [esp + 4]
// 007bc7d4  668b5012             mov dx, word ptr [eax + 0x12]
// 007bc7d8  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007bc7dc  663b5112             cmp dx, word ptr [ecx + 0x12]
// 007bc7e0  7405                 je 0x7bc7e7
// 007bc7e2  33c0                 xor eax, eax
// 007bc7e4  c20800               ret 8
// 007bc7e7  668b5010             mov dx, word ptr [eax + 0x10]
// 007bc7eb  663b5110             cmp dx, word ptr [ecx + 0x10]
// 007bc7ef  75f1                 jne 0x7bc7e2
// 007bc7f1  8b5004               mov edx, dword ptr [eax + 4]
// 007bc7f4  3b5104               cmp edx, dword ptr [ecx + 4]
// 007bc7f7  75e9                 jne 0x7bc7e2
// 007bc7f9  8b4008               mov eax, dword ptr [eax + 8]
// 007bc7fc  33d2                 xor edx, edx
// 007bc7fe  3b4108               cmp eax, dword ptr [ecx + 8]
// 007bc801  0f94c2               sete dl
// 007bc804  8bc2                 mov eax, edx
// 007bc806  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?BitmapsCompatible@CXTPImageManager@@ABEHPAUtagBITMAP@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp

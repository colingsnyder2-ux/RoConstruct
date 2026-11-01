// from server: 100% by auto
// roc 2009-06 007314b0  unit: CXTPCommandBar  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007314b0
//
// 007314b0  8b442404             mov eax, dword ptr [esp + 4]
// 007314b4  668b5012             mov dx, word ptr [eax + 0x12]
// 007314b8  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007314bc  663b5112             cmp dx, word ptr [ecx + 0x12]
// 007314c0  7405                 je 0x7314c7
// 007314c2  33c0                 xor eax, eax
// 007314c4  c20800               ret 8
// 007314c7  668b5010             mov dx, word ptr [eax + 0x10]
// 007314cb  663b5110             cmp dx, word ptr [ecx + 0x10]
// 007314cf  75f1                 jne 0x7314c2
// 007314d1  8b5004               mov edx, dword ptr [eax + 4]
// 007314d4  3b5104               cmp edx, dword ptr [ecx + 4]
// 007314d7  75e9                 jne 0x7314c2
// 007314d9  8b4008               mov eax, dword ptr [eax + 8]
// 007314dc  33d2                 xor edx, edx
// 007314de  3b4108               cmp eax, dword ptr [ecx + 8]
// 007314e1  0f94c2               sete dl
// 007314e4  8bc2                 mov eax, edx
// 007314e6  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?BitmapsCompatible@CXTPImageManager@@ABEHPAUtagBITMAP@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

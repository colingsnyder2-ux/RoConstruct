// from server: 100% by auto
// roc 2009-12 00808630  unit: CXTPCommandBar  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00808630
//
// 00808630  8b442404             mov eax, dword ptr [esp + 4]
// 00808634  668b5012             mov dx, word ptr [eax + 0x12]
// 00808638  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080863c  663b5112             cmp dx, word ptr [ecx + 0x12]
// 00808640  7405                 je 0x808647
// 00808642  33c0                 xor eax, eax
// 00808644  c20800               ret 8
// 00808647  668b5010             mov dx, word ptr [eax + 0x10]
// 0080864b  663b5110             cmp dx, word ptr [ecx + 0x10]
// 0080864f  75f1                 jne 0x808642
// 00808651  8b5004               mov edx, dword ptr [eax + 4]
// 00808654  3b5104               cmp edx, dword ptr [ecx + 4]
// 00808657  75e9                 jne 0x808642
// 00808659  8b4008               mov eax, dword ptr [eax + 8]
// 0080865c  33d2                 xor edx, edx
// 0080865e  3b4108               cmp eax, dword ptr [ecx + 8]
// 00808661  0f94c2               sete dl
// 00808664  8bc2                 mov eax, edx
// 00808666  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?BitmapsCompatible@CXTPImageManager@@ABEHPAUtagBITMAP@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

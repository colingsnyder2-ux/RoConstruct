// from server: 100% by auto
// roc 2007-03 00624480  unit: seg_00620000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00624480
//
// 00624480  8b442404             mov eax, dword ptr [esp + 4]
// 00624484  668b5012             mov dx, word ptr [eax + 0x12]
// 00624488  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062448c  663b5112             cmp dx, word ptr [ecx + 0x12]
// 00624490  7405                 je 0x624497
// 00624492  33c0                 xor eax, eax
// 00624494  c20800               ret 8
// 00624497  668b5010             mov dx, word ptr [eax + 0x10]
// 0062449b  663b5110             cmp dx, word ptr [ecx + 0x10]
// 0062449f  75f1                 jne 0x624492
// 006244a1  8b5004               mov edx, dword ptr [eax + 4]
// 006244a4  3b5104               cmp edx, dword ptr [ecx + 4]
// 006244a7  75e9                 jne 0x624492
// 006244a9  8b4008               mov eax, dword ptr [eax + 8]
// 006244ac  33d2                 xor edx, edx
// 006244ae  3b4108               cmp eax, dword ptr [ecx + 8]
// 006244b1  0f94c2               sete dl
// 006244b4  8bc2                 mov eax, edx
// 006244b6  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?BitmapsCompatible@CXTPImageManager@@ABEHPAUtagBITMAP@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp

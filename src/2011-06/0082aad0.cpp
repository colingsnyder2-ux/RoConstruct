// from server: 100% by auto
// roc 2011-06 0082aad0  unit: MyXTPCommandBars  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082aad0
//
// 0082aad0  57                   push edi
// 0082aad1  8bf9                 mov edi, ecx
// 0082aad3  8b87a0000000         mov eax, dword ptr [edi + 0xa0]
// 0082aad9  50                   push eax
// 0082aada  e8711c1a00           call 0x9cc750
// 0082aadf  50                   push eax
// 0082aae0  e857f9fdff           call 0x80a43c
// 0082aae5  83c408               add esp, 8
// 0082aae8  85c0                 test eax, eax
// 0082aaea  7502                 jne 0x82aaee
// 0082aaec  5f                   pop edi
// 0082aaed  c3                   ret 
// 0082aaee  53                   push ebx
// 0082aaef  0fb75f64             movzx ebx, word ptr [edi + 0x64]
// 0082aaf3  56                   push esi
// 0082aaf4  6a00                 push 0
// 0082aaf6  8bc8                 mov ecx, eax
// 0082aaf8  e84d1c1a00           call 0x9cc74a
// 0082aafd  8bf0                 mov esi, eax
// 0082aaff  85f6                 test esi, esi
// 0082ab01  742f                 je 0x82ab32
// 0082ab03  8b06                 mov eax, dword ptr [esi]
// 0082ab05  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 0082ab0b  8bce                 mov ecx, esi
// 0082ab0d  ffd2                 call edx
// 0082ab0f  85c0                 test eax, eax
// 0082ab11  7419                 je 0x82ab2c
// 0082ab13  56                   push esi
// 0082ab14  8bcf                 mov ecx, edi
// 0082ab16  e825ffffff           call 0x82aa40
// 0082ab1b  85c0                 test eax, eax
// 0082ab1d  7504                 jne 0x82ab23
// 0082ab1f  5e                   pop esi
// 0082ab20  5b                   pop ebx
// 0082ab21  5f                   pop edi
// 0082ab22  c3                   ret 
// 0082ab23  8b5840               mov ebx, dword ptr [eax + 0x40]
// 0082ab26  5e                   pop esi
// 0082ab27  8bc3                 mov eax, ebx
// 0082ab29  5b                   pop ebx
// 0082ab2a  5f                   pop edi
// 0082ab2b  c3                   ret 
// 0082ab2c  8b9ea4000000         mov ebx, dword ptr [esi + 0xa4]
// 0082ab32  5e                   pop esi
// 0082ab33  8bc3                 mov eax, ebx
// 0082ab35  5b                   pop ebx
// 0082ab36  5f                   pop edi
// 0082ab37  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?GetActiveDocTemplate@CXTPCommandBars@@UAEIXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp

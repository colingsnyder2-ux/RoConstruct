// from server: 100% by auto
// roc 2010-06 007c9020  unit: MyXTPCommandBars  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c9020
//
// 007c9020  57                   push edi
// 007c9021  8bf9                 mov edi, ecx
// 007c9023  8b87a0000000         mov eax, dword ptr [edi + 0xa0]
// 007c9029  50                   push eax
// 007c902a  e8ff3e1b00           call 0x97cf2e
// 007c902f  50                   push eax
// 007c9030  e849edfdff           call 0x7a7d7e
// 007c9035  83c408               add esp, 8
// 007c9038  85c0                 test eax, eax
// 007c903a  7502                 jne 0x7c903e
// 007c903c  5f                   pop edi
// 007c903d  c3                   ret 
// 007c903e  53                   push ebx
// 007c903f  0fb75f64             movzx ebx, word ptr [edi + 0x64]
// 007c9043  56                   push esi
// 007c9044  6a00                 push 0
// 007c9046  8bc8                 mov ecx, eax
// 007c9048  e8db3e1b00           call 0x97cf28
// 007c904d  8bf0                 mov esi, eax
// 007c904f  85f6                 test esi, esi
// 007c9051  742f                 je 0x7c9082
// 007c9053  8b06                 mov eax, dword ptr [esi]
// 007c9055  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 007c905b  8bce                 mov ecx, esi
// 007c905d  ffd2                 call edx
// 007c905f  85c0                 test eax, eax
// 007c9061  7419                 je 0x7c907c
// 007c9063  56                   push esi
// 007c9064  8bcf                 mov ecx, edi
// 007c9066  e825ffffff           call 0x7c8f90
// 007c906b  85c0                 test eax, eax
// 007c906d  7504                 jne 0x7c9073
// 007c906f  5e                   pop esi
// 007c9070  5b                   pop ebx
// 007c9071  5f                   pop edi
// 007c9072  c3                   ret 
// 007c9073  8b5840               mov ebx, dword ptr [eax + 0x40]
// 007c9076  5e                   pop esi
// 007c9077  8bc3                 mov eax, ebx
// 007c9079  5b                   pop ebx
// 007c907a  5f                   pop edi
// 007c907b  c3                   ret 
// 007c907c  8b9ea4000000         mov ebx, dword ptr [esi + 0xa4]
// 007c9082  5e                   pop esi
// 007c9083  8bc3                 mov eax, ebx
// 007c9085  5b                   pop ebx
// 007c9086  5f                   pop edi
// 007c9087  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?GetActiveDocTemplate@CXTPCommandBars@@UAEIXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp

// from server: 100% by auto
// roc 2011-06 00880d20  unit: PAUHWND__::?$CArray  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00880d20
//
// 00880d20  56                   push esi
// 00880d21  8bf1                 mov esi, ecx
// 00880d23  57                   push edi
// 00880d24  8d7e08               lea edi, [esi + 8]
// 00880d27  8bcf                 mov ecx, edi
// 00880d29  c70640faac00         mov dword ptr [esi], 0xacfa40
// 00880d2f  e8cc95faff           call 0x82a300
// 00880d34  c70710faac00         mov dword ptr [edi], 0xacfa10
// 00880d3a  8d7e2c               lea edi, [esi + 0x2c]
// 00880d3d  8bcf                 mov ecx, edi
// 00880d3f  e8fcf8ffff           call 0x880640
// 00880d44  33c0                 xor eax, eax
// 00880d46  c70728faac00         mov dword ptr [edi], 0xacfa28
// 00880d4c  6a01                 push 1
// 00880d4e  8bce                 mov ecx, esi
// 00880d50  89461c               mov dword ptr [esi + 0x1c], eax
// 00880d53  894604               mov dword ptr [esi + 4], eax
// 00880d56  894624               mov dword ptr [esi + 0x24], eax
// 00880d59  894628               mov dword ptr [esi + 0x28], eax
// 00880d5c  894620               mov dword ptr [esi + 0x20], eax
// 00880d5f  894640               mov dword ptr [esi + 0x40], eax
// 00880d62  894644               mov dword ptr [esi + 0x44], eax
// 00880d65  e8c6feffff           call 0x880c30
// 00880d6a  5f                   pop edi
// 00880d6b  8bc6                 mov eax, esi
// 00880d6d  5e                   pop esi
// 00880d6e  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPMouseManager.cpp (function ??0CXTPMouseManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPMouseManager.cpp

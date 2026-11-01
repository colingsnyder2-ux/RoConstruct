// from server: 100% by auto
// roc 2009-06 0071bb80  unit: CXTPControlComboBoxList  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071bb80
//
// 0071bb80  51                   push ecx
// 0071bb81  56                   push esi
// 0071bb82  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0071bb86  57                   push edi
// 0071bb87  8bf9                 mov edi, ecx
// 0071bb89  81fe25e10000         cmp esi, 0xe125
// 0071bb8f  7523                 jne 0x71bbb4
// 0071bb91  e846031300           call 0x84bedc
// 0071bb96  a900080008           test eax, 0x8000800
// 0071bb9b  756b                 jne 0x71bc08
// 0071bb9d  6a01                 push 1
// 0071bb9f  ff1558ee8900         call dword ptr [0x89ee58]
// 0071bba5  85c0                 test eax, eax
// 0071bba7  745f                 je 0x71bc08
// 0071bba9  5f                   pop edi
// 0071bbaa  b801000000           mov eax, 1
// 0071bbaf  5e                   pop esi
// 0071bbb0  59                   pop ecx
// 0071bbb1  c20400               ret 4
// 0071bbb4  81fe23e10000         cmp esi, 0xe123
// 0071bbba  7413                 je 0x71bbcf
// 0071bbbc  81fe22e10000         cmp esi, 0xe122
// 0071bbc2  740b                 je 0x71bbcf
// 0071bbc4  5f                   pop edi
// 0071bbc5  b801000000           mov eax, 1
// 0071bbca  5e                   pop esi
// 0071bbcb  59                   pop ecx
// 0071bbcc  c20400               ret 4
// 0071bbcf  8b5720               mov edx, dword ptr [edi + 0x20]
// 0071bbd2  8d442408             lea eax, [esp + 8]
// 0071bbd6  50                   push eax
// 0071bbd7  8d4c2414             lea ecx, [esp + 0x14]
// 0071bbdb  51                   push ecx
// 0071bbdc  68b0000000           push 0xb0
// 0071bbe1  52                   push edx
// 0071bbe2  ff1590ee8900         call dword ptr [0x89ee90]
// 0071bbe8  8b442410             mov eax, dword ptr [esp + 0x10]
// 0071bbec  3b442408             cmp eax, dword ptr [esp + 8]
// 0071bbf0  7416                 je 0x71bc08
// 0071bbf2  81fe22e10000         cmp esi, 0xe122
// 0071bbf8  74ca                 je 0x71bbc4
// 0071bbfa  8bcf                 mov ecx, edi
// 0071bbfc  e8db021300           call 0x84bedc
// 0071bc01  a900080008           test eax, 0x8000800
// 0071bc06  74bc                 je 0x71bbc4
// 0071bc08  5f                   pop edi
// 0071bc09  33c0                 xor eax, eax
// 0071bc0b  5e                   pop esi
// 0071bc0c  59                   pop ecx
// 0071bc0d  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?IsCommandEnabled@CXTPCommandBarEditCtrl@@IAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp

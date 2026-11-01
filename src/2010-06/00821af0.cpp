// from server: 100% by auto
// roc 2010-06 00821af0  unit: CSelectionCaption  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00821af0
//
// 00821af0  83ec10               sub esp, 0x10
// 00821af3  56                   push esi
// 00821af4  57                   push edi
// 00821af5  8bf1                 mov esi, ecx
// 00821af7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00821afa  8d442408             lea eax, [esp + 8]
// 00821afe  50                   push eax
// 00821aff  51                   push ecx
// 00821b00  ff155cbc9e00         call dword ptr [0x9ebc5c]
// 00821b06  8b5620               mov edx, dword ptr [esi + 0x20]
// 00821b09  52                   push edx
// 00821b0a  ff1570ba9e00         call dword ptr [0x9eba70]
// 00821b10  50                   push eax
// 00821b11  e856b21500           call 0x97cd6c
// 00821b16  8bf8                 mov edi, eax
// 00821b18  8b06                 mov eax, dword ptr [esi]
// 00821b1a  8b906c010000         mov edx, dword ptr [eax + 0x16c]
// 00821b20  8d4c2408             lea ecx, [esp + 8]
// 00821b24  51                   push ecx
// 00821b25  57                   push edi
// 00821b26  8bce                 mov ecx, esi
// 00821b28  ffd2                 call edx
// 00821b2a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00821b2e  85c0                 test eax, eax
// 00821b30  741a                 je 0x821b4c
// 00821b32  50                   push eax
// 00821b33  8d8ed0000000         lea ecx, [esi + 0xd0]
// 00821b39  ff158cce9e00         call dword ptr [0x9ece8c]
// 00821b3f  8b06                 mov eax, dword ptr [esi]
// 00821b41  8b9078010000         mov edx, dword ptr [eax + 0x178]
// 00821b47  57                   push edi
// 00821b48  8bce                 mov ecx, esi
// 00821b4a  ffd2                 call edx
// 00821b4c  8b442420             mov eax, dword ptr [esp + 0x20]
// 00821b50  85c0                 test eax, eax
// 00821b52  7418                 je 0x821b6c
// 00821b54  8d4c2408             lea ecx, [esp + 8]
// 00821b58  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 00821b5e  8b06                 mov eax, dword ptr [esi]
// 00821b60  8b9074010000         mov edx, dword ptr [eax + 0x174]
// 00821b66  51                   push ecx
// 00821b67  57                   push edi
// 00821b68  8bce                 mov ecx, esi
// 00821b6a  ffd2                 call edx
// 00821b6c  8b4704               mov eax, dword ptr [edi + 4]
// 00821b6f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00821b72  50                   push eax
// 00821b73  51                   push ecx
// 00821b74  ff1568ba9e00         call dword ptr [0x9eba68]
// 00821b7a  5f                   pop edi
// 00821b7b  5e                   pop esi
// 00821b7c  83c410               add esp, 0x10
// 00821b7f  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?UpdateCaption@CXTCaption@@UAEXPBDPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp

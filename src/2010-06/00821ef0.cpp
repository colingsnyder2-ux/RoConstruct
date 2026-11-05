// from server: 100% by auto
// roc 2010-06 00821ef0  unit: CSelectionCaption  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00821ef0
//
// 00821ef0  56                   push esi
// 00821ef1  8bf1                 mov esi, ecx
// 00821ef3  8b06                 mov eax, dword ptr [esi]
// 00821ef5  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 00821efb  57                   push edi
// 00821efc  ffd2                 call edx
// 00821efe  8b8688000000         mov eax, dword ptr [esi + 0x88]
// 00821f04  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00821f07  8dbea8000000         lea edi, [esi + 0xa8]
// 00821f0d  57                   push edi
// 00821f0e  51                   push ecx
// 00821f0f  ff155cbc9e00         call dword ptr [0x9ebc5c]
// 00821f15  8b17                 mov edx, dword ptr [edi]
// 00821f17  8b4704               mov eax, dword ptr [edi + 4]
// 00821f1a  8b4f08               mov ecx, dword ptr [edi + 8]
// 00821f1d  899698000000         mov dword ptr [esi + 0x98], edx
// 00821f23  8b570c               mov edx, dword ptr [edi + 0xc]
// 00821f26  89869c000000         mov dword ptr [esi + 0x9c], eax
// 00821f2c  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00821f2f  898ea0000000         mov dword ptr [esi + 0xa0], ecx
// 00821f35  8996a4000000         mov dword ptr [esi + 0xa4], edx
// 00821f3b  01869c000000         add dword ptr [esi + 0x9c], eax
// 00821f41  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 00821f47  8b96a4000000         mov edx, dword ptr [esi + 0xa4]
// 00821f4d  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 00821f53  6a01                 push 1
// 00821f55  2bd0                 sub edx, eax
// 00821f57  52                   push edx
// 00821f58  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 00821f5e  2bd1                 sub edx, ecx
// 00821f60  52                   push edx
// 00821f61  50                   push eax
// 00821f62  51                   push ecx
// 00821f63  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 00821f69  e8045ef8ff           call 0x7a7d72
// 00821f6e  8b4638               mov eax, dword ptr [esi + 0x38]
// 00821f71  85c0                 test eax, eax
// 00821f73  750a                 jne 0x821f7f
// 00821f75  8b4620               mov eax, dword ptr [esi + 0x20]
// 00821f78  50                   push eax
// 00821f79  ff154cba9e00         call dword ptr [0x9eba4c]
// 00821f7f  50                   push eax
// 00821f80  e8e55cf8ff           call 0x7a7c6a
// 00821f85  8bf8                 mov edi, eax
// 00821f87  85ff                 test edi, edi
// 00821f89  7403                 je 0x821f8e
// 00821f8b  8b4720               mov eax, dword ptr [edi + 0x20]
// 00821f8e  50                   push eax
// 00821f8f  ff1528bc9e00         call dword ptr [0x9ebc28]
// 00821f95  85c0                 test eax, eax
// 00821f97  7421                 je 0x821fba
// 00821f99  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00821f9c  6a00                 push 0
// 00821f9e  6a00                 push 0
// 00821fa0  683e270000           push 0x273e
// 00821fa5  51                   push ecx
// 00821fa6  ff1554ba9e00         call dword ptr [0x9eba54]
// 00821fac  8b5620               mov edx, dword ptr [esi + 0x20]
// 00821faf  6a01                 push 1
// 00821fb1  6a00                 push 0
// 00821fb3  52                   push edx
// 00821fb4  ff1578ba9e00         call dword ptr [0x9eba78]
// 00821fba  5f                   pop edi
// 00821fbb  5e                   pop esi
// 00821fbc  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?OnPushPinButton@CXTCaption@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp

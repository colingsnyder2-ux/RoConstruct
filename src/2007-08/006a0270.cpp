// from server: 100% by auto
// roc 2007-08 006a0270  unit: CSelectionCaption  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a0270
//
// 006a0270  56                   push esi
// 006a0271  8bf1                 mov esi, ecx
// 006a0273  8b06                 mov eax, dword ptr [esi]
// 006a0275  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 006a027b  57                   push edi
// 006a027c  ffd2                 call edx
// 006a027e  8b8688000000         mov eax, dword ptr [esi + 0x88]
// 006a0284  8b4820               mov ecx, dword ptr [eax + 0x20]
// 006a0287  8dbea8000000         lea edi, [esi + 0xa8]
// 006a028d  57                   push edi
// 006a028e  51                   push ecx
// 006a028f  ff15f4ed7700         call dword ptr [0x77edf4]
// 006a0295  8b17                 mov edx, dword ptr [edi]
// 006a0297  8b4704               mov eax, dword ptr [edi + 4]
// 006a029a  8b4f08               mov ecx, dword ptr [edi + 8]
// 006a029d  899698000000         mov dword ptr [esi + 0x98], edx
// 006a02a3  8b570c               mov edx, dword ptr [edi + 0xc]
// 006a02a6  89869c000000         mov dword ptr [esi + 0x9c], eax
// 006a02ac  8b467c               mov eax, dword ptr [esi + 0x7c]
// 006a02af  898ea0000000         mov dword ptr [esi + 0xa0], ecx
// 006a02b5  8996a4000000         mov dword ptr [esi + 0xa4], edx
// 006a02bb  01869c000000         add dword ptr [esi + 0x9c], eax
// 006a02c1  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 006a02c7  8b96a4000000         mov edx, dword ptr [esi + 0xa4]
// 006a02cd  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 006a02d3  6a01                 push 1
// 006a02d5  2bd0                 sub edx, eax
// 006a02d7  52                   push edx
// 006a02d8  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 006a02de  2bd1                 sub edx, ecx
// 006a02e0  52                   push edx
// 006a02e1  50                   push eax
// 006a02e2  51                   push ecx
// 006a02e3  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 006a02e9  e846fdf8ff           call 0x630034
// 006a02ee  8b4638               mov eax, dword ptr [esi + 0x38]
// 006a02f1  85c0                 test eax, eax
// 006a02f3  750a                 jne 0x6a02ff
// 006a02f5  8b4620               mov eax, dword ptr [esi + 0x20]
// 006a02f8  50                   push eax
// 006a02f9  ff15f8eb7700         call dword ptr [0x77ebf8]
// 006a02ff  50                   push eax
// 006a0300  e8bbfef8ff           call 0x6301c0
// 006a0305  8bf8                 mov edi, eax
// 006a0307  85ff                 test edi, edi
// 006a0309  7403                 je 0x6a030e
// 006a030b  8b4720               mov eax, dword ptr [edi + 0x20]
// 006a030e  50                   push eax
// 006a030f  ff15bced7700         call dword ptr [0x77edbc]
// 006a0315  85c0                 test eax, eax
// 006a0317  7421                 je 0x6a033a
// 006a0319  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 006a031c  6a00                 push 0
// 006a031e  6a00                 push 0
// 006a0320  683e270000           push 0x273e
// 006a0325  51                   push ecx
// 006a0326  ff15d8ec7700         call dword ptr [0x77ecd8]
// 006a032c  8b5620               mov edx, dword ptr [esi + 0x20]
// 006a032f  6a01                 push 1
// 006a0331  6a00                 push 0
// 006a0333  52                   push edx
// 006a0334  ff15dcec7700         call dword ptr [0x77ecdc]
// 006a033a  5f                   pop edi
// 006a033b  5e                   pop esi
// 006a033c  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnPushPinButton@CXTCaption@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp

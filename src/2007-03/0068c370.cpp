// from server: 100% by auto
// roc 2007-03 0068c370  unit: seg_00680000  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068c370
//
// 0068c370  56                   push esi
// 0068c371  8bf1                 mov esi, ecx
// 0068c373  8b06                 mov eax, dword ptr [esi]
// 0068c375  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 0068c37b  57                   push edi
// 0068c37c  ffd2                 call edx
// 0068c37e  8b8688000000         mov eax, dword ptr [esi + 0x88]
// 0068c384  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0068c387  8dbea8000000         lea edi, [esi + 0xa8]
// 0068c38d  57                   push edi
// 0068c38e  51                   push ecx
// 0068c38f  ff153ced7700         call dword ptr [0x77ed3c]
// 0068c395  8b17                 mov edx, dword ptr [edi]
// 0068c397  8b4704               mov eax, dword ptr [edi + 4]
// 0068c39a  8b4f08               mov ecx, dword ptr [edi + 8]
// 0068c39d  899698000000         mov dword ptr [esi + 0x98], edx
// 0068c3a3  8b570c               mov edx, dword ptr [edi + 0xc]
// 0068c3a6  89869c000000         mov dword ptr [esi + 0x9c], eax
// 0068c3ac  8b467c               mov eax, dword ptr [esi + 0x7c]
// 0068c3af  898ea0000000         mov dword ptr [esi + 0xa0], ecx
// 0068c3b5  8996a4000000         mov dword ptr [esi + 0xa4], edx
// 0068c3bb  01869c000000         add dword ptr [esi + 0x9c], eax
// 0068c3c1  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 0068c3c7  8b96a4000000         mov edx, dword ptr [esi + 0xa4]
// 0068c3cd  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 0068c3d3  6a01                 push 1
// 0068c3d5  2bd0                 sub edx, eax
// 0068c3d7  52                   push edx
// 0068c3d8  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 0068c3de  2bd1                 sub edx, ecx
// 0068c3e0  52                   push edx
// 0068c3e1  50                   push eax
// 0068c3e2  51                   push ecx
// 0068c3e3  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0068c3e9  e8ce20f9ff           call 0x61e4bc
// 0068c3ee  8b4638               mov eax, dword ptr [esi + 0x38]
// 0068c3f1  85c0                 test eax, eax
// 0068c3f3  750a                 jne 0x68c3ff
// 0068c3f5  8b4620               mov eax, dword ptr [esi + 0x20]
// 0068c3f8  50                   push eax
// 0068c3f9  ff15c8ec7700         call dword ptr [0x77ecc8]
// 0068c3ff  50                   push eax
// 0068c400  e84922f9ff           call 0x61e64e
// 0068c405  8bf8                 mov edi, eax
// 0068c407  85ff                 test edi, edi
// 0068c409  7403                 je 0x68c40e
// 0068c40b  8b4720               mov eax, dword ptr [edi + 0x20]
// 0068c40e  50                   push eax
// 0068c40f  ff1574ed7700         call dword ptr [0x77ed74]
// 0068c415  85c0                 test eax, eax
// 0068c417  7421                 je 0x68c43a
// 0068c419  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 0068c41c  6a00                 push 0
// 0068c41e  6a00                 push 0
// 0068c420  683e270000           push 0x273e
// 0068c425  51                   push ecx
// 0068c426  ff1550ee7700         call dword ptr [0x77ee50]
// 0068c42c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0068c42f  6a01                 push 1
// 0068c431  6a00                 push 0
// 0068c433  52                   push edx
// 0068c434  ff1554ee7700         call dword ptr [0x77ee54]
// 0068c43a  5f                   pop edi
// 0068c43b  5e                   pop esi
// 0068c43c  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnPushPinButton@CXTCaption@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp

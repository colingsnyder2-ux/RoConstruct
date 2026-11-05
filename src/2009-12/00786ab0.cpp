// from server: 100% by auto
// roc 2009-12 00786ab0  unit: RBX::BoxSelectCommand  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00786ab0
//
// 00786ab0  53                   push ebx
// 00786ab1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00786ab5  8b4318               mov eax, dword ptr [ebx + 0x18]
// 00786ab8  56                   push esi
// 00786ab9  57                   push edi
// 00786aba  8bf1                 mov esi, ecx
// 00786abc  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00786abf  83c004               add eax, 4
// 00786ac2  8b00                 mov eax, dword ptr [eax]
// 00786ac4  57                   push edi
// 00786ac5  50                   push eax
// 00786ac6  e825f9ffff           call 0x7863f0
// 00786acb  894704               mov dword ptr [edi + 4], eax
// 00786ace  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 00786ad1  8b5618               mov edx, dword ptr [esi + 0x18]
// 00786ad4  894e1c               mov dword ptr [esi + 0x1c], ecx
// 00786ad7  8b4204               mov eax, dword ptr [edx + 4]
// 00786ada  80781100             cmp byte ptr [eax + 0x11], 0
// 00786ade  7537                 jne 0x786b17
// 00786ae0  8b08                 mov ecx, dword ptr [eax]
// 00786ae2  80791100             cmp byte ptr [ecx + 0x11], 0
// 00786ae6  750a                 jne 0x786af2
// 00786ae8  8bc1                 mov eax, ecx
// 00786aea  8b08                 mov ecx, dword ptr [eax]
// 00786aec  80791100             cmp byte ptr [ecx + 0x11], 0
// 00786af0  74f6                 je 0x786ae8
// 00786af2  8902                 mov dword ptr [edx], eax
// 00786af4  8b7618               mov esi, dword ptr [esi + 0x18]
// 00786af7  8b4e04               mov ecx, dword ptr [esi + 4]
// 00786afa  8b4108               mov eax, dword ptr [ecx + 8]
// 00786afd  80781100             cmp byte ptr [eax + 0x11], 0
// 00786b01  750b                 jne 0x786b0e
// 00786b03  8bc8                 mov ecx, eax
// 00786b05  8b4108               mov eax, dword ptr [ecx + 8]
// 00786b08  80781100             cmp byte ptr [eax + 0x11], 0
// 00786b0c  74f5                 je 0x786b03
// 00786b0e  5f                   pop edi
// 00786b0f  894e08               mov dword ptr [esi + 8], ecx
// 00786b12  5e                   pop esi
// 00786b13  5b                   pop ebx
// 00786b14  c20400               ret 4
// 00786b17  8912                 mov dword ptr [edx], edx
// 00786b19  8b7618               mov esi, dword ptr [esi + 0x18]
// 00786b1c  5f                   pop edi
// 00786b1d  897608               mov dword ptr [esi + 8], esi
// 00786b20  5e                   pop esi
// 00786b21  5b                   pop ebx
// 00786b22  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ?_Copy@?$_Tree@V?$_Tset_traits@PBVTriangle@?$ConvexHull3@M@Wml@@U?$less@PBVTriangle@?$ConvexHull3@M@Wml@@@std@@V?$allocator@PBVTriangle@?$ConvexHull3@M@Wml@@@5@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp

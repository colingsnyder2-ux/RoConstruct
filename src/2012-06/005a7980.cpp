// roc 2012-06 005a7980  unit: RBX::Image  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a7980
//
// 005a7980  53                   push ebx
// 005a7981  56                   push esi
// 005a7982  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005a7986  8bd9                 mov ebx, ecx
// 005a7988  85f6                 test esi, esi
// 005a798a  7446                 je 0x5a79d2
// 005a798c  8a0e                 mov cl, byte ptr [esi]
// 005a798e  84c9                 test cl, cl
// 005a7990  7440                 je 0x5a79d2
// 005a7992  8bc6                 mov eax, esi
// 005a7994  57                   push edi
// 005a7995  8d7801               lea edi, [eax + 1]
// 005a7998  8a10                 mov dl, byte ptr [eax]
// 005a799a  40                   inc eax
// 005a799b  84d2                 test dl, dl
// 005a799d  75f9                 jne 0x5a7998
// 005a799f  2bc7                 sub eax, edi
// 005a79a1  5f                   pop edi
// 005a79a2  83f80f               cmp eax, 0xf
// 005a79a5  772b                 ja 0x5a79d2
// 005a79a7  8b13                 mov edx, dword ptr [ebx]
// 005a79a9  8b5210               mov edx, dword ptr [edx + 0x10]
// 005a79ac  33c0                 xor eax, eax
// 005a79ae  380a                 cmp byte ptr [edx], cl
// 005a79b0  750e                 jne 0x5a79c0
// 005a79b2  84c9                 test cl, cl
// 005a79b4  7423                 je 0x5a79d9
// 005a79b6  8a4c3001             mov cl, byte ptr [eax + esi + 1]
// 005a79ba  40                   inc eax
// 005a79bb  380c02               cmp byte ptr [edx + eax], cl
// 005a79be  74f2                 je 0x5a79b2
// 005a79c0  8a1402               mov dl, byte ptr [edx + eax]
// 005a79c3  84d2                 test dl, dl
// 005a79c5  740b                 je 0x5a79d2
// 005a79c7  803c3000             cmp byte ptr [eax + esi], 0
// 005a79cb  7405                 je 0x5a79d2
// 005a79cd  80fa2a               cmp dl, 0x2a
// 005a79d0  7407                 je 0x5a79d9
// 005a79d2  5e                   pop esi
// 005a79d3  32c0                 xor al, al
// 005a79d5  5b                   pop ebx
// 005a79d6  c20400               ret 4
// 005a79d9  5e                   pop esi
// 005a79da  b001                 mov al, 1
// 005a79dc  5b                   pop ebx
// 005a79dd  c20400               ret 4
// copied from an identical function in another client (function ?IPAddressMatch@RakString@RakNet@@QAE_NPBD@Z)

// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakString.cpp
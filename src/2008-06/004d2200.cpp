// from server: 100% by auto
// roc 2008-06 004d2200  unit: seg_004d0000  size: 445 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d2200
//
// 004d2200  83ec0c               sub esp, 0xc
// 004d2203  53                   push ebx
// 004d2204  56                   push esi
// 004d2205  57                   push edi
// 004d2206  8bf1                 mov esi, ecx
// 004d2208  68c0f74c00           push 0x4cf7c0
// 004d220d  8d442413             lea eax, [esp + 0x13]
// 004d2211  50                   push eax
// 004d2212  8d4c2424             lea ecx, [esp + 0x24]
// 004d2216  8dbea4000000         lea edi, [esi + 0xa4]
// 004d221c  51                   push ecx
// 004d221d  8bcf                 mov ecx, edi
// 004d221f  e84ccfffff           call 0x4cf170
// 004d2224  8b17                 mov edx, dword ptr [edi]
// 004d2226  8bd8                 mov ebx, eax
// 004d2228  8b0c9a               mov ecx, dword ptr [edx + ebx*4]
// 004d222b  8d049a               lea eax, [edx + ebx*4]
// 004d222e  8b5108               mov edx, dword ptr [ecx + 8]
// 004d2231  8b12                 mov edx, dword ptr [edx]
// 004d2233  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 004d2236  3b4a24               cmp ecx, dword ptr [edx + 0x24]
// 004d2239  0f8573010000         jne 0x4d23b2
// 004d223f  8b10                 mov edx, dword ptr [eax]
// 004d2241  8b4208               mov eax, dword ptr [edx + 8]
// 004d2244  8d8eb0070000         lea ecx, [esi + 0x7b0]
// 004d224a  55                   push ebp
// 004d224b  8b28                 mov ebp, dword ptr [eax]
// 004d224d  894c2418             mov dword ptr [esp + 0x18], ecx
// 004d2251  e8aad6ffff           call 0x4cf900
// 004d2256  8b542424             mov edx, dword ptr [esp + 0x24]
// 004d225a  8bf0                 mov esi, eax
// 004d225c  8b442428             mov eax, dword ptr [esp + 0x28]
// 004d2260  33c9                 xor ecx, ecx
// 004d2262  894e38               mov dword ptr [esi + 0x38], ecx
// 004d2265  894e3c               mov dword ptr [esi + 0x3c], ecx
// 004d2268  895628               mov dword ptr [esi + 0x28], edx
// 004d226b  89462c               mov dword ptr [esi + 0x2c], eax
// 004d226e  894e30               mov dword ptr [esi + 0x30], ecx
// 004d2271  894e34               mov dword ptr [esi + 0x34], ecx
// 004d2274  8b5518               mov edx, dword ptr [ebp + 0x18]
// 004d2277  895618               mov dword ptr [esi + 0x18], edx
// 004d227a  8a4514               mov al, byte ptr [ebp + 0x14]
// 004d227d  884614               mov byte ptr [esi + 0x14], al
// 004d2280  8b5500               mov edx, dword ptr [ebp]
// 004d2283  8916                 mov dword ptr [esi], edx
// 004d2285  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004d2288  89460c               mov dword ptr [esi + 0xc], eax
// 004d228b  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004d228e  895610               mov dword ptr [esi + 0x10], edx
// 004d2291  894e38               mov dword ptr [esi + 0x38], ecx
// 004d2294  8b07                 mov eax, dword ptr [edi]
// 004d2296  8b0498               mov eax, dword ptr [eax + ebx*4]
// 004d2299  39480c               cmp dword ptr [eax + 0xc], ecx
// 004d229c  7619                 jbe 0x4d22b7
// 004d229e  8bff                 mov edi, edi
// 004d22a0  8b5008               mov edx, dword ptr [eax + 8]
// 004d22a3  8b048a               mov eax, dword ptr [edx + ecx*4]
// 004d22a6  8b5038               mov edx, dword ptr [eax + 0x38]
// 004d22a9  015638               add dword ptr [esi + 0x38], edx
// 004d22ac  8b07                 mov eax, dword ptr [edi]
// 004d22ae  8b0498               mov eax, dword ptr [eax + ebx*4]
// 004d22b1  41                   inc ecx
// 004d22b2  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004d22b5  72e9                 jb 0x4d22a0
// 004d22b7  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 004d22ba  83c107               add ecx, 7
// 004d22bd  c1e903               shr ecx, 3
// 004d22c0  51                   push ecx
// 004d22c1  e85ae61c00           call 0x6a0920
// 004d22c6  89463c               mov dword ptr [esi + 0x3c], eax
// 004d22c9  8b17                 mov edx, dword ptr [edi]
// 004d22cb  8b0c9a               mov ecx, dword ptr [edx + ebx*4]
// 004d22ce  8d049a               lea eax, [edx + ebx*4]
// 004d22d1  33ed                 xor ebp, ebp
// 004d22d3  83c404               add esp, 4
// 004d22d6  896c2424             mov dword ptr [esp + 0x24], ebp
// 004d22da  39690c               cmp dword ptr [ecx + 0xc], ebp
// 004d22dd  7649                 jbe 0x4d2328
// 004d22df  90                   nop 
// 004d22e0  8b10                 mov edx, dword ptr [eax]
// 004d22e2  8b4208               mov eax, dword ptr [edx + 8]
// 004d22e5  8b04a8               mov eax, dword ptr [eax + ebp*4]
// 004d22e8  8b4838               mov ecx, dword ptr [eax + 0x38]
// 004d22eb  8b503c               mov edx, dword ptr [eax + 0x3c]
// 004d22ee  8b463c               mov eax, dword ptr [esi + 0x3c]
// 004d22f1  03442424             add eax, dword ptr [esp + 0x24]
// 004d22f5  83c107               add ecx, 7
// 004d22f8  c1e903               shr ecx, 3
// 004d22fb  51                   push ecx
// 004d22fc  52                   push edx
// 004d22fd  50                   push eax
// 004d22fe  e8ddf41c00           call 0x6a17e0
// 004d2303  8b0f                 mov ecx, dword ptr [edi]
// 004d2305  8d0499               lea eax, [ecx + ebx*4]
// 004d2308  8b08                 mov ecx, dword ptr [eax]
// 004d230a  8b5108               mov edx, dword ptr [ecx + 8]
// 004d230d  8b0caa               mov ecx, dword ptr [edx + ebp*4]
// 004d2310  8b5138               mov edx, dword ptr [ecx + 0x38]
// 004d2313  8b08                 mov ecx, dword ptr [eax]
// 004d2315  83c207               add edx, 7
// 004d2318  c1ea03               shr edx, 3
// 004d231b  01542430             add dword ptr [esp + 0x30], edx
// 004d231f  45                   inc ebp
// 004d2320  83c40c               add esp, 0xc
// 004d2323  3b690c               cmp ebp, dword ptr [ecx + 0xc]
// 004d2326  72b8                 jb 0x4d22e0
// 004d2328  8b17                 mov edx, dword ptr [edi]
// 004d232a  8b049a               mov eax, dword ptr [edx + ebx*4]
// 004d232d  33ed                 xor ebp, ebp
// 004d232f  39680c               cmp dword ptr [eax + 0xc], ebp
// 004d2332  7632                 jbe 0x4d2366
// 004d2334  8b4008               mov eax, dword ptr [eax + 8]
// 004d2337  8b0ca8               mov ecx, dword ptr [eax + ebp*4]
// 004d233a  8b513c               mov edx, dword ptr [ecx + 0x3c]
// 004d233d  52                   push edx
// 004d233e  e837e31c00           call 0x6a067a
// 004d2343  8b07                 mov eax, dword ptr [edi]
// 004d2345  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 004d2348  8b5108               mov edx, dword ptr [ecx + 8]
// 004d234b  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 004d234e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004d2352  83c404               add esp, 4
// 004d2355  50                   push eax
// 004d2356  e845d6ffff           call 0x4cf9a0
// 004d235b  8b0f                 mov ecx, dword ptr [edi]
// 004d235d  8b0499               mov eax, dword ptr [ecx + ebx*4]
// 004d2360  45                   inc ebp
// 004d2361  3b680c               cmp ebp, dword ptr [eax + 0xc]
// 004d2364  72ce                 jb 0x4d2334
// 004d2366  8b17                 mov edx, dword ptr [edi]
// 004d2368  8b2c9a               mov ebp, dword ptr [edx + ebx*4]
// 004d236b  85ed                 test ebp, ebp
// 004d236d  7411                 je 0x4d2380
// 004d236f  8d4d08               lea ecx, [ebp + 8]
// 004d2372  e88980feff           call 0x4ba400
// 004d2377  55                   push ebp
// 004d2378  e8fde21c00           call 0x6a067a
// 004d237d  83c404               add esp, 4
// 004d2380  8b4f04               mov ecx, dword ptr [edi + 4]
// 004d2383  5d                   pop ebp
// 004d2384  3bd9                 cmp ebx, ecx
// 004d2386  731f                 jae 0x4d23a7
// 004d2388  49                   dec ecx
// 004d2389  8bc3                 mov eax, ebx
// 004d238b  3bd9                 cmp ebx, ecx
// 004d238d  7315                 jae 0x4d23a4
// 004d238f  90                   nop 
// 004d2390  8b0f                 mov ecx, dword ptr [edi]
// 004d2392  8b548104             mov edx, dword ptr [ecx + eax*4 + 4]
// 004d2396  8d0c81               lea ecx, [ecx + eax*4]
// 004d2399  8911                 mov dword ptr [ecx], edx
// 004d239b  8b4f04               mov ecx, dword ptr [edi + 4]
// 004d239e  40                   inc eax
// 004d239f  49                   dec ecx
// 004d23a0  3bc1                 cmp eax, ecx
// 004d23a2  72ec                 jb 0x4d2390
// 004d23a4  ff4f04               dec dword ptr [edi + 4]
// 004d23a7  5f                   pop edi
// 004d23a8  8bc6                 mov eax, esi
// 004d23aa  5e                   pop esi
// 004d23ab  5b                   pop ebx
// 004d23ac  83c40c               add esp, 0xc
// 004d23af  c20c00               ret 0xc
// 004d23b2  5f                   pop edi
// 004d23b3  5e                   pop esi
// 004d23b4  33c0                 xor eax, eax
// 004d23b6  5b                   pop ebx
// 004d23b7  83c40c               add esp, 0xc
// 004d23ba  c20c00               ret 0xc
// library openrbx-raknet/ReliabilityLayer.cpp (function ?BuildPacketFromSplitPacketList@ReliabilityLayer@@AAEPAUInternalPacket@@G_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp

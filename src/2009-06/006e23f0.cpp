// from server: 100% by auto
// roc 2009-06 006e23f0  unit: RBX::ScoreHud  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e23f0
//
// 006e23f0  83ec08               sub esp, 8
// 006e23f3  53                   push ebx
// 006e23f4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006e23f8  56                   push esi
// 006e23f9  8bf1                 mov esi, ecx
// 006e23fb  8b4610               mov eax, dword ptr [esi + 0x10]
// 006e23fe  57                   push edi
// 006e23ff  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006e2402  8bc8                 mov ecx, eax
// 006e2404  2bcf                 sub ecx, edi
// 006e2406  c1f903               sar ecx, 3
// 006e2409  3bcb                 cmp ecx, ebx
// 006e240b  7705                 ja 0x6e2412
// 006e240d  e80efbffff           call 0x6e1f20
// 006e2412  3bf8                 cmp edi, eax
// 006e2414  7606                 jbe 0x6e241c
// 006e2416  ff15ace98900         call dword ptr [0x89e9ac]
// 006e241c  8b36                 mov esi, dword ptr [esi]
// 006e241e  55                   push ebp
// 006e241f  8bee                 mov ebp, esi
// 006e2421  897c2414             mov dword ptr [esp + 0x14], edi
// 006e2425  85f6                 test esi, esi
// 006e2427  7518                 jne 0x6e2441
// 006e2429  ff15ace98900         call dword ptr [0x89e9ac]
// 006e242f  33c0                 xor eax, eax
// 006e2431  8d3cdf               lea edi, [edi + ebx*8]
// 006e2434  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006e2437  7713                 ja 0x6e244c
// 006e2439  85f6                 test esi, esi
// 006e243b  7408                 je 0x6e2445
// 006e243d  8b36                 mov esi, dword ptr [esi]
// 006e243f  eb06                 jmp 0x6e2447
// 006e2441  8b06                 mov eax, dword ptr [esi]
// 006e2443  ebec                 jmp 0x6e2431
// 006e2445  33f6                 xor esi, esi
// 006e2447  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006e244a  730a                 jae 0x6e2456
// 006e244c  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 006e2452  ffd6                 call esi
// 006e2454  eb06                 jmp 0x6e245c
// 006e2456  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 006e245c  85ed                 test ebp, ebp
// 006e245e  7517                 jne 0x6e2477
// 006e2460  ffd6                 call esi
// 006e2462  33c0                 xor eax, eax
// 006e2464  5d                   pop ebp
// 006e2465  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006e2468  7202                 jb 0x6e246c
// 006e246a  ffd6                 call esi
// 006e246c  8bc7                 mov eax, edi
// 006e246e  5f                   pop edi
// 006e246f  5e                   pop esi
// 006e2470  5b                   pop ebx
// 006e2471  83c408               add esp, 8
// 006e2474  c20400               ret 4
// 006e2477  8b4500               mov eax, dword ptr [ebp]
// 006e247a  ebe8                 jmp 0x6e2464
// standard library vector<double> (function ?at@?$vector@NV?$allocator@N@std@@@std@@QBEABNI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

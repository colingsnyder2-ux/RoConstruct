// from server: 100% by auto
// roc 2009-12 006f5360  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5360
//
// 006f5360  53                   push ebx
// 006f5361  56                   push esi
// 006f5362  8bf1                 mov esi, ecx
// 006f5364  33db                 xor ebx, ebx
// 006f5366  57                   push edi
// 006f5367  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 006f536a  7451                 je 0x6f53bd
// 006f536c  83cfff               or edi, 0xffffffff
// 006f536f  90                   nop 
// 006f5370  8b461c               mov eax, dword ptr [esi + 0x1c]
// 006f5373  3bc3                 cmp eax, ebx
// 006f5375  7441                 je 0x6f53b8
// 006f5377  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f537a  8b5614               mov edx, dword ptr [esi + 0x14]
// 006f537d  8d4408ff             lea eax, [eax + ecx - 1]
// 006f5381  8bc8                 mov ecx, eax
// 006f5383  d1e9                 shr ecx, 1
// 006f5385  3bd1                 cmp edx, ecx
// 006f5387  7702                 ja 0x6f538b
// 006f5389  2bca                 sub ecx, edx
// 006f538b  8b5610               mov edx, dword ptr [esi + 0x10]
// 006f538e  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 006f5391  83e001               and eax, 1
// 006f5394  8d44c104             lea eax, [ecx + eax*8 + 4]
// 006f5398  8b08                 mov ecx, dword ptr [eax]
// 006f539a  3bcb                 cmp ecx, ebx
// 006f539c  7412                 je 0x6f53b0
// 006f539e  8d5108               lea edx, [ecx + 8]
// 006f53a1  8bc7                 mov eax, edi
// 006f53a3  f00fc102             lock xadd dword ptr [edx], eax
// 006f53a7  7507                 jne 0x6f53b0
// 006f53a9  8b11                 mov edx, dword ptr [ecx]
// 006f53ab  8b4208               mov eax, dword ptr [edx + 8]
// 006f53ae  ffd0                 call eax
// 006f53b0  017e1c               add dword ptr [esi + 0x1c], edi
// 006f53b3  7503                 jne 0x6f53b8
// 006f53b5  895e18               mov dword ptr [esi + 0x18], ebx
// 006f53b8  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 006f53bb  75b3                 jne 0x6f5370
// 006f53bd  8b7e14               mov edi, dword ptr [esi + 0x14]
// 006f53c0  3bfb                 cmp edi, ebx
// 006f53c2  761b                 jbe 0x6f53df
// 006f53c4  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006f53c7  4f                   dec edi
// 006f53c8  391cb9               cmp dword ptr [ecx + edi*4], ebx
// 006f53cb  8d04b9               lea eax, [ecx + edi*4]
// 006f53ce  740b                 je 0x6f53db
// 006f53d0  8b10                 mov edx, dword ptr [eax]
// 006f53d2  52                   push edx
// 006f53d3  e882e40f00           call 0x7f385a
// 006f53d8  83c404               add esp, 4
// 006f53db  3bfb                 cmp edi, ebx
// 006f53dd  77e5                 ja 0x6f53c4
// 006f53df  8b4610               mov eax, dword ptr [esi + 0x10]
// 006f53e2  3bc3                 cmp eax, ebx
// 006f53e4  7409                 je 0x6f53ef
// 006f53e6  50                   push eax
// 006f53e7  e86ee40f00           call 0x7f385a
// 006f53ec  83c404               add esp, 4
// 006f53ef  5f                   pop edi
// 006f53f0  895e10               mov dword ptr [esi + 0x10], ebx
// 006f53f3  895e14               mov dword ptr [esi + 0x14], ebx
// 006f53f6  5e                   pop esi
// 006f53f7  5b                   pop ebx
// 006f53f8  c3                   ret 
// library templates-boost-1_34_1/deque_wp.cpp (function ?_Tidy@?$deque@V?$weak_ptr@UT@@@boost@@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_wp.cpp

// from server: 100% by auto
// roc 2009-12 007c25f0  unit: RBX::VChatLine::?$sp_counted_impl_p  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c25f0
//
// 007c25f0  55                   push ebp
// 007c25f1  56                   push esi
// 007c25f2  8bf1                 mov esi, ecx
// 007c25f4  f6461801             test byte ptr [esi + 0x18], 1
// 007c25f8  7514                 jne 0x7c260e
// 007c25fa  8b461c               mov eax, dword ptr [esi + 0x1c]
// 007c25fd  83c002               add eax, 2
// 007c2600  d1e8                 shr eax, 1
// 007c2602  394614               cmp dword ptr [esi + 0x14], eax
// 007c2605  7707                 ja 0x7c260e
// 007c2607  6a01                 push 1
// 007c2609  e8d2d3f6ff           call 0x72f9e0
// 007c260e  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 007c2611  85ed                 test ebp, ebp
// 007c2613  7505                 jne 0x7c261a
// 007c2615  8b6e14               mov ebp, dword ptr [esi + 0x14]
// 007c2618  03ed                 add ebp, ebp
// 007c261a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007c261d  4d                   dec ebp
// 007c261e  57                   push edi
// 007c261f  8bfd                 mov edi, ebp
// 007c2621  d1ef                 shr edi, 1
// 007c2623  833cb900             cmp dword ptr [ecx + edi*4], 0
// 007c2627  7510                 jne 0x7c2639
// 007c2629  6a10                 push 0x10
// 007c262b  e830120300           call 0x7f3860
// 007c2630  8b5610               mov edx, dword ptr [esi + 0x10]
// 007c2633  83c404               add esp, 4
// 007c2636  8904ba               mov dword ptr [edx + edi*4], eax
// 007c2639  8b4610               mov eax, dword ptr [esi + 0x10]
// 007c263c  8b14b8               mov edx, dword ptr [eax + edi*4]
// 007c263f  8bcd                 mov ecx, ebp
// 007c2641  83e101               and ecx, 1
// 007c2644  8d04ca               lea eax, [edx + ecx*8]
// 007c2647  5f                   pop edi
// 007c2648  85c0                 test eax, eax
// 007c264a  741e                 je 0x7c266a
// 007c264c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007c2650  8b11                 mov edx, dword ptr [ecx]
// 007c2652  8910                 mov dword ptr [eax], edx
// 007c2654  8b4904               mov ecx, dword ptr [ecx + 4]
// 007c2657  894804               mov dword ptr [eax + 4], ecx
// 007c265a  85c9                 test ecx, ecx
// 007c265c  740c                 je 0x7c266a
// 007c265e  83c104               add ecx, 4
// 007c2661  b801000000           mov eax, 1
// 007c2666  f00fc101             lock xadd dword ptr [ecx], eax
// 007c266a  ff461c               inc dword ptr [esi + 0x1c]
// 007c266d  896e18               mov dword ptr [esi + 0x18], ebp
// 007c2670  5e                   pop esi
// 007c2671  5d                   pop ebp
// 007c2672  c20400               ret 4
// library templates-boost-1_34_1/deque_sp.cpp (function ?push_front@?$deque@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@QAEXABV?$shared_ptr@UT@@@boost@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_sp.cpp

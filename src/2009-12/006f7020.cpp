// from server: 100% by auto
// roc 2009-12 006f7020  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f7020
//
// 006f7020  56                   push esi
// 006f7021  8bf1                 mov esi, ecx
// 006f7023  8b461c               mov eax, dword ptr [esi + 0x1c]
// 006f7026  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f7029  03c8                 add ecx, eax
// 006f702b  f6c101               test cl, 1
// 006f702e  7513                 jne 0x6f7043
// 006f7030  83c002               add eax, 2
// 006f7033  d1e8                 shr eax, 1
// 006f7035  394614               cmp dword ptr [esi + 0x14], eax
// 006f7038  7709                 ja 0x6f7043
// 006f703a  6a01                 push 1
// 006f703c  8bce                 mov ecx, esi
// 006f703e  e89d890300           call 0x72f9e0
// 006f7043  8b4614               mov eax, dword ptr [esi + 0x14]
// 006f7046  55                   push ebp
// 006f7047  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 006f704a  036e1c               add ebp, dword ptr [esi + 0x1c]
// 006f704d  57                   push edi
// 006f704e  8bfd                 mov edi, ebp
// 006f7050  d1ef                 shr edi, 1
// 006f7052  3bc7                 cmp eax, edi
// 006f7054  7702                 ja 0x6f7058
// 006f7056  2bf8                 sub edi, eax
// 006f7058  8b5610               mov edx, dword ptr [esi + 0x10]
// 006f705b  833cba00             cmp dword ptr [edx + edi*4], 0
// 006f705f  7510                 jne 0x6f7071
// 006f7061  6a10                 push 0x10
// 006f7063  e8f8c70f00           call 0x7f3860
// 006f7068  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006f706b  83c404               add esp, 4
// 006f706e  8904b9               mov dword ptr [ecx + edi*4], eax
// 006f7071  8b5610               mov edx, dword ptr [esi + 0x10]
// 006f7074  8b04ba               mov eax, dword ptr [edx + edi*4]
// 006f7077  83e501               and ebp, 1
// 006f707a  8d04e8               lea eax, [eax + ebp*8]
// 006f707d  5f                   pop edi
// 006f707e  5d                   pop ebp
// 006f707f  85c0                 test eax, eax
// 006f7081  741e                 je 0x6f70a1
// 006f7083  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006f7087  8b11                 mov edx, dword ptr [ecx]
// 006f7089  8910                 mov dword ptr [eax], edx
// 006f708b  8b4904               mov ecx, dword ptr [ecx + 4]
// 006f708e  894804               mov dword ptr [eax + 4], ecx
// 006f7091  85c9                 test ecx, ecx
// 006f7093  740c                 je 0x6f70a1
// 006f7095  83c108               add ecx, 8
// 006f7098  b801000000           mov eax, 1
// 006f709d  f00fc101             lock xadd dword ptr [ecx], eax
// 006f70a1  ff461c               inc dword ptr [esi + 0x1c]
// 006f70a4  5e                   pop esi
// 006f70a5  c20400               ret 4
// library templates-boost-1_34_1/deque_wp.cpp (function ?push_back@?$deque@V?$weak_ptr@UT@@@boost@@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@std@@QAEXABV?$weak_ptr@UT@@@boost@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_wp.cpp

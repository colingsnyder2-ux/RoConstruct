// from server: 100% by auto
// roc 2009-12 0072fb40  unit: G3D::$$A6AXVVector3::?$signal::slot  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072fb40
//
// 0072fb40  56                   push esi
// 0072fb41  8bf1                 mov esi, ecx
// 0072fb43  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0072fb46  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0072fb49  03c8                 add ecx, eax
// 0072fb4b  f6c101               test cl, 1
// 0072fb4e  7513                 jne 0x72fb63
// 0072fb50  83c002               add eax, 2
// 0072fb53  d1e8                 shr eax, 1
// 0072fb55  394614               cmp dword ptr [esi + 0x14], eax
// 0072fb58  7709                 ja 0x72fb63
// 0072fb5a  6a01                 push 1
// 0072fb5c  8bce                 mov ecx, esi
// 0072fb5e  e87dfeffff           call 0x72f9e0
// 0072fb63  8b4614               mov eax, dword ptr [esi + 0x14]
// 0072fb66  55                   push ebp
// 0072fb67  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0072fb6a  036e1c               add ebp, dword ptr [esi + 0x1c]
// 0072fb6d  57                   push edi
// 0072fb6e  8bfd                 mov edi, ebp
// 0072fb70  d1ef                 shr edi, 1
// 0072fb72  3bc7                 cmp eax, edi
// 0072fb74  7702                 ja 0x72fb78
// 0072fb76  2bf8                 sub edi, eax
// 0072fb78  8b5610               mov edx, dword ptr [esi + 0x10]
// 0072fb7b  833cba00             cmp dword ptr [edx + edi*4], 0
// 0072fb7f  7510                 jne 0x72fb91
// 0072fb81  6a10                 push 0x10
// 0072fb83  e8d83c0c00           call 0x7f3860
// 0072fb88  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0072fb8b  83c404               add esp, 4
// 0072fb8e  8904b9               mov dword ptr [ecx + edi*4], eax
// 0072fb91  8b5610               mov edx, dword ptr [esi + 0x10]
// 0072fb94  8b04ba               mov eax, dword ptr [edx + edi*4]
// 0072fb97  83e501               and ebp, 1
// 0072fb9a  8d04e8               lea eax, [eax + ebp*8]
// 0072fb9d  5f                   pop edi
// 0072fb9e  5d                   pop ebp
// 0072fb9f  85c0                 test eax, eax
// 0072fba1  741e                 je 0x72fbc1
// 0072fba3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0072fba7  8b11                 mov edx, dword ptr [ecx]
// 0072fba9  8910                 mov dword ptr [eax], edx
// 0072fbab  8b4904               mov ecx, dword ptr [ecx + 4]
// 0072fbae  894804               mov dword ptr [eax + 4], ecx
// 0072fbb1  85c9                 test ecx, ecx
// 0072fbb3  740c                 je 0x72fbc1
// 0072fbb5  83c104               add ecx, 4
// 0072fbb8  b801000000           mov eax, 1
// 0072fbbd  f00fc101             lock xadd dword ptr [ecx], eax
// 0072fbc1  ff461c               inc dword ptr [esi + 0x1c]
// 0072fbc4  5e                   pop esi
// 0072fbc5  c20400               ret 4
// library templates-boost-1_34_1/deque_sp.cpp (function ?push_back@?$deque@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@QAEXABV?$shared_ptr@UT@@@boost@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_sp.cpp

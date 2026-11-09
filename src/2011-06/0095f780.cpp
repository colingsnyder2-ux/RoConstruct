// from server: 100% by auto
// roc 2011-06 0095f780  unit: Ogre::RbxSceneUpdater  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0095f780
//
// 0095f780  53                   push ebx
// 0095f781  56                   push esi
// 0095f782  8bf1                 mov esi, ecx
// 0095f784  33db                 xor ebx, ebx
// 0095f786  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0095f789  741c                 je 0x95f7a7
// 0095f78b  eb03                 jmp 0x95f790
// 0095f78d  8d4900               lea ecx, [ecx]
// 0095f790  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0095f793  3bc3                 cmp eax, ebx
// 0095f795  740b                 je 0x95f7a2
// 0095f797  48                   dec eax
// 0095f798  89461c               mov dword ptr [esi + 0x1c], eax
// 0095f79b  3bc3                 cmp eax, ebx
// 0095f79d  7503                 jne 0x95f7a2
// 0095f79f  895e18               mov dword ptr [esi + 0x18], ebx
// 0095f7a2  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0095f7a5  75e9                 jne 0x95f790
// 0095f7a7  57                   push edi
// 0095f7a8  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0095f7ab  3bfb                 cmp edi, ebx
// 0095f7ad  761c                 jbe 0x95f7cb
// 0095f7af  90                   nop 
// 0095f7b0  8b4610               mov eax, dword ptr [esi + 0x10]
// 0095f7b3  4f                   dec edi
// 0095f7b4  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0095f7b7  8d04b8               lea eax, [eax + edi*4]
// 0095f7ba  740b                 je 0x95f7c7
// 0095f7bc  8b08                 mov ecx, dword ptr [eax]
// 0095f7be  51                   push ecx
// 0095f7bf  e894a8eaff           call 0x80a058
// 0095f7c4  83c404               add esp, 4
// 0095f7c7  3bfb                 cmp edi, ebx
// 0095f7c9  77e5                 ja 0x95f7b0
// 0095f7cb  8b4610               mov eax, dword ptr [esi + 0x10]
// 0095f7ce  5f                   pop edi
// 0095f7cf  3bc3                 cmp eax, ebx
// 0095f7d1  7409                 je 0x95f7dc
// 0095f7d3  50                   push eax
// 0095f7d4  e87fa8eaff           call 0x80a058
// 0095f7d9  83c404               add esp, 4
// 0095f7dc  895e10               mov dword ptr [esi + 0x10], ebx
// 0095f7df  895e14               mov dword ptr [esi + 0x14], ebx
// 0095f7e2  5e                   pop esi
// 0095f7e3  5b                   pop ebx
// 0095f7e4  c3                   ret 
// standard library deque<ptr> (function ?_Tidy@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;

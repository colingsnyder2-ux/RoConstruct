// from server: 100% by auto
// roc 2012-06 00422130  unit: RBX::DS::CAudioStream  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00422130
//
// 00422130  56                   push esi
// 00422131  8bf1                 mov esi, ecx
// 00422133  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00422136  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00422139  03c8                 add ecx, eax
// 0042213b  f6c101               test cl, 1
// 0042213e  7513                 jne 0x422153
// 00422140  83c002               add eax, 2
// 00422143  d1e8                 shr eax, 1
// 00422145  394614               cmp dword ptr [esi + 0x14], eax
// 00422148  7709                 ja 0x422153
// 0042214a  6a01                 push 1
// 0042214c  8bce                 mov ecx, esi
// 0042214e  e81d592b00           call 0x6d7a70
// 00422153  8b4614               mov eax, dword ptr [esi + 0x14]
// 00422156  55                   push ebp
// 00422157  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0042215a  036e1c               add ebp, dword ptr [esi + 0x1c]
// 0042215d  57                   push edi
// 0042215e  8bfd                 mov edi, ebp
// 00422160  d1ef                 shr edi, 1
// 00422162  3bc7                 cmp eax, edi
// 00422164  7702                 ja 0x422168
// 00422166  2bf8                 sub edi, eax
// 00422168  8b5610               mov edx, dword ptr [esi + 0x10]
// 0042216b  833cba00             cmp dword ptr [edx + edi*4], 0
// 0042216f  7510                 jne 0x422181
// 00422171  6a10                 push 0x10
// 00422173  e8a2ff5500           call 0x98211a
// 00422178  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0042217b  83c404               add esp, 4
// 0042217e  8904b9               mov dword ptr [ecx + edi*4], eax
// 00422181  8b5610               mov edx, dword ptr [esi + 0x10]
// 00422184  8b04ba               mov eax, dword ptr [edx + edi*4]
// 00422187  83e501               and ebp, 1
// 0042218a  8d04e8               lea eax, [eax + ebp*8]
// 0042218d  5f                   pop edi
// 0042218e  5d                   pop ebp
// 0042218f  85c0                 test eax, eax
// 00422191  740e                 je 0x4221a1
// 00422193  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00422197  8b11                 mov edx, dword ptr [ecx]
// 00422199  8910                 mov dword ptr [eax], edx
// 0042219b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0042219e  894804               mov dword ptr [eax + 4], ecx
// 004221a1  ff461c               inc dword ptr [esi + 0x1c]
// 004221a4  5e                   pop esi
// 004221a5  c20400               ret 4
// standard library deque<i64> (function ?push_back@?$deque@_JV?$allocator@_J@std@@@std@@QAEXAB_J@Z)

// stl: deque<i64>
typedef __int64 E;
#include <deque>
template class std::deque<E>;

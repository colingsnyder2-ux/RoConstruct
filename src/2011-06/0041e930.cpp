// from server: 100% by auto
// roc 2011-06 0041e930  unit: RBX::DS::CAudioStream  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0041e930
//
// 0041e930  56                   push esi
// 0041e931  8bf1                 mov esi, ecx
// 0041e933  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0041e936  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041e939  03c8                 add ecx, eax
// 0041e93b  f6c101               test cl, 1
// 0041e93e  7513                 jne 0x41e953
// 0041e940  83c002               add eax, 2
// 0041e943  d1e8                 shr eax, 1
// 0041e945  394614               cmp dword ptr [esi + 0x14], eax
// 0041e948  7709                 ja 0x41e953
// 0041e94a  6a01                 push 1
// 0041e94c  8bce                 mov ecx, esi
// 0041e94e  e8adf5ffff           call 0x41df00
// 0041e953  8b4614               mov eax, dword ptr [esi + 0x14]
// 0041e956  55                   push ebp
// 0041e957  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0041e95a  036e1c               add ebp, dword ptr [esi + 0x1c]
// 0041e95d  57                   push edi
// 0041e95e  8bfd                 mov edi, ebp
// 0041e960  d1ef                 shr edi, 1
// 0041e962  3bc7                 cmp eax, edi
// 0041e964  7702                 ja 0x41e968
// 0041e966  2bf8                 sub edi, eax
// 0041e968  8b5610               mov edx, dword ptr [esi + 0x10]
// 0041e96b  833cba00             cmp dword ptr [edx + edi*4], 0
// 0041e96f  7510                 jne 0x41e981
// 0041e971  6a10                 push 0x10
// 0041e973  e8e6b63e00           call 0x80a05e
// 0041e978  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0041e97b  83c404               add esp, 4
// 0041e97e  8904b9               mov dword ptr [ecx + edi*4], eax
// 0041e981  8b5610               mov edx, dword ptr [esi + 0x10]
// 0041e984  8b04ba               mov eax, dword ptr [edx + edi*4]
// 0041e987  83e501               and ebp, 1
// 0041e98a  8d04e8               lea eax, [eax + ebp*8]
// 0041e98d  5f                   pop edi
// 0041e98e  5d                   pop ebp
// 0041e98f  85c0                 test eax, eax
// 0041e991  740e                 je 0x41e9a1
// 0041e993  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041e997  8b11                 mov edx, dword ptr [ecx]
// 0041e999  8910                 mov dword ptr [eax], edx
// 0041e99b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0041e99e  894804               mov dword ptr [eax + 4], ecx
// 0041e9a1  ff461c               inc dword ptr [esi + 0x1c]
// 0041e9a4  5e                   pop esi
// 0041e9a5  c20400               ret 4
// standard library deque<i64> (function ?push_back@?$deque@_JV?$allocator@_J@std@@@std@@QAEXAB_J@Z)

// stl: deque<i64>
typedef __int64 E;
#include <deque>
template class std::deque<E>;

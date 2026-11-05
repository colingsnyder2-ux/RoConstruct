// from server: 100% by auto
// roc 2009-06 004e8520  unit: RBX::JointsService  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8520
//
// 004e8520  56                   push esi
// 004e8521  8bf1                 mov esi, ecx
// 004e8523  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004e8526  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004e8529  03c8                 add ecx, eax
// 004e852b  f6c103               test cl, 3
// 004e852e  7514                 jne 0x4e8544
// 004e8530  83c004               add eax, 4
// 004e8533  c1e802               shr eax, 2
// 004e8536  394614               cmp dword ptr [esi + 0x14], eax
// 004e8539  7709                 ja 0x4e8544
// 004e853b  6a01                 push 1
// 004e853d  8bce                 mov ecx, esi
// 004e853f  e81cedffff           call 0x4e7260
// 004e8544  8b4614               mov eax, dword ptr [esi + 0x14]
// 004e8547  53                   push ebx
// 004e8548  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004e854b  035e1c               add ebx, dword ptr [esi + 0x1c]
// 004e854e  57                   push edi
// 004e854f  8bfb                 mov edi, ebx
// 004e8551  c1ef02               shr edi, 2
// 004e8554  3bc7                 cmp eax, edi
// 004e8556  7702                 ja 0x4e855a
// 004e8558  2bf8                 sub edi, eax
// 004e855a  8b5610               mov edx, dword ptr [esi + 0x10]
// 004e855d  833cba00             cmp dword ptr [edx + edi*4], 0
// 004e8561  7510                 jne 0x4e8573
// 004e8563  6a10                 push 0x10
// 004e8565  e8ce042300           call 0x718a38
// 004e856a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004e856d  83c404               add esp, 4
// 004e8570  8904b9               mov dword ptr [ecx + edi*4], eax
// 004e8573  8b5610               mov edx, dword ptr [esi + 0x10]
// 004e8576  8b04ba               mov eax, dword ptr [edx + edi*4]
// 004e8579  83e303               and ebx, 3
// 004e857c  8d0498               lea eax, [eax + ebx*4]
// 004e857f  5f                   pop edi
// 004e8580  5b                   pop ebx
// 004e8581  85c0                 test eax, eax
// 004e8583  7408                 je 0x4e858d
// 004e8585  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e8589  8b11                 mov edx, dword ptr [ecx]
// 004e858b  8910                 mov dword ptr [eax], edx
// 004e858d  ff461c               inc dword ptr [esi + 0x1c]
// 004e8590  5e                   pop esi
// 004e8591  c20400               ret 4
// standard library deque<ptr> (function ?push_back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;

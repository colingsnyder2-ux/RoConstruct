// from server: 100% by auto
// roc 2008-06 00589330  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00589330
//
// 00589330  56                   push esi
// 00589331  8bf1                 mov esi, ecx
// 00589333  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00589336  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00589339  03c8                 add ecx, eax
// 0058933b  f6c103               test cl, 3
// 0058933e  7514                 jne 0x589354
// 00589340  83c004               add eax, 4
// 00589343  c1e802               shr eax, 2
// 00589346  394614               cmp dword ptr [esi + 0x14], eax
// 00589349  7709                 ja 0x589354
// 0058934b  6a01                 push 1
// 0058934d  8bce                 mov ecx, esi
// 0058934f  e8acd4eaff           call 0x436800
// 00589354  8b4614               mov eax, dword ptr [esi + 0x14]
// 00589357  53                   push ebx
// 00589358  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0058935b  035e1c               add ebx, dword ptr [esi + 0x1c]
// 0058935e  57                   push edi
// 0058935f  8bfb                 mov edi, ebx
// 00589361  c1ef02               shr edi, 2
// 00589364  3bc7                 cmp eax, edi
// 00589366  7702                 ja 0x58936a
// 00589368  2bf8                 sub edi, eax
// 0058936a  8b5610               mov edx, dword ptr [esi + 0x10]
// 0058936d  833cba00             cmp dword ptr [edx + edi*4], 0
// 00589371  7510                 jne 0x589383
// 00589373  6a10                 push 0x10
// 00589375  e8a6751100           call 0x6a0920
// 0058937a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0058937d  83c404               add esp, 4
// 00589380  8904b9               mov dword ptr [ecx + edi*4], eax
// 00589383  8b5610               mov edx, dword ptr [esi + 0x10]
// 00589386  8b04ba               mov eax, dword ptr [edx + edi*4]
// 00589389  83e303               and ebx, 3
// 0058938c  8d0498               lea eax, [eax + ebx*4]
// 0058938f  5f                   pop edi
// 00589390  5b                   pop ebx
// 00589391  85c0                 test eax, eax
// 00589393  7408                 je 0x58939d
// 00589395  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00589399  8b11                 mov edx, dword ptr [ecx]
// 0058939b  8910                 mov dword ptr [eax], edx
// 0058939d  ff461c               inc dword ptr [esi + 0x1c]
// 005893a0  5e                   pop esi
// 005893a1  c20400               ret 4
// standard library deque<ptr> (function ?push_back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;

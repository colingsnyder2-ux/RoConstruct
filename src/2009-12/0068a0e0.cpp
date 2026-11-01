// from server: 100% by auto
// roc 2009-12 0068a0e0  unit: TextXmlWriterWithEmbeddedContent  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068a0e0
//
// 0068a0e0  56                   push esi
// 0068a0e1  8bf1                 mov esi, ecx
// 0068a0e3  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0068a0e6  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0068a0e9  03c8                 add ecx, eax
// 0068a0eb  f6c103               test cl, 3
// 0068a0ee  7514                 jne 0x68a104
// 0068a0f0  83c004               add eax, 4
// 0068a0f3  c1e802               shr eax, 2
// 0068a0f6  394614               cmp dword ptr [esi + 0x14], eax
// 0068a0f9  7709                 ja 0x68a104
// 0068a0fb  6a01                 push 1
// 0068a0fd  8bce                 mov ecx, esi
// 0068a0ff  e8dcfaffff           call 0x689be0
// 0068a104  8b4614               mov eax, dword ptr [esi + 0x14]
// 0068a107  53                   push ebx
// 0068a108  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0068a10b  035e1c               add ebx, dword ptr [esi + 0x1c]
// 0068a10e  57                   push edi
// 0068a10f  8bfb                 mov edi, ebx
// 0068a111  c1ef02               shr edi, 2
// 0068a114  3bc7                 cmp eax, edi
// 0068a116  7702                 ja 0x68a11a
// 0068a118  2bf8                 sub edi, eax
// 0068a11a  8b5610               mov edx, dword ptr [esi + 0x10]
// 0068a11d  833cba00             cmp dword ptr [edx + edi*4], 0
// 0068a121  7510                 jne 0x68a133
// 0068a123  6a10                 push 0x10
// 0068a125  e836971600           call 0x7f3860
// 0068a12a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0068a12d  83c404               add esp, 4
// 0068a130  8904b9               mov dword ptr [ecx + edi*4], eax
// 0068a133  8b5610               mov edx, dword ptr [esi + 0x10]
// 0068a136  8b04ba               mov eax, dword ptr [edx + edi*4]
// 0068a139  83e303               and ebx, 3
// 0068a13c  8d0498               lea eax, [eax + ebx*4]
// 0068a13f  5f                   pop edi
// 0068a140  5b                   pop ebx
// 0068a141  85c0                 test eax, eax
// 0068a143  7408                 je 0x68a14d
// 0068a145  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068a149  8b11                 mov edx, dword ptr [ecx]
// 0068a14b  8910                 mov dword ptr [eax], edx
// 0068a14d  ff461c               inc dword ptr [esi + 0x1c]
// 0068a150  5e                   pop esi
// 0068a151  c20400               ret 4
// standard library deque<ptr> (function ?push_back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;

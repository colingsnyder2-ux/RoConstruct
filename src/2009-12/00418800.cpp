// from server: 100% by auto
// roc 2009-12 00418800  unit: RBX::VTool::?$FactoryProduct::Creator  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00418800
//
// 00418800  64a100000000         mov eax, dword ptr fs:[0]
// 00418806  6aff                 push -1
// 00418808  68012b9300           push 0x932b01
// 0041880d  50                   push eax
// 0041880e  64892500000000       mov dword ptr fs:[0], esp
// 00418815  83ec08               sub esp, 8
// 00418818  56                   push esi
// 00418819  8bf1                 mov esi, ecx
// 0041881b  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0041881e  40                   inc eax
// 0041881f  394614               cmp dword ptr [esi + 0x14], eax
// 00418822  7707                 ja 0x41882b
// 00418824  6a01                 push 1
// 00418826  e825feffff           call 0x418650
// 0041882b  8b4614               mov eax, dword ptr [esi + 0x14]
// 0041882e  57                   push edi
// 0041882f  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00418832  037e1c               add edi, dword ptr [esi + 0x1c]
// 00418835  3bc7                 cmp eax, edi
// 00418837  7702                 ja 0x41883b
// 00418839  2bf8                 sub edi, eax
// 0041883b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0041883e  833cb900             cmp dword ptr [ecx + edi*4], 0
// 00418842  7510                 jne 0x418854
// 00418844  6a1c                 push 0x1c
// 00418846  e815b03d00           call 0x7f3860
// 0041884b  8b5610               mov edx, dword ptr [esi + 0x10]
// 0041884e  83c404               add esp, 4
// 00418851  8904ba               mov dword ptr [edx + edi*4], eax
// 00418854  8b4610               mov eax, dword ptr [esi + 0x10]
// 00418857  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0041885a  894c2408             mov dword ptr [esp + 8], ecx
// 0041885e  894c240c             mov dword ptr [esp + 0xc], ecx
// 00418862  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0041886a  5f                   pop edi
// 0041886b  85c9                 test ecx, ecx
// 0041886d  740b                 je 0x41887a
// 0041886f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00418873  52                   push edx
// 00418874  ff15f0b69800         call dword ptr [0x98b6f0]
// 0041887a  ff461c               inc dword ptr [esi + 0x1c]
// 0041887d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00418881  5e                   pop esi
// 00418882  64890d00000000       mov dword ptr fs:[0], ecx
// 00418889  83c414               add esp, 0x14
// 0041888c  c20400               ret 4
// standard library deque<string> (function ?push_back@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;

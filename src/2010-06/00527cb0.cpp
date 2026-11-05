// from server: 100% by auto
// roc 2010-06 00527cb0  unit: G3D::VVector3::?$Table  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00527cb0
//
// 00527cb0  6aff                 push -1
// 00527cb2  6858a29900           push 0x99a258
// 00527cb7  64a100000000         mov eax, dword ptr fs:[0]
// 00527cbd  50                   push eax
// 00527cbe  64892500000000       mov dword ptr fs:[0], esp
// 00527cc5  51                   push ecx
// 00527cc6  56                   push esi
// 00527cc7  8bf1                 mov esi, ecx
// 00527cc9  6a04                 push 4
// 00527ccb  89742408             mov dword ptr [esp + 8], esi
// 00527ccf  e8ccfc2700           call 0x7a79a0
// 00527cd4  83c404               add esp, 4
// 00527cd7  85c0                 test eax, eax
// 00527cd9  7404                 je 0x527cdf
// 00527cdb  8930                 mov dword ptr [eax], esi
// 00527cdd  eb02                 jmp 0x527ce1
// 00527cdf  33c0                 xor eax, eax
// 00527ce1  8906                 mov dword ptr [esi], eax
// 00527ce3  8bce                 mov ecx, esi
// 00527ce5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00527ced  e89eb63b00           call 0x8e3390
// 00527cf2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00527cf6  894618               mov dword ptr [esi + 0x18], eax
// 00527cf9  c6402101             mov byte ptr [eax + 0x21], 1
// 00527cfd  8b4618               mov eax, dword ptr [esi + 0x18]
// 00527d00  894004               mov dword ptr [eax + 4], eax
// 00527d03  8b4618               mov eax, dword ptr [esi + 0x18]
// 00527d06  8900                 mov dword ptr [eax], eax
// 00527d08  8b4618               mov eax, dword ptr [esi + 0x18]
// 00527d0b  894008               mov dword ptr [eax + 8], eax
// 00527d0e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00527d15  8bc6                 mov eax, esi
// 00527d17  5e                   pop esi
// 00527d18  64890d00000000       mov dword ptr fs:[0], ecx
// 00527d1f  83c410               add esp, 0x10
// 00527d22  c20800               ret 8
// standard library set<pod20> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

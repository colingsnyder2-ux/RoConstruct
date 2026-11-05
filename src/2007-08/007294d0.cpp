// from server: 100% by auto
// roc 2007-08 007294d0  unit: boost::signals::detail::Ubasic_connection::?$sp_counted_impl_p  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007294d0
//
// 007294d0  55                   push ebp
// 007294d1  8bec                 mov ebp, esp
// 007294d3  6aff                 push -1
// 007294d5  6890bb7600           push 0x76bb90
// 007294da  64a100000000         mov eax, dword ptr fs:[0]
// 007294e0  50                   push eax
// 007294e1  83ec08               sub esp, 8
// 007294e4  53                   push ebx
// 007294e5  56                   push esi
// 007294e6  57                   push edi
// 007294e7  a188518b00           mov eax, dword ptr [0x8b5188]
// 007294ec  33c5                 xor eax, ebp
// 007294ee  50                   push eax
// 007294ef  8d45f4               lea eax, [ebp - 0xc]
// 007294f2  64a300000000         mov dword ptr fs:[0], eax
// 007294f8  8965f0               mov dword ptr [ebp - 0x10], esp
// 007294fb  8bf1                 mov esi, ecx
// 007294fd  8975ec               mov dword ptr [ebp - 0x14], esi
// 00729500  e83bf7ffff           call 0x728c40
// 00729505  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00729508  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0072950b  53                   push ebx
// 0072950c  894604               mov dword ptr [esi + 4], eax
// 0072950f  c7460800000000       mov dword ptr [esi + 8], 0
// 00729516  8b5104               mov edx, dword ptr [ecx + 4]
// 00729519  8b3a                 mov edi, dword ptr [edx]
// 0072951b  8b00                 mov eax, dword ptr [eax]
// 0072951d  52                   push edx
// 0072951e  51                   push ecx
// 0072951f  57                   push edi
// 00729520  51                   push ecx
// 00729521  50                   push eax
// 00729522  56                   push esi
// 00729523  8bce                 mov ecx, esi
// 00729525  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0072952c  e8fffcffff           call 0x729230
// 00729531  8bc6                 mov eax, esi
// 00729533  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00729536  64890d00000000       mov dword ptr fs:[0], ecx
// 0072953d  59                   pop ecx
// 0072953e  5f                   pop edi
// 0072953f  5e                   pop esi
// 00729540  5b                   pop ebx
// 00729541  8be5                 mov esp, ebp
// 00729543  5d                   pop ebp
// 00729544  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;

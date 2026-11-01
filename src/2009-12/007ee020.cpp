// from server: 100% by auto
// roc 2009-12 007ee020  unit: W4_D3DFORMAT::?$EnumDesc  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ee020
//
// 007ee020  83ec08               sub esp, 8
// 007ee023  53                   push ebx
// 007ee024  55                   push ebp
// 007ee025  56                   push esi
// 007ee026  8bf1                 mov esi, ecx
// 007ee028  8b4610               mov eax, dword ptr [esi + 0x10]
// 007ee02b  57                   push edi
// 007ee02c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007ee02f  8bc8                 mov ecx, eax
// 007ee031  2bcf                 sub ecx, edi
// 007ee033  f7c1fcffffff         test ecx, 0xfffffffc
// 007ee039  7504                 jne 0x7ee03f
// 007ee03b  33db                 xor ebx, ebx
// 007ee03d  eb27                 jmp 0x7ee066
// 007ee03f  3bf8                 cmp edi, eax
// 007ee041  7606                 jbe 0x7ee049
// 007ee043  ff1560b79800         call dword ptr [0x98b760]
// 007ee049  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ee04d  8b06                 mov eax, dword ptr [esi]
// 007ee04f  85c9                 test ecx, ecx
// 007ee051  7404                 je 0x7ee057
// 007ee053  3bc8                 cmp ecx, eax
// 007ee055  7406                 je 0x7ee05d
// 007ee057  ff1560b79800         call dword ptr [0x98b760]
// 007ee05d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007ee061  2bdf                 sub ebx, edi
// 007ee063  c1fb02               sar ebx, 2
// 007ee066  8b542428             mov edx, dword ptr [esp + 0x28]
// 007ee06a  8b442424             mov eax, dword ptr [esp + 0x24]
// 007ee06e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ee072  52                   push edx
// 007ee073  6a01                 push 1
// 007ee075  50                   push eax
// 007ee076  51                   push ecx
// 007ee077  8bce                 mov ecx, esi
// 007ee079  e852fdffff           call 0x7eddd0
// 007ee07e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007ee081  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 007ee084  7606                 jbe 0x7ee08c
// 007ee086  ff1560b79800         call dword ptr [0x98b760]
// 007ee08c  8b36                 mov esi, dword ptr [esi]
// 007ee08e  8bee                 mov ebp, esi
// 007ee090  897c2414             mov dword ptr [esp + 0x14], edi
// 007ee094  85f6                 test esi, esi
// 007ee096  7518                 jne 0x7ee0b0
// 007ee098  ff1560b79800         call dword ptr [0x98b760]
// 007ee09e  33c0                 xor eax, eax
// 007ee0a0  8d3c9f               lea edi, [edi + ebx*4]
// 007ee0a3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007ee0a6  7713                 ja 0x7ee0bb
// 007ee0a8  85f6                 test esi, esi
// 007ee0aa  7408                 je 0x7ee0b4
// 007ee0ac  8b36                 mov esi, dword ptr [esi]
// 007ee0ae  eb06                 jmp 0x7ee0b6
// 007ee0b0  8b06                 mov eax, dword ptr [esi]
// 007ee0b2  ebec                 jmp 0x7ee0a0
// 007ee0b4  33f6                 xor esi, esi
// 007ee0b6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007ee0b9  7306                 jae 0x7ee0c1
// 007ee0bb  ff1560b79800         call dword ptr [0x98b760]
// 007ee0c1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ee0c5  897804               mov dword ptr [eax + 4], edi
// 007ee0c8  5f                   pop edi
// 007ee0c9  5e                   pop esi
// 007ee0ca  8928                 mov dword ptr [eax], ebp
// 007ee0cc  5d                   pop ebp
// 007ee0cd  5b                   pop ebx
// 007ee0ce  83c408               add esp, 8
// 007ee0d1  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;

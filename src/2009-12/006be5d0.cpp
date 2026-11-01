// from server: 100% by auto
// roc 2009-12 006be5d0  unit: RBX::VInstance::?$NonFactoryProduct  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006be5d0
//
// 006be5d0  83ec08               sub esp, 8
// 006be5d3  8b442410             mov eax, dword ptr [esp + 0x10]
// 006be5d7  53                   push ebx
// 006be5d8  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006be5de  56                   push esi
// 006be5df  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006be5e3  57                   push edi
// 006be5e4  8bf9                 mov edi, ecx
// 006be5e6  8944240c             mov dword ptr [esp + 0xc], eax
// 006be5ea  85c0                 test eax, eax
// 006be5ec  750a                 jne 0x6be5f8
// 006be5ee  ffd3                 call ebx
// 006be5f0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006be5f4  85c0                 test eax, eax
// 006be5f6  7404                 je 0x6be5fc
// 006be5f8  8b00                 mov eax, dword ptr [eax]
// 006be5fa  eb02                 jmp 0x6be5fe
// 006be5fc  33c0                 xor eax, eax
// 006be5fe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006be602  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 006be605  7502                 jne 0x6be609
// 006be607  ffd3                 call ebx
// 006be609  8b542420             mov edx, dword ptr [esp + 0x20]
// 006be60d  8b02                 mov eax, dword ptr [edx]
// 006be60f  89442420             mov dword ptr [esp + 0x20], eax
// 006be613  3b7714               cmp esi, dword ptr [edi + 0x14]
// 006be616  7424                 je 0x6be63c
// 006be618  8b4e04               mov ecx, dword ptr [esi + 4]
// 006be61b  8b16                 mov edx, dword ptr [esi]
// 006be61d  8911                 mov dword ptr [ecx], edx
// 006be61f  8b4e04               mov ecx, dword ptr [esi + 4]
// 006be622  8b06                 mov eax, dword ptr [esi]
// 006be624  894804               mov dword ptr [eax + 4], ecx
// 006be627  8d4e08               lea ecx, [esi + 8]
// 006be62a  ff15e4b69800         call dword ptr [0x98b6e4]
// 006be630  56                   push esi
// 006be631  e824521300           call 0x7f385a
// 006be636  83c404               add esp, 4
// 006be639  ff4f18               dec dword ptr [edi + 0x18]
// 006be63c  8b0f                 mov ecx, dword ptr [edi]
// 006be63e  8b442418             mov eax, dword ptr [esp + 0x18]
// 006be642  8b542420             mov edx, dword ptr [esp + 0x20]
// 006be646  5f                   pop edi
// 006be647  5e                   pop esi
// 006be648  895004               mov dword ptr [eax + 4], edx
// 006be64b  8908                 mov dword ptr [eax], ecx
// 006be64d  5b                   pop ebx
// 006be64e  83c408               add esp, 8
// 006be651  c20c00               ret 0xc
// standard library list<string> (function ?erase@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;

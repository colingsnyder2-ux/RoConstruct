// from server: 100% by auto
// roc 2009-12 004fe650  unit: RBX::Network::Player::W4BuildPermission::?$EnumDesc  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004fe650
//
// 004fe650  8b542404             mov edx, dword ptr [esp + 4]
// 004fe654  3bca                 cmp ecx, edx
// 004fe656  7452                 je 0x4fe6aa
// 004fe658  8b01                 mov eax, dword ptr [ecx]
// 004fe65a  53                   push ebx
// 004fe65b  56                   push esi
// 004fe65c  8b32                 mov esi, dword ptr [edx]
// 004fe65e  8931                 mov dword ptr [ecx], esi
// 004fe660  8902                 mov dword ptr [edx], eax
// 004fe662  8b31                 mov esi, dword ptr [ecx]
// 004fe664  57                   push edi
// 004fe665  3bf0                 cmp esi, eax
// 004fe667  7408                 je 0x4fe671
// 004fe669  8b18                 mov ebx, dword ptr [eax]
// 004fe66b  8b3e                 mov edi, dword ptr [esi]
// 004fe66d  891e                 mov dword ptr [esi], ebx
// 004fe66f  8938                 mov dword ptr [eax], edi
// 004fe671  8d420c               lea eax, [edx + 0xc]
// 004fe674  8d710c               lea esi, [ecx + 0xc]
// 004fe677  3bf0                 cmp esi, eax
// 004fe679  7408                 je 0x4fe683
// 004fe67b  8b18                 mov ebx, dword ptr [eax]
// 004fe67d  8b3e                 mov edi, dword ptr [esi]
// 004fe67f  891e                 mov dword ptr [esi], ebx
// 004fe681  8938                 mov dword ptr [eax], edi
// 004fe683  8d4210               lea eax, [edx + 0x10]
// 004fe686  8d7110               lea esi, [ecx + 0x10]
// 004fe689  3bf0                 cmp esi, eax
// 004fe68b  7408                 je 0x4fe695
// 004fe68d  8b18                 mov ebx, dword ptr [eax]
// 004fe68f  8b3e                 mov edi, dword ptr [esi]
// 004fe691  891e                 mov dword ptr [esi], ebx
// 004fe693  8938                 mov dword ptr [eax], edi
// 004fe695  8d4214               lea eax, [edx + 0x14]
// 004fe698  83c114               add ecx, 0x14
// 004fe69b  3bc8                 cmp ecx, eax
// 004fe69d  7408                 je 0x4fe6a7
// 004fe69f  8b30                 mov esi, dword ptr [eax]
// 004fe6a1  8b11                 mov edx, dword ptr [ecx]
// 004fe6a3  8931                 mov dword ptr [ecx], esi
// 004fe6a5  8910                 mov dword ptr [eax], edx
// 004fe6a7  5f                   pop edi
// 004fe6a8  5e                   pop esi
// 004fe6a9  5b                   pop ebx
// 004fe6aa  c20400               ret 4
// standard library vector<char> (function ?swap@?$vector@DV?$allocator@D@std@@@std@@QAEXAAV12@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;

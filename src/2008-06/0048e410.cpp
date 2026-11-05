// from server: 100% by auto
// roc 2008-06 0048e410  unit: RBX::Network::VPlayer::?$SignalDesc  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048e410
//
// 0048e410  8b542404             mov edx, dword ptr [esp + 4]
// 0048e414  3bca                 cmp ecx, edx
// 0048e416  7452                 je 0x48e46a
// 0048e418  8b01                 mov eax, dword ptr [ecx]
// 0048e41a  53                   push ebx
// 0048e41b  56                   push esi
// 0048e41c  8b32                 mov esi, dword ptr [edx]
// 0048e41e  8931                 mov dword ptr [ecx], esi
// 0048e420  8902                 mov dword ptr [edx], eax
// 0048e422  8b31                 mov esi, dword ptr [ecx]
// 0048e424  57                   push edi
// 0048e425  3bf0                 cmp esi, eax
// 0048e427  7408                 je 0x48e431
// 0048e429  8b18                 mov ebx, dword ptr [eax]
// 0048e42b  8b3e                 mov edi, dword ptr [esi]
// 0048e42d  891e                 mov dword ptr [esi], ebx
// 0048e42f  8938                 mov dword ptr [eax], edi
// 0048e431  8d420c               lea eax, [edx + 0xc]
// 0048e434  8d710c               lea esi, [ecx + 0xc]
// 0048e437  3bf0                 cmp esi, eax
// 0048e439  7408                 je 0x48e443
// 0048e43b  8b18                 mov ebx, dword ptr [eax]
// 0048e43d  8b3e                 mov edi, dword ptr [esi]
// 0048e43f  891e                 mov dword ptr [esi], ebx
// 0048e441  8938                 mov dword ptr [eax], edi
// 0048e443  8d4210               lea eax, [edx + 0x10]
// 0048e446  8d7110               lea esi, [ecx + 0x10]
// 0048e449  3bf0                 cmp esi, eax
// 0048e44b  7408                 je 0x48e455
// 0048e44d  8b18                 mov ebx, dword ptr [eax]
// 0048e44f  8b3e                 mov edi, dword ptr [esi]
// 0048e451  891e                 mov dword ptr [esi], ebx
// 0048e453  8938                 mov dword ptr [eax], edi
// 0048e455  8d4214               lea eax, [edx + 0x14]
// 0048e458  83c114               add ecx, 0x14
// 0048e45b  3bc8                 cmp ecx, eax
// 0048e45d  7408                 je 0x48e467
// 0048e45f  8b30                 mov esi, dword ptr [eax]
// 0048e461  8b11                 mov edx, dword ptr [ecx]
// 0048e463  8931                 mov dword ptr [ecx], esi
// 0048e465  8910                 mov dword ptr [eax], edx
// 0048e467  5f                   pop edi
// 0048e468  5e                   pop esi
// 0048e469  5b                   pop ebx
// 0048e46a  c20400               ret 4
// standard library vector<char> (function ?swap@?$vector@DV?$allocator@D@std@@@std@@QAEXAAV12@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;

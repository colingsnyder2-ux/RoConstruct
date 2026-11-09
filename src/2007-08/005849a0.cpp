// from server: 100% by auto
// roc 2007-08 005849a0  unit: RBX::VHat::?$FactoryProduct  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005849a0
//
// 005849a0  8b5104               mov edx, dword ptr [ecx + 4]
// 005849a3  8b4204               mov eax, dword ptr [edx + 4]
// 005849a6  83ec10               sub esp, 0x10
// 005849a9  80781500             cmp byte ptr [eax + 0x15], 0
// 005849ad  53                   push ebx
// 005849ae  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005849b2  56                   push esi
// 005849b3  57                   push edi
// 005849b4  7516                 jne 0x5849cc
// 005849b6  8b33                 mov esi, dword ptr [ebx]
// 005849b8  39700c               cmp dword ptr [eax + 0xc], esi
// 005849bb  7d05                 jge 0x5849c2
// 005849bd  8b4008               mov eax, dword ptr [eax + 8]
// 005849c0  eb04                 jmp 0x5849c6
// 005849c2  8bd0                 mov edx, eax
// 005849c4  8b00                 mov eax, dword ptr [eax]
// 005849c6  80781500             cmp byte ptr [eax + 0x15], 0
// 005849ca  74ec                 je 0x5849b8
// 005849cc  3b5104               cmp edx, dword ptr [ecx + 4]
// 005849cf  8bfa                 mov edi, edx
// 005849d1  8bf1                 mov esi, ecx
// 005849d3  7407                 je 0x5849dc
// 005849d5  8b03                 mov eax, dword ptr [ebx]
// 005849d7  3b420c               cmp eax, dword ptr [edx + 0xc]
// 005849da  7d24                 jge 0x584a00
// 005849dc  8b13                 mov edx, dword ptr [ebx]
// 005849de  8d44240c             lea eax, [esp + 0xc]
// 005849e2  50                   push eax
// 005849e3  57                   push edi
// 005849e4  89542414             mov dword ptr [esp + 0x14], edx
// 005849e8  56                   push esi
// 005849e9  8d542420             lea edx, [esp + 0x20]
// 005849ed  52                   push edx
// 005849ee  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005849f6  e8e5fdffff           call 0x5847e0
// 005849fb  8b30                 mov esi, dword ptr [eax]
// 005849fd  8b7804               mov edi, dword ptr [eax + 4]
// 00584a00  85f6                 test esi, esi
// 00584a02  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 00584a08  7502                 jne 0x584a0c
// 00584a0a  ffd3                 call ebx
// 00584a0c  3b7e04               cmp edi, dword ptr [esi + 4]
// 00584a0f  7502                 jne 0x584a13
// 00584a11  ffd3                 call ebx
// 00584a13  8d4710               lea eax, [edi + 0x10]
// 00584a16  5f                   pop edi
// 00584a17  5e                   pop esi
// 00584a18  5b                   pop ebx
// 00584a19  83c410               add esp, 0x10
// 00584a1c  c20400               ret 4
// standard library map_int<ptr> (function ??A?$map@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@@std@@QAEAAPAUT@@ABH@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

// from server: 100% by auto
// roc 2007-08 004a3e90  unit: boost::Vmutex::?$sp_counted_impl_p  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a3e90
//
// 004a3e90  8b5104               mov edx, dword ptr [ecx + 4]
// 004a3e93  8b4204               mov eax, dword ptr [edx + 4]
// 004a3e96  83ec10               sub esp, 0x10
// 004a3e99  80781500             cmp byte ptr [eax + 0x15], 0
// 004a3e9d  53                   push ebx
// 004a3e9e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004a3ea2  56                   push esi
// 004a3ea3  57                   push edi
// 004a3ea4  7516                 jne 0x4a3ebc
// 004a3ea6  8b33                 mov esi, dword ptr [ebx]
// 004a3ea8  39700c               cmp dword ptr [eax + 0xc], esi
// 004a3eab  7d05                 jge 0x4a3eb2
// 004a3ead  8b4008               mov eax, dword ptr [eax + 8]
// 004a3eb0  eb04                 jmp 0x4a3eb6
// 004a3eb2  8bd0                 mov edx, eax
// 004a3eb4  8b00                 mov eax, dword ptr [eax]
// 004a3eb6  80781500             cmp byte ptr [eax + 0x15], 0
// 004a3eba  74ec                 je 0x4a3ea8
// 004a3ebc  3b5104               cmp edx, dword ptr [ecx + 4]
// 004a3ebf  8bfa                 mov edi, edx
// 004a3ec1  8bf1                 mov esi, ecx
// 004a3ec3  7407                 je 0x4a3ecc
// 004a3ec5  8b03                 mov eax, dword ptr [ebx]
// 004a3ec7  3b420c               cmp eax, dword ptr [edx + 0xc]
// 004a3eca  7d24                 jge 0x4a3ef0
// 004a3ecc  8b13                 mov edx, dword ptr [ebx]
// 004a3ece  8d44240c             lea eax, [esp + 0xc]
// 004a3ed2  50                   push eax
// 004a3ed3  57                   push edi
// 004a3ed4  89542414             mov dword ptr [esp + 0x14], edx
// 004a3ed8  56                   push esi
// 004a3ed9  8d542420             lea edx, [esp + 0x20]
// 004a3edd  52                   push edx
// 004a3ede  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004a3ee6  e815fcffff           call 0x4a3b00
// 004a3eeb  8b30                 mov esi, dword ptr [eax]
// 004a3eed  8b7804               mov edi, dword ptr [eax + 4]
// 004a3ef0  85f6                 test esi, esi
// 004a3ef2  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 004a3ef8  7502                 jne 0x4a3efc
// 004a3efa  ffd3                 call ebx
// 004a3efc  3b7e04               cmp edi, dword ptr [esi + 4]
// 004a3eff  7502                 jne 0x4a3f03
// 004a3f01  ffd3                 call ebx
// 004a3f03  8d4710               lea eax, [edi + 0x10]
// 004a3f06  5f                   pop edi
// 004a3f07  5e                   pop esi
// 004a3f08  5b                   pop ebx
// 004a3f09  83c410               add esp, 0x10
// 004a3f0c  c20400               ret 4
// standard library map_int<ptr> (function ??A?$map@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@@std@@QAEAAPAUT@@ABH@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

// from server: 100% by auto
// roc 2007-03 00581220  unit: seg_00580000  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00581220
//
// 00581220  8b5104               mov edx, dword ptr [ecx + 4]
// 00581223  8b4204               mov eax, dword ptr [edx + 4]
// 00581226  83ec10               sub esp, 0x10
// 00581229  80781500             cmp byte ptr [eax + 0x15], 0
// 0058122d  53                   push ebx
// 0058122e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00581232  56                   push esi
// 00581233  57                   push edi
// 00581234  7516                 jne 0x58124c
// 00581236  8b33                 mov esi, dword ptr [ebx]
// 00581238  39700c               cmp dword ptr [eax + 0xc], esi
// 0058123b  7d05                 jge 0x581242
// 0058123d  8b4008               mov eax, dword ptr [eax + 8]
// 00581240  eb04                 jmp 0x581246
// 00581242  8bd0                 mov edx, eax
// 00581244  8b00                 mov eax, dword ptr [eax]
// 00581246  80781500             cmp byte ptr [eax + 0x15], 0
// 0058124a  74ec                 je 0x581238
// 0058124c  3b5104               cmp edx, dword ptr [ecx + 4]
// 0058124f  8bfa                 mov edi, edx
// 00581251  8bf1                 mov esi, ecx
// 00581253  7407                 je 0x58125c
// 00581255  8b03                 mov eax, dword ptr [ebx]
// 00581257  3b420c               cmp eax, dword ptr [edx + 0xc]
// 0058125a  7d24                 jge 0x581280
// 0058125c  8b13                 mov edx, dword ptr [ebx]
// 0058125e  8d44240c             lea eax, [esp + 0xc]
// 00581262  50                   push eax
// 00581263  57                   push edi
// 00581264  89542414             mov dword ptr [esp + 0x14], edx
// 00581268  56                   push esi
// 00581269  8d542420             lea edx, [esp + 0x20]
// 0058126d  52                   push edx
// 0058126e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00581276  e8b5fdffff           call 0x581030
// 0058127b  8b30                 mov esi, dword ptr [eax]
// 0058127d  8b7804               mov edi, dword ptr [eax + 4]
// 00581280  85f6                 test esi, esi
// 00581282  8b1d44e97700         mov ebx, dword ptr [0x77e944]
// 00581288  7502                 jne 0x58128c
// 0058128a  ffd3                 call ebx
// 0058128c  3b7e04               cmp edi, dword ptr [esi + 4]
// 0058128f  7502                 jne 0x581293
// 00581291  ffd3                 call ebx
// 00581293  8d4710               lea eax, [edi + 0x10]
// 00581296  5f                   pop edi
// 00581297  5e                   pop esi
// 00581298  5b                   pop ebx
// 00581299  83c410               add esp, 0x10
// 0058129c  c20400               ret 4
// standard library map_int<ptr> (function ??A?$map@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@@std@@QAEAAPAUT@@ABH@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

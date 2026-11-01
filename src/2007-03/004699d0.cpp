// from server: 100% by auto
// roc 2007-03 004699d0  unit: seg_00460000  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004699d0
//
// 004699d0  8b5104               mov edx, dword ptr [ecx + 4]
// 004699d3  8b4204               mov eax, dword ptr [edx + 4]
// 004699d6  83ec10               sub esp, 0x10
// 004699d9  80781500             cmp byte ptr [eax + 0x15], 0
// 004699dd  53                   push ebx
// 004699de  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004699e2  56                   push esi
// 004699e3  57                   push edi
// 004699e4  7516                 jne 0x4699fc
// 004699e6  8b33                 mov esi, dword ptr [ebx]
// 004699e8  39700c               cmp dword ptr [eax + 0xc], esi
// 004699eb  7d05                 jge 0x4699f2
// 004699ed  8b4008               mov eax, dword ptr [eax + 8]
// 004699f0  eb04                 jmp 0x4699f6
// 004699f2  8bd0                 mov edx, eax
// 004699f4  8b00                 mov eax, dword ptr [eax]
// 004699f6  80781500             cmp byte ptr [eax + 0x15], 0
// 004699fa  74ec                 je 0x4699e8
// 004699fc  3b5104               cmp edx, dword ptr [ecx + 4]
// 004699ff  8bfa                 mov edi, edx
// 00469a01  8bf1                 mov esi, ecx
// 00469a03  7407                 je 0x469a0c
// 00469a05  8b03                 mov eax, dword ptr [ebx]
// 00469a07  3b420c               cmp eax, dword ptr [edx + 0xc]
// 00469a0a  7d24                 jge 0x469a30
// 00469a0c  8b13                 mov edx, dword ptr [ebx]
// 00469a0e  8d44240c             lea eax, [esp + 0xc]
// 00469a12  50                   push eax
// 00469a13  57                   push edi
// 00469a14  89542414             mov dword ptr [esp + 0x14], edx
// 00469a18  56                   push esi
// 00469a19  8d542420             lea edx, [esp + 0x20]
// 00469a1d  52                   push edx
// 00469a1e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00469a26  e895fbffff           call 0x4695c0
// 00469a2b  8b30                 mov esi, dword ptr [eax]
// 00469a2d  8b7804               mov edi, dword ptr [eax + 4]
// 00469a30  85f6                 test esi, esi
// 00469a32  8b1d44e97700         mov ebx, dword ptr [0x77e944]
// 00469a38  7502                 jne 0x469a3c
// 00469a3a  ffd3                 call ebx
// 00469a3c  3b7e04               cmp edi, dword ptr [esi + 4]
// 00469a3f  7502                 jne 0x469a43
// 00469a41  ffd3                 call ebx
// 00469a43  8d4710               lea eax, [edi + 0x10]
// 00469a46  5f                   pop edi
// 00469a47  5e                   pop esi
// 00469a48  5b                   pop ebx
// 00469a49  83c410               add esp, 0x10
// 00469a4c  c20400               ret 4
// standard library map_int<ptr> (function ??A?$map@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@@std@@QAEAAPAUT@@ABH@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

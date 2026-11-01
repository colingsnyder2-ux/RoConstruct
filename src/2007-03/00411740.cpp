// from server: 100% by auto
// roc 2007-03 00411740  unit: seg_00410000  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00411740
//
// 00411740  83ec08               sub esp, 8
// 00411743  56                   push esi
// 00411744  8bf1                 mov esi, ecx
// 00411746  57                   push edi
// 00411747  8b7e04               mov edi, dword ptr [esi + 4]
// 0041174a  85ff                 test edi, edi
// 0041174c  7504                 jne 0x411752
// 0041174e  33c9                 xor ecx, ecx
// 00411750  eb16                 jmp 0x411768
// 00411752  8b4e08               mov ecx, dword ptr [esi + 8]
// 00411755  2bcf                 sub ecx, edi
// 00411757  b8398ee338           mov eax, 0x38e38e39
// 0041175c  f7e9                 imul ecx
// 0041175e  c1fa03               sar edx, 3
// 00411761  8bca                 mov ecx, edx
// 00411763  c1e91f               shr ecx, 0x1f
// 00411766  03ca                 add ecx, edx
// 00411768  85ff                 test edi, edi
// 0041176a  744b                 je 0x4117b7
// 0041176c  8b560c               mov edx, dword ptr [esi + 0xc]
// 0041176f  2bd7                 sub edx, edi
// 00411771  b8398ee338           mov eax, 0x38e38e39
// 00411776  f7ea                 imul edx
// 00411778  c1fa03               sar edx, 3
// 0041177b  8bc2                 mov eax, edx
// 0041177d  c1e81f               shr eax, 0x1f
// 00411780  03c2                 add eax, edx
// 00411782  3bc8                 cmp ecx, eax
// 00411784  7331                 jae 0x4117b7
// 00411786  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0041178a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0041178e  8b7e08               mov edi, dword ptr [esi + 8]
// 00411791  c644240800           mov byte ptr [esp + 8], 0
// 00411796  8b442408             mov eax, dword ptr [esp + 8]
// 0041179a  50                   push eax
// 0041179b  51                   push ecx
// 0041179c  56                   push esi
// 0041179d  52                   push edx
// 0041179e  6a01                 push 1
// 004117a0  57                   push edi
// 004117a1  e8baf3ffff           call 0x410b60
// 004117a6  83c418               add esp, 0x18
// 004117a9  83c724               add edi, 0x24
// 004117ac  897e08               mov dword ptr [esi + 8], edi
// 004117af  5f                   pop edi
// 004117b0  5e                   pop esi
// 004117b1  83c408               add esp, 8
// 004117b4  c20400               ret 4
// 004117b7  53                   push ebx
// 004117b8  8b5e08               mov ebx, dword ptr [esi + 8]
// 004117bb  3bfb                 cmp edi, ebx
// 004117bd  7606                 jbe 0x4117c5
// 004117bf  ff1544e97700         call dword ptr [0x77e944]
// 004117c5  8b442418             mov eax, dword ptr [esp + 0x18]
// 004117c9  50                   push eax
// 004117ca  53                   push ebx
// 004117cb  56                   push esi
// 004117cc  8d4c2418             lea ecx, [esp + 0x18]
// 004117d0  51                   push ecx
// 004117d1  8bce                 mov ecx, esi
// 004117d3  e898fdffff           call 0x411570
// 004117d8  5b                   pop ebx
// 004117d9  5f                   pop edi
// 004117da  5e                   pop esi
// 004117db  83c408               add esp, 8
// 004117de  c20400               ret 4
// standard library vector<pod36> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;

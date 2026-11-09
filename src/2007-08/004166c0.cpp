// from server: 100% by auto
// roc 2007-08 004166c0  unit: VCLuaFunction::?$CComObject  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004166c0
//
// 004166c0  8b542404             mov edx, dword ptr [esp + 4]
// 004166c4  83ec08               sub esp, 8
// 004166c7  53                   push ebx
// 004166c8  8bd9                 mov ebx, ecx
// 004166ca  8b4308               mov eax, dword ptr [ebx + 8]
// 004166cd  b955555515           mov ecx, 0x15555555
// 004166d2  2bc8                 sub ecx, eax
// 004166d4  3bca                 cmp ecx, edx
// 004166d6  7305                 jae 0x4166dd
// 004166d8  e853ea0800           call 0x4a5130
// 004166dd  8bc8                 mov ecx, eax
// 004166df  d1e9                 shr ecx, 1
// 004166e1  83f908               cmp ecx, 8
// 004166e4  7305                 jae 0x4166eb
// 004166e6  b908000000           mov ecx, 8
// 004166eb  3bd1                 cmp edx, ecx
// 004166ed  55                   push ebp
// 004166ee  56                   push esi
// 004166ef  57                   push edi
// 004166f0  7311                 jae 0x416703
// 004166f2  be55555515           mov esi, 0x15555555
// 004166f7  2bf1                 sub esi, ecx
// 004166f9  3bc6                 cmp eax, esi
// 004166fb  7706                 ja 0x416703
// 004166fd  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00416701  8bd1                 mov edx, ecx
// 00416703  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 00416706  03c2                 add eax, edx
// 00416708  6a00                 push 0
// 0041670a  50                   push eax
// 0041670b  e850961900           call 0x5afd60
// 00416710  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00416713  89442418             mov dword ptr [esp + 0x18], eax
// 00416717  8d34ad00000000       lea esi, [ebp*4]
// 0041671e  8d3c06               lea edi, [esi + eax]
// 00416721  8b4308               mov eax, dword ptr [ebx + 8]
// 00416724  03c0                 add eax, eax
// 00416726  03c0                 add eax, eax
// 00416728  8d140e               lea edx, [esi + ecx]
// 0041672b  2bc2                 sub eax, edx
// 0041672d  03c1                 add eax, ecx
// 0041672f  83c408               add esp, 8
// 00416732  c1f802               sar eax, 2
// 00416735  8d048500000000       lea eax, [eax*4]
// 0041673c  8d0c38               lea ecx, [eax + edi]
// 0041673f  894c2414             mov dword ptr [esp + 0x14], ecx
// 00416743  7415                 je 0x41675a
// 00416745  50                   push eax
// 00416746  52                   push edx
// 00416747  50                   push eax
// 00416748  57                   push edi
// 00416749  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 0041674f  ffd7                 call edi
// 00416751  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00416755  83c410               add esp, 0x10
// 00416758  eb06                 jmp 0x416760
// 0041675a  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 00416760  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00416764  3be8                 cmp ebp, eax
// 00416766  7735                 ja 0x41679d
// 00416768  8b4304               mov eax, dword ptr [ebx + 4]
// 0041676b  c1fe02               sar esi, 2
// 0041676e  8d14b500000000       lea edx, [esi*4]
// 00416775  8d340a               lea esi, [edx + ecx]
// 00416778  7409                 je 0x416783
// 0041677a  52                   push edx
// 0041677b  50                   push eax
// 0041677c  52                   push edx
// 0041677d  51                   push ecx
// 0041677e  ffd7                 call edi
// 00416780  83c410               add esp, 0x10
// 00416783  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00416787  2bcd                 sub ecx, ebp
// 00416789  7406                 je 0x416791
// 0041678b  33c0                 xor eax, eax
// 0041678d  8bfe                 mov edi, esi
// 0041678f  f3ab                 rep stosd dword ptr es:[edi], eax
// 00416791  85ed                 test ebp, ebp
// 00416793  765a                 jbe 0x4167ef
// 00416795  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00416799  8bcd                 mov ecx, ebp
// 0041679b  eb4e                 jmp 0x4167eb
// 0041679d  8b5304               mov edx, dword ptr [ebx + 4]
// 004167a0  8d2c8500000000       lea ebp, [eax*4]
// 004167a7  8bc5                 mov eax, ebp
// 004167a9  c1f802               sar eax, 2
// 004167ac  740d                 je 0x4167bb
// 004167ae  03c0                 add eax, eax
// 004167b0  03c0                 add eax, eax
// 004167b2  50                   push eax
// 004167b3  52                   push edx
// 004167b4  50                   push eax
// 004167b5  51                   push ecx
// 004167b6  ffd7                 call edi
// 004167b8  83c410               add esp, 0x10
// 004167bb  8b4304               mov eax, dword ptr [ebx + 4]
// 004167be  8b542410             mov edx, dword ptr [esp + 0x10]
// 004167c2  8d0c28               lea ecx, [eax + ebp]
// 004167c5  2bf1                 sub esi, ecx
// 004167c7  03f0                 add esi, eax
// 004167c9  c1fe02               sar esi, 2
// 004167cc  8d04b500000000       lea eax, [esi*4]
// 004167d3  8d3410               lea esi, [eax + edx]
// 004167d6  7409                 je 0x4167e1
// 004167d8  50                   push eax
// 004167d9  51                   push ecx
// 004167da  50                   push eax
// 004167db  52                   push edx
// 004167dc  ffd7                 call edi
// 004167de  83c410               add esp, 0x10
// 004167e1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004167e5  85c9                 test ecx, ecx
// 004167e7  7606                 jbe 0x4167ef
// 004167e9  8bfe                 mov edi, esi
// 004167eb  33c0                 xor eax, eax
// 004167ed  f3ab                 rep stosd dword ptr es:[edi], eax
// 004167ef  8b4304               mov eax, dword ptr [ebx + 4]
// 004167f2  85c0                 test eax, eax
// 004167f4  5f                   pop edi
// 004167f5  5e                   pop esi
// 004167f6  5d                   pop ebp
// 004167f7  7409                 je 0x416802
// 004167f9  50                   push eax
// 004167fa  e863942100           call 0x62fc62
// 004167ff  83c404               add esp, 4
// 00416802  8b542404             mov edx, dword ptr [esp + 4]
// 00416806  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041680a  014308               add dword ptr [ebx + 8], eax
// 0041680d  895304               mov dword ptr [ebx + 4], edx
// 00416810  5b                   pop ebx
// 00416811  83c408               add esp, 8
// 00416814  c20400               ret 4
// standard library deque<pod12> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod12>
struct E { int v[3]; };
#include <deque>
template class std::deque<E>;

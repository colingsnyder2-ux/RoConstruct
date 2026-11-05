// from server: 100% by auto
// roc 2008-06 00436800  unit: COutputView  size: 350 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00436800
//
// 00436800  51                   push ecx
// 00436801  8b542408             mov edx, dword ptr [esp + 8]
// 00436805  53                   push ebx
// 00436806  8bd9                 mov ebx, ecx
// 00436808  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0043680b  b9ffffff0f           mov ecx, 0xfffffff
// 00436810  2bc8                 sub ecx, eax
// 00436812  3bca                 cmp ecx, edx
// 00436814  7305                 jae 0x43681b
// 00436816  e8f5010e00           call 0x516a10
// 0043681b  8bc8                 mov ecx, eax
// 0043681d  d1e9                 shr ecx, 1
// 0043681f  83f908               cmp ecx, 8
// 00436822  7305                 jae 0x436829
// 00436824  b908000000           mov ecx, 8
// 00436829  55                   push ebp
// 0043682a  56                   push esi
// 0043682b  57                   push edi
// 0043682c  3bd1                 cmp edx, ecx
// 0043682e  7311                 jae 0x436841
// 00436830  beffffff0f           mov esi, 0xfffffff
// 00436835  2bf1                 sub esi, ecx
// 00436837  3bc6                 cmp eax, esi
// 00436839  7706                 ja 0x436841
// 0043683b  894c2418             mov dword ptr [esp + 0x18], ecx
// 0043683f  8bd1                 mov edx, ecx
// 00436841  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 00436844  03c2                 add eax, edx
// 00436846  6a00                 push 0
// 00436848  50                   push eax
// 00436849  c1ed02               shr ebp, 2
// 0043684c  e8ffa2feff           call 0x420b50
// 00436851  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00436854  89442418             mov dword ptr [esp + 0x18], eax
// 00436858  8d34ad00000000       lea esi, [ebp*4]
// 0043685f  8d3c06               lea edi, [esi + eax]
// 00436862  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00436865  03c0                 add eax, eax
// 00436867  03c0                 add eax, eax
// 00436869  8d140e               lea edx, [esi + ecx]
// 0043686c  2bc2                 sub eax, edx
// 0043686e  03c1                 add eax, ecx
// 00436870  c1f802               sar eax, 2
// 00436873  8d0c8500000000       lea ecx, [eax*4]
// 0043687a  83c408               add esp, 8
// 0043687d  03f9                 add edi, ecx
// 0043687f  85c0                 test eax, eax
// 00436881  7614                 jbe 0x436897
// 00436883  51                   push ecx
// 00436884  52                   push edx
// 00436885  8b542418             mov edx, dword ptr [esp + 0x18]
// 00436889  51                   push ecx
// 0043688a  8d0416               lea eax, [esi + edx]
// 0043688d  50                   push eax
// 0043688e  ff1550288000         call dword ptr [0x802850]
// 00436894  83c410               add esp, 0x10
// 00436897  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043689b  3be8                 cmp ebp, eax
// 0043689d  773d                 ja 0x4368dc
// 0043689f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004368a2  c1fe02               sar esi, 2
// 004368a5  8bce                 mov ecx, esi
// 004368a7  8d148d00000000       lea edx, [ecx*4]
// 004368ae  8d343a               lea esi, [edx + edi]
// 004368b1  85c9                 test ecx, ecx
// 004368b3  760d                 jbe 0x4368c2
// 004368b5  52                   push edx
// 004368b6  50                   push eax
// 004368b7  52                   push edx
// 004368b8  57                   push edi
// 004368b9  ff1550288000         call dword ptr [0x802850]
// 004368bf  83c410               add esp, 0x10
// 004368c2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004368c6  2bcd                 sub ecx, ebp
// 004368c8  7406                 je 0x4368d0
// 004368ca  33c0                 xor eax, eax
// 004368cc  8bfe                 mov edi, esi
// 004368ce  f3ab                 rep stosd dword ptr es:[edi], eax
// 004368d0  85ed                 test ebp, ebp
// 004368d2  7664                 jbe 0x436938
// 004368d4  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004368d8  8bcd                 mov ecx, ebp
// 004368da  eb58                 jmp 0x436934
// 004368dc  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004368df  8d2c8500000000       lea ebp, [eax*4]
// 004368e6  8bc5                 mov eax, ebp
// 004368e8  c1f802               sar eax, 2
// 004368eb  85c0                 test eax, eax
// 004368ed  7611                 jbe 0x436900
// 004368ef  03c0                 add eax, eax
// 004368f1  03c0                 add eax, eax
// 004368f3  50                   push eax
// 004368f4  51                   push ecx
// 004368f5  50                   push eax
// 004368f6  57                   push edi
// 004368f7  ff1550288000         call dword ptr [0x802850]
// 004368fd  83c410               add esp, 0x10
// 00436900  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00436903  8b542410             mov edx, dword ptr [esp + 0x10]
// 00436907  8d0c28               lea ecx, [eax + ebp]
// 0043690a  2bf1                 sub esi, ecx
// 0043690c  03f0                 add esi, eax
// 0043690e  c1fe02               sar esi, 2
// 00436911  8d04b500000000       lea eax, [esi*4]
// 00436918  8d3c10               lea edi, [eax + edx]
// 0043691b  85f6                 test esi, esi
// 0043691d  760d                 jbe 0x43692c
// 0043691f  50                   push eax
// 00436920  51                   push ecx
// 00436921  50                   push eax
// 00436922  52                   push edx
// 00436923  ff1550288000         call dword ptr [0x802850]
// 00436929  83c410               add esp, 0x10
// 0043692c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00436930  85c9                 test ecx, ecx
// 00436932  7604                 jbe 0x436938
// 00436934  33c0                 xor eax, eax
// 00436936  f3ab                 rep stosd dword ptr es:[edi], eax
// 00436938  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0043693b  5f                   pop edi
// 0043693c  5e                   pop esi
// 0043693d  5d                   pop ebp
// 0043693e  85c0                 test eax, eax
// 00436940  7409                 je 0x43694b
// 00436942  50                   push eax
// 00436943  e8329d2600           call 0x6a067a
// 00436948  83c404               add esp, 4
// 0043694b  8b442404             mov eax, dword ptr [esp + 4]
// 0043694f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00436953  014b14               add dword ptr [ebx + 0x14], ecx
// 00436956  894310               mov dword ptr [ebx + 0x10], eax
// 00436959  5b                   pop ebx
// 0043695a  59                   pop ecx
// 0043695b  c20400               ret 4
// standard library deque<ptr> (function ?_Growmap@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;

// from server: 100% by auto
// roc 2007-08 004457f0  unit: VCRenderSettings::?$FactoryProduct  size: 437 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004457f0
//
// 004457f0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004457f4  53                   push ebx
// 004457f5  56                   push esi
// 004457f6  8bf1                 mov esi, ecx
// 004457f8  8b08                 mov ecx, dword ptr [eax]
// 004457fa  894c2418             mov dword ptr [esp + 0x18], ecx
// 004457fe  8b4e04               mov ecx, dword ptr [esi + 4]
// 00445801  85c9                 test ecx, ecx
// 00445803  57                   push edi
// 00445804  7504                 jne 0x44580a
// 00445806  33ff                 xor edi, edi
// 00445808  eb08                 jmp 0x445812
// 0044580a  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0044580d  2bf9                 sub edi, ecx
// 0044580f  c1ff02               sar edi, 2
// 00445812  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00445816  85db                 test ebx, ebx
// 00445818  0f8481010000         je 0x44599f
// 0044581e  85c9                 test ecx, ecx
// 00445820  7504                 jne 0x445826
// 00445822  33c0                 xor eax, eax
// 00445824  eb08                 jmp 0x44582e
// 00445826  8b4608               mov eax, dword ptr [esi + 8]
// 00445829  2bc1                 sub eax, ecx
// 0044582b  c1f802               sar eax, 2
// 0044582e  baffffff3f           mov edx, 0x3fffffff
// 00445833  2bd0                 sub edx, eax
// 00445835  3bd3                 cmp edx, ebx
// 00445837  7305                 jae 0x44583e
// 00445839  e8c21ffdff           call 0x417800
// 0044583e  85c9                 test ecx, ecx
// 00445840  7504                 jne 0x445846
// 00445842  33c0                 xor eax, eax
// 00445844  eb08                 jmp 0x44584e
// 00445846  8b4608               mov eax, dword ptr [esi + 8]
// 00445849  2bc1                 sub eax, ecx
// 0044584b  c1f802               sar eax, 2
// 0044584e  03c3                 add eax, ebx
// 00445850  3bf8                 cmp edi, eax
// 00445852  55                   push ebp
// 00445853  0f83b4000000         jae 0x44590d
// 00445859  8bc7                 mov eax, edi
// 0044585b  d1e8                 shr eax, 1
// 0044585d  baffffff3f           mov edx, 0x3fffffff
// 00445862  2bd0                 sub edx, eax
// 00445864  3bd7                 cmp edx, edi
// 00445866  7304                 jae 0x44586c
// 00445868  33ff                 xor edi, edi
// 0044586a  eb02                 jmp 0x44586e
// 0044586c  03f8                 add edi, eax
// 0044586e  85c9                 test ecx, ecx
// 00445870  7504                 jne 0x445876
// 00445872  33c0                 xor eax, eax
// 00445874  eb08                 jmp 0x44587e
// 00445876  8b4608               mov eax, dword ptr [esi + 8]
// 00445879  2bc1                 sub eax, ecx
// 0044587b  c1f802               sar eax, 2
// 0044587e  03c3                 add eax, ebx
// 00445880  3bf8                 cmp edi, eax
// 00445882  7312                 jae 0x445896
// 00445884  85c9                 test ecx, ecx
// 00445886  7504                 jne 0x44588c
// 00445888  33ff                 xor edi, edi
// 0044588a  eb08                 jmp 0x445894
// 0044588c  8b7e08               mov edi, dword ptr [esi + 8]
// 0044588f  2bf9                 sub edi, ecx
// 00445891  c1ff02               sar edi, 2
// 00445894  03fb                 add edi, ebx
// 00445896  6a00                 push 0
// 00445898  57                   push edi
// 00445899  e8c2a41600           call 0x5afd60
// 0044589e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004458a1  83c408               add esp, 8
// 004458a4  8be8                 mov ebp, eax
// 004458a6  8b442418             mov eax, dword ptr [esp + 0x18]
// 004458aa  55                   push ebp
// 004458ab  50                   push eax
// 004458ac  51                   push ecx
// 004458ad  8bce                 mov ecx, esi
// 004458af  e8ecd41600           call 0x5b2da0
// 004458b4  8d542420             lea edx, [esp + 0x20]
// 004458b8  52                   push edx
// 004458b9  53                   push ebx
// 004458ba  50                   push eax
// 004458bb  8bce                 mov ecx, esi
// 004458bd  e87e0e1300           call 0x576740
// 004458c2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004458c6  50                   push eax
// 004458c7  8b4608               mov eax, dword ptr [esi + 8]
// 004458ca  50                   push eax
// 004458cb  51                   push ecx
// 004458cc  8bce                 mov ecx, esi
// 004458ce  e8cdd41600           call 0x5b2da0
// 004458d3  8b4604               mov eax, dword ptr [esi + 4]
// 004458d6  85c0                 test eax, eax
// 004458d8  7504                 jne 0x4458de
// 004458da  33c9                 xor ecx, ecx
// 004458dc  eb08                 jmp 0x4458e6
// 004458de  8b4e08               mov ecx, dword ptr [esi + 8]
// 004458e1  2bc8                 sub ecx, eax
// 004458e3  c1f902               sar ecx, 2
// 004458e6  03d9                 add ebx, ecx
// 004458e8  85c0                 test eax, eax
// 004458ea  7409                 je 0x4458f5
// 004458ec  50                   push eax
// 004458ed  e870a31e00           call 0x62fc62
// 004458f2  83c404               add esp, 4
// 004458f5  8d54bd00             lea edx, [ebp + edi*4]
// 004458f9  8d449d00             lea eax, [ebp + ebx*4]
// 004458fd  896e04               mov dword ptr [esi + 4], ebp
// 00445900  5d                   pop ebp
// 00445901  5f                   pop edi
// 00445902  89560c               mov dword ptr [esi + 0xc], edx
// 00445905  894608               mov dword ptr [esi + 8], eax
// 00445908  5e                   pop esi
// 00445909  5b                   pop ebx
// 0044590a  c21000               ret 0x10
// 0044590d  8b6e08               mov ebp, dword ptr [esi + 8]
// 00445910  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00445914  8bcd                 mov ecx, ebp
// 00445916  2bcf                 sub ecx, edi
// 00445918  c1f902               sar ecx, 2
// 0044591b  8d049d00000000       lea eax, [ebx*4]
// 00445922  3bcb                 cmp ecx, ebx
// 00445924  8944241c             mov dword ptr [esp + 0x1c], eax
// 00445928  8bce                 mov ecx, esi
// 0044592a  7346                 jae 0x445972
// 0044592c  03c7                 add eax, edi
// 0044592e  50                   push eax
// 0044592f  55                   push ebp
// 00445930  57                   push edi
// 00445931  e86ad41600           call 0x5b2da0
// 00445936  8b4608               mov eax, dword ptr [esi + 8]
// 00445939  8bc8                 mov ecx, eax
// 0044593b  2bcf                 sub ecx, edi
// 0044593d  c1f902               sar ecx, 2
// 00445940  8d542420             lea edx, [esp + 0x20]
// 00445944  52                   push edx
// 00445945  2bd9                 sub ebx, ecx
// 00445947  53                   push ebx
// 00445948  50                   push eax
// 00445949  8bce                 mov ecx, esi
// 0044594b  e8f00d1300           call 0x576740
// 00445950  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00445954  014608               add dword ptr [esi + 8], eax
// 00445957  8b7608               mov esi, dword ptr [esi + 8]
// 0044595a  8d542420             lea edx, [esp + 0x20]
// 0044595e  52                   push edx
// 0044595f  2bf0                 sub esi, eax
// 00445961  56                   push esi
// 00445962  57                   push edi
// 00445963  e888171400           call 0x5870f0
// 00445968  83c40c               add esp, 0xc
// 0044596b  5d                   pop ebp
// 0044596c  5f                   pop edi
// 0044596d  5e                   pop esi
// 0044596e  5b                   pop ebx
// 0044596f  c21000               ret 0x10
// 00445972  55                   push ebp
// 00445973  8bdd                 mov ebx, ebp
// 00445975  2bd8                 sub ebx, eax
// 00445977  55                   push ebp
// 00445978  53                   push ebx
// 00445979  e822d41600           call 0x5b2da0
// 0044597e  55                   push ebp
// 0044597f  53                   push ebx
// 00445980  57                   push edi
// 00445981  894608               mov dword ptr [esi + 8], eax
// 00445984  e877971b00           call 0x5ff100
// 00445989  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044598d  8d44242c             lea eax, [esp + 0x2c]
// 00445991  50                   push eax
// 00445992  03cf                 add ecx, edi
// 00445994  51                   push ecx
// 00445995  57                   push edi
// 00445996  e855171400           call 0x5870f0
// 0044599b  83c418               add esp, 0x18
// 0044599e  5d                   pop ebp
// 0044599f  5f                   pop edi
// 004459a0  5e                   pop esi
// 004459a1  5b                   pop ebx
// 004459a2  c21000               ret 0x10
// standard library vector<ptr> (function ?_Insert_n@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;

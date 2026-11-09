// from server: 100% by auto
// roc 2009-06 004c74f0  unit: RBX::VInstance::?$NonFactoryProduct  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c74f0
//
// 004c74f0  8b542404             mov edx, dword ptr [esp + 4]
// 004c74f4  83ec08               sub esp, 8
// 004c74f7  53                   push ebx
// 004c74f8  8bd9                 mov ebx, ecx
// 004c74fa  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004c74fd  b9ffffff03           mov ecx, 0x3ffffff
// 004c7502  2bc8                 sub ecx, eax
// 004c7504  3bca                 cmp ecx, edx
// 004c7506  7305                 jae 0x4c750d
// 004c7508  e86383f6ff           call 0x42f870
// 004c750d  8bc8                 mov ecx, eax
// 004c750f  d1e9                 shr ecx, 1
// 004c7511  83f908               cmp ecx, 8
// 004c7514  7305                 jae 0x4c751b
// 004c7516  b908000000           mov ecx, 8
// 004c751b  55                   push ebp
// 004c751c  56                   push esi
// 004c751d  57                   push edi
// 004c751e  3bd1                 cmp edx, ecx
// 004c7520  7311                 jae 0x4c7533
// 004c7522  beffffff03           mov esi, 0x3ffffff
// 004c7527  2bf1                 sub esi, ecx
// 004c7529  3bc6                 cmp eax, esi
// 004c752b  7706                 ja 0x4c7533
// 004c752d  8bd1                 mov edx, ecx
// 004c752f  8954241c             mov dword ptr [esp + 0x1c], edx
// 004c7533  8b7318               mov esi, dword ptr [ebx + 0x18]
// 004c7536  03c2                 add eax, edx
// 004c7538  6a00                 push 0
// 004c753a  50                   push eax
// 004c753b  89742418             mov dword ptr [esp + 0x18], esi
// 004c753f  e8bc141300           call 0x5f8a00
// 004c7544  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004c7547  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c754b  03f6                 add esi, esi
// 004c754d  03f6                 add esi, esi
// 004c754f  8d3c06               lea edi, [esi + eax]
// 004c7552  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004c7555  03c0                 add eax, eax
// 004c7557  03c0                 add eax, eax
// 004c7559  8d140e               lea edx, [esi + ecx]
// 004c755c  2bc2                 sub eax, edx
// 004c755e  03c1                 add eax, ecx
// 004c7560  c1f802               sar eax, 2
// 004c7563  83c408               add esp, 8
// 004c7566  8d0c8500000000       lea ecx, [eax*4]
// 004c756d  8d2c39               lea ebp, [ecx + edi]
// 004c7570  85c0                 test eax, eax
// 004c7572  760d                 jbe 0x4c7581
// 004c7574  51                   push ecx
// 004c7575  52                   push edx
// 004c7576  51                   push ecx
// 004c7577  57                   push edi
// 004c7578  ff155ce98900         call dword ptr [0x89e95c]
// 004c757e  83c410               add esp, 0x10
// 004c7581  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c7585  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c7589  3bd0                 cmp edx, eax
// 004c758b  7743                 ja 0x4c75d0
// 004c758d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004c7590  c1fe02               sar esi, 2
// 004c7593  8d0cb500000000       lea ecx, [esi*4]
// 004c759a  8d3c29               lea edi, [ecx + ebp]
// 004c759d  85f6                 test esi, esi
// 004c759f  7611                 jbe 0x4c75b2
// 004c75a1  51                   push ecx
// 004c75a2  50                   push eax
// 004c75a3  51                   push ecx
// 004c75a4  55                   push ebp
// 004c75a5  ff155ce98900         call dword ptr [0x89e95c]
// 004c75ab  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c75af  83c410               add esp, 0x10
// 004c75b2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c75b6  2bca                 sub ecx, edx
// 004c75b8  7408                 je 0x4c75c2
// 004c75ba  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c75be  33c0                 xor eax, eax
// 004c75c0  f3ab                 rep stosd dword ptr es:[edi], eax
// 004c75c2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004c75c6  85d2                 test edx, edx
// 004c75c8  7662                 jbe 0x4c762c
// 004c75ca  8bca                 mov ecx, edx
// 004c75cc  8bfd                 mov edi, ebp
// 004c75ce  eb58                 jmp 0x4c7628
// 004c75d0  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004c75d3  8d3c8500000000       lea edi, [eax*4]
// 004c75da  8bc7                 mov eax, edi
// 004c75dc  c1f802               sar eax, 2
// 004c75df  85c0                 test eax, eax
// 004c75e1  7611                 jbe 0x4c75f4
// 004c75e3  03c0                 add eax, eax
// 004c75e5  03c0                 add eax, eax
// 004c75e7  50                   push eax
// 004c75e8  51                   push ecx
// 004c75e9  50                   push eax
// 004c75ea  55                   push ebp
// 004c75eb  ff155ce98900         call dword ptr [0x89e95c]
// 004c75f1  83c410               add esp, 0x10
// 004c75f4  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004c75f7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004c75fb  8d0c07               lea ecx, [edi + eax]
// 004c75fe  2bf1                 sub esi, ecx
// 004c7600  03f0                 add esi, eax
// 004c7602  c1fe02               sar esi, 2
// 004c7605  8d04b500000000       lea eax, [esi*4]
// 004c760c  8d3c28               lea edi, [eax + ebp]
// 004c760f  85f6                 test esi, esi
// 004c7611  760d                 jbe 0x4c7620
// 004c7613  50                   push eax
// 004c7614  51                   push ecx
// 004c7615  50                   push eax
// 004c7616  55                   push ebp
// 004c7617  ff155ce98900         call dword ptr [0x89e95c]
// 004c761d  83c410               add esp, 0x10
// 004c7620  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c7624  85c9                 test ecx, ecx
// 004c7626  7604                 jbe 0x4c762c
// 004c7628  33c0                 xor eax, eax
// 004c762a  f3ab                 rep stosd dword ptr es:[edi], eax
// 004c762c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004c762f  85c0                 test eax, eax
// 004c7631  7409                 je 0x4c763c
// 004c7633  50                   push eax
// 004c7634  e8f9132500           call 0x718a32
// 004c7639  83c404               add esp, 4
// 004c763c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004c7640  015314               add dword ptr [ebx + 0x14], edx
// 004c7643  5f                   pop edi
// 004c7644  5e                   pop esi
// 004c7645  896b10               mov dword ptr [ebx + 0x10], ebp
// 004c7648  5d                   pop ebp
// 004c7649  5b                   pop ebx
// 004c764a  83c408               add esp, 8
// 004c764d  c20400               ret 4
// standard library deque<pod64> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod64>
struct E { int v[16]; };
#include <deque>
template class std::deque<E>;

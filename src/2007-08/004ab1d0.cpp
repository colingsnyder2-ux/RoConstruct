// from server: 100% by auto
// roc 2007-08 004ab1d0  unit: RBX::Network::Peer  size: 345 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ab1d0
//
// 004ab1d0  8b542404             mov edx, dword ptr [esp + 4]
// 004ab1d4  83ec08               sub esp, 8
// 004ab1d7  53                   push ebx
// 004ab1d8  8bd9                 mov ebx, ecx
// 004ab1da  8b4308               mov eax, dword ptr [ebx + 8]
// 004ab1dd  b9ffffff0f           mov ecx, 0xfffffff
// 004ab1e2  2bc8                 sub ecx, eax
// 004ab1e4  3bca                 cmp ecx, edx
// 004ab1e6  7305                 jae 0x4ab1ed
// 004ab1e8  e8439fffff           call 0x4a5130
// 004ab1ed  8bc8                 mov ecx, eax
// 004ab1ef  d1e9                 shr ecx, 1
// 004ab1f1  83f908               cmp ecx, 8
// 004ab1f4  7305                 jae 0x4ab1fb
// 004ab1f6  b908000000           mov ecx, 8
// 004ab1fb  3bd1                 cmp edx, ecx
// 004ab1fd  55                   push ebp
// 004ab1fe  56                   push esi
// 004ab1ff  57                   push edi
// 004ab200  7311                 jae 0x4ab213
// 004ab202  beffffff0f           mov esi, 0xfffffff
// 004ab207  2bf1                 sub esi, ecx
// 004ab209  3bc6                 cmp eax, esi
// 004ab20b  7706                 ja 0x4ab213
// 004ab20d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004ab211  8bd1                 mov edx, ecx
// 004ab213  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 004ab216  03c2                 add eax, edx
// 004ab218  6a00                 push 0
// 004ab21a  50                   push eax
// 004ab21b  d1ed                 shr ebp, 1
// 004ab21d  e83e4b1000           call 0x5afd60
// 004ab222  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004ab225  89442418             mov dword ptr [esp + 0x18], eax
// 004ab229  8d34ad00000000       lea esi, [ebp*4]
// 004ab230  8d3c06               lea edi, [esi + eax]
// 004ab233  8b4308               mov eax, dword ptr [ebx + 8]
// 004ab236  03c0                 add eax, eax
// 004ab238  03c0                 add eax, eax
// 004ab23a  8d140e               lea edx, [esi + ecx]
// 004ab23d  2bc2                 sub eax, edx
// 004ab23f  03c1                 add eax, ecx
// 004ab241  83c408               add esp, 8
// 004ab244  c1f802               sar eax, 2
// 004ab247  8d048500000000       lea eax, [eax*4]
// 004ab24e  8d0c38               lea ecx, [eax + edi]
// 004ab251  894c2414             mov dword ptr [esp + 0x14], ecx
// 004ab255  7415                 je 0x4ab26c
// 004ab257  50                   push eax
// 004ab258  52                   push edx
// 004ab259  50                   push eax
// 004ab25a  57                   push edi
// 004ab25b  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 004ab261  ffd7                 call edi
// 004ab263  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004ab267  83c410               add esp, 0x10
// 004ab26a  eb06                 jmp 0x4ab272
// 004ab26c  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 004ab272  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ab276  3be8                 cmp ebp, eax
// 004ab278  7735                 ja 0x4ab2af
// 004ab27a  8b4304               mov eax, dword ptr [ebx + 4]
// 004ab27d  c1fe02               sar esi, 2
// 004ab280  8d14b500000000       lea edx, [esi*4]
// 004ab287  8d340a               lea esi, [edx + ecx]
// 004ab28a  7409                 je 0x4ab295
// 004ab28c  52                   push edx
// 004ab28d  50                   push eax
// 004ab28e  52                   push edx
// 004ab28f  51                   push ecx
// 004ab290  ffd7                 call edi
// 004ab292  83c410               add esp, 0x10
// 004ab295  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004ab299  2bcd                 sub ecx, ebp
// 004ab29b  7406                 je 0x4ab2a3
// 004ab29d  33c0                 xor eax, eax
// 004ab29f  8bfe                 mov edi, esi
// 004ab2a1  f3ab                 rep stosd dword ptr es:[edi], eax
// 004ab2a3  85ed                 test ebp, ebp
// 004ab2a5  765a                 jbe 0x4ab301
// 004ab2a7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ab2ab  8bcd                 mov ecx, ebp
// 004ab2ad  eb4e                 jmp 0x4ab2fd
// 004ab2af  8b5304               mov edx, dword ptr [ebx + 4]
// 004ab2b2  8d2c8500000000       lea ebp, [eax*4]
// 004ab2b9  8bc5                 mov eax, ebp
// 004ab2bb  c1f802               sar eax, 2
// 004ab2be  740d                 je 0x4ab2cd
// 004ab2c0  03c0                 add eax, eax
// 004ab2c2  03c0                 add eax, eax
// 004ab2c4  50                   push eax
// 004ab2c5  52                   push edx
// 004ab2c6  50                   push eax
// 004ab2c7  51                   push ecx
// 004ab2c8  ffd7                 call edi
// 004ab2ca  83c410               add esp, 0x10
// 004ab2cd  8b4304               mov eax, dword ptr [ebx + 4]
// 004ab2d0  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ab2d4  8d0c28               lea ecx, [eax + ebp]
// 004ab2d7  2bf1                 sub esi, ecx
// 004ab2d9  03f0                 add esi, eax
// 004ab2db  c1fe02               sar esi, 2
// 004ab2de  8d04b500000000       lea eax, [esi*4]
// 004ab2e5  8d3410               lea esi, [eax + edx]
// 004ab2e8  7409                 je 0x4ab2f3
// 004ab2ea  50                   push eax
// 004ab2eb  51                   push ecx
// 004ab2ec  50                   push eax
// 004ab2ed  52                   push edx
// 004ab2ee  ffd7                 call edi
// 004ab2f0  83c410               add esp, 0x10
// 004ab2f3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004ab2f7  85c9                 test ecx, ecx
// 004ab2f9  7606                 jbe 0x4ab301
// 004ab2fb  8bfe                 mov edi, esi
// 004ab2fd  33c0                 xor eax, eax
// 004ab2ff  f3ab                 rep stosd dword ptr es:[edi], eax
// 004ab301  8b4304               mov eax, dword ptr [ebx + 4]
// 004ab304  85c0                 test eax, eax
// 004ab306  5f                   pop edi
// 004ab307  5e                   pop esi
// 004ab308  5d                   pop ebp
// 004ab309  7409                 je 0x4ab314
// 004ab30b  50                   push eax
// 004ab30c  e851491800           call 0x62fc62
// 004ab311  83c404               add esp, 4
// 004ab314  8b542404             mov edx, dword ptr [esp + 4]
// 004ab318  8b442410             mov eax, dword ptr [esp + 0x10]
// 004ab31c  014308               add dword ptr [ebx + 8], eax
// 004ab31f  895304               mov dword ptr [ebx + 4], edx
// 004ab322  5b                   pop ebx
// 004ab323  83c408               add esp, 8
// 004ab326  c20400               ret 4
// standard library deque<double> (function ?_Growmap@?$deque@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;

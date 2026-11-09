// from server: 100% by auto
// roc 2007-03 0048d490  unit: seg_00480000  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0048d490
//
// 0048d490  8b542404             mov edx, dword ptr [esp + 4]
// 0048d494  83ec08               sub esp, 8
// 0048d497  53                   push ebx
// 0048d498  8bd9                 mov ebx, ecx
// 0048d49a  8b4308               mov eax, dword ptr [ebx + 8]
// 0048d49d  b955555505           mov ecx, 0x5555555
// 0048d4a2  2bc8                 sub ecx, eax
// 0048d4a4  3bca                 cmp ecx, edx
// 0048d4a6  7305                 jae 0x48d4ad
// 0048d4a8  e8e3b7f7ff           call 0x408c90
// 0048d4ad  8bc8                 mov ecx, eax
// 0048d4af  d1e9                 shr ecx, 1
// 0048d4b1  83f908               cmp ecx, 8
// 0048d4b4  7305                 jae 0x48d4bb
// 0048d4b6  b908000000           mov ecx, 8
// 0048d4bb  3bd1                 cmp edx, ecx
// 0048d4bd  55                   push ebp
// 0048d4be  56                   push esi
// 0048d4bf  57                   push edi
// 0048d4c0  7311                 jae 0x48d4d3
// 0048d4c2  be55555505           mov esi, 0x5555555
// 0048d4c7  2bf1                 sub esi, ecx
// 0048d4c9  3bc6                 cmp eax, esi
// 0048d4cb  7706                 ja 0x48d4d3
// 0048d4cd  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0048d4d1  8bd1                 mov edx, ecx
// 0048d4d3  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 0048d4d6  03c2                 add eax, edx
// 0048d4d8  6a00                 push 0
// 0048d4da  50                   push eax
// 0048d4db  e880b8f8ff           call 0x418d60
// 0048d4e0  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0048d4e3  89442418             mov dword ptr [esp + 0x18], eax
// 0048d4e7  8d34ad00000000       lea esi, [ebp*4]
// 0048d4ee  8d3c06               lea edi, [esi + eax]
// 0048d4f1  8b4308               mov eax, dword ptr [ebx + 8]
// 0048d4f4  03c0                 add eax, eax
// 0048d4f6  03c0                 add eax, eax
// 0048d4f8  8d140e               lea edx, [esi + ecx]
// 0048d4fb  2bc2                 sub eax, edx
// 0048d4fd  03c1                 add eax, ecx
// 0048d4ff  83c408               add esp, 8
// 0048d502  c1f802               sar eax, 2
// 0048d505  8d048500000000       lea eax, [eax*4]
// 0048d50c  8d0c38               lea ecx, [eax + edi]
// 0048d50f  894c2414             mov dword ptr [esp + 0x14], ecx
// 0048d513  7415                 je 0x48d52a
// 0048d515  50                   push eax
// 0048d516  52                   push edx
// 0048d517  50                   push eax
// 0048d518  57                   push edi
// 0048d519  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 0048d51f  ffd7                 call edi
// 0048d521  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0048d525  83c410               add esp, 0x10
// 0048d528  eb06                 jmp 0x48d530
// 0048d52a  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 0048d530  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048d534  3be8                 cmp ebp, eax
// 0048d536  7735                 ja 0x48d56d
// 0048d538  8b4304               mov eax, dword ptr [ebx + 4]
// 0048d53b  c1fe02               sar esi, 2
// 0048d53e  8d14b500000000       lea edx, [esi*4]
// 0048d545  8d340a               lea esi, [edx + ecx]
// 0048d548  7409                 je 0x48d553
// 0048d54a  52                   push edx
// 0048d54b  50                   push eax
// 0048d54c  52                   push edx
// 0048d54d  51                   push ecx
// 0048d54e  ffd7                 call edi
// 0048d550  83c410               add esp, 0x10
// 0048d553  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0048d557  2bcd                 sub ecx, ebp
// 0048d559  7406                 je 0x48d561
// 0048d55b  33c0                 xor eax, eax
// 0048d55d  8bfe                 mov edi, esi
// 0048d55f  f3ab                 rep stosd dword ptr es:[edi], eax
// 0048d561  85ed                 test ebp, ebp
// 0048d563  765a                 jbe 0x48d5bf
// 0048d565  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048d569  8bcd                 mov ecx, ebp
// 0048d56b  eb4e                 jmp 0x48d5bb
// 0048d56d  8b5304               mov edx, dword ptr [ebx + 4]
// 0048d570  8d2c8500000000       lea ebp, [eax*4]
// 0048d577  8bc5                 mov eax, ebp
// 0048d579  c1f802               sar eax, 2
// 0048d57c  740d                 je 0x48d58b
// 0048d57e  03c0                 add eax, eax
// 0048d580  03c0                 add eax, eax
// 0048d582  50                   push eax
// 0048d583  52                   push edx
// 0048d584  50                   push eax
// 0048d585  51                   push ecx
// 0048d586  ffd7                 call edi
// 0048d588  83c410               add esp, 0x10
// 0048d58b  8b4304               mov eax, dword ptr [ebx + 4]
// 0048d58e  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048d592  8d0c28               lea ecx, [eax + ebp]
// 0048d595  2bf1                 sub esi, ecx
// 0048d597  03f0                 add esi, eax
// 0048d599  c1fe02               sar esi, 2
// 0048d59c  8d04b500000000       lea eax, [esi*4]
// 0048d5a3  8d3410               lea esi, [eax + edx]
// 0048d5a6  7409                 je 0x48d5b1
// 0048d5a8  50                   push eax
// 0048d5a9  51                   push ecx
// 0048d5aa  50                   push eax
// 0048d5ab  52                   push edx
// 0048d5ac  ffd7                 call edi
// 0048d5ae  83c410               add esp, 0x10
// 0048d5b1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0048d5b5  85c9                 test ecx, ecx
// 0048d5b7  7606                 jbe 0x48d5bf
// 0048d5b9  8bfe                 mov edi, esi
// 0048d5bb  33c0                 xor eax, eax
// 0048d5bd  f3ab                 rep stosd dword ptr es:[edi], eax
// 0048d5bf  8b4304               mov eax, dword ptr [ebx + 4]
// 0048d5c2  85c0                 test eax, eax
// 0048d5c4  5f                   pop edi
// 0048d5c5  5e                   pop esi
// 0048d5c6  5d                   pop ebp
// 0048d5c7  7409                 je 0x48d5d2
// 0048d5c9  50                   push eax
// 0048d5ca  e8210b1900           call 0x61e0f0
// 0048d5cf  83c404               add esp, 4
// 0048d5d2  8b542404             mov edx, dword ptr [esp + 4]
// 0048d5d6  8b442410             mov eax, dword ptr [esp + 0x10]
// 0048d5da  014308               add dword ptr [ebx + 8], eax
// 0048d5dd  895304               mov dword ptr [ebx + 4], edx
// 0048d5e0  5b                   pop ebx
// 0048d5e1  83c408               add esp, 8
// 0048d5e4  c20400               ret 4
// standard library deque<pod48> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod48>
struct E { int v[12]; };
#include <deque>
template class std::deque<E>;

// from server: 100% by auto
// roc 2007-08 005f8f40  unit: RBX::VDebrisService::?$FactoryProduct  size: 345 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005f8f40
//
// 005f8f40  8b542404             mov edx, dword ptr [esp + 4]
// 005f8f44  83ec08               sub esp, 8
// 005f8f47  53                   push ebx
// 005f8f48  8bd9                 mov ebx, ecx
// 005f8f4a  8b4308               mov eax, dword ptr [ebx + 8]
// 005f8f4d  b9ffffff0f           mov ecx, 0xfffffff
// 005f8f52  2bc8                 sub ecx, eax
// 005f8f54  3bca                 cmp ecx, edx
// 005f8f56  7305                 jae 0x5f8f5d
// 005f8f58  e863fbffff           call 0x5f8ac0
// 005f8f5d  8bc8                 mov ecx, eax
// 005f8f5f  d1e9                 shr ecx, 1
// 005f8f61  83f908               cmp ecx, 8
// 005f8f64  7305                 jae 0x5f8f6b
// 005f8f66  b908000000           mov ecx, 8
// 005f8f6b  3bd1                 cmp edx, ecx
// 005f8f6d  55                   push ebp
// 005f8f6e  56                   push esi
// 005f8f6f  57                   push edi
// 005f8f70  7311                 jae 0x5f8f83
// 005f8f72  beffffff0f           mov esi, 0xfffffff
// 005f8f77  2bf1                 sub esi, ecx
// 005f8f79  3bc6                 cmp eax, esi
// 005f8f7b  7706                 ja 0x5f8f83
// 005f8f7d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 005f8f81  8bd1                 mov edx, ecx
// 005f8f83  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 005f8f86  03c2                 add eax, edx
// 005f8f88  6a00                 push 0
// 005f8f8a  50                   push eax
// 005f8f8b  d1ed                 shr ebp, 1
// 005f8f8d  e8ce6dfbff           call 0x5afd60
// 005f8f92  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005f8f95  89442418             mov dword ptr [esp + 0x18], eax
// 005f8f99  8d34ad00000000       lea esi, [ebp*4]
// 005f8fa0  8d3c06               lea edi, [esi + eax]
// 005f8fa3  8b4308               mov eax, dword ptr [ebx + 8]
// 005f8fa6  03c0                 add eax, eax
// 005f8fa8  03c0                 add eax, eax
// 005f8faa  8d140e               lea edx, [esi + ecx]
// 005f8fad  2bc2                 sub eax, edx
// 005f8faf  03c1                 add eax, ecx
// 005f8fb1  83c408               add esp, 8
// 005f8fb4  c1f802               sar eax, 2
// 005f8fb7  8d048500000000       lea eax, [eax*4]
// 005f8fbe  8d0c38               lea ecx, [eax + edi]
// 005f8fc1  894c2414             mov dword ptr [esp + 0x14], ecx
// 005f8fc5  7415                 je 0x5f8fdc
// 005f8fc7  50                   push eax
// 005f8fc8  52                   push edx
// 005f8fc9  50                   push eax
// 005f8fca  57                   push edi
// 005f8fcb  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 005f8fd1  ffd7                 call edi
// 005f8fd3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005f8fd7  83c410               add esp, 0x10
// 005f8fda  eb06                 jmp 0x5f8fe2
// 005f8fdc  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 005f8fe2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005f8fe6  3be8                 cmp ebp, eax
// 005f8fe8  7735                 ja 0x5f901f
// 005f8fea  8b4304               mov eax, dword ptr [ebx + 4]
// 005f8fed  c1fe02               sar esi, 2
// 005f8ff0  8d14b500000000       lea edx, [esi*4]
// 005f8ff7  8d340a               lea esi, [edx + ecx]
// 005f8ffa  7409                 je 0x5f9005
// 005f8ffc  52                   push edx
// 005f8ffd  50                   push eax
// 005f8ffe  52                   push edx
// 005f8fff  51                   push ecx
// 005f9000  ffd7                 call edi
// 005f9002  83c410               add esp, 0x10
// 005f9005  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005f9009  2bcd                 sub ecx, ebp
// 005f900b  7406                 je 0x5f9013
// 005f900d  33c0                 xor eax, eax
// 005f900f  8bfe                 mov edi, esi
// 005f9011  f3ab                 rep stosd dword ptr es:[edi], eax
// 005f9013  85ed                 test ebp, ebp
// 005f9015  765a                 jbe 0x5f9071
// 005f9017  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005f901b  8bcd                 mov ecx, ebp
// 005f901d  eb4e                 jmp 0x5f906d
// 005f901f  8b5304               mov edx, dword ptr [ebx + 4]
// 005f9022  8d2c8500000000       lea ebp, [eax*4]
// 005f9029  8bc5                 mov eax, ebp
// 005f902b  c1f802               sar eax, 2
// 005f902e  740d                 je 0x5f903d
// 005f9030  03c0                 add eax, eax
// 005f9032  03c0                 add eax, eax
// 005f9034  50                   push eax
// 005f9035  52                   push edx
// 005f9036  50                   push eax
// 005f9037  51                   push ecx
// 005f9038  ffd7                 call edi
// 005f903a  83c410               add esp, 0x10
// 005f903d  8b4304               mov eax, dword ptr [ebx + 4]
// 005f9040  8b542410             mov edx, dword ptr [esp + 0x10]
// 005f9044  8d0c28               lea ecx, [eax + ebp]
// 005f9047  2bf1                 sub esi, ecx
// 005f9049  03f0                 add esi, eax
// 005f904b  c1fe02               sar esi, 2
// 005f904e  8d04b500000000       lea eax, [esi*4]
// 005f9055  8d3410               lea esi, [eax + edx]
// 005f9058  7409                 je 0x5f9063
// 005f905a  50                   push eax
// 005f905b  51                   push ecx
// 005f905c  50                   push eax
// 005f905d  52                   push edx
// 005f905e  ffd7                 call edi
// 005f9060  83c410               add esp, 0x10
// 005f9063  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005f9067  85c9                 test ecx, ecx
// 005f9069  7606                 jbe 0x5f9071
// 005f906b  8bfe                 mov edi, esi
// 005f906d  33c0                 xor eax, eax
// 005f906f  f3ab                 rep stosd dword ptr es:[edi], eax
// 005f9071  8b4304               mov eax, dword ptr [ebx + 4]
// 005f9074  85c0                 test eax, eax
// 005f9076  5f                   pop edi
// 005f9077  5e                   pop esi
// 005f9078  5d                   pop ebp
// 005f9079  7409                 je 0x5f9084
// 005f907b  50                   push eax
// 005f907c  e8e16b0300           call 0x62fc62
// 005f9081  83c404               add esp, 4
// 005f9084  8b542404             mov edx, dword ptr [esp + 4]
// 005f9088  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f908c  014308               add dword ptr [ebx + 8], eax
// 005f908f  895304               mov dword ptr [ebx + 4], edx
// 005f9092  5b                   pop ebx
// 005f9093  83c408               add esp, 8
// 005f9096  c20400               ret 4
// standard library deque<double> (function ?_Growmap@?$deque@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;

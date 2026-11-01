// from server: 100% by auto
// roc 2007-03 004a0630  unit: seg_004a0000  size: 345 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004a0630
//
// 004a0630  8b542404             mov edx, dword ptr [esp + 4]
// 004a0634  83ec08               sub esp, 8
// 004a0637  53                   push ebx
// 004a0638  8bd9                 mov ebx, ecx
// 004a063a  8b4308               mov eax, dword ptr [ebx + 8]
// 004a063d  b9ffffff0f           mov ecx, 0xfffffff
// 004a0642  2bc8                 sub ecx, eax
// 004a0644  3bca                 cmp ecx, edx
// 004a0646  7305                 jae 0x4a064d
// 004a0648  e84386f6ff           call 0x408c90
// 004a064d  8bc8                 mov ecx, eax
// 004a064f  d1e9                 shr ecx, 1
// 004a0651  83f908               cmp ecx, 8
// 004a0654  7305                 jae 0x4a065b
// 004a0656  b908000000           mov ecx, 8
// 004a065b  3bd1                 cmp edx, ecx
// 004a065d  55                   push ebp
// 004a065e  56                   push esi
// 004a065f  57                   push edi
// 004a0660  7311                 jae 0x4a0673
// 004a0662  beffffff0f           mov esi, 0xfffffff
// 004a0667  2bf1                 sub esi, ecx
// 004a0669  3bc6                 cmp eax, esi
// 004a066b  7706                 ja 0x4a0673
// 004a066d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004a0671  8bd1                 mov edx, ecx
// 004a0673  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 004a0676  03c2                 add eax, edx
// 004a0678  6a00                 push 0
// 004a067a  50                   push eax
// 004a067b  d1ed                 shr ebp, 1
// 004a067d  e8de86f7ff           call 0x418d60
// 004a0682  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004a0685  89442418             mov dword ptr [esp + 0x18], eax
// 004a0689  8d34ad00000000       lea esi, [ebp*4]
// 004a0690  8d3c06               lea edi, [esi + eax]
// 004a0693  8b4308               mov eax, dword ptr [ebx + 8]
// 004a0696  03c0                 add eax, eax
// 004a0698  03c0                 add eax, eax
// 004a069a  8d140e               lea edx, [esi + ecx]
// 004a069d  2bc2                 sub eax, edx
// 004a069f  03c1                 add eax, ecx
// 004a06a1  83c408               add esp, 8
// 004a06a4  c1f802               sar eax, 2
// 004a06a7  8d048500000000       lea eax, [eax*4]
// 004a06ae  8d0c38               lea ecx, [eax + edi]
// 004a06b1  894c2414             mov dword ptr [esp + 0x14], ecx
// 004a06b5  7415                 je 0x4a06cc
// 004a06b7  50                   push eax
// 004a06b8  52                   push edx
// 004a06b9  50                   push eax
// 004a06ba  57                   push edi
// 004a06bb  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 004a06c1  ffd7                 call edi
// 004a06c3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a06c7  83c410               add esp, 0x10
// 004a06ca  eb06                 jmp 0x4a06d2
// 004a06cc  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 004a06d2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a06d6  3be8                 cmp ebp, eax
// 004a06d8  7735                 ja 0x4a070f
// 004a06da  8b4304               mov eax, dword ptr [ebx + 4]
// 004a06dd  c1fe02               sar esi, 2
// 004a06e0  8d14b500000000       lea edx, [esi*4]
// 004a06e7  8d340a               lea esi, [edx + ecx]
// 004a06ea  7409                 je 0x4a06f5
// 004a06ec  52                   push edx
// 004a06ed  50                   push eax
// 004a06ee  52                   push edx
// 004a06ef  51                   push ecx
// 004a06f0  ffd7                 call edi
// 004a06f2  83c410               add esp, 0x10
// 004a06f5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a06f9  2bcd                 sub ecx, ebp
// 004a06fb  7406                 je 0x4a0703
// 004a06fd  33c0                 xor eax, eax
// 004a06ff  8bfe                 mov edi, esi
// 004a0701  f3ab                 rep stosd dword ptr es:[edi], eax
// 004a0703  85ed                 test ebp, ebp
// 004a0705  765a                 jbe 0x4a0761
// 004a0707  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a070b  8bcd                 mov ecx, ebp
// 004a070d  eb4e                 jmp 0x4a075d
// 004a070f  8b5304               mov edx, dword ptr [ebx + 4]
// 004a0712  8d2c8500000000       lea ebp, [eax*4]
// 004a0719  8bc5                 mov eax, ebp
// 004a071b  c1f802               sar eax, 2
// 004a071e  740d                 je 0x4a072d
// 004a0720  03c0                 add eax, eax
// 004a0722  03c0                 add eax, eax
// 004a0724  50                   push eax
// 004a0725  52                   push edx
// 004a0726  50                   push eax
// 004a0727  51                   push ecx
// 004a0728  ffd7                 call edi
// 004a072a  83c410               add esp, 0x10
// 004a072d  8b4304               mov eax, dword ptr [ebx + 4]
// 004a0730  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a0734  8d0c28               lea ecx, [eax + ebp]
// 004a0737  2bf1                 sub esi, ecx
// 004a0739  03f0                 add esi, eax
// 004a073b  c1fe02               sar esi, 2
// 004a073e  8d04b500000000       lea eax, [esi*4]
// 004a0745  8d3410               lea esi, [eax + edx]
// 004a0748  7409                 je 0x4a0753
// 004a074a  50                   push eax
// 004a074b  51                   push ecx
// 004a074c  50                   push eax
// 004a074d  52                   push edx
// 004a074e  ffd7                 call edi
// 004a0750  83c410               add esp, 0x10
// 004a0753  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a0757  85c9                 test ecx, ecx
// 004a0759  7606                 jbe 0x4a0761
// 004a075b  8bfe                 mov edi, esi
// 004a075d  33c0                 xor eax, eax
// 004a075f  f3ab                 rep stosd dword ptr es:[edi], eax
// 004a0761  8b4304               mov eax, dword ptr [ebx + 4]
// 004a0764  85c0                 test eax, eax
// 004a0766  5f                   pop edi
// 004a0767  5e                   pop esi
// 004a0768  5d                   pop ebp
// 004a0769  7409                 je 0x4a0774
// 004a076b  50                   push eax
// 004a076c  e87fd91700           call 0x61e0f0
// 004a0771  83c404               add esp, 4
// 004a0774  8b542404             mov edx, dword ptr [esp + 4]
// 004a0778  8b442410             mov eax, dword ptr [esp + 0x10]
// 004a077c  014308               add dword ptr [ebx + 8], eax
// 004a077f  895304               mov dword ptr [ebx + 4], edx
// 004a0782  5b                   pop ebx
// 004a0783  83c408               add esp, 8
// 004a0786  c20400               ret 4
// standard library deque<double> (function ?_Growmap@?$deque@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;

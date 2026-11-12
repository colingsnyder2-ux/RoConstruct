// from server: 100% by auto
// roc 2008-06 004a5790  unit: RBX::VHint::?$FactoryProduct::Creator  size: 428 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a5790
//
// 004a5790  53                   push ebx
// 004a5791  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004a5795  c1fb03               sar ebx, 3
// 004a5798  4b                   dec ebx
// 004a5799  807c241000           cmp byte ptr [esp + 0x10], 0
// 004a579e  55                   push ebp
// 004a579f  0f95c0               setne al
// 004a57a2  56                   push esi
// 004a57a3  fec8                 dec al
// 004a57a5  57                   push edi
// 004a57a6  8bf1                 mov esi, ecx
// 004a57a8  88442418             mov byte ptr [esp + 0x18], al
// 004a57ac  85db                 test ebx, ebx
// 004a57ae  7f44                 jg 0x4a57f4
// 004a57b0  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 004a57b5  0f8403010000         je 0x4a58be
// 004a57bb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a57bf  03d9                 add ebx, ecx
// 004a57c1  f603f0               test byte ptr [ebx], 0xf0
// 004a57c4  0f8407010000         je 0x4a58d1
// 004a57ca  6a00                 push 0
// 004a57cc  8bce                 mov ecx, esi
// 004a57ce  e8cdfeffff           call 0x4a56a0
// 004a57d3  6a01                 push 1
// 004a57d5  6a08                 push 8
// 004a57d7  53                   push ebx
// 004a57d8  8bce                 mov ecx, esi
// 004a57da  e821feffff           call 0x4a5600
// 004a57df  5f                   pop edi
// 004a57e0  5e                   pop esi
// 004a57e1  5d                   pop ebp
// 004a57e2  5b                   pop ebx
// 004a57e3  c20c00               ret 0xc
// 004a57e6  eb08                 jmp 0x4a57f0
// 004a57e8  8da42400000000       lea esp, [esp]
// 004a57ef  90                   nop 
// 004a57f0  8a442418             mov al, byte ptr [esp + 0x18]
// 004a57f4  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004a57f8  38043b               cmp byte ptr [ebx + edi], al
// 004a57fb  0f859b000000         jne 0x4a589c
// 004a5801  8b06                 mov eax, dword ptr [esi]
// 004a5803  8d7801               lea edi, [eax + 1]
// 004a5806  85ff                 test edi, edi
// 004a5808  7e5a                 jle 0x4a5864
// 004a580a  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a580d  49                   dec ecx
// 004a580e  8d57ff               lea edx, [edi - 1]
// 004a5811  83e1f8               and ecx, 0xfffffff8
// 004a5814  83e2f8               and edx, 0xfffffff8
// 004a5817  3bca                 cmp ecx, edx
// 004a5819  7d49                 jge 0x4a5864
// 004a581b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a581e  8d7c0002             lea edi, [eax + eax + 2]
// 004a5822  8d4707               lea eax, [edi + 7]
// 004a5825  8d6e11               lea ebp, [esi + 0x11]
// 004a5828  c1f803               sar eax, 3
// 004a582b  3bcd                 cmp ecx, ebp
// 004a582d  7527                 jne 0x4a5856
// 004a582f  3d00010000           cmp eax, 0x100
// 004a5834  7e2e                 jle 0x4a5864
// 004a5836  50                   push eax
// 004a5837  ff15b0288000         call dword ptr [0x8028b0]
// 004a583d  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a5840  83c107               add ecx, 7
// 004a5843  c1f903               sar ecx, 3
// 004a5846  51                   push ecx
// 004a5847  55                   push ebp
// 004a5848  50                   push eax
// 004a5849  89460c               mov dword ptr [esi + 0xc], eax
// 004a584c  e88fbf1f00           call 0x6a17e0
// 004a5851  83c410               add esp, 0x10
// 004a5854  eb0e                 jmp 0x4a5864
// 004a5856  50                   push eax
// 004a5857  51                   push ecx
// 004a5858  ff15e0278000         call dword ptr [0x8027e0]
// 004a585e  83c408               add esp, 8
// 004a5861  89460c               mov dword ptr [esi + 0xc], eax
// 004a5864  3b7e04               cmp edi, dword ptr [esi + 4]
// 004a5867  7e03                 jle 0x4a586c
// 004a5869  897e04               mov dword ptr [esi + 4], edi
// 004a586c  8b06                 mov eax, dword ptr [esi]
// 004a586e  8b560c               mov edx, dword ptr [esi + 0xc]
// 004a5871  8bc8                 mov ecx, eax
// 004a5873  c1f803               sar eax, 3
// 004a5876  83e107               and ecx, 7
// 004a5879  7506                 jne 0x4a5881
// 004a587b  c6041080             mov byte ptr [eax + edx], 0x80
// 004a587f  eb0b                 jmp 0x4a588c
// 004a5881  03c2                 add eax, edx
// 004a5883  ba80000000           mov edx, 0x80
// 004a5888  d3fa                 sar edx, cl
// 004a588a  0810                 or byte ptr [eax], dl
// 004a588c  ff06                 inc dword ptr [esi]
// 004a588e  4b                   dec ebx
// 004a588f  85db                 test ebx, ebx
// 004a5891  0f8f59ffffff         jg 0x4a57f0
// 004a5897  e914ffffff           jmp 0x4a57b0
// 004a589c  6a00                 push 0
// 004a589e  8bce                 mov ecx, esi
// 004a58a0  e8fbfdffff           call 0x4a56a0
// 004a58a5  6a01                 push 1
// 004a58a7  8d04dd08000000       lea eax, [ebx*8 + 8]
// 004a58ae  50                   push eax
// 004a58af  57                   push edi
// 004a58b0  8bce                 mov ecx, esi
// 004a58b2  e849fdffff           call 0x4a5600
// 004a58b7  5f                   pop edi
// 004a58b8  5e                   pop esi
// 004a58b9  5d                   pop ebp
// 004a58ba  5b                   pop ebx
// 004a58bb  c20c00               ret 0xc
// 004a58be  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a58c2  8a0413               mov al, byte ptr [ebx + edx]
// 004a58c5  03da                 add ebx, edx
// 004a58c7  24f0                 and al, 0xf0
// 004a58c9  3cf0                 cmp al, 0xf0
// 004a58cb  0f85f9feffff         jne 0x4a57ca
// 004a58d1  6a01                 push 1
// 004a58d3  8bce                 mov ecx, esi
// 004a58d5  e8c6fdffff           call 0x4a56a0
// 004a58da  6a04                 push 4
// 004a58dc  8bce                 mov ecx, esi
// 004a58de  e8cdfaffff           call 0x4a53b0
// 004a58e3  8b0e                 mov ecx, dword ptr [esi]
// 004a58e5  8a13                 mov dl, byte ptr [ebx]
// 004a58e7  8bc1                 mov eax, ecx
// 004a58e9  83e007               and eax, 7
// 004a58ec  c0e204               shl dl, 4
// 004a58ef  c1f903               sar ecx, 3
// 004a58f2  85c0                 test eax, eax
// 004a58f4  7510                 jne 0x4a5906
// 004a58f6  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a58f9  5f                   pop edi
// 004a58fa  881401               mov byte ptr [ecx + eax], dl
// 004a58fd  830604               add dword ptr [esi], 4
// 004a5900  5e                   pop esi
// 004a5901  5d                   pop ebp
// 004a5902  5b                   pop ebx
// 004a5903  c20c00               ret 0xc
// 004a5906  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a5909  03f9                 add edi, ecx
// 004a590b  8ac8                 mov cl, al
// 004a590d  8ada                 mov bl, dl
// 004a590f  d2eb                 shr bl, cl
// 004a5911  b908000000           mov ecx, 8
// 004a5916  2bc8                 sub ecx, eax
// 004a5918  081f                 or byte ptr [edi], bl
// 004a591a  83f908               cmp ecx, 8
// 004a591d  7d13                 jge 0x4a5932
// 004a591f  83f904               cmp ecx, 4
// 004a5922  7d0e                 jge 0x4a5932
// 004a5924  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a5927  d2e2                 shl dl, cl
// 004a5929  8b0e                 mov ecx, dword ptr [esi]
// 004a592b  c1f903               sar ecx, 3
// 004a592e  88540101             mov byte ptr [ecx + eax + 1], dl
// 004a5932  830604               add dword ptr [esi], 4
// 004a5935  5f                   pop edi
// 004a5936  5e                   pop esi
// 004a5937  5d                   pop ebp
// 004a5938  5b                   pop ebx
// 004a5939  c20c00               ret 0xc
// library openrbx-raknet/BitStream.cpp (function ?WriteCompressed@BitStream@RakNet@@AAEXPBEH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet BitStream.cpp

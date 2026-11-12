// from server: 100% by auto
// roc 2008-06 004c4090  unit: ProfiledRakPeer  size: 551 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c4090
//
// 004c4090  55                   push ebp
// 004c4091  8bec                 mov ebp, esp
// 004c4093  83e4f8               and esp, 0xfffffff8
// 004c4096  83ec10               sub esp, 0x10
// 004c4099  53                   push ebx
// 004c409a  55                   push ebp
// 004c409b  56                   push esi
// 004c409c  8bf1                 mov esi, ecx
// 004c409e  8b06                 mov eax, dword ptr [esi]
// 004c40a0  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004c40a3  57                   push edi
// 004c40a4  ffd2                 call edx
// 004c40a6  84c0                 test al, al
// 004c40a8  750a                 jne 0x4c40b4
// 004c40aa  33c0                 xor eax, eax
// 004c40ac  5f                   pop edi
// 004c40ad  5e                   pop esi
// 004c40ae  5d                   pop ebp
// 004c40af  5b                   pop ebx
// 004c40b0  8be5                 mov esp, ebp
// 004c40b2  5d                   pop ebp
// 004c40b3  c3                   ret 
// 004c40b4  33ff                 xor edi, edi
// 004c40b6  39beac020000         cmp dword ptr [esi + 0x2ac], edi
// 004c40bc  7622                 jbe 0x4c40e0
// 004c40be  8bff                 mov edi, edi
// 004c40c0  8b86a8020000         mov eax, dword ptr [esi + 0x2a8]
// 004c40c6  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004c40c9  8b11                 mov edx, dword ptr [ecx]
// 004c40cb  8b4210               mov eax, dword ptr [edx + 0x10]
// 004c40ce  56                   push esi
// 004c40cf  ffd0                 call eax
// 004c40d1  47                   inc edi
// 004c40d2  3bbeac020000         cmp edi, dword ptr [esi + 0x2ac]
// 004c40d8  72e6                 jb 0x4c40c0
// 004c40da  8d9b00000000         lea ebx, [ebx]
// 004c40e0  8b86d8080000         mov eax, dword ptr [esi + 0x8d8]
// 004c40e6  3b86e4080000         cmp eax, dword ptr [esi + 0x8e4]
// 004c40ec  0f847f000000         je 0x4c4171
// 004c40f2  8a4804               mov cl, byte ptr [eax + 4]
// 004c40f5  84c9                 test cl, cl
// 004c40f7  7478                 je 0x4c4171
// 004c40f9  8bbed8080000         mov edi, dword ptr [esi + 0x8d8]
// 004c40ff  8b5708               mov edx, dword ptr [edi + 8]
// 004c4102  8996d8080000         mov dword ptr [esi + 0x8d8], edx
// 004c4108  85ff                 test edi, edi
// 004c410a  7465                 je 0x4c4171
// 004c410c  8d642400             lea esp, [esp]
// 004c4110  8b07                 mov eax, dword ptr [edi]
// 004c4112  ff86e8080000         inc dword ptr [esi + 0x8e8]
// 004c4118  8b8ee0080000         mov ecx, dword ptr [esi + 0x8e0]
// 004c411e  89442414             mov dword ptr [esp + 0x14], eax
// 004c4122  c6410400             mov byte ptr [ecx + 4], 0
// 004c4126  8b96e0080000         mov edx, dword ptr [esi + 0x8e0]
// 004c412c  8b4208               mov eax, dword ptr [edx + 8]
// 004c412f  8986e0080000         mov dword ptr [esi + 0x8e0], eax
// 004c4135  8b86d8080000         mov eax, dword ptr [esi + 0x8d8]
// 004c413b  3b86e4080000         cmp eax, dword ptr [esi + 0x8e4]
// 004c4141  7418                 je 0x4c415b
// 004c4143  8a4804               mov cl, byte ptr [eax + 4]
// 004c4146  84c9                 test cl, cl
// 004c4148  7411                 je 0x4c415b
// 004c414a  8bbed8080000         mov edi, dword ptr [esi + 0x8d8]
// 004c4150  8b5708               mov edx, dword ptr [edi + 8]
// 004c4153  8996d8080000         mov dword ptr [esi + 0x8d8], edx
// 004c4159  eb02                 jmp 0x4c415d
// 004c415b  33ff                 xor edi, edi
// 004c415d  8d442414             lea eax, [esp + 0x14]
// 004c4161  50                   push eax
// 004c4162  8d8ef0080000         lea ecx, [esi + 0x8f0]
// 004c4168  e873ac0000           call 0x4cede0
// 004c416d  85ff                 test edi, edi
// 004c416f  759f                 jne 0x4c4110
// 004c4171  8b96f4080000         mov edx, dword ptr [esi + 0x8f4]
// 004c4177  8b8ef8080000         mov ecx, dword ptr [esi + 0x8f8]
// 004c417d  3bd1                 cmp edx, ecx
// 004c417f  7706                 ja 0x4c4187
// 004c4181  2bca                 sub ecx, edx
// 004c4183  8bc1                 mov eax, ecx
// 004c4185  eb0a                 jmp 0x4c4191
// 004c4187  8b86fc080000         mov eax, dword ptr [esi + 0x8fc]
// 004c418d  2bc2                 sub eax, edx
// 004c418f  03c1                 add eax, ecx
// 004c4191  85c0                 test eax, eax
// 004c4193  0f8411ffffff         je 0x4c40aa
// 004c4199  ff86f4080000         inc dword ptr [esi + 0x8f4]
// 004c419f  8b86f4080000         mov eax, dword ptr [esi + 0x8f4]
// 004c41a5  8b8efc080000         mov ecx, dword ptr [esi + 0x8fc]
// 004c41ab  3bc1                 cmp eax, ecx
// 004c41ad  750a                 jne 0x4c41b9
// 004c41af  c786f408000000000000 mov dword ptr [esi + 0x8f4], 0
// 004c41b9  8b86f4080000         mov eax, dword ptr [esi + 0x8f4]
// 004c41bf  85c0                 test eax, eax
// 004c41c1  750c                 jne 0x4c41cf
// 004c41c3  8b96f0080000         mov edx, dword ptr [esi + 0x8f0]
// 004c41c9  8b7c8afc             mov edi, dword ptr [edx + ecx*4 - 4]
// 004c41cd  eb0a                 jmp 0x4c41d9
// 004c41cf  8b8ef0080000         mov ecx, dword ptr [esi + 0x8f0]
// 004c41d5  8b7c81fc             mov edi, dword ptr [ecx + eax*4 - 4]
// 004c41d9  837f0c05             cmp dword ptr [edi + 0xc], 5
// 004c41dd  7219                 jb 0x4c41f8
// 004c41df  8b4714               mov eax, dword ptr [edi + 0x14]
// 004c41e2  803818               cmp byte ptr [eax], 0x18
// 004c41e5  7511                 jne 0x4c41f8
// 004c41e7  8b5708               mov edx, dword ptr [edi + 8]
// 004c41ea  8b4f04               mov ecx, dword ptr [edi + 4]
// 004c41ed  52                   push edx
// 004c41ee  51                   push ecx
// 004c41ef  40                   inc eax
// 004c41f0  50                   push eax
// 004c41f1  8bce                 mov ecx, esi
// 004c41f3  e828e3ffff           call 0x4c2520
// 004c41f8  8b5714               mov edx, dword ptr [edi + 0x14]
// 004c41fb  803a0c               cmp byte ptr [edx], 0xc
// 004c41fe  757b                 jne 0x4c427b
// 004c4200  80be2907000000       cmp byte ptr [esi + 0x729], 0
// 004c4207  8b4704               mov eax, dword ptr [edi + 4]
// 004c420a  89442418             mov dword ptr [esp + 0x18], eax
// 004c420e  8b4f08               mov ecx, dword ptr [edi + 8]
// 004c4211  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004c4215  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 004c4218  8bda                 mov ebx, edx
// 004c421a  7450                 je 0x4c426c
// 004c421c  8d8620070000         lea eax, [esi + 0x720]
// 004c4222  50                   push eax
// 004c4223  8d4c241c             lea ecx, [esp + 0x1c]
// 004c4227  e8f455feff           call 0x4a9820
// 004c422c  84c0                 test al, al
// 004c422e  7409                 je 0x4c4239
// 004c4230  80be2807000000       cmp byte ptr [esi + 0x728], 0
// 004c4237  741d                 je 0x4c4256
// 004c4239  8d8620070000         lea eax, [esi + 0x720]
// 004c423f  50                   push eax
// 004c4240  8d4c241c             lea ecx, [esp + 0x1c]
// 004c4244  e80756feff           call 0x4a9850
// 004c4249  84c0                 test al, al
// 004c424b  741f                 je 0x4c426c
// 004c424d  80be2807000001       cmp byte ptr [esi + 0x728], 1
// 004c4254  7516                 jne 0x4c426c
// 004c4256  8b8e1c070000         mov ecx, dword ptr [esi + 0x71c]
// 004c425c  4d                   dec ebp
// 004c425d  55                   push ebp
// 004c425e  43                   inc ebx
// 004c425f  53                   push ebx
// 004c4260  e89b14feff           call 0x4a5700
// 004c4265  c6862907000000       mov byte ptr [esi + 0x729], 0
// 004c426c  8b16                 mov edx, dword ptr [esi]
// 004c426e  8b4240               mov eax, dword ptr [edx + 0x40]
// 004c4271  57                   push edi
// 004c4272  8bce                 mov ecx, esi
// 004c4274  ffd0                 call eax
// 004c4276  e965feffff           jmp 0x4c40e0
// 004c427b  33ed                 xor ebp, ebp
// 004c427d  39aeac020000         cmp dword ptr [esi + 0x2ac], ebp
// 004c4283  7628                 jbe 0x4c42ad
// 004c4285  8b8ea8020000         mov ecx, dword ptr [esi + 0x2a8]
// 004c428b  8b0ca9               mov ecx, dword ptr [ecx + ebp*4]
// 004c428e  8b11                 mov edx, dword ptr [ecx]
// 004c4290  8b4214               mov eax, dword ptr [edx + 0x14]
// 004c4293  57                   push edi
// 004c4294  56                   push esi
// 004c4295  ffd0                 call eax
// 004c4297  85c0                 test eax, eax
// 004c4299  74d1                 je 0x4c426c
// 004c429b  83f802               cmp eax, 2
// 004c429e  0f843cfeffff         je 0x4c40e0
// 004c42a4  45                   inc ebp
// 004c42a5  3baeac020000         cmp ebp, dword ptr [esi + 0x2ac]
// 004c42ab  72d8                 jb 0x4c4285
// 004c42ad  8bc7                 mov eax, edi
// 004c42af  5f                   pop edi
// 004c42b0  5e                   pop esi
// 004c42b1  5d                   pop ebp
// 004c42b2  5b                   pop ebx
// 004c42b3  8be5                 mov esp, ebp
// 004c42b5  5d                   pop ebp
// 004c42b6  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?ReceiveIgnoreRPC@RakPeer@@IAEPAUPacket@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp

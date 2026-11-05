// from server: 100% by auto
// roc 2009-12 007d1e30  unit: seg_007d0000  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1e30
//
// 007d1e30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d1e34  53                   push ebx
// 007d1e35  55                   push ebp
// 007d1e36  56                   push esi
// 007d1e37  8b7130               mov esi, dword ptr [ecx + 0x30]
// 007d1e3a  8b1e                 mov ebx, dword ptr [esi]
// 007d1e3c  8b462c               mov eax, dword ptr [esi + 0x2c]
// 007d1e3f  8d6b34               lea ebp, [ebx + 0x34]
// 007d1e42  57                   push edi
// 007d1e43  8b7d00               mov edi, dword ptr [ebp]
// 007d1e46  40                   inc eax
// 007d1e47  3bc7                 cmp eax, edi
// 007d1e49  7e24                 jle 0x7d1e6f
// 007d1e4b  8b5310               mov edx, dword ptr [ebx + 0x10]
// 007d1e4e  8b4134               mov eax, dword ptr [ecx + 0x34]
// 007d1e51  68b4ee9e00           push 0x9eeeb4
// 007d1e56  68ffff0300           push 0x3ffff
// 007d1e5b  6a04                 push 4
// 007d1e5d  55                   push ebp
// 007d1e5e  52                   push edx
// 007d1e5f  50                   push eax
// 007d1e60  e89bf9ffff           call 0x7d1800
// 007d1e65  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007d1e69  83c418               add esp, 0x18
// 007d1e6c  894310               mov dword ptr [ebx + 0x10], eax
// 007d1e6f  3b7d00               cmp edi, dword ptr [ebp]
// 007d1e72  7d10                 jge 0x7d1e84
// 007d1e74  8b5310               mov edx, dword ptr [ebx + 0x10]
// 007d1e77  c704ba00000000       mov dword ptr [edx + edi*4], 0
// 007d1e7e  47                   inc edi
// 007d1e7f  3b7d00               cmp edi, dword ptr [ebp]
// 007d1e82  7cf0                 jl 0x7d1e74
// 007d1e84  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007d1e88  8b462c               mov eax, dword ptr [esi + 0x2c]
// 007d1e8b  8b5310               mov edx, dword ptr [ebx + 0x10]
// 007d1e8e  8b7d00               mov edi, dword ptr [ebp]
// 007d1e91  893c82               mov dword ptr [edx + eax*4], edi
// 007d1e94  ff462c               inc dword ptr [esi + 0x2c]
// 007d1e97  8b4500               mov eax, dword ptr [ebp]
// 007d1e9a  f6400503             test byte ptr [eax + 5], 3
// 007d1e9e  7414                 je 0x7d1eb4
// 007d1ea0  f6430504             test byte ptr [ebx + 5], 4
// 007d1ea4  740e                 je 0x7d1eb4
// 007d1ea6  50                   push eax
// 007d1ea7  8b4134               mov eax, dword ptr [ecx + 0x34]
// 007d1eaa  53                   push ebx
// 007d1eab  50                   push eax
// 007d1eac  e84fbeffff           call 0x7cdd00
// 007d1eb1  83c40c               add esp, 0xc
// 007d1eb4  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 007d1eb7  49                   dec ecx
// 007d1eb8  51                   push ecx
// 007d1eb9  6a00                 push 0
// 007d1ebb  6a24                 push 0x24
// 007d1ebd  56                   push esi
// 007d1ebe  e86da70000           call 0x7dc630
// 007d1ec3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007d1ec7  83caff               or edx, 0xffffffff
// 007d1eca  895110               mov dword ptr [ecx + 0x10], edx
// 007d1ecd  895114               mov dword ptr [ecx + 0x14], edx
// 007d1ed0  c7010b000000         mov dword ptr [ecx], 0xb
// 007d1ed6  894108               mov dword ptr [ecx + 8], eax
// 007d1ed9  8b5500               mov edx, dword ptr [ebp]
// 007d1edc  33db                 xor ebx, ebx
// 007d1ede  83c410               add esp, 0x10
// 007d1ee1  385a48               cmp byte ptr [edx + 0x48], bl
// 007d1ee4  7638                 jbe 0x7d1f1e
// 007d1ee6  8d7d33               lea edi, [ebp + 0x33]
// 007d1ee9  8da42400000000       lea esp, [esp]
// 007d1ef0  0fb64701             movzx eax, byte ptr [edi + 1]
// 007d1ef4  33c9                 xor ecx, ecx
// 007d1ef6  803f06               cmp byte ptr [edi], 6
// 007d1ef9  6a00                 push 0
// 007d1efb  0f94c1               sete cl
// 007d1efe  50                   push eax
// 007d1eff  6a00                 push 0
// 007d1f01  49                   dec ecx
// 007d1f02  83e104               and ecx, 4
// 007d1f05  51                   push ecx
// 007d1f06  56                   push esi
// 007d1f07  e8f4a60000           call 0x7dc600
// 007d1f0c  8b5500               mov edx, dword ptr [ebp]
// 007d1f0f  0fb64248             movzx eax, byte ptr [edx + 0x48]
// 007d1f13  43                   inc ebx
// 007d1f14  83c414               add esp, 0x14
// 007d1f17  83c702               add edi, 2
// 007d1f1a  3bd8                 cmp ebx, eax
// 007d1f1c  7cd2                 jl 0x7d1ef0
// 007d1f1e  5f                   pop edi
// 007d1f1f  5e                   pop esi
// 007d1f20  5d                   pop ebp
// 007d1f21  5b                   pop ebx
// 007d1f22  c3                   ret 
// library lua-5.1/lparser.c (function _pushclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c

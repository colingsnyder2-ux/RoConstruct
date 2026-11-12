// from server: 100% by auto
// roc 2008-06 004bfde0  unit: ProfiledRakPeer  size: 245 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bfde0
//
// 004bfde0  56                   push esi
// 004bfde1  8bf1                 mov esi, ecx
// 004bfde3  6870cb9300           push 0x93cb70
// 004bfde8  8d4c240c             lea ecx, [esp + 0xc]
// 004bfdec  e82f9afeff           call 0x4a9820
// 004bfdf1  84c0                 test al, al
// 004bfdf3  7406                 je 0x4bfdfb
// 004bfdf5  33c0                 xor eax, eax
// 004bfdf7  5e                   pop esi
// 004bfdf8  c21000               ret 0x10
// 004bfdfb  807c241000           cmp byte ptr [esp + 0x10], 0
// 004bfe00  53                   push ebx
// 004bfe01  55                   push ebp
// 004bfe02  57                   push edi
// 004bfe03  7443                 je 0x4bfe48
// 004bfe05  6850b54b00           push 0x4bb550
// 004bfe0a  8d442420             lea eax, [esp + 0x20]
// 004bfe0e  50                   push eax
// 004bfe0f  8d4c241c             lea ecx, [esp + 0x1c]
// 004bfe13  8dbe30020000         lea edi, [esi + 0x230]
// 004bfe19  51                   push ecx
// 004bfe1a  8bcf                 mov ecx, edi
// 004bfe1c  e8cfdaffff           call 0x4bd8f0
// 004bfe21  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 004bfe26  0f84a0000000         je 0x4bfecc
// 004bfe2c  8d1440               lea edx, [eax + eax*2]
// 004bfe2f  8b07                 mov eax, dword ptr [edi]
// 004bfe31  8b449008             mov eax, dword ptr [eax + edx*4 + 8]
// 004bfe35  69c050080000         imul eax, eax, 0x850
// 004bfe3b  03862c020000         add eax, dword ptr [esi + 0x22c]
// 004bfe41  5f                   pop edi
// 004bfe42  5d                   pop ebp
// 004bfe43  5b                   pop ebx
// 004bfe44  5e                   pop esi
// 004bfe45  c21000               ret 0x10
// 004bfe48  33c9                 xor ecx, ecx
// 004bfe4a  83cdff               or ebp, 0xffffffff
// 004bfe4d  33ff                 xor edi, edi
// 004bfe4f  663b4e08             cmp cx, word ptr [esi + 8]
// 004bfe53  7377                 jae 0x4bfecc
// 004bfe55  33db                 xor ebx, ebx
// 004bfe57  eb07                 jmp 0x4bfe60
// 004bfe59  8da42400000000       lea esp, [esp]
// 004bfe60  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 004bfe66  8d542414             lea edx, [esp + 0x14]
// 004bfe6a  52                   push edx
// 004bfe6b  8d4c0304             lea ecx, [ebx + eax + 4]
// 004bfe6f  e8ac99feff           call 0x4a9820
// 004bfe74  84c0                 test al, al
// 004bfe76  7413                 je 0x4bfe8b
// 004bfe78  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 004bfe7e  803c0b00             cmp byte ptr [ebx + ecx], 0
// 004bfe82  7537                 jne 0x4bfebb
// 004bfe84  83fdff               cmp ebp, -1
// 004bfe87  7502                 jne 0x4bfe8b
// 004bfe89  8bef                 mov ebp, edi
// 004bfe8b  0fb75608             movzx edx, word ptr [esi + 8]
// 004bfe8f  47                   inc edi
// 004bfe90  81c350080000         add ebx, 0x850
// 004bfe96  3bfa                 cmp edi, edx
// 004bfe98  72c6                 jb 0x4bfe60
// 004bfe9a  83fdff               cmp ebp, -1
// 004bfe9d  742d                 je 0x4bfecc
// 004bfe9f  807c242000           cmp byte ptr [esp + 0x20], 0
// 004bfea4  7526                 jne 0x4bfecc
// 004bfea6  8bc5                 mov eax, ebp
// 004bfea8  69c050080000         imul eax, eax, 0x850
// 004bfeae  03862c020000         add eax, dword ptr [esi + 0x22c]
// 004bfeb4  5f                   pop edi
// 004bfeb5  5d                   pop ebp
// 004bfeb6  5b                   pop ebx
// 004bfeb7  5e                   pop esi
// 004bfeb8  c21000               ret 0x10
// 004bfebb  8bc7                 mov eax, edi
// 004bfebd  69c050080000         imul eax, eax, 0x850
// 004bfec3  5f                   pop edi
// 004bfec4  5d                   pop ebp
// 004bfec5  5b                   pop ebx
// 004bfec6  03c1                 add eax, ecx
// 004bfec8  5e                   pop esi
// 004bfec9  c21000               ret 0x10
// 004bfecc  5f                   pop edi
// 004bfecd  5d                   pop ebp
// 004bfece  5b                   pop ebx
// 004bfecf  33c0                 xor eax, eax
// 004bfed1  5e                   pop esi
// 004bfed2  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?GetRemoteSystemFromSystemAddress@RakPeer@@IBEPAURemoteSystemStruct@1@USystemAddress@@_N1@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp

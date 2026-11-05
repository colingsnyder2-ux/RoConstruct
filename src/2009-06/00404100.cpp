// from server: 100% by auto
// roc 2009-06 00404100  unit: VCApp::?$CComObject  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404100
//
// 00404100  55                   push ebp
// 00404101  8bec                 mov ebp, esp
// 00404103  83e4f8               and esp, 0xfffffff8
// 00404106  81ec1c010000         sub esp, 0x11c
// 0040410c  8b01                 mov eax, dword ptr [ecx]
// 0040410e  8b5508               mov edx, dword ptr [ebp + 8]
// 00404111  53                   push ebx
// 00404112  56                   push esi
// 00404113  8b7104               mov esi, dword ptr [ecx + 4]
// 00404116  57                   push edi
// 00404117  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0040411b  8d4c2418             lea ecx, [esp + 0x18]
// 0040411f  51                   push ecx
// 00404120  33db                 xor ebx, ebx
// 00404122  81ce1f000200         or esi, 0x2001f
// 00404128  56                   push esi
// 00404129  53                   push ebx
// 0040412a  52                   push edx
// 0040412b  50                   push eax
// 0040412c  895c2420             mov dword ptr [esp + 0x20], ebx
// 00404130  895c2424             mov dword ptr [esp + 0x24], ebx
// 00404134  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00404138  ff1510e08900         call dword ptr [0x89e010]
// 0040413e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00404142  8bf8                 mov edi, eax
// 00404144  3bfb                 cmp edi, ebx
// 00404146  7525                 jne 0x40416d
// 00404148  33c0                 xor eax, eax
// 0040414a  3bcb                 cmp ecx, ebx
// 0040414c  7407                 je 0x404155
// 0040414e  51                   push ecx
// 0040414f  ff1508e08900         call dword ptr [0x89e008]
// 00404155  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00404159  81e600030000         and esi, 0x300
// 0040415f  8bf8                 mov edi, eax
// 00404161  894c240c             mov dword ptr [esp + 0xc], ecx
// 00404165  89742410             mov dword ptr [esp + 0x10], esi
// 00404169  3bc3                 cmp eax, ebx
// 0040416b  7416                 je 0x404183
// 0040416d  3bcb                 cmp ecx, ebx
// 0040416f  7407                 je 0x404178
// 00404171  51                   push ecx
// 00404172  ff1508e08900         call dword ptr [0x89e008]
// 00404178  8bc7                 mov eax, edi
// 0040417a  5f                   pop edi
// 0040417b  5e                   pop esi
// 0040417c  5b                   pop ebx
// 0040417d  8be5                 mov esp, ebp
// 0040417f  5d                   pop ebp
// 00404180  c20400               ret 4
// 00404183  8b351ce08900         mov esi, dword ptr [0x89e01c]
// 00404189  8d442420             lea eax, [esp + 0x20]
// 0040418d  50                   push eax
// 0040418e  53                   push ebx
// 0040418f  53                   push ebx
// 00404190  53                   push ebx
// 00404191  8d542424             lea edx, [esp + 0x24]
// 00404195  52                   push edx
// 00404196  8d44243c             lea eax, [esp + 0x3c]
// 0040419a  50                   push eax
// 0040419b  53                   push ebx
// 0040419c  51                   push ecx
// 0040419d  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 004041a5  ffd6                 call esi
// 004041a7  85c0                 test eax, eax
// 004041a9  753f                 jne 0x4041ea
// 004041ab  eb03                 jmp 0x4041b0
// 004041ad  8d4900               lea ecx, [ecx]
// 004041b0  8d4c2428             lea ecx, [esp + 0x28]
// 004041b4  51                   push ecx
// 004041b5  8d4c2410             lea ecx, [esp + 0x10]
// 004041b9  e842ffffff           call 0x404100
// 004041be  8bf8                 mov edi, eax
// 004041c0  3bfb                 cmp edi, ebx
// 004041c2  7566                 jne 0x40422a
// 004041c4  8d542420             lea edx, [esp + 0x20]
// 004041c8  52                   push edx
// 004041c9  8b542410             mov edx, dword ptr [esp + 0x10]
// 004041cd  53                   push ebx
// 004041ce  53                   push ebx
// 004041cf  53                   push ebx
// 004041d0  8d442424             lea eax, [esp + 0x24]
// 004041d4  50                   push eax
// 004041d5  8d4c243c             lea ecx, [esp + 0x3c]
// 004041d9  51                   push ecx
// 004041da  53                   push ebx
// 004041db  52                   push edx
// 004041dc  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 004041e4  ffd6                 call esi
// 004041e6  85c0                 test eax, eax
// 004041e8  74c6                 je 0x4041b0
// 004041ea  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004041ee  3bc3                 cmp eax, ebx
// 004041f0  740b                 je 0x4041fd
// 004041f2  50                   push eax
// 004041f3  ff1508e08900         call dword ptr [0x89e008]
// 004041f9  895c240c             mov dword ptr [esp + 0xc], ebx
// 004041fd  8b4508               mov eax, dword ptr [ebp + 8]
// 00404200  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00404204  50                   push eax
// 00404205  895c2414             mov dword ptr [esp + 0x14], ebx
// 00404209  e802efffff           call 0x403110
// 0040420e  8bf0                 mov esi, eax
// 00404210  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00404214  3bc3                 cmp eax, ebx
// 00404216  7407                 je 0x40421f
// 00404218  50                   push eax
// 00404219  ff1508e08900         call dword ptr [0x89e008]
// 0040421f  8bc6                 mov eax, esi
// 00404221  5f                   pop edi
// 00404222  5e                   pop esi
// 00404223  5b                   pop ebx
// 00404224  8be5                 mov esp, ebp
// 00404226  5d                   pop ebp
// 00404227  c20400               ret 4
// 0040422a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040422e  3bc3                 cmp eax, ebx
// 00404230  7407                 je 0x404239
// 00404232  50                   push eax
// 00404233  ff1508e08900         call dword ptr [0x89e008]
// 00404239  8bc7                 mov eax, edi
// 0040423b  5f                   pop edi
// 0040423c  5e                   pop esi
// 0040423d  5b                   pop ebx
// 0040423e  8be5                 mov esp, ebp
// 00404240  5d                   pop ebp
// 00404241  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?RecurseDeleteKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp

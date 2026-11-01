// from server: 100% by auto
// roc 2007-03 005fc720  unit: seg_005f0000  size: 316 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc720
//
// 005fc720  53                   push ebx
// 005fc721  55                   push ebp
// 005fc722  56                   push esi
// 005fc723  8b742414             mov esi, dword ptr [esp + 0x14]
// 005fc727  57                   push edi
// 005fc728  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005fc72c  8bc7                 mov eax, edi
// 005fc72e  c1e805               shr eax, 5
// 005fc731  83c001               add eax, 1
// 005fc734  3bf8                 cmp edi, eax
// 005fc736  8bdf                 mov ebx, edi
// 005fc738  897c241c             mov dword ptr [esp + 0x1c], edi
// 005fc73c  8bcf                 mov ecx, edi
// 005fc73e  721f                 jb 0x5fc75f
// 005fc740  0fb6540eff           movzx edx, byte ptr [esi + ecx - 1]
// 005fc745  8beb                 mov ebp, ebx
// 005fc747  c1e505               shl ebp, 5
// 005fc74a  03d5                 add edx, ebp
// 005fc74c  8beb                 mov ebp, ebx
// 005fc74e  c1ed02               shr ebp, 2
// 005fc751  03d5                 add edx, ebp
// 005fc753  2bc8                 sub ecx, eax
// 005fc755  33da                 xor ebx, edx
// 005fc757  3bc8                 cmp ecx, eax
// 005fc759  73e5                 jae 0x5fc740
// 005fc75b  895c241c             mov dword ptr [esp + 0x1c], ebx
// 005fc75f  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fc763  8b4010               mov eax, dword ptr [eax + 0x10]
// 005fc766  8b4808               mov ecx, dword ptr [eax + 8]
// 005fc769  8b10                 mov edx, dword ptr [eax]
// 005fc76b  83e901               sub ecx, 1
// 005fc76e  23cb                 and ecx, ebx
// 005fc770  8b048a               mov eax, dword ptr [edx + ecx*4]
// 005fc773  85c0                 test eax, eax
// 005fc775  0f84a9000000         je 0x5fc824
// 005fc77b  eb03                 jmp 0x5fc780
// 005fc77d  8d4900               lea ecx, [ecx]
// 005fc780  39780c               cmp dword ptr [eax + 0xc], edi
// 005fc783  0f8591000000         jne 0x5fc81a
// 005fc789  83ff04               cmp edi, 4
// 005fc78c  8bcf                 mov ecx, edi
// 005fc78e  8d5010               lea edx, [eax + 0x10]
// 005fc791  7214                 jb 0x5fc7a7
// 005fc793  8b2e                 mov ebp, dword ptr [esi]
// 005fc795  3b2a                 cmp ebp, dword ptr [edx]
// 005fc797  7512                 jne 0x5fc7ab
// 005fc799  83e904               sub ecx, 4
// 005fc79c  83c204               add edx, 4
// 005fc79f  83c604               add esi, 4
// 005fc7a2  83f904               cmp ecx, 4
// 005fc7a5  73ec                 jae 0x5fc793
// 005fc7a7  85c9                 test ecx, ecx
// 005fc7a9  7465                 je 0x5fc810
// 005fc7ab  0fb62e               movzx ebp, byte ptr [esi]
// 005fc7ae  0fb61a               movzx ebx, byte ptr [edx]
// 005fc7b1  2beb                 sub ebp, ebx
// 005fc7b3  7545                 jne 0x5fc7fa
// 005fc7b5  83e901               sub ecx, 1
// 005fc7b8  83c201               add edx, 1
// 005fc7bb  83c601               add esi, 1
// 005fc7be  85c9                 test ecx, ecx
// 005fc7c0  744a                 je 0x5fc80c
// 005fc7c2  0fb62e               movzx ebp, byte ptr [esi]
// 005fc7c5  0fb61a               movzx ebx, byte ptr [edx]
// 005fc7c8  2beb                 sub ebp, ebx
// 005fc7ca  752e                 jne 0x5fc7fa
// 005fc7cc  83e901               sub ecx, 1
// 005fc7cf  83c201               add edx, 1
// 005fc7d2  83c601               add esi, 1
// 005fc7d5  85c9                 test ecx, ecx
// 005fc7d7  7433                 je 0x5fc80c
// 005fc7d9  0fb62e               movzx ebp, byte ptr [esi]
// 005fc7dc  0fb61a               movzx ebx, byte ptr [edx]
// 005fc7df  2beb                 sub ebp, ebx
// 005fc7e1  7517                 jne 0x5fc7fa
// 005fc7e3  83e901               sub ecx, 1
// 005fc7e6  83c201               add edx, 1
// 005fc7e9  83c601               add esi, 1
// 005fc7ec  85c9                 test ecx, ecx
// 005fc7ee  741c                 je 0x5fc80c
// 005fc7f0  0fb62e               movzx ebp, byte ptr [esi]
// 005fc7f3  0fb60a               movzx ecx, byte ptr [edx]
// 005fc7f6  2be9                 sub ebp, ecx
// 005fc7f8  7412                 je 0x5fc80c
// 005fc7fa  85ed                 test ebp, ebp
// 005fc7fc  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 005fc800  b901000000           mov ecx, 1
// 005fc805  7f0b                 jg 0x5fc812
// 005fc807  83c9ff               or ecx, 0xffffffff
// 005fc80a  eb06                 jmp 0x5fc812
// 005fc80c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 005fc810  33c9                 xor ecx, ecx
// 005fc812  85c9                 test ecx, ecx
// 005fc814  7421                 je 0x5fc837
// 005fc816  8b742418             mov esi, dword ptr [esp + 0x18]
// 005fc81a  8b00                 mov eax, dword ptr [eax]
// 005fc81c  85c0                 test eax, eax
// 005fc81e  0f855cffffff         jne 0x5fc780
// 005fc824  53                   push ebx
// 005fc825  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005fc829  56                   push esi
// 005fc82a  e851feffff           call 0x5fc680
// 005fc82f  83c408               add esp, 8
// 005fc832  5f                   pop edi
// 005fc833  5e                   pop esi
// 005fc834  5d                   pop ebp
// 005fc835  5b                   pop ebx
// 005fc836  c3                   ret 
// 005fc837  8b542414             mov edx, dword ptr [esp + 0x14]
// 005fc83b  8b5210               mov edx, dword ptr [edx + 0x10]
// 005fc83e  8a4805               mov cl, byte ptr [eax + 5]
// 005fc841  0fb65214             movzx edx, byte ptr [edx + 0x14]
// 005fc845  0fb6d9               movzx ebx, cl
// 005fc848  f7d2                 not edx
// 005fc84a  83e303               and ebx, 3
// 005fc84d  84d3                 test bl, dl
// 005fc84f  74e1                 je 0x5fc832
// 005fc851  5f                   pop edi
// 005fc852  5e                   pop esi
// 005fc853  80f103               xor cl, 3
// 005fc856  5d                   pop ebp
// 005fc857  884805               mov byte ptr [eax + 5], cl
// 005fc85a  5b                   pop ebx
// 005fc85b  c3                   ret 
// library lua-5.1.1/lstring.c (function _luaS_newlstr)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstring.c

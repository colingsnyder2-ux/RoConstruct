// from server: 100% by auto
// roc 2009-06 005966a0  unit: seg_00590000  size: 767 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005966a0
//
// 005966a0  83ec10               sub esp, 0x10
// 005966a3  56                   push esi
// 005966a4  8b742418             mov esi, dword ptr [esp + 0x18]
// 005966a8  8b4668               mov eax, dword ptr [esi + 0x68]
// 005966ab  57                   push edi
// 005966ac  a801                 test al, 1
// 005966ae  7552                 jne 0x596702
// 005966b0  68f02a8d00           push 0x8d2af0
// 005966b5  56                   push esi
// 005966b6  e8a57affff           call 0x58e160
// 005966bb  83c408               add esp, 8
// 005966be  33ff                 xor edi, edi
// 005966c0  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005966c6  53                   push ebx
// 005966c7  55                   push ebp
// 005966c8  52                   push edx
// 005966c9  56                   push esi
// 005966ca  e8e185ffff           call 0x58ecb0
// 005966cf  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 005966d3  8d4501               lea eax, [ebp + 1]
// 005966d6  50                   push eax
// 005966d7  56                   push esi
// 005966d8  e80386ffff           call 0x58ece0
// 005966dd  8bd8                 mov ebx, eax
// 005966df  83c410               add esp, 0x10
// 005966e2  899e88020000         mov dword ptr [esi + 0x288], ebx
// 005966e8  3bdf                 cmp ebx, edi
// 005966ea  756b                 jne 0x596757
// 005966ec  68d42a8d00           push 0x8d2ad4
// 005966f1  56                   push esi
// 005966f2  e8197bffff           call 0x58e210
// 005966f7  83c408               add esp, 8
// 005966fa  5d                   pop ebp
// 005966fb  5b                   pop ebx
// 005966fc  5f                   pop edi
// 005966fd  5e                   pop esi
// 005966fe  83c410               add esp, 0x10
// 00596701  c3                   ret 
// 00596702  a804                 test al, 4
// 00596704  741f                 je 0x596725
// 00596706  68bc2a8d00           push 0x8d2abc
// 0059670b  56                   push esi
// 0059670c  e8ff7affff           call 0x58e210
// 00596711  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00596715  50                   push eax
// 00596716  56                   push esi
// 00596717  e8c4e4ffff           call 0x594be0
// 0059671c  83c410               add esp, 0x10
// 0059671f  5f                   pop edi
// 00596720  5e                   pop esi
// 00596721  83c410               add esp, 0x10
// 00596724  c3                   ret 
// 00596725  8b442420             mov eax, dword ptr [esp + 0x20]
// 00596729  33ff                 xor edi, edi
// 0059672b  3bc7                 cmp eax, edi
// 0059672d  7491                 je 0x5966c0
// 0059672f  f7400800040000       test dword ptr [eax + 8], 0x400
// 00596736  7488                 je 0x5966c0
// 00596738  68a42a8d00           push 0x8d2aa4
// 0059673d  56                   push esi
// 0059673e  e8cd7affff           call 0x58e210
// 00596743  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00596747  51                   push ecx
// 00596748  56                   push esi
// 00596749  e892e4ffff           call 0x594be0
// 0059674e  83c410               add esp, 0x10
// 00596751  5f                   pop edi
// 00596752  5e                   pop esi
// 00596753  83c410               add esp, 0x10
// 00596756  c3                   ret 
// 00596757  55                   push ebp
// 00596758  53                   push ebx
// 00596759  56                   push esi
// 0059675a  e8a125ffff           call 0x588d00
// 0059675f  55                   push ebp
// 00596760  53                   push ebx
// 00596761  56                   push esi
// 00596762  e859b1feff           call 0x5818c0
// 00596767  57                   push edi
// 00596768  56                   push esi
// 00596769  e872e4ffff           call 0x594be0
// 0059676e  83c420               add esp, 0x20
// 00596771  85c0                 test eax, eax
// 00596773  741e                 je 0x596793
// 00596775  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0059677b  51                   push ecx
// 0059677c  56                   push esi
// 0059677d  e82e85ffff           call 0x58ecb0
// 00596782  83c408               add esp, 8
// 00596785  5d                   pop ebp
// 00596786  5b                   pop ebx
// 00596787  89be88020000         mov dword ptr [esi + 0x288], edi
// 0059678d  5f                   pop edi
// 0059678e  5e                   pop esi
// 0059678f  83c410               add esp, 0x10
// 00596792  c3                   ret 
// 00596793  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00596799  c6042a00             mov byte ptr [edx + ebp], 0
// 0059679d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 005967a3  8bc1                 mov eax, ecx
// 005967a5  803800               cmp byte ptr [eax], 0
// 005967a8  740c                 je 0x5967b6
// 005967aa  8d9b00000000         lea ebx, [ebx]
// 005967b0  40                   inc eax
// 005967b1  803800               cmp byte ptr [eax], 0
// 005967b4  75fa                 jne 0x5967b0
// 005967b6  03cd                 add ecx, ebp
// 005967b8  8d500c               lea edx, [eax + 0xc]
// 005967bb  894c241c             mov dword ptr [esp + 0x1c], ecx
// 005967bf  3bca                 cmp ecx, edx
// 005967c1  770a                 ja 0x5967cd
// 005967c3  68902a8d00           push 0x8d2a90
// 005967c8  e985000000           jmp 0x596852
// 005967cd  0fb66801             movzx ebp, byte ptr [eax + 1]
// 005967d1  0fb64802             movzx ecx, byte ptr [eax + 2]
// 005967d5  0fb65003             movzx edx, byte ptr [eax + 3]
// 005967d9  0fb65805             movzx ebx, byte ptr [eax + 5]
// 005967dd  c1e508               shl ebp, 8
// 005967e0  03e9                 add ebp, ecx
// 005967e2  0fb64804             movzx ecx, byte ptr [eax + 4]
// 005967e6  c1e508               shl ebp, 8
// 005967e9  03ea                 add ebp, edx
// 005967eb  0fb65006             movzx edx, byte ptr [eax + 6]
// 005967ef  c1e308               shl ebx, 8
// 005967f2  03da                 add ebx, edx
// 005967f4  0fb65008             movzx edx, byte ptr [eax + 8]
// 005967f8  c1e508               shl ebp, 8
// 005967fb  03e9                 add ebp, ecx
// 005967fd  0fb64807             movzx ecx, byte ptr [eax + 7]
// 00596801  c1e308               shl ebx, 8
// 00596804  03d9                 add ebx, ecx
// 00596806  8a4809               mov cl, byte ptr [eax + 9]
// 00596809  c1e308               shl ebx, 8
// 0059680c  03da                 add ebx, edx
// 0059680e  8a500a               mov dl, byte ptr [eax + 0xa]
// 00596811  83c00b               add eax, 0xb
// 00596814  884c2413             mov byte ptr [esp + 0x13], cl
// 00596818  88542424             mov byte ptr [esp + 0x24], dl
// 0059681c  89442414             mov dword ptr [esp + 0x14], eax
// 00596820  84c9                 test cl, cl
// 00596822  7507                 jne 0x59682b
// 00596824  80fa02               cmp dl, 2
// 00596827  7524                 jne 0x59684d
// 00596829  eb66                 jmp 0x596891
// 0059682b  80f901               cmp cl, 1
// 0059682e  7507                 jne 0x596837
// 00596830  80fa03               cmp dl, 3
// 00596833  7518                 jne 0x59684d
// 00596835  eb5a                 jmp 0x596891
// 00596837  80f902               cmp cl, 2
// 0059683a  7507                 jne 0x596843
// 0059683c  80fa03               cmp dl, 3
// 0059683f  750c                 jne 0x59684d
// 00596841  eb4e                 jmp 0x596891
// 00596843  80f903               cmp cl, 3
// 00596846  752e                 jne 0x596876
// 00596848  80fa04               cmp dl, 4
// 0059684b  7444                 je 0x596891
// 0059684d  68642a8d00           push 0x8d2a64
// 00596852  56                   push esi
// 00596853  e8b879ffff           call 0x58e210
// 00596858  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0059685e  50                   push eax
// 0059685f  56                   push esi
// 00596860  e84b84ffff           call 0x58ecb0
// 00596865  83c410               add esp, 0x10
// 00596868  5d                   pop ebp
// 00596869  5b                   pop ebx
// 0059686a  89be88020000         mov dword ptr [esi + 0x288], edi
// 00596870  5f                   pop edi
// 00596871  5e                   pop esi
// 00596872  83c410               add esp, 0x10
// 00596875  c3                   ret 
// 00596876  80f904               cmp cl, 4
// 00596879  7216                 jb 0x596891
// 0059687b  6810ed8c00           push 0x8ced10
// 00596880  56                   push esi
// 00596881  e88a79ffff           call 0x58e210
// 00596886  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0059688a  8a54242c             mov dl, byte ptr [esp + 0x2c]
// 0059688e  83c408               add esp, 8
// 00596891  803800               cmp byte ptr [eax], 0
// 00596894  8bf8                 mov edi, eax
// 00596896  7406                 je 0x59689e
// 00596898  47                   inc edi
// 00596899  803f00               cmp byte ptr [edi], 0
// 0059689c  75fa                 jne 0x596898
// 0059689e  0fb6c2               movzx eax, dl
// 005968a1  8d0c8500000000       lea ecx, [eax*4]
// 005968a8  51                   push ecx
// 005968a9  56                   push esi
// 005968aa  8944242c             mov dword ptr [esp + 0x2c], eax
// 005968ae  e82d84ffff           call 0x58ece0
// 005968b3  83c408               add esp, 8
// 005968b6  89442418             mov dword ptr [esp + 0x18], eax
// 005968ba  85c0                 test eax, eax
// 005968bc  752d                 jne 0x5968eb
// 005968be  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005968c4  52                   push edx
// 005968c5  56                   push esi
// 005968c6  e8e583ffff           call 0x58ecb0
// 005968cb  68482a8d00           push 0x8d2a48
// 005968d0  56                   push esi
// 005968d1  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 005968db  e83079ffff           call 0x58e210
// 005968e0  83c410               add esp, 0x10
// 005968e3  5d                   pop ebp
// 005968e4  5b                   pop ebx
// 005968e5  5f                   pop edi
// 005968e6  5e                   pop esi
// 005968e7  83c410               add esp, 0x10
// 005968ea  c3                   ret 
// 005968eb  33d2                 xor edx, edx
// 005968ed  39542424             cmp dword ptr [esp + 0x24], edx
// 005968f1  7e5a                 jle 0x59694d
// 005968f3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005968f7  47                   inc edi
// 005968f8  893c90               mov dword ptr [eax + edx*4], edi
// 005968fb  3bf9                 cmp edi, ecx
// 005968fd  770b                 ja 0x59690a
// 005968ff  90                   nop 
// 00596900  803f00               cmp byte ptr [edi], 0
// 00596903  743d                 je 0x596942
// 00596905  47                   inc edi
// 00596906  3bf9                 cmp edi, ecx
// 00596908  76f6                 jbe 0x596900
// 0059690a  68902a8d00           push 0x8d2a90
// 0059690f  56                   push esi
// 00596910  e8fb78ffff           call 0x58e210
// 00596915  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0059691b  50                   push eax
// 0059691c  56                   push esi
// 0059691d  e88e83ffff           call 0x58ecb0
// 00596922  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00596926  51                   push ecx
// 00596927  56                   push esi
// 00596928  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00596932  e87983ffff           call 0x58ecb0
// 00596937  83c418               add esp, 0x18
// 0059693a  5d                   pop ebp
// 0059693b  5b                   pop ebx
// 0059693c  5f                   pop edi
// 0059693d  5e                   pop esi
// 0059693e  83c410               add esp, 0x10
// 00596941  c3                   ret 
// 00596942  3bf9                 cmp edi, ecx
// 00596944  77c4                 ja 0x59690a
// 00596946  42                   inc edx
// 00596947  3b542424             cmp edx, dword ptr [esp + 0x24]
// 0059694b  7ca6                 jl 0x5968f3
// 0059694d  8b542414             mov edx, dword ptr [esp + 0x14]
// 00596951  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 00596956  50                   push eax
// 00596957  8b442428             mov eax, dword ptr [esp + 0x28]
// 0059695b  52                   push edx
// 0059695c  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00596962  50                   push eax
// 00596963  8b442434             mov eax, dword ptr [esp + 0x34]
// 00596967  51                   push ecx
// 00596968  53                   push ebx
// 00596969  55                   push ebp
// 0059696a  52                   push edx
// 0059696b  50                   push eax
// 0059696c  56                   push esi
// 0059696d  e8cea1feff           call 0x580b40
// 00596972  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00596978  51                   push ecx
// 00596979  56                   push esi
// 0059697a  e83183ffff           call 0x58ecb0
// 0059697f  8b542444             mov edx, dword ptr [esp + 0x44]
// 00596983  52                   push edx
// 00596984  56                   push esi
// 00596985  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0059698f  e81c83ffff           call 0x58ecb0
// 00596994  83c434               add esp, 0x34
// 00596997  5d                   pop ebp
// 00596998  5b                   pop ebx
// 00596999  5f                   pop edi
// 0059699a  5e                   pop esi
// 0059699b  83c410               add esp, 0x10
// 0059699e  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c

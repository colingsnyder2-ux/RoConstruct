// from server: 100% by auto
// roc 2011-06 00571310  unit: seg_00570000  size: 767 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00571310
//
// 00571310  83ec10               sub esp, 0x10
// 00571313  56                   push esi
// 00571314  8b742418             mov esi, dword ptr [esp + 0x18]
// 00571318  8b4668               mov eax, dword ptr [esi + 0x68]
// 0057131b  57                   push edi
// 0057131c  a801                 test al, 1
// 0057131e  7552                 jne 0x571372
// 00571320  68786da800           push 0xa86d78
// 00571325  56                   push esi
// 00571326  e80500ffff           call 0x561330
// 0057132b  83c408               add esp, 8
// 0057132e  33ff                 xor edi, edi
// 00571330  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00571336  53                   push ebx
// 00571337  55                   push ebp
// 00571338  52                   push edx
// 00571339  56                   push esi
// 0057133a  e86103ffff           call 0x5616a0
// 0057133f  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00571343  8d4501               lea eax, [ebp + 1]
// 00571346  50                   push eax
// 00571347  56                   push esi
// 00571348  e88303ffff           call 0x5616d0
// 0057134d  8bd8                 mov ebx, eax
// 0057134f  83c410               add esp, 0x10
// 00571352  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00571358  3bdf                 cmp ebx, edi
// 0057135a  756b                 jne 0x5713c7
// 0057135c  685c6da800           push 0xa86d5c
// 00571361  56                   push esi
// 00571362  e87900ffff           call 0x5613e0
// 00571367  83c408               add esp, 8
// 0057136a  5d                   pop ebp
// 0057136b  5b                   pop ebx
// 0057136c  5f                   pop edi
// 0057136d  5e                   pop esi
// 0057136e  83c410               add esp, 0x10
// 00571371  c3                   ret 
// 00571372  a804                 test al, 4
// 00571374  741f                 je 0x571395
// 00571376  68446da800           push 0xa86d44
// 0057137b  56                   push esi
// 0057137c  e85f00ffff           call 0x5613e0
// 00571381  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00571385  50                   push eax
// 00571386  56                   push esi
// 00571387  e8b4e4ffff           call 0x56f840
// 0057138c  83c410               add esp, 0x10
// 0057138f  5f                   pop edi
// 00571390  5e                   pop esi
// 00571391  83c410               add esp, 0x10
// 00571394  c3                   ret 
// 00571395  8b442420             mov eax, dword ptr [esp + 0x20]
// 00571399  33ff                 xor edi, edi
// 0057139b  3bc7                 cmp eax, edi
// 0057139d  7491                 je 0x571330
// 0057139f  f7400800040000       test dword ptr [eax + 8], 0x400
// 005713a6  7488                 je 0x571330
// 005713a8  682c6da800           push 0xa86d2c
// 005713ad  56                   push esi
// 005713ae  e82d00ffff           call 0x5613e0
// 005713b3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005713b7  51                   push ecx
// 005713b8  56                   push esi
// 005713b9  e882e4ffff           call 0x56f840
// 005713be  83c410               add esp, 0x10
// 005713c1  5f                   pop edi
// 005713c2  5e                   pop esi
// 005713c3  83c410               add esp, 0x10
// 005713c6  c3                   ret 
// 005713c7  55                   push ebp
// 005713c8  53                   push ebx
// 005713c9  56                   push esi
// 005713ca  e8a1fbfeff           call 0x560f70
// 005713cf  55                   push ebp
// 005713d0  53                   push ebx
// 005713d1  56                   push esi
// 005713d2  e879f4fdff           call 0x550850
// 005713d7  57                   push edi
// 005713d8  56                   push esi
// 005713d9  e862e4ffff           call 0x56f840
// 005713de  83c420               add esp, 0x20
// 005713e1  85c0                 test eax, eax
// 005713e3  741e                 je 0x571403
// 005713e5  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 005713eb  51                   push ecx
// 005713ec  56                   push esi
// 005713ed  e8ae02ffff           call 0x5616a0
// 005713f2  83c408               add esp, 8
// 005713f5  5d                   pop ebp
// 005713f6  5b                   pop ebx
// 005713f7  89be88020000         mov dword ptr [esi + 0x288], edi
// 005713fd  5f                   pop edi
// 005713fe  5e                   pop esi
// 005713ff  83c410               add esp, 0x10
// 00571402  c3                   ret 
// 00571403  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00571409  c6042a00             mov byte ptr [edx + ebp], 0
// 0057140d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00571413  8bc1                 mov eax, ecx
// 00571415  803800               cmp byte ptr [eax], 0
// 00571418  740c                 je 0x571426
// 0057141a  8d9b00000000         lea ebx, [ebx]
// 00571420  40                   inc eax
// 00571421  803800               cmp byte ptr [eax], 0
// 00571424  75fa                 jne 0x571420
// 00571426  03cd                 add ecx, ebp
// 00571428  8d500c               lea edx, [eax + 0xc]
// 0057142b  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0057142f  3bca                 cmp ecx, edx
// 00571431  770a                 ja 0x57143d
// 00571433  68186da800           push 0xa86d18
// 00571438  e985000000           jmp 0x5714c2
// 0057143d  0fb66801             movzx ebp, byte ptr [eax + 1]
// 00571441  0fb64802             movzx ecx, byte ptr [eax + 2]
// 00571445  0fb65003             movzx edx, byte ptr [eax + 3]
// 00571449  0fb65805             movzx ebx, byte ptr [eax + 5]
// 0057144d  c1e508               shl ebp, 8
// 00571450  03e9                 add ebp, ecx
// 00571452  0fb64804             movzx ecx, byte ptr [eax + 4]
// 00571456  c1e508               shl ebp, 8
// 00571459  03ea                 add ebp, edx
// 0057145b  0fb65006             movzx edx, byte ptr [eax + 6]
// 0057145f  c1e308               shl ebx, 8
// 00571462  03da                 add ebx, edx
// 00571464  0fb65008             movzx edx, byte ptr [eax + 8]
// 00571468  c1e508               shl ebp, 8
// 0057146b  03e9                 add ebp, ecx
// 0057146d  0fb64807             movzx ecx, byte ptr [eax + 7]
// 00571471  c1e308               shl ebx, 8
// 00571474  03d9                 add ebx, ecx
// 00571476  8a4809               mov cl, byte ptr [eax + 9]
// 00571479  c1e308               shl ebx, 8
// 0057147c  03da                 add ebx, edx
// 0057147e  8a500a               mov dl, byte ptr [eax + 0xa]
// 00571481  83c00b               add eax, 0xb
// 00571484  884c2413             mov byte ptr [esp + 0x13], cl
// 00571488  88542424             mov byte ptr [esp + 0x24], dl
// 0057148c  89442414             mov dword ptr [esp + 0x14], eax
// 00571490  84c9                 test cl, cl
// 00571492  7507                 jne 0x57149b
// 00571494  80fa02               cmp dl, 2
// 00571497  7524                 jne 0x5714bd
// 00571499  eb66                 jmp 0x571501
// 0057149b  80f901               cmp cl, 1
// 0057149e  7507                 jne 0x5714a7
// 005714a0  80fa03               cmp dl, 3
// 005714a3  7518                 jne 0x5714bd
// 005714a5  eb5a                 jmp 0x571501
// 005714a7  80f902               cmp cl, 2
// 005714aa  7507                 jne 0x5714b3
// 005714ac  80fa03               cmp dl, 3
// 005714af  750c                 jne 0x5714bd
// 005714b1  eb4e                 jmp 0x571501
// 005714b3  80f903               cmp cl, 3
// 005714b6  752e                 jne 0x5714e6
// 005714b8  80fa04               cmp dl, 4
// 005714bb  7444                 je 0x571501
// 005714bd  68ec6ca800           push 0xa86cec
// 005714c2  56                   push esi
// 005714c3  e818fffeff           call 0x5613e0
// 005714c8  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 005714ce  50                   push eax
// 005714cf  56                   push esi
// 005714d0  e8cb01ffff           call 0x5616a0
// 005714d5  83c410               add esp, 0x10
// 005714d8  5d                   pop ebp
// 005714d9  5b                   pop ebx
// 005714da  89be88020000         mov dword ptr [esi + 0x288], edi
// 005714e0  5f                   pop edi
// 005714e1  5e                   pop esi
// 005714e2  83c410               add esp, 0x10
// 005714e5  c3                   ret 
// 005714e6  80f904               cmp cl, 4
// 005714e9  7216                 jb 0x571501
// 005714eb  68a05ca800           push 0xa85ca0
// 005714f0  56                   push esi
// 005714f1  e8eafefeff           call 0x5613e0
// 005714f6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005714fa  8a54242c             mov dl, byte ptr [esp + 0x2c]
// 005714fe  83c408               add esp, 8
// 00571501  803800               cmp byte ptr [eax], 0
// 00571504  8bf8                 mov edi, eax
// 00571506  7406                 je 0x57150e
// 00571508  47                   inc edi
// 00571509  803f00               cmp byte ptr [edi], 0
// 0057150c  75fa                 jne 0x571508
// 0057150e  0fb6c2               movzx eax, dl
// 00571511  8d0c8500000000       lea ecx, [eax*4]
// 00571518  51                   push ecx
// 00571519  56                   push esi
// 0057151a  8944242c             mov dword ptr [esp + 0x2c], eax
// 0057151e  e8ad01ffff           call 0x5616d0
// 00571523  83c408               add esp, 8
// 00571526  89442418             mov dword ptr [esp + 0x18], eax
// 0057152a  85c0                 test eax, eax
// 0057152c  752d                 jne 0x57155b
// 0057152e  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00571534  52                   push edx
// 00571535  56                   push esi
// 00571536  e86501ffff           call 0x5616a0
// 0057153b  68d06ca800           push 0xa86cd0
// 00571540  56                   push esi
// 00571541  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0057154b  e890fefeff           call 0x5613e0
// 00571550  83c410               add esp, 0x10
// 00571553  5d                   pop ebp
// 00571554  5b                   pop ebx
// 00571555  5f                   pop edi
// 00571556  5e                   pop esi
// 00571557  83c410               add esp, 0x10
// 0057155a  c3                   ret 
// 0057155b  33d2                 xor edx, edx
// 0057155d  39542424             cmp dword ptr [esp + 0x24], edx
// 00571561  7e5a                 jle 0x5715bd
// 00571563  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00571567  47                   inc edi
// 00571568  893c90               mov dword ptr [eax + edx*4], edi
// 0057156b  3bf9                 cmp edi, ecx
// 0057156d  770b                 ja 0x57157a
// 0057156f  90                   nop 
// 00571570  803f00               cmp byte ptr [edi], 0
// 00571573  743d                 je 0x5715b2
// 00571575  47                   inc edi
// 00571576  3bf9                 cmp edi, ecx
// 00571578  76f6                 jbe 0x571570
// 0057157a  68186da800           push 0xa86d18
// 0057157f  56                   push esi
// 00571580  e85bfefeff           call 0x5613e0
// 00571585  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057158b  50                   push eax
// 0057158c  56                   push esi
// 0057158d  e80e01ffff           call 0x5616a0
// 00571592  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00571596  51                   push ecx
// 00571597  56                   push esi
// 00571598  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 005715a2  e8f900ffff           call 0x5616a0
// 005715a7  83c418               add esp, 0x18
// 005715aa  5d                   pop ebp
// 005715ab  5b                   pop ebx
// 005715ac  5f                   pop edi
// 005715ad  5e                   pop esi
// 005715ae  83c410               add esp, 0x10
// 005715b1  c3                   ret 
// 005715b2  3bf9                 cmp edi, ecx
// 005715b4  77c4                 ja 0x57157a
// 005715b6  42                   inc edx
// 005715b7  3b542424             cmp edx, dword ptr [esp + 0x24]
// 005715bb  7ca6                 jl 0x571563
// 005715bd  8b542414             mov edx, dword ptr [esp + 0x14]
// 005715c1  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 005715c6  50                   push eax
// 005715c7  8b442428             mov eax, dword ptr [esp + 0x28]
// 005715cb  52                   push edx
// 005715cc  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005715d2  50                   push eax
// 005715d3  8b442434             mov eax, dword ptr [esp + 0x34]
// 005715d7  51                   push ecx
// 005715d8  53                   push ebx
// 005715d9  55                   push ebp
// 005715da  52                   push edx
// 005715db  50                   push eax
// 005715dc  56                   push esi
// 005715dd  e88e87feff           call 0x559d70
// 005715e2  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 005715e8  51                   push ecx
// 005715e9  56                   push esi
// 005715ea  e8b100ffff           call 0x5616a0
// 005715ef  8b542444             mov edx, dword ptr [esp + 0x44]
// 005715f3  52                   push edx
// 005715f4  56                   push esi
// 005715f5  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 005715ff  e89c00ffff           call 0x5616a0
// 00571604  83c434               add esp, 0x34
// 00571607  5d                   pop ebp
// 00571608  5b                   pop ebx
// 00571609  5f                   pop edi
// 0057160a  5e                   pop esi
// 0057160b  83c410               add esp, 0x10
// 0057160e  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c

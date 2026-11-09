// from server: 100% by auto
// roc 2010-06 005797b0  unit: seg_00570000  size: 624 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005797b0
//
// 005797b0  81ec0c010000         sub esp, 0x10c
// 005797b6  53                   push ebx
// 005797b7  8b9c2418010000       mov ebx, dword ptr [esp + 0x118]
// 005797be  56                   push esi
// 005797bf  8bb42418010000       mov esi, dword ptr [esp + 0x118]
// 005797c6  8b4668               mov eax, dword ptr [esi + 0x68]
// 005797c9  a801                 test al, 1
// 005797cb  7548                 jne 0x579815
// 005797cd  683874a200           push 0xa27438
// 005797d2  56                   push esi
// 005797d3  e8d882ffff           call 0x571ab0
// 005797d8  83c408               add esp, 8
// 005797db  8a8626010000         mov al, byte ptr [esi + 0x126]
// 005797e1  57                   push edi
// 005797e2  84c0                 test al, al
// 005797e4  0f85d1000000         jne 0x5798bb
// 005797ea  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 005797f1  83ff02               cmp edi, 2
// 005797f4  7477                 je 0x57986d
// 005797f6  681c74a200           push 0xa2741c
// 005797fb  56                   push esi
// 005797fc  e85f83ffff           call 0x571b60
// 00579801  57                   push edi
// 00579802  56                   push esi
// 00579803  e808edffff           call 0x578510
// 00579808  83c410               add esp, 0x10
// 0057980b  5f                   pop edi
// 0057980c  5e                   pop esi
// 0057980d  5b                   pop ebx
// 0057980e  81c40c010000         add esp, 0x10c
// 00579814  c3                   ret 
// 00579815  a804                 test al, 4
// 00579817  7425                 je 0x57983e
// 00579819  680474a200           push 0xa27404
// 0057981e  56                   push esi
// 0057981f  e83c83ffff           call 0x571b60
// 00579824  8b842428010000       mov eax, dword ptr [esp + 0x128]
// 0057982b  50                   push eax
// 0057982c  56                   push esi
// 0057982d  e8deecffff           call 0x578510
// 00579832  83c410               add esp, 0x10
// 00579835  5e                   pop esi
// 00579836  5b                   pop ebx
// 00579837  81c40c010000         add esp, 0x10c
// 0057983d  c3                   ret 
// 0057983e  85db                 test ebx, ebx
// 00579840  7499                 je 0x5797db
// 00579842  f6430810             test byte ptr [ebx + 8], 0x10
// 00579846  7493                 je 0x5797db
// 00579848  68ec73a200           push 0xa273ec
// 0057984d  56                   push esi
// 0057984e  e80d83ffff           call 0x571b60
// 00579853  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 0057985a  51                   push ecx
// 0057985b  56                   push esi
// 0057985c  e8afecffff           call 0x578510
// 00579861  83c410               add esp, 0x10
// 00579864  5e                   pop esi
// 00579865  5b                   pop ebx
// 00579866  81c40c010000         add esp, 0x10c
// 0057986c  c3                   ret 
// 0057986d  6a02                 push 2
// 0057986f  8d542410             lea edx, [esp + 0x10]
// 00579873  52                   push edx
// 00579874  56                   push esi
// 00579875  e8962bffff           call 0x56c410
// 0057987a  6a02                 push 2
// 0057987c  8d44241c             lea eax, [esp + 0x1c]
// 00579880  50                   push eax
// 00579881  56                   push esi
// 00579882  e859b7feff           call 0x564fe0
// 00579887  668b442424           mov ax, word ptr [esp + 0x24]
// 0057988c  b901000000           mov ecx, 1
// 00579891  660fb6d0             movzx dx, al
// 00579895  66898e1a010000       mov word ptr [esi + 0x11a], cx
// 0057989c  b900010000           mov ecx, 0x100
// 005798a1  660fafd1             imul dx, cx
// 005798a5  660fb6c4             movzx ax, ah
// 005798a9  83c418               add esp, 0x18
// 005798ac  6603d0               add dx, ax
// 005798af  66899694010000       mov word ptr [esi + 0x194], dx
// 005798b6  e9f5000000           jmp 0x5799b0
// 005798bb  3c02                 cmp al, 2
// 005798bd  757a                 jne 0x579939
// 005798bf  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 005798c6  83ff06               cmp edi, 6
// 005798c9  0f8527ffffff         jne 0x5797f6
// 005798cf  57                   push edi
// 005798d0  8d4c2414             lea ecx, [esp + 0x14]
// 005798d4  51                   push ecx
// 005798d5  56                   push esi
// 005798d6  e8d5daffff           call 0x5773b0
// 005798db  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 005798e0  b900010000           mov ecx, 0x100
// 005798e5  660fafc1             imul ax, cx
// 005798e9  ba01000000           mov edx, 1
// 005798ee  6689961a010000       mov word ptr [esi + 0x11a], dx
// 005798f5  0fb654241d           movzx edx, byte ptr [esp + 0x1d]
// 005798fa  6603c2               add ax, dx
// 005798fd  0fb654241f           movzx edx, byte ptr [esp + 0x1f]
// 00579902  6689868e010000       mov word ptr [esi + 0x18e], ax
// 00579909  0fb644241e           movzx eax, byte ptr [esp + 0x1e]
// 0057990e  660fafc1             imul ax, cx
// 00579912  6603c2               add ax, dx
// 00579915  0fb6542421           movzx edx, byte ptr [esp + 0x21]
// 0057991a  66898690010000       mov word ptr [esi + 0x190], ax
// 00579921  0fb6442420           movzx eax, byte ptr [esp + 0x20]
// 00579926  660fafc1             imul ax, cx
// 0057992a  83c40c               add esp, 0xc
// 0057992d  6603c2               add ax, dx
// 00579930  66898692010000       mov word ptr [esi + 0x192], ax
// 00579937  eb77                 jmp 0x5799b0
// 00579939  3c03                 cmp al, 3
// 0057993b  0f85b9000000         jne 0x5799fa
// 00579941  f6466802             test byte ptr [esi + 0x68], 2
// 00579945  750e                 jne 0x579955
// 00579947  68d073a200           push 0xa273d0
// 0057994c  56                   push esi
// 0057994d  e80e82ffff           call 0x571b60
// 00579952  83c408               add esp, 8
// 00579955  0fb78618010000       movzx eax, word ptr [esi + 0x118]
// 0057995c  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00579963  3bf8                 cmp edi, eax
// 00579965  0f878bfeffff         ja 0x5797f6
// 0057996b  81ff00010000         cmp edi, 0x100
// 00579971  0f877ffeffff         ja 0x5797f6
// 00579977  85ff                 test edi, edi
// 00579979  751f                 jne 0x57999a
// 0057997b  68b873a200           push 0xa273b8
// 00579980  56                   push esi
// 00579981  e8da81ffff           call 0x571b60
// 00579986  57                   push edi
// 00579987  56                   push esi
// 00579988  e883ebffff           call 0x578510
// 0057998d  83c410               add esp, 0x10
// 00579990  5f                   pop edi
// 00579991  5e                   pop esi
// 00579992  5b                   pop ebx
// 00579993  81c40c010000         add esp, 0x10c
// 00579999  c3                   ret 
// 0057999a  57                   push edi
// 0057999b  8d4c241c             lea ecx, [esp + 0x1c]
// 0057999f  51                   push ecx
// 005799a0  56                   push esi
// 005799a1  e80adaffff           call 0x5773b0
// 005799a6  83c40c               add esp, 0xc
// 005799a9  6689be1a010000       mov word ptr [esi + 0x11a], di
// 005799b0  6a00                 push 0
// 005799b2  56                   push esi
// 005799b3  e858ebffff           call 0x578510
// 005799b8  83c408               add esp, 8
// 005799bb  85c0                 test eax, eax
// 005799bd  7413                 je 0x5799d2
// 005799bf  33d2                 xor edx, edx
// 005799c1  5f                   pop edi
// 005799c2  6689961a010000       mov word ptr [esi + 0x11a], dx
// 005799c9  5e                   pop esi
// 005799ca  5b                   pop ebx
// 005799cb  81c40c010000         add esp, 0x10c
// 005799d1  c3                   ret 
// 005799d2  0fb78e1a010000       movzx ecx, word ptr [esi + 0x11a]
// 005799d9  8d868c010000         lea eax, [esi + 0x18c]
// 005799df  50                   push eax
// 005799e0  51                   push ecx
// 005799e1  8d542420             lea edx, [esp + 0x20]
// 005799e5  52                   push edx
// 005799e6  53                   push ebx
// 005799e7  56                   push esi
// 005799e8  e843affeff           call 0x564930
// 005799ed  83c414               add esp, 0x14
// 005799f0  5f                   pop edi
// 005799f1  5e                   pop esi
// 005799f2  5b                   pop ebx
// 005799f3  81c40c010000         add esp, 0x10c
// 005799f9  c3                   ret 
// 005799fa  688c73a200           push 0xa2738c
// 005799ff  56                   push esi
// 00579a00  e85b81ffff           call 0x571b60
// 00579a05  8b84242c010000       mov eax, dword ptr [esp + 0x12c]
// 00579a0c  50                   push eax
// 00579a0d  56                   push esi
// 00579a0e  e8fdeaffff           call 0x578510
// 00579a13  83c410               add esp, 0x10
// 00579a16  5f                   pop edi
// 00579a17  5e                   pop esi
// 00579a18  5b                   pop ebx
// 00579a19  81c40c010000         add esp, 0x10c
// 00579a1f  c3                   ret 
// library libpng-1.2.18/pngrutil.c (function _png_handle_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngrutil.c

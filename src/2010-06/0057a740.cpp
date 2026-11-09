// from server: 100% by auto
// roc 2010-06 0057a740  unit: seg_00570000  size: 436 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0057a740
//
// 0057a740  53                   push ebx
// 0057a741  55                   push ebp
// 0057a742  56                   push esi
// 0057a743  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057a747  f6466801             test byte ptr [esi + 0x68], 1
// 0057a74b  57                   push edi
// 0057a74c  750e                 jne 0x57a75c
// 0057a74e  68ac79a200           push 0xa279ac
// 0057a753  56                   push esi
// 0057a754  e85773ffff           call 0x571ab0
// 0057a759  83c408               add esp, 8
// 0057a75c  8b4668               mov eax, dword ptr [esi + 0x68]
// 0057a75f  a804                 test al, 4
// 0057a761  7406                 je 0x57a769
// 0057a763  83c808               or eax, 8
// 0057a766  894668               mov dword ptr [esi + 0x68], eax
// 0057a769  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057a76f  50                   push eax
// 0057a770  56                   push esi
// 0057a771  e88a7effff           call 0x572600
// 0057a776  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0057a77a  8d4d01               lea ecx, [ebp + 1]
// 0057a77d  51                   push ecx
// 0057a77e  56                   push esi
// 0057a77f  e8ac7effff           call 0x572630
// 0057a784  8bf8                 mov edi, eax
// 0057a786  33db                 xor ebx, ebx
// 0057a788  83c410               add esp, 0x10
// 0057a78b  89be88020000         mov dword ptr [esi + 0x288], edi
// 0057a791  3bfb                 cmp edi, ebx
// 0057a793  7513                 jne 0x57a7a8
// 0057a795  688479a200           push 0xa27984
// 0057a79a  56                   push esi
// 0057a79b  e8c073ffff           call 0x571b60
// 0057a7a0  83c408               add esp, 8
// 0057a7a3  5f                   pop edi
// 0057a7a4  5e                   pop esi
// 0057a7a5  5d                   pop ebp
// 0057a7a6  5b                   pop ebx
// 0057a7a7  c3                   ret 
// 0057a7a8  55                   push ebp
// 0057a7a9  57                   push edi
// 0057a7aa  56                   push esi
// 0057a7ab  e8601cffff           call 0x56c410
// 0057a7b0  55                   push ebp
// 0057a7b1  57                   push edi
// 0057a7b2  56                   push esi
// 0057a7b3  e828a8feff           call 0x564fe0
// 0057a7b8  53                   push ebx
// 0057a7b9  56                   push esi
// 0057a7ba  e851ddffff           call 0x578510
// 0057a7bf  83c420               add esp, 0x20
// 0057a7c2  85c0                 test eax, eax
// 0057a7c4  741b                 je 0x57a7e1
// 0057a7c6  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0057a7cc  52                   push edx
// 0057a7cd  56                   push esi
// 0057a7ce  e82d7effff           call 0x572600
// 0057a7d3  83c408               add esp, 8
// 0057a7d6  5f                   pop edi
// 0057a7d7  899e88020000         mov dword ptr [esi + 0x288], ebx
// 0057a7dd  5e                   pop esi
// 0057a7de  5d                   pop ebp
// 0057a7df  5b                   pop ebx
// 0057a7e0  c3                   ret 
// 0057a7e1  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057a7e7  881c28               mov byte ptr [eax + ebp], bl
// 0057a7ea  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057a7f0  8bf8                 mov edi, eax
// 0057a7f2  381f                 cmp byte ptr [edi], bl
// 0057a7f4  7405                 je 0x57a7fb
// 0057a7f6  47                   inc edi
// 0057a7f7  381f                 cmp byte ptr [edi], bl
// 0057a7f9  75fb                 jne 0x57a7f6
// 0057a7fb  8d4c28fe             lea ecx, [eax + ebp - 2]
// 0057a7ff  3bf9                 cmp edi, ecx
// 0057a801  7226                 jb 0x57a829
// 0057a803  686c79a200           push 0xa2796c
// 0057a808  56                   push esi
// 0057a809  e85273ffff           call 0x571b60
// 0057a80e  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0057a814  52                   push edx
// 0057a815  56                   push esi
// 0057a816  e8e57dffff           call 0x572600
// 0057a81b  83c410               add esp, 0x10
// 0057a81e  5f                   pop edi
// 0057a81f  899e88020000         mov dword ptr [esi + 0x288], ebx
// 0057a825  5e                   pop esi
// 0057a826  5d                   pop ebp
// 0057a827  5b                   pop ebx
// 0057a828  c3                   ret 
// 0057a829  0fbe5f01             movsx ebx, byte ptr [edi + 1]
// 0057a82d  47                   inc edi
// 0057a82e  85db                 test ebx, ebx
// 0057a830  7410                 je 0x57a842
// 0057a832  684479a200           push 0xa27944
// 0057a837  56                   push esi
// 0057a838  e82373ffff           call 0x571b60
// 0057a83d  83c408               add esp, 8
// 0057a840  33db                 xor ebx, ebx
// 0057a842  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 0057a848  8d442414             lea eax, [esp + 0x14]
// 0057a84c  50                   push eax
// 0057a84d  47                   inc edi
// 0057a84e  57                   push edi
// 0057a84f  55                   push ebp
// 0057a850  53                   push ebx
// 0057a851  56                   push esi
// 0057a852  e809ccffff           call 0x577460
// 0057a857  6a10                 push 0x10
// 0057a859  56                   push esi
// 0057a85a  e8d17dffff           call 0x572630
// 0057a85f  8be8                 mov ebp, eax
// 0057a861  83c41c               add esp, 0x1c
// 0057a864  85ed                 test ebp, ebp
// 0057a866  7526                 jne 0x57a88e
// 0057a868  681879a200           push 0xa27918
// 0057a86d  56                   push esi
// 0057a86e  e8ed72ffff           call 0x571b60
// 0057a873  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0057a879  51                   push ecx
// 0057a87a  56                   push esi
// 0057a87b  e8807dffff           call 0x572600
// 0057a880  83c410               add esp, 0x10
// 0057a883  5f                   pop edi
// 0057a884  89ae88020000         mov dword ptr [esi + 0x288], ebp
// 0057a88a  5e                   pop esi
// 0057a88b  5d                   pop ebp
// 0057a88c  5b                   pop ebx
// 0057a88d  c3                   ret 
// 0057a88e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0057a892  895d00               mov dword ptr [ebp], ebx
// 0057a895  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0057a89b  6a01                 push 1
// 0057a89d  895504               mov dword ptr [ebp + 4], edx
// 0057a8a0  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057a8a6  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0057a8aa  55                   push ebp
// 0057a8ab  52                   push edx
// 0057a8ac  03c7                 add eax, edi
// 0057a8ae  56                   push esi
// 0057a8af  894508               mov dword ptr [ebp + 8], eax
// 0057a8b2  894d0c               mov dword ptr [ebp + 0xc], ecx
// 0057a8b5  e8769efeff           call 0x564730
// 0057a8ba  55                   push ebp
// 0057a8bb  56                   push esi
// 0057a8bc  8bf8                 mov edi, eax
// 0057a8be  e83d7dffff           call 0x572600
// 0057a8c3  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057a8c9  50                   push eax
// 0057a8ca  56                   push esi
// 0057a8cb  e8307dffff           call 0x572600
// 0057a8d0  83c420               add esp, 0x20
// 0057a8d3  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0057a8dd  85ff                 test edi, edi
// 0057a8df  740e                 je 0x57a8ef
// 0057a8e1  68ec78a200           push 0xa278ec
// 0057a8e6  56                   push esi
// 0057a8e7  e8c471ffff           call 0x571ab0
// 0057a8ec  83c408               add esp, 8
// 0057a8ef  5f                   pop edi
// 0057a8f0  5e                   pop esi
// 0057a8f1  5d                   pop ebp
// 0057a8f2  5b                   pop ebx
// 0057a8f3  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c

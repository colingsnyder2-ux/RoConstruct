// from server: 100% by auto
// roc 2011-06 00571930  unit: seg_00570000  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00571930
//
// 00571930  55                   push ebp
// 00571931  56                   push esi
// 00571932  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00571936  f6466801             test byte ptr [esi + 0x68], 1
// 0057193a  57                   push edi
// 0057193b  750e                 jne 0x57194b
// 0057193d  68506fa800           push 0xa86f50
// 00571942  56                   push esi
// 00571943  e8e8f9feff           call 0x561330
// 00571948  83c408               add esp, 8
// 0057194b  8b4668               mov eax, dword ptr [esi + 0x68]
// 0057194e  a804                 test al, 4
// 00571950  7406                 je 0x571958
// 00571952  83c808               or eax, 8
// 00571955  894668               mov dword ptr [esi + 0x68], eax
// 00571958  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057195e  50                   push eax
// 0057195f  56                   push esi
// 00571960  e83bfdfeff           call 0x5616a0
// 00571965  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00571969  8d4d01               lea ecx, [ebp + 1]
// 0057196c  51                   push ecx
// 0057196d  56                   push esi
// 0057196e  e85dfdfeff           call 0x5616d0
// 00571973  8bf8                 mov edi, eax
// 00571975  83c410               add esp, 0x10
// 00571978  89be88020000         mov dword ptr [esi + 0x288], edi
// 0057197e  85ff                 test edi, edi
// 00571980  7512                 jne 0x571994
// 00571982  682c6fa800           push 0xa86f2c
// 00571987  56                   push esi
// 00571988  e853fafeff           call 0x5613e0
// 0057198d  83c408               add esp, 8
// 00571990  5f                   pop edi
// 00571991  5e                   pop esi
// 00571992  5d                   pop ebp
// 00571993  c3                   ret 
// 00571994  55                   push ebp
// 00571995  57                   push edi
// 00571996  56                   push esi
// 00571997  e8d4f5feff           call 0x560f70
// 0057199c  55                   push ebp
// 0057199d  57                   push edi
// 0057199e  56                   push esi
// 0057199f  e8aceefdff           call 0x550850
// 005719a4  6a00                 push 0
// 005719a6  56                   push esi
// 005719a7  e894deffff           call 0x56f840
// 005719ac  83c420               add esp, 0x20
// 005719af  85c0                 test eax, eax
// 005719b1  741e                 je 0x5719d1
// 005719b3  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005719b9  52                   push edx
// 005719ba  56                   push esi
// 005719bb  e8e0fcfeff           call 0x5616a0
// 005719c0  83c408               add esp, 8
// 005719c3  5f                   pop edi
// 005719c4  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 005719ce  5e                   pop esi
// 005719cf  5d                   pop ebp
// 005719d0  c3                   ret 
// 005719d1  53                   push ebx
// 005719d2  8b9e88020000         mov ebx, dword ptr [esi + 0x288]
// 005719d8  8d042b               lea eax, [ebx + ebp]
// 005719db  c60000               mov byte ptr [eax], 0
// 005719de  803b00               cmp byte ptr [ebx], 0
// 005719e1  8beb                 mov ebp, ebx
// 005719e3  7407                 je 0x5719ec
// 005719e5  45                   inc ebp
// 005719e6  807d0000             cmp byte ptr [ebp], 0
// 005719ea  75f9                 jne 0x5719e5
// 005719ec  3be8                 cmp ebp, eax
// 005719ee  7401                 je 0x5719f1
// 005719f0  45                   inc ebp
// 005719f1  6a10                 push 0x10
// 005719f3  56                   push esi
// 005719f4  e8d7fcfeff           call 0x5616d0
// 005719f9  8bf8                 mov edi, eax
// 005719fb  83c408               add esp, 8
// 005719fe  85ff                 test edi, edi
// 00571a00  7526                 jne 0x571a28
// 00571a02  68006fa800           push 0xa86f00
// 00571a07  56                   push esi
// 00571a08  e8d3f9feff           call 0x5613e0
// 00571a0d  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00571a13  50                   push eax
// 00571a14  56                   push esi
// 00571a15  e886fcfeff           call 0x5616a0
// 00571a1a  83c410               add esp, 0x10
// 00571a1d  5b                   pop ebx
// 00571a1e  89be88020000         mov dword ptr [esi + 0x288], edi
// 00571a24  5f                   pop edi
// 00571a25  5e                   pop esi
// 00571a26  5d                   pop ebp
// 00571a27  c3                   ret 
// 00571a28  8bc5                 mov eax, ebp
// 00571a2a  c707ffffffff         mov dword ptr [edi], 0xffffffff
// 00571a30  895f04               mov dword ptr [edi + 4], ebx
// 00571a33  896f08               mov dword ptr [edi + 8], ebp
// 00571a36  8d5001               lea edx, [eax + 1]
// 00571a39  8da42400000000       lea esp, [esp]
// 00571a40  8a08                 mov cl, byte ptr [eax]
// 00571a42  40                   inc eax
// 00571a43  84c9                 test cl, cl
// 00571a45  75f9                 jne 0x571a40
// 00571a47  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00571a4b  6a01                 push 1
// 00571a4d  57                   push edi
// 00571a4e  51                   push ecx
// 00571a4f  2bc2                 sub eax, edx
// 00571a51  56                   push esi
// 00571a52  89470c               mov dword ptr [edi + 0xc], eax
// 00571a55  e81688feff           call 0x55a270
// 00571a5a  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00571a60  52                   push edx
// 00571a61  56                   push esi
// 00571a62  8bd8                 mov ebx, eax
// 00571a64  e837fcfeff           call 0x5616a0
// 00571a69  57                   push edi
// 00571a6a  56                   push esi
// 00571a6b  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00571a75  e826fcfeff           call 0x5616a0
// 00571a7a  83c420               add esp, 0x20
// 00571a7d  85db                 test ebx, ebx
// 00571a7f  740e                 je 0x571a8f
// 00571a81  68d46ea800           push 0xa86ed4
// 00571a86  56                   push esi
// 00571a87  e854f9feff           call 0x5613e0
// 00571a8c  83c408               add esp, 8
// 00571a8f  5b                   pop ebx
// 00571a90  5f                   pop edi
// 00571a91  5e                   pop esi
// 00571a92  5d                   pop ebp
// 00571a93  c3                   ret 
// library libpng-1.2.35/pngrutil.c (function _png_handle_tEXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngrutil.c

// from server: 100% by auto
// roc 2010-06 00425660  unit: MainLogManager  size: 484 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425660
//
// 00425660  55                   push ebp
// 00425661  8bec                 mov ebp, esp
// 00425663  6aff                 push -1
// 00425665  6812fb9700           push 0x97fb12
// 0042566a  64a100000000         mov eax, dword ptr fs:[0]
// 00425670  50                   push eax
// 00425671  64892500000000       mov dword ptr fs:[0], esp
// 00425678  83ec50               sub esp, 0x50
// 0042567b  53                   push ebx
// 0042567c  56                   push esi
// 0042567d  8bf1                 mov esi, ecx
// 0042567f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00425682  57                   push edi
// 00425683  8965f0               mov dword ptr [ebp - 0x10], esp
// 00425686  8975e0               mov dword ptr [ebp - 0x20], esi
// 00425689  85c0                 test eax, eax
// 0042568b  7505                 jne 0x425692
// 0042568d  8945ec               mov dword ptr [ebp - 0x14], eax
// 00425690  eb1b                 jmp 0x4256ad
// 00425692  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00425695  2bc8                 sub ecx, eax
// 00425697  b893244992           mov eax, 0x92492493
// 0042569c  f7e9                 imul ecx
// 0042569e  03d1                 add edx, ecx
// 004256a0  c1fa04               sar edx, 4
// 004256a3  8bc2                 mov eax, edx
// 004256a5  c1e81f               shr eax, 0x1f
// 004256a8  03c2                 add eax, edx
// 004256aa  8945ec               mov dword ptr [ebp - 0x14], eax
// 004256ad  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004256b0  85ff                 test edi, edi
// 004256b2  0f842d030000         je 0x4259e5
// 004256b8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004256bb  8bcb                 mov ecx, ebx
// 004256bd  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 004256c0  b893244992           mov eax, 0x92492493
// 004256c5  f7e9                 imul ecx
// 004256c7  03d1                 add edx, ecx
// 004256c9  c1fa04               sar edx, 4
// 004256cc  8bc2                 mov eax, edx
// 004256ce  c1e81f               shr eax, 0x1f
// 004256d1  03c2                 add eax, edx
// 004256d3  b949922409           mov ecx, 0x9249249
// 004256d8  2bc8                 sub ecx, eax
// 004256da  3bcf                 cmp ecx, edi
// 004256dc  7305                 jae 0x4256e3
// 004256de  e80de7ffff           call 0x423df0
// 004256e3  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004256e6  03c7                 add eax, edi
// 004256e8  3bc8                 cmp ecx, eax
// 004256ea  0f83b6010000         jae 0x4258a6
// 004256f0  8bd1                 mov edx, ecx
// 004256f2  d1ea                 shr edx, 1
// 004256f4  bb49922409           mov ebx, 0x9249249
// 004256f9  2bda                 sub ebx, edx
// 004256fb  3bd9                 cmp ebx, ecx
// 004256fd  730c                 jae 0x42570b
// 004256ff  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00425706  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00425709  eb05                 jmp 0x425710
// 0042570b  03ca                 add ecx, edx
// 0042570d  894dec               mov dword ptr [ebp - 0x14], ecx
// 00425710  3bc8                 cmp ecx, eax
// 00425712  7305                 jae 0x425719
// 00425714  8945ec               mov dword ptr [ebp - 0x14], eax
// 00425717  8bc8                 mov ecx, eax
// 00425719  6a00                 push 0
// 0042571b  51                   push ecx
// 0042571c  e87f182300           call 0x656fa0
// 00425721  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00425724  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00425727  8bc8                 mov ecx, eax
// 00425729  b893244992           mov eax, 0x92492493
// 0042572e  f7eb                 imul ebx
// 00425730  03d3                 add edx, ebx
// 00425732  c1fa04               sar edx, 4
// 00425735  8bda                 mov ebx, edx
// 00425737  33c0                 xor eax, eax
// 00425739  c1eb1f               shr ebx, 0x1f
// 0042573c  03da                 add ebx, edx
// 0042573e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00425741  83c408               add esp, 8
// 00425744  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00425747  8945fc               mov dword ptr [ebp - 4], eax
// 0042574a  52                   push edx
// 0042574b  8d04dd00000000       lea eax, [ebx*8]
// 00425752  894de8               mov dword ptr [ebp - 0x18], ecx
// 00425755  2bc3                 sub eax, ebx
// 00425757  8d0c81               lea ecx, [ecx + eax*4]
// 0042575a  57                   push edi
// 0042575b  51                   push ecx
// 0042575c  8bce                 mov ecx, esi
// 0042575e  895ddc               mov dword ptr [ebp - 0x24], ebx
// 00425761  e8bafeffff           call 0x425620
// 00425766  8b460c               mov eax, dword ptr [esi + 0xc]
// 00425769  c6451400             mov byte ptr [ebp + 0x14], 0
// 0042576d  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00425770  52                   push edx
// 00425771  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00425774  52                   push edx
// 00425775  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00425778  8d4e08               lea ecx, [esi + 8]
// 0042577b  51                   push ecx
// 0042577c  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0042577f  51                   push ecx
// 00425780  52                   push edx
// 00425781  50                   push eax
// 00425782  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 00425789  e802f1ffff           call 0x424890
// 0042578e  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 00425791  8b4610               mov eax, dword ptr [esi + 0x10]
// 00425794  03df                 add ebx, edi
// 00425796  83c418               add esp, 0x18
// 00425799  8d0cdd00000000       lea ecx, [ebx*8]
// 004257a0  2bcb                 sub ecx, ebx
// 004257a2  8d0c8a               lea ecx, [edx + ecx*4]
// 004257a5  c6451400             mov byte ptr [ebp + 0x14], 0
// 004257a9  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004257ac  52                   push edx
// 004257ad  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004257b0  52                   push edx
// 004257b1  8d5608               lea edx, [esi + 8]
// 004257b4  52                   push edx
// 004257b5  51                   push ecx
// 004257b6  50                   push eax
// 004257b7  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004257ba  50                   push eax
// 004257bb  c745e402000000       mov dword ptr [ebp - 0x1c], 2
// 004257c2  e8c9f0ffff           call 0x424890
// 004257c7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004257ca  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004257cd  2bcb                 sub ecx, ebx
// 004257cf  b893244992           mov eax, 0x92492493
// 004257d4  f7e9                 imul ecx
// 004257d6  03d1                 add edx, ecx
// 004257d8  c1fa04               sar edx, 4
// 004257db  8bca                 mov ecx, edx
// 004257dd  c1e91f               shr ecx, 0x1f
// 004257e0  03ca                 add ecx, edx
// 004257e2  83c418               add esp, 0x18
// 004257e5  03f9                 add edi, ecx
// 004257e7  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 004257ee  85db                 test ebx, ebx
// 004257f0  7418                 je 0x42580a
// 004257f2  8b5610               mov edx, dword ptr [esi + 0x10]
// 004257f5  52                   push edx
// 004257f6  53                   push ebx
// 004257f7  8bce                 mov ecx, esi
// 004257f9  e8822dffff           call 0x418580
// 004257fe  8b460c               mov eax, dword ptr [esi + 0xc]
// 00425801  50                   push eax
// 00425802  e893213800           call 0x7a799a
// 00425807  83c404               add esp, 4
// 0042580a  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0042580d  8d0cc500000000       lea ecx, [eax*8]
// 00425814  2bc8                 sub ecx, eax
// 00425816  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00425819  8d1488               lea edx, [eax + ecx*4]
// 0042581c  8d0cfd00000000       lea ecx, [edi*8]
// 00425823  2bcf                 sub ecx, edi
// 00425825  895614               mov dword ptr [esi + 0x14], edx
// 00425828  8d1488               lea edx, [eax + ecx*4]
// 0042582b  895610               mov dword ptr [esi + 0x10], edx
// 0042582e  89460c               mov dword ptr [esi + 0xc], eax
// 00425831  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00425834  64890d00000000       mov dword ptr fs:[0], ecx
// 0042583b  5f                   pop edi
// 0042583c  5e                   pop esi
// 0042583d  5b                   pop ebx
// 0042583e  8be5                 mov esp, ebp
// 00425840  5d                   pop ebp
// 00425841  c21000               ret 0x10
// standard library vector<string> (function ?_Insert_n@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXV?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@IABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

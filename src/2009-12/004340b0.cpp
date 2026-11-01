// from server: 100% by auto
// roc 2009-12 004340b0  unit: CPropGrid::UpdateItemsJob  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004340b0
//
// 004340b0  64a100000000         mov eax, dword ptr fs:[0]
// 004340b6  6aff                 push -1
// 004340b8  6812699500           push 0x956912
// 004340bd  50                   push eax
// 004340be  64892500000000       mov dword ptr fs:[0], esp
// 004340c5  8b442418             mov eax, dword ptr [esp + 0x18]
// 004340c9  83ec48               sub esp, 0x48
// 004340cc  80781100             cmp byte ptr [eax + 0x11], 0
// 004340d0  55                   push ebp
// 004340d1  8be9                 mov ebp, ecx
// 004340d3  7459                 je 0x43412e
// 004340d5  68e4f49900           push 0x99f4e4
// 004340da  8d4c240c             lea ecx, [esp + 0xc]
// 004340de  ff15f4b69800         call dword ptr [0x98b6f4]
// 004340e4  8d4c2424             lea ecx, [esp + 0x24]
// 004340e8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004340f0  ff1554b79800         call dword ptr [0x98b754]
// 004340f6  8d442408             lea eax, [esp + 8]
// 004340fa  50                   push eax
// 004340fb  8d4c2434             lea ecx, [esp + 0x34]
// 004340ff  c644245801           mov byte ptr [esp + 0x58], 1
// 00434104  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 0043410c  ff15f0b69800         call dword ptr [0x98b6f0]
// 00434112  688cefa800           push 0xa8ef8c
// 00434117  8d4c2428             lea ecx, [esp + 0x28]
// 0043411b  51                   push ecx
// 0043411c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00434121  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 00434129  e84a073c00           call 0x7f4878
// 0043412e  53                   push ebx
// 0043412f  56                   push esi
// 00434130  8bd8                 mov ebx, eax
// 00434132  57                   push edi
// 00434133  8d4c246c             lea ecx, [esp + 0x6c]
// 00434137  895c2410             mov dword ptr [esp + 0x10], ebx
// 0043413b  e8405e2e00           call 0x719f80
// 00434140  8b0b                 mov ecx, dword ptr [ebx]
// 00434142  80791100             cmp byte ptr [ecx + 0x11], 0
// 00434146  7405                 je 0x43414d
// 00434148  8b7b08               mov edi, dword ptr [ebx + 8]
// 0043414b  eb1b                 jmp 0x434168
// 0043414d  8b5308               mov edx, dword ptr [ebx + 8]
// 00434150  807a1100             cmp byte ptr [edx + 0x11], 0
// 00434154  7404                 je 0x43415a
// 00434156  8bf9                 mov edi, ecx
// 00434158  eb0e                 jmp 0x434168
// 0043415a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0043415e  8b7808               mov edi, dword ptr [eax + 8]
// 00434161  8d5008               lea edx, [eax + 8]
// 00434164  3bc3                 cmp eax, ebx
// 00434166  756b                 jne 0x4341d3
// 00434168  807f1100             cmp byte ptr [edi + 0x11], 0
// 0043416c  8b7304               mov esi, dword ptr [ebx + 4]
// 0043416f  7503                 jne 0x434174
// 00434171  897704               mov dword ptr [edi + 4], esi
// 00434174  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00434177  395804               cmp dword ptr [eax + 4], ebx
// 0043417a  7505                 jne 0x434181
// 0043417c  897804               mov dword ptr [eax + 4], edi
// 0043417f  eb0b                 jmp 0x43418c
// 00434181  391e                 cmp dword ptr [esi], ebx
// 00434183  7504                 jne 0x434189
// 00434185  893e                 mov dword ptr [esi], edi
// 00434187  eb03                 jmp 0x43418c
// 00434189  897e08               mov dword ptr [esi + 8], edi
// 0043418c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0043418f  8b03                 mov eax, dword ptr [ebx]
// 00434191  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00434195  7515                 jne 0x4341ac
// 00434197  807f1100             cmp byte ptr [edi + 0x11], 0
// 0043419b  7404                 je 0x4341a1
// 0043419d  8bc6                 mov eax, esi
// 0043419f  eb09                 jmp 0x4341aa
// 004341a1  57                   push edi
// 004341a2  e8396c1200           call 0x55ade0
// 004341a7  83c404               add esp, 4
// 004341aa  8903                 mov dword ptr [ebx], eax
// 004341ac  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004341af  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004341b3  394b08               cmp dword ptr [ebx + 8], ecx
// 004341b6  7577                 jne 0x43422f
// 004341b8  807f1100             cmp byte ptr [edi + 0x11], 0
// 004341bc  7407                 je 0x4341c5
// 004341be  8bc6                 mov eax, esi
// 004341c0  894308               mov dword ptr [ebx + 8], eax
// 004341c3  eb6a                 jmp 0x43422f
// 004341c5  57                   push edi
// 004341c6  e8c5ddfcff           call 0x401f90
// 004341cb  83c404               add esp, 4
// 004341ce  894308               mov dword ptr [ebx + 8], eax
// 004341d1  eb5c                 jmp 0x43422f
// 004341d3  894104               mov dword ptr [ecx + 4], eax
// 004341d6  8b0b                 mov ecx, dword ptr [ebx]
// 004341d8  8908                 mov dword ptr [eax], ecx
// 004341da  3b4308               cmp eax, dword ptr [ebx + 8]
// 004341dd  7504                 jne 0x4341e3
// 004341df  8bf0                 mov esi, eax
// 004341e1  eb19                 jmp 0x4341fc
// 004341e3  807f1100             cmp byte ptr [edi + 0x11], 0
// 004341e7  8b7004               mov esi, dword ptr [eax + 4]
// 004341ea  7503                 jne 0x4341ef
// 004341ec  897704               mov dword ptr [edi + 4], esi
// 004341ef  893e                 mov dword ptr [esi], edi
// 004341f1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004341f4  890a                 mov dword ptr [edx], ecx
// 004341f6  8b5308               mov edx, dword ptr [ebx + 8]
// 004341f9  894204               mov dword ptr [edx + 4], eax
// 004341fc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004341ff  395904               cmp dword ptr [ecx + 4], ebx
// 00434202  7505                 jne 0x434209
// 00434204  894104               mov dword ptr [ecx + 4], eax
// 00434207  eb0e                 jmp 0x434217
// 00434209  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0043420c  3919                 cmp dword ptr [ecx], ebx
// 0043420e  7504                 jne 0x434214
// 00434210  8901                 mov dword ptr [ecx], eax
// 00434212  eb03                 jmp 0x434217
// 00434214  894108               mov dword ptr [ecx + 8], eax
// 00434217  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0043421a  894804               mov dword ptr [eax + 4], ecx
// 0043421d  8d4b10               lea ecx, [ebx + 0x10]
// 00434220  83c010               add eax, 0x10
// 00434223  3bc1                 cmp eax, ecx
// 00434225  7408                 je 0x43422f
// 00434227  8a19                 mov bl, byte ptr [ecx]
// 00434229  8a10                 mov dl, byte ptr [eax]
// 0043422b  8818                 mov byte ptr [eax], bl
// 0043422d  8811                 mov byte ptr [ecx], dl
// 0043422f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00434233  b301                 mov bl, 1
// 00434235  385a10               cmp byte ptr [edx + 0x10], bl
// 00434238  0f85fd000000         jne 0x43433b
// 0043423e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00434241  3b7804               cmp edi, dword ptr [eax + 4]
// 00434244  0f84ee000000         je 0x434338
// 0043424a  8d9b00000000         lea ebx, [ebx]
// 00434250  385f10               cmp byte ptr [edi + 0x10], bl
// 00434253  0f85df000000         jne 0x434338
// 00434259  8b06                 mov eax, dword ptr [esi]
// 0043425b  3bf8                 cmp edi, eax
// 0043425d  7565                 jne 0x4342c4
// 0043425f  8b4608               mov eax, dword ptr [esi + 8]
// 00434262  80781000             cmp byte ptr [eax + 0x10], 0
// 00434266  7512                 jne 0x43427a
// 00434268  885810               mov byte ptr [eax + 0x10], bl
// 0043426b  56                   push esi
// 0043426c  8bcd                 mov ecx, ebp
// 0043426e  c6461000             mov byte ptr [esi + 0x10], 0
// 00434272  e8c92e3800           call 0x7b7140
// 00434277  8b4608               mov eax, dword ptr [esi + 8]
// 0043427a  80781100             cmp byte ptr [eax + 0x11], 0
// 0043427e  7574                 jne 0x4342f4
// 00434280  8b08                 mov ecx, dword ptr [eax]
// 00434282  385910               cmp byte ptr [ecx + 0x10], bl
// 00434285  7508                 jne 0x43428f
// 00434287  8b5008               mov edx, dword ptr [eax + 8]
// 0043428a  385a10               cmp byte ptr [edx + 0x10], bl
// 0043428d  7461                 je 0x4342f0
// 0043428f  8b4808               mov ecx, dword ptr [eax + 8]
// 00434292  385910               cmp byte ptr [ecx + 0x10], bl
// 00434295  7514                 jne 0x4342ab
// 00434297  8b10                 mov edx, dword ptr [eax]
// 00434299  885a10               mov byte ptr [edx + 0x10], bl
// 0043429c  50                   push eax
// 0043429d  8bcd                 mov ecx, ebp
// 0043429f  c6401000             mov byte ptr [eax + 0x10], 0
// 004342a3  e8d8602e00           call 0x71a380
// 004342a8  8b4608               mov eax, dword ptr [esi + 8]
// 004342ab  8a4e10               mov cl, byte ptr [esi + 0x10]
// 004342ae  884810               mov byte ptr [eax + 0x10], cl
// 004342b1  885e10               mov byte ptr [esi + 0x10], bl
// 004342b4  8b5008               mov edx, dword ptr [eax + 8]
// 004342b7  56                   push esi
// 004342b8  8bcd                 mov ecx, ebp
// 004342ba  885a10               mov byte ptr [edx + 0x10], bl
// 004342bd  e87e2e3800           call 0x7b7140
// 004342c2  eb74                 jmp 0x434338
// 004342c4  80781000             cmp byte ptr [eax + 0x10], 0
// 004342c8  7511                 jne 0x4342db
// 004342ca  885810               mov byte ptr [eax + 0x10], bl
// 004342cd  56                   push esi
// 004342ce  8bcd                 mov ecx, ebp
// 004342d0  c6461000             mov byte ptr [esi + 0x10], 0
// 004342d4  e8a7602e00           call 0x71a380
// 004342d9  8b06                 mov eax, dword ptr [esi]
// 004342db  80781100             cmp byte ptr [eax + 0x11], 0
// 004342df  7513                 jne 0x4342f4
// 004342e1  8b4808               mov ecx, dword ptr [eax + 8]
// 004342e4  385910               cmp byte ptr [ecx + 0x10], bl
// 004342e7  751e                 jne 0x434307
// 004342e9  8b10                 mov edx, dword ptr [eax]
// 004342eb  385a10               cmp byte ptr [edx + 0x10], bl
// 004342ee  7517                 jne 0x434307
// 004342f0  c6401000             mov byte ptr [eax + 0x10], 0
// 004342f4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004342f7  8bfe                 mov edi, esi
// 004342f9  8b7604               mov esi, dword ptr [esi + 4]
// 004342fc  3b7804               cmp edi, dword ptr [eax + 4]
// 004342ff  0f854bffffff         jne 0x434250
// 00434305  eb31                 jmp 0x434338
// 00434307  8b08                 mov ecx, dword ptr [eax]
// 00434309  385910               cmp byte ptr [ecx + 0x10], bl
// 0043430c  7514                 jne 0x434322
// 0043430e  8b5008               mov edx, dword ptr [eax + 8]
// 00434311  885a10               mov byte ptr [edx + 0x10], bl
// 00434314  50                   push eax
// 00434315  8bcd                 mov ecx, ebp
// 00434317  c6401000             mov byte ptr [eax + 0x10], 0
// 0043431b  e8202e3800           call 0x7b7140
// 00434320  8b06                 mov eax, dword ptr [esi]
// 00434322  8a4e10               mov cl, byte ptr [esi + 0x10]
// 00434325  884810               mov byte ptr [eax + 0x10], cl
// 00434328  885e10               mov byte ptr [esi + 0x10], bl
// 0043432b  8b10                 mov edx, dword ptr [eax]
// 0043432d  56                   push esi
// 0043432e  8bcd                 mov ecx, ebp
// 00434330  885a10               mov byte ptr [edx + 0x10], bl
// 00434333  e848602e00           call 0x71a380
// 00434338  885f10               mov byte ptr [edi + 0x10], bl
// 0043433b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0043433f  50                   push eax
// 00434340  e815f53b00           call 0x7f385a
// 00434345  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00434348  83c404               add esp, 4
// 0043434b  5f                   pop edi
// 0043434c  5e                   pop esi
// 0043434d  5b                   pop ebx
// 0043434e  85c0                 test eax, eax
// 00434350  7604                 jbe 0x434356
// 00434352  48                   dec eax
// 00434353  89451c               mov dword ptr [ebp + 0x1c], eax
// 00434356  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0043435a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0043435e  8b5500               mov edx, dword ptr [ebp]
// 00434361  894804               mov dword ptr [eax + 4], ecx
// 00434364  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00434368  8910                 mov dword ptr [eax], edx
// 0043436a  5d                   pop ebp
// 0043436b  64890d00000000       mov dword ptr fs:[0], ecx
// 00434372  83c454               add esp, 0x54
// 00434375  c20c00               ret 0xc
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

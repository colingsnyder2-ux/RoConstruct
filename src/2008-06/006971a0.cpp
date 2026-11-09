// from server: 100% by auto
// roc 2008-06 006971a0  unit: Ogre::RbxSceneManager  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006971a0
//
// 006971a0  64a100000000         mov eax, dword ptr fs:[0]
// 006971a6  6aff                 push -1
// 006971a8  6842e87d00           push 0x7de842
// 006971ad  50                   push eax
// 006971ae  64892500000000       mov dword ptr fs:[0], esp
// 006971b5  8b442418             mov eax, dword ptr [esp + 0x18]
// 006971b9  83ec48               sub esp, 0x48
// 006971bc  80783900             cmp byte ptr [eax + 0x39], 0
// 006971c0  55                   push ebp
// 006971c1  8be9                 mov ebp, ecx
// 006971c3  7459                 je 0x69721e
// 006971c5  6870b28000           push 0x80b270
// 006971ca  8d4c240c             lea ecx, [esp + 0xc]
// 006971ce  ff1558248000         call dword ptr [0x802458]
// 006971d4  8d4c2424             lea ecx, [esp + 0x24]
// 006971d8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006971e0  ff1598288000         call dword ptr [0x802898]
// 006971e6  8d442408             lea eax, [esp + 8]
// 006971ea  50                   push eax
// 006971eb  8d4c2434             lea ecx, [esp + 0x34]
// 006971ef  c644245801           mov byte ptr [esp + 0x58], 1
// 006971f4  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 006971fc  ff155c248000         call dword ptr [0x80245c]
// 00697202  683c0c8d00           push 0x8d0c3c
// 00697207  8d4c2428             lea ecx, [esp + 0x28]
// 0069720b  51                   push ecx
// 0069720c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00697211  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 00697219  e86ea30000           call 0x6a158c
// 0069721e  53                   push ebx
// 0069721f  56                   push esi
// 00697220  8bd8                 mov ebx, eax
// 00697222  57                   push edi
// 00697223  8d4c246c             lea ecx, [esp + 0x6c]
// 00697227  895c2410             mov dword ptr [esp + 0x10], ebx
// 0069722b  e8e05fffff           call 0x68d210
// 00697230  8b0b                 mov ecx, dword ptr [ebx]
// 00697232  80793900             cmp byte ptr [ecx + 0x39], 0
// 00697236  7405                 je 0x69723d
// 00697238  8b7b08               mov edi, dword ptr [ebx + 8]
// 0069723b  eb1b                 jmp 0x697258
// 0069723d  8b5308               mov edx, dword ptr [ebx + 8]
// 00697240  807a3900             cmp byte ptr [edx + 0x39], 0
// 00697244  7404                 je 0x69724a
// 00697246  8bf9                 mov edi, ecx
// 00697248  eb0e                 jmp 0x697258
// 0069724a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0069724e  8b7808               mov edi, dword ptr [eax + 8]
// 00697251  8d5008               lea edx, [eax + 8]
// 00697254  3bc3                 cmp eax, ebx
// 00697256  756b                 jne 0x6972c3
// 00697258  807f3900             cmp byte ptr [edi + 0x39], 0
// 0069725c  8b7304               mov esi, dword ptr [ebx + 4]
// 0069725f  7503                 jne 0x697264
// 00697261  897704               mov dword ptr [edi + 4], esi
// 00697264  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00697267  395804               cmp dword ptr [eax + 4], ebx
// 0069726a  7505                 jne 0x697271
// 0069726c  897804               mov dword ptr [eax + 4], edi
// 0069726f  eb0b                 jmp 0x69727c
// 00697271  391e                 cmp dword ptr [esi], ebx
// 00697273  7504                 jne 0x697279
// 00697275  893e                 mov dword ptr [esi], edi
// 00697277  eb03                 jmp 0x69727c
// 00697279  897e08               mov dword ptr [esi + 8], edi
// 0069727c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0069727f  8b03                 mov eax, dword ptr [ebx]
// 00697281  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00697285  7515                 jne 0x69729c
// 00697287  807f3900             cmp byte ptr [edi + 0x39], 0
// 0069728b  7404                 je 0x697291
// 0069728d  8bc6                 mov eax, esi
// 0069728f  eb09                 jmp 0x69729a
// 00697291  57                   push edi
// 00697292  e8895effff           call 0x68d120
// 00697297  83c404               add esp, 4
// 0069729a  8903                 mov dword ptr [ebx], eax
// 0069729c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0069729f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006972a3  394b08               cmp dword ptr [ebx + 8], ecx
// 006972a6  7577                 jne 0x69731f
// 006972a8  807f3900             cmp byte ptr [edi + 0x39], 0
// 006972ac  7407                 je 0x6972b5
// 006972ae  8bc6                 mov eax, esi
// 006972b0  894308               mov dword ptr [ebx + 8], eax
// 006972b3  eb6a                 jmp 0x69731f
// 006972b5  57                   push edi
// 006972b6  e8455effff           call 0x68d100
// 006972bb  83c404               add esp, 4
// 006972be  894308               mov dword ptr [ebx + 8], eax
// 006972c1  eb5c                 jmp 0x69731f
// 006972c3  894104               mov dword ptr [ecx + 4], eax
// 006972c6  8b0b                 mov ecx, dword ptr [ebx]
// 006972c8  8908                 mov dword ptr [eax], ecx
// 006972ca  3b4308               cmp eax, dword ptr [ebx + 8]
// 006972cd  7504                 jne 0x6972d3
// 006972cf  8bf0                 mov esi, eax
// 006972d1  eb19                 jmp 0x6972ec
// 006972d3  807f3900             cmp byte ptr [edi + 0x39], 0
// 006972d7  8b7004               mov esi, dword ptr [eax + 4]
// 006972da  7503                 jne 0x6972df
// 006972dc  897704               mov dword ptr [edi + 4], esi
// 006972df  893e                 mov dword ptr [esi], edi
// 006972e1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006972e4  890a                 mov dword ptr [edx], ecx
// 006972e6  8b5308               mov edx, dword ptr [ebx + 8]
// 006972e9  894204               mov dword ptr [edx + 4], eax
// 006972ec  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006972ef  395904               cmp dword ptr [ecx + 4], ebx
// 006972f2  7505                 jne 0x6972f9
// 006972f4  894104               mov dword ptr [ecx + 4], eax
// 006972f7  eb0e                 jmp 0x697307
// 006972f9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006972fc  3919                 cmp dword ptr [ecx], ebx
// 006972fe  7504                 jne 0x697304
// 00697300  8901                 mov dword ptr [ecx], eax
// 00697302  eb03                 jmp 0x697307
// 00697304  894108               mov dword ptr [ecx + 8], eax
// 00697307  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0069730a  894804               mov dword ptr [eax + 4], ecx
// 0069730d  8d4b38               lea ecx, [ebx + 0x38]
// 00697310  83c038               add eax, 0x38
// 00697313  3bc1                 cmp eax, ecx
// 00697315  7408                 je 0x69731f
// 00697317  8a19                 mov bl, byte ptr [ecx]
// 00697319  8a10                 mov dl, byte ptr [eax]
// 0069731b  8818                 mov byte ptr [eax], bl
// 0069731d  8811                 mov byte ptr [ecx], dl
// 0069731f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00697323  b301                 mov bl, 1
// 00697325  385a38               cmp byte ptr [edx + 0x38], bl
// 00697328  0f85fd000000         jne 0x69742b
// 0069732e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00697331  3b7804               cmp edi, dword ptr [eax + 4]
// 00697334  0f84ee000000         je 0x697428
// 0069733a  8d9b00000000         lea ebx, [ebx]
// 00697340  385f38               cmp byte ptr [edi + 0x38], bl
// 00697343  0f85df000000         jne 0x697428
// 00697349  8b06                 mov eax, dword ptr [esi]
// 0069734b  3bf8                 cmp edi, eax
// 0069734d  7565                 jne 0x6973b4
// 0069734f  8b4608               mov eax, dword ptr [esi + 8]
// 00697352  80783800             cmp byte ptr [eax + 0x38], 0
// 00697356  7512                 jne 0x69736a
// 00697358  885838               mov byte ptr [eax + 0x38], bl
// 0069735b  56                   push esi
// 0069735c  8bcd                 mov ecx, ebp
// 0069735e  c6463800             mov byte ptr [esi + 0x38], 0
// 00697362  e8e96bffff           call 0x68df50
// 00697367  8b4608               mov eax, dword ptr [esi + 8]
// 0069736a  80783900             cmp byte ptr [eax + 0x39], 0
// 0069736e  7574                 jne 0x6973e4
// 00697370  8b08                 mov ecx, dword ptr [eax]
// 00697372  385938               cmp byte ptr [ecx + 0x38], bl
// 00697375  7508                 jne 0x69737f
// 00697377  8b5008               mov edx, dword ptr [eax + 8]
// 0069737a  385a38               cmp byte ptr [edx + 0x38], bl
// 0069737d  7461                 je 0x6973e0
// 0069737f  8b4808               mov ecx, dword ptr [eax + 8]
// 00697382  385938               cmp byte ptr [ecx + 0x38], bl
// 00697385  7514                 jne 0x69739b
// 00697387  8b10                 mov edx, dword ptr [eax]
// 00697389  885a38               mov byte ptr [edx + 0x38], bl
// 0069738c  50                   push eax
// 0069738d  8bcd                 mov ecx, ebp
// 0069738f  c6403800             mov byte ptr [eax + 0x38], 0
// 00697393  e8a85dffff           call 0x68d140
// 00697398  8b4608               mov eax, dword ptr [esi + 8]
// 0069739b  8a4e38               mov cl, byte ptr [esi + 0x38]
// 0069739e  884838               mov byte ptr [eax + 0x38], cl
// 006973a1  885e38               mov byte ptr [esi + 0x38], bl
// 006973a4  8b5008               mov edx, dword ptr [eax + 8]
// 006973a7  56                   push esi
// 006973a8  8bcd                 mov ecx, ebp
// 006973aa  885a38               mov byte ptr [edx + 0x38], bl
// 006973ad  e89e6bffff           call 0x68df50
// 006973b2  eb74                 jmp 0x697428
// 006973b4  80783800             cmp byte ptr [eax + 0x38], 0
// 006973b8  7511                 jne 0x6973cb
// 006973ba  885838               mov byte ptr [eax + 0x38], bl
// 006973bd  56                   push esi
// 006973be  8bcd                 mov ecx, ebp
// 006973c0  c6463800             mov byte ptr [esi + 0x38], 0
// 006973c4  e8775dffff           call 0x68d140
// 006973c9  8b06                 mov eax, dword ptr [esi]
// 006973cb  80783900             cmp byte ptr [eax + 0x39], 0
// 006973cf  7513                 jne 0x6973e4
// 006973d1  8b4808               mov ecx, dword ptr [eax + 8]
// 006973d4  385938               cmp byte ptr [ecx + 0x38], bl
// 006973d7  751e                 jne 0x6973f7
// 006973d9  8b10                 mov edx, dword ptr [eax]
// 006973db  385a38               cmp byte ptr [edx + 0x38], bl
// 006973de  7517                 jne 0x6973f7
// 006973e0  c6403800             mov byte ptr [eax + 0x38], 0
// 006973e4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006973e7  8bfe                 mov edi, esi
// 006973e9  8b7604               mov esi, dword ptr [esi + 4]
// 006973ec  3b7804               cmp edi, dword ptr [eax + 4]
// 006973ef  0f854bffffff         jne 0x697340
// 006973f5  eb31                 jmp 0x697428
// 006973f7  8b08                 mov ecx, dword ptr [eax]
// 006973f9  385938               cmp byte ptr [ecx + 0x38], bl
// 006973fc  7514                 jne 0x697412
// 006973fe  8b5008               mov edx, dword ptr [eax + 8]
// 00697401  885a38               mov byte ptr [edx + 0x38], bl
// 00697404  50                   push eax
// 00697405  8bcd                 mov ecx, ebp
// 00697407  c6403800             mov byte ptr [eax + 0x38], 0
// 0069740b  e8406bffff           call 0x68df50
// 00697410  8b06                 mov eax, dword ptr [esi]
// 00697412  8a4e38               mov cl, byte ptr [esi + 0x38]
// 00697415  884838               mov byte ptr [eax + 0x38], cl
// 00697418  885e38               mov byte ptr [esi + 0x38], bl
// 0069741b  8b10                 mov edx, dword ptr [eax]
// 0069741d  56                   push esi
// 0069741e  8bcd                 mov ecx, ebp
// 00697420  885a38               mov byte ptr [edx + 0x38], bl
// 00697423  e8185dffff           call 0x68d140
// 00697428  885f38               mov byte ptr [edi + 0x38], bl
// 0069742b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0069742f  83c110               add ecx, 0x10
// 00697432  ff15ec438000         call dword ptr [0x8043ec]
// 00697438  8b442410             mov eax, dword ptr [esp + 0x10]
// 0069743c  50                   push eax
// 0069743d  e838920000           call 0x6a067a
// 00697442  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00697445  83c404               add esp, 4
// 00697448  5f                   pop edi
// 00697449  5e                   pop esi
// 0069744a  5b                   pop ebx
// 0069744b  85c0                 test eax, eax
// 0069744d  7604                 jbe 0x697453
// 0069744f  48                   dec eax
// 00697450  89451c               mov dword ptr [ebp + 0x1c], eax
// 00697453  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00697457  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0069745b  8b5500               mov edx, dword ptr [ebp]
// 0069745e  894804               mov dword ptr [eax + 4], ecx
// 00697461  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00697465  8910                 mov dword ptr [eax], edx
// 00697467  5d                   pop ebp
// 00697468  64890d00000000       mov dword ptr fs:[0], ecx
// 0069746f  83c454               add esp, 0x54
// 00697472  c20c00               ret 0xc
// standard library map_str<double> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<double>
typedef double E;
#include <map>
#include <string>
template class std::map<std::string, E>;

// from server: 100% by auto
// roc 2009-12 0048f4c0  unit: RBX::RbxTextureProxy  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048f4c0
//
// 0048f4c0  64a100000000         mov eax, dword ptr fs:[0]
// 0048f4c6  6aff                 push -1
// 0048f4c8  6812699500           push 0x956912
// 0048f4cd  50                   push eax
// 0048f4ce  64892500000000       mov dword ptr fs:[0], esp
// 0048f4d5  8b442418             mov eax, dword ptr [esp + 0x18]
// 0048f4d9  83ec48               sub esp, 0x48
// 0048f4dc  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f4e0  55                   push ebp
// 0048f4e1  8be9                 mov ebp, ecx
// 0048f4e3  7459                 je 0x48f53e
// 0048f4e5  68e4f49900           push 0x99f4e4
// 0048f4ea  8d4c240c             lea ecx, [esp + 0xc]
// 0048f4ee  ff15f4b69800         call dword ptr [0x98b6f4]
// 0048f4f4  8d4c2424             lea ecx, [esp + 0x24]
// 0048f4f8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0048f500  ff1554b79800         call dword ptr [0x98b754]
// 0048f506  8d442408             lea eax, [esp + 8]
// 0048f50a  50                   push eax
// 0048f50b  8d4c2434             lea ecx, [esp + 0x34]
// 0048f50f  c644245801           mov byte ptr [esp + 0x58], 1
// 0048f514  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 0048f51c  ff15f0b69800         call dword ptr [0x98b6f0]
// 0048f522  688cefa800           push 0xa8ef8c
// 0048f527  8d4c2428             lea ecx, [esp + 0x28]
// 0048f52b  51                   push ecx
// 0048f52c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0048f531  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 0048f539  e83a533600           call 0x7f4878
// 0048f53e  53                   push ebx
// 0048f53f  56                   push esi
// 0048f540  8bd8                 mov ebx, eax
// 0048f542  57                   push edi
// 0048f543  8d4c246c             lea ecx, [esp + 0x6c]
// 0048f547  895c2410             mov dword ptr [esp + 0x10], ebx
// 0048f54b  e8b0fbffff           call 0x48f100
// 0048f550  8b0b                 mov ecx, dword ptr [ebx]
// 0048f552  80792100             cmp byte ptr [ecx + 0x21], 0
// 0048f556  7405                 je 0x48f55d
// 0048f558  8b7b08               mov edi, dword ptr [ebx + 8]
// 0048f55b  eb1b                 jmp 0x48f578
// 0048f55d  8b5308               mov edx, dword ptr [ebx + 8]
// 0048f560  807a2100             cmp byte ptr [edx + 0x21], 0
// 0048f564  7404                 je 0x48f56a
// 0048f566  8bf9                 mov edi, ecx
// 0048f568  eb0e                 jmp 0x48f578
// 0048f56a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0048f56e  8b7808               mov edi, dword ptr [eax + 8]
// 0048f571  8d5008               lea edx, [eax + 8]
// 0048f574  3bc3                 cmp eax, ebx
// 0048f576  756b                 jne 0x48f5e3
// 0048f578  807f2100             cmp byte ptr [edi + 0x21], 0
// 0048f57c  8b7304               mov esi, dword ptr [ebx + 4]
// 0048f57f  7503                 jne 0x48f584
// 0048f581  897704               mov dword ptr [edi + 4], esi
// 0048f584  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0048f587  395804               cmp dword ptr [eax + 4], ebx
// 0048f58a  7505                 jne 0x48f591
// 0048f58c  897804               mov dword ptr [eax + 4], edi
// 0048f58f  eb0b                 jmp 0x48f59c
// 0048f591  391e                 cmp dword ptr [esi], ebx
// 0048f593  7504                 jne 0x48f599
// 0048f595  893e                 mov dword ptr [esi], edi
// 0048f597  eb03                 jmp 0x48f59c
// 0048f599  897e08               mov dword ptr [esi + 8], edi
// 0048f59c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0048f59f  8b03                 mov eax, dword ptr [ebx]
// 0048f5a1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0048f5a5  7515                 jne 0x48f5bc
// 0048f5a7  807f2100             cmp byte ptr [edi + 0x21], 0
// 0048f5ab  7404                 je 0x48f5b1
// 0048f5ad  8bc6                 mov eax, esi
// 0048f5af  eb09                 jmp 0x48f5ba
// 0048f5b1  57                   push edi
// 0048f5b2  e889d01300           call 0x5cc640
// 0048f5b7  83c404               add esp, 4
// 0048f5ba  8903                 mov dword ptr [ebx], eax
// 0048f5bc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0048f5bf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048f5c3  394b08               cmp dword ptr [ebx + 8], ecx
// 0048f5c6  7577                 jne 0x48f63f
// 0048f5c8  807f2100             cmp byte ptr [edi + 0x21], 0
// 0048f5cc  7407                 je 0x48f5d5
// 0048f5ce  8bc6                 mov eax, esi
// 0048f5d0  894308               mov dword ptr [ebx + 8], eax
// 0048f5d3  eb6a                 jmp 0x48f63f
// 0048f5d5  57                   push edi
// 0048f5d6  e8c5d01300           call 0x5cc6a0
// 0048f5db  83c404               add esp, 4
// 0048f5de  894308               mov dword ptr [ebx + 8], eax
// 0048f5e1  eb5c                 jmp 0x48f63f
// 0048f5e3  894104               mov dword ptr [ecx + 4], eax
// 0048f5e6  8b0b                 mov ecx, dword ptr [ebx]
// 0048f5e8  8908                 mov dword ptr [eax], ecx
// 0048f5ea  3b4308               cmp eax, dword ptr [ebx + 8]
// 0048f5ed  7504                 jne 0x48f5f3
// 0048f5ef  8bf0                 mov esi, eax
// 0048f5f1  eb19                 jmp 0x48f60c
// 0048f5f3  807f2100             cmp byte ptr [edi + 0x21], 0
// 0048f5f7  8b7004               mov esi, dword ptr [eax + 4]
// 0048f5fa  7503                 jne 0x48f5ff
// 0048f5fc  897704               mov dword ptr [edi + 4], esi
// 0048f5ff  893e                 mov dword ptr [esi], edi
// 0048f601  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0048f604  890a                 mov dword ptr [edx], ecx
// 0048f606  8b5308               mov edx, dword ptr [ebx + 8]
// 0048f609  894204               mov dword ptr [edx + 4], eax
// 0048f60c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0048f60f  395904               cmp dword ptr [ecx + 4], ebx
// 0048f612  7505                 jne 0x48f619
// 0048f614  894104               mov dword ptr [ecx + 4], eax
// 0048f617  eb0e                 jmp 0x48f627
// 0048f619  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0048f61c  3919                 cmp dword ptr [ecx], ebx
// 0048f61e  7504                 jne 0x48f624
// 0048f620  8901                 mov dword ptr [ecx], eax
// 0048f622  eb03                 jmp 0x48f627
// 0048f624  894108               mov dword ptr [ecx + 8], eax
// 0048f627  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0048f62a  894804               mov dword ptr [eax + 4], ecx
// 0048f62d  8d4b20               lea ecx, [ebx + 0x20]
// 0048f630  83c020               add eax, 0x20
// 0048f633  3bc1                 cmp eax, ecx
// 0048f635  7408                 je 0x48f63f
// 0048f637  8a19                 mov bl, byte ptr [ecx]
// 0048f639  8a10                 mov dl, byte ptr [eax]
// 0048f63b  8818                 mov byte ptr [eax], bl
// 0048f63d  8811                 mov byte ptr [ecx], dl
// 0048f63f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048f643  b301                 mov bl, 1
// 0048f645  385a20               cmp byte ptr [edx + 0x20], bl
// 0048f648  0f85fd000000         jne 0x48f74b
// 0048f64e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0048f651  3b7804               cmp edi, dword ptr [eax + 4]
// 0048f654  0f84ee000000         je 0x48f748
// 0048f65a  8d9b00000000         lea ebx, [ebx]
// 0048f660  385f20               cmp byte ptr [edi + 0x20], bl
// 0048f663  0f85df000000         jne 0x48f748
// 0048f669  8b06                 mov eax, dword ptr [esi]
// 0048f66b  3bf8                 cmp edi, eax
// 0048f66d  7565                 jne 0x48f6d4
// 0048f66f  8b4608               mov eax, dword ptr [esi + 8]
// 0048f672  80782000             cmp byte ptr [eax + 0x20], 0
// 0048f676  7512                 jne 0x48f68a
// 0048f678  885820               mov byte ptr [eax + 0x20], bl
// 0048f67b  56                   push esi
// 0048f67c  8bcd                 mov ecx, ebp
// 0048f67e  c6462000             mov byte ptr [esi + 0x20], 0
// 0048f682  e8d9dc1300           call 0x5cd360
// 0048f687  8b4608               mov eax, dword ptr [esi + 8]
// 0048f68a  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f68e  7574                 jne 0x48f704
// 0048f690  8b08                 mov ecx, dword ptr [eax]
// 0048f692  385920               cmp byte ptr [ecx + 0x20], bl
// 0048f695  7508                 jne 0x48f69f
// 0048f697  8b5008               mov edx, dword ptr [eax + 8]
// 0048f69a  385a20               cmp byte ptr [edx + 0x20], bl
// 0048f69d  7461                 je 0x48f700
// 0048f69f  8b4808               mov ecx, dword ptr [eax + 8]
// 0048f6a2  385920               cmp byte ptr [ecx + 0x20], bl
// 0048f6a5  7514                 jne 0x48f6bb
// 0048f6a7  8b10                 mov edx, dword ptr [eax]
// 0048f6a9  885a20               mov byte ptr [edx + 0x20], bl
// 0048f6ac  50                   push eax
// 0048f6ad  8bcd                 mov ecx, ebp
// 0048f6af  c6402000             mov byte ptr [eax + 0x20], 0
// 0048f6b3  e8c8ce1300           call 0x5cc580
// 0048f6b8  8b4608               mov eax, dword ptr [esi + 8]
// 0048f6bb  8a4e20               mov cl, byte ptr [esi + 0x20]
// 0048f6be  884820               mov byte ptr [eax + 0x20], cl
// 0048f6c1  885e20               mov byte ptr [esi + 0x20], bl
// 0048f6c4  8b5008               mov edx, dword ptr [eax + 8]
// 0048f6c7  56                   push esi
// 0048f6c8  8bcd                 mov ecx, ebp
// 0048f6ca  885a20               mov byte ptr [edx + 0x20], bl
// 0048f6cd  e88edc1300           call 0x5cd360
// 0048f6d2  eb74                 jmp 0x48f748
// 0048f6d4  80782000             cmp byte ptr [eax + 0x20], 0
// 0048f6d8  7511                 jne 0x48f6eb
// 0048f6da  885820               mov byte ptr [eax + 0x20], bl
// 0048f6dd  56                   push esi
// 0048f6de  8bcd                 mov ecx, ebp
// 0048f6e0  c6462000             mov byte ptr [esi + 0x20], 0
// 0048f6e4  e897ce1300           call 0x5cc580
// 0048f6e9  8b06                 mov eax, dword ptr [esi]
// 0048f6eb  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f6ef  7513                 jne 0x48f704
// 0048f6f1  8b4808               mov ecx, dword ptr [eax + 8]
// 0048f6f4  385920               cmp byte ptr [ecx + 0x20], bl
// 0048f6f7  751e                 jne 0x48f717
// 0048f6f9  8b10                 mov edx, dword ptr [eax]
// 0048f6fb  385a20               cmp byte ptr [edx + 0x20], bl
// 0048f6fe  7517                 jne 0x48f717
// 0048f700  c6402000             mov byte ptr [eax + 0x20], 0
// 0048f704  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0048f707  8bfe                 mov edi, esi
// 0048f709  8b7604               mov esi, dword ptr [esi + 4]
// 0048f70c  3b7804               cmp edi, dword ptr [eax + 4]
// 0048f70f  0f854bffffff         jne 0x48f660
// 0048f715  eb31                 jmp 0x48f748
// 0048f717  8b08                 mov ecx, dword ptr [eax]
// 0048f719  385920               cmp byte ptr [ecx + 0x20], bl
// 0048f71c  7514                 jne 0x48f732
// 0048f71e  8b5008               mov edx, dword ptr [eax + 8]
// 0048f721  885a20               mov byte ptr [edx + 0x20], bl
// 0048f724  50                   push eax
// 0048f725  8bcd                 mov ecx, ebp
// 0048f727  c6402000             mov byte ptr [eax + 0x20], 0
// 0048f72b  e830dc1300           call 0x5cd360
// 0048f730  8b06                 mov eax, dword ptr [esi]
// 0048f732  8a4e20               mov cl, byte ptr [esi + 0x20]
// 0048f735  884820               mov byte ptr [eax + 0x20], cl
// 0048f738  885e20               mov byte ptr [esi + 0x20], bl
// 0048f73b  8b10                 mov edx, dword ptr [eax]
// 0048f73d  56                   push esi
// 0048f73e  8bcd                 mov ecx, ebp
// 0048f740  885a20               mov byte ptr [edx + 0x20], bl
// 0048f743  e838ce1300           call 0x5cc580
// 0048f748  885f20               mov byte ptr [edi + 0x20], bl
// 0048f74b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0048f74f  50                   push eax
// 0048f750  e805413600           call 0x7f385a
// 0048f755  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0048f758  83c404               add esp, 4
// 0048f75b  5f                   pop edi
// 0048f75c  5e                   pop esi
// 0048f75d  5b                   pop ebx
// 0048f75e  85c0                 test eax, eax
// 0048f760  7604                 jbe 0x48f766
// 0048f762  48                   dec eax
// 0048f763  89451c               mov dword ptr [ebp + 0x1c], eax
// 0048f766  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0048f76a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0048f76e  8b5500               mov edx, dword ptr [ebp]
// 0048f771  894804               mov dword ptr [eax + 4], ecx
// 0048f774  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0048f778  8910                 mov dword ptr [eax], edx
// 0048f77a  5d                   pop ebp
// 0048f77b  64890d00000000       mov dword ptr fs:[0], ecx
// 0048f782  83c454               add esp, 0x54
// 0048f785  c20c00               ret 0xc
// standard library set<pod20> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

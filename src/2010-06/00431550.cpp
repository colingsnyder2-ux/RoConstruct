// from server: 100% by auto
// roc 2010-06 00431550  unit: COutputView  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00431550
//
// 00431550  8b542404             mov edx, dword ptr [esp + 4]
// 00431554  83ec08               sub esp, 8
// 00431557  53                   push ebx
// 00431558  8bd9                 mov ebx, ecx
// 0043155a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0043155d  b966666606           mov ecx, 0x6666666
// 00431562  2bc8                 sub ecx, eax
// 00431564  3bca                 cmp ecx, edx
// 00431566  7305                 jae 0x43156d
// 00431568  e863e80800           call 0x4bfdd0
// 0043156d  8bc8                 mov ecx, eax
// 0043156f  d1e9                 shr ecx, 1
// 00431571  83f908               cmp ecx, 8
// 00431574  7305                 jae 0x43157b
// 00431576  b908000000           mov ecx, 8
// 0043157b  55                   push ebp
// 0043157c  56                   push esi
// 0043157d  57                   push edi
// 0043157e  3bd1                 cmp edx, ecx
// 00431580  7311                 jae 0x431593
// 00431582  be66666606           mov esi, 0x6666666
// 00431587  2bf1                 sub esi, ecx
// 00431589  3bc6                 cmp eax, esi
// 0043158b  7706                 ja 0x431593
// 0043158d  8bd1                 mov edx, ecx
// 0043158f  8954241c             mov dword ptr [esp + 0x1c], edx
// 00431593  8b7318               mov esi, dword ptr [ebx + 0x18]
// 00431596  03c2                 add eax, edx
// 00431598  6a00                 push 0
// 0043159a  50                   push eax
// 0043159b  89742418             mov dword ptr [esp + 0x18], esi
// 0043159f  e86c3d4a00           call 0x8d5310
// 004315a4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004315a7  8944241c             mov dword ptr [esp + 0x1c], eax
// 004315ab  03f6                 add esi, esi
// 004315ad  03f6                 add esi, esi
// 004315af  8d3c06               lea edi, [esi + eax]
// 004315b2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004315b5  03c0                 add eax, eax
// 004315b7  03c0                 add eax, eax
// 004315b9  8d140e               lea edx, [esi + ecx]
// 004315bc  2bc2                 sub eax, edx
// 004315be  03c1                 add eax, ecx
// 004315c0  c1f802               sar eax, 2
// 004315c3  83c408               add esp, 8
// 004315c6  8d0c8500000000       lea ecx, [eax*4]
// 004315cd  8d2c39               lea ebp, [ecx + edi]
// 004315d0  85c0                 test eax, eax
// 004315d2  760d                 jbe 0x4315e1
// 004315d4  51                   push ecx
// 004315d5  52                   push edx
// 004315d6  51                   push ecx
// 004315d7  57                   push edi
// 004315d8  ff1580a89e00         call dword ptr [0x9ea880]
// 004315de  83c410               add esp, 0x10
// 004315e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004315e5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004315e9  3bd0                 cmp edx, eax
// 004315eb  7743                 ja 0x431630
// 004315ed  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004315f0  c1fe02               sar esi, 2
// 004315f3  8d0cb500000000       lea ecx, [esi*4]
// 004315fa  8d3c29               lea edi, [ecx + ebp]
// 004315fd  85f6                 test esi, esi
// 004315ff  7611                 jbe 0x431612
// 00431601  51                   push ecx
// 00431602  50                   push eax
// 00431603  51                   push ecx
// 00431604  55                   push ebp
// 00431605  ff1580a89e00         call dword ptr [0x9ea880]
// 0043160b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0043160f  83c410               add esp, 0x10
// 00431612  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00431616  2bca                 sub ecx, edx
// 00431618  7408                 je 0x431622
// 0043161a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0043161e  33c0                 xor eax, eax
// 00431620  f3ab                 rep stosd dword ptr es:[edi], eax
// 00431622  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00431626  85d2                 test edx, edx
// 00431628  7662                 jbe 0x43168c
// 0043162a  8bca                 mov ecx, edx
// 0043162c  8bfd                 mov edi, ebp
// 0043162e  eb58                 jmp 0x431688
// 00431630  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00431633  8d3c8500000000       lea edi, [eax*4]
// 0043163a  8bc7                 mov eax, edi
// 0043163c  c1f802               sar eax, 2
// 0043163f  85c0                 test eax, eax
// 00431641  7611                 jbe 0x431654
// 00431643  03c0                 add eax, eax
// 00431645  03c0                 add eax, eax
// 00431647  50                   push eax
// 00431648  51                   push ecx
// 00431649  50                   push eax
// 0043164a  55                   push ebp
// 0043164b  ff1580a89e00         call dword ptr [0x9ea880]
// 00431651  83c410               add esp, 0x10
// 00431654  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00431657  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0043165b  8d0c07               lea ecx, [edi + eax]
// 0043165e  2bf1                 sub esi, ecx
// 00431660  03f0                 add esi, eax
// 00431662  c1fe02               sar esi, 2
// 00431665  8d04b500000000       lea eax, [esi*4]
// 0043166c  8d3c28               lea edi, [eax + ebp]
// 0043166f  85f6                 test esi, esi
// 00431671  760d                 jbe 0x431680
// 00431673  50                   push eax
// 00431674  51                   push ecx
// 00431675  50                   push eax
// 00431676  55                   push ebp
// 00431677  ff1580a89e00         call dword ptr [0x9ea880]
// 0043167d  83c410               add esp, 0x10
// 00431680  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00431684  85c9                 test ecx, ecx
// 00431686  7604                 jbe 0x43168c
// 00431688  33c0                 xor eax, eax
// 0043168a  f3ab                 rep stosd dword ptr es:[edi], eax
// 0043168c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0043168f  85c0                 test eax, eax
// 00431691  7409                 je 0x43169c
// 00431693  50                   push eax
// 00431694  e801633700           call 0x7a799a
// 00431699  83c404               add esp, 4
// 0043169c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004316a0  015314               add dword ptr [ebx + 0x14], edx
// 004316a3  5f                   pop edi
// 004316a4  5e                   pop esi
// 004316a5  896b10               mov dword ptr [ebx + 0x10], ebp
// 004316a8  5d                   pop ebp
// 004316a9  5b                   pop ebx
// 004316aa  83c408               add esp, 8
// 004316ad  c20400               ret 4
// standard library deque<pod40> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod40>
struct E { int v[10]; };
#include <deque>
template class std::deque<E>;

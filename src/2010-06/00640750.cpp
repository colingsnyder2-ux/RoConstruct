// from server: 100% by auto
// roc 2010-06 00640750  unit: RBX::VInstance::?$NonFactoryProduct  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00640750
//
// 00640750  64a100000000         mov eax, dword ptr fs:[0]
// 00640756  6aff                 push -1
// 00640758  68e22f9a00           push 0x9a2fe2
// 0064075d  50                   push eax
// 0064075e  64892500000000       mov dword ptr fs:[0], esp
// 00640765  8b442418             mov eax, dword ptr [esp + 0x18]
// 00640769  83ec48               sub esp, 0x48
// 0064076c  80783500             cmp byte ptr [eax + 0x35], 0
// 00640770  55                   push ebp
// 00640771  8be9                 mov ebp, ecx
// 00640773  7459                 je 0x6407ce
// 00640775  688c00a000           push 0xa0008c
// 0064077a  8d4c240c             lea ecx, [esp + 0xc]
// 0064077e  ff1510a49e00         call dword ptr [0x9ea410]
// 00640784  8d4c2424             lea ecx, [esp + 0x24]
// 00640788  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00640790  ff1518a99e00         call dword ptr [0x9ea918]
// 00640796  8d442408             lea eax, [esp + 8]
// 0064079a  50                   push eax
// 0064079b  8d4c2434             lea ecx, [esp + 0x34]
// 0064079f  c644245801           mov byte ptr [esp + 0x58], 1
// 006407a4  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 006407ac  ff150ca49e00         call dword ptr [0x9ea40c]
// 006407b2  68081bb000           push 0xb01b08
// 006407b7  8d4c2428             lea ecx, [esp + 0x28]
// 006407bb  51                   push ecx
// 006407bc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 006407c1  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 006407c9  e8e4811600           call 0x7a89b2
// 006407ce  53                   push ebx
// 006407cf  56                   push esi
// 006407d0  8bd8                 mov ebx, eax
// 006407d2  57                   push edi
// 006407d3  8d4c246c             lea ecx, [esp + 0x6c]
// 006407d7  895c2410             mov dword ptr [esp + 0x10], ebx
// 006407db  e82052eaff           call 0x4e5a00
// 006407e0  8b0b                 mov ecx, dword ptr [ebx]
// 006407e2  80793500             cmp byte ptr [ecx + 0x35], 0
// 006407e6  7405                 je 0x6407ed
// 006407e8  8b7b08               mov edi, dword ptr [ebx + 8]
// 006407eb  eb1b                 jmp 0x640808
// 006407ed  8b5308               mov edx, dword ptr [ebx + 8]
// 006407f0  807a3500             cmp byte ptr [edx + 0x35], 0
// 006407f4  7404                 je 0x6407fa
// 006407f6  8bf9                 mov edi, ecx
// 006407f8  eb0e                 jmp 0x640808
// 006407fa  8b442470             mov eax, dword ptr [esp + 0x70]
// 006407fe  8b7808               mov edi, dword ptr [eax + 8]
// 00640801  8d5008               lea edx, [eax + 8]
// 00640804  3bc3                 cmp eax, ebx
// 00640806  756b                 jne 0x640873
// 00640808  807f3500             cmp byte ptr [edi + 0x35], 0
// 0064080c  8b7304               mov esi, dword ptr [ebx + 4]
// 0064080f  7503                 jne 0x640814
// 00640811  897704               mov dword ptr [edi + 4], esi
// 00640814  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00640817  395804               cmp dword ptr [eax + 4], ebx
// 0064081a  7505                 jne 0x640821
// 0064081c  897804               mov dword ptr [eax + 4], edi
// 0064081f  eb0b                 jmp 0x64082c
// 00640821  391e                 cmp dword ptr [esi], ebx
// 00640823  7504                 jne 0x640829
// 00640825  893e                 mov dword ptr [esi], edi
// 00640827  eb03                 jmp 0x64082c
// 00640829  897e08               mov dword ptr [esi + 8], edi
// 0064082c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0064082f  8b03                 mov eax, dword ptr [ebx]
// 00640831  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00640835  7515                 jne 0x64084c
// 00640837  807f3500             cmp byte ptr [edi + 0x35], 0
// 0064083b  7404                 je 0x640841
// 0064083d  8bc6                 mov eax, esi
// 0064083f  eb09                 jmp 0x64084a
// 00640841  57                   push edi
// 00640842  e8b90efeff           call 0x621700
// 00640847  83c404               add esp, 4
// 0064084a  8903                 mov dword ptr [ebx], eax
// 0064084c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0064084f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00640853  394b08               cmp dword ptr [ebx + 8], ecx
// 00640856  7577                 jne 0x6408cf
// 00640858  807f3500             cmp byte ptr [edi + 0x35], 0
// 0064085c  7407                 je 0x640865
// 0064085e  8bc6                 mov eax, esi
// 00640860  894308               mov dword ptr [ebx + 8], eax
// 00640863  eb6a                 jmp 0x6408cf
// 00640865  57                   push edi
// 00640866  e87551eaff           call 0x4e59e0
// 0064086b  83c404               add esp, 4
// 0064086e  894308               mov dword ptr [ebx + 8], eax
// 00640871  eb5c                 jmp 0x6408cf
// 00640873  894104               mov dword ptr [ecx + 4], eax
// 00640876  8b0b                 mov ecx, dword ptr [ebx]
// 00640878  8908                 mov dword ptr [eax], ecx
// 0064087a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0064087d  7504                 jne 0x640883
// 0064087f  8bf0                 mov esi, eax
// 00640881  eb19                 jmp 0x64089c
// 00640883  807f3500             cmp byte ptr [edi + 0x35], 0
// 00640887  8b7004               mov esi, dword ptr [eax + 4]
// 0064088a  7503                 jne 0x64088f
// 0064088c  897704               mov dword ptr [edi + 4], esi
// 0064088f  893e                 mov dword ptr [esi], edi
// 00640891  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00640894  890a                 mov dword ptr [edx], ecx
// 00640896  8b5308               mov edx, dword ptr [ebx + 8]
// 00640899  894204               mov dword ptr [edx + 4], eax
// 0064089c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0064089f  395904               cmp dword ptr [ecx + 4], ebx
// 006408a2  7505                 jne 0x6408a9
// 006408a4  894104               mov dword ptr [ecx + 4], eax
// 006408a7  eb0e                 jmp 0x6408b7
// 006408a9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006408ac  3919                 cmp dword ptr [ecx], ebx
// 006408ae  7504                 jne 0x6408b4
// 006408b0  8901                 mov dword ptr [ecx], eax
// 006408b2  eb03                 jmp 0x6408b7
// 006408b4  894108               mov dword ptr [ecx + 8], eax
// 006408b7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006408ba  894804               mov dword ptr [eax + 4], ecx
// 006408bd  8d4b34               lea ecx, [ebx + 0x34]
// 006408c0  83c034               add eax, 0x34
// 006408c3  3bc1                 cmp eax, ecx
// 006408c5  7408                 je 0x6408cf
// 006408c7  8a19                 mov bl, byte ptr [ecx]
// 006408c9  8a10                 mov dl, byte ptr [eax]
// 006408cb  8818                 mov byte ptr [eax], bl
// 006408cd  8811                 mov byte ptr [ecx], dl
// 006408cf  8b542410             mov edx, dword ptr [esp + 0x10]
// 006408d3  b301                 mov bl, 1
// 006408d5  385a34               cmp byte ptr [edx + 0x34], bl
// 006408d8  0f85fd000000         jne 0x6409db
// 006408de  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006408e1  3b7804               cmp edi, dword ptr [eax + 4]
// 006408e4  0f84ee000000         je 0x6409d8
// 006408ea  8d9b00000000         lea ebx, [ebx]
// 006408f0  385f34               cmp byte ptr [edi + 0x34], bl
// 006408f3  0f85df000000         jne 0x6409d8
// 006408f9  8b06                 mov eax, dword ptr [esi]
// 006408fb  3bf8                 cmp edi, eax
// 006408fd  7565                 jne 0x640964
// 006408ff  8b4608               mov eax, dword ptr [esi + 8]
// 00640902  80783400             cmp byte ptr [eax + 0x34], 0
// 00640906  7512                 jne 0x64091a
// 00640908  885834               mov byte ptr [eax + 0x34], bl
// 0064090b  56                   push esi
// 0064090c  8bcd                 mov ecx, ebp
// 0064090e  c6463400             mov byte ptr [esi + 0x34], 0
// 00640912  e899f3ffff           call 0x63fcb0
// 00640917  8b4608               mov eax, dword ptr [esi + 8]
// 0064091a  80783500             cmp byte ptr [eax + 0x35], 0
// 0064091e  7574                 jne 0x640994
// 00640920  8b08                 mov ecx, dword ptr [eax]
// 00640922  385934               cmp byte ptr [ecx + 0x34], bl
// 00640925  7508                 jne 0x64092f
// 00640927  8b5008               mov edx, dword ptr [eax + 8]
// 0064092a  385a34               cmp byte ptr [edx + 0x34], bl
// 0064092d  7461                 je 0x640990
// 0064092f  8b4808               mov ecx, dword ptr [eax + 8]
// 00640932  385934               cmp byte ptr [ecx + 0x34], bl
// 00640935  7514                 jne 0x64094b
// 00640937  8b10                 mov edx, dword ptr [eax]
// 00640939  885a34               mov byte ptr [edx + 0x34], bl
// 0064093c  50                   push eax
// 0064093d  8bcd                 mov ecx, ebp
// 0064093f  c6403400             mov byte ptr [eax + 0x34], 0
// 00640943  e8b8f3ffff           call 0x63fd00
// 00640948  8b4608               mov eax, dword ptr [esi + 8]
// 0064094b  8a4e34               mov cl, byte ptr [esi + 0x34]
// 0064094e  884834               mov byte ptr [eax + 0x34], cl
// 00640951  885e34               mov byte ptr [esi + 0x34], bl
// 00640954  8b5008               mov edx, dword ptr [eax + 8]
// 00640957  56                   push esi
// 00640958  8bcd                 mov ecx, ebp
// 0064095a  885a34               mov byte ptr [edx + 0x34], bl
// 0064095d  e84ef3ffff           call 0x63fcb0
// 00640962  eb74                 jmp 0x6409d8
// 00640964  80783400             cmp byte ptr [eax + 0x34], 0
// 00640968  7511                 jne 0x64097b
// 0064096a  885834               mov byte ptr [eax + 0x34], bl
// 0064096d  56                   push esi
// 0064096e  8bcd                 mov ecx, ebp
// 00640970  c6463400             mov byte ptr [esi + 0x34], 0
// 00640974  e887f3ffff           call 0x63fd00
// 00640979  8b06                 mov eax, dword ptr [esi]
// 0064097b  80783500             cmp byte ptr [eax + 0x35], 0
// 0064097f  7513                 jne 0x640994
// 00640981  8b4808               mov ecx, dword ptr [eax + 8]
// 00640984  385934               cmp byte ptr [ecx + 0x34], bl
// 00640987  751e                 jne 0x6409a7
// 00640989  8b10                 mov edx, dword ptr [eax]
// 0064098b  385a34               cmp byte ptr [edx + 0x34], bl
// 0064098e  7517                 jne 0x6409a7
// 00640990  c6403400             mov byte ptr [eax + 0x34], 0
// 00640994  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00640997  8bfe                 mov edi, esi
// 00640999  8b7604               mov esi, dword ptr [esi + 4]
// 0064099c  3b7804               cmp edi, dword ptr [eax + 4]
// 0064099f  0f854bffffff         jne 0x6408f0
// 006409a5  eb31                 jmp 0x6409d8
// 006409a7  8b08                 mov ecx, dword ptr [eax]
// 006409a9  385934               cmp byte ptr [ecx + 0x34], bl
// 006409ac  7514                 jne 0x6409c2
// 006409ae  8b5008               mov edx, dword ptr [eax + 8]
// 006409b1  885a34               mov byte ptr [edx + 0x34], bl
// 006409b4  50                   push eax
// 006409b5  8bcd                 mov ecx, ebp
// 006409b7  c6403400             mov byte ptr [eax + 0x34], 0
// 006409bb  e8f0f2ffff           call 0x63fcb0
// 006409c0  8b06                 mov eax, dword ptr [esi]
// 006409c2  8a4e34               mov cl, byte ptr [esi + 0x34]
// 006409c5  884834               mov byte ptr [eax + 0x34], cl
// 006409c8  885e34               mov byte ptr [esi + 0x34], bl
// 006409cb  8b10                 mov edx, dword ptr [eax]
// 006409cd  56                   push esi
// 006409ce  8bcd                 mov ecx, ebp
// 006409d0  885a34               mov byte ptr [edx + 0x34], bl
// 006409d3  e828f3ffff           call 0x63fd00
// 006409d8  885f34               mov byte ptr [edi + 0x34], bl
// 006409db  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006409df  83c10c               add ecx, 0xc
// 006409e2  ff1500a49e00         call dword ptr [0x9ea400]
// 006409e8  8b442410             mov eax, dword ptr [esp + 0x10]
// 006409ec  50                   push eax
// 006409ed  e8a86f1600           call 0x7a799a
// 006409f2  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 006409f5  83c404               add esp, 4
// 006409f8  5f                   pop edi
// 006409f9  5e                   pop esi
// 006409fa  5b                   pop ebx
// 006409fb  85c0                 test eax, eax
// 006409fd  7604                 jbe 0x640a03
// 006409ff  48                   dec eax
// 00640a00  89451c               mov dword ptr [ebp + 0x1c], eax
// 00640a03  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00640a07  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00640a0b  8b5500               mov edx, dword ptr [ebp]
// 00640a0e  894804               mov dword ptr [eax + 4], ecx
// 00640a11  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00640a15  8910                 mov dword ptr [eax], edx
// 00640a17  5d                   pop ebp
// 00640a18  64890d00000000       mov dword ptr fs:[0], ecx
// 00640a1f  83c454               add esp, 0x54
// 00640a22  c20c00               ret 0xc
// standard library map_str<pod12> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

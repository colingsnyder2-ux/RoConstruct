// from server: 100% by auto
// roc 2007-03 00580790  unit: seg_00580000  size: 696 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00580790
//
// 00580790  64a100000000         mov eax, dword ptr fs:[0]
// 00580796  6aff                 push -1
// 00580798  68926f7500           push 0x756f92
// 0058079d  50                   push eax
// 0058079e  64892500000000       mov dword ptr fs:[0], esp
// 005807a5  8b442418             mov eax, dword ptr [esp + 0x18]
// 005807a9  83ec48               sub esp, 0x48
// 005807ac  80782100             cmp byte ptr [eax + 0x21], 0
// 005807b0  55                   push ebp
// 005807b1  8be9                 mov ebp, ecx
// 005807b3  7459                 je 0x58080e
// 005807b5  68dc3e7800           push 0x783edc
// 005807ba  8d4c240c             lea ecx, [esp + 0xc]
// 005807be  ff1578e77700         call dword ptr [0x77e778]
// 005807c4  8d4c2424             lea ecx, [esp + 0x24]
// 005807c8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005807d0  ff1560e97700         call dword ptr [0x77e960]
// 005807d6  8d442408             lea eax, [esp + 8]
// 005807da  50                   push eax
// 005807db  8d4c2434             lea ecx, [esp + 0x34]
// 005807df  c644245801           mov byte ptr [esp + 0x58], 1
// 005807e4  c7442428383e7800     mov dword ptr [esp + 0x28], 0x783e38
// 005807ec  ff157ce77700         call dword ptr [0x77e77c]
// 005807f2  68ccf38300           push 0x83f3cc
// 005807f7  8d4c2428             lea ecx, [esp + 0x28]
// 005807fb  51                   push ecx
// 005807fc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00580801  c744242c503e7800     mov dword ptr [esp + 0x2c], 0x783e50
// 00580809  e820e80900           call 0x61f02e
// 0058080e  53                   push ebx
// 0058080f  56                   push esi
// 00580810  8bd8                 mov ebx, eax
// 00580812  57                   push edi
// 00580813  8d4c246c             lea ecx, [esp + 0x6c]
// 00580817  895c2410             mov dword ptr [esp + 0x10], ebx
// 0058081b  e8007af1ff           call 0x498220
// 00580820  8b03                 mov eax, dword ptr [ebx]
// 00580822  80782100             cmp byte ptr [eax + 0x21], 0
// 00580826  7405                 je 0x58082d
// 00580828  8b7b08               mov edi, dword ptr [ebx + 8]
// 0058082b  eb18                 jmp 0x580845
// 0058082d  8b5308               mov edx, dword ptr [ebx + 8]
// 00580830  807a2100             cmp byte ptr [edx + 0x21], 0
// 00580834  7404                 je 0x58083a
// 00580836  8bf8                 mov edi, eax
// 00580838  eb0b                 jmp 0x580845
// 0058083a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0058083e  3bcb                 cmp ecx, ebx
// 00580840  8b7908               mov edi, dword ptr [ecx + 8]
// 00580843  756b                 jne 0x5808b0
// 00580845  807f2100             cmp byte ptr [edi + 0x21], 0
// 00580849  8b7304               mov esi, dword ptr [ebx + 4]
// 0058084c  7503                 jne 0x580851
// 0058084e  897704               mov dword ptr [edi + 4], esi
// 00580851  8b4504               mov eax, dword ptr [ebp + 4]
// 00580854  395804               cmp dword ptr [eax + 4], ebx
// 00580857  7505                 jne 0x58085e
// 00580859  897804               mov dword ptr [eax + 4], edi
// 0058085c  eb0b                 jmp 0x580869
// 0058085e  391e                 cmp dword ptr [esi], ebx
// 00580860  7504                 jne 0x580866
// 00580862  893e                 mov dword ptr [esi], edi
// 00580864  eb03                 jmp 0x580869
// 00580866  897e08               mov dword ptr [esi + 8], edi
// 00580869  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0058086c  8b03                 mov eax, dword ptr [ebx]
// 0058086e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00580872  7515                 jne 0x580889
// 00580874  807f2100             cmp byte ptr [edi + 0x21], 0
// 00580878  7404                 je 0x58087e
// 0058087a  8bc6                 mov eax, esi
// 0058087c  eb09                 jmp 0x580887
// 0058087e  57                   push edi
// 0058087f  e82c19f4ff           call 0x4c21b0
// 00580884  83c404               add esp, 4
// 00580887  8903                 mov dword ptr [ebx], eax
// 00580889  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0058088c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00580890  394b08               cmp dword ptr [ebx + 8], ecx
// 00580893  7572                 jne 0x580907
// 00580895  807f2100             cmp byte ptr [edi + 0x21], 0
// 00580899  7407                 je 0x5808a2
// 0058089b  8bc6                 mov eax, esi
// 0058089d  894308               mov dword ptr [ebx + 8], eax
// 005808a0  eb65                 jmp 0x580907
// 005808a2  57                   push edi
// 005808a3  e828110100           call 0x5919d0
// 005808a8  83c404               add esp, 4
// 005808ab  894308               mov dword ptr [ebx + 8], eax
// 005808ae  eb57                 jmp 0x580907
// 005808b0  894804               mov dword ptr [eax + 4], ecx
// 005808b3  8b13                 mov edx, dword ptr [ebx]
// 005808b5  8911                 mov dword ptr [ecx], edx
// 005808b7  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 005808ba  7504                 jne 0x5808c0
// 005808bc  8bf1                 mov esi, ecx
// 005808be  eb1a                 jmp 0x5808da
// 005808c0  807f2100             cmp byte ptr [edi + 0x21], 0
// 005808c4  8b7104               mov esi, dword ptr [ecx + 4]
// 005808c7  7503                 jne 0x5808cc
// 005808c9  897704               mov dword ptr [edi + 4], esi
// 005808cc  893e                 mov dword ptr [esi], edi
// 005808ce  8b4308               mov eax, dword ptr [ebx + 8]
// 005808d1  894108               mov dword ptr [ecx + 8], eax
// 005808d4  8b5308               mov edx, dword ptr [ebx + 8]
// 005808d7  894a04               mov dword ptr [edx + 4], ecx
// 005808da  8b4504               mov eax, dword ptr [ebp + 4]
// 005808dd  395804               cmp dword ptr [eax + 4], ebx
// 005808e0  7505                 jne 0x5808e7
// 005808e2  894804               mov dword ptr [eax + 4], ecx
// 005808e5  eb0e                 jmp 0x5808f5
// 005808e7  8b4304               mov eax, dword ptr [ebx + 4]
// 005808ea  3918                 cmp dword ptr [eax], ebx
// 005808ec  7504                 jne 0x5808f2
// 005808ee  8908                 mov dword ptr [eax], ecx
// 005808f0  eb03                 jmp 0x5808f5
// 005808f2  894808               mov dword ptr [eax + 8], ecx
// 005808f5  8b4304               mov eax, dword ptr [ebx + 4]
// 005808f8  894104               mov dword ptr [ecx + 4], eax
// 005808fb  8a5320               mov dl, byte ptr [ebx + 0x20]
// 005808fe  8a4120               mov al, byte ptr [ecx + 0x20]
// 00580901  885120               mov byte ptr [ecx + 0x20], dl
// 00580904  884320               mov byte ptr [ebx + 0x20], al
// 00580907  8b442410             mov eax, dword ptr [esp + 0x10]
// 0058090b  b301                 mov bl, 1
// 0058090d  385820               cmp byte ptr [eax + 0x20], bl
// 00580910  0f85f2000000         jne 0x580a08
// 00580916  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00580919  3b7904               cmp edi, dword ptr [ecx + 4]
// 0058091c  0f84e3000000         je 0x580a05
// 00580922  385f20               cmp byte ptr [edi + 0x20], bl
// 00580925  0f85da000000         jne 0x580a05
// 0058092b  8b06                 mov eax, dword ptr [esi]
// 0058092d  3bf8                 cmp edi, eax
// 0058092f  7563                 jne 0x580994
// 00580931  8b4608               mov eax, dword ptr [esi + 8]
// 00580934  80782000             cmp byte ptr [eax + 0x20], 0
// 00580938  7512                 jne 0x58094c
// 0058093a  885820               mov byte ptr [eax + 0x20], bl
// 0058093d  56                   push esi
// 0058093e  8bcd                 mov ecx, ebp
// 00580940  c6462000             mov byte ptr [esi + 0x20], 0
// 00580944  e8971af4ff           call 0x4c23e0
// 00580949  8b4608               mov eax, dword ptr [esi + 8]
// 0058094c  80782100             cmp byte ptr [eax + 0x21], 0
// 00580950  7572                 jne 0x5809c4
// 00580952  8b10                 mov edx, dword ptr [eax]
// 00580954  385a20               cmp byte ptr [edx + 0x20], bl
// 00580957  7508                 jne 0x580961
// 00580959  8b4808               mov ecx, dword ptr [eax + 8]
// 0058095c  385920               cmp byte ptr [ecx + 0x20], bl
// 0058095f  745f                 je 0x5809c0
// 00580961  8b4808               mov ecx, dword ptr [eax + 8]
// 00580964  385920               cmp byte ptr [ecx + 0x20], bl
// 00580967  7512                 jne 0x58097b
// 00580969  885a20               mov byte ptr [edx + 0x20], bl
// 0058096c  50                   push eax
// 0058096d  8bcd                 mov ecx, ebp
// 0058096f  c6402000             mov byte ptr [eax + 0x20], 0
// 00580973  e8088debff           call 0x439680
// 00580978  8b4608               mov eax, dword ptr [esi + 8]
// 0058097b  8a4e20               mov cl, byte ptr [esi + 0x20]
// 0058097e  884820               mov byte ptr [eax + 0x20], cl
// 00580981  885e20               mov byte ptr [esi + 0x20], bl
// 00580984  8b5008               mov edx, dword ptr [eax + 8]
// 00580987  56                   push esi
// 00580988  8bcd                 mov ecx, ebp
// 0058098a  885a20               mov byte ptr [edx + 0x20], bl
// 0058098d  e84e1af4ff           call 0x4c23e0
// 00580992  eb71                 jmp 0x580a05
// 00580994  80782000             cmp byte ptr [eax + 0x20], 0
// 00580998  7511                 jne 0x5809ab
// 0058099a  885820               mov byte ptr [eax + 0x20], bl
// 0058099d  56                   push esi
// 0058099e  8bcd                 mov ecx, ebp
// 005809a0  c6462000             mov byte ptr [esi + 0x20], 0
// 005809a4  e8d78cebff           call 0x439680
// 005809a9  8b06                 mov eax, dword ptr [esi]
// 005809ab  80782100             cmp byte ptr [eax + 0x21], 0
// 005809af  7513                 jne 0x5809c4
// 005809b1  8b5008               mov edx, dword ptr [eax + 8]
// 005809b4  385a20               cmp byte ptr [edx + 0x20], bl
// 005809b7  751e                 jne 0x5809d7
// 005809b9  8b08                 mov ecx, dword ptr [eax]
// 005809bb  385920               cmp byte ptr [ecx + 0x20], bl
// 005809be  7517                 jne 0x5809d7
// 005809c0  c6402000             mov byte ptr [eax + 0x20], 0
// 005809c4  8b5504               mov edx, dword ptr [ebp + 4]
// 005809c7  8bfe                 mov edi, esi
// 005809c9  3b7a04               cmp edi, dword ptr [edx + 4]
// 005809cc  8b7604               mov esi, dword ptr [esi + 4]
// 005809cf  0f854dffffff         jne 0x580922
// 005809d5  eb2e                 jmp 0x580a05
// 005809d7  8b08                 mov ecx, dword ptr [eax]
// 005809d9  385920               cmp byte ptr [ecx + 0x20], bl
// 005809dc  7511                 jne 0x5809ef
// 005809de  885a20               mov byte ptr [edx + 0x20], bl
// 005809e1  50                   push eax
// 005809e2  8bcd                 mov ecx, ebp
// 005809e4  c6402000             mov byte ptr [eax + 0x20], 0
// 005809e8  e8f319f4ff           call 0x4c23e0
// 005809ed  8b06                 mov eax, dword ptr [esi]
// 005809ef  8a4e20               mov cl, byte ptr [esi + 0x20]
// 005809f2  884820               mov byte ptr [eax + 0x20], cl
// 005809f5  885e20               mov byte ptr [esi + 0x20], bl
// 005809f8  8b10                 mov edx, dword ptr [eax]
// 005809fa  56                   push esi
// 005809fb  8bcd                 mov ecx, ebp
// 005809fd  885a20               mov byte ptr [edx + 0x20], bl
// 00580a00  e87b8cebff           call 0x439680
// 00580a05  885f20               mov byte ptr [edi + 0x20], bl
// 00580a08  8b442410             mov eax, dword ptr [esp + 0x10]
// 00580a0c  50                   push eax
// 00580a0d  e8ded60900           call 0x61e0f0
// 00580a12  8b4508               mov eax, dword ptr [ebp + 8]
// 00580a15  83c404               add esp, 4
// 00580a18  85c0                 test eax, eax
// 00580a1a  5f                   pop edi
// 00580a1b  5e                   pop esi
// 00580a1c  5b                   pop ebx
// 00580a1d  7606                 jbe 0x580a25
// 00580a1f  83c0ff               add eax, -1
// 00580a22  894508               mov dword ptr [ebp + 8], eax
// 00580a25  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00580a29  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00580a2d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00580a31  8908                 mov dword ptr [eax], ecx
// 00580a33  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00580a37  895004               mov dword ptr [eax + 4], edx
// 00580a3a  5d                   pop ebp
// 00580a3b  64890d00000000       mov dword ptr fs:[0], ecx
// 00580a42  83c454               add esp, 0x54
// 00580a45  c20c00               ret 0xc
// standard library set<pod20> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

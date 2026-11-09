// from server: 100% by auto
// roc 2010-06 00759000  unit: RBX::PyramidPoly  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00759000
//
// 00759000  64a100000000         mov eax, dword ptr fs:[0]
// 00759006  6aff                 push -1
// 00759008  68e22f9a00           push 0x9a2fe2
// 0075900d  50                   push eax
// 0075900e  64892500000000       mov dword ptr fs:[0], esp
// 00759015  8b442418             mov eax, dword ptr [esp + 0x18]
// 00759019  83ec48               sub esp, 0x48
// 0075901c  80782500             cmp byte ptr [eax + 0x25], 0
// 00759020  55                   push ebp
// 00759021  8be9                 mov ebp, ecx
// 00759023  7459                 je 0x75907e
// 00759025  688c00a000           push 0xa0008c
// 0075902a  8d4c240c             lea ecx, [esp + 0xc]
// 0075902e  ff1510a49e00         call dword ptr [0x9ea410]
// 00759034  8d4c2424             lea ecx, [esp + 0x24]
// 00759038  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00759040  ff1518a99e00         call dword ptr [0x9ea918]
// 00759046  8d442408             lea eax, [esp + 8]
// 0075904a  50                   push eax
// 0075904b  8d4c2434             lea ecx, [esp + 0x34]
// 0075904f  c644245801           mov byte ptr [esp + 0x58], 1
// 00759054  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 0075905c  ff150ca49e00         call dword ptr [0x9ea40c]
// 00759062  68081bb000           push 0xb01b08
// 00759067  8d4c2428             lea ecx, [esp + 0x28]
// 0075906b  51                   push ecx
// 0075906c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00759071  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 00759079  e834f90400           call 0x7a89b2
// 0075907e  53                   push ebx
// 0075907f  56                   push esi
// 00759080  8bd8                 mov ebx, eax
// 00759082  57                   push edi
// 00759083  8d4c246c             lea ecx, [esp + 0x6c]
// 00759087  895c2410             mov dword ptr [esp + 0x10], ebx
// 0075908b  e880feffff           call 0x758f10
// 00759090  8b0b                 mov ecx, dword ptr [ebx]
// 00759092  80792500             cmp byte ptr [ecx + 0x25], 0
// 00759096  7405                 je 0x75909d
// 00759098  8b7b08               mov edi, dword ptr [ebx + 8]
// 0075909b  eb1b                 jmp 0x7590b8
// 0075909d  8b5308               mov edx, dword ptr [ebx + 8]
// 007590a0  807a2500             cmp byte ptr [edx + 0x25], 0
// 007590a4  7404                 je 0x7590aa
// 007590a6  8bf9                 mov edi, ecx
// 007590a8  eb0e                 jmp 0x7590b8
// 007590aa  8b442470             mov eax, dword ptr [esp + 0x70]
// 007590ae  8b7808               mov edi, dword ptr [eax + 8]
// 007590b1  8d5008               lea edx, [eax + 8]
// 007590b4  3bc3                 cmp eax, ebx
// 007590b6  756b                 jne 0x759123
// 007590b8  807f2500             cmp byte ptr [edi + 0x25], 0
// 007590bc  8b7304               mov esi, dword ptr [ebx + 4]
// 007590bf  7503                 jne 0x7590c4
// 007590c1  897704               mov dword ptr [edi + 4], esi
// 007590c4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 007590c7  395804               cmp dword ptr [eax + 4], ebx
// 007590ca  7505                 jne 0x7590d1
// 007590cc  897804               mov dword ptr [eax + 4], edi
// 007590cf  eb0b                 jmp 0x7590dc
// 007590d1  391e                 cmp dword ptr [esi], ebx
// 007590d3  7504                 jne 0x7590d9
// 007590d5  893e                 mov dword ptr [esi], edi
// 007590d7  eb03                 jmp 0x7590dc
// 007590d9  897e08               mov dword ptr [esi + 8], edi
// 007590dc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 007590df  8b03                 mov eax, dword ptr [ebx]
// 007590e1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 007590e5  7515                 jne 0x7590fc
// 007590e7  807f2500             cmp byte ptr [edi + 0x25], 0
// 007590eb  7404                 je 0x7590f1
// 007590ed  8bc6                 mov eax, esi
// 007590ef  eb09                 jmp 0x7590fa
// 007590f1  57                   push edi
// 007590f2  e859dcffff           call 0x756d50
// 007590f7  83c404               add esp, 4
// 007590fa  8903                 mov dword ptr [ebx], eax
// 007590fc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 007590ff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00759103  394b08               cmp dword ptr [ebx + 8], ecx
// 00759106  7577                 jne 0x75917f
// 00759108  807f2500             cmp byte ptr [edi + 0x25], 0
// 0075910c  7407                 je 0x759115
// 0075910e  8bc6                 mov eax, esi
// 00759110  894308               mov dword ptr [ebx + 8], eax
// 00759113  eb6a                 jmp 0x75917f
// 00759115  57                   push edi
// 00759116  e885d9dcff           call 0x526aa0
// 0075911b  83c404               add esp, 4
// 0075911e  894308               mov dword ptr [ebx + 8], eax
// 00759121  eb5c                 jmp 0x75917f
// 00759123  894104               mov dword ptr [ecx + 4], eax
// 00759126  8b0b                 mov ecx, dword ptr [ebx]
// 00759128  8908                 mov dword ptr [eax], ecx
// 0075912a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0075912d  7504                 jne 0x759133
// 0075912f  8bf0                 mov esi, eax
// 00759131  eb19                 jmp 0x75914c
// 00759133  807f2500             cmp byte ptr [edi + 0x25], 0
// 00759137  8b7004               mov esi, dword ptr [eax + 4]
// 0075913a  7503                 jne 0x75913f
// 0075913c  897704               mov dword ptr [edi + 4], esi
// 0075913f  893e                 mov dword ptr [esi], edi
// 00759141  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00759144  890a                 mov dword ptr [edx], ecx
// 00759146  8b5308               mov edx, dword ptr [ebx + 8]
// 00759149  894204               mov dword ptr [edx + 4], eax
// 0075914c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0075914f  395904               cmp dword ptr [ecx + 4], ebx
// 00759152  7505                 jne 0x759159
// 00759154  894104               mov dword ptr [ecx + 4], eax
// 00759157  eb0e                 jmp 0x759167
// 00759159  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0075915c  3919                 cmp dword ptr [ecx], ebx
// 0075915e  7504                 jne 0x759164
// 00759160  8901                 mov dword ptr [ecx], eax
// 00759162  eb03                 jmp 0x759167
// 00759164  894108               mov dword ptr [ecx + 8], eax
// 00759167  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0075916a  894804               mov dword ptr [eax + 4], ecx
// 0075916d  8d4b24               lea ecx, [ebx + 0x24]
// 00759170  83c024               add eax, 0x24
// 00759173  3bc1                 cmp eax, ecx
// 00759175  7408                 je 0x75917f
// 00759177  8a19                 mov bl, byte ptr [ecx]
// 00759179  8a10                 mov dl, byte ptr [eax]
// 0075917b  8818                 mov byte ptr [eax], bl
// 0075917d  8811                 mov byte ptr [ecx], dl
// 0075917f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00759183  b301                 mov bl, 1
// 00759185  385a24               cmp byte ptr [edx + 0x24], bl
// 00759188  0f85fd000000         jne 0x75928b
// 0075918e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00759191  3b7804               cmp edi, dword ptr [eax + 4]
// 00759194  0f84ee000000         je 0x759288
// 0075919a  8d9b00000000         lea ebx, [ebx]
// 007591a0  385f24               cmp byte ptr [edi + 0x24], bl
// 007591a3  0f85df000000         jne 0x759288
// 007591a9  8b06                 mov eax, dword ptr [esi]
// 007591ab  3bf8                 cmp edi, eax
// 007591ad  7565                 jne 0x759214
// 007591af  8b4608               mov eax, dword ptr [esi + 8]
// 007591b2  80782400             cmp byte ptr [eax + 0x24], 0
// 007591b6  7512                 jne 0x7591ca
// 007591b8  885824               mov byte ptr [eax + 0x24], bl
// 007591bb  56                   push esi
// 007591bc  8bcd                 mov ecx, ebp
// 007591be  c6462400             mov byte ptr [esi + 0x24], 0
// 007591c2  e839e4ffff           call 0x757600
// 007591c7  8b4608               mov eax, dword ptr [esi + 8]
// 007591ca  80782500             cmp byte ptr [eax + 0x25], 0
// 007591ce  7574                 jne 0x759244
// 007591d0  8b08                 mov ecx, dword ptr [eax]
// 007591d2  385924               cmp byte ptr [ecx + 0x24], bl
// 007591d5  7508                 jne 0x7591df
// 007591d7  8b5008               mov edx, dword ptr [eax + 8]
// 007591da  385a24               cmp byte ptr [edx + 0x24], bl
// 007591dd  7461                 je 0x759240
// 007591df  8b4808               mov ecx, dword ptr [eax + 8]
// 007591e2  385924               cmp byte ptr [ecx + 0x24], bl
// 007591e5  7514                 jne 0x7591fb
// 007591e7  8b10                 mov edx, dword ptr [eax]
// 007591e9  885a24               mov byte ptr [edx + 0x24], bl
// 007591ec  50                   push eax
// 007591ed  8bcd                 mov ecx, ebp
// 007591ef  c6402400             mov byte ptr [eax + 0x24], 0
// 007591f3  e8c8d8dcff           call 0x526ac0
// 007591f8  8b4608               mov eax, dword ptr [esi + 8]
// 007591fb  8a4e24               mov cl, byte ptr [esi + 0x24]
// 007591fe  884824               mov byte ptr [eax + 0x24], cl
// 00759201  885e24               mov byte ptr [esi + 0x24], bl
// 00759204  8b5008               mov edx, dword ptr [eax + 8]
// 00759207  56                   push esi
// 00759208  8bcd                 mov ecx, ebp
// 0075920a  885a24               mov byte ptr [edx + 0x24], bl
// 0075920d  e8eee3ffff           call 0x757600
// 00759212  eb74                 jmp 0x759288
// 00759214  80782400             cmp byte ptr [eax + 0x24], 0
// 00759218  7511                 jne 0x75922b
// 0075921a  885824               mov byte ptr [eax + 0x24], bl
// 0075921d  56                   push esi
// 0075921e  8bcd                 mov ecx, ebp
// 00759220  c6462400             mov byte ptr [esi + 0x24], 0
// 00759224  e897d8dcff           call 0x526ac0
// 00759229  8b06                 mov eax, dword ptr [esi]
// 0075922b  80782500             cmp byte ptr [eax + 0x25], 0
// 0075922f  7513                 jne 0x759244
// 00759231  8b4808               mov ecx, dword ptr [eax + 8]
// 00759234  385924               cmp byte ptr [ecx + 0x24], bl
// 00759237  751e                 jne 0x759257
// 00759239  8b10                 mov edx, dword ptr [eax]
// 0075923b  385a24               cmp byte ptr [edx + 0x24], bl
// 0075923e  7517                 jne 0x759257
// 00759240  c6402400             mov byte ptr [eax + 0x24], 0
// 00759244  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00759247  8bfe                 mov edi, esi
// 00759249  8b7604               mov esi, dword ptr [esi + 4]
// 0075924c  3b7804               cmp edi, dword ptr [eax + 4]
// 0075924f  0f854bffffff         jne 0x7591a0
// 00759255  eb31                 jmp 0x759288
// 00759257  8b08                 mov ecx, dword ptr [eax]
// 00759259  385924               cmp byte ptr [ecx + 0x24], bl
// 0075925c  7514                 jne 0x759272
// 0075925e  8b5008               mov edx, dword ptr [eax + 8]
// 00759261  885a24               mov byte ptr [edx + 0x24], bl
// 00759264  50                   push eax
// 00759265  8bcd                 mov ecx, ebp
// 00759267  c6402400             mov byte ptr [eax + 0x24], 0
// 0075926b  e890e3ffff           call 0x757600
// 00759270  8b06                 mov eax, dword ptr [esi]
// 00759272  8a4e24               mov cl, byte ptr [esi + 0x24]
// 00759275  884824               mov byte ptr [eax + 0x24], cl
// 00759278  885e24               mov byte ptr [esi + 0x24], bl
// 0075927b  8b10                 mov edx, dword ptr [eax]
// 0075927d  56                   push esi
// 0075927e  8bcd                 mov ecx, ebp
// 00759280  885a24               mov byte ptr [edx + 0x24], bl
// 00759283  e838d8dcff           call 0x526ac0
// 00759288  885f24               mov byte ptr [edi + 0x24], bl
// 0075928b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0075928f  50                   push eax
// 00759290  e805e70400           call 0x7a799a
// 00759295  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00759298  83c404               add esp, 4
// 0075929b  5f                   pop edi
// 0075929c  5e                   pop esi
// 0075929d  5b                   pop ebx
// 0075929e  85c0                 test eax, eax
// 007592a0  7604                 jbe 0x7592a6
// 007592a2  48                   dec eax
// 007592a3  89451c               mov dword ptr [ebp + 0x1c], eax
// 007592a6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 007592aa  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 007592ae  8b5500               mov edx, dword ptr [ebp]
// 007592b1  894804               mov dword ptr [eax + 4], ecx
// 007592b4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007592b8  8910                 mov dword ptr [eax], edx
// 007592ba  5d                   pop ebp
// 007592bb  64890d00000000       mov dword ptr fs:[0], ecx
// 007592c2  83c454               add esp, 0x54
// 007592c5  c20c00               ret 0xc
// standard library set<pod24> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

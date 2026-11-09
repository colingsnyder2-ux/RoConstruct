// from server: 100% by auto
// roc 2010-06 004142c0  unit: CopyVerb  size: 755 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004142c0
//
// 004142c0  6aff                 push -1
// 004142c2  686b059a00           push 0x9a056b
// 004142c7  64a100000000         mov eax, dword ptr fs:[0]
// 004142cd  50                   push eax
// 004142ce  64892500000000       mov dword ptr fs:[0], esp
// 004142d5  83ec4c               sub esp, 0x4c
// 004142d8  8b442464             mov eax, dword ptr [esp + 0x64]
// 004142dc  80784500             cmp byte ptr [eax + 0x45], 0
// 004142e0  53                   push ebx
// 004142e1  8bd9                 mov ebx, ecx
// 004142e3  895c2404             mov dword ptr [esp + 4], ebx
// 004142e7  7459                 je 0x414342
// 004142e9  688c00a000           push 0xa0008c
// 004142ee  8d4c2410             lea ecx, [esp + 0x10]
// 004142f2  ff1510a49e00         call dword ptr [0x9ea410]
// 004142f8  8d4c2428             lea ecx, [esp + 0x28]
// 004142fc  c744245800000000     mov dword ptr [esp + 0x58], 0
// 00414304  ff1518a99e00         call dword ptr [0x9ea918]
// 0041430a  8d44240c             lea eax, [esp + 0xc]
// 0041430e  50                   push eax
// 0041430f  8d4c2438             lea ecx, [esp + 0x38]
// 00414313  c644245c01           mov byte ptr [esp + 0x5c], 1
// 00414318  c744242c2c00a000     mov dword ptr [esp + 0x2c], 0xa0002c
// 00414320  ff150ca49e00         call dword ptr [0x9ea40c]
// 00414326  68081bb000           push 0xb01b08
// 0041432b  8d4c242c             lea ecx, [esp + 0x2c]
// 0041432f  51                   push ecx
// 00414330  c644246000           mov byte ptr [esp + 0x60], 0
// 00414335  c74424304400a000     mov dword ptr [esp + 0x30], 0xa00044
// 0041433d  e870463900           call 0x7a89b2
// 00414342  55                   push ebp
// 00414343  56                   push esi
// 00414344  57                   push edi
// 00414345  8d4c2470             lea ecx, [esp + 0x70]
// 00414349  8be8                 mov ebp, eax
// 0041434b  e8f0f8ffff           call 0x413c40
// 00414350  8b4d00               mov ecx, dword ptr [ebp]
// 00414353  80794500             cmp byte ptr [ecx + 0x45], 0
// 00414357  7405                 je 0x41435e
// 00414359  8b7d08               mov edi, dword ptr [ebp + 8]
// 0041435c  eb1b                 jmp 0x414379
// 0041435e  8b5508               mov edx, dword ptr [ebp + 8]
// 00414361  807a4500             cmp byte ptr [edx + 0x45], 0
// 00414365  7404                 je 0x41436b
// 00414367  8bf9                 mov edi, ecx
// 00414369  eb0e                 jmp 0x414379
// 0041436b  8b442474             mov eax, dword ptr [esp + 0x74]
// 0041436f  8b7808               mov edi, dword ptr [eax + 8]
// 00414372  8d5008               lea edx, [eax + 8]
// 00414375  3bc5                 cmp eax, ebp
// 00414377  7567                 jne 0x4143e0
// 00414379  807f4500             cmp byte ptr [edi + 0x45], 0
// 0041437d  8b7504               mov esi, dword ptr [ebp + 4]
// 00414380  7503                 jne 0x414385
// 00414382  897704               mov dword ptr [edi + 4], esi
// 00414385  8b4318               mov eax, dword ptr [ebx + 0x18]
// 00414388  396804               cmp dword ptr [eax + 4], ebp
// 0041438b  7505                 jne 0x414392
// 0041438d  897804               mov dword ptr [eax + 4], edi
// 00414390  eb0b                 jmp 0x41439d
// 00414392  392e                 cmp dword ptr [esi], ebp
// 00414394  7504                 jne 0x41439a
// 00414396  893e                 mov dword ptr [esi], edi
// 00414398  eb03                 jmp 0x41439d
// 0041439a  897e08               mov dword ptr [esi + 8], edi
// 0041439d  8b5b18               mov ebx, dword ptr [ebx + 0x18]
// 004143a0  392b                 cmp dword ptr [ebx], ebp
// 004143a2  7515                 jne 0x4143b9
// 004143a4  807f4500             cmp byte ptr [edi + 0x45], 0
// 004143a8  7404                 je 0x4143ae
// 004143aa  8bc6                 mov eax, esi
// 004143ac  eb09                 jmp 0x4143b7
// 004143ae  57                   push edi
// 004143af  e80cf5ffff           call 0x4138c0
// 004143b4  83c404               add esp, 4
// 004143b7  8903                 mov dword ptr [ebx], eax
// 004143b9  8b442410             mov eax, dword ptr [esp + 0x10]
// 004143bd  8b5818               mov ebx, dword ptr [eax + 0x18]
// 004143c0  396b08               cmp dword ptr [ebx + 8], ebp
// 004143c3  7578                 jne 0x41443d
// 004143c5  807f4500             cmp byte ptr [edi + 0x45], 0
// 004143c9  7407                 je 0x4143d2
// 004143cb  8bc6                 mov eax, esi
// 004143cd  894308               mov dword ptr [ebx + 8], eax
// 004143d0  eb6b                 jmp 0x41443d
// 004143d2  57                   push edi
// 004143d3  e8c8f4ffff           call 0x4138a0
// 004143d8  83c404               add esp, 4
// 004143db  894308               mov dword ptr [ebx + 8], eax
// 004143de  eb5d                 jmp 0x41443d
// 004143e0  894104               mov dword ptr [ecx + 4], eax
// 004143e3  8b4d00               mov ecx, dword ptr [ebp]
// 004143e6  8908                 mov dword ptr [eax], ecx
// 004143e8  3b4508               cmp eax, dword ptr [ebp + 8]
// 004143eb  7504                 jne 0x4143f1
// 004143ed  8bf0                 mov esi, eax
// 004143ef  eb19                 jmp 0x41440a
// 004143f1  807f4500             cmp byte ptr [edi + 0x45], 0
// 004143f5  8b7004               mov esi, dword ptr [eax + 4]
// 004143f8  7503                 jne 0x4143fd
// 004143fa  897704               mov dword ptr [edi + 4], esi
// 004143fd  893e                 mov dword ptr [esi], edi
// 004143ff  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00414402  890a                 mov dword ptr [edx], ecx
// 00414404  8b5508               mov edx, dword ptr [ebp + 8]
// 00414407  894204               mov dword ptr [edx + 4], eax
// 0041440a  8b4b18               mov ecx, dword ptr [ebx + 0x18]
// 0041440d  396904               cmp dword ptr [ecx + 4], ebp
// 00414410  7505                 jne 0x414417
// 00414412  894104               mov dword ptr [ecx + 4], eax
// 00414415  eb0e                 jmp 0x414425
// 00414417  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0041441a  3929                 cmp dword ptr [ecx], ebp
// 0041441c  7504                 jne 0x414422
// 0041441e  8901                 mov dword ptr [ecx], eax
// 00414420  eb03                 jmp 0x414425
// 00414422  894108               mov dword ptr [ecx + 8], eax
// 00414425  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00414428  894804               mov dword ptr [eax + 4], ecx
// 0041442b  8d4d44               lea ecx, [ebp + 0x44]
// 0041442e  83c044               add eax, 0x44
// 00414431  3bc1                 cmp eax, ecx
// 00414433  7408                 je 0x41443d
// 00414435  8a19                 mov bl, byte ptr [ecx]
// 00414437  8a10                 mov dl, byte ptr [eax]
// 00414439  8818                 mov byte ptr [eax], bl
// 0041443b  8811                 mov byte ptr [ecx], dl
// 0041443d  b301                 mov bl, 1
// 0041443f  385d44               cmp byte ptr [ebp + 0x44], bl
// 00414442  0f8507010000         jne 0x41454f
// 00414448  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041444c  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0041444f  3b7a04               cmp edi, dword ptr [edx + 4]
// 00414452  0f84f4000000         je 0x41454c
// 00414458  eb06                 jmp 0x414460
// 0041445a  8d9b00000000         lea ebx, [ebx]
// 00414460  385f44               cmp byte ptr [edi + 0x44], bl
// 00414463  0f85e3000000         jne 0x41454c
// 00414469  8b06                 mov eax, dword ptr [esi]
// 0041446b  3bf8                 cmp edi, eax
// 0041446d  7567                 jne 0x4144d6
// 0041446f  8b4608               mov eax, dword ptr [esi + 8]
// 00414472  80784400             cmp byte ptr [eax + 0x44], 0
// 00414476  7514                 jne 0x41448c
// 00414478  885844               mov byte ptr [eax + 0x44], bl
// 0041447b  56                   push esi
// 0041447c  c6464400             mov byte ptr [esi + 0x44], 0
// 00414480  e8cbf3ffff           call 0x413850
// 00414485  8b4608               mov eax, dword ptr [esi + 8]
// 00414488  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041448c  80784500             cmp byte ptr [eax + 0x45], 0
// 00414490  7576                 jne 0x414508
// 00414492  8b10                 mov edx, dword ptr [eax]
// 00414494  385a44               cmp byte ptr [edx + 0x44], bl
// 00414497  7508                 jne 0x4144a1
// 00414499  8b5008               mov edx, dword ptr [eax + 8]
// 0041449c  385a44               cmp byte ptr [edx + 0x44], bl
// 0041449f  7463                 je 0x414504
// 004144a1  8b5008               mov edx, dword ptr [eax + 8]
// 004144a4  385a44               cmp byte ptr [edx + 0x44], bl
// 004144a7  7516                 jne 0x4144bf
// 004144a9  8b10                 mov edx, dword ptr [eax]
// 004144ab  885a44               mov byte ptr [edx + 0x44], bl
// 004144ae  50                   push eax
// 004144af  c6404400             mov byte ptr [eax + 0x44], 0
// 004144b3  e828f4ffff           call 0x4138e0
// 004144b8  8b4608               mov eax, dword ptr [esi + 8]
// 004144bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004144bf  8a5644               mov dl, byte ptr [esi + 0x44]
// 004144c2  885044               mov byte ptr [eax + 0x44], dl
// 004144c5  885e44               mov byte ptr [esi + 0x44], bl
// 004144c8  8b4008               mov eax, dword ptr [eax + 8]
// 004144cb  56                   push esi
// 004144cc  885844               mov byte ptr [eax + 0x44], bl
// 004144cf  e87cf3ffff           call 0x413850
// 004144d4  eb76                 jmp 0x41454c
// 004144d6  80784400             cmp byte ptr [eax + 0x44], 0
// 004144da  7513                 jne 0x4144ef
// 004144dc  885844               mov byte ptr [eax + 0x44], bl
// 004144df  56                   push esi
// 004144e0  c6464400             mov byte ptr [esi + 0x44], 0
// 004144e4  e8f7f3ffff           call 0x4138e0
// 004144e9  8b06                 mov eax, dword ptr [esi]
// 004144eb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004144ef  80784500             cmp byte ptr [eax + 0x45], 0
// 004144f3  7513                 jne 0x414508
// 004144f5  8b5008               mov edx, dword ptr [eax + 8]
// 004144f8  385a44               cmp byte ptr [edx + 0x44], bl
// 004144fb  751e                 jne 0x41451b
// 004144fd  8b10                 mov edx, dword ptr [eax]
// 004144ff  385a44               cmp byte ptr [edx + 0x44], bl
// 00414502  7517                 jne 0x41451b
// 00414504  c6404400             mov byte ptr [eax + 0x44], 0
// 00414508  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0041450b  8bfe                 mov edi, esi
// 0041450d  8b7604               mov esi, dword ptr [esi + 4]
// 00414510  3b7804               cmp edi, dword ptr [eax + 4]
// 00414513  0f8547ffffff         jne 0x414460
// 00414519  eb31                 jmp 0x41454c
// 0041451b  8b10                 mov edx, dword ptr [eax]
// 0041451d  385a44               cmp byte ptr [edx + 0x44], bl
// 00414520  7516                 jne 0x414538
// 00414522  8b5008               mov edx, dword ptr [eax + 8]
// 00414525  885a44               mov byte ptr [edx + 0x44], bl
// 00414528  50                   push eax
// 00414529  c6404400             mov byte ptr [eax + 0x44], 0
// 0041452d  e81ef3ffff           call 0x413850
// 00414532  8b06                 mov eax, dword ptr [esi]
// 00414534  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00414538  8a5644               mov dl, byte ptr [esi + 0x44]
// 0041453b  885044               mov byte ptr [eax + 0x44], dl
// 0041453e  885e44               mov byte ptr [esi + 0x44], bl
// 00414541  8b00                 mov eax, dword ptr [eax]
// 00414543  56                   push esi
// 00414544  885844               mov byte ptr [eax + 0x44], bl
// 00414547  e894f3ffff           call 0x4138e0
// 0041454c  885f44               mov byte ptr [edi + 0x44], bl
// 0041454f  8d750c               lea esi, [ebp + 0xc]
// 00414552  89742414             mov dword ptr [esp + 0x14], esi
// 00414556  8d4e1c               lea ecx, [esi + 0x1c]
// 00414559  c744246402000000     mov dword ptr [esp + 0x64], 2
// 00414561  ff1500a49e00         call dword ptr [0x9ea400]
// 00414567  8bce                 mov ecx, esi
// 00414569  c7442464ffffffff     mov dword ptr [esp + 0x64], 0xffffffff
// 00414571  ff1500a49e00         call dword ptr [0x9ea400]
// 00414577  55                   push ebp
// 00414578  e81d343900           call 0x7a799a
// 0041457d  8b542414             mov edx, dword ptr [esp + 0x14]
// 00414581  8b421c               mov eax, dword ptr [edx + 0x1c]
// 00414584  83c404               add esp, 4
// 00414587  5f                   pop edi
// 00414588  5e                   pop esi
// 00414589  5d                   pop ebp
// 0041458a  85c0                 test eax, eax
// 0041458c  7604                 jbe 0x414592
// 0041458e  48                   dec eax
// 0041458f  89421c               mov dword ptr [edx + 0x1c], eax
// 00414592  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 00414596  8b442460             mov eax, dword ptr [esp + 0x60]
// 0041459a  8b12                 mov edx, dword ptr [edx]
// 0041459c  894804               mov dword ptr [eax + 4], ecx
// 0041459f  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 004145a3  8910                 mov dword ptr [eax], edx
// 004145a5  5b                   pop ebx
// 004145a6  64890d00000000       mov dword ptr fs:[0], ecx
// 004145ad  83c458               add esp, 0x58
// 004145b0  c20c00               ret 0xc
// standard library map_str<string> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

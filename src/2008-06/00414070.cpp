// from server: 100% by auto
// roc 2008-06 00414070  unit: CopyVerb  size: 755 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00414070
//
// 00414070  6aff                 push -1
// 00414072  68ebb87d00           push 0x7db8eb
// 00414077  64a100000000         mov eax, dword ptr fs:[0]
// 0041407d  50                   push eax
// 0041407e  64892500000000       mov dword ptr fs:[0], esp
// 00414085  83ec4c               sub esp, 0x4c
// 00414088  8b442464             mov eax, dword ptr [esp + 0x64]
// 0041408c  80784500             cmp byte ptr [eax + 0x45], 0
// 00414090  53                   push ebx
// 00414091  8bd9                 mov ebx, ecx
// 00414093  895c2404             mov dword ptr [esp + 4], ebx
// 00414097  7459                 je 0x4140f2
// 00414099  6870b28000           push 0x80b270
// 0041409e  8d4c2410             lea ecx, [esp + 0x10]
// 004140a2  ff1558248000         call dword ptr [0x802458]
// 004140a8  8d4c2428             lea ecx, [esp + 0x28]
// 004140ac  c744245800000000     mov dword ptr [esp + 0x58], 0
// 004140b4  ff1598288000         call dword ptr [0x802898]
// 004140ba  8d44240c             lea eax, [esp + 0xc]
// 004140be  50                   push eax
// 004140bf  8d4c2438             lea ecx, [esp + 0x38]
// 004140c3  c644245c01           mov byte ptr [esp + 0x5c], 1
// 004140c8  c744242c10b18000     mov dword ptr [esp + 0x2c], 0x80b110
// 004140d0  ff155c248000         call dword ptr [0x80245c]
// 004140d6  683c0c8d00           push 0x8d0c3c
// 004140db  8d4c242c             lea ecx, [esp + 0x2c]
// 004140df  51                   push ecx
// 004140e0  c644246000           mov byte ptr [esp + 0x60], 0
// 004140e5  c744243028b18000     mov dword ptr [esp + 0x30], 0x80b128
// 004140ed  e89ad42800           call 0x6a158c
// 004140f2  55                   push ebp
// 004140f3  56                   push esi
// 004140f4  57                   push edi
// 004140f5  8d4c2470             lea ecx, [esp + 0x70]
// 004140f9  8be8                 mov ebp, eax
// 004140fb  e8b0f8ffff           call 0x4139b0
// 00414100  8b4d00               mov ecx, dword ptr [ebp]
// 00414103  80794500             cmp byte ptr [ecx + 0x45], 0
// 00414107  7405                 je 0x41410e
// 00414109  8b7d08               mov edi, dword ptr [ebp + 8]
// 0041410c  eb1b                 jmp 0x414129
// 0041410e  8b5508               mov edx, dword ptr [ebp + 8]
// 00414111  807a4500             cmp byte ptr [edx + 0x45], 0
// 00414115  7404                 je 0x41411b
// 00414117  8bf9                 mov edi, ecx
// 00414119  eb0e                 jmp 0x414129
// 0041411b  8b442474             mov eax, dword ptr [esp + 0x74]
// 0041411f  8b7808               mov edi, dword ptr [eax + 8]
// 00414122  8d5008               lea edx, [eax + 8]
// 00414125  3bc5                 cmp eax, ebp
// 00414127  7567                 jne 0x414190
// 00414129  807f4500             cmp byte ptr [edi + 0x45], 0
// 0041412d  8b7504               mov esi, dword ptr [ebp + 4]
// 00414130  7503                 jne 0x414135
// 00414132  897704               mov dword ptr [edi + 4], esi
// 00414135  8b4318               mov eax, dword ptr [ebx + 0x18]
// 00414138  396804               cmp dword ptr [eax + 4], ebp
// 0041413b  7505                 jne 0x414142
// 0041413d  897804               mov dword ptr [eax + 4], edi
// 00414140  eb0b                 jmp 0x41414d
// 00414142  392e                 cmp dword ptr [esi], ebp
// 00414144  7504                 jne 0x41414a
// 00414146  893e                 mov dword ptr [esi], edi
// 00414148  eb03                 jmp 0x41414d
// 0041414a  897e08               mov dword ptr [esi + 8], edi
// 0041414d  8b5b18               mov ebx, dword ptr [ebx + 0x18]
// 00414150  392b                 cmp dword ptr [ebx], ebp
// 00414152  7515                 jne 0x414169
// 00414154  807f4500             cmp byte ptr [edi + 0x45], 0
// 00414158  7404                 je 0x41415e
// 0041415a  8bc6                 mov eax, esi
// 0041415c  eb09                 jmp 0x414167
// 0041415e  57                   push edi
// 0041415f  e86cf4ffff           call 0x4135d0
// 00414164  83c404               add esp, 4
// 00414167  8903                 mov dword ptr [ebx], eax
// 00414169  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041416d  8b5818               mov ebx, dword ptr [eax + 0x18]
// 00414170  396b08               cmp dword ptr [ebx + 8], ebp
// 00414173  7578                 jne 0x4141ed
// 00414175  807f4500             cmp byte ptr [edi + 0x45], 0
// 00414179  7407                 je 0x414182
// 0041417b  8bc6                 mov eax, esi
// 0041417d  894308               mov dword ptr [ebx + 8], eax
// 00414180  eb6b                 jmp 0x4141ed
// 00414182  57                   push edi
// 00414183  e828f4ffff           call 0x4135b0
// 00414188  83c404               add esp, 4
// 0041418b  894308               mov dword ptr [ebx + 8], eax
// 0041418e  eb5d                 jmp 0x4141ed
// 00414190  894104               mov dword ptr [ecx + 4], eax
// 00414193  8b4d00               mov ecx, dword ptr [ebp]
// 00414196  8908                 mov dword ptr [eax], ecx
// 00414198  3b4508               cmp eax, dword ptr [ebp + 8]
// 0041419b  7504                 jne 0x4141a1
// 0041419d  8bf0                 mov esi, eax
// 0041419f  eb19                 jmp 0x4141ba
// 004141a1  807f4500             cmp byte ptr [edi + 0x45], 0
// 004141a5  8b7004               mov esi, dword ptr [eax + 4]
// 004141a8  7503                 jne 0x4141ad
// 004141aa  897704               mov dword ptr [edi + 4], esi
// 004141ad  893e                 mov dword ptr [esi], edi
// 004141af  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004141b2  890a                 mov dword ptr [edx], ecx
// 004141b4  8b5508               mov edx, dword ptr [ebp + 8]
// 004141b7  894204               mov dword ptr [edx + 4], eax
// 004141ba  8b4b18               mov ecx, dword ptr [ebx + 0x18]
// 004141bd  396904               cmp dword ptr [ecx + 4], ebp
// 004141c0  7505                 jne 0x4141c7
// 004141c2  894104               mov dword ptr [ecx + 4], eax
// 004141c5  eb0e                 jmp 0x4141d5
// 004141c7  8b4d04               mov ecx, dword ptr [ebp + 4]
// 004141ca  3929                 cmp dword ptr [ecx], ebp
// 004141cc  7504                 jne 0x4141d2
// 004141ce  8901                 mov dword ptr [ecx], eax
// 004141d0  eb03                 jmp 0x4141d5
// 004141d2  894108               mov dword ptr [ecx + 8], eax
// 004141d5  8b4d04               mov ecx, dword ptr [ebp + 4]
// 004141d8  894804               mov dword ptr [eax + 4], ecx
// 004141db  8d4d44               lea ecx, [ebp + 0x44]
// 004141de  83c044               add eax, 0x44
// 004141e1  3bc1                 cmp eax, ecx
// 004141e3  7408                 je 0x4141ed
// 004141e5  8a19                 mov bl, byte ptr [ecx]
// 004141e7  8a10                 mov dl, byte ptr [eax]
// 004141e9  8818                 mov byte ptr [eax], bl
// 004141eb  8811                 mov byte ptr [ecx], dl
// 004141ed  b301                 mov bl, 1
// 004141ef  385d44               cmp byte ptr [ebp + 0x44], bl
// 004141f2  0f8507010000         jne 0x4142ff
// 004141f8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004141fc  8b5118               mov edx, dword ptr [ecx + 0x18]
// 004141ff  3b7a04               cmp edi, dword ptr [edx + 4]
// 00414202  0f84f4000000         je 0x4142fc
// 00414208  eb06                 jmp 0x414210
// 0041420a  8d9b00000000         lea ebx, [ebx]
// 00414210  385f44               cmp byte ptr [edi + 0x44], bl
// 00414213  0f85e3000000         jne 0x4142fc
// 00414219  8b06                 mov eax, dword ptr [esi]
// 0041421b  3bf8                 cmp edi, eax
// 0041421d  7567                 jne 0x414286
// 0041421f  8b4608               mov eax, dword ptr [esi + 8]
// 00414222  80784400             cmp byte ptr [eax + 0x44], 0
// 00414226  7514                 jne 0x41423c
// 00414228  885844               mov byte ptr [eax + 0x44], bl
// 0041422b  56                   push esi
// 0041422c  c6464400             mov byte ptr [esi + 0x44], 0
// 00414230  e82bf3ffff           call 0x413560
// 00414235  8b4608               mov eax, dword ptr [esi + 8]
// 00414238  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041423c  80784500             cmp byte ptr [eax + 0x45], 0
// 00414240  7576                 jne 0x4142b8
// 00414242  8b10                 mov edx, dword ptr [eax]
// 00414244  385a44               cmp byte ptr [edx + 0x44], bl
// 00414247  7508                 jne 0x414251
// 00414249  8b5008               mov edx, dword ptr [eax + 8]
// 0041424c  385a44               cmp byte ptr [edx + 0x44], bl
// 0041424f  7463                 je 0x4142b4
// 00414251  8b5008               mov edx, dword ptr [eax + 8]
// 00414254  385a44               cmp byte ptr [edx + 0x44], bl
// 00414257  7516                 jne 0x41426f
// 00414259  8b10                 mov edx, dword ptr [eax]
// 0041425b  885a44               mov byte ptr [edx + 0x44], bl
// 0041425e  50                   push eax
// 0041425f  c6404400             mov byte ptr [eax + 0x44], 0
// 00414263  e888f3ffff           call 0x4135f0
// 00414268  8b4608               mov eax, dword ptr [esi + 8]
// 0041426b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041426f  8a5644               mov dl, byte ptr [esi + 0x44]
// 00414272  885044               mov byte ptr [eax + 0x44], dl
// 00414275  885e44               mov byte ptr [esi + 0x44], bl
// 00414278  8b4008               mov eax, dword ptr [eax + 8]
// 0041427b  56                   push esi
// 0041427c  885844               mov byte ptr [eax + 0x44], bl
// 0041427f  e8dcf2ffff           call 0x413560
// 00414284  eb76                 jmp 0x4142fc
// 00414286  80784400             cmp byte ptr [eax + 0x44], 0
// 0041428a  7513                 jne 0x41429f
// 0041428c  885844               mov byte ptr [eax + 0x44], bl
// 0041428f  56                   push esi
// 00414290  c6464400             mov byte ptr [esi + 0x44], 0
// 00414294  e857f3ffff           call 0x4135f0
// 00414299  8b06                 mov eax, dword ptr [esi]
// 0041429b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041429f  80784500             cmp byte ptr [eax + 0x45], 0
// 004142a3  7513                 jne 0x4142b8
// 004142a5  8b5008               mov edx, dword ptr [eax + 8]
// 004142a8  385a44               cmp byte ptr [edx + 0x44], bl
// 004142ab  751e                 jne 0x4142cb
// 004142ad  8b10                 mov edx, dword ptr [eax]
// 004142af  385a44               cmp byte ptr [edx + 0x44], bl
// 004142b2  7517                 jne 0x4142cb
// 004142b4  c6404400             mov byte ptr [eax + 0x44], 0
// 004142b8  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004142bb  8bfe                 mov edi, esi
// 004142bd  8b7604               mov esi, dword ptr [esi + 4]
// 004142c0  3b7804               cmp edi, dword ptr [eax + 4]
// 004142c3  0f8547ffffff         jne 0x414210
// 004142c9  eb31                 jmp 0x4142fc
// 004142cb  8b10                 mov edx, dword ptr [eax]
// 004142cd  385a44               cmp byte ptr [edx + 0x44], bl
// 004142d0  7516                 jne 0x4142e8
// 004142d2  8b5008               mov edx, dword ptr [eax + 8]
// 004142d5  885a44               mov byte ptr [edx + 0x44], bl
// 004142d8  50                   push eax
// 004142d9  c6404400             mov byte ptr [eax + 0x44], 0
// 004142dd  e87ef2ffff           call 0x413560
// 004142e2  8b06                 mov eax, dword ptr [esi]
// 004142e4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004142e8  8a5644               mov dl, byte ptr [esi + 0x44]
// 004142eb  885044               mov byte ptr [eax + 0x44], dl
// 004142ee  885e44               mov byte ptr [esi + 0x44], bl
// 004142f1  8b00                 mov eax, dword ptr [eax]
// 004142f3  56                   push esi
// 004142f4  885844               mov byte ptr [eax + 0x44], bl
// 004142f7  e8f4f2ffff           call 0x4135f0
// 004142fc  885f44               mov byte ptr [edi + 0x44], bl
// 004142ff  8d750c               lea esi, [ebp + 0xc]
// 00414302  89742414             mov dword ptr [esp + 0x14], esi
// 00414306  8d4e1c               lea ecx, [esi + 0x1c]
// 00414309  c744246402000000     mov dword ptr [esp + 0x64], 2
// 00414311  ff1568248000         call dword ptr [0x802468]
// 00414317  8bce                 mov ecx, esi
// 00414319  c7442464ffffffff     mov dword ptr [esp + 0x64], 0xffffffff
// 00414321  ff1568248000         call dword ptr [0x802468]
// 00414327  55                   push ebp
// 00414328  e84dc32800           call 0x6a067a
// 0041432d  8b542414             mov edx, dword ptr [esp + 0x14]
// 00414331  8b421c               mov eax, dword ptr [edx + 0x1c]
// 00414334  83c404               add esp, 4
// 00414337  5f                   pop edi
// 00414338  5e                   pop esi
// 00414339  5d                   pop ebp
// 0041433a  85c0                 test eax, eax
// 0041433c  7604                 jbe 0x414342
// 0041433e  48                   dec eax
// 0041433f  89421c               mov dword ptr [edx + 0x1c], eax
// 00414342  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 00414346  8b442460             mov eax, dword ptr [esp + 0x60]
// 0041434a  8b12                 mov edx, dword ptr [edx]
// 0041434c  894804               mov dword ptr [eax + 4], ecx
// 0041434f  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00414353  8910                 mov dword ptr [eax], edx
// 00414355  5b                   pop ebx
// 00414356  64890d00000000       mov dword ptr fs:[0], ecx
// 0041435d  83c458               add esp, 0x58
// 00414360  c20c00               ret 0xc
// standard library map_str<string> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

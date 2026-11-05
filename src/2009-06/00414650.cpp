// from server: 100% by auto
// roc 2009-06 00414650  unit: CopyVerb  size: 755 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00414650
//
// 00414650  6aff                 push -1
// 00414652  683b5d8500           push 0x855d3b
// 00414657  64a100000000         mov eax, dword ptr fs:[0]
// 0041465d  50                   push eax
// 0041465e  64892500000000       mov dword ptr fs:[0], esp
// 00414665  83ec4c               sub esp, 0x4c
// 00414668  8b442464             mov eax, dword ptr [esp + 0x64]
// 0041466c  80784500             cmp byte ptr [eax + 0x45], 0
// 00414670  53                   push ebx
// 00414671  8bd9                 mov ebx, ecx
// 00414673  895c2404             mov dword ptr [esp + 4], ebx
// 00414677  7459                 je 0x4146d2
// 00414679  68a4c98a00           push 0x8ac9a4
// 0041467e  8d4c2410             lea ecx, [esp + 0x10]
// 00414682  ff15b4e48900         call dword ptr [0x89e4b4]
// 00414688  8d4c2428             lea ecx, [esp + 0x28]
// 0041468c  c744245800000000     mov dword ptr [esp + 0x58], 0
// 00414694  ff15b8e98900         call dword ptr [0x89e9b8]
// 0041469a  8d44240c             lea eax, [esp + 0xc]
// 0041469e  50                   push eax
// 0041469f  8d4c2438             lea ecx, [esp + 0x38]
// 004146a3  c644245c01           mov byte ptr [esp + 0x5c], 1
// 004146a8  c744242c44c98a00     mov dword ptr [esp + 0x2c], 0x8ac944
// 004146b0  ff15b8e48900         call dword ptr [0x89e4b8]
// 004146b6  68dc919700           push 0x9791dc
// 004146bb  8d4c242c             lea ecx, [esp + 0x2c]
// 004146bf  51                   push ecx
// 004146c0  c644246000           mov byte ptr [esp + 0x60], 0
// 004146c5  c74424305cc98a00     mov dword ptr [esp + 0x30], 0x8ac95c
// 004146cd  e878533000           call 0x719a4a
// 004146d2  55                   push ebp
// 004146d3  56                   push esi
// 004146d4  57                   push edi
// 004146d5  8d4c2470             lea ecx, [esp + 0x70]
// 004146d9  8be8                 mov ebp, eax
// 004146db  e8d0f8ffff           call 0x413fb0
// 004146e0  8b4d00               mov ecx, dword ptr [ebp]
// 004146e3  80794500             cmp byte ptr [ecx + 0x45], 0
// 004146e7  7405                 je 0x4146ee
// 004146e9  8b7d08               mov edi, dword ptr [ebp + 8]
// 004146ec  eb1b                 jmp 0x414709
// 004146ee  8b5508               mov edx, dword ptr [ebp + 8]
// 004146f1  807a4500             cmp byte ptr [edx + 0x45], 0
// 004146f5  7404                 je 0x4146fb
// 004146f7  8bf9                 mov edi, ecx
// 004146f9  eb0e                 jmp 0x414709
// 004146fb  8b442474             mov eax, dword ptr [esp + 0x74]
// 004146ff  8b7808               mov edi, dword ptr [eax + 8]
// 00414702  8d5008               lea edx, [eax + 8]
// 00414705  3bc5                 cmp eax, ebp
// 00414707  7567                 jne 0x414770
// 00414709  807f4500             cmp byte ptr [edi + 0x45], 0
// 0041470d  8b7504               mov esi, dword ptr [ebp + 4]
// 00414710  7503                 jne 0x414715
// 00414712  897704               mov dword ptr [edi + 4], esi
// 00414715  8b4318               mov eax, dword ptr [ebx + 0x18]
// 00414718  396804               cmp dword ptr [eax + 4], ebp
// 0041471b  7505                 jne 0x414722
// 0041471d  897804               mov dword ptr [eax + 4], edi
// 00414720  eb0b                 jmp 0x41472d
// 00414722  392e                 cmp dword ptr [esi], ebp
// 00414724  7504                 jne 0x41472a
// 00414726  893e                 mov dword ptr [esi], edi
// 00414728  eb03                 jmp 0x41472d
// 0041472a  897e08               mov dword ptr [esi + 8], edi
// 0041472d  8b5b18               mov ebx, dword ptr [ebx + 0x18]
// 00414730  392b                 cmp dword ptr [ebx], ebp
// 00414732  7515                 jne 0x414749
// 00414734  807f4500             cmp byte ptr [edi + 0x45], 0
// 00414738  7404                 je 0x41473e
// 0041473a  8bc6                 mov eax, esi
// 0041473c  eb09                 jmp 0x414747
// 0041473e  57                   push edi
// 0041473f  e83cf4ffff           call 0x413b80
// 00414744  83c404               add esp, 4
// 00414747  8903                 mov dword ptr [ebx], eax
// 00414749  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041474d  8b5818               mov ebx, dword ptr [eax + 0x18]
// 00414750  396b08               cmp dword ptr [ebx + 8], ebp
// 00414753  7578                 jne 0x4147cd
// 00414755  807f4500             cmp byte ptr [edi + 0x45], 0
// 00414759  7407                 je 0x414762
// 0041475b  8bc6                 mov eax, esi
// 0041475d  894308               mov dword ptr [ebx + 8], eax
// 00414760  eb6b                 jmp 0x4147cd
// 00414762  57                   push edi
// 00414763  e8f8f3ffff           call 0x413b60
// 00414768  83c404               add esp, 4
// 0041476b  894308               mov dword ptr [ebx + 8], eax
// 0041476e  eb5d                 jmp 0x4147cd
// 00414770  894104               mov dword ptr [ecx + 4], eax
// 00414773  8b4d00               mov ecx, dword ptr [ebp]
// 00414776  8908                 mov dword ptr [eax], ecx
// 00414778  3b4508               cmp eax, dword ptr [ebp + 8]
// 0041477b  7504                 jne 0x414781
// 0041477d  8bf0                 mov esi, eax
// 0041477f  eb19                 jmp 0x41479a
// 00414781  807f4500             cmp byte ptr [edi + 0x45], 0
// 00414785  8b7004               mov esi, dword ptr [eax + 4]
// 00414788  7503                 jne 0x41478d
// 0041478a  897704               mov dword ptr [edi + 4], esi
// 0041478d  893e                 mov dword ptr [esi], edi
// 0041478f  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00414792  890a                 mov dword ptr [edx], ecx
// 00414794  8b5508               mov edx, dword ptr [ebp + 8]
// 00414797  894204               mov dword ptr [edx + 4], eax
// 0041479a  8b4b18               mov ecx, dword ptr [ebx + 0x18]
// 0041479d  396904               cmp dword ptr [ecx + 4], ebp
// 004147a0  7505                 jne 0x4147a7
// 004147a2  894104               mov dword ptr [ecx + 4], eax
// 004147a5  eb0e                 jmp 0x4147b5
// 004147a7  8b4d04               mov ecx, dword ptr [ebp + 4]
// 004147aa  3929                 cmp dword ptr [ecx], ebp
// 004147ac  7504                 jne 0x4147b2
// 004147ae  8901                 mov dword ptr [ecx], eax
// 004147b0  eb03                 jmp 0x4147b5
// 004147b2  894108               mov dword ptr [ecx + 8], eax
// 004147b5  8b4d04               mov ecx, dword ptr [ebp + 4]
// 004147b8  894804               mov dword ptr [eax + 4], ecx
// 004147bb  8d4d44               lea ecx, [ebp + 0x44]
// 004147be  83c044               add eax, 0x44
// 004147c1  3bc1                 cmp eax, ecx
// 004147c3  7408                 je 0x4147cd
// 004147c5  8a19                 mov bl, byte ptr [ecx]
// 004147c7  8a10                 mov dl, byte ptr [eax]
// 004147c9  8818                 mov byte ptr [eax], bl
// 004147cb  8811                 mov byte ptr [ecx], dl
// 004147cd  b301                 mov bl, 1
// 004147cf  385d44               cmp byte ptr [ebp + 0x44], bl
// 004147d2  0f8507010000         jne 0x4148df
// 004147d8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004147dc  8b5118               mov edx, dword ptr [ecx + 0x18]
// 004147df  3b7a04               cmp edi, dword ptr [edx + 4]
// 004147e2  0f84f4000000         je 0x4148dc
// 004147e8  eb06                 jmp 0x4147f0
// 004147ea  8d9b00000000         lea ebx, [ebx]
// 004147f0  385f44               cmp byte ptr [edi + 0x44], bl
// 004147f3  0f85e3000000         jne 0x4148dc
// 004147f9  8b06                 mov eax, dword ptr [esi]
// 004147fb  3bf8                 cmp edi, eax
// 004147fd  7567                 jne 0x414866
// 004147ff  8b4608               mov eax, dword ptr [esi + 8]
// 00414802  80784400             cmp byte ptr [eax + 0x44], 0
// 00414806  7514                 jne 0x41481c
// 00414808  885844               mov byte ptr [eax + 0x44], bl
// 0041480b  56                   push esi
// 0041480c  c6464400             mov byte ptr [esi + 0x44], 0
// 00414810  e8fbf2ffff           call 0x413b10
// 00414815  8b4608               mov eax, dword ptr [esi + 8]
// 00414818  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041481c  80784500             cmp byte ptr [eax + 0x45], 0
// 00414820  7576                 jne 0x414898
// 00414822  8b10                 mov edx, dword ptr [eax]
// 00414824  385a44               cmp byte ptr [edx + 0x44], bl
// 00414827  7508                 jne 0x414831
// 00414829  8b5008               mov edx, dword ptr [eax + 8]
// 0041482c  385a44               cmp byte ptr [edx + 0x44], bl
// 0041482f  7463                 je 0x414894
// 00414831  8b5008               mov edx, dword ptr [eax + 8]
// 00414834  385a44               cmp byte ptr [edx + 0x44], bl
// 00414837  7516                 jne 0x41484f
// 00414839  8b10                 mov edx, dword ptr [eax]
// 0041483b  885a44               mov byte ptr [edx + 0x44], bl
// 0041483e  50                   push eax
// 0041483f  c6404400             mov byte ptr [eax + 0x44], 0
// 00414843  e858f3ffff           call 0x413ba0
// 00414848  8b4608               mov eax, dword ptr [esi + 8]
// 0041484b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041484f  8a5644               mov dl, byte ptr [esi + 0x44]
// 00414852  885044               mov byte ptr [eax + 0x44], dl
// 00414855  885e44               mov byte ptr [esi + 0x44], bl
// 00414858  8b4008               mov eax, dword ptr [eax + 8]
// 0041485b  56                   push esi
// 0041485c  885844               mov byte ptr [eax + 0x44], bl
// 0041485f  e8acf2ffff           call 0x413b10
// 00414864  eb76                 jmp 0x4148dc
// 00414866  80784400             cmp byte ptr [eax + 0x44], 0
// 0041486a  7513                 jne 0x41487f
// 0041486c  885844               mov byte ptr [eax + 0x44], bl
// 0041486f  56                   push esi
// 00414870  c6464400             mov byte ptr [esi + 0x44], 0
// 00414874  e827f3ffff           call 0x413ba0
// 00414879  8b06                 mov eax, dword ptr [esi]
// 0041487b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041487f  80784500             cmp byte ptr [eax + 0x45], 0
// 00414883  7513                 jne 0x414898
// 00414885  8b5008               mov edx, dword ptr [eax + 8]
// 00414888  385a44               cmp byte ptr [edx + 0x44], bl
// 0041488b  751e                 jne 0x4148ab
// 0041488d  8b10                 mov edx, dword ptr [eax]
// 0041488f  385a44               cmp byte ptr [edx + 0x44], bl
// 00414892  7517                 jne 0x4148ab
// 00414894  c6404400             mov byte ptr [eax + 0x44], 0
// 00414898  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0041489b  8bfe                 mov edi, esi
// 0041489d  8b7604               mov esi, dword ptr [esi + 4]
// 004148a0  3b7804               cmp edi, dword ptr [eax + 4]
// 004148a3  0f8547ffffff         jne 0x4147f0
// 004148a9  eb31                 jmp 0x4148dc
// 004148ab  8b10                 mov edx, dword ptr [eax]
// 004148ad  385a44               cmp byte ptr [edx + 0x44], bl
// 004148b0  7516                 jne 0x4148c8
// 004148b2  8b5008               mov edx, dword ptr [eax + 8]
// 004148b5  885a44               mov byte ptr [edx + 0x44], bl
// 004148b8  50                   push eax
// 004148b9  c6404400             mov byte ptr [eax + 0x44], 0
// 004148bd  e84ef2ffff           call 0x413b10
// 004148c2  8b06                 mov eax, dword ptr [esi]
// 004148c4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004148c8  8a5644               mov dl, byte ptr [esi + 0x44]
// 004148cb  885044               mov byte ptr [eax + 0x44], dl
// 004148ce  885e44               mov byte ptr [esi + 0x44], bl
// 004148d1  8b00                 mov eax, dword ptr [eax]
// 004148d3  56                   push esi
// 004148d4  885844               mov byte ptr [eax + 0x44], bl
// 004148d7  e8c4f2ffff           call 0x413ba0
// 004148dc  885f44               mov byte ptr [edi + 0x44], bl
// 004148df  8d750c               lea esi, [ebp + 0xc]
// 004148e2  89742414             mov dword ptr [esp + 0x14], esi
// 004148e6  8d4e1c               lea ecx, [esi + 0x1c]
// 004148e9  c744246402000000     mov dword ptr [esp + 0x64], 2
// 004148f1  ff15c4e48900         call dword ptr [0x89e4c4]
// 004148f7  8bce                 mov ecx, esi
// 004148f9  c7442464ffffffff     mov dword ptr [esp + 0x64], 0xffffffff
// 00414901  ff15c4e48900         call dword ptr [0x89e4c4]
// 00414907  55                   push ebp
// 00414908  e825413000           call 0x718a32
// 0041490d  8b542414             mov edx, dword ptr [esp + 0x14]
// 00414911  8b421c               mov eax, dword ptr [edx + 0x1c]
// 00414914  83c404               add esp, 4
// 00414917  5f                   pop edi
// 00414918  5e                   pop esi
// 00414919  5d                   pop ebp
// 0041491a  85c0                 test eax, eax
// 0041491c  7604                 jbe 0x414922
// 0041491e  48                   dec eax
// 0041491f  89421c               mov dword ptr [edx + 0x1c], eax
// 00414922  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 00414926  8b442460             mov eax, dword ptr [esp + 0x60]
// 0041492a  8b12                 mov edx, dword ptr [edx]
// 0041492c  894804               mov dword ptr [eax + 4], ecx
// 0041492f  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00414933  8910                 mov dword ptr [eax], edx
// 00414935  5b                   pop ebx
// 00414936  64890d00000000       mov dword ptr fs:[0], ecx
// 0041493d  83c458               add esp, 0x58
// 00414940  c20c00               ret 0xc
// standard library map_str<string> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

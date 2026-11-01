// from server: 100% by auto
// roc 2009-12 009240d0  unit: seg_00920000  size: 847 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009240d0
//
// 009240d0  55                   push ebp
// 009240d1  8bec                 mov ebp, esp
// 009240d3  6aff                 push -1
// 009240d5  68507c9600           push 0x967c50
// 009240da  64a100000000         mov eax, dword ptr fs:[0]
// 009240e0  50                   push eax
// 009240e1  64892500000000       mov dword ptr fs:[0], esp
// 009240e8  51                   push ecx
// 009240e9  81ec2c020000         sub esp, 0x22c
// 009240ef  53                   push ebx
// 009240f0  56                   push esi
// 009240f1  57                   push edi
// 009240f2  8965f0               mov dword ptr [ebp - 0x10], esp
// 009240f5  898dd4fdffff         mov dword ptr [ebp - 0x22c], ecx
// 009240fb  8b85d4fdffff         mov eax, dword ptr [ebp - 0x22c]
// 00924101  83780c00             cmp dword ptr [eax + 0xc], 0
// 00924105  750c                 jne 0x924113
// 00924107  c785d0fdffff00000000 mov dword ptr [ebp - 0x230], 0
// 00924111  eb1b                 jmp 0x92412e
// 00924113  8b8dd4fdffff         mov ecx, dword ptr [ebp - 0x22c]
// 00924119  8b95d4fdffff         mov edx, dword ptr [ebp - 0x22c]
// 0092411f  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00924122  2b420c               sub eax, dword ptr [edx + 0xc]
// 00924125  c1f802               sar eax, 2
// 00924128  8985d0fdffff         mov dword ptr [ebp - 0x230], eax
// 0092412e  8b8dd0fdffff         mov ecx, dword ptr [ebp - 0x230]
// 00924134  894dec               mov dword ptr [ebp - 0x14], ecx
// 00924137  837d1000             cmp dword ptr [ebp + 0x10], 0
// 0092413b  7505                 jne 0x924142
// 0092413d  e9d9060000           jmp 0x92481b
// 00924142  c745d0ffffff3f       mov dword ptr [ebp - 0x30], 0x3fffffff
// 00924149  837dd000             cmp dword ptr [ebp - 0x30], 0
// 0092414d  760b                 jbe 0x92415a
// 0092414f  8b55d0               mov edx, dword ptr [ebp - 0x30]
// 00924152  8995ccfdffff         mov dword ptr [ebp - 0x234], edx
// 00924158  eb0a                 jmp 0x924164
// 0092415a  c785ccfdffff01000000 mov dword ptr [ebp - 0x234], 1
// 00924164  8b85d4fdffff         mov eax, dword ptr [ebp - 0x22c]
// 0092416a  8b8dd4fdffff         mov ecx, dword ptr [ebp - 0x22c]
// 00924170  8b5010               mov edx, dword ptr [eax + 0x10]
// 00924173  2b510c               sub edx, dword ptr [ecx + 0xc]
// 00924176  c1fa02               sar edx, 2
// 00924179  8b85ccfdffff         mov eax, dword ptr [ebp - 0x234]
// 0092417f  2bc2                 sub eax, edx
// 00924181  3b4510               cmp eax, dword ptr [ebp + 0x10]
// 00924184  730a                 jae 0x924190
// 00924186  e805d8bcff           call 0x4f1990
// 0092418b  e98b060000           jmp 0x92481b
// 00924190  8b8dd4fdffff         mov ecx, dword ptr [ebp - 0x22c]
// 00924196  8b95d4fdffff         mov edx, dword ptr [ebp - 0x22c]
// 0092419c  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0092419f  2b420c               sub eax, dword ptr [edx + 0xc]
// 009241a2  c1f802               sar eax, 2
// 009241a5  034510               add eax, dword ptr [ebp + 0x10]
// 009241a8  3945ec               cmp dword ptr [ebp - 0x14], eax
// 009241ab  0f83ce030000         jae 0x92457f
// 009241b1  c74588ffffff3f       mov dword ptr [ebp - 0x78], 0x3fffffff
// 009241b8  837d8800             cmp dword ptr [ebp - 0x78], 0
// 009241bc  760b                 jbe 0x9241c9
// 009241be  8b4d88               mov ecx, dword ptr [ebp - 0x78]
// 009241c1  898dc8fdffff         mov dword ptr [ebp - 0x238], ecx
// 009241c7  eb0a                 jmp 0x9241d3
// 009241c9  c785c8fdffff01000000 mov dword ptr [ebp - 0x238], 1
// 009241d3  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 009241d6  d1ea                 shr edx, 1
// 009241d8  8b85c8fdffff         mov eax, dword ptr [ebp - 0x238]
// 009241de  2bc2                 sub eax, edx
// 009241e0  3b45ec               cmp eax, dword ptr [ebp - 0x14]
// 009241e3  730c                 jae 0x9241f1
// 009241e5  c785c4fdffff00000000 mov dword ptr [ebp - 0x23c], 0
// 009241ef  eb0e                 jmp 0x9241ff
// 009241f1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 009241f4  d1e9                 shr ecx, 1
// 009241f6  034dec               add ecx, dword ptr [ebp - 0x14]
// 009241f9  898dc4fdffff         mov dword ptr [ebp - 0x23c], ecx
// 009241ff  8b95c4fdffff         mov edx, dword ptr [ebp - 0x23c]
// 00924205  8955ec               mov dword ptr [ebp - 0x14], edx
// 00924208  8b85d4fdffff         mov eax, dword ptr [ebp - 0x22c]
// 0092420e  8b8dd4fdffff         mov ecx, dword ptr [ebp - 0x22c]
// 00924214  8b5010               mov edx, dword ptr [eax + 0x10]
// 00924217  2b510c               sub edx, dword ptr [ecx + 0xc]
// 0092421a  c1fa02               sar edx, 2
// 0092421d  035510               add edx, dword ptr [ebp + 0x10]
// 00924220  3955ec               cmp dword ptr [ebp - 0x14], edx
// 00924223  731b                 jae 0x924240
// 00924225  8b85d4fdffff         mov eax, dword ptr [ebp - 0x22c]
// 0092422b  8b8dd4fdffff         mov ecx, dword ptr [ebp - 0x22c]
// 00924231  8b5010               mov edx, dword ptr [eax + 0x10]
// 00924234  2b510c               sub edx, dword ptr [ecx + 0xc]
// 00924237  c1fa02               sar edx, 2
// 0092423a  035510               add edx, dword ptr [ebp + 0x10]
// 0092423d  8955ec               mov dword ptr [ebp - 0x14], edx
// 00924240  6a00                 push 0
// 00924242  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00924245  50                   push eax
// 00924246  e8e5190000           call 0x925c30
// 0092424b  83c408               add esp, 8
// 0092424e  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00924251  8b8dd4fdffff         mov ecx, dword ptr [ebp - 0x22c]
// 00924257  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0092425a  2b510c               sub edx, dword ptr [ecx + 0xc]
// 0092425d  c1fa02               sar edx, 2
// 00924260  8955e8               mov dword ptr [ebp - 0x18], edx
// 00924263  c745e000000000       mov dword ptr [ebp - 0x20], 0
// 0092426a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00924271  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00924274  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 00924277  8d1481               lea edx, [ecx + eax*4]
// 0092427a  899568ffffff         mov dword ptr [ebp - 0x98], edx
// 00924280  8b8568ffffff         mov eax, dword ptr [ebp - 0x98]
// 00924286  89856cffffff         mov dword ptr [ebp - 0x94], eax
// 0092428c  33c9                 xor ecx, ecx
// 0092428e  888d7bffffff         mov byte ptr [ebp - 0x85], cl
// 00924294  8a9579ffffff         mov dl, byte ptr [ebp - 0x87]
// 0092429a  88957affffff         mov byte ptr [ebp - 0x86], dl
// 009242a0  8a857bffffff         mov al, byte ptr [ebp - 0x85]
// 009242a6  888573ffffff         mov byte ptr [ebp - 0x8d], al
// 009242ac  8b8d6cffffff         mov ecx, dword ptr [ebp - 0x94]
// 009242b2  898d74ffffff         mov dword ptr [ebp - 0x8c], ecx
// 009242b8  8b5514               mov edx, dword ptr [ebp + 0x14]
// 009242bb  52                   push edx
// 009242bc  8b4510               mov eax, dword ptr [ebp + 0x10]
// 009242bf  50                   push eax
// 009242c0  8b8d74ffffff         mov ecx, dword ptr [ebp - 0x8c]
// 009242c6  51                   push ecx
// 009242c7  e8641d0000           call 0x926030
// 009242cc  83c40c               add esp, 0xc
// 009242cf  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 009242d2  83c201               add edx, 1
// 009242d5  8955e0               mov dword ptr [ebp - 0x20], edx
// 009242d8  8b85d4fdffff         mov eax, dword ptr [ebp - 0x22c]
// 009242de  8b480c               mov ecx, dword ptr [eax + 0xc]
// 009242e1  898d40ffffff         mov dword ptr [ebp - 0xc0], ecx
// 009242e7  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 009242ea  899544ffffff         mov dword ptr [ebp - 0xbc], edx
// 009242f0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 009242f3  898548ffffff         mov dword ptr [ebp - 0xb8], eax
// 009242f9  8b8d40ffffff         mov ecx, dword ptr [ebp - 0xc0]
// 009242ff  898d4cffffff         mov dword ptr [ebp - 0xb4], ecx
// 00924305  33d2                 xor edx, edx
// 00924307  889567ffffff         mov byte ptr [ebp - 0x99], dl
// 0092430d  8a8565ffffff         mov al, byte ptr [ebp - 0x9b]
// 00924313  888566ffffff         mov byte ptr [ebp - 0x9a], al
// 00924319  8b8d48ffffff         mov ecx, dword ptr [ebp - 0xb8]
// 0092431f  898d60ffffff         mov dword ptr [ebp - 0xa0], ecx
// 00924325  8b954cffffff         mov edx, dword ptr [ebp - 0xb4]
// 0092432b  899558ffffff         mov dword ptr [ebp - 0xa8], edx
// 00924331  8a8567ffffff         mov al, byte ptr [ebp - 0x99]
// 00924337  888553ffffff         mov byte ptr [ebp - 0xad], al
// 0092433d  8b8d44ffffff         mov ecx, dword ptr [ebp - 0xbc]
// 00924343  898d54ffffff         mov dword ptr [ebp - 0xac], ecx
// 00924349  8b95d4fdffff         mov edx, dword ptr [ebp - 0x22c]
// 0092434f  83c208               add edx, 8
// 00924352  52                   push edx
// 00924353  8b8554ffffff         mov eax, dword ptr [ebp - 0xac]
// 00924359  50                   push eax
// 0092435a  8b8d60ffffff         mov ecx, dword ptr [ebp - 0xa0]
// 00924360  51                   push ecx
// 00924361  8b9558ffffff         mov edx, dword ptr [ebp - 0xa8]
// 00924367  52                   push edx
// 00924368  e853180000           call 0x925bc0
// 0092436d  83c410               add esp, 0x10
// 00924370  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 00924373  83c001               add eax, 1
// 00924376  8945e0               mov dword ptr [ebp - 0x20], eax
// 00924379  8b8dd4fdffff         mov ecx, dword ptr [ebp - 0x22c]
// 0092437f  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00924382  899518ffffff         mov dword ptr [ebp - 0xe8], edx
// 00924388  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0092438b  034510               add eax, dword ptr [ebp + 0x10]
// 0092438e  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 00924391  8d1481               lea edx, [ecx + eax*4]
// 00924394  89951cffffff         mov dword ptr [ebp - 0xe4], edx
// 0092439a  8b8518ffffff         mov eax, dword ptr [ebp - 0xe8]
// 009243a0  898520ffffff         mov dword ptr [ebp - 0xe0], eax
// 009243a6  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 009243a9  898d24ffffff         mov dword ptr [ebp - 0xdc], ecx
// 009243af  33d2                 xor edx, edx
// 009243b1  88953fffffff         mov byte ptr [ebp - 0xc1], dl
// 009243b7  8a853dffffff         mov al, byte ptr [ebp - 0xc3]
// 009243bd  88853effffff         mov byte ptr [ebp - 0xc2], al
// 009243c3  8b8d20ffffff         mov ecx, dword ptr [ebp - 0xe0]
// 009243c9  898d38ffffff         mov dword ptr [ebp - 0xc8], ecx
// 009243cf  8b9524ffffff         mov edx, dword ptr [ebp - 0xdc]
// 009243d5  899530ffffff         mov dword ptr [ebp - 0xd0], edx
// 009243db  8a853fffffff         mov al, byte ptr [ebp - 0xc1]
// 009243e1  88852bffffff         mov byte ptr [ebp - 0xd5], al
// 009243e7  8b8d1cffffff         mov ecx, dword ptr [ebp - 0xe4]
// 009243ed  898d2cffffff         mov dword ptr [ebp - 0xd4], ecx
// 009243f3  8b95d4fdffff         mov edx, dword ptr [ebp - 0x22c]
// 009243f9  83c208               add edx, 8
// 009243fc  52                   push edx
// 009243fd  8b852cffffff         mov eax, dword ptr [ebp - 0xd4]
// 00924403  50                   push eax
// 00924404  8b8d38ffffff         mov ecx, dword ptr [ebp - 0xc8]
// 0092440a  51                   push ecx
// 0092440b  8b9530ffffff         mov edx, dword ptr [ebp - 0xd0]
// 00924411  52                   push edx
// 00924412  e8a9170000           call 0x925bc0
// 00924417  83c410               add esp, 0x10
// 0092441a  e982000000           jmp 0x9244a1
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Insert_n@?$vector@HV?$allocator@H@std@@@std@@IAEXV?$_Vector_const_iterator@HV?$allocator@H@std@@@2@IABH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp

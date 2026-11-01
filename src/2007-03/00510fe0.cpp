// from server: 100% by auto
// roc 2007-03 00510fe0  unit: seg_00510000  size: 1019 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00510fe0
//
// 00510fe0  8b542404             mov edx, dword ptr [esp + 4]
// 00510fe4  8a4208               mov al, byte ptr [edx + 8]
// 00510fe7  83ec08               sub esp, 8
// 00510fea  84c0                 test al, al
// 00510fec  53                   push ebx
// 00510fed  55                   push ebp
// 00510fee  56                   push esi
// 00510fef  8b32                 mov esi, dword ptr [edx]
// 00510ff1  57                   push edi
// 00510ff2  0f8556020000         jne 0x51124e
// 00510ff8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00510ffc  85c9                 test ecx, ecx
// 00510ffe  7406                 je 0x511006
// 00511000  0fb77908             movzx edi, word ptr [ecx + 8]
// 00511004  eb0c                 jmp 0x511012
// 00511006  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0051100e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00511012  8a4209               mov al, byte ptr [edx + 9]
// 00511015  3c08                 cmp al, 8
// 00511017  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0051101b  0f8367010000         jae 0x511188
// 00511021  0fb6c0               movzx eax, al
// 00511024  83e801               sub eax, 1
// 00511027  0f84e7000000         je 0x511114
// 0051102d  83e801               sub eax, 1
// 00511030  7475                 je 0x5110a7
// 00511032  83e802               sub eax, 2
// 00511035  0f853e010000         jne 0x511179
// 0051103b  8bc7                 mov eax, edi
// 0051103d  8d56ff               lea edx, [esi - 1]
// 00511040  83e201               and edx, 1
// 00511043  c1e004               shl eax, 4
// 00511046  03c7                 add eax, edi
// 00511048  03d2                 add edx, edx
// 0051104a  03d2                 add edx, edx
// 0051104c  0fb7c8               movzx ecx, ax
// 0051104f  8d7eff               lea edi, [esi - 1]
// 00511052  8bc2                 mov eax, edx
// 00511054  d1ef                 shr edi, 1
// 00511056  ba04000000           mov edx, 4
// 0051105b  03fb                 add edi, ebx
// 0051105d  2bd0                 sub edx, eax
// 0051105f  85f6                 test esi, esi
// 00511061  894c2410             mov dword ptr [esp + 0x10], ecx
// 00511065  8d6c1eff             lea ebp, [esi + ebx - 1]
// 00511069  0f8602010000         jbe 0x511171
// 0051106f  89742414             mov dword ptr [esp + 0x14], esi
// 00511073  0fb607               movzx eax, byte ptr [edi]
// 00511076  8aca                 mov cl, dl
// 00511078  d3e8                 shr eax, cl
// 0051107a  83e00f               and eax, 0xf
// 0051107d  8ac8                 mov cl, al
// 0051107f  c0e104               shl cl, 4
// 00511082  0ac8                 or cl, al
// 00511084  83fa04               cmp edx, 4
// 00511087  884d00               mov byte ptr [ebp], cl
// 0051108a  7507                 jne 0x511093
// 0051108c  33d2                 xor edx, edx
// 0051108e  83ef01               sub edi, 1
// 00511091  eb05                 jmp 0x511098
// 00511093  ba04000000           mov edx, 4
// 00511098  83ed01               sub ebp, 1
// 0051109b  836c241401           sub dword ptr [esp + 0x14], 1
// 005110a0  75d1                 jne 0x511073
// 005110a2  e9ca000000           jmp 0x511171
// 005110a7  6bff55               imul edi, edi, 0x55
// 005110aa  0fb7d7               movzx edx, di
// 005110ad  89542410             mov dword ptr [esp + 0x10], edx
// 005110b1  8d46ff               lea eax, [esi - 1]
// 005110b4  83e003               and eax, 3
// 005110b7  8d7eff               lea edi, [esi - 1]
// 005110ba  ba03000000           mov edx, 3
// 005110bf  c1ef02               shr edi, 2
// 005110c2  2bd0                 sub edx, eax
// 005110c4  03fb                 add edi, ebx
// 005110c6  03d2                 add edx, edx
// 005110c8  85f6                 test esi, esi
// 005110ca  8d6c1eff             lea ebp, [esi + ebx - 1]
// 005110ce  0f869d000000         jbe 0x511171
// 005110d4  89742414             mov dword ptr [esp + 0x14], esi
// 005110d8  0fb607               movzx eax, byte ptr [edi]
// 005110db  8aca                 mov cl, dl
// 005110dd  d3e8                 shr eax, cl
// 005110df  83e003               and eax, 3
// 005110e2  8ac8                 mov cl, al
// 005110e4  02c9                 add cl, cl
// 005110e6  02c9                 add cl, cl
// 005110e8  0ac8                 or cl, al
// 005110ea  02c9                 add cl, cl
// 005110ec  02c9                 add cl, cl
// 005110ee  0ac8                 or cl, al
// 005110f0  02c9                 add cl, cl
// 005110f2  02c9                 add cl, cl
// 005110f4  0ac8                 or cl, al
// 005110f6  83fa06               cmp edx, 6
// 005110f9  884d00               mov byte ptr [ebp], cl
// 005110fc  7507                 jne 0x511105
// 005110fe  33d2                 xor edx, edx
// 00511100  83ef01               sub edi, 1
// 00511103  eb03                 jmp 0x511108
// 00511105  83c202               add edx, 2
// 00511108  83ed01               sub ebp, 1
// 0051110b  836c241401           sub dword ptr [esp + 0x14], 1
// 00511110  75c6                 jne 0x5110d8
// 00511112  eb5d                 jmp 0x511171
// 00511114  69ffff000000         imul edi, edi, 0xff
// 0051111a  0fb7c7               movzx eax, di
// 0051111d  89442410             mov dword ptr [esp + 0x10], eax
// 00511121  8d7eff               lea edi, [esi - 1]
// 00511124  8d4eff               lea ecx, [esi - 1]
// 00511127  c1ef03               shr edi, 3
// 0051112a  83e107               and ecx, 7
// 0051112d  b807000000           mov eax, 7
// 00511132  03fb                 add edi, ebx
// 00511134  2bc1                 sub eax, ecx
// 00511136  85f6                 test esi, esi
// 00511138  8d6c1eff             lea ebp, [esi + ebx - 1]
// 0051113c  7637                 jbe 0x511175
// 0051113e  89742414             mov dword ptr [esp + 0x14], esi
// 00511142  8a17                 mov dl, byte ptr [edi]
// 00511144  8ac8                 mov cl, al
// 00511146  d2ea                 shr dl, cl
// 00511148  80e201               and dl, 1
// 0051114b  f6da                 neg dl
// 0051114d  1ad2                 sbb dl, dl
// 0051114f  81e2ff000000         and edx, 0xff
// 00511155  83f807               cmp eax, 7
// 00511158  885500               mov byte ptr [ebp], dl
// 0051115b  7507                 jne 0x511164
// 0051115d  33c0                 xor eax, eax
// 0051115f  83ef01               sub edi, 1
// 00511162  eb03                 jmp 0x511167
// 00511164  83c001               add eax, 1
// 00511167  83ed01               sub ebp, 1
// 0051116a  836c241401           sub dword ptr [esp + 0x14], 1
// 0051116f  75d1                 jne 0x511142
// 00511171  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00511175  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00511179  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0051117d  c6420908             mov byte ptr [edx + 9], 8
// 00511181  c6420b08             mov byte ptr [edx + 0xb], 8
// 00511185  897204               mov dword ptr [edx + 4], esi
// 00511188  85c9                 test ecx, ecx
// 0051118a  0f8443020000         je 0x5113d3
// 00511190  8a4209               mov al, byte ptr [edx + 9]
// 00511193  3c08                 cmp al, 8
// 00511195  754c                 jne 0x5111e3
// 00511197  85f6                 test esi, esi
// 00511199  8d4c1eff             lea ecx, [esi + ebx - 1]
// 0051119d  8d4473ff             lea eax, [ebx + esi*2 - 1]
// 005111a1  0f8697000000         jbe 0x51123e
// 005111a7  8bee                 mov ebp, esi
// 005111a9  8da42400000000       lea esp, [esp]
// 005111b0  660fb619             movzx bx, byte ptr [ecx]
// 005111b4  663bdf               cmp bx, di
// 005111b7  7505                 jne 0x5111be
// 005111b9  c60000               mov byte ptr [eax], 0
// 005111bc  eb03                 jmp 0x5111c1
// 005111be  c600ff               mov byte ptr [eax], 0xff
// 005111c1  8a19                 mov bl, byte ptr [ecx]
// 005111c3  83e801               sub eax, 1
// 005111c6  8818                 mov byte ptr [eax], bl
// 005111c8  83e801               sub eax, 1
// 005111cb  83e901               sub ecx, 1
// 005111ce  83ed01               sub ebp, 1
// 005111d1  75dd                 jne 0x5111b0
// 005111d3  8a4209               mov al, byte ptr [edx + 9]
// 005111d6  c6420804             mov byte ptr [edx + 8], 4
// 005111da  c6420a02             mov byte ptr [edx + 0xa], 2
// 005111de  e9c7010000           jmp 0x5113aa
// 005111e3  3c10                 cmp al, 0x10
// 005111e5  7557                 jne 0x51123e
// 005111e7  85f6                 test esi, esi
// 005111e9  8b4204               mov eax, dword ptr [edx + 4]
// 005111ec  8d4c18ff             lea ecx, [eax + ebx - 1]
// 005111f0  8d4443ff             lea eax, [ebx + eax*2 - 1]
// 005111f4  7648                 jbe 0x51123e
// 005111f6  0fb7ef               movzx ebp, di
// 005111f9  8bfe                 mov edi, esi
// 005111fb  eb03                 jmp 0x511200
// 005111fd  8d4900               lea ecx, [ecx]
// 00511200  33db                 xor ebx, ebx
// 00511202  8a79ff               mov bh, byte ptr [ecx - 1]
// 00511205  8a19                 mov bl, byte ptr [ecx]
// 00511207  3bdd                 cmp ebx, ebp
// 00511209  750b                 jne 0x511216
// 0051120b  c60000               mov byte ptr [eax], 0
// 0051120e  83e801               sub eax, 1
// 00511211  c60000               mov byte ptr [eax], 0
// 00511214  eb09                 jmp 0x51121f
// 00511216  c600ff               mov byte ptr [eax], 0xff
// 00511219  83e801               sub eax, 1
// 0051121c  c600ff               mov byte ptr [eax], 0xff
// 0051121f  0fb619               movzx ebx, byte ptr [ecx]
// 00511222  83e801               sub eax, 1
// 00511225  8818                 mov byte ptr [eax], bl
// 00511227  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0051122b  83c1ff               add ecx, -1
// 0051122e  83e801               sub eax, 1
// 00511231  8818                 mov byte ptr [eax], bl
// 00511233  83e801               sub eax, 1
// 00511236  83e901               sub ecx, 1
// 00511239  83ef01               sub edi, 1
// 0051123c  75c2                 jne 0x511200
// 0051123e  8a4209               mov al, byte ptr [edx + 9]
// 00511241  c6420804             mov byte ptr [edx + 8], 4
// 00511245  c6420a02             mov byte ptr [edx + 0xa], 2
// 00511249  e95c010000           jmp 0x5113aa
// 0051124e  3c02                 cmp al, 2
// 00511250  0f857d010000         jne 0x5113d3
// 00511256  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0051125a  85ed                 test ebp, ebp
// 0051125c  0f8471010000         je 0x5113d3
// 00511262  8a4209               mov al, byte ptr [edx + 9]
// 00511265  3c08                 cmp al, 8
// 00511267  7571                 jne 0x5112da
// 00511269  85f6                 test esi, esi
// 0051126b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0051126f  8b4a04               mov ecx, dword ptr [edx + 4]
// 00511272  8d4c01ff             lea ecx, [ecx + eax - 1]
// 00511276  8d44b0ff             lea eax, [eax + esi*4 - 1]
// 0051127a  0f861d010000         jbe 0x51139d
// 00511280  8bfe                 mov edi, esi
// 00511282  660fb659fe           movzx bx, byte ptr [ecx - 2]
// 00511287  663b5d02             cmp bx, word ptr [ebp + 2]
// 0051128b  751a                 jne 0x5112a7
// 0051128d  660fb659ff           movzx bx, byte ptr [ecx - 1]
// 00511292  663b5d04             cmp bx, word ptr [ebp + 4]
// 00511296  750f                 jne 0x5112a7
// 00511298  660fb619             movzx bx, byte ptr [ecx]
// 0051129c  663b5d06             cmp bx, word ptr [ebp + 6]
// 005112a0  7505                 jne 0x5112a7
// 005112a2  c60000               mov byte ptr [eax], 0
// 005112a5  eb03                 jmp 0x5112aa
// 005112a7  c600ff               mov byte ptr [eax], 0xff
// 005112aa  0fb619               movzx ebx, byte ptr [ecx]
// 005112ad  83e801               sub eax, 1
// 005112b0  8818                 mov byte ptr [eax], bl
// 005112b2  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 005112b6  83e901               sub ecx, 1
// 005112b9  83e801               sub eax, 1
// 005112bc  8818                 mov byte ptr [eax], bl
// 005112be  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 005112c2  83e901               sub ecx, 1
// 005112c5  83e801               sub eax, 1
// 005112c8  8818                 mov byte ptr [eax], bl
// 005112ca  83e801               sub eax, 1
// 005112cd  83e901               sub ecx, 1
// 005112d0  83ef01               sub edi, 1
// 005112d3  75ad                 jne 0x511282
// 005112d5  e9c3000000           jmp 0x51139d
// 005112da  3c10                 cmp al, 0x10
// 005112dc  0f85bb000000         jne 0x51139d
// 005112e2  85f6                 test esi, esi
// 005112e4  8b442420             mov eax, dword ptr [esp + 0x20]
// 005112e8  8b4a04               mov ecx, dword ptr [edx + 4]
// 005112eb  8d4c01ff             lea ecx, [ecx + eax - 1]
// 005112ef  8d44f0ff             lea eax, [eax + esi*8 - 1]
// 005112f3  0f86a4000000         jbe 0x51139d
// 005112f9  8bfe                 mov edi, esi
// 005112fb  eb03                 jmp 0x511300
// 005112fd  8d4900               lea ecx, [ecx]
// 00511300  0fb75d02             movzx ebx, word ptr [ebp + 2]
// 00511304  33d2                 xor edx, edx
// 00511306  8a71fb               mov dh, byte ptr [ecx - 5]
// 00511309  8a51fc               mov dl, byte ptr [ecx - 4]
// 0051130c  3bd3                 cmp edx, ebx
// 0051130e  752a                 jne 0x51133a
// 00511310  0fb75d04             movzx ebx, word ptr [ebp + 4]
// 00511314  33d2                 xor edx, edx
// 00511316  8a71fd               mov dh, byte ptr [ecx - 3]
// 00511319  8a51fe               mov dl, byte ptr [ecx - 2]
// 0051131c  3bd3                 cmp edx, ebx
// 0051131e  751a                 jne 0x51133a
// 00511320  0fb75d06             movzx ebx, word ptr [ebp + 6]
// 00511324  33d2                 xor edx, edx
// 00511326  8a71ff               mov dh, byte ptr [ecx - 1]
// 00511329  8a11                 mov dl, byte ptr [ecx]
// 0051132b  3bd3                 cmp edx, ebx
// 0051132d  750b                 jne 0x51133a
// 0051132f  c60000               mov byte ptr [eax], 0
// 00511332  83e801               sub eax, 1
// 00511335  c60000               mov byte ptr [eax], 0
// 00511338  eb09                 jmp 0x511343
// 0051133a  c600ff               mov byte ptr [eax], 0xff
// 0051133d  83e801               sub eax, 1
// 00511340  c600ff               mov byte ptr [eax], 0xff
// 00511343  0fb611               movzx edx, byte ptr [ecx]
// 00511346  8850ff               mov byte ptr [eax - 1], dl
// 00511349  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0051134d  83e801               sub eax, 1
// 00511350  83e901               sub ecx, 1
// 00511353  8850ff               mov byte ptr [eax - 1], dl
// 00511356  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0051135a  83e801               sub eax, 1
// 0051135d  83e901               sub ecx, 1
// 00511360  8850ff               mov byte ptr [eax - 1], dl
// 00511363  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00511367  83e801               sub eax, 1
// 0051136a  83e901               sub ecx, 1
// 0051136d  83e801               sub eax, 1
// 00511370  8810                 mov byte ptr [eax], dl
// 00511372  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00511376  83e901               sub ecx, 1
// 00511379  83e801               sub eax, 1
// 0051137c  8810                 mov byte ptr [eax], dl
// 0051137e  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00511382  83e901               sub ecx, 1
// 00511385  83e801               sub eax, 1
// 00511388  8810                 mov byte ptr [eax], dl
// 0051138a  83e801               sub eax, 1
// 0051138d  83e901               sub ecx, 1
// 00511390  83ef01               sub edi, 1
// 00511393  0f8567ffffff         jne 0x511300
// 00511399  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0051139d  8a4209               mov al, byte ptr [edx + 9]
// 005113a0  c6420806             mov byte ptr [edx + 8], 6
// 005113a4  c6420a04             mov byte ptr [edx + 0xa], 4
// 005113a8  02c0                 add al, al
// 005113aa  02c0                 add al, al
// 005113ac  88420b               mov byte ptr [edx + 0xb], al
// 005113af  3c08                 cmp al, 8
// 005113b1  0fb6c0               movzx eax, al
// 005113b4  7211                 jb 0x5113c7
// 005113b6  c1e803               shr eax, 3
// 005113b9  0fafc6               imul eax, esi
// 005113bc  5f                   pop edi
// 005113bd  5e                   pop esi
// 005113be  5d                   pop ebp
// 005113bf  894204               mov dword ptr [edx + 4], eax
// 005113c2  5b                   pop ebx
// 005113c3  83c408               add esp, 8
// 005113c6  c3                   ret 
// 005113c7  0fafc6               imul eax, esi
// 005113ca  83c007               add eax, 7
// 005113cd  c1e803               shr eax, 3
// 005113d0  894204               mov dword ptr [edx + 4], eax
// 005113d3  5f                   pop edi
// 005113d4  5e                   pop esi
// 005113d5  5d                   pop ebp
// 005113d6  5b                   pop ebx
// 005113d7  83c408               add esp, 8
// 005113da  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_expand)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c

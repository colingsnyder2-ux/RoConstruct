// from server: 100% by auto
// roc 2007-03 0050edf0  unit: seg_00500000  size: 793 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050edf0
//
// 0050edf0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0050edf4  53                   push ebx
// 0050edf5  55                   push ebp
// 0050edf6  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0050edfa  8a4508               mov al, byte ptr [ebp + 8]
// 0050edfd  8bda                 mov ebx, edx
// 0050edff  56                   push esi
// 0050ee00  8b7500               mov esi, dword ptr [ebp]
// 0050ee03  c1eb08               shr ebx, 8
// 0050ee06  84c0                 test al, al
// 0050ee08  57                   push edi
// 0050ee09  885c2414             mov byte ptr [esp + 0x14], bl
// 0050ee0d  0f8530010000         jne 0x50ef43
// 0050ee13  8a4509               mov al, byte ptr [ebp + 9]
// 0050ee16  3c08                 cmp al, 8
// 0050ee18  7572                 jne 0x50ee8c
// 0050ee1a  f644242080           test byte ptr [esp + 0x20], 0x80
// 0050ee1f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050ee23  8d3c06               lea edi, [esi + eax]
// 0050ee26  8d0437               lea eax, [edi + esi]
// 0050ee29  7433                 je 0x50ee5e
// 0050ee2b  83fe01               cmp esi, 1
// 0050ee2e  7618                 jbe 0x50ee48
// 0050ee30  8d4eff               lea ecx, [esi - 1]
// 0050ee33  83e801               sub eax, 1
// 0050ee36  8810                 mov byte ptr [eax], dl
// 0050ee38  8a5fff               mov bl, byte ptr [edi - 1]
// 0050ee3b  83ef01               sub edi, 1
// 0050ee3e  83e801               sub eax, 1
// 0050ee41  83e901               sub ecx, 1
// 0050ee44  8818                 mov byte ptr [eax], bl
// 0050ee46  75eb                 jne 0x50ee33
// 0050ee48  5f                   pop edi
// 0050ee49  8850ff               mov byte ptr [eax - 1], dl
// 0050ee4c  8d0c36               lea ecx, [esi + esi]
// 0050ee4f  5e                   pop esi
// 0050ee50  c6450a02             mov byte ptr [ebp + 0xa], 2
// 0050ee54  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 0050ee58  894d04               mov dword ptr [ebp + 4], ecx
// 0050ee5b  5d                   pop ebp
// 0050ee5c  5b                   pop ebx
// 0050ee5d  c3                   ret 
// 0050ee5e  85f6                 test esi, esi
// 0050ee60  7617                 jbe 0x50ee79
// 0050ee62  8bce                 mov ecx, esi
// 0050ee64  8a5fff               mov bl, byte ptr [edi - 1]
// 0050ee67  83ef01               sub edi, 1
// 0050ee6a  83e801               sub eax, 1
// 0050ee6d  8818                 mov byte ptr [eax], bl
// 0050ee6f  83e801               sub eax, 1
// 0050ee72  83e901               sub ecx, 1
// 0050ee75  8810                 mov byte ptr [eax], dl
// 0050ee77  75eb                 jne 0x50ee64
// 0050ee79  5f                   pop edi
// 0050ee7a  8d0c36               lea ecx, [esi + esi]
// 0050ee7d  5e                   pop esi
// 0050ee7e  c6450a02             mov byte ptr [ebp + 0xa], 2
// 0050ee82  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 0050ee86  894d04               mov dword ptr [ebp + 4], ecx
// 0050ee89  5d                   pop ebp
// 0050ee8a  5b                   pop ebx
// 0050ee8b  c3                   ret 
// 0050ee8c  3c10                 cmp al, 0x10
// 0050ee8e  0f8570020000         jne 0x50f104
// 0050ee94  f644242080           test byte ptr [esp + 0x20], 0x80
// 0050ee99  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050ee9d  8d3c70               lea edi, [eax + esi*2]
// 0050eea0  8d0477               lea eax, [edi + esi*2]
// 0050eea3  7456                 je 0x50eefb
// 0050eea5  83fe01               cmp esi, 1
// 0050eea8  7631                 jbe 0x50eedb
// 0050eeaa  8d4eff               lea ecx, [esi - 1]
// 0050eead  894c2414             mov dword ptr [esp + 0x14], ecx
// 0050eeb1  8858ff               mov byte ptr [eax - 1], bl
// 0050eeb4  83e801               sub eax, 1
// 0050eeb7  83e801               sub eax, 1
// 0050eeba  8810                 mov byte ptr [eax], dl
// 0050eebc  0fb64fff             movzx ecx, byte ptr [edi - 1]
// 0050eec0  83ef01               sub edi, 1
// 0050eec3  83e801               sub eax, 1
// 0050eec6  8808                 mov byte ptr [eax], cl
// 0050eec8  0fb64fff             movzx ecx, byte ptr [edi - 1]
// 0050eecc  83ef01               sub edi, 1
// 0050eecf  83e801               sub eax, 1
// 0050eed2  836c241401           sub dword ptr [esp + 0x14], 1
// 0050eed7  8808                 mov byte ptr [eax], cl
// 0050eed9  75d6                 jne 0x50eeb1
// 0050eedb  8858ff               mov byte ptr [eax - 1], bl
// 0050eede  83e801               sub eax, 1
// 0050eee1  8850ff               mov byte ptr [eax - 1], dl
// 0050eee4  5f                   pop edi
// 0050eee5  8d14b500000000       lea edx, [esi*4]
// 0050eeec  5e                   pop esi
// 0050eeed  c6450a02             mov byte ptr [ebp + 0xa], 2
// 0050eef1  c6450b20             mov byte ptr [ebp + 0xb], 0x20
// 0050eef5  895504               mov dword ptr [ebp + 4], edx
// 0050eef8  5d                   pop ebp
// 0050eef9  5b                   pop ebx
// 0050eefa  c3                   ret 
// 0050eefb  85f6                 test esi, esi
// 0050eefd  762d                 jbe 0x50ef2c
// 0050eeff  89742414             mov dword ptr [esp + 0x14], esi
// 0050ef03  0fb64fff             movzx ecx, byte ptr [edi - 1]
// 0050ef07  83ef01               sub edi, 1
// 0050ef0a  83e801               sub eax, 1
// 0050ef0d  8808                 mov byte ptr [eax], cl
// 0050ef0f  0fb64fff             movzx ecx, byte ptr [edi - 1]
// 0050ef13  83ef01               sub edi, 1
// 0050ef16  83e801               sub eax, 1
// 0050ef19  8808                 mov byte ptr [eax], cl
// 0050ef1b  83e801               sub eax, 1
// 0050ef1e  8818                 mov byte ptr [eax], bl
// 0050ef20  83e801               sub eax, 1
// 0050ef23  836c241401           sub dword ptr [esp + 0x14], 1
// 0050ef28  8810                 mov byte ptr [eax], dl
// 0050ef2a  75d7                 jne 0x50ef03
// 0050ef2c  5f                   pop edi
// 0050ef2d  8d14b500000000       lea edx, [esi*4]
// 0050ef34  5e                   pop esi
// 0050ef35  c6450a02             mov byte ptr [ebp + 0xa], 2
// 0050ef39  c6450b20             mov byte ptr [ebp + 0xb], 0x20
// 0050ef3d  895504               mov dword ptr [ebp + 4], edx
// 0050ef40  5d                   pop ebp
// 0050ef41  5b                   pop ebx
// 0050ef42  c3                   ret 
// 0050ef43  3c02                 cmp al, 2
// 0050ef45  0f85b9010000         jne 0x50f104
// 0050ef4b  8a4509               mov al, byte ptr [ebp + 9]
// 0050ef4e  3c08                 cmp al, 8
// 0050ef50  0f85a0000000         jne 0x50eff6
// 0050ef56  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050ef5a  8d3c70               lea edi, [eax + esi*2]
// 0050ef5d  03fe                 add edi, esi
// 0050ef5f  f644242080           test byte ptr [esp + 0x20], 0x80
// 0050ef64  8d0437               lea eax, [edi + esi]
// 0050ef67  743c                 je 0x50efa5
// 0050ef69  83fe01               cmp esi, 1
// 0050ef6c  7632                 jbe 0x50efa0
// 0050ef6e  8d4eff               lea ecx, [esi - 1]
// 0050ef71  8850ff               mov byte ptr [eax - 1], dl
// 0050ef74  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0050ef78  83e801               sub eax, 1
// 0050ef7b  83ef01               sub edi, 1
// 0050ef7e  83e801               sub eax, 1
// 0050ef81  8818                 mov byte ptr [eax], bl
// 0050ef83  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0050ef87  83ef01               sub edi, 1
// 0050ef8a  83e801               sub eax, 1
// 0050ef8d  8818                 mov byte ptr [eax], bl
// 0050ef8f  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0050ef93  83ef01               sub edi, 1
// 0050ef96  83e801               sub eax, 1
// 0050ef99  83e901               sub ecx, 1
// 0050ef9c  8818                 mov byte ptr [eax], bl
// 0050ef9e  75d1                 jne 0x50ef71
// 0050efa0  8850ff               mov byte ptr [eax - 1], dl
// 0050efa3  eb3a                 jmp 0x50efdf
// 0050efa5  85f6                 test esi, esi
// 0050efa7  7636                 jbe 0x50efdf
// 0050efa9  8bce                 mov ecx, esi
// 0050efab  eb03                 jmp 0x50efb0
// 0050efad  8d4900               lea ecx, [ecx]
// 0050efb0  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0050efb4  83ef01               sub edi, 1
// 0050efb7  8858ff               mov byte ptr [eax - 1], bl
// 0050efba  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0050efbe  83e801               sub eax, 1
// 0050efc1  83ef01               sub edi, 1
// 0050efc4  83e801               sub eax, 1
// 0050efc7  8818                 mov byte ptr [eax], bl
// 0050efc9  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0050efcd  83ef01               sub edi, 1
// 0050efd0  83e801               sub eax, 1
// 0050efd3  8818                 mov byte ptr [eax], bl
// 0050efd5  83e801               sub eax, 1
// 0050efd8  83e901               sub ecx, 1
// 0050efdb  8810                 mov byte ptr [eax], dl
// 0050efdd  75d1                 jne 0x50efb0
// 0050efdf  5f                   pop edi
// 0050efe0  8d0cb500000000       lea ecx, [esi*4]
// 0050efe7  5e                   pop esi
// 0050efe8  c6450a04             mov byte ptr [ebp + 0xa], 4
// 0050efec  c6450b20             mov byte ptr [ebp + 0xb], 0x20
// 0050eff0  894d04               mov dword ptr [ebp + 4], ecx
// 0050eff3  5d                   pop ebp
// 0050eff4  5b                   pop ebx
// 0050eff5  c3                   ret 
// 0050eff6  3c10                 cmp al, 0x10
// 0050eff8  0f8506010000         jne 0x50f104
// 0050effe  f644242080           test byte ptr [esp + 0x20], 0x80
// 0050f003  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050f007  8d0476               lea eax, [esi + esi*2]
// 0050f00a  8d0c41               lea ecx, [ecx + eax*2]
// 0050f00d  8d0471               lea eax, [ecx + esi*2]
// 0050f010  0f8475000000         je 0x50f08b
// 0050f016  83fe01               cmp esi, 1
// 0050f019  7666                 jbe 0x50f081
// 0050f01b  8d7eff               lea edi, [esi - 1]
// 0050f01e  8bff                 mov edi, edi
// 0050f020  8858ff               mov byte ptr [eax - 1], bl
// 0050f023  83e801               sub eax, 1
// 0050f026  8850ff               mov byte ptr [eax - 1], dl
// 0050f029  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f02d  83e801               sub eax, 1
// 0050f030  8858ff               mov byte ptr [eax - 1], bl
// 0050f033  83e901               sub ecx, 1
// 0050f036  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f03a  83e801               sub eax, 1
// 0050f03d  8858ff               mov byte ptr [eax - 1], bl
// 0050f040  83e901               sub ecx, 1
// 0050f043  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f047  83e801               sub eax, 1
// 0050f04a  83e901               sub ecx, 1
// 0050f04d  8858ff               mov byte ptr [eax - 1], bl
// 0050f050  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f054  83e801               sub eax, 1
// 0050f057  83e901               sub ecx, 1
// 0050f05a  8858ff               mov byte ptr [eax - 1], bl
// 0050f05d  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f061  83e801               sub eax, 1
// 0050f064  83e901               sub ecx, 1
// 0050f067  83e801               sub eax, 1
// 0050f06a  8818                 mov byte ptr [eax], bl
// 0050f06c  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f070  83e901               sub ecx, 1
// 0050f073  83e801               sub eax, 1
// 0050f076  83ef01               sub edi, 1
// 0050f079  8818                 mov byte ptr [eax], bl
// 0050f07b  8a5c2414             mov bl, byte ptr [esp + 0x14]
// 0050f07f  759f                 jne 0x50f020
// 0050f081  83e801               sub eax, 1
// 0050f084  8818                 mov byte ptr [eax], bl
// 0050f086  8850ff               mov byte ptr [eax - 1], dl
// 0050f089  eb67                 jmp 0x50f0f2
// 0050f08b  85f6                 test esi, esi
// 0050f08d  7663                 jbe 0x50f0f2
// 0050f08f  8bfe                 mov edi, esi
// 0050f091  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f095  8858ff               mov byte ptr [eax - 1], bl
// 0050f098  83e901               sub ecx, 1
// 0050f09b  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f09f  83e801               sub eax, 1
// 0050f0a2  8858ff               mov byte ptr [eax - 1], bl
// 0050f0a5  83e901               sub ecx, 1
// 0050f0a8  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f0ac  83e801               sub eax, 1
// 0050f0af  8858ff               mov byte ptr [eax - 1], bl
// 0050f0b2  83e901               sub ecx, 1
// 0050f0b5  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f0b9  83e801               sub eax, 1
// 0050f0bc  8858ff               mov byte ptr [eax - 1], bl
// 0050f0bf  83e901               sub ecx, 1
// 0050f0c2  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f0c6  83e801               sub eax, 1
// 0050f0c9  83e901               sub ecx, 1
// 0050f0cc  8858ff               mov byte ptr [eax - 1], bl
// 0050f0cf  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f0d3  83e801               sub eax, 1
// 0050f0d6  83e901               sub ecx, 1
// 0050f0d9  83e801               sub eax, 1
// 0050f0dc  8818                 mov byte ptr [eax], bl
// 0050f0de  0fb65c2414           movzx ebx, byte ptr [esp + 0x14]
// 0050f0e3  83e801               sub eax, 1
// 0050f0e6  8818                 mov byte ptr [eax], bl
// 0050f0e8  83e801               sub eax, 1
// 0050f0eb  83ef01               sub edi, 1
// 0050f0ee  8810                 mov byte ptr [eax], dl
// 0050f0f0  759f                 jne 0x50f091
// 0050f0f2  8d14f500000000       lea edx, [esi*8]
// 0050f0f9  c6450b40             mov byte ptr [ebp + 0xb], 0x40
// 0050f0fd  c6450a04             mov byte ptr [ebp + 0xa], 4
// 0050f101  895504               mov dword ptr [ebp + 4], edx
// 0050f104  5f                   pop edi
// 0050f105  5e                   pop esi
// 0050f106  5d                   pop ebp
// 0050f107  5b                   pop ebx
// 0050f108  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_read_filler)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c

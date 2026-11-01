// from server: 100% by auto
// roc 2009-12 00606770  unit: seg_00600000  size: 671 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00606770
//
// 00606770  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00606774  53                   push ebx
// 00606775  55                   push ebp
// 00606776  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0060677a  8a4508               mov al, byte ptr [ebp + 8]
// 0060677d  8bda                 mov ebx, edx
// 0060677f  56                   push esi
// 00606780  8b7500               mov esi, dword ptr [ebp]
// 00606783  c1eb08               shr ebx, 8
// 00606786  57                   push edi
// 00606787  885c2414             mov byte ptr [esp + 0x14], bl
// 0060678b  84c0                 test al, al
// 0060678d  0f8511010000         jne 0x6068a4
// 00606793  8a4509               mov al, byte ptr [ebp + 9]
// 00606796  3c08                 cmp al, 8
// 00606798  7568                 jne 0x606802
// 0060679a  f644242080           test byte ptr [esp + 0x20], 0x80
// 0060679f  8b442418             mov eax, dword ptr [esp + 0x18]
// 006067a3  8d3c06               lea edi, [esi + eax]
// 006067a6  8d0437               lea eax, [edi + esi]
// 006067a9  742d                 je 0x6067d8
// 006067ab  83fe01               cmp esi, 1
// 006067ae  7612                 jbe 0x6067c2
// 006067b0  8d4eff               lea ecx, [esi - 1]
// 006067b3  48                   dec eax
// 006067b4  8810                 mov byte ptr [eax], dl
// 006067b6  8a5fff               mov bl, byte ptr [edi - 1]
// 006067b9  4f                   dec edi
// 006067ba  48                   dec eax
// 006067bb  83e901               sub ecx, 1
// 006067be  8818                 mov byte ptr [eax], bl
// 006067c0  75f1                 jne 0x6067b3
// 006067c2  5f                   pop edi
// 006067c3  8850ff               mov byte ptr [eax - 1], dl
// 006067c6  8d0c36               lea ecx, [esi + esi]
// 006067c9  5e                   pop esi
// 006067ca  c6450a02             mov byte ptr [ebp + 0xa], 2
// 006067ce  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 006067d2  894d04               mov dword ptr [ebp + 4], ecx
// 006067d5  5d                   pop ebp
// 006067d6  5b                   pop ebx
// 006067d7  c3                   ret 
// 006067d8  85f6                 test esi, esi
// 006067da  7613                 jbe 0x6067ef
// 006067dc  8bce                 mov ecx, esi
// 006067de  8bff                 mov edi, edi
// 006067e0  8a5fff               mov bl, byte ptr [edi - 1]
// 006067e3  4f                   dec edi
// 006067e4  48                   dec eax
// 006067e5  8818                 mov byte ptr [eax], bl
// 006067e7  48                   dec eax
// 006067e8  83e901               sub ecx, 1
// 006067eb  8810                 mov byte ptr [eax], dl
// 006067ed  75f1                 jne 0x6067e0
// 006067ef  5f                   pop edi
// 006067f0  8d0c36               lea ecx, [esi + esi]
// 006067f3  5e                   pop esi
// 006067f4  c6450a02             mov byte ptr [ebp + 0xa], 2
// 006067f8  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 006067fc  894d04               mov dword ptr [ebp + 4], ecx
// 006067ff  5d                   pop ebp
// 00606800  5b                   pop ebx
// 00606801  c3                   ret 
// 00606802  3c10                 cmp al, 0x10
// 00606804  0f8500020000         jne 0x606a0a
// 0060680a  f644242080           test byte ptr [esp + 0x20], 0x80
// 0060680f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00606813  8d3c70               lea edi, [eax + esi*2]
// 00606816  8d0477               lea eax, [edi + esi*2]
// 00606819  7448                 je 0x606863
// 0060681b  83fe01               cmp esi, 1
// 0060681e  7625                 jbe 0x606845
// 00606820  8d4eff               lea ecx, [esi - 1]
// 00606823  894c2414             mov dword ptr [esp + 0x14], ecx
// 00606827  8858ff               mov byte ptr [eax - 1], bl
// 0060682a  48                   dec eax
// 0060682b  48                   dec eax
// 0060682c  8810                 mov byte ptr [eax], dl
// 0060682e  0fb64fff             movzx ecx, byte ptr [edi - 1]
// 00606832  4f                   dec edi
// 00606833  48                   dec eax
// 00606834  8808                 mov byte ptr [eax], cl
// 00606836  0fb64fff             movzx ecx, byte ptr [edi - 1]
// 0060683a  4f                   dec edi
// 0060683b  48                   dec eax
// 0060683c  836c241401           sub dword ptr [esp + 0x14], 1
// 00606841  8808                 mov byte ptr [eax], cl
// 00606843  75e2                 jne 0x606827
// 00606845  8858ff               mov byte ptr [eax - 1], bl
// 00606848  48                   dec eax
// 00606849  8850ff               mov byte ptr [eax - 1], dl
// 0060684c  5f                   pop edi
// 0060684d  8d14b500000000       lea edx, [esi*4]
// 00606854  5e                   pop esi
// 00606855  c6450a02             mov byte ptr [ebp + 0xa], 2
// 00606859  c6450b20             mov byte ptr [ebp + 0xb], 0x20
// 0060685d  895504               mov dword ptr [ebp + 4], edx
// 00606860  5d                   pop ebp
// 00606861  5b                   pop ebx
// 00606862  c3                   ret 
// 00606863  85f6                 test esi, esi
// 00606865  7626                 jbe 0x60688d
// 00606867  89742414             mov dword ptr [esp + 0x14], esi
// 0060686b  eb03                 jmp 0x606870
// 0060686d  8d4900               lea ecx, [ecx]
// 00606870  0fb64fff             movzx ecx, byte ptr [edi - 1]
// 00606874  4f                   dec edi
// 00606875  48                   dec eax
// 00606876  8808                 mov byte ptr [eax], cl
// 00606878  0fb64fff             movzx ecx, byte ptr [edi - 1]
// 0060687c  4f                   dec edi
// 0060687d  48                   dec eax
// 0060687e  8808                 mov byte ptr [eax], cl
// 00606880  48                   dec eax
// 00606881  8818                 mov byte ptr [eax], bl
// 00606883  48                   dec eax
// 00606884  836c241401           sub dword ptr [esp + 0x14], 1
// 00606889  8810                 mov byte ptr [eax], dl
// 0060688b  75e3                 jne 0x606870
// 0060688d  5f                   pop edi
// 0060688e  8d14b500000000       lea edx, [esi*4]
// 00606895  5e                   pop esi
// 00606896  c6450a02             mov byte ptr [ebp + 0xa], 2
// 0060689a  c6450b20             mov byte ptr [ebp + 0xb], 0x20
// 0060689e  895504               mov dword ptr [ebp + 4], edx
// 006068a1  5d                   pop ebp
// 006068a2  5b                   pop ebx
// 006068a3  c3                   ret 
// 006068a4  3c02                 cmp al, 2
// 006068a6  0f855e010000         jne 0x606a0a
// 006068ac  8a4509               mov al, byte ptr [ebp + 9]
// 006068af  3c08                 cmp al, 8
// 006068b1  0f8581000000         jne 0x606938
// 006068b7  8b442418             mov eax, dword ptr [esp + 0x18]
// 006068bb  8d3c70               lea edi, [eax + esi*2]
// 006068be  03fe                 add edi, esi
// 006068c0  f644242080           test byte ptr [esp + 0x20], 0x80
// 006068c5  8d0437               lea eax, [edi + esi]
// 006068c8  742e                 je 0x6068f8
// 006068ca  83fe01               cmp esi, 1
// 006068cd  7624                 jbe 0x6068f3
// 006068cf  8d4eff               lea ecx, [esi - 1]
// 006068d2  8850ff               mov byte ptr [eax - 1], dl
// 006068d5  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 006068d9  48                   dec eax
// 006068da  4f                   dec edi
// 006068db  48                   dec eax
// 006068dc  8818                 mov byte ptr [eax], bl
// 006068de  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 006068e2  4f                   dec edi
// 006068e3  48                   dec eax
// 006068e4  8818                 mov byte ptr [eax], bl
// 006068e6  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 006068ea  4f                   dec edi
// 006068eb  48                   dec eax
// 006068ec  83e901               sub ecx, 1
// 006068ef  8818                 mov byte ptr [eax], bl
// 006068f1  75df                 jne 0x6068d2
// 006068f3  8850ff               mov byte ptr [eax - 1], dl
// 006068f6  eb29                 jmp 0x606921
// 006068f8  85f6                 test esi, esi
// 006068fa  7625                 jbe 0x606921
// 006068fc  8bce                 mov ecx, esi
// 006068fe  8bff                 mov edi, edi
// 00606900  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 00606904  4f                   dec edi
// 00606905  8858ff               mov byte ptr [eax - 1], bl
// 00606908  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0060690c  48                   dec eax
// 0060690d  4f                   dec edi
// 0060690e  48                   dec eax
// 0060690f  8818                 mov byte ptr [eax], bl
// 00606911  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 00606915  4f                   dec edi
// 00606916  48                   dec eax
// 00606917  8818                 mov byte ptr [eax], bl
// 00606919  48                   dec eax
// 0060691a  83e901               sub ecx, 1
// 0060691d  8810                 mov byte ptr [eax], dl
// 0060691f  75df                 jne 0x606900
// 00606921  5f                   pop edi
// 00606922  8d0cb500000000       lea ecx, [esi*4]
// 00606929  5e                   pop esi
// 0060692a  c6450a04             mov byte ptr [ebp + 0xa], 4
// 0060692e  c6450b20             mov byte ptr [ebp + 0xb], 0x20
// 00606932  894d04               mov dword ptr [ebp + 4], ecx
// 00606935  5d                   pop ebp
// 00606936  5b                   pop ebx
// 00606937  c3                   ret 
// 00606938  3c10                 cmp al, 0x10
// 0060693a  0f85ca000000         jne 0x606a0a
// 00606940  f644242080           test byte ptr [esp + 0x20], 0x80
// 00606945  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00606949  8d0476               lea eax, [esi + esi*2]
// 0060694c  8d0c41               lea ecx, [ecx + eax*2]
// 0060694f  8d0471               lea eax, [ecx + esi*2]
// 00606952  7459                 je 0x6069ad
// 00606954  83fe01               cmp esi, 1
// 00606957  764c                 jbe 0x6069a5
// 00606959  8d7eff               lea edi, [esi - 1]
// 0060695c  8d642400             lea esp, [esp]
// 00606960  8858ff               mov byte ptr [eax - 1], bl
// 00606963  48                   dec eax
// 00606964  8850ff               mov byte ptr [eax - 1], dl
// 00606967  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0060696b  48                   dec eax
// 0060696c  8858ff               mov byte ptr [eax - 1], bl
// 0060696f  49                   dec ecx
// 00606970  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606974  48                   dec eax
// 00606975  8858ff               mov byte ptr [eax - 1], bl
// 00606978  49                   dec ecx
// 00606979  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0060697d  48                   dec eax
// 0060697e  49                   dec ecx
// 0060697f  8858ff               mov byte ptr [eax - 1], bl
// 00606982  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606986  48                   dec eax
// 00606987  49                   dec ecx
// 00606988  8858ff               mov byte ptr [eax - 1], bl
// 0060698b  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0060698f  48                   dec eax
// 00606990  49                   dec ecx
// 00606991  48                   dec eax
// 00606992  8818                 mov byte ptr [eax], bl
// 00606994  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606998  49                   dec ecx
// 00606999  48                   dec eax
// 0060699a  83ef01               sub edi, 1
// 0060699d  8818                 mov byte ptr [eax], bl
// 0060699f  8a5c2414             mov bl, byte ptr [esp + 0x14]
// 006069a3  75bb                 jne 0x606960
// 006069a5  48                   dec eax
// 006069a6  8818                 mov byte ptr [eax], bl
// 006069a8  8850ff               mov byte ptr [eax - 1], dl
// 006069ab  eb4b                 jmp 0x6069f8
// 006069ad  85f6                 test esi, esi
// 006069af  7647                 jbe 0x6069f8
// 006069b1  8bfe                 mov edi, esi
// 006069b3  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 006069b7  8858ff               mov byte ptr [eax - 1], bl
// 006069ba  49                   dec ecx
// 006069bb  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 006069bf  48                   dec eax
// 006069c0  8858ff               mov byte ptr [eax - 1], bl
// 006069c3  49                   dec ecx
// 006069c4  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 006069c8  48                   dec eax
// 006069c9  8858ff               mov byte ptr [eax - 1], bl
// 006069cc  49                   dec ecx
// 006069cd  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 006069d1  48                   dec eax
// 006069d2  8858ff               mov byte ptr [eax - 1], bl
// 006069d5  49                   dec ecx
// 006069d6  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 006069da  48                   dec eax
// 006069db  49                   dec ecx
// 006069dc  8858ff               mov byte ptr [eax - 1], bl
// 006069df  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 006069e3  48                   dec eax
// 006069e4  49                   dec ecx
// 006069e5  48                   dec eax
// 006069e6  8818                 mov byte ptr [eax], bl
// 006069e8  0fb65c2414           movzx ebx, byte ptr [esp + 0x14]
// 006069ed  48                   dec eax
// 006069ee  8818                 mov byte ptr [eax], bl
// 006069f0  48                   dec eax
// 006069f1  83ef01               sub edi, 1
// 006069f4  8810                 mov byte ptr [eax], dl
// 006069f6  75bb                 jne 0x6069b3
// 006069f8  8d14f500000000       lea edx, [esi*8]
// 006069ff  c6450b40             mov byte ptr [ebp + 0xb], 0x40
// 00606a03  c6450a04             mov byte ptr [ebp + 0xa], 4
// 00606a07  895504               mov dword ptr [ebp + 4], edx
// 00606a0a  5f                   pop edi
// 00606a0b  5e                   pop esi
// 00606a0c  5d                   pop ebp
// 00606a0d  5b                   pop ebx
// 00606a0e  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_read_filler)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c

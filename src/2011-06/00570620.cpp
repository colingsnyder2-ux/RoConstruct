// from server: 100% by auto
// roc 2011-06 00570620  unit: seg_00570000  size: 502 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00570620
//
// 00570620  56                   push esi
// 00570621  8b742408             mov esi, dword ptr [esp + 8]
// 00570625  8b4668               mov eax, dword ptr [esi + 0x68]
// 00570628  a801                 test al, 1
// 0057062a  750d                 jne 0x570639
// 0057062c  685069a800           push 0xa86950
// 00570631  56                   push esi
// 00570632  e8f90cffff           call 0x561330
// 00570637  eb2e                 jmp 0x570667
// 00570639  a804                 test al, 4
// 0057063b  741b                 je 0x570658
// 0057063d  683869a800           push 0xa86938
// 00570642  56                   push esi
// 00570643  e8980dffff           call 0x5613e0
// 00570648  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057064c  50                   push eax
// 0057064d  56                   push esi
// 0057064e  e8edf1ffff           call 0x56f840
// 00570653  83c410               add esp, 0x10
// 00570656  5e                   pop esi
// 00570657  c3                   ret 
// 00570658  a802                 test al, 2
// 0057065a  740e                 je 0x57066a
// 0057065c  682069a800           push 0xa86920
// 00570661  56                   push esi
// 00570662  e8790dffff           call 0x5613e0
// 00570667  83c408               add esp, 8
// 0057066a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057066e  53                   push ebx
// 0057066f  33db                 xor ebx, ebx
// 00570671  3bc3                 cmp eax, ebx
// 00570673  7425                 je 0x57069a
// 00570675  f7400800100000       test dword ptr [eax + 8], 0x1000
// 0057067c  741c                 je 0x57069a
// 0057067e  680869a800           push 0xa86908
// 00570683  56                   push esi
// 00570684  e8570dffff           call 0x5613e0
// 00570689  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0057068d  51                   push ecx
// 0057068e  56                   push esi
// 0057068f  e8acf1ffff           call 0x56f840
// 00570694  83c410               add esp, 0x10
// 00570697  5b                   pop ebx
// 00570698  5e                   pop esi
// 00570699  c3                   ret 
// 0057069a  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005706a0  55                   push ebp
// 005706a1  57                   push edi
// 005706a2  52                   push edx
// 005706a3  56                   push esi
// 005706a4  e8f70fffff           call 0x5616a0
// 005706a9  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 005706ad  8d4501               lea eax, [ebp + 1]
// 005706b0  50                   push eax
// 005706b1  56                   push esi
// 005706b2  e8890fffff           call 0x561640
// 005706b7  8bf8                 mov edi, eax
// 005706b9  55                   push ebp
// 005706ba  57                   push edi
// 005706bb  56                   push esi
// 005706bc  89be88020000         mov dword ptr [esi + 0x288], edi
// 005706c2  e8a908ffff           call 0x560f70
// 005706c7  55                   push ebp
// 005706c8  57                   push edi
// 005706c9  56                   push esi
// 005706ca  e88101feff           call 0x550850
// 005706cf  53                   push ebx
// 005706d0  56                   push esi
// 005706d1  e86af1ffff           call 0x56f840
// 005706d6  83c430               add esp, 0x30
// 005706d9  85c0                 test eax, eax
// 005706db  741b                 je 0x5706f8
// 005706dd  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 005706e3  51                   push ecx
// 005706e4  56                   push esi
// 005706e5  e8b60fffff           call 0x5616a0
// 005706ea  83c408               add esp, 8
// 005706ed  5f                   pop edi
// 005706ee  5d                   pop ebp
// 005706ef  899e88020000         mov dword ptr [esi + 0x288], ebx
// 005706f5  5b                   pop ebx
// 005706f6  5e                   pop esi
// 005706f7  c3                   ret 
// 005706f8  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005706fe  881c2a               mov byte ptr [edx + ebp], bl
// 00570701  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00570707  8bf8                 mov edi, eax
// 00570709  381f                 cmp byte ptr [edi], bl
// 0057070b  7408                 je 0x570715
// 0057070d  8d4900               lea ecx, [ecx]
// 00570710  47                   inc edi
// 00570711  381f                 cmp byte ptr [edi], bl
// 00570713  75fb                 jne 0x570710
// 00570715  47                   inc edi
// 00570716  8d4c28ff             lea ecx, [eax + ebp - 1]
// 0057071a  3bf9                 cmp edi, ecx
// 0057071c  7220                 jb 0x57073e
// 0057071e  50                   push eax
// 0057071f  56                   push esi
// 00570720  e87b0fffff           call 0x5616a0
// 00570725  68f068a800           push 0xa868f0
// 0057072a  56                   push esi
// 0057072b  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00570731  e8aa0cffff           call 0x5613e0
// 00570736  83c410               add esp, 0x10
// 00570739  5f                   pop edi
// 0057073a  5d                   pop ebp
// 0057073b  5b                   pop ebx
// 0057073c  5e                   pop esi
// 0057073d  c3                   ret 
// 0057073e  8a07                 mov al, byte ptr [edi]
// 00570740  47                   inc edi
// 00570741  84c0                 test al, al
// 00570743  7410                 je 0x570755
// 00570745  68c068a800           push 0xa868c0
// 0057074a  56                   push esi
// 0057074b  e8900cffff           call 0x5613e0
// 00570750  83c408               add esp, 8
// 00570753  32c0                 xor al, al
// 00570755  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 0057075b  8d542414             lea edx, [esp + 0x14]
// 0057075f  52                   push edx
// 00570760  57                   push edi
// 00570761  0fb6d8               movzx ebx, al
// 00570764  55                   push ebp
// 00570765  53                   push ebx
// 00570766  56                   push esi
// 00570767  e814e0ffff           call 0x56e780
// 0057076c  8b442428             mov eax, dword ptr [esp + 0x28]
// 00570770  8bc8                 mov ecx, eax
// 00570772  83c414               add esp, 0x14
// 00570775  2bcf                 sub ecx, edi
// 00570777  3bf8                 cmp edi, eax
// 00570779  7771                 ja 0x5707ec
// 0057077b  83f904               cmp ecx, 4
// 0057077e  726c                 jb 0x5707ec
// 00570780  8bae88020000         mov ebp, dword ptr [esi + 0x288]
// 00570786  0fb6042f             movzx eax, byte ptr [edi + ebp]
// 0057078a  8d142f               lea edx, [edi + ebp]
// 0057078d  0fb67a01             movzx edi, byte ptr [edx + 1]
// 00570791  c1e008               shl eax, 8
// 00570794  0bc7                 or eax, edi
// 00570796  0fb67a02             movzx edi, byte ptr [edx + 2]
// 0057079a  c1e008               shl eax, 8
// 0057079d  0bc7                 or eax, edi
// 0057079f  0fb67a03             movzx edi, byte ptr [edx + 3]
// 005707a3  c1e008               shl eax, 8
// 005707a6  0bc7                 or eax, edi
// 005707a8  3bc1                 cmp eax, ecx
// 005707aa  7330                 jae 0x5707dc
// 005707ac  8bc8                 mov ecx, eax
// 005707ae  8b442418             mov eax, dword ptr [esp + 0x18]
// 005707b2  51                   push ecx
// 005707b3  52                   push edx
// 005707b4  53                   push ebx
// 005707b5  55                   push ebp
// 005707b6  50                   push eax
// 005707b7  56                   push esi
// 005707b8  e8c399feff           call 0x55a180
// 005707bd  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 005707c3  51                   push ecx
// 005707c4  56                   push esi
// 005707c5  e8d60effff           call 0x5616a0
// 005707ca  83c420               add esp, 0x20
// 005707cd  5f                   pop edi
// 005707ce  5d                   pop ebp
// 005707cf  5b                   pop ebx
// 005707d0  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 005707da  5e                   pop esi
// 005707db  c3                   ret 
// 005707dc  76d0                 jbe 0x5707ae
// 005707de  55                   push ebp
// 005707df  56                   push esi
// 005707e0  e8bb0effff           call 0x5616a0
// 005707e5  689c68a800           push 0xa8689c
// 005707ea  eb12                 jmp 0x5707fe
// 005707ec  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005707f2  52                   push edx
// 005707f3  56                   push esi
// 005707f4  e8a70effff           call 0x5616a0
// 005707f9  687068a800           push 0xa86870
// 005707fe  56                   push esi
// 005707ff  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00570809  e8d20bffff           call 0x5613e0
// 0057080e  83c410               add esp, 0x10
// 00570811  5f                   pop edi
// 00570812  5d                   pop ebp
// 00570813  5b                   pop ebx
// 00570814  5e                   pop esi
// 00570815  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c

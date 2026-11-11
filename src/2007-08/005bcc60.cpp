// from server: 100% by EspClaude
// from server: 95% by EspClaude
// roc 2007-08 005bcc60  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 619 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bcc60
//
// 005bcc60  a144578c00           mov eax, dword ptr [0x8c5744]
// 005bcc65  8b159ce47700         mov edx, dword ptr [0x77e49c]
// 005bcc6b  83ec24               sub esp, 0x24
// 005bcc6e  a801                 test al, 1
// 005bcc70  7512                 jne 0x5bcc84
// 005bcc72  83c801               or eax, 1
// 005bcc75  a344578c00           mov dword ptr [0x8c5744], eax
// 005bcc7a  d902                 fld dword ptr [edx]
// 005bcc7c  d91540578c00         fst dword ptr [0x8c5740]
// 005bcc82  eb06                 jmp 0x5bcc8a
// 005bcc84  d90540578c00         fld dword ptr [0x8c5740]
// 005bcc8a  a801                 test al, 1
// 005bcc8c  7528                 jne 0x5bccb6
// 005bcc8e  83c801               or eax, 1
// 005bcc91  ddd8                 fstp st(0)
// 005bcc93  a801                 test al, 1
// 005bcc95  a344578c00           mov dword ptr [0x8c5744], eax
// 005bcc9a  d902                 fld dword ptr [edx]
// 005bcc9c  d91540578c00         fst dword ptr [0x8c5740]
// 005bcca2  7512                 jne 0x5bccb6
// 005bcca4  83c801               or eax, 1
// 005bcca7  ddd8                 fstp st(0)
// 005bcca9  a344578c00           mov dword ptr [0x8c5744], eax
// 005bccae  d902                 fld dword ptr [edx]
// 005bccb0  d91540578c00         fst dword ptr [0x8c5740]
// 005bccb6  a801                 test al, 1
// 005bccb8  d954240c             fst dword ptr [esp + 0xc]
// 005bccbc  d9542410             fst dword ptr [esp + 0x10]
// 005bccc0  d9c0                 fld st(0)
// 005bccc2  d9542414             fst dword ptr [esp + 0x14]
// 005bccc6  7544                 jne 0x5bcd0c
// 005bccc8  83c801               or eax, 1
// 005bcccb  ddd9                 fstp st(1)
// 005bcccd  a801                 test al, 1
// 005bcccf  a344578c00           mov dword ptr [0x8c5744], eax
// 005bccd4  d902                 fld dword ptr [edx]
// 005bccd6  d91540578c00         fst dword ptr [0x8c5740]
// 005bccdc  d9c9                 fxch st(1)
// 005bccde  752c                 jne 0x5bcd0c
// 005bcce0  83c801               or eax, 1
// 005bcce3  ddd9                 fstp st(1)
// 005bcce5  a801                 test al, 1
// 005bcce7  a344578c00           mov dword ptr [0x8c5744], eax
// 005bccec  d902                 fld dword ptr [edx]
// 005bccee  d91540578c00         fst dword ptr [0x8c5740]
// 005bccf4  d9c9                 fxch st(1)
// 005bccf6  7514                 jne 0x5bcd0c
// 005bccf8  83c801               or eax, 1
// 005bccfb  ddd9                 fstp st(1)
// 005bccfd  a344578c00           mov dword ptr [0x8c5744], eax
// 005bcd02  d902                 fld dword ptr [edx]
// 005bcd04  d91540578c00         fst dword ptr [0x8c5740]
// 005bcd0a  d9c9                 fxch st(1)
// 005bcd0c  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005bcd10  d9c9                 fxch st(1)
// 005bcd12  d9e0                 fchs 
// 005bcd14  56                   push esi
// 005bcd15  8b742434             mov esi, dword ptr [esp + 0x34]
// 005bcd19  d9542404             fst dword ptr [esp + 4]
// 005bcd1d  d9542408             fst dword ptr [esp + 8]
// 005bcd21  57                   push edi
// 005bcd22  d9542410             fst dword ptr [esp + 0x10]
// 005bcd26  33ff                 xor edi, edi
// 005bcd28  8bc7                 mov eax, edi
// 005bcd2a  c1e802               shr eax, 2
// 005bcd2d  8d0440               lea eax, [eax + eax*2]
// 005bcd30  d90481               fld dword ptr [ecx + eax*4]
// 005bcd33  8bc7                 mov eax, edi
// 005bcd35  d1e8                 shr eax, 1
// 005bcd37  2501000080           and eax, 0x80000001
// 005bcd3c  7905                 jns 0x5bcd43
// 005bcd3e  48                   dec eax
// 005bcd3f  83c8fe               or eax, 0xfffffffe
// 005bcd42  40                   inc eax
// 005bcd43  8d0440               lea eax, [eax + eax*2]
// 005bcd46  d9448104             fld dword ptr [ecx + eax*4 + 4]
// 005bcd4a  8bc7                 mov eax, edi
// 005bcd4c  83e001               and eax, 1
// 005bcd4f  8d0440               lea eax, [eax + eax*2]
// 005bcd52  d9448108             fld dword ptr [ecx + eax*4 + 8]
// 005bcd56  d94204               fld dword ptr [edx + 4]
// 005bcd59  d8ca                 fmul st(2)
// 005bcd5b  d94208               fld dword ptr [edx + 8]
// 005bcd5e  d8ca                 fmul st(2)
// 005bcd60  dec1                 faddp st(1)
// 005bcd62  d902                 fld dword ptr [edx]
// 005bcd64  d8cc                 fmul st(4)
// 005bcd66  dec1                 faddp st(1)
// 005bcd68  d84224               fadd dword ptr [edx + 0x24]
// 005bcd6b  d94210               fld dword ptr [edx + 0x10]
// 005bcd6e  d8cb                 fmul st(3)
// 005bcd70  d9420c               fld dword ptr [edx + 0xc]
// 005bcd73  d8cd                 fmul st(5)
// 005bcd75  dec1                 faddp st(1)
// 005bcd77  d94214               fld dword ptr [edx + 0x14]
// 005bcd7a  d8cb                 fmul st(3)
// 005bcd7c  dec1                 faddp st(1)
// 005bcd7e  d84228               fadd dword ptr [edx + 0x28]
// 005bcd81  d94218               fld dword ptr [edx + 0x18]
// 005bcd84  decd                 fmulp st(5)
// 005bcd86  d9cb                 fxch st(3)
// 005bcd88  d84a1c               fmul dword ptr [edx + 0x1c]
// 005bcd8b  dec4                 faddp st(4)
// 005bcd8d  d9c9                 fxch st(1)
// 005bcd8f  d84a20               fmul dword ptr [edx + 0x20]
// 005bcd92  dec3                 faddp st(3)
// 005bcd94  d9ca                 fxch st(2)
// 005bcd96  d8422c               fadd dword ptr [edx + 0x2c]
// 005bcd99  d9ca                 fxch st(2)
// 005bcd9b  d86624               fsub dword ptr [esi + 0x24]
// 005bcd9e  d9c9                 fxch st(1)
// 005bcda0  d86628               fsub dword ptr [esi + 0x28]
// 005bcda3  d9ca                 fxch st(2)
// 005bcda5  d8662c               fsub dword ptr [esi + 0x2c]
// 005bcda8  d94618               fld dword ptr [esi + 0x18]
// 005bcdab  d8c9                 fmul st(1)
// 005bcdad  d9460c               fld dword ptr [esi + 0xc]
// 005bcdb0  d8cc                 fmul st(4)
// 005bcdb2  dec1                 faddp st(1)
// 005bcdb4  d906                 fld dword ptr [esi]
// 005bcdb6  d8cb                 fmul st(3)
// 005bcdb8  dec1                 faddp st(1)
// 005bcdba  d9542420             fst dword ptr [esp + 0x20]
// 005bcdbe  d9461c               fld dword ptr [esi + 0x1c]
// 005bcdc1  d8ca                 fmul st(2)
// 005bcdc3  d94610               fld dword ptr [esi + 0x10]
// 005bcdc6  d8cd                 fmul st(5)
// 005bcdc8  dec1                 faddp st(1)
// 005bcdca  d9c3                 fld st(3)
// 005bcdcc  d84e04               fmul dword ptr [esi + 4]
// 005bcdcf  dec1                 faddp st(1)
// 005bcdd1  d9542424             fst dword ptr [esp + 0x24]
// 005bcdd5  d94608               fld dword ptr [esi + 8]
// 005bcdd8  decc                 fmulp st(4)
// 005bcdda  d94620               fld dword ptr [esi + 0x20]
// 005bcddd  decb                 fmulp st(3)
// 005bcddf  d9cb                 fxch st(3)
// 005bcde1  dec2                 faddp st(2)
// 005bcde3  d94614               fld dword ptr [esi + 0x14]
// 005bcde6  decc                 fmulp st(4)
// 005bcde8  d9c9                 fxch st(1)
// 005bcdea  dec3                 faddp st(3)
// 005bcdec  d9ca                 fxch st(2)
// 005bcdee  d9542428             fst dword ptr [esp + 0x28]
// 005bcdf2  d8d4                 fcom st(4)
// 005bcdf4  dfe0                 fnstsw ax
// 005bcdf6  dddc                 fstp st(4)
// 005bcdf8  f6c441               test ah, 0x41
// 005bcdfb  8d44241c             lea eax, [esp + 0x1c]
// 005bcdff  7404                 je 0x5bce05
// 005bce01  8d442428             lea eax, [esp + 0x28]
// 005bce05  d900                 fld dword ptr [eax]
// 005bce07  d9c9                 fxch st(1)
// 005bce09  d8542418             fcom dword ptr [esp + 0x18]
// 005bce0d  dfe0                 fnstsw ax
// 005bce0f  f6c441               test ah, 0x41
// 005bce12  8d442418             lea eax, [esp + 0x18]
// 005bce16  7404                 je 0x5bce1c
// 005bce18  8d442424             lea eax, [esp + 0x24]
// 005bce1c  d900                 fld dword ptr [eax]
// 005bce1e  d9cb                 fxch st(3)
// 005bce20  d8542414             fcom dword ptr [esp + 0x14]
// 005bce24  dfe0                 fnstsw ax
// 005bce26  f6c441               test ah, 0x41
// 005bce29  8d442414             lea eax, [esp + 0x14]
// 005bce2d  7404                 je 0x5bce33
// 005bce2f  8d442420             lea eax, [esp + 0x20]
// 005bce33  d900                 fld dword ptr [eax]
// 005bce35  d95c2414             fstp dword ptr [esp + 0x14]
// 005bce39  d9cb                 fxch st(3)
// 005bce3b  d95c2418             fstp dword ptr [esp + 0x18]
// 005bce3f  d9c9                 fxch st(1)
// 005bce41  d954241c             fst dword ptr [esp + 0x1c]
// 005bce45  d9cc                 fxch st(4)
// 005bce47  d8db                 fcomp st(3)
// 005bce49  dfe0                 fnstsw ax
// 005bce4b  ddda                 fstp st(2)
// 005bce4d  f6c405               test ah, 5
// 005bce50  8d442410             lea eax, [esp + 0x10]
// 005bce54  7b04                 jnp 0x5bce5a
// 005bce56  8d442428             lea eax, [esp + 0x28]
// 005bce5a  d900                 fld dword ptr [eax]
// 005bce5c  d944240c             fld dword ptr [esp + 0xc]
// 005bce60  d8db                 fcomp st(3)
// 005bce62  dfe0                 fnstsw ax
// 005bce64  ddda                 fstp st(2)
// 005bce66  f6c441               test ah, 0x41
// 005bce69  8d44240c             lea eax, [esp + 0xc]
// 005bce6d  7404                 je 0x5bce73
// 005bce6f  8d442424             lea eax, [esp + 0x24]
// 005bce73  d900                 fld dword ptr [eax]
// 005bce75  d9442408             fld dword ptr [esp + 8]
// 005bce79  d8da                 fcomp st(2)
// 005bce7b  dfe0                 fnstsw ax
// 005bce7d  ddd9                 fstp st(1)
// 005bce7f  f6c441               test ah, 0x41
// 005bce82  8d442408             lea eax, [esp + 8]
// 005bce86  7404                 je 0x5bce8c
// 005bce88  8d442420             lea eax, [esp + 0x20]
// 005bce8c  d900                 fld dword ptr [eax]
// 005bce8e  83c701               add edi, 1
// 005bce91  83ff08               cmp edi, 8
// 005bce94  d95c2408             fstp dword ptr [esp + 8]
// 005bce98  d95c240c             fstp dword ptr [esp + 0xc]
// 005bce9c  d9542410             fst dword ptr [esp + 0x10]
// 005bcea0  0f8c82feffff         jl 0x5bcd28
// 005bcea6  8b742430             mov esi, dword ptr [esp + 0x30]
// 005bceaa  ddd9                 fstp st(1)
// 005bceac  8d4c2408             lea ecx, [esp + 8]
// 005bceb0  ddd8                 fstp st(0)
// 005bceb2  51                   push ecx
// 005bceb3  8d542418             lea edx, [esp + 0x18]
// 005bceb7  52                   push edx
// 005bceb8  56                   push esi
// 005bceb9  e8d2fcffff           call 0x5bcb90
// 005bcebe  83c40c               add esp, 0xc
// 005bcec1  5f                   pop edi
// 005bcec2  8bc6                 mov eax, esi
// 005bcec4  5e                   pop esi
// 005bcec5  83c424               add esp, 0x24
// 005bcec8  c20c00               ret 0xc

// from server: 100% by EspClaude
// roc 2008-06 0060f9b0  unit: RBX::BlockBlockContact  size: 617 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060f9b0
//
// 0060f9b0  a194b89700           mov eax, dword ptr [0x97b894]
// 0060f9b5  8b150c258000         mov edx, dword ptr [0x80250c]
// 0060f9bb  83ec24               sub esp, 0x24
// 0060f9be  a801                 test al, 1
// 0060f9c0  7512                 jne 0x60f9d4
// 0060f9c2  83c801               or eax, 1
// 0060f9c5  a394b89700           mov dword ptr [0x97b894], eax
// 0060f9ca  d902                 fld dword ptr [edx]
// 0060f9cc  d91590b89700         fst dword ptr [0x97b890]
// 0060f9d2  eb06                 jmp 0x60f9da
// 0060f9d4  d90590b89700         fld dword ptr [0x97b890]
// 0060f9da  a801                 test al, 1
// 0060f9dc  7528                 jne 0x60fa06
// 0060f9de  83c801               or eax, 1
// 0060f9e1  ddd8                 fstp st(0)
// 0060f9e3  a394b89700           mov dword ptr [0x97b894], eax
// 0060f9e8  d902                 fld dword ptr [edx]
// 0060f9ea  d91590b89700         fst dword ptr [0x97b890]
// 0060f9f0  a801                 test al, 1
// 0060f9f2  7512                 jne 0x60fa06
// 0060f9f4  83c801               or eax, 1
// 0060f9f7  ddd8                 fstp st(0)
// 0060f9f9  a394b89700           mov dword ptr [0x97b894], eax
// 0060f9fe  d902                 fld dword ptr [edx]
// 0060fa00  d91590b89700         fst dword ptr [0x97b890]
// 0060fa06  d954240c             fst dword ptr [esp + 0xc]
// 0060fa0a  d9542410             fst dword ptr [esp + 0x10]
// 0060fa0e  d9c0                 fld st(0)
// 0060fa10  d9542414             fst dword ptr [esp + 0x14]
// 0060fa14  a801                 test al, 1
// 0060fa16  7544                 jne 0x60fa5c
// 0060fa18  83c801               or eax, 1
// 0060fa1b  ddd9                 fstp st(1)
// 0060fa1d  a394b89700           mov dword ptr [0x97b894], eax
// 0060fa22  d902                 fld dword ptr [edx]
// 0060fa24  d91590b89700         fst dword ptr [0x97b890]
// 0060fa2a  d9c9                 fxch st(1)
// 0060fa2c  a801                 test al, 1
// 0060fa2e  752c                 jne 0x60fa5c
// 0060fa30  83c801               or eax, 1
// 0060fa33  ddd9                 fstp st(1)
// 0060fa35  a394b89700           mov dword ptr [0x97b894], eax
// 0060fa3a  d902                 fld dword ptr [edx]
// 0060fa3c  d91590b89700         fst dword ptr [0x97b890]
// 0060fa42  d9c9                 fxch st(1)
// 0060fa44  a801                 test al, 1
// 0060fa46  7514                 jne 0x60fa5c
// 0060fa48  83c801               or eax, 1
// 0060fa4b  ddd9                 fstp st(1)
// 0060fa4d  a394b89700           mov dword ptr [0x97b894], eax
// 0060fa52  d902                 fld dword ptr [edx]
// 0060fa54  d91590b89700         fst dword ptr [0x97b890]
// 0060fa5a  d9c9                 fxch st(1)
// 0060fa5c  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0060fa60  d9c9                 fxch st(1)
// 0060fa62  d9e0                 fchs 
// 0060fa64  56                   push esi
// 0060fa65  8b742434             mov esi, dword ptr [esp + 0x34]
// 0060fa69  d9542404             fst dword ptr [esp + 4]
// 0060fa6d  d9542408             fst dword ptr [esp + 8]
// 0060fa71  57                   push edi
// 0060fa72  d9542410             fst dword ptr [esp + 0x10]
// 0060fa76  33ff                 xor edi, edi
// 0060fa78  8bc7                 mov eax, edi
// 0060fa7a  c1e802               shr eax, 2
// 0060fa7d  8d0440               lea eax, [eax + eax*2]
// 0060fa80  d90481               fld dword ptr [ecx + eax*4]
// 0060fa83  8bc7                 mov eax, edi
// 0060fa85  d1e8                 shr eax, 1
// 0060fa87  2501000080           and eax, 0x80000001
// 0060fa8c  7905                 jns 0x60fa93
// 0060fa8e  48                   dec eax
// 0060fa8f  83c8fe               or eax, 0xfffffffe
// 0060fa92  40                   inc eax
// 0060fa93  8d0440               lea eax, [eax + eax*2]
// 0060fa96  d9448104             fld dword ptr [ecx + eax*4 + 4]
// 0060fa9a  8bc7                 mov eax, edi
// 0060fa9c  83e001               and eax, 1
// 0060fa9f  8d0440               lea eax, [eax + eax*2]
// 0060faa2  d9448108             fld dword ptr [ecx + eax*4 + 8]
// 0060faa6  d94204               fld dword ptr [edx + 4]
// 0060faa9  d8ca                 fmul st(2)
// 0060faab  d94208               fld dword ptr [edx + 8]
// 0060faae  d8ca                 fmul st(2)
// 0060fab0  dec1                 faddp st(1)
// 0060fab2  d902                 fld dword ptr [edx]
// 0060fab4  d8cc                 fmul st(4)
// 0060fab6  dec1                 faddp st(1)
// 0060fab8  d84224               fadd dword ptr [edx + 0x24]
// 0060fabb  d94210               fld dword ptr [edx + 0x10]
// 0060fabe  d8cb                 fmul st(3)
// 0060fac0  d9420c               fld dword ptr [edx + 0xc]
// 0060fac3  d8cd                 fmul st(5)
// 0060fac5  dec1                 faddp st(1)
// 0060fac7  d94214               fld dword ptr [edx + 0x14]
// 0060faca  d8cb                 fmul st(3)
// 0060facc  dec1                 faddp st(1)
// 0060face  d84228               fadd dword ptr [edx + 0x28]
// 0060fad1  d94218               fld dword ptr [edx + 0x18]
// 0060fad4  decd                 fmulp st(5)
// 0060fad6  d9cb                 fxch st(3)
// 0060fad8  d84a1c               fmul dword ptr [edx + 0x1c]
// 0060fadb  dec4                 faddp st(4)
// 0060fadd  d9c9                 fxch st(1)
// 0060fadf  d84a20               fmul dword ptr [edx + 0x20]
// 0060fae2  dec3                 faddp st(3)
// 0060fae4  d9ca                 fxch st(2)
// 0060fae6  d8422c               fadd dword ptr [edx + 0x2c]
// 0060fae9  d9ca                 fxch st(2)
// 0060faeb  d86624               fsub dword ptr [esi + 0x24]
// 0060faee  d9c9                 fxch st(1)
// 0060faf0  d86628               fsub dword ptr [esi + 0x28]
// 0060faf3  d9ca                 fxch st(2)
// 0060faf5  d8662c               fsub dword ptr [esi + 0x2c]
// 0060faf8  d94618               fld dword ptr [esi + 0x18]
// 0060fafb  d8c9                 fmul st(1)
// 0060fafd  d9460c               fld dword ptr [esi + 0xc]
// 0060fb00  d8cc                 fmul st(4)
// 0060fb02  dec1                 faddp st(1)
// 0060fb04  d906                 fld dword ptr [esi]
// 0060fb06  d8cb                 fmul st(3)
// 0060fb08  dec1                 faddp st(1)
// 0060fb0a  d9542420             fst dword ptr [esp + 0x20]
// 0060fb0e  d9461c               fld dword ptr [esi + 0x1c]
// 0060fb11  d8ca                 fmul st(2)
// 0060fb13  d94610               fld dword ptr [esi + 0x10]
// 0060fb16  d8cd                 fmul st(5)
// 0060fb18  dec1                 faddp st(1)
// 0060fb1a  d9c3                 fld st(3)
// 0060fb1c  d84e04               fmul dword ptr [esi + 4]
// 0060fb1f  dec1                 faddp st(1)
// 0060fb21  d9542424             fst dword ptr [esp + 0x24]
// 0060fb25  d94608               fld dword ptr [esi + 8]
// 0060fb28  decc                 fmulp st(4)
// 0060fb2a  d94620               fld dword ptr [esi + 0x20]
// 0060fb2d  decb                 fmulp st(3)
// 0060fb2f  d9cb                 fxch st(3)
// 0060fb31  dec2                 faddp st(2)
// 0060fb33  d94614               fld dword ptr [esi + 0x14]
// 0060fb36  decc                 fmulp st(4)
// 0060fb38  d9c9                 fxch st(1)
// 0060fb3a  dec3                 faddp st(3)
// 0060fb3c  d9ca                 fxch st(2)
// 0060fb3e  d9542428             fst dword ptr [esp + 0x28]
// 0060fb42  d8d4                 fcom st(4)
// 0060fb44  dfe0                 fnstsw ax
// 0060fb46  dddc                 fstp st(4)
// 0060fb48  f6c441               test ah, 0x41
// 0060fb4b  8d44241c             lea eax, [esp + 0x1c]
// 0060fb4f  7404                 je 0x60fb55
// 0060fb51  8d442428             lea eax, [esp + 0x28]
// 0060fb55  d900                 fld dword ptr [eax]
// 0060fb57  d9c9                 fxch st(1)
// 0060fb59  d8542418             fcom dword ptr [esp + 0x18]
// 0060fb5d  dfe0                 fnstsw ax
// 0060fb5f  f6c441               test ah, 0x41
// 0060fb62  8d442418             lea eax, [esp + 0x18]
// 0060fb66  7404                 je 0x60fb6c
// 0060fb68  8d442424             lea eax, [esp + 0x24]
// 0060fb6c  d900                 fld dword ptr [eax]
// 0060fb6e  d9cb                 fxch st(3)
// 0060fb70  d8542414             fcom dword ptr [esp + 0x14]
// 0060fb74  dfe0                 fnstsw ax
// 0060fb76  f6c441               test ah, 0x41
// 0060fb79  8d442414             lea eax, [esp + 0x14]
// 0060fb7d  7404                 je 0x60fb83
// 0060fb7f  8d442420             lea eax, [esp + 0x20]
// 0060fb83  d900                 fld dword ptr [eax]
// 0060fb85  d95c2414             fstp dword ptr [esp + 0x14]
// 0060fb89  d9cb                 fxch st(3)
// 0060fb8b  d95c2418             fstp dword ptr [esp + 0x18]
// 0060fb8f  d9c9                 fxch st(1)
// 0060fb91  d954241c             fst dword ptr [esp + 0x1c]
// 0060fb95  d9cc                 fxch st(4)
// 0060fb97  d8db                 fcomp st(3)
// 0060fb99  dfe0                 fnstsw ax
// 0060fb9b  ddda                 fstp st(2)
// 0060fb9d  f6c405               test ah, 5
// 0060fba0  8d442410             lea eax, [esp + 0x10]
// 0060fba4  7b04                 jnp 0x60fbaa
// 0060fba6  8d442428             lea eax, [esp + 0x28]
// 0060fbaa  d900                 fld dword ptr [eax]
// 0060fbac  d944240c             fld dword ptr [esp + 0xc]
// 0060fbb0  d8db                 fcomp st(3)
// 0060fbb2  dfe0                 fnstsw ax
// 0060fbb4  ddda                 fstp st(2)
// 0060fbb6  f6c441               test ah, 0x41
// 0060fbb9  8d44240c             lea eax, [esp + 0xc]
// 0060fbbd  7404                 je 0x60fbc3
// 0060fbbf  8d442424             lea eax, [esp + 0x24]
// 0060fbc3  d900                 fld dword ptr [eax]
// 0060fbc5  d9442408             fld dword ptr [esp + 8]
// 0060fbc9  d8da                 fcomp st(2)
// 0060fbcb  dfe0                 fnstsw ax
// 0060fbcd  ddd9                 fstp st(1)
// 0060fbcf  f6c441               test ah, 0x41
// 0060fbd2  8d442408             lea eax, [esp + 8]
// 0060fbd6  7404                 je 0x60fbdc
// 0060fbd8  8d442420             lea eax, [esp + 0x20]
// 0060fbdc  d900                 fld dword ptr [eax]
// 0060fbde  47                   inc edi
// 0060fbdf  83ff08               cmp edi, 8
// 0060fbe2  d95c2408             fstp dword ptr [esp + 8]
// 0060fbe6  d95c240c             fstp dword ptr [esp + 0xc]
// 0060fbea  d9542410             fst dword ptr [esp + 0x10]
// 0060fbee  0f8c84feffff         jl 0x60fa78
// 0060fbf4  8b742430             mov esi, dword ptr [esp + 0x30]
// 0060fbf8  ddd9                 fstp st(1)
// 0060fbfa  8d4c2408             lea ecx, [esp + 8]
// 0060fbfe  ddd8                 fstp st(0)
// 0060fc00  51                   push ecx
// 0060fc01  8d542418             lea edx, [esp + 0x18]
// 0060fc05  52                   push edx
// 0060fc06  56                   push esi
// 0060fc07  e8d4fcffff           call 0x60f8e0
// 0060fc0c  83c40c               add esp, 0xc
// 0060fc0f  5f                   pop edi
// 0060fc10  8bc6                 mov eax, esi
// 0060fc12  5e                   pop esi
// 0060fc13  83c424               add esp, 0x24
// 0060fc16  c20c00               ret 0xc

// claude-opus-5-5 G3: row1 of pointToWorldSpace read into named locals (m10,m11,m12,t1) fixes fp:fast pair order
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
#include <limits>
#include <algorithm>
namespace G3D {
template <class T> inline T min(const T& x, const T& y) { return std::min<T>(x, y); }
template <class T> inline T max(const T& x, const T& y) { return std::max<T>(x, y); }
class Vector3 {
public:
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
    Vector3& operator= (const Vector3& r) { x = r.x; y = r.y; z = r.z; return *this; }
    const float& operator[] (int i) const { return ((float*)this)[i]; }
    float& operator[] (int i) { return ((float*)this)[i]; }
    Vector3 min(const Vector3 &v) const { return Vector3(G3D::min(v.x, x), G3D::min(v.y, y), G3D::min(v.z, z)); }
    Vector3 max(const Vector3 &v) const { return Vector3(G3D::max(v.x, x), G3D::max(v.y, y), G3D::max(v.z, z)); }
};
class Matrix3 {
public:
    float elt[3][3];
    float* operator[] (int iRow) { return (float*)&elt[iRow][0]; }
    const float* operator[] (int iRow) const { return (const float*)&elt[iRow][0]; }
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    Vector3 pointToWorldSpace(const Vector3& v) const {
        float m10 = rotation[1][0];
        float m11 = rotation[1][1];
        float m12 = rotation[1][2];
        float t1 = translation[1];
        return Vector3(
			rotation[0][0] * v[0] + rotation[0][1] * v[1] + rotation[0][2] * v[2] + translation[0],
			m10 * v[0] + m11 * v[1] + m12 * v[2] + t1,
			rotation[2][0] * v[0] + rotation[2][1] * v[1] + rotation[2][2] * v[2] + translation[2]);
    }
	Vector3 pointToObjectSpace(const Vector3& v) const {
		float p[3];
		p[0] = v[0] - translation[0];
		p[1] = v[1] - translation[1];
		p[2] = v[2] - translation[2];
		return Vector3(
			rotation[0][0] * p[0] + rotation[1][0] * p[1] + rotation[2][0] * p[2],
			rotation[0][1] * p[0] + rotation[1][1] * p[1] + rotation[2][1] * p[2],
			rotation[0][2] * p[0] + rotation[1][2] * p[1] + rotation[2][2] * p[2]);
    }
};
}
namespace RBX {
using G3D::Vector3;
using G3D::CoordinateFrame;
class Math { public:
	static const float& inf() { static const float i = std::numeric_limits<float>::infinity(); return i; }
};
class Extents {
public:
	Extents() {}
	static Extents vv(const Vector3& v0, const Vector3& v1);
	Vector3 getCorner(int index) const;
	Extents express(const CoordinateFrame& from, const CoordinateFrame& to);
	Vector3 low, high;
};
Vector3 Extents::getCorner(int i) const
{
	const Vector3* corners = &low;
	return Vector3(corners[i / 4].x, corners[i / 2 % 2].y, corners[i % 2].z);
}
Extents Extents::express(const CoordinateFrame& myFrame, const CoordinateFrame& expressInFrame)
{
	Vector3 minC(Math::inf(), Math::inf(), Math::inf());
	Vector3 maxC(-Math::inf(), -Math::inf(), -Math::inf());

	for (int i = 0; i < 8; ++i) {
		const Vector3 inOther = expressInFrame.pointToObjectSpace(myFrame.pointToWorldSpace(getCorner(i)));

		minC = minC.min(inOther);
		maxC = maxC.max(inOther);
	}

	return vv(minC, maxC);
}
}


// from server: 100% by auto
// roc 2012-06 00657e60  unit: seg_00650000  size: 832 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00657e60
//
// 00657e60  83ec38               sub esp, 0x38
// 00657e63  dd442440             fld qword ptr [esp + 0x40]
// 00657e67  53                   push ebx
// 00657e68  dd05e03ab500         fld qword ptr [0xb53ae0]
// 00657e6e  55                   push ebp
// 00657e6f  dcc9                 fmul st(1), st(0)
// 00657e71  56                   push esi
// 00657e72  dd0500a2b600         fld qword ptr [0xb6a200]
// 00657e78  57                   push edi
// 00657e79  d97c2450             fnstcw word ptr [esp + 0x50]
// 00657e7d  c644242063           mov byte ptr [esp + 0x20], 0x63
// 00657e82  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00657e87  dcc2                 fadd st(2), st(0)
// 00657e89  0d000c0000           or eax, 0xc00
// 00657e8e  d9ca                 fxch st(2)
// 00657e90  89442410             mov dword ptr [esp + 0x10], eax
// 00657e94  c644242148           mov byte ptr [esp + 0x21], 0x48
// 00657e99  c644242252           mov byte ptr [esp + 0x22], 0x52
// 00657e9e  d96c2410             fldcw word ptr [esp + 0x10]
// 00657ea2  c64424234d           mov byte ptr [esp + 0x23], 0x4d
// 00657ea7  c644242400           mov byte ptr [esp + 0x24], 0
// 00657eac  df7c2418             fistp qword ptr [esp + 0x18]
// 00657eb0  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00657eb4  d96c2450             fldcw word ptr [esp + 0x50]
// 00657eb8  dd442458             fld qword ptr [esp + 0x58]
// 00657ebc  d8c9                 fmul st(1)
// 00657ebe  d97c2450             fnstcw word ptr [esp + 0x50]
// 00657ec2  d8c2                 fadd st(2)
// 00657ec4  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00657ec9  0d000c0000           or eax, 0xc00
// 00657ece  89442458             mov dword ptr [esp + 0x58], eax
// 00657ed2  d96c2458             fldcw word ptr [esp + 0x58]
// 00657ed6  df7c2458             fistp qword ptr [esp + 0x58]
// 00657eda  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00657ede  894c2410             mov dword ptr [esp + 0x10], ecx
// 00657ee2  d96c2450             fldcw word ptr [esp + 0x50]
// 00657ee6  dd442460             fld qword ptr [esp + 0x60]
// 00657eea  d8c9                 fmul st(1)
// 00657eec  d97c2450             fnstcw word ptr [esp + 0x50]
// 00657ef0  d8c2                 fadd st(2)
// 00657ef2  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00657ef7  0d000c0000           or eax, 0xc00
// 00657efc  89442458             mov dword ptr [esp + 0x58], eax
// 00657f00  d96c2458             fldcw word ptr [esp + 0x58]
// 00657f04  df7c2458             fistp qword ptr [esp + 0x58]
// 00657f08  8b542458             mov edx, dword ptr [esp + 0x58]
// 00657f0c  89542414             mov dword ptr [esp + 0x14], edx
// 00657f10  d96c2450             fldcw word ptr [esp + 0x50]
// 00657f14  dd442468             fld qword ptr [esp + 0x68]
// 00657f18  d8c9                 fmul st(1)
// 00657f1a  d97c2450             fnstcw word ptr [esp + 0x50]
// 00657f1e  d8c2                 fadd st(2)
// 00657f20  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00657f25  0d000c0000           or eax, 0xc00
// 00657f2a  89442458             mov dword ptr [esp + 0x58], eax
// 00657f2e  d96c2458             fldcw word ptr [esp + 0x58]
// 00657f32  df7c2458             fistp qword ptr [esp + 0x58]
// 00657f36  8b742458             mov esi, dword ptr [esp + 0x58]
// 00657f3a  89742418             mov dword ptr [esp + 0x18], esi
// 00657f3e  d96c2450             fldcw word ptr [esp + 0x50]
// 00657f42  dd442470             fld qword ptr [esp + 0x70]
// 00657f46  d97c2450             fnstcw word ptr [esp + 0x50]
// 00657f4a  d8c9                 fmul st(1)
// 00657f4c  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00657f51  0d000c0000           or eax, 0xc00
// 00657f56  89442458             mov dword ptr [esp + 0x58], eax
// 00657f5a  d8c2                 fadd st(2)
// 00657f5c  d96c2458             fldcw word ptr [esp + 0x58]
// 00657f60  df7c2458             fistp qword ptr [esp + 0x58]
// 00657f64  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 00657f68  897c2470             mov dword ptr [esp + 0x70], edi
// 00657f6c  d96c2450             fldcw word ptr [esp + 0x50]
// 00657f70  dd442478             fld qword ptr [esp + 0x78]
// 00657f74  d97c2450             fnstcw word ptr [esp + 0x50]
// 00657f78  d8c9                 fmul st(1)
// 00657f7a  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00657f7f  0d000c0000           or eax, 0xc00
// 00657f84  89442458             mov dword ptr [esp + 0x58], eax
// 00657f88  d8c2                 fadd st(2)
// 00657f8a  d96c2458             fldcw word ptr [esp + 0x58]
// 00657f8e  df7c2458             fistp qword ptr [esp + 0x58]
// 00657f92  d96c2450             fldcw word ptr [esp + 0x50]
// 00657f96  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 00657f9a  dd842480000000       fld qword ptr [esp + 0x80]
// 00657fa1  d97c2450             fnstcw word ptr [esp + 0x50]
// 00657fa5  896c2478             mov dword ptr [esp + 0x78], ebp
// 00657fa9  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00657fae  d8c9                 fmul st(1)
// 00657fb0  0d000c0000           or eax, 0xc00
// 00657fb5  89442458             mov dword ptr [esp + 0x58], eax
// 00657fb9  d8c2                 fadd st(2)
// 00657fbb  d96c2458             fldcw word ptr [esp + 0x58]
// 00657fbf  df7c2458             fistp qword ptr [esp + 0x58]
// 00657fc3  8b442458             mov eax, dword ptr [esp + 0x58]
// 00657fc7  89442460             mov dword ptr [esp + 0x60], eax
// 00657fcb  d96c2450             fldcw word ptr [esp + 0x50]
// 00657fcf  dc8c2488000000       fmul qword ptr [esp + 0x88]
// 00657fd6  d97c2450             fnstcw word ptr [esp + 0x50]
// 00657fda  dec1                 faddp st(1)
// 00657fdc  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00657fe1  0d000c0000           or eax, 0xc00
// 00657fe6  89442468             mov dword ptr [esp + 0x68], eax
// 00657fea  d96c2468             fldcw word ptr [esp + 0x68]
// 00657fee  df7c2468             fistp qword ptr [esp + 0x68]
// 00657ff2  8b442468             mov eax, dword ptr [esp + 0x68]
// 00657ff6  50                   push eax
// 00657ff7  d96c2454             fldcw word ptr [esp + 0x54]
// 00657ffb  89442454             mov dword ptr [esp + 0x54], eax
// 00657fff  8b442464             mov eax, dword ptr [esp + 0x64]
// 00658003  50                   push eax
// 00658004  55                   push ebp
// 00658005  57                   push edi
// 00658006  56                   push esi
// 00658007  8b742460             mov esi, dword ptr [esp + 0x60]
// 0065800b  52                   push edx
// 0065800c  51                   push ecx
// 0065800d  53                   push ebx
// 0065800e  56                   push esi
// 0065800f  e8bc63feff           call 0x63e3d0
// 00658014  83c424               add esp, 0x24
// 00658017  85c0                 test eax, eax
// 00658019  0f8479010000         je 0x658198
// 0065801f  8bc3                 mov eax, ebx
// 00658021  c1e808               shr eax, 8
// 00658024  8844242a             mov byte ptr [esp + 0x2a], al
// 00658028  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065802c  8bcb                 mov ecx, ebx
// 0065802e  c1e918               shr ecx, 0x18
// 00658031  884c2428             mov byte ptr [esp + 0x28], cl
// 00658035  8bc8                 mov ecx, eax
// 00658037  c1e918               shr ecx, 0x18
// 0065803a  884c242c             mov byte ptr [esp + 0x2c], cl
// 0065803e  8bd3                 mov edx, ebx
// 00658040  c1ea10               shr edx, 0x10
// 00658043  88542429             mov byte ptr [esp + 0x29], dl
// 00658047  8bd0                 mov edx, eax
// 00658049  c1ea10               shr edx, 0x10
// 0065804c  8854242d             mov byte ptr [esp + 0x2d], dl
// 00658050  8bc8                 mov ecx, eax
// 00658052  c1e908               shr ecx, 8
// 00658055  884c242e             mov byte ptr [esp + 0x2e], cl
// 00658059  8844242f             mov byte ptr [esp + 0x2f], al
// 0065805d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00658061  8bd0                 mov edx, eax
// 00658063  c1ea18               shr edx, 0x18
// 00658066  88542430             mov byte ptr [esp + 0x30], dl
// 0065806a  8bc8                 mov ecx, eax
// 0065806c  c1e910               shr ecx, 0x10
// 0065806f  884c2431             mov byte ptr [esp + 0x31], cl
// 00658073  8bd0                 mov edx, eax
// 00658075  c1ea08               shr edx, 8
// 00658078  88542432             mov byte ptr [esp + 0x32], dl
// 0065807c  88442433             mov byte ptr [esp + 0x33], al
// 00658080  8b442418             mov eax, dword ptr [esp + 0x18]
// 00658084  8bc8                 mov ecx, eax
// 00658086  c1e918               shr ecx, 0x18
// 00658089  884c2434             mov byte ptr [esp + 0x34], cl
// 0065808d  8bd0                 mov edx, eax
// 0065808f  c1ea10               shr edx, 0x10
// 00658092  88542435             mov byte ptr [esp + 0x35], dl
// 00658096  8bc8                 mov ecx, eax
// 00658098  c1e908               shr ecx, 8
// 0065809b  884c2436             mov byte ptr [esp + 0x36], cl
// 0065809f  88442437             mov byte ptr [esp + 0x37], al
// 006580a3  8bc7                 mov eax, edi
// 006580a5  8bd0                 mov edx, eax
// 006580a7  c1ea18               shr edx, 0x18
// 006580aa  88542438             mov byte ptr [esp + 0x38], dl
// 006580ae  8bc8                 mov ecx, eax
// 006580b0  c1e910               shr ecx, 0x10
// 006580b3  884c2439             mov byte ptr [esp + 0x39], cl
// 006580b7  8bd0                 mov edx, eax
// 006580b9  c1ea08               shr edx, 8
// 006580bc  8844243b             mov byte ptr [esp + 0x3b], al
// 006580c0  8bc5                 mov eax, ebp
// 006580c2  8854243a             mov byte ptr [esp + 0x3a], dl
// 006580c6  8bc8                 mov ecx, eax
// 006580c8  c1e918               shr ecx, 0x18
// 006580cb  884c243c             mov byte ptr [esp + 0x3c], cl
// 006580cf  8bd0                 mov edx, eax
// 006580d1  c1ea10               shr edx, 0x10
// 006580d4  8854243d             mov byte ptr [esp + 0x3d], dl
// 006580d8  8bc8                 mov ecx, eax
// 006580da  c1e908               shr ecx, 8
// 006580dd  8844243f             mov byte ptr [esp + 0x3f], al
// 006580e1  8b442460             mov eax, dword ptr [esp + 0x60]
// 006580e5  884c243e             mov byte ptr [esp + 0x3e], cl
// 006580e9  8bd0                 mov edx, eax
// 006580eb  c1ea18               shr edx, 0x18
// 006580ee  88542440             mov byte ptr [esp + 0x40], dl
// 006580f2  8bc8                 mov ecx, eax
// 006580f4  c1e910               shr ecx, 0x10
// 006580f7  8bd0                 mov edx, eax
// 006580f9  88442443             mov byte ptr [esp + 0x43], al
// 006580fd  8b442450             mov eax, dword ptr [esp + 0x50]
// 00658101  884c2441             mov byte ptr [esp + 0x41], cl
// 00658105  c1ea08               shr edx, 8
// 00658108  8bc8                 mov ecx, eax
// 0065810a  c1e918               shr ecx, 0x18
// 0065810d  88542442             mov byte ptr [esp + 0x42], dl
// 00658111  885c242b             mov byte ptr [esp + 0x2b], bl
// 00658115  884c2444             mov byte ptr [esp + 0x44], cl
// 00658119  8bd0                 mov edx, eax
// 0065811b  8bc8                 mov ecx, eax
// 0065811d  c1ea10               shr edx, 0x10
// 00658120  c1e908               shr ecx, 8
// 00658123  88542445             mov byte ptr [esp + 0x45], dl
// 00658127  884c2446             mov byte ptr [esp + 0x46], cl
// 0065812b  88442447             mov byte ptr [esp + 0x47], al
// 0065812f  85f6                 test esi, esi
// 00658131  7465                 je 0x658198
// 00658133  6a20                 push 0x20
// 00658135  8d542424             lea edx, [esp + 0x24]
// 00658139  52                   push edx
// 0065813a  56                   push esi
// 0065813b  e880dfffff           call 0x6560c0
// 00658140  6a20                 push 0x20
// 00658142  8d442438             lea eax, [esp + 0x38]
// 00658146  50                   push eax
// 00658147  56                   push esi
// 00658148  e873f5feff           call 0x6476c0
// 0065814d  6a20                 push 0x20
// 0065814f  8d4c2444             lea ecx, [esp + 0x44]
// 00658153  51                   push ecx
// 00658154  56                   push esi
// 00658155  e8365dfeff           call 0x63de90
// 0065815a  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00658160  8bd0                 mov edx, eax
// 00658162  c1ea18               shr edx, 0x18
// 00658165  8854247c             mov byte ptr [esp + 0x7c], dl
// 00658169  8bc8                 mov ecx, eax
// 0065816b  8bd0                 mov edx, eax
// 0065816d  8844247f             mov byte ptr [esp + 0x7f], al
// 00658171  6a04                 push 4
// 00658173  8d842480000000       lea eax, [esp + 0x80]
// 0065817a  50                   push eax
// 0065817b  c1e910               shr ecx, 0x10
// 0065817e  c1ea08               shr edx, 8
// 00658181  56                   push esi
// 00658182  888c2489000000       mov byte ptr [esp + 0x89], cl
// 00658189  8894248a000000       mov byte ptr [esp + 0x8a], dl
// 00658190  e82bf5feff           call 0x6476c0
// 00658195  83c430               add esp, 0x30
// 00658198  5f                   pop edi
// 00658199  5e                   pop esi
// 0065819a  5d                   pop ebp
// 0065819b  5b                   pop ebx
// 0065819c  83c438               add esp, 0x38
// 0065819f  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_cHRM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c

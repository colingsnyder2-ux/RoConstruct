// from server: 100% by auto
// roc 2011-06 0056c750  unit: seg_00560000  size: 832 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056c750
//
// 0056c750  83ec38               sub esp, 0x38
// 0056c753  dd442440             fld qword ptr [esp + 0x40]
// 0056c757  53                   push ebx
// 0056c758  dd05c890a600         fld qword ptr [0xa690c8]
// 0056c75e  55                   push ebp
// 0056c75f  dcc9                 fmul st(1), st(0)
// 0056c761  56                   push esi
// 0056c762  dd0508afa700         fld qword ptr [0xa7af08]
// 0056c768  57                   push edi
// 0056c769  d97c2450             fnstcw word ptr [esp + 0x50]
// 0056c76d  c644242063           mov byte ptr [esp + 0x20], 0x63
// 0056c772  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0056c777  dcc2                 fadd st(2), st(0)
// 0056c779  0d000c0000           or eax, 0xc00
// 0056c77e  d9ca                 fxch st(2)
// 0056c780  89442410             mov dword ptr [esp + 0x10], eax
// 0056c784  c644242148           mov byte ptr [esp + 0x21], 0x48
// 0056c789  c644242252           mov byte ptr [esp + 0x22], 0x52
// 0056c78e  d96c2410             fldcw word ptr [esp + 0x10]
// 0056c792  c64424234d           mov byte ptr [esp + 0x23], 0x4d
// 0056c797  c644242400           mov byte ptr [esp + 0x24], 0
// 0056c79c  df7c2418             fistp qword ptr [esp + 0x18]
// 0056c7a0  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0056c7a4  d96c2450             fldcw word ptr [esp + 0x50]
// 0056c7a8  dd442458             fld qword ptr [esp + 0x58]
// 0056c7ac  d8c9                 fmul st(1)
// 0056c7ae  d97c2450             fnstcw word ptr [esp + 0x50]
// 0056c7b2  d8c2                 fadd st(2)
// 0056c7b4  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0056c7b9  0d000c0000           or eax, 0xc00
// 0056c7be  89442458             mov dword ptr [esp + 0x58], eax
// 0056c7c2  d96c2458             fldcw word ptr [esp + 0x58]
// 0056c7c6  df7c2458             fistp qword ptr [esp + 0x58]
// 0056c7ca  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0056c7ce  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056c7d2  d96c2450             fldcw word ptr [esp + 0x50]
// 0056c7d6  dd442460             fld qword ptr [esp + 0x60]
// 0056c7da  d8c9                 fmul st(1)
// 0056c7dc  d97c2450             fnstcw word ptr [esp + 0x50]
// 0056c7e0  d8c2                 fadd st(2)
// 0056c7e2  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0056c7e7  0d000c0000           or eax, 0xc00
// 0056c7ec  89442458             mov dword ptr [esp + 0x58], eax
// 0056c7f0  d96c2458             fldcw word ptr [esp + 0x58]
// 0056c7f4  df7c2458             fistp qword ptr [esp + 0x58]
// 0056c7f8  8b542458             mov edx, dword ptr [esp + 0x58]
// 0056c7fc  89542414             mov dword ptr [esp + 0x14], edx
// 0056c800  d96c2450             fldcw word ptr [esp + 0x50]
// 0056c804  dd442468             fld qword ptr [esp + 0x68]
// 0056c808  d8c9                 fmul st(1)
// 0056c80a  d97c2450             fnstcw word ptr [esp + 0x50]
// 0056c80e  d8c2                 fadd st(2)
// 0056c810  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0056c815  0d000c0000           or eax, 0xc00
// 0056c81a  89442458             mov dword ptr [esp + 0x58], eax
// 0056c81e  d96c2458             fldcw word ptr [esp + 0x58]
// 0056c822  df7c2458             fistp qword ptr [esp + 0x58]
// 0056c826  8b742458             mov esi, dword ptr [esp + 0x58]
// 0056c82a  89742418             mov dword ptr [esp + 0x18], esi
// 0056c82e  d96c2450             fldcw word ptr [esp + 0x50]
// 0056c832  dd442470             fld qword ptr [esp + 0x70]
// 0056c836  d97c2450             fnstcw word ptr [esp + 0x50]
// 0056c83a  d8c9                 fmul st(1)
// 0056c83c  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0056c841  0d000c0000           or eax, 0xc00
// 0056c846  89442458             mov dword ptr [esp + 0x58], eax
// 0056c84a  d8c2                 fadd st(2)
// 0056c84c  d96c2458             fldcw word ptr [esp + 0x58]
// 0056c850  df7c2458             fistp qword ptr [esp + 0x58]
// 0056c854  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 0056c858  897c2470             mov dword ptr [esp + 0x70], edi
// 0056c85c  d96c2450             fldcw word ptr [esp + 0x50]
// 0056c860  dd442478             fld qword ptr [esp + 0x78]
// 0056c864  d97c2450             fnstcw word ptr [esp + 0x50]
// 0056c868  d8c9                 fmul st(1)
// 0056c86a  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0056c86f  0d000c0000           or eax, 0xc00
// 0056c874  89442458             mov dword ptr [esp + 0x58], eax
// 0056c878  d8c2                 fadd st(2)
// 0056c87a  d96c2458             fldcw word ptr [esp + 0x58]
// 0056c87e  df7c2458             fistp qword ptr [esp + 0x58]
// 0056c882  d96c2450             fldcw word ptr [esp + 0x50]
// 0056c886  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 0056c88a  dd842480000000       fld qword ptr [esp + 0x80]
// 0056c891  d97c2450             fnstcw word ptr [esp + 0x50]
// 0056c895  896c2478             mov dword ptr [esp + 0x78], ebp
// 0056c899  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0056c89e  d8c9                 fmul st(1)
// 0056c8a0  0d000c0000           or eax, 0xc00
// 0056c8a5  89442458             mov dword ptr [esp + 0x58], eax
// 0056c8a9  d8c2                 fadd st(2)
// 0056c8ab  d96c2458             fldcw word ptr [esp + 0x58]
// 0056c8af  df7c2458             fistp qword ptr [esp + 0x58]
// 0056c8b3  8b442458             mov eax, dword ptr [esp + 0x58]
// 0056c8b7  89442460             mov dword ptr [esp + 0x60], eax
// 0056c8bb  d96c2450             fldcw word ptr [esp + 0x50]
// 0056c8bf  dc8c2488000000       fmul qword ptr [esp + 0x88]
// 0056c8c6  d97c2450             fnstcw word ptr [esp + 0x50]
// 0056c8ca  dec1                 faddp st(1)
// 0056c8cc  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0056c8d1  0d000c0000           or eax, 0xc00
// 0056c8d6  89442468             mov dword ptr [esp + 0x68], eax
// 0056c8da  d96c2468             fldcw word ptr [esp + 0x68]
// 0056c8de  df7c2468             fistp qword ptr [esp + 0x68]
// 0056c8e2  8b442468             mov eax, dword ptr [esp + 0x68]
// 0056c8e6  50                   push eax
// 0056c8e7  d96c2454             fldcw word ptr [esp + 0x54]
// 0056c8eb  89442454             mov dword ptr [esp + 0x54], eax
// 0056c8ef  8b442464             mov eax, dword ptr [esp + 0x64]
// 0056c8f3  50                   push eax
// 0056c8f4  55                   push ebp
// 0056c8f5  57                   push edi
// 0056c8f6  56                   push esi
// 0056c8f7  8b742460             mov esi, dword ptr [esp + 0x60]
// 0056c8fb  52                   push edx
// 0056c8fc  51                   push ecx
// 0056c8fd  53                   push ebx
// 0056c8fe  56                   push esi
// 0056c8ff  e88c44feff           call 0x550d90
// 0056c904  83c424               add esp, 0x24
// 0056c907  85c0                 test eax, eax
// 0056c909  0f8479010000         je 0x56ca88
// 0056c90f  8bc3                 mov eax, ebx
// 0056c911  c1e808               shr eax, 8
// 0056c914  8844242a             mov byte ptr [esp + 0x2a], al
// 0056c918  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056c91c  8bcb                 mov ecx, ebx
// 0056c91e  c1e918               shr ecx, 0x18
// 0056c921  884c2428             mov byte ptr [esp + 0x28], cl
// 0056c925  8bc8                 mov ecx, eax
// 0056c927  c1e918               shr ecx, 0x18
// 0056c92a  884c242c             mov byte ptr [esp + 0x2c], cl
// 0056c92e  8bd3                 mov edx, ebx
// 0056c930  c1ea10               shr edx, 0x10
// 0056c933  88542429             mov byte ptr [esp + 0x29], dl
// 0056c937  8bd0                 mov edx, eax
// 0056c939  c1ea10               shr edx, 0x10
// 0056c93c  8854242d             mov byte ptr [esp + 0x2d], dl
// 0056c940  8bc8                 mov ecx, eax
// 0056c942  c1e908               shr ecx, 8
// 0056c945  884c242e             mov byte ptr [esp + 0x2e], cl
// 0056c949  8844242f             mov byte ptr [esp + 0x2f], al
// 0056c94d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056c951  8bd0                 mov edx, eax
// 0056c953  c1ea18               shr edx, 0x18
// 0056c956  88542430             mov byte ptr [esp + 0x30], dl
// 0056c95a  8bc8                 mov ecx, eax
// 0056c95c  c1e910               shr ecx, 0x10
// 0056c95f  884c2431             mov byte ptr [esp + 0x31], cl
// 0056c963  8bd0                 mov edx, eax
// 0056c965  c1ea08               shr edx, 8
// 0056c968  88542432             mov byte ptr [esp + 0x32], dl
// 0056c96c  88442433             mov byte ptr [esp + 0x33], al
// 0056c970  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056c974  8bc8                 mov ecx, eax
// 0056c976  c1e918               shr ecx, 0x18
// 0056c979  884c2434             mov byte ptr [esp + 0x34], cl
// 0056c97d  8bd0                 mov edx, eax
// 0056c97f  c1ea10               shr edx, 0x10
// 0056c982  88542435             mov byte ptr [esp + 0x35], dl
// 0056c986  8bc8                 mov ecx, eax
// 0056c988  c1e908               shr ecx, 8
// 0056c98b  884c2436             mov byte ptr [esp + 0x36], cl
// 0056c98f  88442437             mov byte ptr [esp + 0x37], al
// 0056c993  8bc7                 mov eax, edi
// 0056c995  8bd0                 mov edx, eax
// 0056c997  c1ea18               shr edx, 0x18
// 0056c99a  88542438             mov byte ptr [esp + 0x38], dl
// 0056c99e  8bc8                 mov ecx, eax
// 0056c9a0  c1e910               shr ecx, 0x10
// 0056c9a3  884c2439             mov byte ptr [esp + 0x39], cl
// 0056c9a7  8bd0                 mov edx, eax
// 0056c9a9  c1ea08               shr edx, 8
// 0056c9ac  8844243b             mov byte ptr [esp + 0x3b], al
// 0056c9b0  8bc5                 mov eax, ebp
// 0056c9b2  8854243a             mov byte ptr [esp + 0x3a], dl
// 0056c9b6  8bc8                 mov ecx, eax
// 0056c9b8  c1e918               shr ecx, 0x18
// 0056c9bb  884c243c             mov byte ptr [esp + 0x3c], cl
// 0056c9bf  8bd0                 mov edx, eax
// 0056c9c1  c1ea10               shr edx, 0x10
// 0056c9c4  8854243d             mov byte ptr [esp + 0x3d], dl
// 0056c9c8  8bc8                 mov ecx, eax
// 0056c9ca  c1e908               shr ecx, 8
// 0056c9cd  8844243f             mov byte ptr [esp + 0x3f], al
// 0056c9d1  8b442460             mov eax, dword ptr [esp + 0x60]
// 0056c9d5  884c243e             mov byte ptr [esp + 0x3e], cl
// 0056c9d9  8bd0                 mov edx, eax
// 0056c9db  c1ea18               shr edx, 0x18
// 0056c9de  88542440             mov byte ptr [esp + 0x40], dl
// 0056c9e2  8bc8                 mov ecx, eax
// 0056c9e4  c1e910               shr ecx, 0x10
// 0056c9e7  8bd0                 mov edx, eax
// 0056c9e9  88442443             mov byte ptr [esp + 0x43], al
// 0056c9ed  8b442450             mov eax, dword ptr [esp + 0x50]
// 0056c9f1  884c2441             mov byte ptr [esp + 0x41], cl
// 0056c9f5  c1ea08               shr edx, 8
// 0056c9f8  8bc8                 mov ecx, eax
// 0056c9fa  c1e918               shr ecx, 0x18
// 0056c9fd  88542442             mov byte ptr [esp + 0x42], dl
// 0056ca01  885c242b             mov byte ptr [esp + 0x2b], bl
// 0056ca05  884c2444             mov byte ptr [esp + 0x44], cl
// 0056ca09  8bd0                 mov edx, eax
// 0056ca0b  8bc8                 mov ecx, eax
// 0056ca0d  c1ea10               shr edx, 0x10
// 0056ca10  c1e908               shr ecx, 8
// 0056ca13  88542445             mov byte ptr [esp + 0x45], dl
// 0056ca17  884c2446             mov byte ptr [esp + 0x46], cl
// 0056ca1b  88442447             mov byte ptr [esp + 0x47], al
// 0056ca1f  85f6                 test esi, esi
// 0056ca21  7465                 je 0x56ca88
// 0056ca23  6a20                 push 0x20
// 0056ca25  8d542424             lea edx, [esp + 0x24]
// 0056ca29  52                   push edx
// 0056ca2a  56                   push esi
// 0056ca2b  e880dfffff           call 0x56a9b0
// 0056ca30  6a20                 push 0x20
// 0056ca32  8d442438             lea eax, [esp + 0x38]
// 0056ca36  50                   push eax
// 0056ca37  56                   push esi
// 0056ca38  e803defeff           call 0x55a840
// 0056ca3d  6a20                 push 0x20
// 0056ca3f  8d4c2444             lea ecx, [esp + 0x44]
// 0056ca43  51                   push ecx
// 0056ca44  56                   push esi
// 0056ca45  e8063efeff           call 0x550850
// 0056ca4a  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056ca50  8bd0                 mov edx, eax
// 0056ca52  c1ea18               shr edx, 0x18
// 0056ca55  8854247c             mov byte ptr [esp + 0x7c], dl
// 0056ca59  8bc8                 mov ecx, eax
// 0056ca5b  8bd0                 mov edx, eax
// 0056ca5d  8844247f             mov byte ptr [esp + 0x7f], al
// 0056ca61  6a04                 push 4
// 0056ca63  8d842480000000       lea eax, [esp + 0x80]
// 0056ca6a  50                   push eax
// 0056ca6b  c1e910               shr ecx, 0x10
// 0056ca6e  c1ea08               shr edx, 8
// 0056ca71  56                   push esi
// 0056ca72  888c2489000000       mov byte ptr [esp + 0x89], cl
// 0056ca79  8894248a000000       mov byte ptr [esp + 0x8a], dl
// 0056ca80  e8bbddfeff           call 0x55a840
// 0056ca85  83c430               add esp, 0x30
// 0056ca88  5f                   pop edi
// 0056ca89  5e                   pop esi
// 0056ca8a  5d                   pop ebp
// 0056ca8b  5b                   pop ebx
// 0056ca8c  83c438               add esp, 0x38
// 0056ca8f  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_cHRM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c

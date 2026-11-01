// from server: 100% by auto
// roc 2010-06 0044eec0  unit: CRbxPlayDocTemplate  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044eec0
//
// 0044eec0  83ec08               sub esp, 8
// 0044eec3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044eec7  56                   push esi
// 0044eec8  8d442404             lea eax, [esp + 4]
// 0044eecc  50                   push eax
// 0044eecd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044eed1  8d4c240c             lea ecx, [esp + 0xc]
// 0044eed5  51                   push ecx
// 0044eed6  52                   push edx
// 0044eed7  50                   push eax
// 0044eed8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044eee0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044eee8  e8c3f9ffff           call 0x44e8b0
// 0044eeed  8bf0                 mov esi, eax
// 0044eeef  85f6                 test esi, esi
// 0044eef1  7c70                 jl 0x44ef63
// 0044eef3  8b442404             mov eax, dword ptr [esp + 4]
// 0044eef7  8b08                 mov ecx, dword ptr [eax]
// 0044eef9  8d542414             lea edx, [esp + 0x14]
// 0044eefd  52                   push edx
// 0044eefe  50                   push eax
// 0044eeff  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0044ef02  ffd0                 call eax
// 0044ef04  8bf0                 mov esi, eax
// 0044ef06  85f6                 test esi, esi
// 0044ef08  7c59                 jl 0x44ef63
// 0044ef0a  803decfabf0001       cmp byte ptr [0xbffaec], 1
// 0044ef11  751f                 jne 0x44ef32
// 0044ef13  6800c2a000           push 0xa0c200
// 0044ef18  ff15e4a29e00         call dword ptr [0x9ea2e4]
// 0044ef1e  85c0                 test eax, eax
// 0044ef20  7410                 je 0x44ef32
// 0044ef22  68e4c1a000           push 0xa0c1e4
// 0044ef27  50                   push eax
// 0044ef28  ff1590a39e00         call dword ptr [0x9ea390]
// 0044ef2e  85c0                 test eax, eax
// 0044ef30  7505                 jne 0x44ef37
// 0044ef32  a13caa9e00           mov eax, dword ptr [0x9eaa3c]
// 0044ef37  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044ef3b  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0044ef3e  52                   push edx
// 0044ef3f  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0044ef42  52                   push edx
// 0044ef43  0fb7511a             movzx edx, word ptr [ecx + 0x1a]
// 0044ef47  52                   push edx
// 0044ef48  0fb75118             movzx edx, word ptr [ecx + 0x18]
// 0044ef4c  52                   push edx
// 0044ef4d  51                   push ecx
// 0044ef4e  ffd0                 call eax
// 0044ef50  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044ef54  8bf0                 mov esi, eax
// 0044ef56  8b442404             mov eax, dword ptr [esp + 4]
// 0044ef5a  8b08                 mov ecx, dword ptr [eax]
// 0044ef5c  52                   push edx
// 0044ef5d  50                   push eax
// 0044ef5e  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0044ef61  ffd0                 call eax
// 0044ef63  8b442404             mov eax, dword ptr [esp + 4]
// 0044ef67  85c0                 test eax, eax
// 0044ef69  7408                 je 0x44ef73
// 0044ef6b  8b08                 mov ecx, dword ptr [eax]
// 0044ef6d  8b5108               mov edx, dword ptr [ecx + 8]
// 0044ef70  50                   push eax
// 0044ef71  ffd2                 call edx
// 0044ef73  8b442408             mov eax, dword ptr [esp + 8]
// 0044ef77  50                   push eax
// 0044ef78  ff1540aa9e00         call dword ptr [0x9eaa40]
// 0044ef7e  8bc6                 mov eax, esi
// 0044ef80  5e                   pop esi
// 0044ef81  83c408               add esp, 8
// 0044ef84  c20800               ret 8
// library atl-9.0/atl.cpp (function _AtlUnRegisterTypeLib@8)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp

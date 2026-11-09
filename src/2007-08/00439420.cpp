// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 00439420  unit: CPropertyGridItemBrickColor  size: 414 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439420
//
// 00439420  6aff                 push -1
// 00439422  68836b7600           push 0x766b83
// 00439427  64a100000000         mov eax, dword ptr fs:[0]
// 0043942d  50                   push eax
// 0043942e  83ec14               sub esp, 0x14
// 00439431  53                   push ebx
// 00439432  55                   push ebp
// 00439433  56                   push esi
// 00439434  57                   push edi
// 00439435  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043943a  33c4                 xor eax, esp
// 0043943c  50                   push eax
// 0043943d  8d442428             lea eax, [esp + 0x28]
// 00439441  64a300000000         mov dword ptr fs:[0], eax
// 00439447  8bf1                 mov esi, ecx
// 00439449  8b442438             mov eax, dword ptr [esp + 0x38]
// 0043944d  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00439453  50                   push eax
// 00439454  6a05                 push 5
// 00439456  e895162600           call 0x69aaf0
// 0043945b  83f801               cmp eax, 1
// 0043945e  0f8444010000         je 0x4395a8
// 00439464  8b16                 mov edx, dword ptr [esi]
// 00439466  8b8290000000         mov eax, dword ptr [edx + 0x90]
// 0043946c  8bce                 mov ecx, esi
// 0043946e  ffd0                 call eax
// 00439470  85c0                 test eax, eax
// 00439472  0f8430010000         je 0x4395a8
// 00439478  8d4c2418             lea ecx, [esp + 0x18]
// 0043947c  51                   push ecx
// 0043947d  8bce                 mov ecx, esi
// 0043947f  e8acf32500           call 0x698830
// 00439484  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0043948a  8d542418             lea edx, [esp + 0x18]
// 0043948e  52                   push edx
// 0043948f  e87a6d1f00           call 0x63020e
// 00439494  8b442420             mov eax, dword ptr [esp + 0x20]
// 00439498  0562ffffff           add eax, 0xffffff62
// 0043949d  6a00                 push 0
// 0043949f  8944241c             mov dword ptr [esp + 0x1c], eax
// 004394a3  e828e42300           call 0x6778d0
// 004394a8  6878010000           push 0x178
// 004394ad  8be8                 mov ebp, eax
// 004394af  e8426a1f00           call 0x62fef6
// 004394b4  83c408               add esp, 8
// 004394b7  89442438             mov dword ptr [esp + 0x38], eax
// 004394bb  85c0                 test eax, eax
// 004394bd  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004394c5  740b                 je 0x4394d2
// 004394c7  8bc8                 mov ecx, eax
// 004394c9  e8e2340100           call 0x44c9b0
// 004394ce  8bf8                 mov edi, eax
// 004394d0  eb02                 jmp 0x4394d4
// 004394d2  33ff                 xor edi, edi
// 004394d4  8b8df8000000         mov ecx, dword ptr [ebp + 0xf8]
// 004394da  6a00                 push 0
// 004394dc  6aff                 push -1
// 004394de  6a00                 push 0
// 004394e0  6a00                 push 0
// 004394e2  57                   push edi
// 004394e3  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 004394eb  e8f03c2400           call 0x67d1e0
// 004394f0  8d4c2438             lea ecx, [esp + 0x38]
// 004394f4  51                   push ecx
// 004394f5  8bce                 mov ecx, esi
// 004394f7  e854f9ffff           call 0x438e50
// 004394fc  6854597800           push 0x785954
// 00439501  8bc8                 mov ecx, eax
// 00439503  c744243401000000     mov dword ptr [esp + 0x34], 1
// 0043950b  ff15b8dc7700         call dword ptr [0x77dcb8]
// 00439511  85c0                 test eax, eax
// 00439513  8d4c2438             lea ecx, [esp + 0x38]
// 00439517  0f95c3               setne bl
// 0043951a  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00439522  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00439528  84db                 test bl, bl
// 0043952a  7414                 je 0x439540
// 0043952c  8b16                 mov edx, dword ptr [esi]
// 0043952e  8b82e8000000         mov eax, dword ptr [edx + 0xe8]
// 00439534  8bce                 mov ecx, esi
// 00439536  ffd0                 call eax
// 00439538  50                   push eax
// 00439539  8bcf                 mov ecx, edi
// 0043953b  e870240100           call 0x44b9b0
// 00439540  e88b6e1f00           call 0x6303d0
// 00439545  85c0                 test eax, eax
// 00439547  740b                 je 0x439554
// 00439549  8b10                 mov edx, dword ptr [eax]
// 0043954b  8bc8                 mov ecx, eax
// 0043954d  8b427c               mov eax, dword ptr [edx + 0x7c]
// 00439550  ffd0                 call eax
// 00439552  eb02                 jmp 0x439556
// 00439554  33c0                 xor eax, eax
// 00439556  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043955a  8b542420             mov edx, dword ptr [esp + 0x20]
// 0043955e  6a00                 push 0
// 00439560  6a00                 push 0
// 00439562  50                   push eax
// 00439563  51                   push ecx
// 00439564  52                   push edx
// 00439565  6888000000           push 0x88
// 0043956a  55                   push ebp
// 0043956b  e860ad1f00           call 0x6342d0
// 00439570  83c41c               add esp, 0x1c
// 00439573  85c0                 test eax, eax
// 00439575  742a                 je 0x4395a1
// 00439577  80bf7001000000       cmp byte ptr [edi + 0x170], 0
// 0043957e  7421                 je 0x4395a1
// 00439580  8bcf                 mov ecx, edi
// 00439582  e819240100           call 0x44b9a0
// 00439587  51                   push ecx
// 00439588  8bcc                 mov ecx, esp
// 0043958a  89642418             mov dword ptr [esp + 0x18], esp
// 0043958e  50                   push eax
// 0043958f  51                   push ecx
// 00439590  e88bf3ffff           call 0x438920
// 00439595  8b16                 mov edx, dword ptr [esi]
// 00439597  8b4264               mov eax, dword ptr [edx + 0x64]
// 0043959a  83c408               add esp, 8
// 0043959d  8bce                 mov ecx, esi
// 0043959f  ffd0                 call eax
// 004395a1  8bcd                 mov ecx, ebp
// 004395a3  e83c6c1f00           call 0x6301e4
// 004395a8  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004395ac  64890d00000000       mov dword ptr fs:[0], ecx
// 004395b3  59                   pop ecx
// 004395b4  5f                   pop edi
// 004395b5  5e                   pop esi
// 004395b6  5d                   pop ebp
// 004395b7  5b                   pop ebx
// 004395b8  83c420               add esp, 0x20
// 004395bb  c20400               ret 4

// from server: 100% by user
// roc 2008-06 004382b0  unit: CPropertyGridItemBrickColor  size: 402 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004382b0
//
// 004382b0  6aff                 push -1
// 004382b2  64a100000000         mov eax, dword ptr fs:[0]
// 004382b8  68c3037c00           push 0x7c03c3
// 004382bd  50                   push eax
// 004382be  64892500000000       mov dword ptr fs:[0], esp
// 004382c5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004382c9  83ec14               sub esp, 0x14
// 004382cc  53                   push ebx
// 004382cd  55                   push ebp
// 004382ce  56                   push esi
// 004382cf  57                   push edi
// 004382d0  8bf1                 mov esi, ecx
// 004382d2  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 004382d8  50                   push eax
// 004382d9  6a05                 push 5
// 004382db  e820be2d00           call 0x714100
// 004382e0  83f801               cmp eax, 1
// 004382e3  0f8444010000         je 0x43842d
// 004382e9  8b16                 mov edx, dword ptr [esi]
// 004382eb  8b8290000000         mov eax, dword ptr [edx + 0x90]
// 004382f1  8bce                 mov ecx, esi
// 004382f3  ffd0                 call eax
// 004382f5  85c0                 test eax, eax
// 004382f7  0f8430010000         je 0x43842d
// 004382fd  8d4c2414             lea ecx, [esp + 0x14]
// 00438301  51                   push ecx
// 00438302  8bce                 mov ecx, esi
// 00438304  e8e7982d00           call 0x711bf0
// 00438309  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0043830f  8d542414             lea edx, [esp + 0x14]
// 00438313  52                   push edx
// 00438314  e819892600           call 0x6a0c32
// 00438319  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043831d  0562ffffff           add eax, 0xffffff62
// 00438322  6a00                 push 0
// 00438324  89442418             mov dword ptr [esp + 0x18], eax
// 00438328  e8f3632b00           call 0x6ee720
// 0043832d  6884010000           push 0x184
// 00438332  8be8                 mov ebp, eax
// 00438334  e8e7852600           call 0x6a0920
// 00438339  83c408               add esp, 8
// 0043833c  89442434             mov dword ptr [esp + 0x34], eax
// 00438340  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00438348  85c0                 test eax, eax
// 0043834a  740b                 je 0x438357
// 0043834c  8bc8                 mov ecx, eax
// 0043834e  e80d690100           call 0x44ec60
// 00438353  8bf8                 mov edi, eax
// 00438355  eb02                 jmp 0x438359
// 00438357  33ff                 xor edi, edi
// 00438359  8b8dfc000000         mov ecx, dword ptr [ebp + 0xfc]
// 0043835f  6a00                 push 0
// 00438361  6aff                 push -1
// 00438363  6a00                 push 0
// 00438365  6a00                 push 0
// 00438367  57                   push edi
// 00438368  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 00438370  e85bc52b00           call 0x6f48d0
// 00438375  8d4c2434             lea ecx, [esp + 0x34]
// 00438379  51                   push ecx
// 0043837a  8bce                 mov ecx, esi
// 0043837c  e84ffbffff           call 0x437ed0
// 00438381  6816b78000           push 0x80b716
// 00438386  8bc8                 mov ecx, eax
// 00438388  c744243001000000     mov dword ptr [esp + 0x30], 1
// 00438390  ff15f02f8000         call dword ptr [0x802ff0]
// 00438396  85c0                 test eax, eax
// 00438398  8d4c2434             lea ecx, [esp + 0x34]
// 0043839c  0f95c3               setne bl
// 0043839f  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004383a7  ff15143f8000         call dword ptr [0x803f14]
// 004383ad  84db                 test bl, bl
// 004383af  7414                 je 0x4383c5
// 004383b1  8b16                 mov edx, dword ptr [esi]
// 004383b3  8b82e8000000         mov eax, dword ptr [edx + 0xe8]
// 004383b9  8bce                 mov ecx, esi
// 004383bb  ffd0                 call eax
// 004383bd  50                   push eax
// 004383be  8bcf                 mov ecx, edi
// 004383c0  e84b5a0100           call 0x44de10
// 004383c5  e8848a2600           call 0x6a0e4e
// 004383ca  85c0                 test eax, eax
// 004383cc  740b                 je 0x4383d9
// 004383ce  8b10                 mov edx, dword ptr [eax]
// 004383d0  8bc8                 mov ecx, eax
// 004383d2  8b427c               mov eax, dword ptr [edx + 0x7c]
// 004383d5  ffd0                 call eax
// 004383d7  eb02                 jmp 0x4383db
// 004383d9  33c0                 xor eax, eax
// 004383db  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004383df  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004383e3  6a00                 push 0
// 004383e5  6a00                 push 0
// 004383e7  50                   push eax
// 004383e8  51                   push ecx
// 004383e9  52                   push edx
// 004383ea  6888000000           push 0x88
// 004383ef  55                   push ebp
// 004383f0  e8bbcb2600           call 0x6a4fb0
// 004383f5  83c41c               add esp, 0x1c
// 004383f8  85c0                 test eax, eax
// 004383fa  742a                 je 0x438426
// 004383fc  80bf7c01000000       cmp byte ptr [edi + 0x17c], 0
// 00438403  7421                 je 0x438426
// 00438405  8bcf                 mov ecx, edi
// 00438407  e8f4590100           call 0x44de00
// 0043840c  51                   push ecx
// 0043840d  8bcc                 mov ecx, esp
// 0043840f  89642414             mov dword ptr [esp + 0x14], esp
// 00438413  50                   push eax
// 00438414  51                   push ecx
// 00438415  e806f6ffff           call 0x437a20
// 0043841a  8b16                 mov edx, dword ptr [esi]
// 0043841c  8b4264               mov eax, dword ptr [edx + 0x64]
// 0043841f  83c408               add esp, 8
// 00438422  8bce                 mov ecx, esi
// 00438424  ffd0                 call eax
// 00438426  8bcd                 mov ecx, ebp
// 00438428  e8b7872600           call 0x6a0be4
// 0043842d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00438431  5f                   pop edi
// 00438432  5e                   pop esi
// 00438433  5d                   pop ebp
// 00438434  64890d00000000       mov dword ptr fs:[0], ecx
// 0043843b  5b                   pop ebx
// 0043843c  83c420               add esp, 0x20
// 0043843f  c20400               ret 4

// from server: 99% by colin
// roc 2008-06 004382b0  unit: CPropertyGridItemBrickColor  size: 402 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004382b0
//
// 004382b0  6aff                 push -1
// 004382b2  64a100000000         mov eax, dword ptr fs:[0]
// 004382b8  68c3037c00           push 0x7c03c3
// 004382bd  50                   push eax
// 004382be  64892500000000       mov dword ptr fs:[0], esp
// 004382c5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004382c9  83ec14               sub esp, 0x14
// 004382cc  53                   push ebx
// 004382cd  55                   push ebp
// 004382ce  56                   push esi
// 004382cf  57                   push edi
// 004382d0  8bf1                 mov esi, ecx
// 004382d2  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 004382d8  50                   push eax
// 004382d9  6a05                 push 5
// 004382db  e820be2d00           call 0x714100
// 004382e0  83f801               cmp eax, 1
// 004382e3  0f8444010000         je 0x43842d
// 004382e9  8b16                 mov edx, dword ptr [esi]
// 004382eb  8b8290000000         mov eax, dword ptr [edx + 0x90]
// 004382f1  8bce                 mov ecx, esi
// 004382f3  ffd0                 call eax
// 004382f5  85c0                 test eax, eax
// 004382f7  0f8430010000         je 0x43842d
// 004382fd  8d4c2414             lea ecx, [esp + 0x14]
// 00438301  51                   push ecx
// 00438302  8bce                 mov ecx, esi
// 00438304  e8e7982d00           call 0x711bf0
// 00438309  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0043830f  8d542414             lea edx, [esp + 0x14]
// 00438313  52                   push edx
// 00438314  e819892600           call 0x6a0c32
// 00438319  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043831d  0562ffffff           add eax, 0xffffff62
// 00438322  6a00                 push 0
// 00438324  89442418             mov dword ptr [esp + 0x18], eax
// 00438328  e8f3632b00           call 0x6ee720
// 0043832d  6884010000           push 0x184
// 00438332  8be8                 mov ebp, eax
// 00438334  e8e7852600           call 0x6a0920
// 00438339  83c408               add esp, 8
// 0043833c  89442434             mov dword ptr [esp + 0x34], eax
// 00438340  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00438348  85c0                 test eax, eax
// 0043834a  740b                 je 0x438357
// 0043834c  8bc8                 mov ecx, eax
// 0043834e  e80d690100           call 0x44ec60
// 00438353  8bf8                 mov edi, eax
// 00438355  eb02                 jmp 0x438359
// 00438357  33ff                 xor edi, edi
// 00438359  8b8dfc000000         mov ecx, dword ptr [ebp + 0xfc]
// 0043835f  6a00                 push 0
// 00438361  6aff                 push -1
// 00438363  6a00                 push 0
// 00438365  6a00                 push 0
// 00438367  57                   push edi
// 00438368  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 00438370  e85bc52b00           call 0x6f48d0
// 00438375  8d4c2434             lea ecx, [esp + 0x34]
// 00438379  51                   push ecx
// 0043837a  8bce                 mov ecx, esi
// 0043837c  e84ffbffff           call 0x437ed0
// 00438381  6816b78000           push 0x80b716
// 00438386  8bc8                 mov ecx, eax
// 00438388  c744243001000000     mov dword ptr [esp + 0x30], 1
// 00438390  ff15f02f8000         call dword ptr [0x802ff0]
// 00438396  85c0                 test eax, eax
// 00438398  8d4c2434             lea ecx, [esp + 0x34]
// 0043839c  0f95c3               setne bl
// 0043839f  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004383a7  ff15143f8000         call dword ptr [0x803f14]
// 004383ad  84db                 test bl, bl
// 004383af  7414                 je 0x4383c5
// 004383b1  8b16                 mov edx, dword ptr [esi]
// 004383b3  8b82e8000000         mov eax, dword ptr [edx + 0xe8]
// 004383b9  8bce                 mov ecx, esi
// 004383bb  ffd0                 call eax
// 004383bd  50                   push eax
// 004383be  8bcf                 mov ecx, edi
// 004383c0  e84b5a0100           call 0x44de10
// 004383c5  e8848a2600           call 0x6a0e4e
// 004383ca  85c0                 test eax, eax
// 004383cc  740b                 je 0x4383d9
// 004383ce  8b10                 mov edx, dword ptr [eax]
// 004383d0  8bc8                 mov ecx, eax
// 004383d2  8b427c               mov eax, dword ptr [edx + 0x7c]
// 004383d5  ffd0                 call eax
// 004383d7  eb02                 jmp 0x4383db
// 004383d9  33c0                 xor eax, eax
// 004383db  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004383df  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004383e3  6a00                 push 0
// 004383e5  6a00                 push 0
// 004383e7  50                   push eax
// 004383e8  51                   push ecx
// 004383e9  52                   push edx
// 004383ea  6888000000           push 0x88
// 004383ef  55                   push ebp
// 004383f0  e8bbcb2600           call 0x6a4fb0
// 004383f5  83c41c               add esp, 0x1c
// 004383f8  85c0                 test eax, eax
// 004383fa  742a                 je 0x438426
// 004383fc  80bf7c01000000       cmp byte ptr [edi + 0x17c], 0
// 00438403  7421                 je 0x438426
// 00438405  8bcf                 mov ecx, edi
// 00438407  e8f4590100           call 0x44de00
// 0043840c  51                   push ecx
// 0043840d  8bcc                 mov ecx, esp
// 0043840f  89642414             mov dword ptr [esp + 0x14], esp
// 00438413  50                   push eax
// 00438414  51                   push ecx
// 00438415  e806f6ffff           call 0x437a20
// 0043841a  8b16                 mov edx, dword ptr [esi]
// 0043841c  8b4264               mov eax, dword ptr [edx + 0x64]
// 0043841f  83c408               add esp, 8
// 00438422  8bce                 mov ecx, esi
// 00438424  ffd0                 call eax
// 00438426  8bcd                 mov ecx, ebp
// 00438428  e8b7872600           call 0x6a0be4
// 0043842d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00438431  5f                   pop edi
// 00438432  5e                   pop esi
// 00438433  5d                   pop ebp
// 00438434  64890d00000000       mov dword ptr fs:[0], ecx
// 0043843b  5b                   pop ebx
// 0043843c  83c420               add esp, 0x20
// 0043843f  c20400               ret 4

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Str {
    int words[8];
};

extern int (__thiscall* string_compare)(Str*, const char*);
extern void (__thiscall* string_destroy)(Str*);

struct StringTemporary {
    int storage;
    operator Str*();
    ~StringTemporary();
};

inline StringTemporary::operator Str*()
{
    return reinterpret_cast<Str*>(this);
}

inline StringTemporary::~StringTemporary()
{
    string_destroy(reinterpret_cast<Str*>(this));
}

struct Rect {
    int left, top, right, bottom;
};

struct Value {
    int data;
    Value(int);
    Value(const Value&);
    ~Value();
};

extern Value __cdecl make_value(int);

struct Grid {
    int notify(int, int);
    void convert_rect(Rect*);
};

struct Popup {
    char padding[0x170];
    unsigned char accepted;
    char padding2[3];
    int color;

    Popup();
    void set_color(int);
    int get_color();
};

struct Manager {
    void attach(Popup*, int, int, int, int);
};

struct Owner {
    char padding[0xf8];
    Manager* manager;
    void release();
};

struct Window {
    void** table;
};

extern Owner* __cdecl get_owner(int);
extern Window* __cdecl get_window();
extern int __cdecl show_popup(Owner*, int, int, int, int, int, int);

struct Item {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void set_value(Value);

    char padding[0xb0];
    Grid* grid;

    void get_rect(Rect*);
    StringTemporary copy();
    void activate(int);
};

void Item::activate(int argument)
{
    if (grid->notify(5, argument) == 1)
        return;

    if (!reinterpret_cast<int (__thiscall*)(Item*)>(
            (*reinterpret_cast<void***>(this))[0x90 / 4])(this))
        return;

    Rect rect;
    get_rect(&rect);
    grid->convert_rect(&rect);
    rect.left = rect.right - 158;

    Owner* owner = get_owner(0);
    Popup* popup = new Popup;
    owner->manager->attach(popup, 0, 0, -1, 0);

    bool authoring = string_compare(copy(), "") != 0;

    if (authoring)
        popup->set_color(
            reinterpret_cast<int (__thiscall*)(Item*)>(
                (*reinterpret_cast<void***>(this))[0xe8 / 4])(this));

    Window* window = get_window();
    int handle = window
        ? reinterpret_cast<int (__thiscall*)(Window*)>(
            window->table[0x7c / 4])(window)
        : 0;

    if (show_popup(owner, 0x88, rect.right, rect.bottom, handle, 0, 0)
        && popup->accepted)
    {
        int color = popup->get_color();
        reinterpret_cast<void (__thiscall*)(Item*, Value)>(
            (*reinterpret_cast<void***>(this))[0x64 / 4])(this, make_value(color));
    }

    owner->release();
}

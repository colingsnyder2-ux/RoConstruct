// from server: 100% by EspClaude
// from server: 72% by EspClaude
// roc 2007-08 00447870  unit: VCRenderSettings::?$FactoryProduct  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00447870
//
// 00447870  6aff                 push -1
// 00447872  68f1f87300           push 0x73f8f1
// 00447877  64a100000000         mov eax, dword ptr fs:[0]
// 0044787d  50                   push eax
// 0044787e  83ec20               sub esp, 0x20
// 00447881  56                   push esi
// 00447882  a188518b00           mov eax, dword ptr [0x8b5188]
// 00447887  33c4                 xor eax, esp
// 00447889  50                   push eax
// 0044788a  8d442428             lea eax, [esp + 0x28]
// 0044788e  64a300000000         mov dword ptr fs:[0], eax
// 00447894  8bf1                 mov esi, ecx
// 00447896  89742408             mov dword ptr [esp + 8], esi
// 0044789a  e851fdffff           call 0x4475f0
// 0044789f  684cfa7800           push 0x78fa4c
// 004478a4  8d4c2410             lea ecx, [esp + 0x10]
// 004478a8  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004478b0  c70634007900         mov dword ptr [esi], 0x790034
// 004478b6  c7460428007900       mov dword ptr [esi + 4], 0x790028
// 004478bd  c7461020007900       mov dword ptr [esi + 0x10], 0x790020
// 004478c4  c7461410007900       mov dword ptr [esi + 0x14], 0x790010
// 004478cb  c7462c00007900       mov dword ptr [esi + 0x2c], 0x790000
// 004478d2  c74644f0ff7800       mov dword ptr [esi + 0x44], 0x78fff0
// 004478d9  c7465ce0ff7800       mov dword ptr [esi + 0x5c], 0x78ffe0
// 004478e0  c74674d0ff7800       mov dword ptr [esi + 0x74], 0x78ffd0
// 004478e7  c7868c000000c0ff7800 mov dword ptr [esi + 0x8c], 0x78ffc0
// 004478f1  ff1598e67700         call dword ptr [0x77e698]
// 004478f7  8d44240c             lea eax, [esp + 0xc]
// 004478fb  50                   push eax
// 004478fc  8bce                 mov ecx, esi
// 004478fe  c644243401           mov byte ptr [esp + 0x34], 1
// 00447903  e8e8a20f00           call 0x541bf0
// 00447908  8d4c240c             lea ecx, [esp + 0xc]
// 0044790c  c644243000           mov byte ptr [esp + 0x30], 0
// 00447911  ff15ace67700         call dword ptr [0x77e6ac]
// 00447917  8935a4af8b00         mov dword ptr [0x8bafa4], esi
// 0044791d  8bc6                 mov eax, esi
// 0044791f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00447923  64890d00000000       mov dword ptr fs:[0], ecx
// 0044792a  59                   pop ecx
// 0044792b  5e                   pop esi
// 0044792c  83c42c               add esp, 0x2c
// 0044792f  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 00448120  unit: VCRenderSettings::?$FactoryProduct  size: 255 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00448120
//
// 00448120  6aff                 push -1
// 00448122  687a0f7c00           push 0x7c0f7a
// 00448127  64a100000000         mov eax, dword ptr fs:[0]
// 0044812d  50                   push eax
// 0044812e  64892500000000       mov dword ptr fs:[0], esp
// 00448135  83ec48               sub esp, 0x48
// 00448138  56                   push esi
// 00448139  8bf1                 mov esi, ecx
// 0044813b  89742404             mov dword ptr [esp + 4], esi
// 0044813f  e8fcfeffff           call 0x448040
// 00448144  68d45b8100           push 0x815bd4
// 00448149  8d4c240c             lea ecx, [esp + 0xc]
// 0044814d  c744245800000000     mov dword ptr [esp + 0x58], 0
// 00448155  c706845e8100         mov dword ptr [esi], 0x815e84
// 0044815b  c74610785e8100       mov dword ptr [esi + 0x10], 0x815e78
// 00448162  c74614705e8100       mov dword ptr [esi + 0x14], 0x815e70
// 00448169  c74620685e8100       mov dword ptr [esi + 0x20], 0x815e68
// 00448170  c74624585e8100       mov dword ptr [esi + 0x24], 0x815e58
// 00448177  c74644485e8100       mov dword ptr [esi + 0x44], 0x815e48
// 0044817e  c74664385e8100       mov dword ptr [esi + 0x64], 0x815e38
// 00448185  c78684000000285e8100 mov dword ptr [esi + 0x84], 0x815e28
// 0044818f  c786a4000000185e8100 mov dword ptr [esi + 0xa4], 0x815e18
// 00448199  c786c4000000085e8100 mov dword ptr [esi + 0xc4], 0x815e08
// 004481a3  ff1558248000         call dword ptr [0x802458]
// 004481a9  8d442408             lea eax, [esp + 8]
// 004481ad  50                   push eax
// 004481ae  8bce                 mov ecx, esi
// 004481b0  c644245801           mov byte ptr [esp + 0x58], 1
// 004481b5  e8d62d1100           call 0x55af90
// 004481ba  8d4c2408             lea ecx, [esp + 8]
// 004481be  c644245400           mov byte ptr [esp + 0x54], 0
// 004481c3  ff1568248000         call dword ptr [0x802468]
// 004481c9  833deccb960000       cmp dword ptr [0x96cbec], 0
// 004481d0  7435                 je 0x448207
// 004481d2  68d45b8100           push 0x815bd4
// 004481d7  8d4c240c             lea ecx, [esp + 0xc]
// 004481db  68c4c78000           push 0x80c7c4
// 004481e0  51                   push ecx
// 004481e1  e82a190c00           call 0x509b10
// 004481e6  83c40c               add esp, 0xc
// 004481e9  50                   push eax
// 004481ea  8d4c2428             lea ecx, [esp + 0x28]
// 004481ee  c644245802           mov byte ptr [esp + 0x58], 2
// 004481f3  e8581bfcff           call 0x409d50
// 004481f8  68c81b8d00           push 0x8d1bc8
// 004481fd  8d542428             lea edx, [esp + 0x28]
// 00448201  52                   push edx
// 00448202  e885932500           call 0x6a158c
// 00448207  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0044820b  8935eccb9600         mov dword ptr [0x96cbec], esi
// 00448211  8bc6                 mov eax, esi
// 00448213  5e                   pop esi
// 00448214  64890d00000000       mov dword ptr fs:[0], ecx
// 0044821b  83c454               add esp, 0x54
// 0044821e  c3                   ret 

struct String;
extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String(const char* text) { stringConstruct(this, text); }
    ~String() { stringDestroy(this); }
};

extern String __cdecl format(const char*, ...);

struct Exception {
    char storage[40];
    Exception(const String&);
    Exception(const Exception&);
    ~Exception();
};

struct Base {
    unsigned long storage[36];
    Base();
    ~Base();
    void setValue(const String&);
};

struct S : Base {
    S();
};

extern S* singleton;
extern unsigned char table0[], table4[], table10[], table14[], table2c[];
extern unsigned char table44[], table5c[], table74[], table8c[];

S::S()
{
    storage[0] = reinterpret_cast<unsigned long>(table0);
    storage[1] = reinterpret_cast<unsigned long>(table4);
    storage[4] = reinterpret_cast<unsigned long>(table10);
    storage[5] = reinterpret_cast<unsigned long>(table14);
    storage[11] = reinterpret_cast<unsigned long>(table2c);
    storage[17] = reinterpret_cast<unsigned long>(table44);
    storage[23] = reinterpret_cast<unsigned long>(table5c);
    storage[29] = reinterpret_cast<unsigned long>(table74);
    storage[35] = reinterpret_cast<unsigned long>(table8c);

    setValue(String("RenderSettings"));

    singleton = this;
}

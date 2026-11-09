// from server: 72% by EspClaude
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
    unsigned long storage[75];
    Base();
    ~Base();
    void setValue(const String&);
};

struct S : Base {
    S();
};

extern S* singleton;
extern unsigned char table0[], table10[], table14[], table20[], table24[];
extern unsigned char table44[], table64[], table84[], tableA4[], tableC4[];

S::S()
{
    storage[0] = reinterpret_cast<unsigned long>(table0);
    storage[4] = reinterpret_cast<unsigned long>(table10);
    storage[5] = reinterpret_cast<unsigned long>(table14);
    storage[8] = reinterpret_cast<unsigned long>(table20);
    storage[9] = reinterpret_cast<unsigned long>(table24);
    storage[17] = reinterpret_cast<unsigned long>(table44);
    storage[25] = reinterpret_cast<unsigned long>(table64);
    storage[33] = reinterpret_cast<unsigned long>(table84);
    storage[41] = reinterpret_cast<unsigned long>(tableA4);
    storage[49] = reinterpret_cast<unsigned long>(tableC4);

    setValue(String("RenderSettings"));

    if (singleton)
        throw Exception(format("singleton %s already exists", "RenderSettings"));

    singleton = this;
}

// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 81% by king_originala
// roc 2008-06 00632070  unit: RBX::VBodyThrust::?$FactoryProduct  size: 224 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00632070
//
// 00632070  6aff                 push -1
// 00632072  68a89d7d00           push 0x7d9da8
// 00632077  64a100000000         mov eax, dword ptr fs:[0]
// 0063207d  50                   push eax
// 0063207e  64892500000000       mov dword ptr fs:[0], esp
// 00632085  51                   push ecx
// 00632086  56                   push esi
// 00632087  8bf1                 mov esi, ecx
// 00632089  6808c79500           push 0x95c708
// 0063208e  89742408             mov dword ptr [esp + 8], esi
// 00632092  e8c9f6ffff           call 0x631760
// 00632097  d905e87a8400         fld dword ptr [0x847ae8]
// 0063209d  d99e48010000         fstp dword ptr [esi + 0x148]
// 006320a3  c706a47a8400         mov dword ptr [esi], 0x847aa4
// 006320a9  d905987a8400         fld dword ptr [0x847a98]
// 006320af  c74610907a8400       mov dword ptr [esi + 0x10], 0x847a90
// 006320b6  d99e4c010000         fstp dword ptr [esi + 0x14c]
// 006320bc  c74614887a8400       mov dword ptr [esi + 0x14], 0x847a88
// 006320c3  d905807a8400         fld dword ptr [0x847a80]
// 006320c9  c746207c7a8400       mov dword ptr [esi + 0x20], 0x847a7c
// 006320d0  c746246c7a8400       mov dword ptr [esi + 0x24], 0x847a6c
// 006320d7  c746445c7a8400       mov dword ptr [esi + 0x44], 0x847a5c
// 006320de  c746644c7a8400       mov dword ptr [esi + 0x64], 0x847a4c
// 006320e5  c786840000003c7a8400 mov dword ptr [esi + 0x84], 0x847a3c
// 006320ef  c786a40000002c7a8400 mov dword ptr [esi + 0xa4], 0x847a2c
// 006320f9  c786c40000001c7a8400 mov dword ptr [esi + 0xc4], 0x847a1c
// 00632103  c78630010000007a8400 mov dword ptr [esi + 0x130], 0x847a00
// 0063210d  c78638010000f4798400 mov dword ptr [esi + 0x138], 0x8479f4
// 00632117  d99650010000         fst dword ptr [esi + 0x150]
// 0063211d  d9ee                 fldz 
// 0063211f  8d8e5c010000         lea ecx, [esi + 0x15c]
// 00632125  d99e54010000         fstp dword ptr [esi + 0x154]
// 0063212b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00632133  d99e58010000         fstp dword ptr [esi + 0x158]
// 00632139  e89261e4ff           call 0x4782d0
// 0063213e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00632142  8bc6                 mov eax, esi
// 00632144  5e                   pop esi
// 00632145  64890d00000000       mov dword ptr fs:[0], ecx
// 0063214c  83c410               add esp, 0x10
// 0063214f  c3                   ret 

extern const char name_95C708[];
extern const float value_847AE8;
extern const float value_847A98;
extern const float value_847A80;

extern const unsigned long table_847AA4[];
extern const unsigned long table_847A90[];
extern const unsigned long table_847A88[];
extern const unsigned long table_847A7C[];
extern const unsigned long table_847A6C[];
extern const unsigned long table_847A5C[];
extern const unsigned long table_847A4C[];
extern const unsigned long table_847A3C[];
extern const unsigned long table_847A2C[];
extern const unsigned long table_847A1C[];
extern const unsigned long table_847A00[];
extern const unsigned long table_8479F4[];

struct Base {
    const unsigned long *p00;
    char pad04[12];
    const unsigned long *p10;
    const unsigned long *p14;
    char pad18[8];
    const unsigned long *p20;
    const unsigned long *p24;
    char pad28[28];
    const unsigned long *p44;
    char pad48[28];
    const unsigned long *p64;
    char pad68[28];
    const unsigned long *p84;
    char pad88[28];
    const unsigned long *pA4;
    char padA8[28];
    const unsigned long *pC4;
    char padC8[104];
    const unsigned long *p130;
    char pad134[4];
    const unsigned long *p138;
    char pad13C[12];

    Base(const char *);
    ~Base();
};

struct NameItem {
    NameItem();
};

struct S : Base {
    volatile float f148;
    volatile float f14C;
    volatile float f150;
    volatile float f154;
    volatile float f158;
    NameItem item;

    S();
};

S::S()
    : Base(name_95C708),
      f148(3000.0f),
      f14C((p00 = table_847AA4,
            p10 = table_847A90,
            500.0f)),
      f150((p14 = table_847A88,
            p20 = table_847A7C,
            p24 = table_847A6C,
            p44 = table_847A5C,
            p64 = table_847A4C,
            p84 = table_847A3C,
            pA4 = table_847A2C,
            pC4 = table_847A1C,
            p130 = table_847A00,
            p138 = table_8479F4,
            400000.0f)),
      f154(0.0f),
      f158(400000.0f),
      item()
{
}


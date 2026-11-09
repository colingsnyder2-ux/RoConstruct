// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 82% by colin
// roc 2008-06 00632b50  unit: RBX::VRocket::?$FactoryProduct  size: 281 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00632b50
//
// 00632b50  56                   push esi
// 00632b51  6840c79500           push 0x95c740
// 00632b56  8bf1                 mov esi, ecx
// 00632b58  e803ffffff           call 0x632a60
// 00632b5d  d9ee                 fldz 
// 00632b5f  c7066c818400         mov dword ptr [esi], 0x84816c
// 00632b65  c746105c818400       mov dword ptr [esi + 0x10], 0x84815c
// 00632b6c  c7461454818400       mov dword ptr [esi + 0x14], 0x848154
// 00632b73  c746204c818400       mov dword ptr [esi + 0x20], 0x84814c
// 00632b7a  c746243c818400       mov dword ptr [esi + 0x24], 0x84813c
// 00632b81  c746442c818400       mov dword ptr [esi + 0x44], 0x84812c
// 00632b88  c746641c818400       mov dword ptr [esi + 0x64], 0x84811c
// 00632b8f  c786840000000c818400 mov dword ptr [esi + 0x84], 0x84810c
// 00632b99  c786a4000000fc808400 mov dword ptr [esi + 0xa4], 0x8480fc
// 00632ba3  c786c4000000ec808400 mov dword ptr [esi + 0xc4], 0x8480ec
// 00632bad  c78630010000d0808400 mov dword ptr [esi + 0x130], 0x8480d0
// 00632bb7  c78638010000c4808400 mov dword ptr [esi + 0x138], 0x8480c4
// 00632bc1  33c0                 xor eax, eax
// 00632bc3  888648010000         mov byte ptr [esi + 0x148], al
// 00632bc9  d99654010000         fst dword ptr [esi + 0x154]
// 00632bcf  d99658010000         fst dword ptr [esi + 0x158]
// 00632bd5  89864c010000         mov dword ptr [esi + 0x14c], eax
// 00632bdb  d9965c010000         fst dword ptr [esi + 0x15c]
// 00632be1  898650010000         mov dword ptr [esi + 0x150], eax
// 00632be7  d9056c6e8200         fld dword ptr [0x826e6c]
// 00632bed  888664010000         mov byte ptr [esi + 0x164], al
// 00632bf3  d99e60010000         fstp dword ptr [esi + 0x160]
// 00632bf9  8bc6                 mov eax, esi
// 00632bfb  d9057c7b8400         fld dword ptr [0x847b7c]
// 00632c01  d99e68010000         fstp dword ptr [esi + 0x168]
// 00632c07  d905bccc8100         fld dword ptr [0x81ccbc]
// 00632c0d  d99e6c010000         fstp dword ptr [esi + 0x16c]
// 00632c13  d9059c838100         fld dword ptr [0x81839c]
// 00632c19  d99e70010000         fstp dword ptr [esi + 0x170]
// 00632c1f  d905884d8700         fld dword ptr [0x874d88]
// 00632c25  d99e74010000         fstp dword ptr [esi + 0x174]
// 00632c2b  d905e87a8400         fld dword ptr [0x847ae8]
// 00632c31  d99e78010000         fstp dword ptr [esi + 0x178]
// 00632c37  d905987a8400         fld dword ptr [0x847a98]
// 00632c3d  d99e7c010000         fstp dword ptr [esi + 0x17c]
// 00632c43  d905807a8400         fld dword ptr [0x847a80]
// 00632c49  d99680010000         fst dword ptr [esi + 0x180]
// 00632c4f  d99e84010000         fstp dword ptr [esi + 0x184]
// 00632c55  d99e88010000         fstp dword ptr [esi + 0x188]
// 00632c5b  d905b8888200         fld dword ptr [0x8288b8]
// 00632c61  d99e8c010000         fstp dword ptr [esi + 0x18c]
// 00632c67  5e                   pop esi
// 00632c68  c3                   ret 

extern unsigned char table0[], table10[], table14[], table20[];
extern unsigned char table24[], table44[], table64[], table84[];
extern unsigned char tableA4[], tableC4[], table130[], table138[];
extern const float value160, value168, value16C, value170;
extern const float value174, value178, value17C, value180, value18C;

extern const char className[];
struct S {
    void* t0;
    unsigned char pad04[12];
    void* t10;
    void* t14;
    unsigned char pad18[8];
    void* t20;
    void* t24;
    unsigned char pad28[28];
    void* t44;
    unsigned char pad48[28];
    void* t64;
    unsigned char pad68[28];
    void* t84;
    unsigned char pad88[28];
    void* tA4;
    unsigned char padA8[28];
    void* tC4;
    unsigned char padC8[104];
    void* t130;
    unsigned char pad134[4];
    void* t138;
    unsigned char pad13C[12];
    unsigned char flag148;
    unsigned char pad149[3];
    unsigned int field14C;
    unsigned int field150;
    volatile float field154, field158, field15C, field160;
    unsigned char flag164;
    unsigned char pad165[3];
    volatile float field168, field16C, field170, field174;
    volatile float field178, field17C, field180, field184, field188, field18C;

    unsigned int base(const char*);
    S* init();
};

S* S::init()
{
    base(className);
    t0 = table0;
    t10 = table10;
    t14 = table14;
    t20 = table20;
    t24 = table24;
    t44 = table44;
    t64 = table64;
    t84 = table84;
    tA4 = tableA4;
    tC4 = tableC4;
    t130 = table130;
    t138 = table138;
    flag148 = 0;
    field154 = 0.0f;
    field158 = 0.0f;
    field14C = 0;
    field15C = 0.0f;
    field150 = 0;
    flag164 = 0;
    field160 = 4.0f;
    field168 = value168;
    field16C = value16C;
    field170 = value170;
    field174 = value174;
    field178 = value178;
    field17C = value17C;
    field180 = 400000.0f;
    field184 = 400000.0f;
    field188 = 0.0f;
    field18C = value18C;
    return this;
}

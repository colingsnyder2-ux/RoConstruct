// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_toolhandleobjectab350bf3d281f133.cpp

// Candidate translation unit (score above; library headers required).
// from server: 90% by king_originala
// roc 2008-06 00600240  unit: RBX::VTool::?$BoundPropGetSet  size: 475 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00600240
//
// 00600240  6aff                 push -1
// 00600242  68d3807d00           push 0x7d80d3
// 00600247  64a100000000         mov eax, dword ptr fs:[0]
// 0060024d  50                   push eax
// 0060024e  64892500000000       mov dword ptr fs:[0], esp
// 00600255  83ec20               sub esp, 0x20
// 00600258  53                   push ebx
// 00600259  56                   push esi
// 0060025a  33db                 xor ebx, ebx
// 0060025c  8bf1                 mov esi, ecx
// 0060025e  57                   push edi
// 0060025f  8974240c             mov dword ptr [esp + 0xc], esi
// 00600263  395c243c             cmp dword ptr [esp + 0x3c], ebx
// 00600267  740a                 je 0x600273
// 00600269  c786c0010000e03d8400 mov dword ptr [esi + 0x1c0], 0x843de0
// 00600273  e838feffff           call 0x6000b0
// 00600278  8dbea0010000         lea edi, [esi + 0x1a0]
// 0060027e  8bcf                 mov ecx, edi
// 00600280  895c2434             mov dword ptr [esp + 0x34], ebx
// 00600284  e8378d0200           call 0x628fc0
// 00600289  83c8ff               or eax, 0xffffffff
// 0060028c  8986b4010000         mov dword ptr [esi + 0x1b4], eax
// 00600292  8986b8010000         mov dword ptr [esi + 0x1b8], eax
// 00600298  899ebc010000         mov dword ptr [esi + 0x1bc], ebx
// 0060029e  8b86c0010000         mov eax, dword ptr [esi + 0x1c0]
// 006002a4  c7064c1a8400         mov dword ptr [esi], 0x841a4c
// 006002aa  c746103c1a8400       mov dword ptr [esi + 0x10], 0x841a3c
// 006002b1  c74614341a8400       mov dword ptr [esi + 0x14], 0x841a34
// 006002b8  c746202c1a8400       mov dword ptr [esi + 0x20], 0x841a2c
// 006002bf  c746241c1a8400       mov dword ptr [esi + 0x24], 0x841a1c
// 006002c6  c746440c1a8400       mov dword ptr [esi + 0x44], 0x841a0c
// 006002cd  c74664fc198400       mov dword ptr [esi + 0x64], 0x8419fc
// 006002d4  c78684000000ec198400 mov dword ptr [esi + 0x84], 0x8419ec
// 006002de  c786a4000000dc198400 mov dword ptr [esi + 0xa4], 0x8419dc
// 006002e8  c786c4000000cc198400 mov dword ptr [esi + 0xc4], 0x8419cc
// 006002f2  c78630010000c4198400 mov dword ptr [esi + 0x130], 0x8419c4
// 006002fc  c707bc198400         mov dword ptr [edi], 0x8419bc
// 00600302  c786b0010000a4198400 mov dword ptr [esi + 0x1b0], 0x8419a4
// 0060030c  8b4804               mov ecx, dword ptr [eax + 4]
// 0060030f  c78431c00100009c198400 mov dword ptr [ecx + esi + 0x1c0], 0x84199c
// 0060031a  8b96c0010000         mov edx, dword ptr [esi + 0x1c0]
// 00600320  8b4204               mov eax, dword ptr [edx + 4]
// 00600323  8d8854ffffff         lea ecx, [eax - 0xac]
// 00600329  898c30bc010000       mov dword ptr [eax + esi + 0x1bc], ecx
// 00600330  8d8ecc010000         lea ecx, [esi + 0x1cc]
// 00600336  c644243402           mov byte ptr [esp + 0x34], 2
// 0060033b  899ec4010000         mov dword ptr [esi + 0x1c4], ebx
// 00600341  899ec8010000         mov dword ptr [esi + 0x1c8], ebx
// 00600347  e8847fe7ff           call 0x4782d0
// 0060034c  c686fc01000001       mov byte ptr [esi + 0x1fc], 1
// 00600353  899e00020000         mov dword ptr [esi + 0x200], ebx
// 00600359  899e08020000         mov dword ptr [esi + 0x208], ebx
// 0060035f  899e0c020000         mov dword ptr [esi + 0x20c], ebx
// 00600365  889e10020000         mov byte ptr [esi + 0x210], bl
// 0060036b  889e14020000         mov byte ptr [esi + 0x214], bl
// 00600371  899e1c020000         mov dword ptr [esi + 0x21c], ebx
// 00600377  899e20020000         mov dword ptr [esi + 0x220], ebx
// 0060037d  889e24020000         mov byte ptr [esi + 0x224], bl
// 00600383  889e28020000         mov byte ptr [esi + 0x228], bl
// 00600389  899e30020000         mov dword ptr [esi + 0x230], ebx
// 0060038f  899e34020000         mov dword ptr [esi + 0x234], ebx
// 00600395  889e38020000         mov byte ptr [esi + 0x238], bl
// 0060039b  889e3c020000         mov byte ptr [esi + 0x23c], bl
// 006003a1  899e44020000         mov dword ptr [esi + 0x244], ebx
// 006003a7  899e48020000         mov dword ptr [esi + 0x248], ebx
// 006003ad  889e4c020000         mov byte ptr [esi + 0x24c], bl
// 006003b3  889e50020000         mov byte ptr [esi + 0x250], bl
// 006003b9  899e58020000         mov dword ptr [esi + 0x258], ebx
// 006003bf  899e5c020000         mov dword ptr [esi + 0x25c], ebx
// 006003c5  889e60020000         mov byte ptr [esi + 0x260], bl
// 006003cb  889e64020000         mov byte ptr [esi + 0x264], bl
// 006003d1  b307                 mov bl, 7
// 006003d3  68d0168400           push 0x8416d0
// 006003d8  8d4c2414             lea ecx, [esp + 0x14]
// 006003dc  885c2438             mov byte ptr [esp + 0x38], bl
// 006003e0  ff1558248000         call dword ptr [0x802458]
// 006003e6  8d542410             lea edx, [esp + 0x10]
// 006003ea  52                   push edx
// 006003eb  8bce                 mov ecx, esi
// 006003ed  c644243808           mov byte ptr [esp + 0x38], 8
// 006003f2  e899abf5ff           call 0x55af90
// 006003f7  8d4c2410             lea ecx, [esp + 0x10]
// 006003fb  885c2434             mov byte ptr [esp + 0x34], bl
// 006003ff  ff1568248000         call dword ptr [0x802468]
// 00600405  5f                   pop edi
// 00600406  8bc6                 mov eax, esi
// 00600408  5e                   pop esi
// 00600409  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060040d  5b                   pop ebx
// 0060040e  64890d00000000       mov dword ptr fs:[0], ecx
// 00600415  83c42c               add esp, 0x2c
// 00600418  c20400               ret 4

struct String;
typedef void (__thiscall *StringConstruct)(String *, const char *);
typedef void (__thiscall *StringDestroy)(String *);
extern StringConstruct stringConstruct;
extern StringDestroy stringDestroy;

struct String {
    unsigned char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text) { stringConstruct(this, text); }
inline String::~String() { stringDestroy(this); }

struct Base {
    unsigned char data[0x1a0];
    Base(int, unsigned long **);
    void initialize();
    ~Base();
    void setName(const String &);
};

inline Base::Base(int complete, unsigned long **table)
{
    if (complete)
        *table = reinterpret_cast<unsigned long *>(0x843de0);
    initialize();
}

struct Vector {
    unsigned long data[4];
    Vector();
    ~Vector();
};

struct Secondary {
    unsigned long value;
    int first,second,third;
    Secondary():first(-1),second(-1),third(0) {}
    ~Secondary();
};

struct Name {
    unsigned char data[48];
    Name();
};

struct Group {
    unsigned long unused;
    unsigned long first;
    unsigned long second;
    unsigned char flag;
    unsigned char padding[3];
    unsigned char other;
    unsigned char padding2[3];
    Group():first(0),second(0),flag(0),other(0) {}
    ~Group();
};

struct S : Base {
    Vector vector;
    Secondary secondary;
    unsigned long *table;
    unsigned long a;
    unsigned long b;
    Name name;
    unsigned char enabled;
    unsigned char padding[3];
    unsigned long value;
    Group group0;
    Group group1;
    Group group2;
    Group group3;
    Group group4;

    void fixOffset() {unsigned offset=table[1]; *(unsigned long*)((char*)this+0x1bc+offset)=offset-0xac;}
    S(int);
    ~S();
};

S::S(int complete)
    : Base(complete, &table), vector(),
      a((
          *reinterpret_cast<unsigned long *>(data) = 0x841a4c,
          *reinterpret_cast<unsigned long *>(data + 0x10) = 0x841a3c,
          *reinterpret_cast<unsigned long *>(data + 0x14) = 0x841a34,
          *reinterpret_cast<unsigned long *>(data + 0x20) = 0x841a2c,
          *reinterpret_cast<unsigned long *>(data + 0x24) = 0x841a1c,
          *reinterpret_cast<unsigned long *>(data + 0x44) = 0x841a0c,
          *reinterpret_cast<unsigned long *>(data + 0x64) = 0x8419fc,
          *reinterpret_cast<unsigned long *>(data + 0x84) = 0x8419ec,
          *reinterpret_cast<unsigned long *>(data + 0xa4) = 0x8419dc,
          *reinterpret_cast<unsigned long *>(data + 0xc4) = 0x8419cc,
          *reinterpret_cast<unsigned long *>(data + 0x130) = 0x8419c4,
          vector.data[0] = 0x8419bc,
          secondary.value = 0x8419a4,
          *reinterpret_cast<unsigned long *>(
              reinterpret_cast<unsigned char *>(this) + 0x1c0 + table[1]) = 0x84199c,
          fixOffset(),
          0)),
      b(0), enabled(1), value(0)
{


    String text("Tool");
    setName(text);
}

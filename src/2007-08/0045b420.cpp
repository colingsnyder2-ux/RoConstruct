// from server: 100% by EspClaude
// from server: 74% by EspClaude
// roc 2007-08 0045b420  unit: CRobloxWnd::RenderStatsItem  size: 467 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045b420
//
// 0045b420  55                   push ebp
// 0045b421  8bec                 mov ebp, esp
// 0045b423  83e4c0               and esp, 0xffffffc0
// 0045b426  6aff                 push -1
// 0045b428  6809247400           push 0x742409
// 0045b42d  64a100000000         mov eax, dword ptr fs:[0]
// 0045b433  50                   push eax
// 0045b434  83ec70               sub esp, 0x70
// 0045b437  56                   push esi
// 0045b438  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045b43d  33c4                 xor eax, esp
// 0045b43f  50                   push eax
// 0045b440  8d442478             lea eax, [esp + 0x78]
// 0045b444  64a300000000         mov dword ptr fs:[0], eax
// 0045b44a  8bf1                 mov esi, ecx
// 0045b44c  8b0ddcfb8b00         mov ecx, dword ptr [0x8bfbdc]
// 0045b452  85c9                 test ecx, ecx
// 0045b454  894c2420             mov dword ptr [esp + 0x20], ecx
// 0045b458  7553                 jne 0x45b4ad
// 0045b45a  687c3c7900           push 0x793c7c
// 0045b45f  8d4c242c             lea ecx, [esp + 0x2c]
// 0045b463  ff1598e67700         call dword ptr [0x77e698]
// 0045b469  d9ee                 fldz 
// 0045b46b  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0045b471  dd98e8000000         fstp qword ptr [eax + 0xe8]
// 0045b477  8d4c2428             lea ecx, [esp + 0x28]
// 0045b47b  51                   push ecx
// 0045b47c  8d88f0000000         lea ecx, [eax + 0xf0]
// 0045b482  c784248400000000000000 mov dword ptr [esp + 0x84], 0
// 0045b48d  ff1590e67700         call dword ptr [0x77e690]
// 0045b493  8d4c2428             lea ecx, [esp + 0x28]
// 0045b497  c7842480000000ffffffff mov dword ptr [esp + 0x80], 0xffffffff
// 0045b4a2  ff15ace67700         call dword ptr [0x77e6ac]
// 0045b4a8  e994000000           jmp 0x45b541
// 0045b4ad  a1e4fb8b00           mov eax, dword ptr [0x8bfbe4]
// 0045b4b2  83ec10               sub esp, 0x10
// 0045b4b5  85c0                 test eax, eax
// 0045b4b7  751f                 jne 0x45b4d8
// 0045b4b9  d9e8                 fld1 
// 0045b4bb  8b9610010000         mov edx, dword ptr [esi + 0x110]
// 0045b4c1  dd5c2408             fstp qword ptr [esp + 8]
// 0045b4c5  d9ee                 fldz 
// 0045b4c7  dd1424               fst qword ptr [esp]
// 0045b4ca  686c3c7900           push 0x793c6c
// 0045b4cf  83ec08               sub esp, 8
// 0045b4d2  dd1c24               fstp qword ptr [esp]
// 0045b4d5  52                   push edx
// 0045b4d6  eb61                 jmp 0x45b539
// 0045b4d8  2b05e0fb8b00         sub eax, dword ptr [0x8bfbe0]
// 0045b4de  db442430             fild dword ptr [esp + 0x30]
// 0045b4e2  03c1                 add eax, ecx
// 0045b4e4  d95c2434             fstp dword ptr [esp + 0x34]
// 0045b4e8  89442430             mov dword ptr [esp + 0x30], eax
// 0045b4ec  db442430             fild dword ptr [esp + 0x30]
// 0045b4f0  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0045b4f6  d95c2430             fstp dword ptr [esp + 0x30]
// 0045b4fa  d9442434             fld dword ptr [esp + 0x34]
// 0045b4fe  d9c0                 fld st(0)
// 0045b500  d9442430             fld dword ptr [esp + 0x30]
// 0045b504  d9c0                 fld st(0)
// 0045b506  deea                 fsubp st(2)
// 0045b508  d9c2                 fld st(2)
// 0045b50a  dc2598317900         fsub qword ptr [0x793198]
// 0045b510  defa                 fdivp st(2)
// 0045b512  d9c9                 fxch st(1)
// 0045b514  d95c2434             fstp dword ptr [esp + 0x34]
// 0045b518  def9                 fdivp st(1)
// 0045b51a  dd5c2408             fstp qword ptr [esp + 8]
// 0045b51e  d9442434             fld dword ptr [esp + 0x34]
// 0045b522  dd05e8fe7800         fld qword ptr [0x78fee8]
// 0045b528  d8c9                 fmul st(1)
// 0045b52a  dd1c24               fstp qword ptr [esp]
// 0045b52d  686c3c7900           push 0x793c6c
// 0045b532  83ec08               sub esp, 8
// 0045b535  dd1c24               fstp qword ptr [esp]
// 0045b538  50                   push eax
// 0045b539  e8a2b51300           call 0x596ae0
// 0045b53e  83c420               add esp, 0x20
// 0045b541  8b8628010000         mov eax, dword ptr [esi + 0x128]
// 0045b547  8b9010020000         mov edx, dword ptr [eax + 0x210]
// 0045b54d  8b8814020000         mov ecx, dword ptr [eax + 0x214]
// 0045b553  8b8620010000         mov eax, dword ptr [esi + 0x120]
// 0045b559  52                   push edx
// 0045b55a  51                   push ecx
// 0045b55b  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0045b55f  db44242c             fild dword ptr [esp + 0x2c]
// 0045b563  68643c7900           push 0x793c64
// 0045b568  83ec08               sub esp, 8
// 0045b56b  dd1c24               fstp qword ptr [esp]
// 0045b56e  50                   push eax
// 0045b56f  e86cb51300           call 0x596ae0
// 0045b574  8b8628010000         mov eax, dword ptr [esi + 0x128]
// 0045b57a  8b9018020000         mov edx, dword ptr [eax + 0x218]
// 0045b580  8b881c020000         mov ecx, dword ptr [eax + 0x21c]
// 0045b586  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 0045b58c  83c418               add esp, 0x18
// 0045b58f  52                   push edx
// 0045b590  51                   push ecx
// 0045b591  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0045b595  db44242c             fild dword ptr [esp + 0x2c]
// 0045b599  68643c7900           push 0x793c64
// 0045b59e  83ec08               sub esp, 8
// 0045b5a1  dd1c24               fstp qword ptr [esp]
// 0045b5a4  50                   push eax
// 0045b5a5  e836b51300           call 0x596ae0
// 0045b5aa  8b0d28d08b00         mov ecx, dword ptr [0x8bd028]
// 0045b5b0  83c418               add esp, 0x18
// 0045b5b3  51                   push ecx
// 0045b5b4  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 0045b5ba  e8a1b41300           call 0x596a60
// 0045b5bf  8b15b4d08b00         mov edx, dword ptr [0x8bd0b4]
// 0045b5c5  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0045b5cb  52                   push edx
// 0045b5cc  e88fb41300           call 0x596a60
// 0045b5d1  e8aa790100           call 0x472f80
// 0045b5d6  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 0045b5dc  50                   push eax
// 0045b5dd  e87eb41300           call 0x596a60
// 0045b5e2  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0045b5e6  64890d00000000       mov dword ptr fs:[0], ecx
// 0045b5ed  59                   pop ecx
// 0045b5ee  5e                   pop esi
// 0045b5ef  8be5                 mov esp, ebp
// 0045b5f1  5d                   pop ebp
// 0045b5f2  c3                   ret 

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
struct String;
extern void (__thiscall *constructString)(String *, const char *);
extern void (__thiscall *destroyString)(String *);
extern String *(__thiscall *assignString)(String *, const String *);

struct String {
    int storage[7];
    String(const char *);
    ~String();
    String &operator=(const String &);
};

__forceinline String::String(const char *s) {
    constructString(this, s);
}

__forceinline String::~String() {
    destroyString(this);
}

__forceinline String &String::operator=(const String &s) {
    return *assignString(this, &s);
}

struct Item {
    char padding[0xe8];
    double value;
    String text;
    void setValue(unsigned int);
};

struct Statistics {
    char padding[0x210];
    int firstLimit;
    int firstCount;
    int secondLimit;
    int secondCount;
};

extern int profileCount;
extern int profileBegin;
extern int profileEnd;
extern unsigned int firstValue;
extern unsigned int secondValue;
extern unsigned int __cdecl getValue();
extern void __cdecl formatItem(Item *, double, const char *, ...);

struct S {
    char padding[0x110];
    Item *profile;
    Item *first;
    Item *second;
    Item *third;
    Item *firstStats;
    Item *secondStats;
    Statistics *stats;
    void RenderStatsItem();
};

void S::RenderStatsItem() {
    __declspec(align(64)) int workspace[16];
    int count = profileCount;

    if (!count) {
        String text("n/a");
        Item *item = profile;
        item->value = 0.0;
        item->text = text;
    } else {
        int total = profileEnd;
        if (!total) {
            formatItem(profile, 0.0, "%.0f%%, %.2g", 0.0, 1.0);
        } else {
            total -= profileBegin;
            float samples = float(count);
            count = total + count;
            float elapsed = float(count);
            float ratio = (samples - elapsed) / (samples - 1.0f);
            formatItem(profile, ratio, "%.0f%%, %.2g",
                       100.0f * ratio, samples / elapsed);
        }
    }

    formatItem(firstStats, double(stats->firstCount), "%d/%d",
               stats->firstCount, stats->firstLimit);
    formatItem(secondStats, double(stats->secondCount), "%d/%d",
               stats->secondCount, stats->secondLimit);
    first->setValue(firstValue);
    second->setValue(secondValue);
    third->setValue(getValue());
}

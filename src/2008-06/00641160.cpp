// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 00641160  unit: RBX::AxisMoveTool  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00641160
//
// 00641160  64a100000000         mov eax, dword ptr fs:[0]
// 00641166  6aff                 push -1
// 00641168  6809e77c00           push 0x7ce709
// 0064116d  50                   push eax
// 0064116e  64892500000000       mov dword ptr fs:[0], esp
// 00641175  83ec28               sub esp, 0x28
// 00641178  56                   push esi
// 00641179  57                   push edi
// 0064117a  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0064117e  57                   push edi
// 0064117f  8bf1                 mov esi, ecx
// 00641181  e8fa4ffdff           call 0x616180
// 00641186  8a4614               mov al, byte ptr [esi + 0x14]
// 00641189  84c0                 test al, al
// 0064118b  7421                 je 0x6411ae
// 0064118d  68603a8400           push 0x843a60
// 00641192  8d4e24               lea ecx, [esi + 0x24]
// 00641195  ff154c248000         call dword ptr [0x80244c]
// 0064119b  5f                   pop edi
// 0064119c  5e                   pop esi
// 0064119d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006411a1  64890d00000000       mov dword ptr fs:[0], ecx
// 006411a8  83c434               add esp, 0x34
// 006411ab  c20400               ret 4
// 006411ae  d9ee                 fldz 
// 006411b0  8d442440             lea eax, [esp + 0x40]
// 006411b4  50                   push eax
// 006411b5  d954240c             fst dword ptr [esp + 0xc]
// 006411b9  8d4c240c             lea ecx, [esp + 0xc]
// 006411bd  d9542410             fst dword ptr [esp + 0x10]
// 006411c1  51                   push ecx
// 006411c2  d95c2418             fstp dword ptr [esp + 0x18]
// 006411c6  57                   push edi
// 006411c7  8bce                 mov ecx, esi
// 006411c9  e882fbffff           call 0x640d50
// 006411ce  84c0                 test al, al
// 006411d0  7421                 je 0x6411f3
// 006411d2  68e8a38400           push 0x84a3e8
// 006411d7  8d4e24               lea ecx, [esi + 0x24]
// 006411da  ff154c248000         call dword ptr [0x80244c]
// 006411e0  5f                   pop edi
// 006411e1  5e                   pop esi
// 006411e2  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006411e6  64890d00000000       mov dword ptr fs:[0], ecx
// 006411ed  83c434               add esp, 0x34
// 006411f0  c20400               ret 4
// 006411f3  8d542414             lea edx, [esp + 0x14]
// 006411f7  52                   push edx
// 006411f8  8bce                 mov ecx, esi
// 006411fa  e8a14ffdff           call 0x6161a0
// 006411ff  50                   push eax
// 00641200  8d4e24               lea ecx, [esi + 0x24]
// 00641203  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0064120b  ff150c248000         call dword ptr [0x80240c]
// 00641211  8d4c2414             lea ecx, [esp + 0x14]
// 00641215  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0064121d  ff1568248000         call dword ptr [0x802468]
// 00641223  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00641227  5f                   pop edi
// 00641228  5e                   pop esi
// 00641229  64890d00000000       mov dword ptr fs:[0], ecx
// 00641230  83c434               add esp, 0x34
// 00641233  c20400               ret 4

struct Text;

extern void (__thiscall *textDestroy)(Text*);
extern Text& (__thiscall *textAssignText)(Text*, const Text&);
extern Text& (__thiscall *textAssignChars)(Text*, const char*);

struct Text {
    char storage[28];

    ~Text();
    Text& operator=(const Text&);
    Text& operator=(const char*);
};

inline Text::~Text() {
    textDestroy(this);
}

inline Text& Text::operator=(const Text& value) {
    return textAssignText(this, value);
}

inline Text& Text::operator=(const char* value) {
    return textAssignChars(this, value);
}

struct Vector {
    float x, y, z;
};

struct S {
    char padding0[0x14];
    volatile bool dragging;
    char padding1[0x0f];
    Text cursor;

    void update(const void*);
    void prepare(const void*);
    bool hitTest(const void*, Vector&, const void**);
    Text defaultCursor();
};

void S::update(const void* volatile argument) {
    const void* original = argument;
    prepare(original);

    bool d = dragging;
    if (d) {
        cursor = "DragCursor";
        return;
    }

    Vector position;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;

    if (hitTest(original, position, const_cast<const void**>(&argument))) {
        cursor = "ResizeCursor";
        return;
    }

    cursor = defaultCursor();
}

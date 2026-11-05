// from server: 81% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-cl: 21022
// from server: 100% by king_originala
// roc 2008-06 00614200  unit: RBX::RevoluteLink  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00614200
//
// 00614200  83ec4c               sub esp, 0x4c
// 00614203  807c245000           cmp byte ptr [esp + 0x50], 0
// 00614208  53                   push ebx
// 00614209  8bd9                 mov ebx, ecx
// 0061420b  c744240400000000     mov dword ptr [esp + 4], 0
// 00614213  7415                 je 0x61422a
// 00614215  807b3000             cmp byte ptr [ebx + 0x30], 0
// 00614219  740f                 je 0x61422a
// 0061421b  8b4b2c               mov ecx, dword ptr [ebx + 0x2c]
// 0061421e  e85dfcffff           call 0x613e80
// 00614223  5b                   pop ebx
// 00614224  83c44c               add esp, 0x4c
// 00614227  c20400               ret 4
// 0061422a  8b4b2c               mov ecx, dword ptr [ebx + 0x2c]
// 0061422d  e87e4d0400           call 0x658fb0
// 00614232  837b2800             cmp dword ptr [ebx + 0x28], 0
// 00614236  7508                 jne 0x614240
// 00614238  8b432c               mov eax, dword ptr [ebx + 0x2c]
// 0061423b  83c00c               add eax, 0xc
// 0061423e  eb0d                 jmp 0x61424d
// 00614240  8b4b2c               mov ecx, dword ptr [ebx + 0x2c]
// 00614243  8d442408             lea eax, [esp + 8]
// 00614247  50                   push eax
// 00614248  e8534a0400           call 0x658ca0
// 0061424d  8d9394000000         lea edx, [ebx + 0x94]
// 00614253  56                   push esi
// 00614254  57                   push edi
// 00614255  8bf0                 mov esi, eax
// 00614257  b909000000           mov ecx, 9
// 0061425c  8bfa                 mov edi, edx
// 0061425e  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00614260  d94024               fld dword ptr [eax + 0x24]
// 00614263  d95a24               fstp dword ptr [edx + 0x24]
// 00614266  d94028               fld dword ptr [eax + 0x28]
// 00614269  d95a28               fstp dword ptr [edx + 0x28]
// 0061426c  d9402c               fld dword ptr [eax + 0x2c]
// 0061426f  d95a2c               fstp dword ptr [edx + 0x2c]
// 00614272  d94030               fld dword ptr [eax + 0x30]
// 00614275  d95a30               fstp dword ptr [edx + 0x30]
// 00614278  d94034               fld dword ptr [eax + 0x34]
// 0061427b  d95a34               fstp dword ptr [edx + 0x34]
// 0061427e  d94038               fld dword ptr [eax + 0x38]
// 00614281  d95a38               fstp dword ptr [edx + 0x38]
// 00614284  5f                   pop edi
// 00614285  d9403c               fld dword ptr [eax + 0x3c]
// 00614288  5e                   pop esi
// 00614289  d95a3c               fstp dword ptr [edx + 0x3c]
// 0061428c  d94040               fld dword ptr [eax + 0x40]
// 0061428f  d95a40               fstp dword ptr [edx + 0x40]
// 00614292  d94044               fld dword ptr [eax + 0x44]
// 00614295  a198a89500           mov eax, dword ptr [0x95a898]
// 0061429a  40                   inc eax
// 0061429b  d95a44               fstp dword ptr [edx + 0x44]
// 0061429e  a398a89500           mov dword ptr [0x95a898], eax
// 006142a3  3dffffff7f           cmp eax, 0x7fffffff
// 006142a8  750a                 jne 0x6142b4
// 006142aa  b801000000           mov eax, 1
// 006142af  a398a89500           mov dword ptr [0x95a898], eax
// 006142b4  898390000000         mov dword ptr [ebx + 0x90], eax
// 006142ba  5b                   pop ebx
// 006142bb  83c44c               add esp, 0x4c
// 006142be  c20400               ret 4

struct Matrix {
    float elements[9];
};

struct Transform {
    Matrix rotation;
    float x0, y0, z0;
    float x1, y1, z1;
    float x2, y2, z2;

    Transform& operator=(const Transform& value);
};

inline Transform& Transform::operator=(const Transform& value)
{
    rotation = value.rotation;
    x0 = value.x0;
    y0 = value.y0;
    z0 = value.z0;
    x1 = value.x1;
    y1 = value.y1;
    z1 = value.z1;
    x2 = value.x2;
    y2 = value.y2;
    z2 = value.z2;
    return *this;
}

struct Source {
    char padding[12];
    Transform transform;

    void fastUpdate();
    void update();
    Transform* calculate(Transform* result);
};

static int generation;

struct Link {
    char padding0[0x28];
    int mode;
    Source* source;
    bool enabled;
    char padding1[0x5f];
    int stamp;
    Transform transform;

    void refresh(bool fast);
};

void Link::refresh(bool fast)
{
    volatile int unused = 0;
    Transform temporary;

    if (fast && enabled) {
        source->fastUpdate();
        return;
    }

    source->update();

    const Transform* value;
    if (mode == 0)
        value = &source->transform;
    else
        value = source->calculate(&temporary);

    transform = *value;

    int next = ++generation;
    if (next == 0x7fffffff)
        generation = next = 1;
    stamp = next;
}

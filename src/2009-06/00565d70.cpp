// from server: 86% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005023e0  unit: G3D::Sphere  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005023e0
//
// 005023e0  55                   push ebp
// 005023e1  8bec                 mov ebp, esp
// 005023e3  83e4c0               and esp, 0xffffffc0
// 005023e6  83ec34               sub esp, 0x34
// 005023e9  53                   push ebx
// 005023ea  56                   push esi
// 005023eb  57                   push edi
// 005023ec  8b7d08               mov edi, dword ptr [ebp + 8]
// 005023ef  8bf1                 mov esi, ecx
// 005023f1  6a03                 push 3
// 005023f3  8bcf                 mov ecx, edi
// 005023f5  8974243c             mov dword ptr [esp + 0x3c], esi
// 005023f9  e89249f7ff           call 0x476d90
// 005023fe  6a02                 push 2
// 00502400  bb01000000           mov ebx, 1
// 00502405  53                   push ebx
// 00502406  6a00                 push 0
// 00502408  8bcf                 mov ecx, edi
// 0050240a  e8e150f7ff           call 0x4774f0
// 0050240f  015f78               add dword ptr [edi + 0x78], ebx
// 00502412  80bfe103000000       cmp byte ptr [edi + 0x3e1], 0
// 00502419  7412                 je 0x50242d
// 0050241b  015f70               add dword ptr [edi + 0x70], ebx
// 0050241e  6a00                 push 0
// 00502420  ff15f0298000         call dword ptr [0x8029f0]
// 00502426  c687e103000000       mov byte ptr [edi + 0x3e1], 0
// 0050242d  83be9002000000       cmp dword ptr [esi + 0x290], 0
// 00502434  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0050243c  0f8eab000000         jle 0x5024ed
// 00502442  8d9fa8040000         lea ebx, [edi + 0x4a8]
// 00502448  eb08                 jmp 0x502452
// 0050244a  8d9b00000000         lea ebx, [ebx]
// 00502450  8bf1                 mov esi, ecx
// 00502452  8b868c020000         mov eax, dword ptr [esi + 0x28c]
// 00502458  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0050245c  8b3488               mov esi, dword ptr [eax + ecx*4]
// 0050245f  8b5634               mov edx, dword ptr [esi + 0x34]
// 00502462  56                   push esi
// 00502463  8bcf                 mov ecx, edi
// 00502465  89542438             mov dword ptr [esp + 0x38], edx
// 00502469  e87253f7ff           call 0x4777e0
// 0050246e  d94638               fld dword ptr [esi + 0x38]
// 00502471  83ec08               sub esp, 8
// 00502474  8bcf                 mov ecx, edi
// 00502476  dd1c24               fstp qword ptr [esp]
// 00502479  e86258f7ff           call 0x477ce0
// 0050247e  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00502481  8b01                 mov eax, dword ptr [ecx]
// 00502483  8b502c               mov edx, dword ptr [eax + 0x2c]
// 00502486  57                   push edi
// 00502487  ffd2                 call edx
// 00502489  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0050248d  8b01                 mov eax, dword ptr [ecx]
// 0050248f  8b5028               mov edx, dword ptr [eax + 0x28]
// 00502492  ffd2                 call edx
// 00502494  d9e8                 fld1 
// 00502496  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0050249a  dee1                 fsubrp st(1)
// 0050249c  8b01                 mov eax, dword ptr [ecx]
// 0050249e  8b5018               mov edx, dword ptr [eax + 0x18]
// 005024a1  d95c243c             fstp dword ptr [esp + 0x3c]
// 005024a5  ffd2                 call edx
// 005024a7  d900                 fld dword ptr [eax]
// 005024a9  53                   push ebx
// 005024aa  d94004               fld dword ptr [eax + 4]
// 005024ad  d94008               fld dword ptr [eax + 8]
// 005024b0  d9ca                 fxch st(2)
// 005024b2  d91b                 fstp dword ptr [ebx]
// 005024b4  d95b04               fstp dword ptr [ebx + 4]
// 005024b7  d95b08               fstp dword ptr [ebx + 8]
// 005024ba  d9442440             fld dword ptr [esp + 0x40]
// 005024be  d95b0c               fstp dword ptr [ebx + 0xc]
// 005024c1  ff15f4298000         call dword ptr [0x8029f4]
// 005024c7  8b463c               mov eax, dword ptr [esi + 0x3c]
// 005024ca  57                   push edi
// 005024cb  50                   push eax
// 005024cc  e80f6b0400           call 0x548fe0
// 005024d1  8b442438             mov eax, dword ptr [esp + 0x38]
// 005024d5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 005024d9  40                   inc eax
// 005024da  83c408               add esp, 8
// 005024dd  3b8190020000         cmp eax, dword ptr [ecx + 0x290]
// 005024e3  89442430             mov dword ptr [esp + 0x30], eax
// 005024e7  0f8c63ffffff         jl 0x502450
// 005024ed  5f                   pop edi
// 005024ee  5e                   pop esi
// 005024ef  5b                   pop ebx
// 005024f0  8be5                 mov esp, ebp
// 005024f2  5d                   pop ebp
// 005024f3  c20400               ret 4

extern "C" {
    extern void (__stdcall *glDepthMask)(unsigned char);
    extern void (__stdcall *glColor4fv)(const float*);
}

struct RenderDevice;
struct Entry;

struct Color3 {
    float r, g, b;
};

struct Color4 {
    float r, g, b, a;

    Color4(const Color3&, float);
    Color4& operator=(const Color4&);
};

#pragma float_control(precise, off, push)

inline Color4::Color4(const Color3& c, float alpha)
    : r(c.r), g(c.g), b(c.b), a(alpha)
{
}

inline Color4& Color4::operator=(const Color4& c)
{
    r = c.r;
    g = c.g;
    b = c.b;
    a = c.a;
    return *this;
}

struct Material {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual const Color3& color();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual float transparency();
    virtual void apply(RenderDevice*);
};

struct Entry {
    char padding[0x34];
    Material* material;
    float value;
    void* geometry;
};

struct RenderDevice {
    char padding0[0x70];
    int changes;
    char padding1[4];
    int stateChanges;
    char padding2[0x365];
    unsigned char depthWrite;
    char padding3[0xC6];
    Color4 rgba;

    void mode(int);
    void blend(int, int, int);
    void configure(Entry*);
    void parameter(double);
};

extern void __cdecl drawGeometry(void*, RenderDevice*);

struct Sphere {
    char padding[0x28C];
    Entry** entries;
    int count;

    void render(RenderDevice*);
};

void Sphere::render(RenderDevice* device)
{
    device->mode(3);
    device->blend(0, 1, 2);
    ++device->stateChanges;

    if (device->depthWrite) {
        ++device->changes;
        glDepthMask(0);
        device->depthWrite = 0;
    }

    for (int i = 0; i < count; ++i) {
        Entry* entry = entries[i];
        Material* material = entry->material;
        device->configure(entry);
        device->parameter(entry->value);
        entry->material->apply(device);

        float alpha = 1.0f - material->transparency();
        __declspec(align(64)) Color4 color(material->color(), alpha);
        device->rgba = color;
        glColor4fv(&device->rgba.r);
        drawGeometry(entry->geometry, device);
    }
}

#pragma float_control(pop)

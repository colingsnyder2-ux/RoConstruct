// from server: 100% by king_originala
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

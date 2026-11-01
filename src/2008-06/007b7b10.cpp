// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vec3 {
    float x, y, z;
};

struct Vec4 {
    float x, y, z, w;
    Vec4(const Vec3&, float);
    Vec4& operator=(const Vec4&);
};

__forceinline Vec4::Vec4(const Vec3& v, float a)
    : x(v.x), y(v.y), z(v.z), w(a)
{
}

__forceinline Vec4& Vec4::operator=(const Vec4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

struct Handle {
    void* p;
    Handle();
    Handle(const Handle&);
    ~Handle();
};

__forceinline Handle::~Handle()
{
}

struct Device {
    char padding[0x4a8];
    Vec4 color;

    void setFirst(float);
    void setSecond(float);
    void setHandle(int, Handle);
    void setMode(int, int);
};

extern "C" void (__stdcall *glColor3fv)(const float*);

struct Mode {
    virtual void slot0();
    virtual void slot1();
    virtual int value();
};

struct Level {
    virtual void slot0();
    virtual void slot1();
    virtual Handle getHandle(Device*);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual const Vec3& getColor();
    virtual float getFirst();
    virtual float getSecond();

    char padding[8];
    Mode* mode;

    void apply(Device*);
};

void Level::apply(Device* device)
{
    device->color = Vec4(getColor(), 1.0f);
    glColor3fv(&device->color.x);
    device->setFirst(getFirst());
    device->setSecond(getSecond());
    device->setHandle(0, getHandle(device));

    Mode* m = mode;
    if (m) {
        switch (m->value()) {
        case 0:
            device->setMode(0, 2);
            break;
        case 1:
            device->setMode(0, 4);
            break;
        case 2:
            device->setMode(0, 0);
            break;
        default:
            device->setMode(0, 4);
            break;
        }
    }
}

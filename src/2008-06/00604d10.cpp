// from server: 54% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Widget;

struct Pair {
    Widget* object;
    Control* control;

    Pair();
    Pair(const Pair&);
    ~Pair();
};

__forceinline Pair::Pair() : object(0), control(0)
{
}

__forceinline Pair::Pair(const Pair& p)
    : object(p.object), control(p.control)
{
    if (control)
        _InterlockedExchangeAdd(&control->strong, 1);
}

__forceinline Pair::~Pair()
{
    Control* p = control;
    if (p && _InterlockedExchangeAdd(&p->strong, -1) == 1) {
        p->dispose();
        if (_InterlockedExchangeAdd(&p->weak, -1) == 1)
            p->destroy();
    }
}

struct Children {
    char reserved[12];
    Pair* first;
    Pair* last;
};

struct Vector3 {
    float x, y, z;
};

struct Vector4 {
    float x, y, z, w;
};

extern float scale;
extern float width;
extern float height;

extern const Vector3& __cdecl defaultColor();
extern const Vector4& __cdecl defaultRectangle();
extern void __cdecl acquire(Pair*, void*);

struct Widget {
    char reserved0[0x108];
    Children* children;
    char reserved1[0x30];
    float sizeX;
    float sizeY;
    char reserved2[0x14];
    unsigned char dirty;
    char reserved3[7];
    int size;
    Vector4 color;
    Vector4 rectangle;

    void initialize();
    Pair f();
};

Pair Widget::f()
{
    Pair owner;
    acquire(&owner, reinterpret_cast<char*>(this) + 0xe4);

    {
        Pair argument(owner);
        argument.object->initialize();
    }

    unsigned int index = 0;
    while (owner.object->children &&
           index < static_cast<unsigned int>(
               owner.object->children->last -
               owner.object->children->first)) {
        Children* list = owner.object->children;
        if (index >= static_cast<unsigned int>(list->last - list->first))
            _invalid_parameter_noinfo();

        Widget* child = list->first[index].object;
        Pair value;
        acquire(&value, child ? reinterpret_cast<char*>(child) + 0xe4 : 0);

        Widget* object = value.object;
        int& size = object->size;
        size = 14;
        float n = static_cast<float>(size);
        object->sizeX = scale * n;
        object->sizeY = n + n;

        const Vector3& c = defaultColor();
        float red = c.x;
        float green = c.y;
        float blue = c.z;
        Vector4& color = value.object->color;
        color.x = red;
        color.y = green;
        color.z = blue;
        color.w = 1.0f;

        object = value.object;
        const Vector4& r = defaultRectangle();
        object->rectangle.x = r.x;
        object->rectangle.y = r.y;
        object->rectangle.z = r.z;
        object->rectangle.w = r.w;

        float* dimensions = &value.object->sizeX;
        dimensions[0] = width;
        dimensions[1] = height;

        ++index;
    }

    owner.object->dirty = 0;
    return Pair(owner);
}

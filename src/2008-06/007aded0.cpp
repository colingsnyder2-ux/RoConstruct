// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern unsigned char baseTypeDescriptor;
extern unsigned char proxyTypeDescriptor;

struct Base {
    virtual ~Base();
    unsigned char padding[0x34];
};

struct Ptr {
    Base* p;

    Ptr(Base*);
    Ptr(const Ptr&);
    ~Ptr();
    void assign(Base*);
};

inline Ptr::Ptr(Base* value) : p(0)
{
    assign(value);
}

struct Vector {
    float x, y, z;
};

struct TextureProxy : Base {
    unsigned int value;
    unsigned char padding3C[4];
    Ptr source;
    Ptr owner;
    Vector position;
    unsigned char padding54[12];

    TextureProxy(Ptr);
    Ptr clone(const Vector&, const Ptr&);
};

Ptr TextureProxy::clone(const Vector& positionValue, const Ptr& input)
{
    Base* object = *static_cast<Base* const volatile*>(&input.p);
    TextureProxy* other = static_cast<TextureProxy*>(
        __RTDynamicCast(object, 0, &baseTypeDescriptor,
                        &proxyTypeDescriptor, 0));
    TextureProxy* result = new TextureProxy(Ptr(other));

    *static_cast<volatile unsigned int*>(&result->value) = value;
    result->source.assign(other);
    result->position.x = positionValue.x;
    result->position.y = positionValue.y;
    result->position.z = positionValue.z;
    result->owner.assign(this);

    return Ptr(result);
}

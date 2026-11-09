// from server: 100% by king_originala
namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char pad[0x100];
        Instance* next;
    };

    class ServiceProvider : public Instance {
    public:
        ServiceProvider* finish();
    };
}

RBX::ServiceProvider* __cdecl func_00491e50(RBX::Instance*);

struct Matrix {
    float elements[9];
};

struct Transform {
    Matrix rotation;
    float x, y, z;

    bool different(const Transform&) const;
    __forceinline Transform& operator=(const Transform&);
};

__forceinline Transform& Transform::operator=(const Transform& value)
{
    rotation = value.rotation;
    x = value.x;
    y = value.y;
    z = value.z;
    return *this;
}

struct Flag {
    bool value;
};

struct Signal {
    void fire(Flag);
};

struct Attachment {
    void set(const Transform&);
};

struct S : RBX::Instance {
    char padding0[0x2c];
    Attachment* attachment;
    char padding1[0x20];
    Transform transform;

    void changed(const void*);
    void setTransform(const Transform&);
};

void S::setTransform(const Transform& value)
{
    Transform& destination = transform;
    if (value.different(destination)) {
        destination = value;

        RBX::ServiceProvider* provider = func_00491e50(this);
        if (provider) {
            Flag flag;
            flag.value = false;
            reinterpret_cast<Signal*>(
                reinterpret_cast<char*>(provider) + 0x344)->fire(flag);
        }

        changed(reinterpret_cast<const void*>(0x976d20));

        if (attachment)
            attachment->set(destination);
    }
}

// from server: 100% by king_originala
struct Matrix {
    float data[9];
};

struct Frame {
    Matrix rotation;
    float x, y, z;
    bool different(const Frame& other) const;
};

struct Receiver {
    void update(const Frame& value);
};

struct Boolean {
    bool value;
};

struct Event {
    void notify(Boolean value);
};

namespace RBX {
    struct Instance;
    struct ServiceProvider {
        char padding[0x344];
        Event event;
    };
}

extern RBX::ServiceProvider* func_00491e50(RBX::Instance*);
extern char property_0097b7a8;

struct Tool {
    char padding0[0x1a4];
    Receiver* receiver;
    char padding1[0x24];
    Frame frame;

    void propertyChanged(const void* property);
    void func_005ffb70(const Frame& value);
};

void Tool::func_005ffb70(const Frame& value)
{
    Frame& destination = frame;
    if (value.different(destination)) {
        destination.rotation = value.rotation;
        destination.x = value.x;
        destination.y = value.y;
        destination.z = value.z;

        RBX::ServiceProvider* provider =
            func_00491e50(reinterpret_cast<RBX::Instance*>(this));
        if (provider) {
            Boolean flag;
            flag.value = false;
            provider->event.notify(flag);
        }

        propertyChanged(&property_0097b7a8);
        if (receiver)
            receiver->update(destination);
    }
}

// from server: 100% by king_originala
struct Transform {
    float data[12];
};

struct Receiver {
    void apply(const Transform& value);
};

struct Body {
    unsigned char padding[0xA0];
    Receiver* receiver;
};

struct Joint {
    Transform calculate(Body* first, Body* second);
};

void __cdecl update(Body* first, Joint* joint, Body* second)
{
    Receiver* receiver = second->receiver;
    receiver->apply(joint->calculate(first, second));
}

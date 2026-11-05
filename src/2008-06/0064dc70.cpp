// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Receiver {
    void update(const Vector3*, const Vector3*);
};

struct Owner {
    char padding[0x2C];
    Receiver* receiver;
};

struct Link {
    char padding[0x10];
    Owner* owner;
};

struct Point {
    char padding0[0x0C];
    Link* link;
    char padding1[0x0C];
    Vector3 first;
    Vector3 second;

    void update();
};

void Point::update()
{
    Receiver* receiver = link->owner->receiver;
    if (receiver)
        receiver->update(&second, &first);
}

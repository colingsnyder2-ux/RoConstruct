// from server: 100% by king_originala
struct Vector2 {
    float x, y;
};

struct Vector2int16 {
    short x, y;
    void convert(const Vector2* source);
};

struct Receiver;
struct ReceiverVTable {
    void* unused[3];
    void (__thiscall* invoke)(Receiver*, void*, const Vector2int16*);
};

struct Receiver {
    ReceiverVTable* vtable;
};

struct Context {
    char padding[24];
    Receiver* receiver;
};

struct S {
    char padding[20];
    void f(const Vector2* points, Context* first, Context* second);
};

void S::f(const Vector2* points, Context* first, Context* second)
{
    {
        Vector2int16 value;
        value.convert(points);
        first->receiver->vtable->invoke(
            first->receiver,
            this ? reinterpret_cast<char*>(this) + 20 : 0,
            &value);
    }

    {
        Vector2int16 value;
        value.convert(points + 1);
        second->receiver->vtable->invoke(
            second->receiver,
            this ? reinterpret_cast<char*>(this) + 20 : 0,
            &value);
    }
}

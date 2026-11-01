// from server: 100% by king_originala
struct Base {
    char value;
};

struct Signal {
    void invoke(char* value);
};

struct Object {
    char padding[16];
    Signal signal;
};

struct Descriptor {
    Object* lookup(Base* value);
};

extern Descriptor descriptor;

struct Padding {
    char bytes[20];
};

struct S : Padding, Base {
    void f();
};

void S::f()
{
    char value;
    Object* object = descriptor.lookup(static_cast<Base*>(this));
    if (object)
        object->signal.invoke(&value);
}

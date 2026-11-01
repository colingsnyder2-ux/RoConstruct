// from server: 100% by king_originala
struct State {
    char data[20];
    void reset();
};

struct Object {
    void setFirst(int);
    void setSecond(int);
    void setThird(int);
};

struct Handle {
    Object* object;
    void* control;
    void reset();
};

extern "C" double __cdecl getTime();

struct S {
    char padding[0x3FC];
    State state;
    double timestamp;
    Handle handle;

    void update(bool enabled);
};

void S::update(bool enabled)
{
    if (!enabled) {
        state.reset();
        timestamp = getTime();
        if (handle.object) {
            handle.object->setFirst(0);
            handle.object->setSecond(0);
            handle.object->setThird(0);
            handle.reset();
        }
    }
}

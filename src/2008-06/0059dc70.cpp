// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Listener {
    void begin(void*);
    void end(void*);
};

struct S {
    char padding0[0x1e0];
    int mode;
    char padding1[0x44];
    char notification;

    Vector3 convert(const Vector3&);
    void apply(const Vector3&);
    void update();
    void f(const Vector3&);
};

extern void* __cdecl func_005a3390(S*);
extern const float scale1;
extern const float scale2;

void S::f(const Vector3& input)
{
    Listener* listener = static_cast<Listener*>(func_005a3390(this));
    if (listener)
        listener->begin(&notification);

    Vector3 value = { input.x, input.y, input.z };

    switch (mode) {
    case 1:
        value.y = *(const volatile float*)&input.y * scale1;
        break;
    case 2:
        value.y = *(const volatile float*)&input.y * scale2;
        break;
    }

    apply(convert(value));
    update();

    listener = static_cast<Listener*>(func_005a3390(this));
    if (listener)
        listener->end(&notification);
}

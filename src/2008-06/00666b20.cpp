// from server: 100% by king_originala
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

extern const float resetValue;

struct Signal {
    void fire(const float*, float);
};

struct Result {
    char padding[0x10];
    Signal signal;
};

struct Source {
    char padding[0x14];
    char data;
};

struct Lookup {
    Result* find(void*);
};

extern Lookup lookup;

struct Running {
    char padding0[0x0c];
    float value;
    char padding1[0xa8];
    float x;
    float y;
    float z;

    void update(float, int);
    void baseUpdate(float, int);
    bool shouldReset();
    bool shouldNotify();
    Source* source();
};

void Running::update(float dt, int argument)
{
    baseUpdate(dt, argument);

    if (shouldReset())
        value = resetValue;

    if (shouldNotify()) {
        Source* p = source();
        void* key = p ? &p->data : 0;
        float& speed = reinterpret_cast<float&>(argument);
        speed = (float)sqrt(x * x + y * y + z * z);
        Result* result = lookup.find(key);
        if (result)
            result->signal.fire(&speed, speed);
    }
}

// from server: 51% by atomic.potato
extern "C" void __stdcall Notify(int);

struct S {
    char padding[180];
    void Set(float);
};

void S::Set(float value)
{
    float *target = *(float **)((char *)this + 180);
    if (*target != value) {
        *target = value;
        Notify(0xB96D6C);
    }
}

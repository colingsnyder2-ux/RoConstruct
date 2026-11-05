// from server: 42% by atomic.potato
extern "C" void __stdcall Notify(int);

struct S
{
    char padding[180];
    void *object;
    void Set(float);
};

void S::Set(float value)
{
    float *field = (float *)((char *)object + 164);
    if (*field != value) {
        *field = value;
        Notify(0xB96E00);
    }
}

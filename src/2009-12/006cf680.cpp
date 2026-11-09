// from server: 46% by atomic.potato
struct S
{
    void f(float value);
};

extern "C" void __cdecl sub_006ceb10(void* object, const void* descriptor, int value);

const int g_006ceaa0 = 0;

void S::f(float value)
{
    void* object = *(void**)this;
    int bits = *(int*)&value;

    if (object)
        sub_006ceb10(object, &g_006ceaa0, bits);
}

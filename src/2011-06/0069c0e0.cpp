// from server: 42% by atomic.potato
struct S {
    void f(int);
};

extern "C" void __cdecl sub_69b720(float*, float, float, float);

void S::f(int value)
{
    float v[3];
    v[0] = *(float*)((char*)this + 0x90);
    v[1] = *(float*)((char*)this + 0x94);
    v[2] = *(float*)((char*)this + 0x98);
    sub_69b720(v, v[0], v[1], v[2]);
}

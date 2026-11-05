// from server: 62% by atomic.potato
struct S
{
    char padding[8];
    void (__thiscall *callback)(void *, float, float, float);
    char padding2[4];
    void method(void *, float *);
};

void S::method(void *arg1, float *arg2)
{
    void *obj;
    if (arg1 != 0)
        obj = (char *)arg1 - 0x1c;
    else
        obj = 0;

    float x = arg2[0];
    float y = arg2[1];
    float z = arg2[2];

    callback((char *)this + 0xc + (int)obj, x, y, z);
}

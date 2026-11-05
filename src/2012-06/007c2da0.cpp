// from server: 48% by atomic.potato
extern "C" int __stdcall Invoke(int, float);

struct S {
    int f(float);
    int field_84;
};

int S::f(float value)
{
    extern volatile unsigned char flag;
    if (flag)
        return 0;
    return Invoke(*(int*)field_84, value);
}

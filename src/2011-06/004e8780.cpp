// from server: 34% by atomic.potato
struct S
{
    unsigned char padding[8];
    unsigned int value;
    unsigned char* bits;
    unsigned char f();
};

unsigned char S::f()
{
    unsigned int n = value;
    unsigned char result = (bits[n >> 3] & (unsigned char)(0x80 >> (n & 7))) != 0;
    value = n + 1;
    return result;
}

struct Vec3
{
    float x;
    float y;
    float z;
};

struct Quat
{
    float x;
    float y;
    float z;
    float w;
};

struct C1
{
    unsigned char f();
};

struct C2
{
    void f(void* a, float* b, float* c, float* d);
};

extern "C" void __cdecl sub_4F08A0(void* a, void* b);
extern "C" float __cdecl sub_6CCCE0(unsigned int x);
extern "C" void* __cdecl sub_542880();
extern "C" void* __cdecl sub_542780();
extern "C" void* __cdecl sub_542800();
extern "C" void __cdecl sub_510F10(void* a, void* b);

extern float g_a6ec30;
extern float g_a75cdc;

struct Job
{
    void func(void* a, void* b);
};

void Job::func(void* a, void* b)
{
    unsigned char* self = (unsigned char*)a;
    float* out = (float*)b;

    if (((C1*)self)->f())
    {
        float tmp;
        sub_4F08A0(self, &tmp);
        float f = sub_6CCCE0(*(unsigned int*)&tmp);
        void* v1 = sub_542880();
        void* v2 = sub_542780();

        float x = *(float*)v1;
        float y = *((float*)v1 + 1);
        float z = *((float*)v1 + 2);
        float w = *((float*)v2);
        float w2 = *((float*)v2 + 1);
        float w3 = *((float*)v2 + 2);

        float scale;
        if (f >= 0.0f)
        {
            scale = f;
        }
        else
        {
            x *= g_a6ec30;
            y *= g_a6ec30;
            z *= g_a6ec30;
            scale = g_a75cdc - f;
        }

        out[0] = x;
        out[1] = y;
        out[2] = z;
        out[3] = scale;
        out[4] = w;
        out[5] = w2;
        out[6] = w3;
        return;
    }

    unsigned char b1 = ((C1*)self)->f();
    unsigned char b2 = ((C1*)self)->f();

    if (b1)
    {
        sub_510F10(self, self + 0x10);
    }
    else
    {
        void* v = sub_542780();
        *((float*)self + 4) = *(float*)v;
        *((float*)self + 5) = *((float*)v + 1);
        *((float*)self + 6) = *((float*)v + 2);
    }

    if (b2)
    {
        float vx = 0.0f;
        float vy = 0.0f;
        float vz = 0.0f;
        ((C2*)self)->f(&vx, &vy, &vz, 0);

        float tmp;
        sub_4F08A0(self, &tmp);
        float f = sub_6CCCE0(*(unsigned int*)&tmp);

        if (f >= 0.0f)
        {
            out[0] = vx;
            out[1] = vy;
            out[2] = vz;
            out[3] = f;
        }
        else
        {
            out[0] = vx * g_a6ec30;
            out[1] = vy * g_a6ec30;
            out[2] = vz * g_a6ec30;
            out[3] = g_a75cdc - f;
        }
    }
    else
    {
        void* v = sub_542800();
        out[0] = *(float*)v;
        out[1] = *((float*)v + 1);
        out[2] = *((float*)v + 2);
        out[3] = 0.0f;
    }
}

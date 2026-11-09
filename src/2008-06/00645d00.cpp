// from server: 100% by king_originala




#pragma float_control(precise, off)

unsigned int func_0063e420();
unsigned int func_006492d0();

struct State
{
    char padding[0x2c];
    float value;
    unsigned char flag;
};

struct S
{
    char padding[0xc0];
    State* state;
    float scale;

    void f();
};

void S::f()
{
    State* p = state;
    if (p)
    {
        float divisor = (float)(int)func_0063e420();
        float v = scale / divisor;
        float divisor2 = (float)(int)func_006492d0();
        p->value = v / divisor2;
        if (p->value == 0.0f)
            p->flag = 1;
    }
}

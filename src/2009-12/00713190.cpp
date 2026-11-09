// from server: 73% by atomic.potato
struct S_func_00713190 {
    char pad[228];
    unsigned char flag;
    char pad2[27];
    float value1;
    float value2;
    float value3;
    void f(float* out);
};

void S_func_00713190::f(float* out)
{
    char* base = (char*)this;
    if (flag)
        base += 256;
    else
        base += 268;
    out[0] = *(float*)base;
    out[1] = *((float*)base + 1);
    out[2] = *((float*)base + 2);
}

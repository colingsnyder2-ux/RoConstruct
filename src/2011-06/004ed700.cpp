// from server: 20% by atomic.potato
extern float G_float_a7ae6c;
extern void G_func_004e7560(unsigned short*);

void __stdcall func_004ed700(float a, float b, float c)
{
    float t = (a - b) * G_float_a7ae6c / (c - b);
    if (t < 0.0f)
        t = 0.0f;
    else if (t > G_float_a7ae6c)
        t = G_float_a7ae6c;
    unsigned short v = (unsigned short)(int)t;
    G_func_004e7560(&v);
}

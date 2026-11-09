// from server: 28% by atomic.potato
extern "C" void __cdecl sub_7c0e00(float *a, float *b, float c, float d, float e, float f, float g, float h, float i);

float g_7cc20;
float g_7cc24;
float g_7cc28;

struct FilterStairs
{
};

void __cdecl Func(float a, float b, float c, float d, float e, float f, float g, float h)
{
    float v20 = g_7cc20;
    float v24 = g_7cc24;
    float v28 = g_7cc28;

    float t0 = v20 - a;
    float t1 = v24 - b;
    float t2 = v28 - c;
    float t3 = a + v20;
    float t4 = b + v24;
    float t5 = c + v28;

    float arr[6];
    arr[0] = t0;
    arr[1] = t1;
    arr[2] = t2;
    arr[3] = t3;
    arr[4] = t4;
    arr[5] = t5;

    sub_7c0e00(arr, &arr[0], d, e, f, g, h, 0.0f, 0.0f);
}

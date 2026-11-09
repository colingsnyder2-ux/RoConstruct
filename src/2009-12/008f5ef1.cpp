// from server: 51% by atomic.potato
extern float g_009ed82c;
extern float g_00a11d48;

int __stdcall func_008f5ef1(float a, float b)
{
    float x = a - b;
    if (x < g_00a11d48 && x > g_009ed82c)
        return 1;
    return 0;
}

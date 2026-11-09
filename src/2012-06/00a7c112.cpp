// from server: 51% by atomic.potato
extern float g_00c2db90;
extern float g_00bf0cc0;

int __stdcall func_00a7c112(float a, float b)
{
    float x = a - b;
    if (x <= g_00c2db90 && x >= g_00bf0cc0)
        return 1;
    return 0;
}

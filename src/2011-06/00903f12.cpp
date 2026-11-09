// from server: 43% by atomic.potato
float g_00ae24d0;
float g_00abc524;

int __stdcall func_00903f12(float a, float b)
{
    float x = a - b;
    if (g_00ae24d0 <= x && x <= g_00abc524)
        return 1;
    return 0;
}

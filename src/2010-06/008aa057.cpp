// from server: 35% by atomic.potato
float g_00a76040;
float g_00a51624;

int __stdcall func_008aa057(float a, float b)
{
    float v = a - b;
    if (!(v < g_00a76040))
        return 0;
    if (!(v > g_00a51624))
        return 0;
    return 1;
}

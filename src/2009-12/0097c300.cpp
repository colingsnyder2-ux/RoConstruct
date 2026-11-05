// from server: 56% by atomic.potato
extern char g_00B63888;
extern int g_00B98D44;

void func_0097C300()
{
    char* p = &g_00B63888;
    char* q = p + 1;
    while (*p)
        ++p;
    g_00B98D44 = 127 - (int)(p - q);
}

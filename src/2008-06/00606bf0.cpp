// from server: 100% by colin
extern int g_hit, g_miss;
extern float g_none;

double hitRatio() {
    int n = g_hit + g_miss;
    if (n == 0) return g_none;
    return (double)g_hit / n;
}

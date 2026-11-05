// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern int g_hit, g_miss;
float hitRatio() {
    int n = g_hit + g_miss;
    if (n == 0) return -1.0f;
    return (float)g_hit / n;
}

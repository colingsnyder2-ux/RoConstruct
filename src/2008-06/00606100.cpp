// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern float g_81c3b8;
extern int g_97b878;
extern int g_97b87c;

float sub_606100()
{
    int sum = g_97b878 + g_97b87c;
    float r;
    if (sum == 0)
        r = g_81c3b8;
    else
        r = (float)g_97b878 / (float)sum;
    g_97b878 = 0;
    g_97b87c = 0;
    return r;
}

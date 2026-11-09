// from server: 100% by tester
extern "C" __declspec(dllimport) double _Inf;

double g_8bd100;
int g_8bd108;
double* g_77e564;
float g_8c0c1c;
float g_8c0c20;
float g_8c0c24;

void f()
{
    int flags = g_8bd108;
    double* p = g_77e564;
    if ((flags & 1) == 0)
    {
        flags |= 1;
        g_8bd108 = flags;
        g_8bd100 = *p;
        if ((flags & 1) == 0)
        {
            flags |= 1;
            g_8bd108 = flags;
            g_8bd100 = *p;
            if ((flags & 1) == 0)
            {
                flags |= 1;
                g_8bd108 = flags;
                g_8bd100 = *p;
            }
        }
    }
    float v = (float)g_8bd100;
    g_8c0c1c = v;
    g_8c0c20 = v;
    g_8c0c24 = v;
}

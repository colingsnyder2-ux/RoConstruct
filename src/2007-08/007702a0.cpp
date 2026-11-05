// from server: 100% by colin
extern "C" __declspec(dllimport) double _Nan;

double g_8c0940;
int g_8c0948;
double* g_77e544;
float g_8c0c10;
float g_8c0c14;
float g_8c0c18;

void f()
{
    int flags = g_8c0948;
    double* p = g_77e544;
    if ((flags & 1) == 0)
    {
        flags |= 1;
        g_8c0948 = flags;
        g_8c0940 = *p;
        if ((flags & 1) == 0)
        {
            flags |= 1;
            g_8c0948 = flags;
            g_8c0940 = *p;
            if ((flags & 1) == 0)
            {
                flags |= 1;
                g_8c0948 = flags;
                g_8c0940 = *p;
            }
        }
    }
    float v = (float)g_8c0940;
    g_8c0c10 = v;
    g_8c0c14 = v;
    g_8c0c18 = v;
}

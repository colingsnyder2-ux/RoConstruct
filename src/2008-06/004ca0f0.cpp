// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern const float scale;
extern const float offset;

struct S
{
    bool read(void* destination, int bits, bool rightAligned);
    bool f(float& x, float& y, float& z);
};

bool S::f(float& x, float& y, float& z)
{
    int packed;
    float magnitude;
    float a;
    float b;

    if (!read(&magnitude, 32, true))
        return false;

    if (magnitude != 0.0f)
    {
        if (read(&packed, 16, true))
        {
            packed = (unsigned short)packed;
            a = packed * scale - offset;
        }

        if (read(&packed, 16, true))
        {
            packed = (unsigned short)packed;
            b = packed * scale - offset;
        }

        if (!read(&packed, 16, true))
            return false;

        packed = (unsigned short)packed;
        double c = packed * scale - offset;

        x = a;
        y = b;
        z = c;

        x *= magnitude;
        y *= magnitude;
        z *= magnitude;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    return true;
}

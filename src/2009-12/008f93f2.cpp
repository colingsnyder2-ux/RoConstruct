// from server: 33% by atomic.potato
extern float G_9aea18;
extern float G_a11d4c;

extern "C" int __cdecl func_008f5ef1(float, float);
extern "C" float __cdecl sqrtf(float);

struct Vec2 { float x; float y; };

Vec2* func_008f93f2(Vec2* out, Vec2* in)
{
    float len2 = in->x * in->x + in->y * in->y;
    if (func_008f5ef1(len2, 1.0f))
    {
        if (out != in)
        {
            out->x = in->x;
            out->y = in->y;
        }
    }
    else if (len2 == G_a11d4c)
    {
        out->x = 0.0f;
        out->y = 0.0f;
    }
    else
    {
        float s = G_9aea18 / sqrtf(len2);
        out->x = in->x * s;
        out->y = in->y * s;
    }
    return out;
}

// from server: 47% by atomic.potato
float G3D_Ray_Epsilon = 0.0f;

extern "C" int __cdecl G3D_Ray_Compare(float, float)
{
    return 0;
}

int G3D_Ray_Equal(float a, float b)
{
    if (a != b)
        return 0;
    if ((a - b) < G3D_Ray_Epsilon)
        return 0;
    return 1;
}

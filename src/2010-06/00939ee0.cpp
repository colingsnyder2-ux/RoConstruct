// from server: 49% by atomic.potato
struct S
{
    float value;
};

struct MeshFaceCustomizableKey
{
    char padding[92];
    float field_5c;
    void GetValue(void *out, int count);
};

void MeshFaceCustomizableKey::GetValue(void *out, int count)
{
    float *p = (float *)out;
    if (count > 0)
    {
        p[0] = field_5c;
        p[1] = 1.0f;
        p[2] = 1.0f;
    }
    else
    {
        p[0] = 0.0f;
        p[1] = 1.0f;
        p[2] = 1.0f;
    }
}

// from server: 45% by atomic.potato
struct MeshFaceCustomizableKey
{
    unsigned char padding[0x70];
    unsigned char value;
    float get() const;
};

float MeshFaceCustomizableKey::get() const
{
    volatile float result;
    if (value != 0)
        result = 1.0f;
    else
        result = 0.0f;
    return result;
}

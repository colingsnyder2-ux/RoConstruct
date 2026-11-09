// from server: 87% by atomic.potato
struct BoundPropGetSet
{
    int unused;
    int unused2;
    int offset;
    float get(float* value);
};

float BoundPropGetSet::get(float* value)
{
    if (value != 0)
        return *(float*)((char*)value + offset - 28);
    return *(float*)offset;
}

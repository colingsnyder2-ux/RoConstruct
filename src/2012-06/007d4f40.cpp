// from server: 75% by atomic.potato
struct BoundPropGetSet
{
    float* values;

    void __thiscall get(float* out, float* source);
};

void __thiscall BoundPropGetSet::get(float* out, float* source)
{
    float* p = source ? source - 7 : 0;
    float* base = values + (p ? 0 : 0);
    if (p)
        base = values + (p - source);
    out[0] = base[0];
    out[1] = base[1];
    out[2] = base[2];
}

// from server: 30% by atomic.potato
struct S
{
    int Get(int* out, int index);
};

int S::Get(int* out, int index)
{
    const int* value = reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(this) + index * 12);
    out[0] = value[0];
    out[1] = value[1];
    out[2] = value[2];
    return reinterpret_cast<int>(out);
}

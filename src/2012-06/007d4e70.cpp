// from server: 62% by atomic.potato
struct S
{
    int* data;
    void f(int* out, int* value);
};

void S::f(int* out, int* value)
{
    int offset = value ? (int)value - 0x1c : 0;
    int* entry = (int*)((char*)data + offset);
    out[0] = entry[0];
    out[1] = entry[1];
    out[2] = entry[2];
}

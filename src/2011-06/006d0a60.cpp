// from server: 73% by atomic.potato
struct S
{
    float* data;
    int get(float* result, int offset);
};

int __thiscall S::get(float* result, int offset)
{
    int index = offset ? offset - 0x1c : 0;
    float* source = data + index;
    result[0] = source[0];
    result[1] = source[1];
    result[2] = source[2];
    return 0;
}

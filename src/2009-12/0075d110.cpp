// from server: 100% by atomic.potato
struct SelectionPointLasso
{
    char get(float *out);
};

char SelectionPointLasso::get(float *out)
{
    out[0] = *(float *)((char *)this + 0xbc);
    out[1] = *(float *)((char *)this + 0xc0);
    out[2] = *(float *)((char *)this + 0xc4);
    return 1;
}

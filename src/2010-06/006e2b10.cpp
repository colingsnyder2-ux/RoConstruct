// from server: 87% by atomic.potato
struct S
{
    char pad[188];
    float x;
    float y;
    float z;
    void get(float *out);
};

void S::get(float *out)
{
    out[0] = x;
    out[1] = y;
    out[2] = z;
}

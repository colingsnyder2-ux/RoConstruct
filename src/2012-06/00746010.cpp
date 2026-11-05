// from server: 73% by atomic.potato
struct S
{
    float value;
    unsigned short key;
    void f(float* out);
};

unsigned int g_mask;

void S::f(float* out)
{
    out[0] = *(float*)(((unsigned int*)&value)[0] ^ g_mask);
    ((unsigned short*)out)[2] = (unsigned short)(-(short)key);
}

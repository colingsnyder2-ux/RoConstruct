// from server: 44% by atomic.potato
struct S
{
    float f();
};

float S::f()
{
    return *reinterpret_cast<float *>(reinterpret_cast<char *>(this) + 0x214);
}

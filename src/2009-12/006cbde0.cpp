// from server: 79% by atomic.potato
struct PartInstance
{
    void f(unsigned int* result);
};

void PartInstance::f(unsigned int* result)
{
    unsigned int* data = *reinterpret_cast<unsigned int**>(
        reinterpret_cast<unsigned char*>(this) + 0x168);
    unsigned int a = data[0x78 / 4];
    unsigned int b = data[0x7c / 4];
    result[0] = a;
    result[1] = b;
}

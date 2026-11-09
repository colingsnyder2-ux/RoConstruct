// from server: 100% by atomic.potato
struct S {
    float f();
    char padding[0x168];
    void* member;
};

float S::f()
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(member) + 0x108);
}

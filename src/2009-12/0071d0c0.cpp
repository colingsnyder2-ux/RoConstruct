// from server: 50% by atomic.potato
struct NonFactoryProduct
{
    void set(float value);
};

extern "C" void __cdecl dispatch(int);

void NonFactoryProduct::set(float value)
{
    *(float *)((char *)this + 0xc4) = value;
    dispatch(0xb95a14);
}

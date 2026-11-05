// from server: 83% by atomic.potato
struct PrismBuilder
{
    PrismBuilder* f(void*);
};

PrismBuilder* PrismBuilder::f(void* value)
{
    PrismBuilder* result = this;
    result->f(value);
    *(int*)((char*)result + 0x28) = 0xc2;
    *(volatile float*)((char*)result + 0x2c) = 0.0f;
    return result;
}

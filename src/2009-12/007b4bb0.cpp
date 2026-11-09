// from server: 69% by atomic.potato
extern "C" void __stdcall Function_00773660(float*, int, void*, int);
extern "C" void __stdcall Function_005F3990(void*, float*, int);

struct FactoryProduct_007B4BB0
{
    void *value;
    float data[3];
};

FactoryProduct_007B4BB0 * __stdcall Function_007B4BB0(FactoryProduct_007B4BB0 *value)
{
    float buffer[3];
    Function_00773660(buffer, 0, value, 2);
    Function_005F3990(value, buffer, 0);
    return value;
}

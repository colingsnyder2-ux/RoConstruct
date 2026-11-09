// from server: 60% by atomic.potato
struct BoundFuncDesc
{
    int value;
    void* field;
    int f(void*);
};

extern "C" void func_006f1f70(BoundFuncDesc*);
extern "C" void __stdcall func_0065f320(void*, void*);

int BoundFuncDesc::f(void* p)
{
    func_006f1f70(this);
    func_0065f320(field, p);
    return (int)p;
}

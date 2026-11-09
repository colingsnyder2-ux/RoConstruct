// from server: 43% by atomic.potato
extern "C" void __cdecl func_00719030(void*, int);

struct S_00719260
{
    void* f(int);
};

void* S_00719260::f(int value)
{
    func_00719030(this, 0);
    return (void*)value;
}

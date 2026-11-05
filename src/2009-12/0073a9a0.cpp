// from server: 100% by atomic.potato
extern "C" void __cdecl G1_func_00788f90(void *);
extern "C" int __cdecl G1_func_0078a150(void *, int);

struct S {
    int *value;
    int result;
    S *f(int *);
};

S *S::f(int *value)
{
    this->value = value;
    if (value) {
        G1_func_00788f90(value);
        this->result = G1_func_0078a150(this->value, -10000);
    }
    return this;
}

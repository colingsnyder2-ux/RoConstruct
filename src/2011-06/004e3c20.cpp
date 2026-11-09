// from server: 41% by atomic.potato
struct S
{
    int pad0[7];
    void* vtable_object;
    void f(double value);
};

extern "C" double __cdecl sub_4197e0(int value);

typedef void (__thiscall *Callback)(S*, int, double*);

void S::f(double value)
{
    double converted;
    converted = sub_4197e0((int)value);
    Callback callback = *(Callback *)(*(void ***)vtable_object + 12);
    callback(this, (int)value, &converted);
}

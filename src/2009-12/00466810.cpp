// from server: 57% by atomic.potato
struct S
{
    double value;
    void __cdecl f(double*);
};

extern "C" double GetValue(void*);
extern "C" void SetValue(S*, double*);

void S::f(double* arg)
{
    value = GetValue((char*)this + 0xc0);
    SetValue(this, &value);
}

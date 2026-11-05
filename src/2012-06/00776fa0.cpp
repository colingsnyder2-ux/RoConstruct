// from server: 74% by atomic.potato
struct S_00776fa0 {
    char pad0[0x198];
    int m_value;
    void f(int);
};

extern "C" void __stdcall sub_00751080(S_00776fa0 *, int);
extern "C" void __stdcall sub_007B92E0(int *, int);

void S_00776fa0::f(int value)
{
    sub_00751080(this, value);
    sub_007B92E0(&m_value, 2);
}

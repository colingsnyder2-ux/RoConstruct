// from server: 29% by atomic.potato
struct S_func_007e0d90 {
    int m_field0;
    int m_field4;
    void f(int);
};

struct T_007e08e0 { char __thiscall g(); };
struct T_007de000 { void __thiscall g(); };

extern "C" void __stdcall sub_007de7b0(void*, void*);

void S_func_007e0d90::f(int a)
{
    char buf[0x70];
    sub_007de7b0(buf, &a);
    char r = ((T_007e08e0*)0xdd1ae8)->g();
    m_field0 = r ? 0xdd1ae8 : 0;
    ((T_007de000*)buf)->g();
}

// from server: 59% by atomic.potato
struct S_func_006df440 {
    char pad[0x17c];
    float m_x;
    float m_y;
    float m_z;
    void f(void* out);
};

extern "C" void __stdcall sub_0061f1a0(void* out, void* arg);

void S_func_006df440::f(void* out)
{
    float tmp[3];
    tmp[0] = m_x;
    tmp[1] = m_y;
    tmp[2] = m_z;
    sub_0061f1a0(tmp, out);
}

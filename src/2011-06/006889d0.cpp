// from server: 60% by atomic.potato
struct S_func_006889d0 {
    char pad[0xc0];
    float m_field_c0;
    void f(float);
};

extern "C" void __stdcall sub_00411f60(const char*);
extern "C" int __fastcall sub_00688180(S_func_006889d0*);
extern "C" void __fastcall sub_00688a80(int);

void S_func_006889d0::f(float v)
{
    if (m_field_c0 != v) {
        sub_00411f60((const char*)0xccf118);
        m_field_c0 = v;
        int r = sub_00688180(this);
        if (r != 0) {
            sub_00688a80(r);
        }
    }
}

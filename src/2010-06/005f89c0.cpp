// from server: 65% by atomic.potato
struct S_func_005f89c0 {
    char pad0[0x144];
    char m_flag;
    char pad1[3];
    int m_field148;
    bool f();
};

extern "C" void __stdcall sub_0040c470(const char*);
void sub_005f8500();
void sub_005f88c0();

bool S_func_005f89c0::f()
{
    if (!((bool (__thiscall*)(S_func_005f89c0*))*(void**)(*(char**)this + 0x8c))(this))
        return false;
    if (m_flag != 0) {
        ((void (__thiscall*)(S_func_005f89c0*))*(void**)(*(char**)this + 0x9c))(this);
        return true;
    }
    m_flag = 1;
    sub_0040c470("$SUV");
    if (m_field148 == 0)
        sub_005f8500();
    else
        sub_005f88c0();
    return true;
}

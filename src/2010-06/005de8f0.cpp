// from server: 25% by atomic.potato
struct S_func_005de8f0 {
    char pad0[0xa8];
    char m_str[0x1c];
    void f();
};

extern "C" void __stdcall sub_9ea400(void*);
extern "C" void __stdcall sub_40fab0(void*);

void S_func_005de8f0::f()
{
    sub_9ea400(&m_str[0]);
    sub_40fab0(this);
}

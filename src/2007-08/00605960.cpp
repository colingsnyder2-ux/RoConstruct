// from server: 100% by tester
struct S_func_00609130 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S_func_006056f0 {
    void f(void* a1);
};

struct S_func_006055c0 {
    void f(void* a1);
};

struct SleepStage {
    void f(void* a1);
};

void SleepStage::f(void* a1)
{
    ((S_func_00609130*)a1)->f((int)this);
    ((S_func_006056f0*)this)->f(a1);
    void* p = *(void**)((char*)a1 + 0x6c);
    if (p != 0) {
        ((S_func_006055c0*)this)->f(p);
    }
}

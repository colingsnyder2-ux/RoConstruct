// from server: 100% by atomic.potato
extern "C" void __cdecl target_685090();

struct S {
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0) = 0x00bbfcb4;
    *(int *)((char *)this + 4) = 0x00bbfcac;
    *(int *)((char *)this + 0x18) = 0x00bbfca0;
    *(int *)((char *)this + 0x1c) = 0x00bbfc94;
    *(int *)((char *)this + 0x80) = 0x00bbfc8c;
    target_685090();
}

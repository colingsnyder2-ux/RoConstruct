// from server: 83% by atomic.potato
extern "C" void __fastcall func_007f56c0(void *, void *);
extern "C" void __fastcall func_007a1d00(void *, void *);

struct EdgeStage
{
    void f(void *);
};

void EdgeStage::f(void *arg)
{
    func_007f56c0(*(void **)((char *)this + 8), arg);
    func_007a1d00(arg, this);
}

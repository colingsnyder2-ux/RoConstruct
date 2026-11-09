// from server: 77% by atomic.potato
struct EdgeStage
{
    void f(void *);
};

extern "C" void __cdecl func_006795a0(void *);
extern "C" void func_0078c580(EdgeStage *, void *);

void EdgeStage::f(void *arg)
{
    func_006795a0(arg);
    func_0078c580(this, arg);
}

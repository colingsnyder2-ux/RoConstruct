// from server: 100% by atomic.potato
struct EdgeStage
{
    void f(void *);
};

extern "C" void __stdcall func_0078c5a0(void *);
extern "C" void __cdecl func_00678e60(void *);

void EdgeStage::f(void *arg)
{
    func_0078c5a0(arg);
    func_00678e60(arg);
}

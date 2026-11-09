// from server: 100% by atomic.potato
extern "C" void __stdcall func_007ef010(void *);
extern "C" void __cdecl func_006a4d00(void *);

struct EdgeStage
{
    void f(void *);
};

void EdgeStage::f(void *arg)
{
    func_007ef010(arg);
    func_006a4d00(arg);
}

// from server: 72% by atomic.potato
extern "C" void __cdecl target();

struct CXTRegistryManager
{
    void f(int, int, int, int);
};

void CXTRegistryManager::f(int a, int b, int c, int d)
{
    target();
}

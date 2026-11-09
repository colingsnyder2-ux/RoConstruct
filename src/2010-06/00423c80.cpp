// from server: 64% by atomic.potato
extern "C" void __cdecl LogManagerTarget();

struct LogManager
{
    void f();
};

void LogManager::f()
{
    if (*((void **)((char *)this + 0x2c)) != 0)
        LogManagerTarget();
}

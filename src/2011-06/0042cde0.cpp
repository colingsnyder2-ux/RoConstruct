// from server: 64% by atomic.potato
struct LogManager
{
    void f();
};

extern void G1_func_004de7e0();

void LogManager::f()
{
    if (*(void**)((char*)this + 0x2c))
        G1_func_004de7e0();
}

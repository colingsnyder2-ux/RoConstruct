// from server: 43% by atomic.potato
typedef void (__cdecl *LogManagerTarget)();

struct LogManager
{
    void Get();
};

void LogManager::Get()
{
    LogManagerTarget target = *(LogManagerTarget*)((char*)this + 0x2c);
    if (target)
        target();
}

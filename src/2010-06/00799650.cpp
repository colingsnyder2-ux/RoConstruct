// from server: 100% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedIncrement(volatile long *);

struct Log
{
    char padding[420];
    long value;

    void increment();
};

void Log::increment()
{
    InterlockedIncrement(&value);
}

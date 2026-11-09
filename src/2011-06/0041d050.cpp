// from server: 100% by atomic.potato
extern "C" unsigned long __declspec(dllimport) __stdcall timeGetTime();

struct DSVideoCaptureEngine
{
    int f();
    int padding[6];
    int field18;
};

int DSVideoCaptureEngine::f()
{
    return (int)timeGetTime() - field18;
}

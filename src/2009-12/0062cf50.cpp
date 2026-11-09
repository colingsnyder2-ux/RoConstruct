// from server: 100% by atomic.potato
extern "C" void __cdecl continuation();

struct S {
    int v0;
    int v4;
    int padding[4];
    int v18;
    int v1c;
    void initialize();
};

int g_b7ae30;

void S::initialize()
{
    g_b7ae30 = 0;
    v0 = 0x9caf64;
    v4 = 0x9caf58;
    v18 = 0x9caf4c;
    v1c = 0x9caf44;
    continuation();
}

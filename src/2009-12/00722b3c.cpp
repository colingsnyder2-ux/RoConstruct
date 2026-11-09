// from server: 94% by atomic.potato
extern "C" void __stdcall target(int, int);

void wrapper()
{
    target(0, 0);
}

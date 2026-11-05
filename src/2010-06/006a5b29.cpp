// from server: 45% by atomic.potato
extern "C" void __cdecl target(int, int);

void wrapper()
{
    target(0, 0);
}

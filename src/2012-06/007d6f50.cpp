// from server: 100% by atomic.potato
extern "C" void __cdecl f009831f5(int);

unsigned int g00e4df94;
int g00e4df8c;
int g00e4df90;

void f007d6f50()
{
    if (!(g00e4df94 & 1))
    {
        g00e4df94 |= 1;
        g00e4df8c = 0;
        g00e4df90 = 0;
        f009831f5((int)0x00b1d130);
    }
}

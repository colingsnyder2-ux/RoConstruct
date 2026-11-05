// from server: 64% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(long*);

struct S
{
    S();
    long value0;
    long value1;
    char value2;
    char padding[3];
    long value3;
};

S::S()
{
    InterlockedIncrement((long*)0x00b808ec);
    value0 = 0x009be904;
    value2 = 0;
    value1 = 0;
    value3 = 0;
}

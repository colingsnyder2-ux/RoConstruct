// from server: 100% by atomic.potato
extern "C" unsigned char __cdecl sub_007bd720(int);

struct Unlocked
{
    int f(int);
};

int Unlocked::f(int value)
{
    return sub_007bd720(value) ? 2 : 0;
}

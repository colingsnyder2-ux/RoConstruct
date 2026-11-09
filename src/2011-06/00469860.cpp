// from server: 100% by atomic.potato
extern "C" int __cdecl sub_0080B2EA(int, int, int, int, int);

struct StatsService
{
    int f(int);
};

int StatsService::f(int value)
{
    return sub_0080B2EA(value, 0, 0xC071F8, 0xC12EF0, 0) != 0;
}

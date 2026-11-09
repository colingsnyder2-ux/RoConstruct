// from server: 88% by atomic.potato
extern "C" unsigned char __stdcall sub_007b89f0(const char *);

struct Unlocked {
    int f(const char *);
};

int Unlocked::f(const char *value)
{
    return sub_007b89f0(value) ? 0 : 2;
}

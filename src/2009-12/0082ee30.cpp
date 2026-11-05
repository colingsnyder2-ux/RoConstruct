// from server: 65% by atomic.potato
extern "C" void __cdecl sub_82ee10(void *);

extern float g_9af2dc;

struct S
{
    S();
    int value;
    char padding[24];
};

S::S()
{
    int *p = reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 4);
    sub_82ee10(p);
    p = reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 16);
    sub_82ee10(p);
    *reinterpret_cast<float *>(reinterpret_cast<char *>(this) + 28) = g_9af2dc;
}

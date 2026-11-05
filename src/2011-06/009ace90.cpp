// from server: 42% by atomic.potato
extern "C" int __stdcall sub_009aba60(int, int, int);

int __stdcall sub_009ace90(int a, int b, int c, int d)
{
    return sub_009aba60(a, b, d);
}

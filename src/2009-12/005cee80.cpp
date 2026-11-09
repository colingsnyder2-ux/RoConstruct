// from server: 100% by atomic.potato
extern "C" void __cdecl sub_5cc810(int, int, int);

struct S {
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4) {
        sub_5cc810(a, b, c);
        return;
    }

    *(int*)b = 0x00b25c38;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}

// from server: 100% by atomic.potato
extern "C" void target_507e50(int, int, int);

struct S {
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4) {
        target_507e50(a, b, c);
    } else {
        *(int*)b = 0x00b167b8;
        *((char*)b + 4) = 0;
        *((char*)b + 5) = 0;
    }
}

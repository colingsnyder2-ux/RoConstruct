// from server: 48% by atomic.potato
extern "C" void *__cdecl Call4(int, int, int, int);
extern "C" void __cdecl Call5(void *, int, int, int);

void Function(int a, int b, int c, int d)
{
    void *p = Call4(0, b, 0, 0);
    int v = *(int *)p;
    Call5(p, d, v, a);
}

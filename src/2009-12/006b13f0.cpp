// from server: 58% by atomic.potato
extern "C" int __stdcall sub_6b0ec0(int, int);

struct S {
    int __cdecl f(int a, int b, int c);
};

int S::f(int a, int b, int c)
{
    char buf[4];
    buf[0] = (char)a;
    buf[1] = (char)b;
    buf[2] = (char)c;
    buf[3] = 0;
    int v;
    *(char*)&v = buf[0];
    *((char*)&v + 1) = buf[1];
    *((char*)&v + 2) = buf[2];
    *((char*)&v + 3) = 0;
    sub_6b0ec0(v, a);
    return a;
}

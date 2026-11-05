// from server: 75% by atomic.potato
extern "C" int __stdcall sub_742B50(int, int);

int __cdecl sub_742FF0(int a, char b, char c, char d)
{
    char buf[4];
    buf[0] = b;
    buf[1] = c;
    buf[2] = d;
    buf[3] = 0;
    sub_742B50(a, *(int*)buf);
    return a;
}

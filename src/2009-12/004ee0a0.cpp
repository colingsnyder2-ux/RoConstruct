// from server: 13% by atomic.potato
extern "C" int __cdecl sub_4EE510(int, int, int);

int __cdecl sub_4EE0A0(int a, int b, int c)
{
    char pad[8];
    pad[0] = 0;
    char t = pad[2];
    pad[1] = t;
    char u = pad[0];
    char v = u;
    int w = a;
    return sub_4EE510(w, b, c);
}

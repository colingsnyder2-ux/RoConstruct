// from server: 62% by atomic.potato
extern "C" int __cdecl sub_0061EC30(int, int);

int sub_0061F160(int a, char b, char c, char d) {
    char buf[4];
    buf[0] = b;
    buf[1] = c;
    buf[2] = d;
    buf[3] = 0;
    sub_0061EC30(a, *(int *)buf);
    return a;
}

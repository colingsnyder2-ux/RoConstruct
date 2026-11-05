// from server: 92% by atomic.potato
struct EventDesc {
    char pad[0x24];
    int field24;
    int sub_706c20(int);

    int sub_7078b0(int a, int b);
};

extern "C" int __cdecl sub_5be6b0(int);

int EventDesc::sub_7078b0(int a, int b) {
    int *p = (int *)a;
    int v = (p != 0) ? (int)((char *)p - 0x1c) : 0;
    int s = field24 + v;
    int *q = (int *)b;
    int r = sub_5be6b0(q[1]);
    return ((EventDesc *)s)->sub_706c20(*(int *)r);
}

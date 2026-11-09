// from server: 27% by atomic.potato
extern "C" {
int __cdecl sub_6510A0(int, int);
int __cdecl sub_762960(int, int, int);
void __stdcall sub_A404D0(int);
}

struct S {
    int __cdecl f(int);
};

int S::f(int a) {
    char buf[0x1c];
    sub_6510A0((int)buf, a);
    int p = *(int*)buf;
    if (*(int*)(buf + 0x14) >= 0x10)
        p = *(int*)buf;
    sub_762960(*(int*)(buf + 0x10), p, *(int*)(buf + 0x24));
    sub_A404D0((int)buf);
    return 1;
}

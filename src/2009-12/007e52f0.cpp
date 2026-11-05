// from server: 92% by atomic.potato
extern "C" int __stdcall sub_90F234(int, int, int, int);

struct S {
};

void __cdecl f(int a) {
    int buf[4];
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    sub_90F234(a, 0x200, 0, (int)buf);
    *(double*)buf[2] = *(double*)&buf[1];
}

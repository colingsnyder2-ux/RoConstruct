// from server: 91% by atomic.potato
extern "C" int __stdcall sub_90f234(int, int, int, int);

struct S {
};

void __cdecl f(int a) {
    int buf[4];
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    sub_90f234(a, 0x100, 0, (int)buf);
    *(int*)buf[2] = buf[0];
}

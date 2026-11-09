// from server: 76% by atomic.potato
extern "C" int __stdcall sub_832ED0(int, int);
extern "C" int __stdcall sub_6A2240(int, int);
extern "C" int __stdcall sub_832130(int, int);
extern "C" int __stdcall sub_832200(int, int, int);
extern "C" int __stdcall sub_832550(int, int);
extern "C" int __stdcall sub_832460(int, int, int);
extern "C" int __stdcall sub_831B00(int, int);

struct S {
    void f(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
          int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
    int* g = (int*)0x00de13e8;
    int v = *g;
    sub_832ED0(v, a1);
    sub_6A2240(a1, -1);
    sub_832130(a1, 0x00b94214);
    sub_832200(a1, a4, 0);
    sub_832550(a1, -3);
    sub_832130(a1, 0x00b94208);
    sub_832200(a1, a8, 0);
    sub_832550(a1, -3);
    sub_832130(a1, 0x00bd1b68);
    sub_832200(a1, 0x00844210, 0);
    sub_832550(a1, -3);
    sub_832130(a1, 0x00bd1b60);
    sub_832200(a1, 0x00844250, 0);
    sub_832550(a1, -3);
    sub_832130(a1, 0x00bd1b54);
    sub_832200(a1, 0x00844230, 0);
    sub_832550(a1, -3);
    sub_832460(a1, -1, 1);
    sub_831B00(a1, -2);
}

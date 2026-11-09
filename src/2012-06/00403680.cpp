// from server: 36% by atomic.potato
struct Value { int x; };

extern "C" int (__thiscall *sub_004015a0)(int, int);
extern "C" Value* __stdcall sub_004019d0();
extern "C" Value& __stdcall sub_004025c0();
extern "C" void* __stdcall sub_00457100();
extern "C" int* __stdcall sub_00466420();
extern "C" void* __stdcall sub_0067f480();
extern "C" void __stdcall sub_00972290(int, int);

extern char g_00b42f90;
extern char g_00b42fa8;
extern char g_00b43010;
extern char g_00b43080;
extern char g_00b4311c;
extern char g_00b43160;
extern char g_00b431d0;
extern char g_00b431e8;
extern char g_00b43284;
extern char g_00b43510;
extern int g_00b908dc;
extern int g_00e16400;
extern char g_00e16410;
extern int g_00e5809c;
extern char g_00e580b3;

struct S {
    int f();
};

int S::f()
{
    int local8;
    int localc;
    Value* pi;
    int* pi2;
    int i;

    *(int*)this = (int)&g_00b43510;

    if (g_00b908dc == 0) {
        sub_0067f480();
    } else {
        sub_004015a0(0x402720, (int)&g_00e16410);
        sub_004025c0();
    }

    pi = &sub_004025c0();

    if (g_00e580b3 != 0) {
        localc = (int)pi;
        pi2 = (int*)sub_004019d0();
        i = pi2[1];
        sub_004019d0();
        if (*sub_00466420() != i) {
            if (g_00e5809c != 0) {
                if (!((char (__stdcall*)(int, int, int))g_00e5809c)(0xd7, (int)&g_00b42fa8, (int)&g_00b43284)) {
                    sub_00972290((int)&g_00b431e8, (int)g_00e580b3);
                }
            } else {
                sub_00972290((int)&g_00b431e8, (int)g_00e580b3);
            }
        }
        if (g_00e580b3 != 0) {
            if (g_00e16400 == 0x29a) {
                if (g_00e5809c != 0) {
                    if (!((char (__stdcall*)(int, int, int))g_00e5809c)(0xd8, (int)&g_00b42fa8, (int)&g_00b431d0)) {
                        sub_00972290((int)&g_00b43160, (int)g_00e580b3);
                    }
                } else {
                    sub_00972290((int)&g_00b43160, (int)g_00e580b3);
                }
            }
        }
    }

    local8 = (int)pi;
    sub_004019d0();
    *(int*)sub_00457100() = (int)this;

    g_00e16400 = 0x29a;

    if (g_00e580b3 != 0) {
        localc = (int)pi;
        pi2 = (int*)sub_004019d0();
        i = pi2[1];
        sub_004019d0();
        if (*sub_00466420() == i) {
            if (g_00e5809c != 0) {
                if (!((char (__stdcall*)(int, int, int))g_00e5809c)(0xdd, (int)&g_00b42fa8, (int)&g_00b4311c)) {
                    sub_00972290((int)&g_00b43080, (int)g_00e580b3);
                }
            } else {
                sub_00972290((int)&g_00b43080, (int)g_00e580b3);
            }
        }
        if (g_00e580b3 != 0) {
            if (g_00e16400 != 0x29a) {
                if (g_00e5809c != 0) {
                    if (!((char (__stdcall*)(int, int, int))g_00e5809c)(0xde, (int)&g_00b42fa8, (int)&g_00b42f90)) {
                        sub_00972290((int)&g_00b43010, (int)g_00e580b3);
                    }
                } else {
                    sub_00972290((int)&g_00b43010, (int)g_00e580b3);
                }
            }
        }
    }

    return (int)this;
}

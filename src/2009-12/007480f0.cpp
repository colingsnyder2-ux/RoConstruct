// from server: 93% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Sub {
    char pad[0x20];
    Sub(int, int);
};

struct Handles {
    char pad0[4];
    char f4;
    char f5;
    char pad6[2];
    int f8;
    int fc;
    int f10;
    char pad14[4];
    char sub18[0x20];
    int f38;
    int f3c;
    int f40;
    int f44;
    Handles(int, int, int);
};

Handles::Handles(int a, int b, int c)
{
    InterlockedIncrement((long*)0xb7a224);
    *(int*)this = 0x9a2cc4;
    f5 = 1;
    f8 = 0;
    fc = *(int*)0x9efd3c;
    f10 = c;
    *(int*)this = 0x9ae384;
    *(int*)sub18 = 0;
    ((Sub*)sub18)->Sub::Sub(a, b);
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
}

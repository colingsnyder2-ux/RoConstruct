// from server: 100% by king_originala
#pragma float_control(precise, off)

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

struct Data {
    char reserved0[4];
    int count;
    char reserved1[0x20];
    int value;
};

struct S {
    char reserved[0x10];
    Data* data;
    int f();
};

int S::f()
{
    return (int)sqrt(sqrt((double)(data->count * 6 + data->value + 4))) + 1;
}

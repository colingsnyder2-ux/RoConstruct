// from server: 46% by TrollStein
struct Assembly
{
    char pad0[0x0c];
    int field0c;
    char pad10[0x14];
    float field24;
    float field28;
    float field2c;
    char pad30[0x1c];
    float field4c;
    float field50;
    float field54;
    char pad58[0x30];
    float field88;

    void* func(int a, int b);
};

struct Helper1
{
    void method(int* a, int* b, float f);
};

struct Helper2
{
    void method(int* a);
};

struct Helper3
{
    int method(int* a);
};

struct Helper4
{
    void method(int* a, int* b);
};

extern "C" void __cdecl func_5aaf50(int* a, int* b, float f);
extern "C" void __cdecl func_5095d0(int* a, int* b);
extern "C" int __cdecl func_4750b0(int* a);
extern "C" void __cdecl func_473200(int* a, int* b);

void* Assembly::func(int a, int b)
{
    int local1[3];
    int local2[3];
    int local3[3];
    int local4[3];
    int local5[3];

    func_5aaf50(local1, (int*)((char*)this + 0x28), field88);
    func_5095d0(local2, local1);

    float f1 = field4c;
    float f2 = field50;
    float f3 = field54;

    int tmp[3];
    tmp[0] = *(int*)&f1;
    tmp[1] = *(int*)&f2;
    tmp[2] = *(int*)&f3;

    func_4750b0((int*)((char*)this + 0x58));
    func_473200(local3, tmp);

    if (a == field0c)
    {
        func_5095d0(local4, local2);
        field24 = *(float*)&local4[0];
        field28 = *(float*)&local4[1];
        field2c = *(float*)&local4[2];
    }
    else
    {
        func_4750b0(local5);
    }

    return this;
}

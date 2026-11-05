// from server: 100% by tester
struct FactoryProduct {
    char pad[4];
    char field4;
    char field5;
};

extern "C" void __cdecl sub_6db270(int, int, int);

void __cdecl sub_6db870(int arg0, int arg1, int arg2)
{
    if (arg2 != 4) {
        sub_6db270(arg0, arg1, arg2);
        return;
    }
    FactoryProduct* p = (FactoryProduct*)arg1;
    *(int*)p = 0xbd69a8;
    p->field4 = 0;
    p->field5 = 0;
}

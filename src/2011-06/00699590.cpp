// from server: 24% by colin
// roc 2011-06 00699590  unit: RBX::$$A6AXVBrickColor::?$signal::Vslot::?$callable  size: 210 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00699590

struct BrickColor {
    int number;
    int pad0[5];
    int field18;
    int field1c;
    int field20;
    int field24;
    void construct(int a, int b, int c, int d);
};

extern "C" int __cdecl sub_5cf480(int, int);
extern "C" int __cdecl sub_6a5ab0();
extern "C" int __cdecl sub_592b40(int*);
extern "C" int __cdecl sub_66d710();
extern "C" int __cdecl sub_62d1b0(int*);
extern "C" int __cdecl sub_4a7f80(int, int, int*);
extern "C" int __cdecl sub_722ca0(int);

extern int dword_cca60c;

void BrickColor::construct(int a, int b, int c, int d)
{
    int local14;
    int local18;
    int local1c;
    int local20;
    int local24;
    int local28;
    int local2c;
    int local30;
    int local34;
    int local38;

    int v = sub_5cf480(a, b);
    sub_6a5ab0();
    this->field24 = c;

    local30 = 0;
    *(int*)this = 0xaa2838;

    local34 = 0;
    sub_592b40(&local34);
    dword_cca60c++;
    local14 = local34;

    local18 = sub_66d710();
    sub_62d1b0(&local1c);

    int ebp = this->field1c;
    int edx = *(int*)(ebp + 4);
    int* edi = &this->field18;
    local20 = local18;
    local2c = 1;
    int ebx = sub_4a7f80(ebp, edx, &local20);
    sub_722ca0(1);
    *(int*)(ebp + 4) = ebx;
    int eax = *(int*)(ebx + 4);
    *(int*)eax = ebx;

    int ecx = local24;
    local2c = 0;
    if (ecx != 0) {
        int* eax2 = (int*)ecx;
        int edx2 = *eax2;
        void (__stdcall *fn)(int) = (void (__stdcall *)(int))edx2;
        fn(1);
    }
}

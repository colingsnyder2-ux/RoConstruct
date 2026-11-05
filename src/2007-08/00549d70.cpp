// from server: 26% by colin
extern "C" {
    int __stdcall sub_40F800(int);
    int __stdcall sub_40FB40(int);
    int __stdcall sub_443450(int, int, int, int);
    int __stdcall sub_4434C0(int);
    int __stdcall sub_542160(int, int, int);
    int __stdcall sub_549A10(int);
    int __stdcall sub_566C00(int, int);
    int __stdcall sub_567100(int, int);
    int __stdcall sub_62FC62(int);
    int __stdcall sub_725750(int);
    int __stdcall sub_725770(int);
    int __stdcall sub_77E658(int, int, int, int);
    int __stdcall sub_77E65C(int);
}

struct VServiceProviderNotifier {
    char pad[0x100];
    void func();
};

void VServiceProviderNotifier::func()
{
    char buf[0x100];
    int local_54;
    int local_50;
    int local_40;
    int local_3c;
    int local_38;
    int local_34;
    int local_30;
    int local_2c;
    int local_28;
    int local_24;
    int local_20;
    int local_1c;
    int local_18;
    int local_14;
    int local_10;
    int local_8;
    int local_4;
    int local_74;
    int local_6c;
    int local_8c;
    int local_94;
    int local_100;
    int local_f8;

    local_34 = (int)this;
    sub_549A10((int)&local_54);
    local_4 = 0;
    if (local_40 == 0) goto end;
    if (local_3c >= 0x10) {
        local_50 = local_50;
    } else {
        local_50 = (int)&local_50;
    }
    sub_77E658(local_50, 0x21, 0x40, 1);
    local_4 = 2;
    sub_566C00((int)&local_8c, (int)&local_f8);
    local_74 = 0x786dcc;
    local_4 = 3;
    sub_567100((int)&local_8c, (int)&local_38);
    local_14 = local_38;
    local_38 = 0;
    local_4 = 4;
    if (local_38 != 0) {
        sub_40F800(local_38);
        sub_62FC62(local_38);
    }
    local_30 = 0x8c1c50;
    local_2c = 0;
    sub_725750(0x8c1c50);
    local_2c = 1;
    local_28 = 0x78f6fc;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_4 = 6;
    sub_542160(local_34, local_14, (int)&local_28);
    sub_4434C0((int)&local_28);
    local_4 = 5;
    if (local_20 != 0) {
        sub_443450(local_20, local_1c, (int)&local_24, local_14);
        sub_62FC62(local_20);
    }
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_4 = 4;
    sub_725770(0x8c1c50);
    local_4 = 3;
    if (local_14 != 0) {
        sub_40F800(local_14);
        sub_62FC62(local_14);
    }
    sub_40FB40((int)&local_94);
    local_4 = 1;
    sub_77E65C((int)&local_100);
end:
    ;
}

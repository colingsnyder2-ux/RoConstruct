// from server: 99% by atomic.potato
extern "C" {
    int __cdecl sub_007224D0(int, int);
    int __cdecl sub_00721590(int, int);
    int __cdecl sub_00721660(int, int, int);
    int __cdecl sub_007219B0(int, int);
    int __cdecl sub_007218C0(int, int, int);
    int __cdecl sub_00720F60(int, int);
}

struct S_0060E9E0 {
    void __cdecl run(int a, int b, int c, int d, int e);
};

void S_0060E9E0::run(int a, int b, int c, int d, int e) {
    int g = *(int*)0xbe2a48;
    sub_007224D0((int)this, g);
    sub_00721590((int)this, 0xa31478);
    sub_00721660((int)this, c, 0);
    sub_007219B0((int)this, -3);
    sub_00721590((int)this, 0xa31598);
    sub_00721660((int)this, d, 0);
    sub_007219B0((int)this, -3);
    sub_00721590((int)this, 0xa31590);
    sub_00721660((int)this, 0x60ae00, 0);
    sub_007219B0((int)this, -3);
    sub_00721590((int)this, 0xa31588);
    sub_00721660((int)this, 0x60ae20, 0);
    sub_007219B0((int)this, -3);
    sub_00721590((int)this, 0xa3157c);
    sub_00721660((int)this, 0x60cd90, 0);
    sub_007219B0((int)this, -3);
    sub_007218C0((int)this, -1, 1);
    sub_00720F60((int)this, -2);
}

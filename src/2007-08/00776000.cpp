// from server: 100% by Espeon_2
struct S {
    void Init(int a, int b);
};

int __cdecl sub_5d35b0();
void __cdecl sub_630d23(int x);

void __cdecl sub_776000()
{
    int v = sub_5d35b0();
    ((S*)0x8c8038)->Init(v, 0x7c3c08);
    *(int*)0x8c8038 = 0x7c3b9c;
    sub_630d23(0x77c9d0);
}

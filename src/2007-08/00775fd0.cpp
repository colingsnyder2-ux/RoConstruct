// from server: 100% by colin
struct S {
    void Init(int a, int b);
};

int __cdecl sub_5d35b0();
void __cdecl sub_630d23(int x);

void __cdecl sub_775fd0()
{
    int v = sub_5d35b0();
    ((S*)0x8c81bc)->Init(v, 0x7c3bf8);
    *(int*)0x8c81bc = 0x7c3b9c;
    sub_630d23(0x77c9c0);
}

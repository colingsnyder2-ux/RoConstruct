// from server: 100% by atomic.potato
struct S {
    void Click(int a, int b);
};

int __cdecl sub_5d35b0();
void __cdecl sub_630d23(int x);

void __cdecl init_8c805c()
{
    int v = sub_5d35b0();
    ((S*)0x8c805c)->Click(v, 0x7c3bc8);
    *(int*)0x8c805c = 0x7c3b9c;
    sub_630d23(0x77c980);
}

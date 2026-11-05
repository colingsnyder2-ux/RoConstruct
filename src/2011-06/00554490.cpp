// from server: 100% by atomic.potato
extern "C" int __cdecl sub_563280(int, int, int);
extern "C" int __cdecl sub_5679e0(int, int, int);

int __cdecl sub_554490(int a, int b, int c) {
    int r = sub_563280(a, b, c);
    if (r < 0) {
        return 0;
    }
    return sub_5679e0(a, r, c);
}

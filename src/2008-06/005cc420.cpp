// from server: 100% by tester
struct S {
    char pad[0x1dc];
    int f1dc;
    int method();
};
extern char g92907c[], g948304[];
extern "C" int __cdecl sub_6A17C6(int, int, void*, void*, int);
int S::method() {
    if (f1dc != 0)
        return sub_6A17C6(f1dc, 0, g92907c, g948304, 0);
    return 0;
}

// from server: 100% by king_originala
struct PartInstance {
    int get();
};

extern "C" int __cdecl process(int value, int a, int b);

struct S {
    int f(int a, int b);
};

int S::f(int a, int b) {
    return process(((PartInstance*)((char*)this - 0x1cc))->get(), a, b);
}

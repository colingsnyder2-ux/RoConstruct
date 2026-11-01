// from server: 100% by king_originala
extern "C" void __cdecl finish(const char*, int);

struct S {
    void prepare(int, const char*);
    void f(int, int, const char*);
};

void S::f(int a, int b, const char* text)
{
    prepare(a, text);
    finish(text, b);
}

// from server: 100% by king_originala
extern char data_0060a2f0;

struct Source
{
    int func_00553830(void *);
};

struct Result
{
    void func_00553810(int);
};

extern Result *__cdecl func_0054c630(int, int);

struct S
{
    void func_00553620(int, int, Source *, int);
};

#pragma optimize("", off)
void S::func_00553620(int, int value, Source *source, int)
{
    func_0054c630(value, 0)->func_00553810(
        source->func_00553830(&data_0060a2f0));
}
#pragma optimize("", on)

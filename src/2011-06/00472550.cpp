// from server: 43% by atomic.potato
struct VerbBinder_00472550 {
    int bind(int, int, int, int);
};

extern "C" int __fastcall call_00471850(int, int, int, int, int*);

int __thiscall VerbBinder_00472550::bind(int a, int b, int c, int d)
{
    int e = 0;
    char f = 0;
    call_00471850(d, c, f, (int)this + 4, &e);
    return d;
}

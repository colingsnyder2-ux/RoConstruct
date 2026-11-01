// from server: 100% by king_originala
struct Guard {
    int* value;
    int mode;
    bool active;
    bool* flag;

    Guard(int* p, int m, bool* f);
    ~Guard();
};

inline Guard::Guard(int* p, int m, bool* f)
    : value(p), mode(m), active(true), flag(f)
{
}

extern int __cdecl process(int*, int*, int, int, int);

int __cdecl function(int first, int second, int third)
{
    bool flag = false;
    volatile int empty;
    Guard firstGuard(&first, 1, &flag);
    Guard secondGuard(&second, 2, &flag);
    return process(&first, &second, third, empty, empty);
}

// from server: 100% by king_originala
struct Empty {};

struct FirstGuard
{
    int* value;
    int mode;
    bool active;
    bool* state;

    FirstGuard(int* p, bool* s)
        : value(p), mode(1), active(true), state(s) {}
    ~FirstGuard();
};

struct SecondGuard
{
    int* value;
    int mode;
    bool active;
    bool* state;

    SecondGuard(int* p, bool* s)
        : value(p), mode(2), active(true), state(s) {}
    ~SecondGuard();
};

extern int __cdecl process(int*, int*, int, Empty, Empty);

int __cdecl reconstruct(int first, int second, int third)
{
    bool state = false;
    Empty empty1;
    Empty empty2;
    FirstGuard firstGuard(&first, &state);
    SecondGuard secondGuard(&second, &state);
    return process(&first, &second, third, empty1, empty2);
}

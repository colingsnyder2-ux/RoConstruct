// from server: 100% by king_originala
struct EmptyOne {};
struct EmptyTwo {};

struct GuardOne {
    int* value;
    int count;
    bool active;
    bool* flag;
    ~GuardOne();
};

struct GuardTwo {
    int* value;
    int count;
    bool active;
    bool* flag;
    ~GuardTwo();
};

int __cdecl func_00451210(int*, int*, int, EmptyOne, EmptyTwo);

int __cdecl func_00451300(int first, int second, int third)
{
    bool flag = false;
    EmptyOne tagOne;
    EmptyTwo tagTwo;
    GuardOne one = { &first, 1, true, &flag };
    GuardTwo two = { &second, 2, true, &flag };
    return func_00451210(&first, &second, third, tagOne, tagTwo);
}

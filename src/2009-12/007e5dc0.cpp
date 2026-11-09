// from server: 65% by atomic.potato
extern "C" int __cdecl sub_7e5b60(int);
extern "C" int __cdecl sub_7e5d40(int);

extern int dword_B64AE8;

struct RBX_Log {
};

int __cdecl method(int a, int b)
{
    int v = b - 1;
    if (v != 0) {
        if (dword_B64AE8 > 1)
            sub_7e5d40(a);
        else
            sub_7e5b60(a);
    } else {
        v = v - 1;
        if (v != 0)
            sub_7e5d40(a);
        else
            sub_7e5b60(a);
    }
    return a;
}

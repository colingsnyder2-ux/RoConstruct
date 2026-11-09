// from server: 97% by atomic.potato
struct S_func_005215e0 {
    char pad[4];
    void* field4;
    int f(int a1, int a2);
};

extern "C" int __stdcall sub_00521170(void* p, int a1, int a2);

int S_func_005215e0::f(int a1, int a2)
{
    void* p = field4;
    int r = sub_00521170(p, a1, a2);
    switch (r) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return 0;
}

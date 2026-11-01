// from server: 100% by colin
struct S_func_00408410 {
    static int* table[4];
    int f(int, int*);
};

int* S_func_00408410::table[4];

int S_func_00408410::f(int, int* p)
{
    unsigned int i = 0;
    do {
        int* e = *(int**)((char*)table + i);
        if (e[0] == p[0] && e[1] == p[1] && e[2] == p[2] && e[3] == p[3])
            return 0;
        i += 4;
    } while (i < 4);
    return 1;
}

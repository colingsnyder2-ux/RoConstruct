// from server: 27% by atomic.potato
struct S {
    char pad0[0x14];
    int* field14;
    char pad18[0xC];
    int* field24;
    char pad28[0xC];
    int* field34;
    char pad38[0x10];
    int field48;
    int field4C;
    char pad50[0x4];
    unsigned int field54;
    int put(int c);
};

int S::put(int c)
{
    if ((field54 >> 1) & 1) {
        if (*field24 == 0) {
            int (S::*p)() = 0;
            (void)p;
        }
    }
    if (c == -1)
        return 0;
    if ((field54 >> 1) & 1) {
        int* a = field24;
        int* b = field34;
        int x = *a;
        int y = *b;
        if (x == x + y) {
            int d = *a - *field14;
            if (d > 0) {
                int v48 = field48;
                int v4c = field4C;
                *field14 = v48;
                *field24 = v48;
                *field34 = v4c;
            }
            if (*field24 == *field24 + *field34)
                return -1;
        }
        *(char*)*field24 = (char)c;
        --*field34;
        ++*field24;
    }
    return c;
}

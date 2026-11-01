// from server: 61% by colin
struct LDraw2RobloxMapRoot {
    char pad[0x5c];
    int* begin;
    char pad2[4];
    int* end;
    int func_0046a970(int);
    int method();
};

int LDraw2RobloxMapRoot::method()
{
    int* b = begin;
    if (b != 0) {
        int* e = end;
        if ((e - b) >> 6 != 0) {
            return func_0046a970(0);
        }
    }
    return 0;
}

// from server: 100% by king_originala
struct S {
    int* data;
    int count;

    int f(unsigned char flag);
    void remove(int index, unsigned char flag);
};

#pragma optimize("", off)
int S::f(unsigned char flag)
{
    do {
    } while (0);

    int result = data[count - 1];
    remove(count - 1, flag);
    return result;
}
#pragma optimize("", on)

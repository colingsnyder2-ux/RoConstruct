// from server: 31% by atomic.potato
void func_006d2d30(int* a, int* b, int* c)
{
    if (b != c) {
        do {
            c--;
            b--;
            *c = *b;
        } while (b != c);
    }
    *a = (int)c;
}

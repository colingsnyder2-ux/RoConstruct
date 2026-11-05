// from server: 20% by atomic.potato
struct ChatLine {
    char pad0[8];
    void sub_93D1C0(int, int, int, int);
    void func(int* a, int b, int c, int d);
};

void ChatLine::func(int* a, int b, int c, int d) {
    int v = *a;
    int local;
    char flag = 0;
    sub_93D1C0(v, b, c, d);
}

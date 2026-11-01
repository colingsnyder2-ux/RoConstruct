// from server: 100% by king_originala
struct Receiver
{
    unsigned char func_0049d770(int a, int b);
};

struct S
{
    int unused;
    Receiver* receiver;
    int func_0049df50(int a, int b);
};

int S::func_0049df50(int a, int b)
{
    return receiver->func_0049d770(a, b) != 0;
}

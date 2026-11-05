// from server: 18% by atomic.potato
struct S
{
    int field10;
    int field14;
    int field18;

    int get();
};

int S::get()
{
    return field10 + field14 + field18;
}

// from server: 27% by atomic.potato
struct S {
    int (*field10)(int, int);
    int field14;
    int field18;
    int field1c;
    int f();
};

int S::f()
{
    return field10(field14 + field18, field1c);
}

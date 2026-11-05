// from server: 100% by atomic.potato
struct S
{
    int IsActionStation();
    int pad[162];
    int value;
};

int S::IsActionStation()
{
    return value == 1;
}

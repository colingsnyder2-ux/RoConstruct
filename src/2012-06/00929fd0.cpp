// from server: 100% by tester
struct PolyPair
{
    int unused;
    int first;
    int second;
    int contains(int value);
};

int PolyPair::contains(int value)
{
    if (first == value || second == value)
        return 1;
    return 0;
}

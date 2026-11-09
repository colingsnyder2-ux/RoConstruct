// from server: 100% by atomic.potato
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

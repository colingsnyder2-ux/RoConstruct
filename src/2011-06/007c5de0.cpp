// from server: 100% by atomic.potato
struct PolyPair {
    int f(int value);
    int unused;
    int first;
    int second;
};

int PolyPair::f(int value)
{
    if (first == value || second == value)
        return 1;
    return 0;
}

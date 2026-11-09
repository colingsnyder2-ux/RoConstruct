// from server: 30% by atomic.potato
struct EdgeEdgePair
{
    int get(int index);
    int data;
};

int EdgeEdgePair::get(int index)
{
    return index * 20 + data;
}

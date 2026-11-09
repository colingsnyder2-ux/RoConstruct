// from server: 47% by atomic.potato
struct S
{
    int Get(int index);
    int *items;
    int count;
};

int S::Get(int index)
{
    if (index < 0 || index >= count)
        index = 0;
    else
        index = items[index];

    return index;
}

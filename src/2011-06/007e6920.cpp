// from server: 100% by atomic.potato
struct S
{
    int *unused[5];
    int **data;
    int get(int index);
};

int S::get(int index)
{
    int *value = data[index];
    if (this == (S *)value[1])
        return value[3];
    return value[4];
}

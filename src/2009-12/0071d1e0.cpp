// from server: 100% by atomic.potato
struct NonFactoryProduct
{
    int get();
};

int NonFactoryProduct::get()
{
    int index = *(int *)((char *)this + 4);
    int **object = *(int ***)this;
    int *table = *(int **)((char *)object + 0x168);
    return table[index + 0x10c / 4];
}

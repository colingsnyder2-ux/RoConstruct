// from server: 60% by atomic.potato
struct S_func_009782a0 {
    int __cdecl f(int* first, int* last, int* result, int (*op)(int, int));
};

int S_func_009782a0::f(int* first, int* last, int* result, int (*op)(int, int))
{
    while (first != last) {
        op(*first, 0);
        first += 2;
    }
    result[0] = (int)first;
    result[1] = (int)last;
    return (int)result;
}

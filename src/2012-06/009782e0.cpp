// from server: 25% by atomic.potato
struct S_func_009782e0 {
    int __cdecl f(int* result, int* first, int* last, int* value);
};

int S_func_009782e0::f(int* result, int* first, int* last, int* value)
{
    int* cur = first;
    while (cur != last) {
        int* elem = (int*)*cur;
        if (((char (*)(int*))value)(elem)) {
            break;
        }
        cur += 2;
    }
    *result = (int)cur;
    return (int)result;
}

// from server: 100% by colin
struct S {
};

int __cdecl f(int* first, int* last, int* value, bool (*pred)(int, int))
{
    int count = (int)(last - first);
    if (count > 0) {
        while (count > 0) {
            int half = count / 2;
            if (pred(first[half], *value)) {
                first += half + 1;
                count -= half + 1;
            } else {
                count = half;
            }
        }
    }
    return (int)first;
}

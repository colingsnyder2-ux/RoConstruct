// from server: 0% by atomic.potato
extern "C" void __stdcall helper_004f3180(void*, int, int, int);

void func_004f3180(int* first, int* last, int* dest)
{
    int* cur = dest;
    while (first != last) {
        int* src = first;
        if (cur != 0) {
            int obj = *src;
            if (obj != 0) {
                int* vtbl = *(int**)obj;
                int (*fn)(void*) = *(int (**)(void*))(vtbl + 8);
                *cur = fn((void*)obj);
                cur++;
            }
        }
        first++;
    }
}

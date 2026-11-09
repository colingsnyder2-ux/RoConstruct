// from server: 47% by atomic.potato
struct S_func_0070b100 {
    char pad0[4];
    int m_count;
    int* m_array;
    int __cdecl f(int* a, int* b);
};

extern "C" int __cdecl sub_008c3216(int, int, int, int, int*, int*);
extern "C" int __cdecl sub_008c3210();

int S_func_0070b100::f(int* a, int* b)
{
    int i;
    int j;
    if (m_count <= 0) {
        return sub_008c3210();
    }
    sub_008c3216(0, m_count - 1, 1, 1, &j, &i);
    if (i <= j) {
        do {
            int* p = (int*)m_array[i];
            ((void (__thiscall*)(void*, int))*(void**)(*(int*)p + 8))(p, *(unsigned char*)b);
            i++;
        } while (i <= j);
    }
    return sub_008c3210();
}

// from server: 50% by atomic.potato
typedef unsigned char BYTE;

extern BYTE g_flag_00e580b3;
extern int* g_ptr_00e5809c;
extern "C" void __cdecl function_00972290(int, const char*);

struct S_func_0081c120 {
    char pad0[224];
    int m_x;
    int* f();
};

struct S {
    int** m_array;
    int* get(int index);
};

int* S::get(int index)
{
    if (g_flag_00e580b3 != 0)
    {
        return m_array[index];
    }

    int* p = ((S_func_0081c120*)m_array[index])->f();
    if (*p == index)
    {
        return m_array[index];
    }

    if (g_ptr_00e5809c != 0)
    {
        if (((int (__cdecl*)(int, const char*, const char*))g_ptr_00e5809c)(0x67, (const char*)0x00b7b540, (const char*)0x00b7b524))
        {
            return m_array[index];
        }
    }

    function_00972290((int)g_flag_00e580b3, (const char*)0x00b7b4a8);
    return m_array[index];
}

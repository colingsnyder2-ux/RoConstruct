// from server: 100% by colin
extern void (__cdecl *free_ptr)(void*);

struct S {
    void* m_ptr;
    int m_count;
    void Release();
};

void S::Release()
{
    if (m_count > 0)
    {
        free_ptr(m_ptr);
    }
}

// from server: 40% by atomic.potato
struct CString
{
    void* m_pData;
    CString();
    CString(const CString&);
    ~CString();
    bool IsEmpty() const;
};

struct CStringArray
{
    CString* m_pData;
    int m_nSize;
};

extern "C" void __stdcall sub_a42de4(CString* self, const char* src);
extern "C" void __stdcall sub_a429f0(CString* self);
extern "C" bool __stdcall sub_a426b0(const CString* self);
extern "C" void __stdcall sub_a42e08(CString* self);
extern "C" int __stdcall sub_8100f0(int a, int b, int c, int d, int e, int f, int g, int h);

int __stdcall func_0085dfb0(const char* a1, const char* a2, const char* a3,
                            CStringArray* a4, CStringArray* a5, CStringArray* a6)
{
    CString s1;
    CString s2;
    CString s3;

    sub_a42de4(&s1, a1);
    sub_a42de4(&s2, a2);
    sub_a42de4(&s3, a3);

    a4->m_pData = 0;
    a4->m_nSize = 0;
    a5->m_pData = 0;
    a5->m_nSize = 0;
    a6->m_pData = 0;
    a6->m_nSize = 0;

    if (!sub_a426b0(&s1))
    {
        if (sub_a426b0(&s2))
        {
            if (sub_a426b0(&s3))
            {
                int v = (int)s1.m_pData;
                a4->m_pData = (CString*)v;
                int r = sub_8100f0(0x410, (int)&s1, (int)s2.m_pData, 0, 0, 0x7d00, 0, 0);
                a4->m_nSize = r;
                sub_a42e08(&s3);
                sub_a42e08(&s2);
                sub_a42e08(&s1);
                return r;
            }
        }
    }

    if (sub_a426b0(&s1))
    {
        if (!sub_a426b0(&s2))
        {
            if (sub_a426b0(&s3))
            {
                int v = (int)s1.m_pData;
                a5->m_pData = (CString*)v;
                int r = sub_8100f0(0x411, (int)&s1, (int)s3.m_pData, 0, 0, 0x7d00, 0, 0);
                a5->m_nSize = r;
                sub_a42e08(&s3);
                sub_a42e08(&s2);
                sub_a42e08(&s1);
                return r;
            }
        }
    }

    if (sub_a426b0(&s1))
    {
        if (sub_a426b0(&s2))
        {
            if (!sub_a426b0(&s3))
            {
                int v = (int)s1.m_pData;
                a6->m_pData = (CString*)v;
                int r = sub_8100f0(0x412, (int)&s1, (int)s2.m_pData, 0, 0, 0x7d00, 0, 0);
                a6->m_nSize = r;
                sub_a42e08(&s3);
                sub_a42e08(&s2);
                sub_a42e08(&s1);
                return r;
            }
        }
    }

    sub_a42e08(&s3);
    sub_a42e08(&s2);
    sub_a42e08(&s1);
    return -1;
}

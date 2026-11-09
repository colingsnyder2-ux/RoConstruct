// from server: 100% by colin
struct CXTPResourceManager {
    char m_bInit;
    int m_nHandle;
    void Init();
};

struct Helper {
    int sub_6B2C10();
};

extern "C" Helper* __stdcall func_006b3010();
extern "C" void* __stdcall func_0062ff02();

void CXTPResourceManager::Init()
{
    Helper* p = func_006b3010();
    int r = p->sub_6B2C10();
    if (r == 0)
    {
        m_bInit = 0;
        return;
    }
    void* q = func_0062ff02();
    int* pi = (int*)q;
    m_nHandle = pi[3];
    Helper* p2 = func_006b3010();
    int r2 = p2->sub_6B2C10();
    pi[3] = r2;
    m_bInit = 1;
}

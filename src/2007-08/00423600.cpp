// from server: 72% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CSelectionTreeCtrl {
    char pad[0xe4];
    int m_fieldE4;
    int m_fieldE8;
    void getPair(int* out);
};

void CSelectionTreeCtrl::getPair(int* out) {
    out[0] = m_fieldE4;
    int* p = (int*)m_fieldE8;
    out[1] = (int)p;
    if (p == 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    }
}

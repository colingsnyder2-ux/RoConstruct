// from server: 72% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Listener {
    char pad[0x1d8];
    int m_listener;
    int m_query;
    void get(int* out);
};

void Listener::get(int* out) {
    out[0] = this->m_listener;
    int q = this->m_query;
    out[1] = q;
    if (q == 0) {
        _InterlockedExchangeAdd((volatile long*)(q + 4), 1);
    }
}

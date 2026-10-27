extern "C" long __cdecl _InterlockedExchangeAdd(volatile long *addend, long value);

struct SpCounted {
    long m_ref_count;

    long add_ref();
};

long SpCounted::add_ref() {
    long old_count = _InterlockedExchangeAdd(&m_ref_count, 1);
    return old_count + 1;
}
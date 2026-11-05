// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern char instanceType;
extern char itemType;
extern "C" void* __cdecl dynamicCast(void*, long, void*, void*, int);

__forceinline void incrementReference(volatile long* count) {
    _InterlockedExchangeAdd(count, 1);
}

struct Reference {
    long reserved;
    volatile long count;
};

struct Pair {
    void* first;
    Reference* firstReference;
    void* second;
    Reference* secondReference;

    Pair(const Pair&);
    ~Pair();
};

__forceinline Pair::Pair(const Pair& other) {
    first = other.first;
    firstReference = other.firstReference;
    if (firstReference)
        incrementReference(&firstReference->count);
    second = other.second;
    secondReference = other.secondReference;
    if (secondReference)
        incrementReference(&secondReference->count);
}

struct CSettingsExplorer {
    void forward(int, Pair);
    void process(int, Pair);
};

void CSettingsExplorer::process(int value, Pair objects) {
    if (dynamicCast(objects.first, 0, &instanceType, &itemType, 0))
        forward(value, objects);
}

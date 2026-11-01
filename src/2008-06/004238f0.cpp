// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

extern void* __cdecl func_006a0920(unsigned int);

struct RefCount
{
    long reserved;
    volatile long count;
};

struct SharedValue
{
    void* value;
    RefCount* reference;
};

struct Node
{
    Node* first;
    Node* second;
    Node* third;
    SharedValue shared;
    unsigned char flag;
    unsigned char state;
};

Node* __stdcall func_004238f0(Node* first, Node* second, Node* third,
                            const SharedValue& shared, unsigned char flag)
{
    Node* result = static_cast<Node*>(func_006a0920(24));
    if (result)
    {
        result->first = first;
        result->second = second;
        result->third = third;
        result->shared.value = shared.value;
        result->shared.reference = shared.reference;
        if (result->shared.reference)
        {
            volatile long* count = &result->shared.reference->count;
            _ReadWriteBarrier();
            _InterlockedExchangeAdd(count, 1);
        }
        result->flag = flag;
        result->state = 0;
    }
    return result;
}

// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct MediaQueryListListener;
struct MediaQueryList;

struct Listener {
    void evaluate(void* scriptState, void* evaluator);
};

struct MediaQueryMatcher {
    char pad0[0x58];
    float m_a;
    char pad1[4];
    float m_b;
    char pad2[0x194 - 0x64];
    void* m_listener;
    void* m_query;
};

struct RefPtrHolder {
    void* ptr;
    void* refcount;
};

extern "C" void __cdecl sub_630D60();
extern "C" void __cdecl sub_5086F0();
extern "C" void __cdecl sub_40D550();
extern "C" void __cdecl sub_559670();
extern "C" void __cdecl sub_5595A0();

void Listener::evaluate(void* scriptState, void* evaluator)
{
    MediaQueryMatcher* matcher = (MediaQueryMatcher*)this;
    float diff = matcher->m_b - matcher->m_a;
    unsigned short v1 = (unsigned short)(int)diff;
    sub_630D60();
    unsigned short v2 = (unsigned short)(int)diff;
    sub_5086F0();
    void* p1 = matcher->m_listener;
    void* p2 = matcher->m_query;
    RefPtrHolder holder;
    holder.ptr = p1;
    holder.refcount = p2;
    if (holder.refcount) {
        _InterlockedExchangeAdd((volatile long*)((char*)holder.refcount + 4), 1);
    }
    sub_40D550();
    sub_559670();
    sub_5595A0();
}

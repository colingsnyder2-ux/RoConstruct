// from server: 91% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(volatile long*);

extern const char g_Name[];
extern void* g_009a2cc4;

struct CInstanceRecord_CNameItem
{
    void* value;
    void f();
};

void CInstanceRecord_CNameItem::f()
{
    value = (void*)&g_009a2cc4;
    InterlockedDecrement((volatile long*)g_Name);
}

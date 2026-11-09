// from server: 5% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall GetProcessHeap();
extern "C" void* __stdcall HeapAlloc(void*, unsigned long, unsigned long);
extern "C" int __stdcall HeapFree(void*, unsigned long, void*);

struct RefCounted {
    void addRef();
    void release();
};

struct Item {
    void construct();
    void setValue(int);
    void update();
};

struct RenderStatsItem : Item {
    void construct();
    void setValue(int);
    void update();
    void init();
};

void RenderStatsItem::init()
{
    construct();
    setValue(0);
    *(int*)((char*)this + 0x58) = 2;
    update();
    Item::update();
}

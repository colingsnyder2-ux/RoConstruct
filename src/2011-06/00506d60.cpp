// from server: 72% by atomic.potato
extern "C" int __cdecl func_0065d0d0(int);

struct Helper
{
    void method(const char*, const char*);
};

struct EventInvocationItem
{
    void construct(int, int);
};

void EventInvocationItem::construct(int a, int b)
{
    Helper* obj = (Helper*)func_0065d0d0(a);
    obj->method((const char*)0xa7bb98, (const char*)(b + 0));
    obj->method((const char*)0xa7bb88, (const char*)(b + 8));
    obj->method((const char*)0xa7bb78, (const char*)(b + 16));
    obj->method((const char*)0xa7bb68, (const char*)(b + 24));
}

// from server: 31% by atomic.potato
extern "C" void __stdcall sub_0098B6E8();
extern "C" void __stdcall sub_0098B6E4();

struct GuidScope
{
    static GuidScope* getLocalScope();
};

struct GlobalSettings
{
    bool isSomething();
};

struct VContentId
{
    bool equals(VContentId& other);
};

struct TypedPropertyDescriptor
{
    bool func_00645110(VContentId& id, int a2, int a3, int a4);
};

bool TypedPropertyDescriptor::func_00645110(VContentId& id, int a2, int a3, int a4)
{
    if (id.equals(id))
        return true;

    char buf[8];
    sub_0098B6E8();
    int flag = 0;
    GuidScope* scope = GuidScope::getLocalScope();
    int saved = 0;
    GlobalSettings* gs = (GlobalSettings*)scope;
    if (gs->isSomething())
    {
        void* p = *(void**)((char*)this + 0x1c);
        void** vt = *(void***)p;
        void (*fn)(void*, int, char*) = (void (*)(void*, int, char*))vt[4];
        fn(p, a2, buf);
    }
    sub_0098B6E4();
    return false;
}

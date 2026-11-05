// from server: 100% by atomic.potato
struct EventDesc
{
    bool f();
};

extern "C" EventDesc *__cdecl getLocalScope();

bool EventDesc::f()
{
    return getLocalScope() == this;
}

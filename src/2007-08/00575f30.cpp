// from server: 91% by tajop
typedef void (__cdecl* InvalidParamFn)();
extern const InvalidParamFn g_invalid_parameter_noinfo;

struct Listener;

struct Event
{
    char value;
    Event(const Event& o) : value(o.value) {}
};

struct ListenerVector
{
    void* proxy;
    Listener** first;
    Listener** last;
    Listener** endOfStorage;

    unsigned size() const { return first == 0 ? 0 : (unsigned)(last - first); }
    Listener* at(unsigned pos, InvalidParamFn fn) const
    {
        if (pos >= size())
            fn();
        return first[pos];
    }
};

struct RaiseContext
{
    unsigned index;
    unsigned count;
    RaiseContext* prev;
};

struct Notifier
{
    void* vtbl;
    ListenerVector listeners;
    RaiseContext* raising;

    void raise(Event e);
    void raiseTo(Event e, Listener* listener);
};

void Notifier::raise(Event e)
{
    RaiseContext ctx;
    ctx.index = 0;
    ctx.count = listeners.size();
    ctx.prev = raising;
    raising = &ctx;
    InvalidParamFn fn = g_invalid_parameter_noinfo;
    for (; ctx.index < ctx.count; ++ctx.index)
        raiseTo(e, listeners.at(ctx.index, fn));
    raising = ctx.prev;
}

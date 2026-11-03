// from server: 100% by EspClaude
// roc 2007-08 0042b590  stdcall Release of a hand-rolled COM-style event sink
typedef void* (__cdecl *SinkFn)(void* context, int release);
struct SinkCallback {
    SinkFn fn;
    void* context;
    int extra;
    bool empty() const { return fn == 0; }
    void release() { context = fn(context, 1); }
};
struct EventSink {
    void* vtbl;
    SinkCallback callback;
    long refCount;
};

unsigned long __stdcall EventSink_Release(EventSink* self)
{
    if (--self->refCount == 0) {
        if (!self->callback.empty())
            self->callback.release();
        self->callback.fn = 0;
        self->callback.extra = 0;
        delete self;
        return 0;
    }
    return self->refCount;
}

// from server: 100% by EspClaude
// roc 2009-06 005d6050
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Mutex { int h; };
class ScopedLock {
public:
    ScopedLock(Mutex& m);
    ~ScopedLock();
private:
    Mutex* m; bool locked;
};
class Sink { public: void handle(int a, int b); };
struct Shared {
    int refs;
    char pad;
    volatile bool enabled;
    char pad2[2];
    Mutex mutex;
    char pad3[0xc];
    Sink sink;
};
void dispatch(Shared* s, int a, int b)
{
    ScopedLock lock(s->mutex);
    if (s->enabled)
        s->sink.handle(a, b);
}
}

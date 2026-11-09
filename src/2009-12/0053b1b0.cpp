// from server: 64% by atomic.potato
typedef void *(*Fn539df0)(void *);
typedef void (*Fn533390)(void *, void *);

extern "C" void *Call539df0(void *);
extern "C" void Call533390(void *, void *);

void Function(void *p)
{
    char local[12];
    void *value = Call539df0(local);
    Call533390(p, value);
}

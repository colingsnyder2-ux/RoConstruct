// from server: 100% by coldek
template<class T> inline T roc_val(T v) { return v; }
struct Scope
{
    const char* name;
    void* previous;
    bool enabled;
    double startTime;

    Scope(const char*, bool);
    ~Scope();
};

struct Item
{
    virtual ~Item();
    virtual void step(float, bool);
    virtual bool inactive();
};

struct Phase
{
    void begin();
    void end();
};

struct Node
{
    void step(bool);
};

struct Source
{
    const void* get();
};

template<class T> struct Array
{
    T** data;
    int count;
    int capacity;
};

struct ItemArray
{
    Item** data;
    int count;
    int capacity;

    void clear(int, int);
    __declspec(noalias) void append(Item* const&);
};

struct State
{
    Array<Node> nodes;
    Array<Source> sources;
    Array<Phase> phases;
    Array<Item> items;
    Array<Item> extraItems;
};

extern float __cdecl timeStep();
extern int __cdecl stepCount();

struct Kernel
{
    char reserved[12];
    bool running;
    char padding[3];
    State* state;
    ItemArray active;
    const char* name;

    void fallback(int);
    void f(int, float, bool, bool);
};

void Kernel::f(int delta, float unused, bool selective, bool alternate)
{
    if (alternate)
    {
        fallback(delta);
        return;
    }

    State* s = state;
    running = true;
    Scope scope(roc_val(name), false);

    if (selective)
    {
        active.clear(0, 0);
        for (int i = 0; i < s->items.count; ++i)
        {
            if (!s->items.data[i]->inactive())
            {
                Item* item = s->items.data[i];
                active.append(item);
            }
        }
    }

    float dt = timeStep();
    int count = stepCount();
    if (count > 0)
    {
        int steps = count;
        do
        {
            for (int i = 0; i < s->phases.count; ++i)
                s->phases.data[i]->begin();

            if (selective)
            {
                for (int i = 0; i < active.count; ++i)
                    active.data[i]->step(dt, selective);
            }
            else
            {
                for (int i = 0; i < s->items.count; ++i)
                    s->items.data[i]->step(dt, false);
            }

            for (int i = 0; i < s->phases.count; ++i)
                s->phases.data[i]->end();

            for (int i = 0; i < s->extraItems.count; ++i)
                s->extraItems.data[i]->step(dt, selective);

            for (int i = 0; i < s->nodes.count; ++i)
                s->nodes.data[i]->step(selective);

            for (int i = 0; i < s->sources.count; ++i)
                s->sources.data[i]->get();
        }
        while (--steps);
    }

    running = false;
}

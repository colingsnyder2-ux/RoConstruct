// from server: 100% by king_originala
extern "C" void* __cdecl allocate(unsigned int size);

struct Listener;

struct Task
{
    Task* initialize(Listener*, void*, Task*);
};

struct Pending
{
    char storage[28];
    void insert(Task**);
};

struct Dispatcher
{
    void method(int);
};

struct Listener
{
    void* vtable;
    Pending pending;
    Dispatcher* dispatcher;

    void f(void*, Task*);
};

void Listener::f(void* a, Task* b)
{
    Task* task = (Task*)allocate(0x14);
    if (task)
        task = task->initialize(this, a, b);
    else
        task = 0;

    b = task;
    pending.insert(&b);
    dispatcher->method((int)task);
}

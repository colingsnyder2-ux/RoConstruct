// from server: 100% by king_originala
typedef void (__cdecl *Task)();

union FunctionBuffer
{
    Task function;
    double storage[3];
};

typedef void (__cdecl *Manager)(FunctionBuffer *, FunctionBuffer *, int);

struct FunctionTable
{
    Manager manager;
};

extern FunctionTable taskTable;
extern void __cdecl taskEntry();

void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

struct Callback
{
    FunctionTable *table;
    FunctionBuffer buffer;

    Callback(Task);
    Callback(const Callback &);
};

inline Callback::Callback(Task task)
{
    table = 0;
    FunctionBuffer *destination = &buffer;
    if (taskTable.manager)
        taskTable.manager(destination, destination, 1);

    if (task)
    {
        destination->function = task;
        table = &taskTable;
    }
    else
    {
        table = 0;
    }
}

struct Thread
{
    unsigned char storage[32];

    Thread(Callback, unsigned int);
};

struct S
{
    void reset(Thread *);
    S &f();
};

S &S::f()
{
    reset(new Thread(Callback(taskEntry), 0));
    return *this;
}

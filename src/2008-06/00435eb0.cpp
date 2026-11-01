// from server: 100% by king_originala
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

struct Mutex
{
    void lock();
    void unlock();
};

Mutex* __cdecl getMutex();
void* __cdecl getDescriptor();

struct Lock
{
    Mutex* mutex;
    bool locked;

    Lock(Mutex*);
    ~Lock();
};

inline Lock::Lock(Mutex* p) : mutex(p)
{
    mutex->lock();
    locked = true;
}

inline Lock::~Lock()
{
    mutex->unlock();
}

struct Iterator
{
    unsigned int first;
    unsigned int second;
};

Iterator* __cdecl getEnd(Iterator*);
Iterator* __cdecl getBegin(Iterator*);

struct __multiple_inheritance CClassTreeView;
typedef void (CClassTreeView::*VisitFunction)(void*);

struct Function
{
    VisitFunction callback;
    CClassTreeView* object;
    int extra;
};

Function __cdecl visitRange(Iterator, Iterator, Function);
int __stdcall compareItems(long, long, long);

struct SortInfo
{
    void* parent;
    int (__stdcall *compare)(long, long, long);
    long parameter;
};

struct BaseFirst
{
    char storage[0x10];
};

struct BaseSecond
{
    char storage[0x10];
};

struct CClassTreeView : BaseFirst, BaseSecond
{
    void* window;

    void baseInitialize();
    void populate(void*);
    void visitItem(void*);
    void initialize();
};

void CClassTreeView::initialize()
{
    baseInitialize();
    Lock lock(getMutex());
    populate(getDescriptor());

    Function function;
    function.callback = &CClassTreeView::visitItem;
    function.object = this;

    Iterator endStorage;
    Iterator beginStorage;
    Iterator* end = getEnd(&endStorage);
    Iterator* begin = getBegin(&beginStorage);
    visitRange(*begin, *end, function);

    SortInfo sort;
    sort.parent = (void*)0xffff0000;
    sort.compare = compareItems;
    SendMessageA(window, 0x1115, 0, (long)&sort);
}

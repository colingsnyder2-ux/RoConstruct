// from server: 100% by king_originala
extern unsigned long baseTable[];
extern unsigned long secondaryTable[];
extern unsigned long registryTable[];
extern unsigned long listenerBaseTable[];
extern unsigned long listenerTable[];

struct Base {
    unsigned long* volatile tablePointer;
    char padding0[0x50];
    unsigned long* volatile secondaryTable;
    char padding1[0x138];

    Base();
    ~Base();
};

struct S {
    unsigned long* volatile tablePointer;

    S();
    ~S();
    S* initialize();
};

inline S::S()
{
    initialize();
}

struct ListenerBase {
    unsigned long* volatile tablePointer;
    char padding[0x20];

    ListenerBase();
    ~ListenerBase();
};

struct Listener : ListenerBase {
    Listener();
};

inline Listener::Listener()
{
    tablePointer = listenerBaseTable;
}

struct FilteredListener : Base {
    S registryEntry;
    Listener listener;
    volatile unsigned long first;
    volatile unsigned long second;
    volatile unsigned long third;
    volatile unsigned long fourth;

    FilteredListener();
};

FilteredListener::FilteredListener()
{
    tablePointer = baseTable;
    Base::secondaryTable = ::secondaryTable;
    registryEntry.tablePointer = registryTable;
    listener.tablePointer = listenerTable;
    first = 0;
    second = 0;
    third = 0;
    fourth = 0;
}

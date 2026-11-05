// from server: 100% by king_originala
struct Name {
    const char* text() const;
};

struct LogHandle {
    void* data[2];
    void* f();
    ~LogHandle();
};

extern LogHandle __cdecl getLog();
extern void __cdecl writeLog(void*, int, const char*, ...);
extern const Name& __cdecl getLocalScope();

struct Link {
    int value;
    int next;
};

#pragma optimize("", off)

void __cdecl report(const Name* first, const Name* second,
                    int number, const Name* last)
{
    writeLog(getLog().f(), 1,
             "Replicator: Last item %d, Last name %s",
             number, last ? last->text() : "NULL");

    writeLog(getLog().f(), 3,
             "Replicator: Can't find object for %s:%d",
             first->text(), second);

    const Name* scope = second;
    int local = first == &getLocalScope();

    do {
        Link* link = 0;
        link->value = link->next;
    } while (false);
}

#pragma optimize("", on)

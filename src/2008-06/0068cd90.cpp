// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S;
struct Query;

struct QueryTable {
    void* reserved;
    void (__thiscall *setMask)(Query*, unsigned int);
};

extern QueryTable queryTable;
extern void* secondaryTable[];
extern Query* (__thiscall *baseConstructor)(Query*, S*);

struct Query {
    QueryTable* table;
    char padding[0x30];
    void** secondary;
    unsigned int reserved;

    Query(S*);
};

struct S {
    Query* createQuery(unsigned int);
};

__forceinline Query::Query(S* owner)
{
    baseConstructor(this, owner);
    table = &queryTable;
    secondary = secondaryTable;
}

Query* S::createQuery(unsigned int mask)
{
    Query* query = new Query(this);
    query->table->setMask(query, mask);
    return query;
}

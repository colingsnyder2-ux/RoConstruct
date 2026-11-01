// from server: 100% by king_originala
struct SceneManager;
struct Query;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

typedef void (__thiscall *QueryMethod)(Query*, unsigned int);

struct QueryVTable
{
    void* slot0;
    QueryMethod setMask;
    void* slots2to7[6];
    void (__thiscall *setRay)(Query*, const void*);
};

extern QueryVTable queryVTable;
extern void* secondaryVTable[];
extern void (__thiscall *DefaultRaySceneQueryConstructor)(Query*, SceneManager*);

struct Query
{
    QueryVTable* vtable;
    char primaryData[48];
    void** secondary;
    char secondaryData[52];

    Query(SceneManager*);
};

struct SceneManager
{
    Query* createRayQuery(const void*, unsigned int);
};

__forceinline Query::Query(SceneManager* manager)
{
    DefaultRaySceneQueryConstructor(this, manager);
    vtable = &queryVTable;
    secondary = secondaryVTable;
}

Query* SceneManager::createRayQuery(const void* ray, unsigned int mask)
{
    Query* query = new Query(this);
    query->vtable->setRay(query, ray);
    query->vtable->setMask(query, mask);
    return query;
}

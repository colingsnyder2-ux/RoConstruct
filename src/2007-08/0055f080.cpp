// from server: 87% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Node
{
    Node* next;
};

struct Item
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Node* getNode();
};

struct NodeList
{
    int pad;
    Node* head;
    Node* tail;
};

struct CountedBase
{
    virtual ~CountedBase();
    virtual void dispose() = 0;
    virtual void destroy();
    long useCount;
    long weakCount;

    void release()
    {
        if (_InterlockedDecrement(&useCount) == 0)
        {
            dispose();
            if (_InterlockedDecrement(&weakCount) == 0)
                destroy();
        }
    }
};

struct ItemPtr
{
    Item* px;
    CountedBase* pn;

    ~ItemPtr()
    {
        if (pn)
            pn->release();
    }
};

void collectBackpackItem(NodeList* list, ItemPtr item)
{
    Node* n = item.px->getNode();
    if (n)
    {
        if (list->tail == 0)
            list->head = n;
        else
            list->tail->next = n;
        list->tail = n;
    }
}

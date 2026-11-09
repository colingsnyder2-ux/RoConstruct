// from server: 37% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Node
{
    Node* next;
    Node* prev;
    long refCount;
    long weakCount;
    virtual void Release();
    virtual void WeakRelease();
};

struct ListHead
{
    Node* head;
};

struct NotificationBox
{
    ListHead* list;
    int count;
    void Clear();
};

void __cdecl operator_delete(void*);

void NotificationBox::Clear()
{
    Node* sentinel = list->head;
    Node* current = sentinel->next;
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    count = 0;

    while (current != sentinel)
    {
        Node* nextNode = current->next;
        if (current->refCount != 0)
        {
            long oldRef = _InterlockedExchangeAdd(&current->refCount, -1);
            if (oldRef == 1)
            {
                current->Release();
            }
        }
        if (current->weakCount != 0)
        {
            long oldWeak = _InterlockedExchangeAdd(&current->weakCount, -1);
            if (oldWeak == 1)
            {
                current->WeakRelease();
            }
        }
        operator_delete(current);
        current = nextNode;
    }
}

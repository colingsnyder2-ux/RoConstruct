// from server: 100% by atomic.potato
struct S
{
    int *f(int);
};

struct Node
{
    int pad[6];
    Node *next;
};

extern "C" void __declspec(dllimport) __stdcall EnterCriticalSection(void *);
extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(void *);
extern "C" Node *__cdecl CreateNode();

S *__cdecl g_lock;

int *S::f(int flags)
{
    S *self = this;

    if (flags & 1)
    {
        Node *node = CreateNode();
        EnterCriticalSection(node);
        *(Node **)self = node->next;
        node->next = (Node *)self;
        LeaveCriticalSection(node);
    }

    return (int *)self;
}

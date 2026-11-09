// from server: 44% by atomic.potato
typedef unsigned long DWORD;

struct CRITICAL_SECTION
{
    DWORD data[6];
};

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct Node
{
    Node *next;
};

extern "C" Node *__cdecl GetNode();

struct NormalBreakConnector
{
    Node *next;
    NormalBreakConnector *f(unsigned int);
};

NormalBreakConnector *NormalBreakConnector::f(unsigned int flags)
{
    if ((flags & 1) != 0)
    {
        Node *node = GetNode();
        EnterCriticalSection((CRITICAL_SECTION *)0xa40384);
        next = node->next;
        node->next = (Node *)this;
        LeaveCriticalSection((CRITICAL_SECTION *)0xa40380);
    }
    return this;
}

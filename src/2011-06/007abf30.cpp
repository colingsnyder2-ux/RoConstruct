// from server: 77% by atomic.potato
struct InnerNode
{
    int a;
    int b;
    int c;
    int d;
    InnerNode* next;
};

struct InnerContainer
{
    int a;
    int b;
    InnerNode* first;
};

struct S
{
    int count;
    int pad1;
    int pad2;
    int pad3;
    S* next;
    InnerContainer* container;
};

extern "C" void __cdecl free(void*);

int f(S* node)
{
    int result = 0;
    while (node != 0)
    {
        if (node->count != 0)
        {
            InnerNode* inner = node->container->first;
            int cnt = 0;
            InnerNode* p = inner;
            while (p != 0)
            {
                p = p->next;
                cnt++;
            }
            if (cnt > 2)
            {
                node->count = cnt;
                result++;
            }
            else
            {
                p = inner;
                while (p != 0)
                {
                    InnerNode* nxt = p->next;
                    free(p);
                    p = nxt;
                }
                node->count = 0;
            }
        }
        node = node->next;
    }
    return result;
}

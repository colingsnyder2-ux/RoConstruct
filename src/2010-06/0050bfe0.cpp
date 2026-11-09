// from server: 100% by atomic.potato
struct S
{
    int count;
    void* list;
    void f(void* node);
};

void S::f(void* node)
{
    char* p = (char*)node;
    if (p)
        p += 8;
    else
        p = 0;

    char* head = (char*)list;
    char* next = *(char**)(head + 4);

    *(char**)(p + 4) = next;
    *(char**)next = p;
    *(char**)(head + 4) = p;
    *(char**)p = head;
    ++count;
}

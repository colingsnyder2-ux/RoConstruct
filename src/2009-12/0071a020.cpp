// from server: 4% by atomic.potato
struct EventDescNode
{
    int Type();
    EventDescNode* next;
    char data[16];
};

struct EventDesc
{
    EventDescNode* node;
    EventDescNode* Find();
};

int EventDescNode::Type()
{
    return 0;
}

EventDescNode* EventDesc::Find()
{
    EventDescNode* p = node;
    while (p->Type() != 7)
        p = p->next;
    return (EventDescNode*)((char*)p + 0x10);
}

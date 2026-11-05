// from server: 55% by atomic.potato
typedef unsigned int DWORD;

extern "C" void BasicStringCopy(void *destination, void *source);
extern "C" void EventDescFinalize(void *object);

struct EventDesc
{
    char reserved0[0x94];
    void *source;
    char reserved1[0x14];
    void *target;

    void f(void *argument);
};

void EventDesc::f(void *argument)
{
    char buffer[0x1c];
    *(void **)(buffer + 0x20) = buffer;
    BasicStringCopy(buffer, source);
    EventDescFinalize(target);
}

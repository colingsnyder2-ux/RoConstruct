// from server: 100% by tester
struct EventHandler {
    char pad[0x10];
    long counter;
};

long __stdcall EventHandler_increment(EventHandler* handler)
{
    handler->counter += 1;
    return handler->counter;
}

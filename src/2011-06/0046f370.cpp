// from server: 100% by atomic.potato
struct CloseGameVerb
{
    char pad[12];
    void *field_0c;
    void f();
};

extern "C" void __declspec(noreturn) CloseGameVerb_Continue();

void CloseGameVerb::f()
{
    *((unsigned char *)((char *)field_0c + 0xb8)) = 1;
    CloseGameVerb_Continue();
}

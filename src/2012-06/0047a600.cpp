// from server: 100% by tester
struct CloseGameVerb
{
    char pad[12];
    void *field_0c;
    void f();
};

extern "C" void __declspec(noreturn) CloseGameVerb_Continue();

void CloseGameVerb::f()
{
    *((unsigned char *)((char *)field_0c + 0xd4)) = 1;
    CloseGameVerb_Continue();
}

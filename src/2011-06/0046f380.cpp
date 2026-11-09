// from server: 69% by atomic.potato
struct CloseGameAndSaveLocalVerb
{
    void* unused;
    void* field_0c;
    void f();
};

void CloseGameAndSaveLocalVerb::f()
{
    *((unsigned char*)field_0c + 0xB9) = 1;
}

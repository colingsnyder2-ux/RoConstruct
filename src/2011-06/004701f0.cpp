// from server: 36% by atomic.potato
struct RecordPauseVerb
{
    void f();
};

struct RecordPauseVerbData
{
    char pad[0xa0];
};

extern void func_0086b640();

void RecordPauseVerb::f()
{
    RecordPauseVerbData* p = *(RecordPauseVerbData**)((char*)this + 0xc);
    func_0086b640();
}

// from server: 76% by atomic.potato
struct Creator
{
    int value;
};

extern "C" void __cdecl sub_007b4cd0(void*, void*, void*);

Creator* __fastcall func_00402880(Creator* self, void* arg)
{
    void* local1;
    void* local2;
    self->value = 0xa5b6a0;
    local2 = self;
    sub_007b4cd0(&local1, &local2, (void*)0xcb15a0);
    return self;
}

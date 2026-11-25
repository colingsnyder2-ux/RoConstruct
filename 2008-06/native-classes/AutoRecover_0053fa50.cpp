// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: server-verified analog shape from packet_0053fa50.md.
#pragma optimize("", off)
#pragma strict_gs_check(on)

extern "C" int __fastcall fn_00540fb0(void* self, int unusedEdx, void* node);
extern "C" unsigned int __fastcall fn_00540ce0(void* self, int unusedEdx, void* key);
extern "C" void* __fastcall fn_00540b10(void* self, int unusedEdx, void* result, void* key);
extern "C" void __fastcall fn_00541030(void* self);
extern "C" void __fastcall fn_0053f340(void* self, int unusedEdx, void* node);
extern "C" int __fastcall fn_0071f210(void* self, int unusedEdx, void* out);
extern "C" void* __fastcall fn_004e6c00(void* self);
extern "C" bool __fastcall fn_00402410(void* self);
extern "C" void* __fastcall fn_005410d0(void* self, int unusedEdx, void* ptr);
extern "C" void* __fastcall fn_005400f0(void* self, int unusedEdx, void* arg);
extern "C" void __fastcall fn_0053f470(void* self, int unusedEdx, void* node);
extern "C" void __fastcall fn_00502a70(void* self);

struct Local_0053fa50_Key
{
    void* value;
    void* control;
    Local_0053fa50_Key(void* node) { fn_00540fb0(this, 0, node); }
    ~Local_0053fa50_Key() { fn_00541030(this); }
};

struct Local_0053fa50_InsertResult
{
    void* first;
    void* second;
    bool inserted;
};

struct Local_0053fa50_Container
{
    unsigned char storage[32];
};

struct Local_0053fa50_S
{
    unsigned char padding[40];
    Local_0053fa50_Container active;
    Local_0053fa50_Container inactive;
};

extern "C" void __fastcall fn_0053fa50(Local_0053fa50_S* self, int unusedEdx, void* node, unsigned char enabled)
{
    if (enabled)
    {
        bool erased;
        {
            Local_0053fa50_Key key(node);
            erased = fn_00540ce0(&self->inactive, 0, &key) == 1;
        }
        if (erased)
        {
            Local_0053fa50_Key key(node);
            Local_0053fa50_InsertResult result;
            fn_00540b10(&self->active, 0, &result, &key);
        }
        fn_0053f340(self, 0, node);
        return;
    }

    {
        bool erased;
        {
            Local_0053fa50_Key key(node);
            erased = fn_00540ce0(&self->active, 0, &key) == 1;
        }
        if (erased)
        {
            Local_0053fa50_Key key(node);
            Local_0053fa50_InsertResult result;
            fn_00540b10(&self->inactive, 0, &result, &key);
        }
    }

    void* handleSlot = 0;
    int offset = fn_0071f210(node, 0, &handleSlot);
    void* strong = fn_004e6c00((void*)(offset + 0x20));
    (void)strong;
    bool valid = fn_00402410(&handleSlot);
    if (valid)
    {
        void* arg = fn_005410d0(node, 0, &handleSlot);
        fn_005400f0(self, 0, arg);
        (void)arg;
    }
    fn_0053f470(self, 0, node);
    fn_00502a70(&handleSlot);
}
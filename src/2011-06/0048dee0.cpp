// from server: 64% by atomic.potato
struct CScriptDoc
{
    void *get();
};

void *CScriptDoc::get()
{
    struct VTable
    {
        void *entry[41];
    };

    CScriptDoc *object = (CScriptDoc *)this;
    void *base = *(void **)((char *)object + 0x54);
    return ((VTable *)*(void **)base)->entry[40];
}

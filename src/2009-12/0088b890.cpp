// from server: 100% by atomic.potato
struct CXTPCustomizeSheet_CCustomizeEdit
{
    void* vtable;
    int pad0[63];
    void* value;
    int pad1[28];
    void* parent;
    void SetValue(void* value);
};

void CXTPCustomizeSheet_CCustomizeEdit::SetValue(void* value)
{
    this->value = value;
    if (value == 0 && this->parent != 0 &&
        *((int*)((char*)this->parent + 0x20)) != 0)
    {
        void** table = *(void***)this->parent;
        typedef void (__thiscall *Callback)(void*);
        ((Callback)table[0x68 / sizeof(void*)])(this->parent);
    }
}

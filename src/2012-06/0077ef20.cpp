// from server: 79% by atomic.potato
struct EnumDesc
{
    void* GetValue(void*);
    void SetValue(void*);
};

extern "C" void* GetEnumValue(void*);
extern "C" void SetEnumValue(void*, void*);

void EnumDesc::SetValue(void* value)
{
    void* current = *(void**)GetEnumValue((char*)value + 4);
    SetEnumValue(this, &current);
}

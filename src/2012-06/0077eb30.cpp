// from server: 17% by atomic.potato
struct EnumDesc
{
    void* GetValue(void*);
    void SetValue(void*);
    void* field;
};

void* EnumDesc::GetValue(void* p)
{
    return 0;
}

void EnumDesc::SetValue(void* p)
{
    void* value = GetValue((char*)p + 4);
    field = value;
    SetValue(&field);
}

// from server: 73% by atomic.potato
struct S
{
    void Set(void* value);
    void* padding[44];
    void* field_b0;
};

void S::Set(void* value)
{
    if (field_b0 != value)
    {
        field_b0 = value;
        *(void**)0x00b96d8c = value;
        *(void**)0x00b96d8c = value;
    }
}

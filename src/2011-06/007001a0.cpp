// from server: 64% by atomic.potato
struct S
{
    unsigned char pad[8];
    unsigned int* table;
    void __thiscall f(void* out, unsigned int value);
};

void __thiscall S::f(void* out, unsigned int value)
{
    unsigned int offset = value ? value - 0x1c : 0;
    unsigned int* entry = (unsigned int*)((unsigned char*)table + offset);
    unsigned int* result = (unsigned int*)out;
    result[0] = entry[0];
    result[1] = entry[1];
    result[2] = entry[2];
}

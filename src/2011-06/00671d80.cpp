// from server: 71% by atomic.potato
struct S_func_00671d80;

typedef void (S_func_00671d80::*MemberCall)(unsigned char);

struct S_func_00671d80 {
    unsigned char pad_168[0x168];
    void *field_168;
    void f(unsigned char);
};

void S_func_00671d80::f(unsigned char value)
{
    if (value != *((unsigned char *)field_168 + 0x7c)) {
        ((void (__thiscall *)(void *, unsigned char))0x006a3060)(field_168, value);
        ((void (__thiscall *)(void *, const void *))0x00411f60)(this, (const void *)0x00cce280);
    }
}

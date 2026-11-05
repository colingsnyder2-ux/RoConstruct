// from server: 53% by atomic.potato
struct S
{
    void __cdecl f(void* value);
};

extern "C" void* __cdecl sub_534470(void* value);
extern "C" void __cdecl sub_533260(void* value, void* data);

void S::f(void* value)
{
    void* data;
    sub_533260(value, sub_534470(&data));
}

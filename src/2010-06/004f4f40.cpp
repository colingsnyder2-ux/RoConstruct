// from server: 53% by atomic.potato
struct S
{
    int f();
    char data[192];
};

extern "C" int __stdcall sub_004f4f70(char *);
extern "C" void __stdcall sub_00649b60(S *, int *);

int S::f()
{
    int value;
    value = sub_004f4f70(data + 192);
    sub_00649b60(this, &value);
    return 0;
}

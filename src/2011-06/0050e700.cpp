// from server: 54% by atomic.potato
extern "C" int __cdecl sub_0040e040();

struct EventSource
{
    int value;
    int data;
    int f();
};

int EventSource::f()
{
    data = sub_0040e040();
    value = 0x00A7CEB4;
    return (int)this;
}

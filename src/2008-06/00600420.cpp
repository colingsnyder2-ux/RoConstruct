// from server: 100% by king_originala
extern char propertyDescriptor;
extern "C" int __cdecl sub_4898d0(int);
extern "C" int __cdecl sub_495eb0(int, int);

struct S
{
    char storage[0x1c4];
    int value;
    int count;

    void notify(const void *descriptor);
    void setValue(int newValue);
    void f(int newCount);
};

void S::f(int newCount)
{
    int oldCount = count;
    if (newCount > oldCount)
    {
        count = newCount;
        notify(&propertyDescriptor);
        if (sub_4898d0((int)this))
        {
            if ((unsigned char)sub_495eb0((int)this, 1))
            {
                if (value >= 5)
                {
                    if (newCount - 1 > oldCount)
                        setValue(5 + ((newCount - 1) % 2 != 0));
                    setValue(5 + (newCount % 2 != 0));
                }
            }
        }
    }
}

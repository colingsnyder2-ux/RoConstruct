// from server: 100% by sophus
struct PadBase
{
    char pad[0x130];
};

struct SoundChannel
{
    void* vtable;
    int field_04;
    int field_08;
    void* field_0c;
    void method1(SoundChannel* other);
    void method2(SoundChannel* other);
};

struct SoundService : PadBase, SoundChannel
{
    char pad2[0x25];
    unsigned char field_165;
    char pad3[6];
    void* field_16c;

    void f();
};

SoundService* getProvider(SoundService* service);

void SoundService::f()
{
    if (this->field_16c != 0 && (this->field_165 & 1) != 0 && this->field_0c != 0)
    {
        SoundChannel* self = this;
        SoundService* provider = getProvider(this);
        if (provider)
            provider->method1(self);
    }
    else
    {
        SoundChannel* self = this;
        SoundService* provider = getProvider(this);
        if (provider)
            provider->method2(self);
    }
}

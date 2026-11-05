// from server: 100% by colin
struct Base {
    unsigned char storage[0x134];
    Base();
    ~Base();
};

struct Observer {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void connect(void *, bool *) = 0;
};

extern Observer *observer;

struct Sound : Base {
    Sound();
};

Sound::Sound() : Base()
{
    unsigned long *endpoint =
        reinterpret_cast<unsigned long *>(storage + 0x14);

    *reinterpret_cast<unsigned long *>(storage + 0x14) = 0x838248;
    *reinterpret_cast<unsigned long *>(storage) = 0x838204;
    *reinterpret_cast<unsigned long *>(storage + 0x10) = 0x8381f4;
    *reinterpret_cast<unsigned long *>(storage + 0x20) = 0x8381ec;
    *reinterpret_cast<unsigned long *>(storage + 0x24) = 0x8381dc;
    *reinterpret_cast<unsigned long *>(storage + 0x44) = 0x8381cc;
    *reinterpret_cast<unsigned long *>(storage + 0x64) = 0x8381bc;
    *reinterpret_cast<unsigned long *>(storage + 0x84) = 0x8381ac;
    *reinterpret_cast<unsigned long *>(storage + 0xa4) = 0x83819c;
    *reinterpret_cast<unsigned long *>(storage + 0xc4) = 0x83818c;
    *reinterpret_cast<unsigned long *>(storage + 0x130) = 0x838180;

    bool flag = false;
    observer->connect(endpoint, &flag);
}

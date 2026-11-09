// from server: 59% by atomic.potato
extern "C" int __cdecl sub_972290(unsigned char, const char*);
extern "C" int __cdecl sub_5a4300(void*, int*);

extern unsigned char byte_E580B3;
extern void* ptr_E5809C;

struct InstancePacketCache {
    char pad[0x84];
    int field_84;
    void method(int* arg);
};

void InstancePacketCache::method(int* arg) {
    if (byte_E580B3 != 0 && *arg == 0) {
        void* p = ptr_E5809C;
        if (p != 0) {
            int (*fn)(const char*, const char*, int) = (int (*)(const char*, const char*, int))p;
            if (fn((const char*)0xb7b82c, (const char*)0xb7b6c0, 0x40)) {
                goto skip;
            }
        }
        sub_972290(byte_E580B3, (const char*)0xb7b7c0);
    }
skip:
    sub_5a4300(&field_84, arg);
}

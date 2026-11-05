// from server: 100% by Intel
extern "C" int __stdcall sub_982A32(void*);

int __stdcall sub_435540(void* arg) {
    if (!sub_982A32(arg)) {
        return 0;
    }
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(arg) + 0x2C) &= 0xFFFFFDFF;
    return 1;
}

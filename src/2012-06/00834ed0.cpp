// from server: 65% by atomic.potato
extern "C" int __cdecl sub_6c1210();
extern "C" int __cdecl sub_4492f0(int, int);
extern "C" int __cdecl sub_791490(void*, int, int);
extern "C" int __cdecl sub_972290(int, int);

extern unsigned char byte_E580B3;
extern int dword_E5809C;

struct LuaArguments {
    void* field0;
    int field4;
    void* method(int);
};

void* LuaArguments::method(int arg) {
    int local = 0;
    if (byte_E580B3 != 0) {
        int v = sub_6c1210();
        void* p = *(void**)this;
        int r = sub_4492f0(*(int*)((char*)p + 0x20), v);
        if ((unsigned char)r == 0) {
            int fn = dword_E5809C;
            if (fn != 0) {
                int r2 = ((int (__cdecl*)(int, int, int))fn)(0xb753e0, 0xb43f40, 0xff);
                if ((unsigned char)r2 != 0) {
                    goto done;
                }
            }
            unsigned char c = byte_E580B3;
            sub_972290(c, 0xb75368);
        }
    }
done:
    int edx = this->field4;
    void* ecx = this->field0;
    sub_791490(ecx, arg, edx);
    return (void*)arg;
}

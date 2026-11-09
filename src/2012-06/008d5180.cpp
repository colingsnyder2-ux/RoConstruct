// from server: 41% by atomic.potato
// roc 2012-06 008d5180  unit: RBX::Handles  size: 174 bytes

extern "C" void __stdcall sub_524ff0(void*, int);
extern "C" void __stdcall sub_6c2450(void*, void*);
extern "C" void* __stdcall sub_783bb0();
extern "C" void __stdcall sub_982114(void*);

struct Handles {
    void method(int);
};

void Handles::method(int a) {
    void* buf[4];
    sub_524ff0(buf, 1);
    void* p = buf[0];
    *(void**)p = sub_783bb0();
    sub_6c2450((char*)p + 4, (void*)a);
    void* vt = *(void**)this;
    void* fn = *((void**)vt + 1);
    ((void (__thiscall*)(void*, void*))fn)(this, buf);
    void* start = buf[0];
    if (start) {
        void* end = buf[1];
        if (start != end) {
            char* cur = (char*)start + 4;
            do {
                void* obj = *(void**)cur;
                if (obj) {
                    void* f = *((void**)obj + 1);
                    ((void (__thiscall*)(void*, void*))f)(obj, cur + 4);
                }
                cur += 0x44;
            } while ((void*)(cur - 4) != end);
        }
        sub_982114(start);
    }
}

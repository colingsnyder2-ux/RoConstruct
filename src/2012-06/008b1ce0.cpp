// from server: 32% by atomic.potato
extern "C" void __stdcall func_00972290(unsigned char, const char*);
extern "C" void* __cdecl func_0098211a(unsigned int);
extern "C" void* __cdecl func_00730560(void*, int*, int);
extern "C" void* __cdecl func_00715e90(void*, int);
extern "C" void __cdecl func_008b1c50(void*);

extern unsigned char g_e580b3;
extern void* g_e5809c;

struct S {
    void* field0;
    void* field4;
    void* method(int);
};

void* S::method(int arg)
{
    if (g_e580b3 != 0 && this->field0 == 0) {
        if (g_e5809c != 0) {
            unsigned char r = ((unsigned char (__stdcall*)(int, const char*, const char*))g_e5809c)(0x1c, (const char*)0xbe1920, (const char*)0xbe19e0);
            if (r != 0)
                goto done;
        }
        func_00972290(g_e580b3, (const char*)0xbe1a78);
    }
done:
    {
        void* ebx = *(void**)((char*)this->field0 + 4);
        int local;
        void* p = func_00730560(this->field0, &local, arg);
        if (*(void**)p == ebx) {
            void* mem = func_0098211a(0x20);
            void* obj = 0;
            if (mem != 0) {
                func_008b1c50(mem);
                obj = mem;
            }
            void* slot = func_00715e90(this->field0, arg);
            *(void**)slot = obj;
            void* q = func_00730560(this->field0, &local, arg);
            void* result = *(void**)q;
            return *(void**)((char*)result + 0x28);
        } else {
            void* q = func_00730560(this->field0, &local, arg);
            void* result = *(void**)q;
            return *(void**)((char*)result + 0x28);
        }
    }
}

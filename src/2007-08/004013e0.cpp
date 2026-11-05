// from server: 34% by colin
extern "C" {
    void __stdcall SysFreeString(void*);
    const char* __stdcall glGetString(unsigned int);
}

struct String {
    char data[28];
    String();
    ~String();
    const char* c_str() const;
};

struct Dialog {
    int field0;
};

extern "C" void __stdcall sub_00466330(void*);
extern "C" void __stdcall sub_00466350(void*, void*);
extern "C" void __stdcall sub_00466580(void*, void*);
extern "C" void __stdcall sub_004665f0(void*);
extern "C" void* __stdcall sub_0046d3b0();
extern "C" void* __stdcall sub_0046d4d0();
extern "C" void* __stdcall sub_0046d600();
extern "C" void* __stdcall sub_0046dcf0();
extern "C" void __stdcall sub_00501330(void*);
extern "C" void* __stdcall sub_0062ff02();
extern "C" int __stdcall sub_0062ff0e(void*, const char*, void**);
extern "C" void __stdcall sub_0062ff14(void*, const char*, int, void*);
extern "C" void __stdcall sub_0062ff1a(void*, void*, void*);
extern "C" void __stdcall sub_00630a1e();
extern "C" void* __stdcall sub_00401220(const char*);

extern "C" void* __stdcall GetModuleHandleA(const char*);
extern "C" void* __stdcall GetProcAddress(void*, const char*);

void __cdecl sub_004013e0(Dialog* self, int a2)
{
    if (*(int*)a2 != 0)
        return;

    String s1;
    String s2;
    String s3;

    sub_00466330(&s1);
    sub_00466350(&s2, &s1);
    sub_00466580(&s3, &s2);

    sub_0062ff14(self, "glInfo", 0x80010402, &s3);

    void* h = GetModuleHandleA("opengl32.dll");
    sub_00501330(h);
    void* p = GetProcAddress(h, "glGetString");
    const char* ver = glGetString(0x1F00);
    if (ver != 0)
    {
        String t1;
        String t2;
        String t3;
        String t4;
        String t5;
        String t6;
        String t7;
        String t8;

        sub_0046d3b0();
        sub_0046d4d0();
        sub_0046d600();
        sub_0046dcf0();

        sub_0062ff14(self, "Version", 0x80010402, &t1);
        sub_0062ff14(self, "driverVersion", 0x80010402, &t2);
        sub_0062ff14(self, "glInfo", 0x80010402, &t3);
        sub_0062ff14(self, "glInfo", 0x80010402, &t4);
        sub_0062ff14(self, "glInfo", 0x80010402, &t5);
        sub_0062ff14(self, "glInfo", 0x80010402, &t6);
        sub_0062ff14(self, "glInfo", 0x80010402, &t7);
        sub_0062ff14(self, "glInfo", 0x80010402, &t8);
    }
    else
    {
        String t;
        sub_0062ff0e(self, "glInfo", (void**)&t);
        if (t.c_str() != 0)
        {
            void* p2 = sub_00401220("glInfo");
            void* p3 = *(void**)p2;
            void* p4 = *(void**)p3;
            void* p5 = *(void**)((char*)p4 + 0x20c);
            ((void (__stdcall*)(void*, void*))p5)(p3, p2);
            SysFreeString(p2);
        }
    }
}

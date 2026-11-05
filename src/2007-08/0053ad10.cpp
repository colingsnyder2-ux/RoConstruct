// from server: 100% by atomic.potato
extern "C" void __cdecl sub_5BDD80(void* self, int size);
extern "C" void __cdecl sub_5BDB90(void* self, int value);
extern "C" void __cdecl sub_5BDFF0(void* self, int value);
extern "C" void* __cdecl sub_409920();
extern "C" void __cdecl sub_5BDCC0(void* self, void* fn, int arg);
extern "C" void __cdecl sub_5BDBF0(void* self, const char* str);
extern "C" void __cdecl sub_5BE290(void* self, int a, int b);

void __cdecl sub_53AD10(void* self, int a, int b)
{
    sub_5BDD80(self, 0x54);
    sub_5BDB90(self, a);
    sub_5BDFF0(self, 0xffffd8ee);

    void* p = sub_409920();
    if (*(unsigned char*)((char*)p + 0xe9) != 0)
    {
        sub_5BDCC0(self, (void*)0x5c8290, 0);
        sub_5BDBF0(self, (const char*)0x7a5a6c);
        sub_5BE290(self, 1, 0);
    }

    sub_5BDBF0(self, (const char*)0x7a5a60);
    sub_5BDCC0(self, (void*)0x53a760, 0);
    sub_5BDFF0(self, 0xffffd8ee);
}

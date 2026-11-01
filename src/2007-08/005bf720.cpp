// from server: 100% by colin
extern "C" void __cdecl sub_5bdee0(void*, int, int);
extern "C" void __cdecl sub_5bd740(void*, int);
extern "C" void __cdecl sub_5be160(void*, int);
extern "C" void __cdecl sub_5bdbb0(void*, void*, int);
extern "C" void __cdecl sub_5bdbf0(void*, void*);
extern "C" void __cdecl sub_5bdff0(void*, int);

extern void* g_7b91b0;

void __cdecl sub_5bf720(void* self, void* arg)
{
    sub_5bdee0(self, 0, 0);
    sub_5bd740(self, -1);
    sub_5be160(self, -2);
    sub_5bdbb0(self, &g_7b91b0, 6);
    sub_5bdbf0(self, arg);
    sub_5bdff0(self, -3);
}

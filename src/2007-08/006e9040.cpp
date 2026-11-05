// from server: 31% by colin
struct CXTPDockingPaneOffice2007Theme {
    void Init();
};

extern "C" {
    void __stdcall sub_77DDB8(void*);
    void* __cdecl sub_710F20();
    void* __cdecl sub_710820(void*);
    void __cdecl sub_6684F0(void*, unsigned int, unsigned int, float);
    void* __cdecl sub_6E54B0(void*, int);
    void __cdecl sub_6E54D0(void*, int, void*, void*);
}

void CXTPDockingPaneOffice2007Theme::Init()
{
    char* self = (char*)this;

    *(unsigned int*)(self + 0xf4) = 0xffffff;

    sub_77DDB8((void*)0x7da258);
    sub_77DDB8((void*)0x78aca0);
    *(unsigned int*)(self + 0x48) = (unsigned int)sub_710820(sub_710F20());
    *(unsigned int*)(self + 0x3c) = *(unsigned int*)(self + 0x17c);

    sub_77DDB8((void*)0x7d6af0);
    sub_77DDB8((void*)0x7d6678);
    *(unsigned int*)(self + 0x13c) = (unsigned int)sub_710820(sub_710F20());

    sub_77DDB8((void*)0x7d6b00);
    sub_77DDB8((void*)0x7d6678);
    *(unsigned int*)(self + 0x150) = (unsigned int)sub_710820(sub_710F20());
    *(unsigned int*)(self + 0x1dc) = 1;

    sub_77DDB8((void*)0x7da634);
    sub_77DDB8((void*)0x78aca0);
    {
        void* a = sub_710820(sub_710F20());
        sub_77DDB8((void*)0x7da624);
        sub_77DDB8((void*)0x78aca0);
        void* b = sub_710820(sub_710F20());
        sub_6684F0(self + 0x50, (unsigned int)a, (unsigned int)b, *(float*)0x787050);
    }

    sub_77DDB8((void*)0x7da610);
    sub_77DDB8((void*)0x78aca0);
    {
        void* a = sub_710820(sub_710F20());
        sub_77DDB8((void*)0x7da5fc);
        sub_77DDB8((void*)0x78aca0);
        void* b = sub_710820(sub_710F20());
        sub_6684F0(self + 0x1e4, (unsigned int)a, (unsigned int)b, *(float*)0x787050);
    }

    sub_77DDB8((void*)0x7da5e8);
    sub_77DDB8((void*)0x78aca0);
    *(unsigned int*)(self + 0x228) = (unsigned int)sub_710820(sub_710F20());

    sub_77DDB8((void*)0x7da5d4);
    sub_77DDB8((void*)0x78aca0);
    {
        void* a = sub_710820(sub_710F20());
        sub_77DDB8((void*)0x7da5c0);
        sub_77DDB8((void*)0x78aca0);
        void* b = sub_710820(sub_710F20());
        sub_6684F0(self + 0x204, (unsigned int)a, (unsigned int)b, *(float*)0x787050);
    }

    sub_77DDB8((void*)0x7da5ac);
    sub_77DDB8((void*)0x78aca0);
    sub_710820(sub_710F20());

    if (*(unsigned int*)(self + 0x1dc) == 0) {
        *(unsigned int*)(self + 0x17c) = 0xcf9365;
        *(unsigned int*)(self + 0x170) = 0xffdbbf;
        *(unsigned int*)(self + 0xf4) = 0xffffff;
        sub_6684F0(self + 0x1e4, 0xffefe3, 0xffd2af, *(float*)0x787050);
        *(unsigned int*)(self + 0x48) = 0xfce7d8;
        *(unsigned int*)(self + 0x3c) = (unsigned int)sub_6E54B0(self, 0x26);
        sub_6684F0(self + 0x50, 0xfedabe, 0xcb8f64, *(float*)0x797e9c);

        unsigned int arr[13];
        arr[0] = 0x26;
        arr[1] = 0x27;
        arr[2] = 0x28;
        arr[3] = 0x29;
        arr[4] = 0x2b;
        arr[5] = 0x1f;
        arr[6] = 0x20;
        arr[7] = 0x32;
        arr[8] = 0x25;
        arr[9] = 0x21;
        arr[10] = 0x24;
        arr[11] = 0x1e;
        arr[12] = 0x2f;

        unsigned int colors[13];
        colors[0] = 0x764127;
        colors[1] = 0xcb8c6a;
        colors[2] = 0xd0966d;
        colors[3] = 0xf6f6f6;
        colors[4] = 0x962d00;
        colors[5] = 0xc2eeff;
        colors[6] = 0x800000;
        colors[7] = 0x800000;
        colors[8] = 0x800000;
        colors[9] = 0x3e80fe;
        colors[10] = 0x6fc0ff;
        colors[11] = 0xf5be9e;
        colors[12] = 0;

        sub_6E54D0(self, 0xd, arr, colors);

        *(unsigned int*)(self + 0x1dc) = 1;
        sub_6684F0(self + 0x204, 0xa2e7ff, 0x4ca6ff, *(float*)0x797e9c);
        *(unsigned int*)(self + 0x228) = 0x723708;
    }

    *(unsigned int*)(self + 0x234) = 0x723708;
}

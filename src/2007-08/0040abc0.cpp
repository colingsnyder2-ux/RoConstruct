// from server: 75% by colin
extern "C" void* __stdcall GetFocus();

struct Inner {
    int f(int*);
};

struct Outer {
    int g(int*);
    char pad[0xf4];
    Inner* inner;
};

extern "C" void* __stdcall sub_006301C0(void*);
extern "C" void* __stdcall sub_00635A60();
extern "C" int __stdcall sub_006301F0(Inner*, void*);
extern "C" int __stdcall sub_006301EA(Outer*, int*);
extern "C" int __stdcall sub_00633E00(Inner*, int*);

int Outer::g(int* p)
{
    if (p[1] >= 0x100 && p[1] <= 0x109)
    {
        int v = p[2];
        if (v != 0xd && v != 9 && v != 0x1b)
        {
            void* focus = GetFocus();
            Inner* obj = (Inner*)sub_006301C0(focus);
            if (obj != 0)
            {
                void* x = sub_00635A60();
                if (sub_006301F0(obj, x) != 0)
                    return 0;
            }
        }
    }

    if (sub_006301EA(this, p) != 0)
        return 1;

    Inner* inner = this->inner;
    if (inner != 0)
    {
        if (sub_00633E00(inner, p) != 0)
            return 1;
    }

    return 0;
}

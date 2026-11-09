// from server: 75% by colin
// roc 2007-08 006f57a0  unit: CXTPControlCustom  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f57a0

extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void*, void*, int, int, int, int, unsigned int);

struct CXTPControlCustom {
    void Update();
};

void CXTPControlCustom::Update()
{
    if (*(int*)((char*)this + 0x170) != 0)
    {
        unsigned int flags;
        if (*(int*)((char*)this + 0xfc) != 0 &&
            *(int*)((char*)this + 0x184) != 0)
        {
            int (__stdcall *pfn)(void*, int);
            pfn = *(int (__stdcall **)(void*, int))(*(int*)this + 0x80);
            if (pfn(this, 0) != 0)
            {
                int* p = *(int**)((char*)this + 0xfc);
                if (p != 0 && p[8] != 0)
                {
                    int (__stdcall *pfn2)(void*);
                    pfn2 = *(int (__stdcall **)(void*))(*(int*)p + 0x160);
                    if (pfn2(p) != 0)
                        flags = 0x40;
                    else
                        flags = 0x80;
                }
                else
                    flags = 0x80;
            }
            else
                flags = 0x80;
        }
        else
            flags = 0x80;

        flags |= 0x17;
        SetWindowPos(*(void**)((char*)this + 0x170), 0, 0, 0, 0, 0, flags);
    }
}

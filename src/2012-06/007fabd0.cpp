// from server: 100% by Intel
typedef unsigned long DWORD;
typedef unsigned char BYTE;

void* operator new(unsigned int);

void* func_007fabd0()
{
    void* p = operator new(0x78);
    if (p) {
        *(DWORD*)p = 0;
    }
    if ((void*)((char*)p + 4)) {
        *(DWORD*)((char*)p + 4) = 0;
    }
    if ((void*)((char*)p + 8)) {
        *(DWORD*)((char*)p + 8) = 0;
    }
    *(BYTE*)((char*)p + 0x70) = 1;
    *(BYTE*)((char*)p + 0x71) = 0;
    return p;
}

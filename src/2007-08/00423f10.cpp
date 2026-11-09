// from server: 48% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

extern "C" long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct CSelectionTreeCtrl;

struct CRefCounted {
    long ref;
};

struct CSelectionTreeCtrl {
    char pad[0x20];
    void* hwnd;
    char pad2[0x94 - 0x24];
    void* field_94;
    char pad3[0xe4 - 0x98];
    CRefCounted* field_e4;
    CRefCounted* field_e8;

    void Update();
};

struct CTreeItem {
    void* vptr;
    char pad[0x44 - 4];
    long field_44;
};

void __fastcall sub_4201A0(CSelectionTreeCtrl* self);
void __fastcall sub_423B70(void* p);
void __fastcall sub_423E70(void* p, void* a, void* b);
void __fastcall sub_492360(void* p);

void CSelectionTreeCtrl::Update()
{
    sub_4201A0(this);

    if (this->field_e4 == 0)
        return;
    if (this->hwnd == 0)
        return;

    void* mem = malloc(0x50);
    void* result = 0;

    if (mem != 0)
    {
        CRefCounted* a = this->field_e4;
        CRefCounted* b = this->field_e8;
        if (b != 0)
        {
            _InterlockedExchangeAdd(&b->ref, 1);
        }
        sub_423E70(mem, &a, this);
        result = mem;
    }

    this->field_94 = result;

    if (result != 0)
    {
        void** vt = *(void***)result;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[3];
        fn(result);

        sub_423B70(this->field_94);

        CTreeItem* item = (CTreeItem*)this->field_94;
        SendMessageA(this->hwnd, 0x1102, 2, item->field_44);
    }
}

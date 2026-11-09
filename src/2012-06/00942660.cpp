// from server: 53% by Intel
struct ChatMessage;

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);
void __stdcall sub_697560(void* thisptr, void* arg);
void* __stdcall sub_4287B0(void* thisptr, void* arg1, void* arg2, void* arg3, void* arg4);

struct SignalSlotCallable {
    void* vftable;
    void* field_4;
    void* field_8;
    void* field_C;
    void* field_10;
    void* field_14;
    void* field_18;
    void* field_1C;
    void* field_20;
    void* field_24;
};

void* __stdcall SignalSlotCallable_ctor(SignalSlotCallable* thisptr, void* a2, ChatMessage* a3, void* a4) {
    void* edi = thisptr;
    void* esi = 0;

    void* eax = operator_new(0x28);
    if (eax) {
        *(int*)((char*)eax + 8) = 0xB92A20;
        *(int*)((char*)eax + 0xC) = 0;
        *(int*)eax = 0xBFFE98;
        *(int*)((char*)eax + 8) = 0xBFFE90;
        *(int*)((char*)eax + 0x10) = (int)edi;
        *(int*)((char*)eax + 0x18) = *(int*)a3;
        *(int*)((char*)eax + 0x1C) = *(int*)((char*)a3 + 4);
        *(int*)((char*)eax + 0x20) = *(int*)((char*)a3 + 8);
        *(int*)((char*)eax + 0x24) = *(int*)((char*)a3 + 0xC);
        *(int*)eax = 0xBFFEE0;
        *(int*)((char*)eax + 8) = 0xBFFED8;
        esi = eax;
    }

    sub_697560(edi, esi);
    *(int*)a4 = (int)esi;
    if (esi) {
        operator_delete((char*)esi + 5);
    }
    return a4;
}

// from server: 60% by Intel
struct SlotData {
    char type;
    float x;
    float y;
    float z;
    int id;
};

extern "C" SlotData* __cdecl GetSlotData(void* global, int index, void* edi);
extern "C" void __cdecl Notify(void* edi, int result);

int __cdecl VWaitScriptSlot_CompareAndNotify(void* edi) {
    void* global = *(void**)0xDE13E8;
    SlotData* slot2 = GetSlotData(global, 2, edi);
    SlotData* slot1 = GetSlotData(global, 1, edi);

    bool equal = (slot1->type != slot2->type) &&
                 (slot1->x == slot2->x) &&
                 (slot1->y == slot2->y) &&
                 (slot1->z == slot2->z) &&
                 (slot1->id == slot2->id);

    Notify(edi, equal);
    return 1;
}

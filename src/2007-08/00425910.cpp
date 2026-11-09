// from server: 53% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CSelectionTreeCtrl {
    char pad[0xbc];
    void* field_bc;
    bool IsSelected(void* item);
    void SelectItem(void* item);
    void SetItemState(void* item, unsigned int state, unsigned int mask);
};

void* __cdecl GetItemFromIndex(int index);

struct ItemHolder {
    void* item;
    ItemHolder();
    ~ItemHolder();
};

void CSelectionTreeCtrl::SelectItem(void* item) {
    void* current = this->field_bc;
    if (current == item) {
        if (item != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)item + 4), -1) == 1) {
                void** vtbl = *(void***)item;
                ((void (__thiscall*)(void*))vtbl[1])(item);
                if (_InterlockedExchangeAdd((volatile long*)((char*)item + 8), -1) == 1) {
                    void** vtbl2 = *(void***)item;
                    ((void (__thiscall*)(void*))vtbl2[2])(item);
                }
            }
        }
        return;
    }

    void* found = GetItemFromIndex((int)item);
    if (found != 0) {
        if (!this->IsSelected(found)) {
            ItemHolder holder;
            holder.item = 0;
            this->SetItemState(found, 1, 1);
        }
    }

    this->SelectItem(item);

    if (item != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)item + 4), -1) == 1) {
            void** vtbl = *(void***)item;
            ((void (__thiscall*)(void*))vtbl[1])(item);
            if (_InterlockedExchangeAdd((volatile long*)((char*)item + 8), -1) == 1) {
                void** vtbl2 = *(void***)item;
                ((void (__thiscall*)(void*))vtbl2[2])(item);
            }
        }
    }
}

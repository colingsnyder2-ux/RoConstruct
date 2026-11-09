// from server: 49% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct QTreeWidgetItem {
    char pad[0x98];
    int value;
};

struct QTreeWidgetItemList {
    void* vptr;
    QTreeWidgetItem* at(int index);
    int count();
    void removeAt(int index);
};

struct QTreeWidget {
    char pad[0x2e8];
    void* getModel();
};

struct RobloxReportView {
    void removeCategoryItem(int value);
};

void RobloxReportView::removeCategoryItem(int value)
{
    QTreeWidget* tree = (QTreeWidget*)((char*)this - 0x2e8);
    void* model = tree->getModel();
    QTreeWidgetItemList* list = *(QTreeWidgetItemList**)((char*)model + 0xa8);
    int n = list->count();
    int i = n - 1;
    if (i >= 0) {
        do {
            QTreeWidgetItem* item = list->at(i);
            if (item->value == value) {
                list->removeAt(i);
                break;
            }
            i--;
        } while (i >= 0);
    }
    if (value) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)value + 4), -1) == 1) {
            void** vt = *(void***)value;
            ((void (__thiscall*)(void*))vt[1])((void*)value);
            if (_InterlockedExchangeAdd((volatile long*)((char*)value + 8), -1) == 1) {
                void** vt2 = *(void***)value;
                ((void (__thiscall*)(void*))vt2[2])((void*)value);
            }
        }
    }
}

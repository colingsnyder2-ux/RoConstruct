// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct QTreeWidgetItem {
    void* vptr;
    int field4;
    int field8;
};

struct QModelIndex {
    int r;
    int c;
    void* p;
    void* m;
};

struct QTreeWidget {
    void* vptr;
    char pad[0x38];
    void* field3c;
    void* field40;
};

struct RobloxCategoryItem {
    void* vptr;
    char pad[0x40];
    int field44;
};

struct RobloxReportView {
    void* vptr;
    char pad[0x2c8];
    QTreeWidget base;
    void* field3c;
    void* field40;
};

extern "C" void* __cdecl sub_00654D90(unsigned int size);
extern "C" void __cdecl sub_00492940(void* a, void* b);
extern "C" void __cdecl sub_00454B50(void* p);

struct RobloxReportView_impl {
    void addCategoryItem(RobloxCategoryItem* pItem);
};

void RobloxReportView_impl::addCategoryItem(RobloxCategoryItem* pItem)
{
    RobloxReportView* self = (RobloxReportView*)((char*)this - 0x2cc);
    void* view = (void*)((char*)this - 0x2cc);
    void* (*getModel)(void*) = *(void*(**)(void*))(*(char**)view + 0x18c);
    void* model = getModel(view);

    void* b = 0;

    RobloxCategoryItem* item = (RobloxCategoryItem*)sub_00654D90(0xa0);
    if (item != 0) {
        void* a = self->field3c;
        b = self->field40;
        if (b != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
        }
        sub_00492940(&a, &b);
        sub_00454B50(item);
    } else {
        item = 0;
    }

    item->field44 = 1;

    void** vt = *(void***)model;
    void (*fn)(void*, RobloxCategoryItem*) = (void(*)(void*, RobloxCategoryItem*))vt[0x144/4];
    fn(model, item);

    if (b != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
            void** vt2 = *(void***)b;
            void (*d1)(void*) = (void(*)(void*))vt2[1];
            d1(b);
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 8), -1) == 1) {
                void** vt3 = *(void***)b;
                void (*d2)(void*) = (void(*)(void*))vt3[2];
                d2(b);
            }
        }
    }
}

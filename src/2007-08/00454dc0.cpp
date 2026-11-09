// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct QTreeWidgetItem {
    char pad[0x98];
    int field98;
};

struct QList {
    void* find(int);
};

struct QTreeWidget {
    void* getItem(int);
    void* getItem2(int);
    void removeItem(int);
};

struct Inner {
    char pad[0x70];
    QTreeWidget* tree;
};

struct S {
    char pad[0x70];
    QTreeWidget* tree;
    void func(int, void*);
};

void S::func(int a, void* b) {
    QTreeWidget* t = this->tree;
    int n = (int)t->getItem(0);
    n = (int)t->getItem2(n);
    n = n - 1;
    if (n >= 0) {
        int* pb = (int*)b;
        int val = *pb;
        do {
            QTreeWidgetItem* item = (QTreeWidgetItem*)t->getItem(n);
            if (item->field98 == val) {
                t->removeItem(n);
                break;
            }
            n = n - 1;
        } while (n >= 0);
    }
    if (b) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
            void** vt = *(void***)b;
            ((void (__thiscall*)(void*))vt[1])(b);
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 8), -1) == 1) {
                void** vt2 = *(void***)b;
                ((void (__thiscall*)(void*))vt2[2])(b);
            }
        }
    }
}

// from server: 100% by king_originala
struct S;

struct VTable {
    void* slots0[6];
    void* (__thiscall *firstOuter)(S*);
    S* (__thiscall *nextOuter)(S*, void**);
    void* slots8[15];
    void* (__thiscall *firstMiddle)(S*);
    S* (__thiscall *nextMiddle)(S*, void**);
    void* slot25;
    void* (__thiscall *firstInner)(S*);
    S* (__thiscall *nextInner)(S*, void**);
};

struct S {
    VTable* table;
    char pad04[0x1c];
    void* handle;

    int sub_6a0bf0(const void*);
    void sub_6a13d6();
    void f();
};

struct Application {
    char pad00[0x58];
    S* list;
};

struct State {
    void* field00;
    Application* application;
};

extern S* globalDialog;
extern "C" State* __cdecl sub_6a0926();
extern "C" int (__stdcall *IsWindow)(void*);
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

void S::f()
{
    if (globalDialog != 0) {
        Application* application = sub_6a0926()->application;
        int found = 0;

        if (application->list != 0) {
            void* outer = application->list->table->firstOuter(application->list);
            while (outer != 0) {
                if (found)
                    break;

                S* middleList =
                    application->list->table->nextOuter(application->list, &outer);
                void* middle = middleList->table->firstMiddle(middleList);

                while (middle != 0) {
                    if (found)
                        break;

                    S* innerList = middleList->table->nextMiddle(middleList, &middle);
                    void* inner = innerList->table->firstInner(innerList);

                    while (inner != 0) {
                        if (found)
                            break;

                        S* candidate = innerList->table->nextInner(innerList, &inner);
                        if (candidate->sub_6a0bf0((const void*)0x81a8c8) &&
                            candidate != this) {
                            void* handle = candidate;
                            if (candidate)
                                handle = candidate->handle;
                            if (IsWindow(handle))
                                found = 1;
                        }
                    }
                }
            }
        }

        if (!found) {
            if (IsWindow(globalDialog->handle))
                SendMessageA(globalDialog->handle, 0x10, 0, 0);
            globalDialog = 0;
        }
    }

    sub_6a13d6();
}

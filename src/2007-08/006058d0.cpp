// from server: 60% by colin
struct Assembly;
struct Joint;
struct Contact;

struct SleepStage {
    char pad[0x1c];
    void* set_1c;
    void* set_20;
    char pad2[0x4];
    void* set_28;
    unsigned int count_2c;
    char pad3[0x78];
    void* list_a8;
    void* list_ac;
    void stepAssembliesRecursiveWakePending();
    void stepAssembliesWakePending();
    void stepJoints();
    void stepAssembliesAwake();
    void stepAssembliesSleepingChecking();
    void doContacts(void* contactLists);
    void stepContacts(void* contactList);
    void stepSleepStage(void* arg);
};

struct Node {
    Node* next;
    Node* prev;
    void* data;
};

struct List {
    Node* head;
    int size;
};

extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __stdcall sub_5b4830(void* a, void* b);
extern "C" void __stdcall sub_5b3e10(void* a);
extern "C" void __stdcall sub_5e29b0(void* a, void* b, void* c);

void SleepStage::stepSleepStage(void* arg) {
    void* p = arg;
    while (*(int*)((char*)p + 0x2c) != 0) {
        List* lst = *(List**)((char*)p + 0x28);
        Node* n = lst->head;
        if (n == (Node*)lst) {
            _invalid_parameter_noinfo();
        }
        void* item = *(void**)((char*)n + 0xc);
        stepContacts(item);
        if (*(int*)((char*)p + 0x2c) == 0) break;
    }
    if (*(int*)((char*)p + 0x20) != 0) {
        char* base = (char*)this + 0xa8;
        do {
            List* lst = *(List**)((char*)p + 0x1c);
            Node* n = lst->head;
            if (n == (Node*)lst) {
                _invalid_parameter_noinfo();
            }
            void* item = *(void**)((char*)n + 0xc);
            void* v = *(void**)((char*)item + 8);
            void* r = sub_5b4830(v, item);
            sub_5b3e10(r);
            void* tmp = item;
            sub_5e29b0(base, &tmp, &tmp);
        } while (*(int*)((char*)p + 0x20) != 0);
    }
}

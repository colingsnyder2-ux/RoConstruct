// from server: 33% by atomic.potato
extern "C" {
    void __stdcall InitializeCriticalSection(void*);
    void __stdcall EnterCriticalSection(void*);
    void __stdcall LeaveCriticalSection(void*);
}

struct Node {
    Node* next;
    char pad[4];
    void* cs;
};

struct List {
    char pad0[4];
    Node* head;
    char pad1[8];
    Node* tail;
    char pad2[8];
    void* cs2;
};

struct S {
    char pad0[4];
    Node* field4;
    char pad1[8];
    Node* field10;
    char pad2[8];
    Node* field20;
    void destroy();
};

void sub_5dfd30(void*);
void sub_7a8a63(void*);
void sub_415200(Node*, int);

void S::destroy()
{
    Node* esi = field20;
    int ebx = 0;
    if (esi != 0) {
        void (__stdcall *ebp)(void*) = *(void (__stdcall**)(void*))0x9ea3c0;
        Node* edi = esi;
        esi = esi->next;
        sub_5dfd30((char*)edi + 8);
        if ((*(unsigned char*)0xbffa04 & 1) == 0) {
            *(unsigned int*)0xbffa04 |= 1;
            ebp((void*)0xbff9d4);
            *(unsigned int*)0xbff9ec = ebx;
            *(unsigned int*)0xbff9f0 = ebx;
            *(unsigned int*)0xbff9f4 = ebx;
            *(unsigned int*)0xbff9f8 = 0x18;
            *(unsigned int*)0xbff9fc = 0x20;
            *(unsigned int*)0xbffa00 = 0x20;
            sub_7a8a63((void*)0x9da820);
        }
        EnterCriticalSection((void*)0xbff9d4);
        *(Node**)edi = *(Node**)0xbff9ec;
        *(Node**)0xbff9ec = edi;
        LeaveCriticalSection((void*)0xbff9d4);
        while (esi != 0) {
            edi = esi;
            esi = esi->next;
            sub_5dfd30((char*)edi + 8);
            if ((*(unsigned char*)0xbffa04 & 1) == 0) {
                *(unsigned int*)0xbffa04 |= 1;
                ebp((void*)0xbff9d4);
                *(unsigned int*)0xbff9ec = ebx;
                *(unsigned int*)0xbff9f0 = ebx;
                *(unsigned int*)0xbff9f4 = ebx;
                *(unsigned int*)0xbff9f8 = 0x18;
                *(unsigned int*)0xbff9fc = 0x20;
                *(unsigned int*)0xbffa00 = 0x20;
                sub_7a8a63((void*)0x9da820);
            }
            EnterCriticalSection((void*)0xbff9d4);
            *(Node**)edi = *(Node**)0xbff9ec;
            *(Node**)0xbff9ec = edi;
            LeaveCriticalSection((void*)0xbff9d4);
        }
    }
    esi = field4;
    while (esi != 0) {
        Node* tmp = esi;
        esi = esi->next;
        sub_415200(tmp, 1);
    }
    sub_5dfd30((char*)this + 0x10);
}

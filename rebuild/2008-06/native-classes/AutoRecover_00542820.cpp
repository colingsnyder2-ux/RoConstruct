// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_00540f70(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_005407e0(void* self, int unusedEdx);
// ReferenceCountedPointer<...>::zeroPointer
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);

// INFERRED: layout of the owner object and its singly linked list of back-pointers
struct ListObj;
struct ListNode {
    ListObj* value;
    ListNode* next;
};
struct ListParent {
    int pad0;
    int pad1;
    ListNode* head; // at +8
};
struct ListObj {
    int pad0;
    ListParent* parent; // at +4
};

// INFERRED: 4-byte smart pointer temporary whose destructor calls zeroPointer
struct TempPtr {
    void* p;
    ~TempPtr() { fn_00502a70(this, 0); }
};

extern "C" void __fastcall fn_00542820(ListObj* self, int unusedEdx)
{
    TempPtr tmp;
    fn_00540f70(self, 0, (int)&tmp);
    if ((unsigned char)fn_005407e0(&tmp, 0)) {
        ListNode** pp = &self->parent->head;
        while ((*pp)->value != self) {
            pp = &(*pp)->next;
        }
        ListNode* node = *pp;
        *pp = node->next;
        operator delete(node);
    }
    self->parent = 0;
}

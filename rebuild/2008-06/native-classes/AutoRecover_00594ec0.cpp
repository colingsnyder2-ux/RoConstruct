// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: MSVCR90 import (call via [0x802890]); not declared by stdlib.h in this config.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: std::list<boost::signals::connection>::_Insert(iterator, const value&), checked iterator.
struct ConnNode {
    ConnNode* next;
    ConnNode* prev;
};
struct ConnIterBase {
    void* container;
    ConnNode* ptr;
};
struct ConnList {
    void* proxy;
    ConnNode* head;
    unsigned size;
};
// INFERRED: iterator proxy owner; field at +0x14 holds the node compared against.
struct ConnIterOwner {
    int pad[5];
    ConnNode* cmp;
};
struct ConnIterHolder {
    ConnIterOwner* owner;
};

extern "C" ConnNode* __fastcall fn_00594e20(ConnList* self, int unusedEdx, ConnNode* next, ConnNode* prev, const void* val);
extern "C" void __fastcall fn_00682cc0(ConnList* self, int unusedEdx, int count);

extern "C" ConnIterBase* __fastcall fn_00594ec0(ConnList* self, int unusedEdx, ConnIterBase* result, ConnIterHolder* whereProxy, ConnNode* wherePtr, const void* val)
{
    ConnNode* newNode = fn_00594e20(self, 0, wherePtr, wherePtr->prev, val);
    fn_00682cc0(self, 0, 1);
    wherePtr->prev = newNode;
    newNode->prev->next = newNode;

    if (!whereProxy)
        _invalid_parameter_noinfo();
    ConnNode* prev = wherePtr->prev;
    ConnIterOwner* owner = whereProxy ? whereProxy->owner : 0;
    if (prev == owner->cmp)
        _invalid_parameter_noinfo();

    result->container = 0;
    result->ptr = prev;
    if (!self)
        _invalid_parameter_noinfo();
    result->container = self->proxy;
    return result;
}

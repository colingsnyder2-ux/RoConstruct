// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "G3D/System.h"

extern "C" char g_00826c04[];   // INFERRED: unnamed global at 0x00826c04 in the original

// INFERRED: the original sets only ecx (edx untouched, no stack args), so a one-parameter fastcall
// declaration matches the call site without an "xor edx, edx".
extern "C" void __fastcall fn_004d7e30(void* self);

struct Local_004d8ea0Payload {
    void* vtable;
    unsigned char data[12];
};

struct Local_004d8ea0Node {
    unsigned char data[8];
    Local_004d8ea0Payload value;
    Local_004d8ea0Node* next;
};

struct Local_004d8ea0Table {
    unsigned int field0;
    int size;
    Local_004d8ea0Node** buckets;
    int bucketCount;
};

extern "C" void __fastcall fn_004d8ea0(Local_004d8ea0Table* self, int unusedEdx)
{
    for (int i = 0; i < self->bucketCount; ++i) {
        Local_004d8ea0Node* node = self->buckets[i];
        while (node) {
            Local_004d8ea0Node* next = node->next;
            node->value.vtable = (void*)((int)&g_00826c04);
            fn_004d7e30(&node->value);
            G3D::System::free(node);
            node = next;
        }
    }
    G3D::System::alignedFree(self->buckets);
    self->buckets = 0;
    self->bucketCount = 0;
    self->size = 0;
}

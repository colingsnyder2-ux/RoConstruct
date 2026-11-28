// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826c1c[];   // INFERRED: unnamed global at 0x00826c1c in the original
#include "G3D/System.h"

// INFERRED: callee only receives ecx; the original never sets edx before this call
extern "C" int __fastcall fn_004d7e30(void* self);

// INFERRED: layout from the disassembly; the node/table types are local helpers
struct Local_004d8ff0Node {
    unsigned char pad[8];
    void* vtable;            // +8, payload start
    unsigned char data[12];
    Local_004d8ff0Node* next; // +0x18
};

struct Local_004d8ff0Table {
    unsigned int field0;
    int size;
    Local_004d8ff0Node** buckets;
    int bucketCount;
};

extern "C" void __fastcall fn_004d8ff0(Local_004d8ff0Table* self, int unusedEdx)
{
    for (int i = 0; i < self->bucketCount; ++i) {
        Local_004d8ff0Node* node = self->buckets[i];
        while (node) {
            Local_004d8ff0Node* next = node->next;
            node->vtable = (void*)((int)&g_00826c1c);
            fn_004d7e30(&node->vtable);
            G3D::System::free(node);
            node = next;
        }
    }
    G3D::System::alignedFree(self->buckets);
    self->buckets = 0;
    self->bucketCount = 0;
    self->size = 0;
}

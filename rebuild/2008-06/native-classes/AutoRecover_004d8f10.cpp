// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826c0c[];   // INFERRED: unnamed global at 0x00826c0c in the original
#include "G3D/System.h"

// INFERRED: the original sets ecx only and pushes nothing, so the callee is declared
// with the object pointer alone. A dummy edx argument would add an extra "xor edx, edx".
extern "C" int __fastcall fn_004d7e30(void* self);

// INFERRED: file-local types; layout from disassembly offsets
struct Local_004d8f10Payload {
    void* vtable;
    unsigned char data[12];
};

struct Local_004d8f10Node {
    unsigned char data[8];
    Local_004d8f10Payload value;
    Local_004d8f10Node* next;
};

struct Local_004d8f10Table {
    unsigned int field0;
    int size;
    Local_004d8f10Node** buckets;
    int bucketCount;
};

extern "C" void __fastcall fn_004d8f10(Local_004d8f10Table* self, int unusedEdx)
{
    for (int i = 0; i < self->bucketCount; ++i) {
        Local_004d8f10Node* node = self->buckets[i];
        while (node) {
            Local_004d8f10Node* next = node->next;
            // INFERRED: vtable pointer constant ((int)&g_00826c0c) from the original
            node->value.vtable = (void*)((int)&g_00826c0c);
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

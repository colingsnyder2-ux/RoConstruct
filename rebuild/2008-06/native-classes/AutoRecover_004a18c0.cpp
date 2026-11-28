// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_008233c4[];   // INFERRED: unnamed global at 0x008233c4 in the original
extern "C" char g_008233f4[];   // INFERRED: unnamed global at 0x008233f4 in the original
extern "C" char g_00823404[];   // INFERRED: unnamed global at 0x00823404 in the original
extern "C" char g_00823414[];   // INFERRED: unnamed global at 0x00823414 in the original
extern "C" char g_00823424[];   // INFERRED: unnamed global at 0x00823424 in the original
extern "C" char g_00823434[];   // INFERRED: unnamed global at 0x00823434 in the original
extern "C" char g_00823444[];   // INFERRED: unnamed global at 0x00823444 in the original
extern "C" char g_00823454[];   // INFERRED: unnamed global at 0x00823454 in the original
extern "C" char g_0082345c[];   // INFERRED: unnamed global at 0x0082345c in the original
extern "C" char g_00823464[];   // INFERRED: unnamed global at 0x00823464 in the original
extern "C" char g_00823474[];   // INFERRED: unnamed global at 0x00823474 in the original
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

// INFERRED: Replicator base destructor (RBX::Network::Replicator::~Replicator at 0x4b96b0)
extern "C" void __fastcall fn_004b96b0(void* self, int unusedEdx);

struct Local_004a18c0_Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

// INFERRED: layout of the derived replicator-like object; only the touched offsets matter
struct Local_004a18c0 {
    volatile unsigned long words[0x2d68 / 4];
    void* object;
    Local_004a18c0_Control* volatile control;
};

extern "C" void __fastcall fn_004a18c0(Local_004a18c0* self, int unusedEdx)
{
    self->words[0x0000 / 4] = ((int)&g_00823474);
    self->words[0x0010 / 4] = ((int)&g_00823464);
    self->words[0x0014 / 4] = ((int)&g_0082345c);
    self->words[0x0020 / 4] = ((int)&g_00823454);
    self->words[0x0024 / 4] = ((int)&g_00823444);
    self->words[0x0044 / 4] = ((int)&g_00823434);
    self->words[0x0064 / 4] = ((int)&g_00823424);
    self->words[0x0084 / 4] = ((int)&g_00823414);
    self->words[0x00a4 / 4] = ((int)&g_00823404);
    self->words[0x00c4 / 4] = ((int)&g_008233f4);
    self->words[0x2b74 / 4] = ((int)&g_008233c4);

    Local_004a18c0_Control* p = self->control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
    fn_004b96b0(self, 0);
}

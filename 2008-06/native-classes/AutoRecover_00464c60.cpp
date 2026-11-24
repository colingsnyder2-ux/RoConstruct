// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: field layout comes from the disassembly offsets; the types are guesses.
// INFERRED: the by-value 8-byte argument has a user-defined copy constructor
// (this forces the sub esp,8 / saved-esp pattern seen in the original).
// INFERRED: the code after the virtual call is a catch(...) funclet, and the listener
// pointer at +0xc is cleared after the try/catch.

struct EightBytes {
    unsigned int a;
    unsigned int b;
    EightBytes() : a(0), b(0) {}
    EightBytes(const EightBytes& o) : a(o.a), b(o.b) {}
};

struct EventDataLike;

struct ListenerTarget {
    // INFERRED: virtual slot 2 (vtable + 8) is thiscall, takes (int, EightBytes by value).
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int arg, EightBytes pair);
};

struct EventDataLike {
    int             field0;
    int             field4;
    int             field8;
    ListenerTarget* listener;   // +0x0c
    EightBytes      pair;       // +0x10, +0x14
};

// MarshaledListener<Instance, DescendantAdded, ...>::remove(EventData*)
extern "C" void __fastcall fn_004574b0(ListenerTarget* self, int unusedEdx, EventDataLike* arg);

extern "C" void __fastcall fn_00464c60(EventDataLike* self, int unusedEdx)
{
    if (self->listener) {
        try {
            fn_004574b0(self->listener, 0, self);
            self->listener->slot2(self->field4, self->pair);
        } catch (...) {
        }
        self->listener = 0;
    }
}

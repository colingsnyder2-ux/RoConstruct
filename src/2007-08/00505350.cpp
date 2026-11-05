// from server: 100% by colin
// roc 2007-08 00505350  unit: G3D::Log  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00505350

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int size);

struct Log {
    void* field0;
    void* field4;
    int field8;
    int fieldC;
    int field10;
    void reset();
    void assign(const Log& other);
};

void Log::assign(const Log& other)
{
    reset();
    field8 = other.field8;
    fieldC = other.fieldC;
    field10 = other.field10;
    int total = fieldC * field8 * field10;
    field4 = operator_new(total);
    memcpy(field4, other.field4, total);
}

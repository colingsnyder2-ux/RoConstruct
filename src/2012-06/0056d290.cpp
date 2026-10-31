// from server: 100% by Intel
// Forward declaration of the called function
extern "C" void __cdecl writeFunction(void* serializer, const void* data);

struct IdSerializer {
    // This might be a static member function or free function
    // But based on RTTI hint, let's make it a member function
    // However, the assembly doesn't use 'this' (ecx)
    // So maybe it's static?
    static void* serialize(void* serializer, const void* data);
};

void* IdSerializer::serialize(void* serializer, const void* data) {
    writeFunction(serializer, data);
    writeFunction(serializer, static_cast<const char*>(data) + 4);
    writeFunction(serializer, static_cast<const char*>(data) + 8);
    return serializer;
}

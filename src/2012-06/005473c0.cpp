// from server: 32% by Intel
struct TypeDescriptor {
    void* pVFTable;
    void* spare;
    const char* name;
};

extern "C" int __stdcall CompareTypeDescriptors(TypeDescriptor* a, TypeDescriptor* b);
extern "C" void* __stdcall CreateExceptionObject(void* typeDesc, const char* name, int a3);
extern "C" void __stdcall ThrowException(void* exception);

struct W4ChatOption {
    TypeDescriptor* typeInfo;

    int EnumDesc(W4ChatOption* esi);
};

int W4ChatOption::EnumDesc(W4ChatOption* esi) {
    TypeDescriptor* eax = esi->typeInfo;
    TypeDescriptor* ecx;

    if (eax)
        ecx = *reinterpret_cast<TypeDescriptor**>(eax);
    else
        ecx = reinterpret_cast<TypeDescriptor*>(0xD60AC8);

    if (ecx != reinterpret_cast<TypeDescriptor*>(0xD824AC)) {
        TypeDescriptor* eax2;
        if (eax)
            eax2 = *reinterpret_cast<TypeDescriptor**>(eax);
        else
            eax2 = reinterpret_cast<TypeDescriptor*>(0xD60AC8);

        if (CompareTypeDescriptors(eax2, reinterpret_cast<TypeDescriptor*>(0xD824AC))) {
            void* exception = CreateExceptionObject(
                reinterpret_cast<void*>(0xB44128),
                ".?AV?$TypedPropertyDescriptor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Reflection@",
                0
            );
            ThrowException(exception);
        }
    }

    return reinterpret_cast<int>(esi + 1);
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: RegisteredCommand is a global-namespace struct; its layout is irrelevant here.
struct RegisteredCommand;

namespace DataStructures
{
    // INFERRED: RakNet-style List layout: array pointer, size, allocation size.
    template <class list_type>
    class List
    {
    public:
        unsigned int Size(void) const;

    private:
        list_type *listArray;
        unsigned int list_size;
        unsigned int allocation_size;
    };

    template <class list_type>
    unsigned int List<list_type>::Size(void) const
    {
        return list_size;
    }
}

template unsigned int DataStructures::List<RegisteredCommand>::Size(void) const;

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: RakNet-style DataStructures::List layout (array pointer first, then sizes);
// INFERRED: RegisteredCommand is 12 bytes (three dwords) from the *12 index scaling.
struct RegisteredCommand
{
    void*        parser;
    const char*  command;
    unsigned int extra;
};

namespace DataStructures
{
    template <class list_type>
    class List
    {
    public:
        list_type& operator[](unsigned int position) const;

    private:
        list_type*   listArray;
        unsigned int list_size;
        unsigned int allocation_size;
    };

    template <class list_type>
    list_type& List<list_type>::operator[](unsigned int position) const
    {
        return listArray[position];
    }

    template RegisteredCommand& List<RegisteredCommand>::operator[](unsigned int position) const;
}

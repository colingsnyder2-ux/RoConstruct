// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no native header for RakNet's DataStructures::List was provided,
// so a minimal layout-compatible definition is declared here.
class CommandParserInterface;

namespace DataStructures
{
    template <class list_type>
    class List
    {
    public:
        list_type& operator[](unsigned int position) const;

    private:
        list_type* listArray;
        unsigned int list_size;
        unsigned int allocation_size;
    };

    template <class list_type>
    list_type& List<list_type>::operator[](unsigned int position) const
    {
        return listArray[position];
    }
}

// Explicit instantiation of just this member to emit the symbol.
template CommandParserInterface*& DataStructures::List<CommandParserInterface*>::operator[](unsigned int) const;

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RakNet {
template <class Type>
inline Type* OP_NEW_ARRAY(const int count)
{
    return new Type[count];
}
template <class Type>
inline void OP_DELETE_ARRAY(Type* buff)
{
    delete [] buff;
}
}

namespace DataStructures {
template <class queue_type>
class Queue {
public:
    void Push(const queue_type& input);
    queue_type* array;
    unsigned int head;
    unsigned int tail;
    unsigned int allocation_size;
};

template <class queue_type>
void Queue<queue_type>::Push(const queue_type& input)
{
    if ( allocation_size == 0 )
    {
        array = RakNet::OP_NEW_ARRAY<queue_type>(16);
        head = 0;
        tail = 1;
        array[ 0 ] = input;
        allocation_size = 16;
        return ;
    }

    array[ tail++ ] = input;

    if ( tail == allocation_size )
        tail = 0;

    if ( tail == head )
    {
        queue_type * new_array;
        new_array = RakNet::OP_NEW_ARRAY<queue_type>(allocation_size * 2);
        if (new_array==0)
            return;

        for ( unsigned int counter = 0; counter < allocation_size; ++counter )
            new_array[ counter ] = array[ ( head + counter ) % ( allocation_size ) ];

        head = 0;
        tail = allocation_size;
        allocation_size *= 2;

        RakNet::OP_DELETE_ARRAY(array);
        array = new_array;
    }
}
}

struct HuffmanEncodingTreeNode;
template class DataStructures::Queue<HuffmanEncodingTreeNode*>;

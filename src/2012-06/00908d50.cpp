// roc 2012-06 00908d50  unit: RBX::Ball  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00908d50
//
// 00908d50  a1f467e500           mov eax, dword ptr [0xe567f4]
// 00908d55  40                   inc eax
// 00908d56  a3f467e500           mov dword ptr [0xe567f4], eax
// 00908d5b  c3                   ret 
// copied from an identical function in another client (function ?increment@Server@ns_ROCX000009@@QAEHXZ)

namespace ns_ROCX000009 {
int g_counter_8be5dc;

struct Server
{
    int increment();
};

int Server::increment()
{
    return ++g_counter_8be5dc;
}
}

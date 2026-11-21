// Self-contained test for 004a8b60 (IdSerializer::deserializeInstanceRef)
// thiscall member function with 3 stack args

namespace RBX
{
    class Instance
    {
    public:
        Instance() {}
        virtual ~Instance() {}
    };

    namespace RakNet
    {
        class BitStream
        {
        public:
            BitStream() {}
        };
    }

    namespace Guid
    {
        struct Data
        {
            unsigned int data1;
            unsigned short data2;
            unsigned short data3;
            unsigned char data4[8];
        };
    }

    namespace Reflection
    {
        class RefPropertyDescriptor;
        class ConstProperty;
    }

    class Instance;

    // Forward declarations for template types
    template<typename T> class FactoryProduct;
    template<typename T> class BoundFuncDesc;

    // VHint namespace for FactoryProduct
    namespace VHint
    {
        template<typename T>
        class FactoryProduct
        {
        public:
            // Creator method - thiscall, ret 8 (2 stack args)
            // Matches 0x4a70b0
            __declspec(noinline) void Creator(RakNet::BitStream& stream, void* context)
            {
                // Dummy implementation - just needs to exist
            }
        };
    }

    // Network namespace for BoundFuncDesc
    namespace Network
    {
        namespace VPlayers
        {
            template<typename T>
            class BoundFuncDesc
            {
            public:
                // Constructor or static method - cdecl, takes 2 args
                // Matches 0x49ba80
                __declspec(noinline) BoundFuncDesc(void* context, const Guid::Data& guid)
                {
                    // Dummy implementation
                }
            };
        }
    }

    namespace Network
    {
        class IdSerializer : public Instance
        {
        public:
            // FactoryProduct creator at offset 0xF54 (from 0x4a70b0: add ecx, 0xF54)
            char factory_padding[0xF54];
            VHint::FactoryProduct<void> factoryProduct; // Simplified

            // IdSerializer method at 004a8b60
            // thiscall: ecx = this, ret 0xC (3 stack args)
            // Assembly:
            //   mov eax, [esp+4]     ; arg1 (BitStream&)
            //   push esi
            //   mov esi, [esp+0x10]  ; arg3 (context)
            //   push esi             ; push context
            //   push eax             ; push stream
            //   call FactoryProduct::Creator  ; ecx = this (IdSerializer*), calls Creator(stream, context)
            //   mov ecx, [esp+0xC]   ; arg2 (Guid::Data&)
            //   push ecx             ; push guid
            //   push esi             ; push context
            //   call BoundFuncDesc   ; BoundFuncDesc(context, guid)
            //   add esp, 8
            //   pop esi
            //   ret 0xC

            __declspec(noinline) void deserializeInstanceRef(
                RakNet::BitStream& stream,
                Guid::Data& guid,
                void* context)
            {
                // Call FactoryProduct::Creator(stream, context)
                // ecx = this (IdSerializer*), Creator is at this+0xF54
                VHint::FactoryProduct<void>* factory = 
                    reinterpret_cast<VHint::FactoryProduct<void>*>(reinterpret_cast<char*>(this) + 0xF54);
                factory->Creator(stream, context);

                // Call BoundFuncDesc(context, guid)
                Network::VPlayers::BoundFuncDesc<void> boundFunc(context, guid);
            }
        };
    }
}

// Force template instantiation
namespace RBX { namespace VHint { template class FactoryProduct<void>; } }
namespace RBX { namespace Network { namespace VPlayers { template class BoundFuncDesc<void>; } } }

// Force emission
void (RBX::Network::IdSerializer::*force_deserializeInstanceRef)(
    RBX::RakNet::BitStream&,
    RBX::Guid::Data&,
    void*) = &RBX::Network::IdSerializer::deserializeInstanceRef;
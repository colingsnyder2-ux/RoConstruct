// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
    namespace Reflection {
        class PropertyDescriptor;
        class SignalInstance;
        class SignalSource;
        class SignalDescriptor {
        protected:
            SignalInstance* findSignalInstance(const SignalSource* source) const;
        };
    }
    class Instance {
    public:
        void raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor);
    };
    namespace Network {
        class Players {
        public:
            static bool backendProcessing(const Instance* instance, bool b);
        };
    }
}

// INFERRED: helper to reach the protected member without changing its mangled name
struct SignalDescriptorAccess : RBX::Reflection::SignalDescriptor {
    using RBX::Reflection::SignalDescriptor::findSignalInstance;
};

// INFERRED: layout of the ClickDetector-like object
struct S {
    char pad0[0x144];
    float threshold;
    bool flag;
};

// INFERRED: unknown globals (property descriptor and signal descriptor objects)
extern "C" char g_0097bf64[];
extern "C" char g_0097bf80[];

// signal0<...>::operator() (truncated mangled name)
extern "C" void __fastcall fn_004b5950(void* signal, int unusedEdx, float* arg);

extern "C" void __fastcall fn_00629ac0(S* self, int unusedEdx, int arg1, float value)
{
    if (self->threshold > value) {
        self->flag = !self->flag;
        reinterpret_cast<RBX::Instance*>(self)->raisePropertyChanged(
            *reinterpret_cast<const RBX::Reflection::PropertyDescriptor*>(g_0097bf64));
        if (RBX::Network::Players::backendProcessing(reinterpret_cast<RBX::Instance*>(self), true)) {
            RBX::Reflection::SignalInstance* inst =
                reinterpret_cast<const SignalDescriptorAccess*>(g_0097bf80)->findSignalInstance(
                    reinterpret_cast<const RBX::Reflection::SignalSource*>(
                        reinterpret_cast<char*>(self) + 0x14));
            if (inst)
                fn_004b5950(reinterpret_cast<char*>(inst) + 0x10, 0, &value);
        }
    }
}

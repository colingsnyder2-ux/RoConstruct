// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdexcept>

namespace RBX {
    class runtime_error : public std::runtime_error
    {
    public:
        runtime_error(const char* fmt, ...);
    };

    namespace Security {
        enum Identities { Anonymous };
        enum Permissions { None };

        bool isInRole(Identities identity, Permissions permission);

        class Context
        {
            Identities identity;
        public:
            void requirePermission(Permissions permission, const char* operation) const;
        };

        void Context::requirePermission(Permissions permission, const char* operation) const
        {
            if (!isInRole(identity, permission))
            {
                if (operation)
                    throw RBX::runtime_error("s %s", operation);
                else
                    throw RBX::runtime_error("s");
            }
        }
    }
}

#pragma once
#include "util/boost.hpp"
// Inactive candidate inferred from 004277d0 and worker_thread construction.
class LoginRenewer : public RBX::worker_thread {
public:
    LoginRenewer();
};

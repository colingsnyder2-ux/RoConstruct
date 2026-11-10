// Inactive native 2008-06 Marshaller (native-headers/AppLeaves2008/Marshaller2008.h).
#include "AppLeaves2008/Marshaller2008.h"
#include "util/standardout.h"

Marshaller::Marshaller(DWORD threadId) : useCount(0)
{
    this->threadId = threadId;
    Create(NULL, NULL, NULL, WS_POPUP);
}

Marshaller::~Marshaller()
{
}

LRESULT Marshaller::onExecute(UINT, WPARAM, LPARAM, BOOL&)
{
    try
    {
        boost::function0<void> function;
        {
            boost::mutex::scoped_lock lock(mutex);
            function = queue.front();
            queue.pop_front();
        }
        function();
    }
    catch (std::exception& e)
    {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, e);
    }
    return 0;
}

void Marshaller::post(boost::function0<void> function)
{
    {
        boost::mutex::scoped_lock lock(mutex);
        queue.push_back(function);
    }
    ::PostMessage(m_hWnd, 0x465, 0, 0);
}

void Marshaller::OnFinalMessage(HWND)
{
    delete this;
}

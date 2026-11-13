// >>> native-status (generated) -- do not edit >>>
// COutputView | 2008-06 | 9 byte-exact, inactive (not link-selected)
// 9/9 mapped addresses byte-exact | 0 unproved | no mapped strings | by colin (+4) (mixed 4)
// <<< native-status | src da05e7c6 | roc native-status --write
#include "COutputView.h"
#include <atlenc.h>
#include <time.h>

// Window message posted by onEvent 00437070 and handled by 00437520.
#define WM_STANDARD_OUT_MESSAGE (WM_USER + 0x65)

IMPLEMENT_DYNAMIC(COutputView, CSecureHtmlView)

// Original 00436a30.
COutputView::COutputView()
{
}

// Original 00436090: the page is the HTML resource 134.
void COutputView::OnInitialUpdate()
{
    CSecureHtmlView::OnInitialUpdate();
    LoadFromResource(134);
}

// Original 004364b0.
void COutputView::OnDocumentComplete(LPCTSTR)
{
    document = GetHtmlDocument();
    if (document) {
        CComPtr<IHTMLElementCollection> all;
        document->get_all(&all);
        CComPtr<IDispatch> item;
        all->item(CComVariant("output"), CComVariant(), &item);
        output = item;
    } else {
        output.Release();
    }
}

// Original 00436b60.
void COutputView::appendElement(IHTMLElement* element)
{
    CComQIPtr<IHTMLDOMNode> node(element);
    CComPtr<IHTMLDOMNode> appended;
    if (output->appendChild(node, &appended) == S_OK) {
        element->scrollIntoView(CComVariant((short)0));
        nodes.push_back(node);
        if (nodes.size() > 250) {
            CComPtr<IHTMLDOMNode> removed;
            output->removeChild(nodes.front(), &removed);
            nodes.pop_front();
        }
    }
}

IMPLEMENT_DYNCREATE(CStandardOutputView, COutputView)

BEGIN_MESSAGE_MAP(CStandardOutputView, COutputView)
    ON_MESSAGE(WM_STANDARD_OUT_MESSAGE, OnStandardOutMessage)
END_MESSAGE_MAP()

// Original 004373a0.
CStandardOutputView::CStandardOutputView()
{
    flag_f4 = true;
    boost::mutex::scoped_lock lock(RBX::StandardOut::singleton()->sync);
    RBX::Notifier<RBX::StandardOut, RBX::StandardOutMessage>::connect(RBX::StandardOut::singleton(), this);
}

// Original 00436ce0.
CStandardOutputView::~CStandardOutputView()
{
    boost::mutex::scoped_lock lock(RBX::StandardOut::singleton()->sync);
    RBX::Notifier<RBX::StandardOut, RBX::StandardOutMessage>::disconnect(RBX::StandardOut::singleton(), this);
}

// Original 00437070.
void CStandardOutputView::onEvent(const RBX::StandardOut*, RBX::StandardOutMessage message)
{
    boost::mutex::scoped_lock lock(messagesLock);
    if (messages.empty())
        ::PostMessage(m_hWnd, WM_STANDARD_OUT_MESSAGE, 0, 0);
    messages.push_back(message);
    if (messages.size() > 250)
        messages.pop_front();
}

// Original 00437150.
void CStandardOutputView::appendMessage(RBX::MessageType type, const char* message, __time64_t time)
{
    CStringW text(message);
    CStringW escaped;
    int length = ATL::EscapeXML(text, text.GetLength(), NULL, 0);
    ATL::EscapeXML(text, text.GetLength(), escaped.GetBufferSetLength(length), length);
    escaped.ReleaseBuffer();

    CStringW html;
    if (type != RBX::MESSAGE_OUTPUT && time != 0) {
        char buffer[32];
        _ctime64_s(buffer, 32, &time);
        html = buffer;
        html += " - ";
    }
    switch (type) {
    case RBX::MESSAGE_INFO:
        html += "<FONT color=\"blue\">";
        html += escaped;
        html += "</FONT>";
        break;
    case RBX::MESSAGE_WARNING:
        html += "<STRONG><FONT color=\"orange\">";
        html += escaped;
        html += "</FONT>";
        break;
    case RBX::MESSAGE_ERROR:
        html += "<STRONG><FONT color=\"red\">";
        html += escaped;
        html += "</FONT>";
        break;
    case RBX::MESSAGE_OUTPUT:
        html += escaped;
        break;
    }

    CComPtr<IHTMLElement> element;
    if (document) {
        document->createElement(CComBSTR("DIV"), &element);
        element->put_innerHTML(CComBSTR(html));
        appendElement(element);
    }
}

// Original 00437520.
LRESULT CStandardOutputView::OnStandardOutMessage(WPARAM, LPARAM)
{
    for (;;) {
        std::string text;
        RBX::MessageType type;
        __time64_t time;
        {
            boost::mutex::scoped_lock lock(messagesLock);
            if (messages.empty())
                break;
            if (messages.size() > 250) {
                messages.pop_front();
                continue;
            }
            type = messages.front().type;
            text = messages.front().message;
            time = messages.front().time;
            messages.pop_front();
        }
        appendMessage(type, text.c_str(), time);
    }
    return 0;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class ATL::CComPtrBase<IDispatch>;
template class ATL::CComPtrBase<IHTMLDOMNode>;
template class ATL::CComPtrBase<IHTMLDocument2>;
template class ATL::CComPtrBase<IHTMLElement>;
template class ATL::CComPtrBase<IHTMLElementCollection>;
template class RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage>;
template class std::_Deque_const_iterator<ATL::CComPtr<IHTMLDOMNode>,std::allocator<ATL::CComPtr<IHTMLDOMNode> >,1>;
template class std::_Deque_const_iterator<RBX::StandardOutMessage,std::allocator<RBX::StandardOutMessage>,1>;
template class std::_Deque_iterator<RBX::StandardOutMessage,std::allocator<RBX::StandardOutMessage>,1>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *,std::allocator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *,std::allocator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *> >;
template class std::vector<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *,std::allocator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *> >;

/** 
  @file GConsole/GConsole.cpp

*/

#include "GConsole.h"
#include "G3D/stringutils.h"
#include "G3D/fileutils.h"
#include "GLG3D/RenderDevice.h"
#include "GLG3D/Draw.h"

namespace G3D {

GConsoleRef GConsole::create(const GFontRef& f, const Settings& s, Callback callback, void* data) {
    return new GConsole(f, s, callback, data);
}

GConsole::GConsole(const GFontRef& f, const Settings& s, Callback callback, void* data) :
    m_font(f),
    m_settings(s),
    m_cursorPos(0),
    m_callback(callback),
    m_callbackData(data),
    m_bufferShift(0),
    m_resetHistoryIndexOnEnter(true),
    m_inCompletion(false),
    m_rect(Rect2D::xywh(-(float)inf(), -(float)inf(), (float)inf(), (float)inf())) {

    debugAssert(m_font.notNull());

    unsetRepeatKeysym();
    m_keyDownTime = System::time();
    setActive(true);

    m_historyIndex = m_history.size() - 1;

    m_posedModel2D = new PosedGConsole2D(this);
}


GConsole::~GConsole() {
    // Intentionally empty
}


void GConsole::setActive(bool a) {
    if (m_active != a) {
        unsetRepeatKeysym();
        m_active = a;

        if (m_active) {
            // Conservative; this will be refined in render
            m_rect = Rect2D::xywh(-(float)inf(), -(float)inf(), (float)inf(), (float)inf());
        } else {
            m_rect = Rect2D::xywh(0,0,0,0);
        }
    }
}


void GConsole::getPosedModel(Array<PosedModelRef>& posedArray, Array<PosedModel2DRef>& posed2DArray) {
    if (m_active) {
        posed2DArray.append(m_posedModel2D);
    }
}


void GConsole::issueCommand() {

    string oldCommandLine = m_currentLine;
    
    m_currentLine = string();
    m_cursorPos = 0;

    // Jump back to the end
    m_bufferShift = 0;

    if (m_settings.commandEcho) {
        print(oldCommandLine, m_settings.defaultCommandColor);
    } else {
        addToCompletionHistory(oldCommandLine);
    }

    m_history.push(oldCommandLine);

    if (m_resetHistoryIndexOnEnter) {
        // Note that we need to go one past the end of the list so that
        // the first up arrow allows us to hit the last element.
        m_historyIndex = m_history.size();
        m_resetHistoryIndexOnEnter = true;
    }

    onCommand(oldCommandLine);
}


void GConsole::setCallback(Callback c, void* d) {
    m_callback = c;
    m_callbackData = d;
}


void GConsole::onCommand(const string& cmd) {
    if (m_callback) {
        m_callback(cmd, m_callbackData);
    }
}


void GConsole::clearBuffer() {
    m_buffer.clear();
    m_bufferShift = 0;
}


void GConsole::clearHistory() {
    m_history.clear();
}


void GConsole::paste(const string& s) {
    if (s.empty()) {
        // Nothing to do
        return;
    }

    int i = 0;

    // Separate the string by newlines and paste each individually
    do {
        int j = s.find('\n', i);

        bool issue = true;

        if (j == string::npos) {
            j = s.size();
            issue = false;
        }
            
        string insert = s.substr(i, j - i + 1);

        if (! insert.empty()) {
            if (insert[0] == '\r') {
                // On Win32, we can conceivably get carriage returns next to newlines in a paste
                insert = insert.substr(1, insert.size() - 1);
            }

            if (! insert.empty() && (insert[insert.size() - 1] == '\r')) {
                insert = insert.substr(0, insert.size() - 1);
            }

            if (! insert.empty()) {
                string begin  = m_currentLine.substr(0, max(0, m_cursorPos - 1));
                string end    = m_currentLine.substr(m_cursorPos, m_currentLine.size() - m_cursorPos + 1);

                m_currentLine = begin + insert + end;
                m_cursorPos += insert.size();
            }
        }

        if (issue) {
            issueCommand();
        }

        i = j + 1;
    } while (i < (int)s.size());
}


void GConsole::copyClipboard(const string& s) const {
#   ifdef G3D_WIN32
        if (OpenClipboard(NULL)) {
            HGLOBAL hMem = GlobalAlloc(GHND | GMEM_DDESHARE, s.size() + 1);
            if (hMem) {
                char *pMem = (char*)GlobalLock(hMem);
                strcpy(pMem, s.c_str());
                GlobalUnlock(hMem);

                EmptyClipboard();
                SetClipboardData(CF_TEXT, hMem);
            }

            CloseClipboard();
            GlobalFree(hMem);
        }
#   endif
}


void GConsole::pasteClipboard() {
    string s;

#   ifdef G3D_WIN32
        if (OpenClipboard(NULL)) {
            HANDLE h = GetClipboardData(CF_TEXT);

            if (h) {
	            char* temp = (char*)GlobalLock(h);
                if (temp) {
    	            s = temp;
                }
                temp = NULL;
	            GlobalUnlock(h);
            }
            CloseClipboard();
        }
#   endif

    paste(s);
}


void __cdecl GConsole::printf(const char* fmt, ...) {
	va_list arg_list;
	va_start(arg_list, fmt);
    vprintf(fmt, arg_list);
    va_end(arg_list);
}


void __cdecl GConsole::vprintf(const char* fmt, va_list argPtr) {
    print(vformat(fmt, argPtr), m_settings.defaultPrintColor);
}


void GConsole::print(const string& s, const Color4& c) {
    addToCompletionHistory(s);

    // If the buffer is too long, pop one from the front
    if (m_buffer.size() >= m_settings.maxBufferLength) {
        m_buffer.popFront();
    }

    m_buffer.pushBack(Text(s, c));
}


static void parseForCompletion(
    const GConsole::string&  source,
    const int                x,
    GConsole::string&        beginStr,
    GConsole::string&        matchStr,
    GConsole::string&        endStr) {

    // Search backwards for a non-identifier character (start one before cursor)
    int i = x - 1;

    while ((i >= 0) && (isDigit(source[i]) || isLetter(source[i]))) {
        --i;
    }

    beginStr = source.substr(0, i + 1);
    matchStr = source.substr(i + 1, x - i - 1);
    endStr   = source.substr(x, source.size() - x + 1);
}


/*inline static bool isQuote(char c) {
    return (c == '\'') || (c == '\"');
}
*/


void GConsole::generateFilenameCompletions(Array<string>& files) {

    if (m_cursorPos == 0) {
        // Nothing to do
        return;
    }

    // Walk backwards, looking for a slash space or a quote that breaks the filename)
    int i = m_cursorPos - 1;

    while ((i > 0) && 
            ! isWhiteSpace(m_currentLine[i]) &&
            ! isQuote(m_currentLine[i])) {
        --i;
    }

    string filespec = m_currentLine.substr(i, m_cursorPos - i + 1) + "*";

    getFiles(filespec, files, false);
    getDirs(filespec, files, false);
}


void GConsole::beginCompletion() {
    m_completionArray.fastClear();

    // Separate the current line into two pieces; before and after the current word.
    // A word follows normal C++ identifier rules.
    string matchStr;

    parseForCompletion(m_currentLine, m_cursorPos, m_completionBeginStr, matchStr, m_completionEndStr);

    // Push the current command on so that we can TAB back to it
    m_completionArray.push(matchStr);
    m_completionArrayIndex = 0;

    // Don't insert the same completion more than once
    static Set<string> alreadySeen;

    if (m_settings.performFilenameCompletion) {
        static Array<string> fcomplete;

        generateFilenameCompletions(fcomplete);

        for (int i = 0; i < fcomplete.size(); ++i) {
            const string& s = fcomplete[i];
            if (! alreadySeen.contains(s)) {
                m_completionArray.push(s);
            }
        }

        fcomplete.fastClear();
    }


    if (m_settings.performCommandCompletion && ! matchStr.empty()) {
        // Generate command completions against completionHistory
        for (int i = 0; i < m_completionHistory.size(); ++i) {
            const string& s = m_completionHistory[i];
            if (beginsWith(s, matchStr) && ! alreadySeen.contains(s)) {
                m_completionArray.push(s);
            }
        }

        // Generate command completions against seed array
        for (int i = 0; i < m_settings.commandCompletionSeed.size(); ++i) {
            const string& s = m_settings.commandCompletionSeed[i];
            if (beginsWith(s, matchStr) && ! alreadySeen.contains(s)) {
                m_completionArray.push(s);
            }
        }
    }

    if (m_completionArray.size() > 1) {
        // We found at least one new alternative to the current string
        m_inCompletion = true;
    }

    alreadySeen.clear();
}


void GConsole::endCompletion() {
    // Cancel the current completion
    m_inCompletion = false;
}


void GConsole::addTokenToCompletionHistory(const string& s) {
    // See if already present
    if (m_completionHistorySet.contains(s)) {
        return;
    }

    // See if we need to remove a queue element
    if (m_completionHistory.size() > m_settings.maxCompletionHistorySize) {
        m_completionHistorySet.remove(m_completionHistory.popFront());
    }

    m_completionHistory.pushBack(s);
    m_completionHistorySet.insert(s);
}


void GConsole::addToCompletionHistory(const string& s) {
    // Parse tokens.  

    // This algorithm treats a token as a legal C++ identifier, number, or string.
    // A better algorithm might follow the one from emacs, which considers pathnames
    // and operator-separated tokens to also be tokens when combined.

    static bool initialized = false;
    static TextInput::Settings settings;
    if (! initialized) {

        settings.cComments = false;
        settings.cppComments = false;
        settings.msvcSpecials = false;

        initialized = true;
    }

    try {
        TextInput t(TextInput::FROM_STRING, s, settings);

        while (t.hasMore()) {
            Token x = t.read();

            // No point in considering one-character completions
            if (x.string().size() > 1) {
                if (x.type() == Token::STRING) {
                    // Recurse into the string to grab its tokens
                    addToCompletionHistory(x.string());
                } else {
                    // Add the raw unparsed string contents
                    addTokenToCompletionHistory(x.string());
                } // if string
            } // if
        } // while
    } catch (...) {
        // In the event of a parse exception we just give up on this string;
        // the worst that will happen is that we'll miss the opportunity to 
        // add some tokens.
    }
}


void GConsole::completeCommand(int direction) {
    if (! m_inCompletion) {
        beginCompletion();

        if (! m_inCompletion) {
            // No identifier under cursor
            return;
        }
    }

    // Compose new command line
    m_completionArrayIndex = (m_completionArrayIndex + m_completionArray.size() + direction) % m_completionArray.size();

    const string& str = m_completionArray[m_completionArrayIndex];
    m_currentLine = m_completionBeginStr + str + m_completionEndStr;
    m_cursorPos = m_completionBeginStr.size() + str.size();

    m_resetHistoryIndexOnEnter = true;
}


void GConsole::processRepeatKeysym() {
    if ((m_repeatKeysym.sym != SDLK_TAB) && m_inCompletion) {
        endCompletion();
    }

    switch (m_repeatKeysym.sym) {
    case SDLK_UNKNOWN:
        // No key
        break;

    case SDLK_RIGHT:
        if (m_cursorPos < (int)m_currentLine.size()) {
            ++m_cursorPos;
        }
        break;

    case SDLK_LEFT:
        if (m_cursorPos > 0) {
            --m_cursorPos;
        }
        break;

    case SDLK_HOME:
        m_cursorPos = 0;
        break;

    case SDLK_END:
        m_cursorPos = m_currentLine.size();
        break;

    case SDLK_DELETE:
        if (m_cursorPos < (int)m_currentLine.size()) {
            m_currentLine = 
                m_currentLine.substr(0, m_cursorPos) + 
                m_currentLine.substr(m_cursorPos + 1, string::npos);
            m_resetHistoryIndexOnEnter = true;
        }
        break;

    case SDLK_BACKSPACE:
        if (m_cursorPos > 0) {
            m_currentLine = 
                m_currentLine.substr(0, m_cursorPos - 1) + 
                ((m_cursorPos < (int)m_currentLine.size()) ? 
                  m_currentLine.substr(m_cursorPos, string::npos) :
                  string());
            m_resetHistoryIndexOnEnter = true;
           --m_cursorPos;
        }
        break;

    case SDLK_UP:
        if (m_historyIndex > 0) {
            historySelect(-1);
        }
        break;

    case SDLK_DOWN:
        if (m_historyIndex < m_history.size() - 1) {
            historySelect(+1);
        }
        break;

    case SDLK_TAB:
        // Command completion
        if ((m_repeatKeysym.mod & KMOD_SHIFT) != 0) {
            completeCommand(-1);
        } else {
            completeCommand(1);
        }
        break;

    case SDLK_PAGEUP:
        if (m_bufferShift < m_buffer.length() - m_settings.numVisibleLines + 1) {
            ++m_bufferShift;
        }
        break;

    case SDLK_PAGEDOWN:
        if (m_bufferShift > 0) {
            --m_bufferShift;
        }
        break;

    case SDLK_RETURN:
        issueCommand();
        break;

    default:
        if ((m_repeatKeysym.sym >= SDLK_SPACE) &&
            (m_repeatKeysym.sym <= SDLK_z)) {

            // Insert character
            char c = m_repeatKeysym.unicode & 0xFF;
            m_currentLine = 
                m_currentLine.substr(0, m_cursorPos) + 
                c +
                ((m_cursorPos < (int)m_currentLine.size()) ? 
                  m_currentLine.substr(m_cursorPos, string::npos) :
                  string());
            ++m_cursorPos;

            m_resetHistoryIndexOnEnter = true;
        } else {
            // This key wasn't processed by the console
            debugAssertM(false, "Unexpected repeat key");
        }
    }
}


void GConsole::historySelect(int direction) {
    m_historyIndex += direction;
    m_currentLine = m_history[m_historyIndex];
    m_cursorPos = m_currentLine.size();
    m_resetHistoryIndexOnEnter = false;
}


void GConsole::setRepeatKeysym(SDL_keysym key) {
    m_keyDownTime = System::time();
    m_keyRepeatTime = m_keyDownTime + m_settings.keyRepeatDelay;
    m_repeatKeysym = key;
}


void GConsole::unsetRepeatKeysym() {
    m_repeatKeysym.sym = SDLK_UNKNOWN;
}


bool GConsole::onEvent(const GEvent& event) {

    if (! m_active) {
        if ((event.type == SDL_KEYDOWN) &&
            ((event.key.keysym.unicode & 0xFF) == '~')) {

            // '~': Open console
            setActive(true);
            return true;

        } else {

            // Console is closed, ignore key
            return false;
        }
    }

    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
            // Close the console
            setActive(false);
            return true;

        case SDLK_RIGHT:
        case SDLK_LEFT:
        case SDLK_DELETE:
        case SDLK_BACKSPACE:
        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_TAB:
        case SDLK_PAGEUP:
        case SDLK_PAGEDOWN:
        case SDLK_RETURN:
        case SDLK_HOME:
        case SDLK_END:
            setRepeatKeysym(event.key.keysym);
            processRepeatKeysym();
            return true;
            break;

        default:

            if ((((event.key.keysym.mod & KMOD_CTRL) != 0) &&
                 ((event.key.keysym.sym == SDLK_v) || (event.key.keysym.sym == SDLK_y))) ||

                (((event.key.keysym.mod & KMOD_SHIFT) != 0) &&
                (event.key.keysym.sym == SDLK_INSERT))) {

                // Paste (not autorepeatable)
                pasteClipboard();
                return true;

            } else if (((event.key.keysym.mod & KMOD_CTRL) != 0) &&
                (event.key.keysym.sym == SDLK_k)) {

                // Cut (not autorepeatable)
                string cut = m_currentLine.substr(m_cursorPos);
                m_currentLine = m_currentLine.substr(0, m_cursorPos);

                copyClipboard(cut);

                return true;

            } else if ((event.key.keysym.sym >= SDLK_SPACE) &&
                (event.key.keysym.sym <= SDLK_z)) {

                // A normal character
                setRepeatKeysym(event.key.keysym);
                processRepeatKeysym();
                return true;

            } else {
                // This key wasn't processed by the console
                return false;
            }
        }
        break;

    case SDL_KEYUP:
        if (event.key.keysym.sym == m_repeatKeysym.sym) {
            unsetRepeatKeysym();
            return true;
        }
        break;
    }

    return false;
}


void GConsole::render(RenderDevice* rd) {
    
    if (! m_active) {
        return;
    }

    static const float  pad = 2;
    const float         fontSize = m_settings.lineHeight - 3;
   
    Rect2D rect;

    RealTime now = System::time();

    bool hasKeyDown = (m_repeatKeysym.sym != SDLK_UNKNOWN);

    // If a key is being pressed, process it on a steady repeat schedule.
    if (hasKeyDown && (now > m_keyRepeatTime)) {
        processRepeatKeysym();
        m_keyRepeatTime = now + 1.0 / m_settings.keyRepeatRate;
    }


    // Only blink the cursor when keys are not being pressed or
    // have not recently been pressed.
    bool solidCursor = hasKeyDown || (now - m_keyRepeatTime < 1.0 / m_settings.blinkRate);
    if (! solidCursor) {
        static const RealTime zero = System::time();
        solidCursor = isOdd((int)((now - zero) * m_settings.blinkRate));
    }

    {
        float w = rd->getWidth();
        float h = rd->getHeight();
        float myHeight = m_settings.lineHeight * m_settings.numVisibleLines + pad * 2;

        rect = m_rect = Rect2D::xywh(pad, h - myHeight - pad, w - pad * 2, myHeight);
    }

    rd->push2D();

        rd->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
        if (m_settings.backgroundColor.a > 0) {
            Draw::fastRect2D(rect, rd, m_settings.backgroundColor);
        }

        rect = Rect2D::xyxy(rect.x0y0() + Vector2(2,1), rect.x1y1() - Vector2(2, 1));
        // Print history
        for (int count = 0; count < m_settings.numVisibleLines - 1; ++count) {
            int q = m_buffer.size() - count - 1 - m_bufferShift;
            if (q >= 0) {
                m_font->draw2D(rd, m_buffer[q].value, rect.x0y1() - Vector2(0, m_settings.lineHeight * (count + 2)), fontSize, m_buffer[q].color);
            }
        }

        if (m_bufferShift > 0) {
            // Draw a line indicating that we aren't looking at the bottom of the buffer
            rd->setColor(Color3::white());
            rd->setLineWidth(1.0f);
            rd->beginPrimitive(RenderDevice::LINES);
                Vector2 v(rect.x0() - 0.3, rect.y1() - m_settings.lineHeight + 1 - 0.3);
                rd->sendVertex(v);
                rd->sendVertex(v + Vector2(rect.width(), 0));
            rd->endPrimitive();
        }

        m_font->draw2D(rd, m_currentLine, rect.x0y1() - Vector2(0, m_settings.lineHeight), fontSize, m_settings.defaultCommandColor);

        // Draw cursor
        if (solidCursor) {
            // Put cursor under a specific character.  We need to check bounds to do this because we might not
            // have a fixed width font.
            Vector2 bounds;
            if (m_cursorPos > 0) {
                bounds = m_font->get2DStringBounds(m_currentLine.substr(0, m_cursorPos), fontSize);
            }

            m_font->draw2D(rd, "_", rect.x0y1() + Vector2(bounds.x, -m_settings.lineHeight), fontSize, m_settings.defaultCommandColor);
        }

    rd->pop2D();
}


void GConsole::onNetwork() {
}


void GConsole::onLogic() {
}


void GConsole::onUserInput(UserInput* ui) {
}


void GConsole::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
}

//////////////////////////////////////////////

GConsole::PosedGConsole2D::PosedGConsole2D(GConsole* c) : m_console(c) {}

void GConsole::PosedGConsole2D::render(RenderDevice* rd) const {
    m_console->render(rd);
}

Rect2D GConsole::PosedGConsole2D::bounds() const {
    return m_console->m_rect;
}

float GConsole::PosedGConsole2D::depth() const {
    return 0.5;
}

} // G3D

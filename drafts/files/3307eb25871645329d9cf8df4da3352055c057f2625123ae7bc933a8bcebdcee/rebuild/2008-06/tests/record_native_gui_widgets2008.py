"""Verify the inactive native RBX gui widget recovery, pass 2 (2008-06): the rows of the gui widget units
0064e840..00657c00 that tests/record_native_widget.py does not compile (ArrowButton::isEnabled, ChatButton::isVisible
and the ArrowPanel template instances; pending: the ArrowPanel constructor / init, create<ArrowButton>, ChatWidget::process,
MenuItem::render2d and EquationDisplay::getLabel).

Builds (document-swap flags, VS2008 RTM 21022, native headers only; the classes are declared by the read-only owner
headers native-headers/gui/{ArrowPanel,WidgetChat,WidgetMenuItem,EquationDisplay}.h, no new header):
  * native-classes/GuiWidgets2008Arrow.cpp     ArrowButton::isEnabled 00657be0, create<ImageWidget>(Adorn*, std::string)
                                               00656f60, create<TopMenuBar>(std::string, Layout::Style) 00657000 and
                                               their shared_ptr / shared_count instances;
  * native-classes/GuiWidgets2008Chat.cpp      ChatButton::isVisible 0064ea90;
  * native-classes/GuiWidgets2008MenuItem.cpp  (pending body only).
Pending builds (NATIVE_GUIWIDGETS_PENDING; rows recorded exact=false, pending-build-only, never counted, vtables never
walked) against out/native-layouts/gui-widgets2008-pending, generated copies of headers owned by others, each with the
declarations below added:
  * gui/ArrowPanel.h (native): ArrowPanel::init(Adorn*, 5 x const std::string&, 4 x SDLKey) (00657780 calls 00657240
    with ten arguments; ret 0x28);
  * util/Object.h (native, core): Creatable<T>::create with five parameters (create<ArrowButton> 00657190 forwards five
    arguments to 006570a0 at 006571f3);
  * util/Rect.h (donor): `bool pointInRect(G3D::Vector2int16);` out of line (ChatWidget::process calls 00573130 at
    0064eb3b; the same proposal as record_native_widget.py);
  * v8tree/Instance.h (native, core): the donor's inline getRootAncestor() / getRootAncestor() const and static
    getRootAncestor(const Instance*) / (Instance*) (EquationDisplay::getLabel tests this at 00656963, inlines two parent
    steps +0x104 and calls 0042a5f0 at 0065697b);
  * gui/Widget.h (native): VerbWidget `Verb* getVerb() { return verb; }` (MenuItem::render2d reads verb +0x148 at
    0064ee3e and calls Verb slot 3 isChecked).

Rows are found by closure from seeds (each named by an original call site or vtable slot, asserted below): every
REL32/DIR32 relocation of an exact row is bound to the address the original instruction uses. A target defined in the
compiled object becomes a row at that address; a vtable target is checked by original RTTI (class name and subobject
offset) and walked slot by slot (main builds only). Every other target is verified: imports by DLL export name, string
literals by bytes, float constants (__real@) by bytes, type descriptors by RTTI name, external functions by the evidence
name or the EXTERNAL map (call sites read in the original disassembly). A symbol binds to one address. A row is counted
only when it is main-build exact, lies in one of the widget unit ranges (UNIT_RANGES) and is not counted by any other
receipt (top-level exact_function_rows of every other work/2008-06/shared-layouts receipt; receipts_checked in the
output). Writes work/2008-06/shared-layouts/gui-widgets2008-working.json.
"""
import glob
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
RECEIPT = ROOT / 'work/2008-06/shared-layouts/gui-widgets2008-working.json'
SOURCES = {name: R / 'native-classes' / ('GuiWidgets2008' + name + '.cpp') for name in ('Arrow', 'Chat', 'MenuItem')}
POST = {}
HEADERS = [R / 'native-headers/gui' / n for n in ('ArrowPanel.h', 'WidgetChat.h', 'WidgetMenuItem.h', 'EquationDisplay.h',
                                                  'Widget.h')]
PENDING_UNITS = ('Arrow', 'Chat', 'MenuItem')

# ---- pending overlay ------------------------------------------------------------------------------------------
pending = OUT / 'gui-widgets2008-pending'
for sub in ('gui', 'util', 'v8tree'):
    (pending / sub).mkdir(parents=True, exist_ok=True)


def overlay(source, relative, changes):
    text = Path(source).read_text()
    for old, new in changes:
        assert text.count(old) == 1, (relative, old)
        text = text.replace(old, new)
    (pending / relative).write_text(text)


overlay(R / 'native-headers/gui/ArrowPanel.h', 'gui/ArrowPanel.h', [(
    '\tpublic:\n\t\tArrowPanel(Adorn*, DataModel*, Controller::ControllerType);',
    '\tprotected:\n\t\tvoid init(Adorn*, const std::string&, const std::string&, const std::string&, const std::string&, '
    'const std::string&, SDLKey, SDLKey, SDLKey, SDLKey);\n'
    '\tpublic:\n\t\tArrowPanel(Adorn*, DataModel*, Controller::ControllerType);')])
overlay(R / 'native-headers/util/Object.h', 'util/Object.h', [(
    '\t\t\treturn boost::shared_ptr<Class>(new Class(p1, p2), Deleter());\n\t\t}\n',
    '\t\t\treturn boost::shared_ptr<Class>(new Class(p1, p2), Deleter());\n\t\t}\n'
    '\t\ttemplate<typename Class, typename Parameter1, typename Parameter2, typename Parameter3, typename Parameter4, '
    'typename Parameter5>\n'
    '\t\tstatic boost::shared_ptr<Class> create(Parameter1 p1, Parameter2 p2, Parameter3 p3, Parameter4 p4, Parameter5 p5)\n'
    '\t\t{\n\t\t\treturn boost::shared_ptr<Class>(new Class(p1, p2, p3, p4, p5), Deleter());\n\t\t}\n')])
overlay(ROOT / 'tools/rbxgs/Client/App/include/util/Rect.h', 'util/Rect.h', [(
    '\t\tbool pointInRect(G3D::Vector2int16 point)\n\t\t{\n\t\t\treturn pointInRect(point.x, point.y);\n\t\t}\n',
    '\t\tbool pointInRect(G3D::Vector2int16 point);\n')])
overlay(R / 'native-headers/v8tree/Instance.h', 'v8tree/Instance.h', [(
    '    Instance* getParent() const { return parent; }\n',
    '    Instance* getParent() const { return parent; }\n'
    '    const Instance* getRootAncestor() const { return parent ? parent->getRootAncestor() : this; }\n'
    '    Instance* getRootAncestor() { return parent ? parent->getRootAncestor() : this; }\n'
    '    static Instance* getRootAncestor(Instance* instance) { return instance ? instance->getRootAncestor() : NULL; }\n'
    '    static const Instance* getRootAncestor(const Instance* instance) '
    '{ return instance ? instance->getRootAncestor() : NULL; }\n')])
overlay(R / 'native-headers/gui/Widget.h', 'gui/Widget.h', [(
    '\tprotected:\n\t\tvirtual bool isEnabled();                                    // slot 30, 006423e0\n',
    '\tprotected:\n\t\tVerb* getVerb()\n\t\t{\n\t\t\treturn verb;\n\t\t}\n'
    '\t\tvirtual bool isEnabled();                                    // slot 30, 006423e0\n')])


def build(name, src, extra=(), post=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(post) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


objs, all_flags = {}, {}
for name, src in SOURCES.items():
    objs[name], all_flags[name] = build('NativeGuiWidgets2008_' + name, src, post=POST.get(name, ()))
    if name in PENDING_UNITS:
        objs[name + '-pending'], all_flags[name + '-pending'] = build(
            'NativeGuiWidgets2008_' + name + 'Pending', src, ['/I' + str(pending)],
            ['/DNATIVE_GUIWIDGETS_PENDING'] + POST.get(name, []))

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
pe = original.pe
TEXT = next(s for s in pe.sections if s.Name.startswith(b'.text'))
TEXT_LO = pe.OPTIONAL_HEADER.ImageBase + TEXT.VirtualAddress
TEXT_HI = TEXT_LO + TEXT.Misc_VirtualSize


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


def call_target(site):
    """Target of the direct call (or tail jump) instruction at `site` in the original."""
    assert original.data(site, 1) in (b'\xe8', b'\xe9'), hex(site)
    return (site + 5 + struct.unpack('<i', original.data(site + 1, 4))[0]) & 0xffffffff


def code(address, length):
    return original.data(address, length)


# ---- layout evidence read in the original (the classes' layouts are checked by record_native_widget.py) ----------
# ArrowButton::isEnabled reads dataModel +0x188 (00657be0: 8b 89 88 01 00 00) and RunService::runState +0x1b4
# (00657bed: 83 b8 b4 01 00 00 01); ChatButton::isVisible reads Players::localPlayer +0x1a0 (0064eaa0: 83 b8 a0 01 00 00
# 00); the ArrowPanel constructor stores controller +0x160 (006577f7) and dataModel +0x15c (00657858); MenuItem::render2d
# reads widgetState +0x144 (0064edda), verb +0x148 (0064ee3e) and accelerator._Mysize +0x160 (0064ef32);
# EquationDisplay::getLabel reads parent +0x104 (00656967), equation +0x188 (006569ab) and label +0x144 (006569c0).
assert code(0x657be0, 6) == b'\x8b\x89\x88\x01\x00\x00' and code(0x657bed, 7) == b'\x83\xb8\xb4\x01\x00\x00\x01'
assert code(0x64eaa0, 7) == b'\x83\xb8\xa0\x01\x00\x00\x00'
assert code(0x6577f7, 6) == b'\x89\x86\x60\x01\x00\x00' and code(0x657858, 6) == b'\x89\x8e\x5c\x01\x00\x00'
assert code(0x64edda, 6) == b'\x8b\x86\x44\x01\x00\x00' and code(0x64ee3e, 6) == b'\x8b\x8e\x48\x01\x00\x00'
assert code(0x64ef32, 7) == b'\x83\xbe\x60\x01\x00\x00\x00'
assert code(0x656967, 6) == b'\x8b\x86\x04\x01\x00\x00' and code(0x6569ab, 6) == b'\x8d\x8e\x88\x01\x00\x00'
assert code(0x6569c0, 6) == b'\x81\xc6\x44\x01\x00\x00'
# Allocation sizes of the create<...> instances: push size, malloc, then the constructor.
for factory, size, site, ctor in ((0x656f60, 0x180, 0x656fb4, 0x64f1c0),     # ImageWidget
                                  (0x657000, 0x15c, 0x657056, 0x573cb0),     # TopMenuBar(std::string, Style)
                                  (0x657190, 0x190, 0x6571f3, 0x6570a0)):    # ArrowButton (pending)
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size))
    assert at < site - factory and call_target(site) == ctor, (hex(factory), hex(size), hex(ctor))

# Externals whose evidence name differs from the compiled symbol (or has none): the address the original call site
# uses, asserted below with the site it was read from.
S = '?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
CALLS = {
    '??0ImageWidget@RBX@@QAE@PAVAdorn@1@ABV%s@Z' % S: (0x656fb4, 0x64f1c0),
    '??0TopMenuBar@RBX@@QAE@ABV%sW4Style@Layout@1@_N@Z' % S: (0x657056, 0x573cb0),
    '??0ArrowButton@RBX@@QAE@PAVAdorn@1@ABV%sW4SDLKey@@W4ControllerType@Controller@1@PAVDataModel@1@@Z' % S: (0x6571f3, 0x6570a0),
    '??$create@VRunService@RBX@@@ServiceProvider@RBX@@QBEPAVRunService@1@XZ': (0x657be6, 0x4530f0),
    '??$find@VPlayers@Network@RBX@@@ServiceProvider@RBX@@SAPAVPlayers@Network@1@PBVInstance@1@@Z': (0x64ea94, 0x491d50),
    '?clientIsPresent@Players@Network@RBX@@SA_NPBVInstance@3@_N@Z': (0x64eaac, 0x495e60),
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': (0x656d05, 0x405e30),  # shared_count catch funclet
    # pending bodies
    '?addGuiItem@GuiItem@RBX@@QAEXV?$shared_ptr@VGuiItem@RBX@@@boost@@@Z': (0x6572c6, 0x600f10),
    '??$create@VTopMenuBar@RBX@@PBDW4Style@Layout@2@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VTopMenuBar@RBX@@@boost@@PBDW4Style@Layout@1@@Z': (0x65726a, 0x601fd0),
    '??$create@VMenuSpacer@RBX@@MM@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VMenuSpacer@RBX@@@boost@@MM@Z': (0x657523, 0x6026e0),
    '??0MenuSpacer@RBX@@QAE@MM@Z': (0x602736, 0x6005e0),                                       # create<MenuSpacer> body
    '?getMyRect@GuiItem@RBX@@IBE?AVRect@2@XZ': (0x64eb34, 0x573310),
    '?pointInRect@Rect@RBX@@QAE_NVVector2int16@G3D@@@Z': (0x64eb3b, 0x573130),
    '??$create@VSoundService@Soundscape@RBX@@@ServiceProvider@RBX@@SAPAVSoundService@Soundscape@1@PBVInstance@1@@Z': (0x64eb5a, 0x5807b0),
    '?playSound@SoundService@Soundscape@RBX@@QAEXW4SoundType@3@@Z': (0x64eb64, 0x5bd820),
    '?chat@Players@Network@RBX@@QAEXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': (0x64eb9b, 0x49cb30),
    '?process@UnifiedWidget@RBX@@UAE?AVGuiResponse@2@ABVGuiEvent@2@@Z': (0x64ebd1, 0x574e70),
    '?getRootAncestor@Instance@RBX@@QBEPBV12@XZ': (0x65697b, 0x42a5f0),     # evidence name: the non-const twin (ICF)
    '?xyxy@Rect2D@G3D@@SA?AV12@ABVVector2@2@0@Z': (0x64edff, 0x4f35d0),
    '?menuSelect@GuiItem@RBX@@SAABVColor4@G3D@@XZ': (0x64ee0a, 0x573250),          # (0.7, 0.7, 0.7, 1); name provisional
    '?menuEnabledFill@GuiItem@RBX@@SAABVColor4@G3D@@XZ': (0x64ee32, 0x5731d0),     # (0.3, 0.3, 0.3, 1); name provisional
    '?menuDisabledFill@GuiItem@RBX@@SAABVColor4@G3D@@XZ': (0x64ee39, 0x573210),    # (0.6, 0.6, 0.6, 1); name provisional
    '?clear@Color4@G3D@@SAABV12@XZ': (0x64eec2, 0x7baf10),
    '?label2d@GuiItem@RBX@@IBEXPAVAdorn@2@ABV%sABVColor4@G3D@@2W4XAlign@12@@Z' % S: (0x64eed1, 0x573360),
}
for symbol, (site, value) in CALLS.items():
    assert call_target(site) == value, (symbol, hex(site), hex(value))
EXTERNAL = {symbol: value for symbol, (site, value) in CALLS.items()}
EXTERNAL.update({
    '??_Ebad_alloc@std@@UAEPAXI@Z': 0x4023c0,                                                # bad_alloc vtable slot 0
})
# sp_counted_impl_pd<T*, Creatable<Instance>::Deleter> deleting destructors: one ICF-folded body 00415000 (slot 0 of
# each RTTI-checked vtable; record_native_gui_hud_builder / record_native_mouse bind the same address).
for cls in ('ImageWidget', 'TopMenuBar', 'ArrowButton'):
    EXTERNAL['??_E?$sp_counted_impl_pd@PAV%s@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@2@@detail@boost@@UAEPAXI@Z' % cls] = 0x415000
UNPROVEN = {}
CLASS_NAMES = {'sInstance': b'Instance'}
EXTENT_SPLITS = {}
DATA = {}
FOLDED = {}

# Seeds: (address, compiled symbol), each named by an original call site or vtable slot.
assert d(0x84bffc + 4 * 30) == 0x657be0          # ArrowButton vtable slot 30 isEnabled
assert d(0x84232c + 4 * 21) == 0x64ea90          # ChatButton vtable slot 21 isVisible
assert d(0x84b45c) == 0x64ead0                   # ChatWidget GuiTarget vtable slot 0 process
assert d(0x84b5f4 + 4 * 24) == 0x64edb0          # MenuItem vtable slot 24 render2d
assert d(0x84becc + 4 * 25) == 0x656940          # EquationDisplay vtable slot 25 getLabel
for vt, cls in ((0x84bffc, 'ArrowButton'), (0x84232c, 'ChatButton'), (0x84b5f4, 'MenuItem'),
                (0x84becc, 'EquationDisplay'), (0x84c164, 'ArrowPanel')):
    assert original.vtable_class(vt) == ('.?AV%s@RBX@@' % cls, 0), (hex(vt), cls)
assert original.vtable_class(0x84b45c) == ('.?AVChatWidget@RBX@@', 0x130)
assert call_target(0x657295) == 0x656f60 and call_target(0x657504) == 0x657000 and call_target(0x656fce) == 0x656e00
assert call_target(0x6026a3) == 0x657780 and call_target(0x65792c) == 0x657240 and call_target(0x65732f) == 0x657190
SEEDS = {
    'Arrow': [
        (0x657be0, '?isEnabled@ArrowButton@RBX@@UAE_NXZ'),                                          # slot 30
        (0x656f60, '??$create@VImageWidget@RBX@@PAVAdorn@2@V%s@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VImageWidget@RBX@@@boost@@PAVAdorn@1@V%s@Z' % (S, S)),  # 00657295
        (0x657000, '??$create@VTopMenuBar@RBX@@V%sW4Style@Layout@2@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VTopMenuBar@RBX@@@boost@@V%sW4Style@Layout@1@@Z' % (S, S)),  # 00657504
    ],
    'Chat': [(0x64ea90, '?isVisible@ChatButton@RBX@@EBE_NXZ')],                                     # slot 21
    'MenuItem': [],
}
PENDING_SEEDS = {
    'Arrow': [(0x657780, '??0ArrowPanel@RBX@@QAE@PAVAdorn@1@PAVDataModel@1@W4ControllerType@Controller@1@@Z')],  # 006026a3
    'Chat': [(0x64ead0, '?process@ChatWidget@RBX@@EAE?AVGuiResponse@2@ABVGuiEvent@2@@Z'),           # 0084b45c slot 0
             (0x656940, '?getLabel@EquationDisplay@RBX@@MBE?AV%sXZ' % S)],                         # 0084becc slot 25
    'MenuItem': [(0x64edb0, '?render2d@MenuItem@RBX@@UAEXPAVAdorn@2@@Z')],                         # 0084b5f4 slot 24
}
OWN_CLASSES = 'ArrowPanel|ArrowButton|ChatButton|ChatWidget|MenuItem|EquationDisplay'
OWN = re.compile(r'(?:^|[^A-Za-z]|\?\?_[EG])(%s)@RBX@@' % OWN_CLASSES)
NOT_ATTEMPTED = {
    '00656db0 / 00656c30': 'ArrowPanel::isVisible: dataModel->workspace (DataModel +0x204) +0x2a8 is a lazily cached 8-byte '
                           'value read through a pointer to member (00656c30: dirty +8, object +0xc, member pointer '
                           '+0x10..+0x18); its type is not derived, so no declaration exists',
    '00656690 / 00656640': 'HealthHud::render2d (678 bytes): Humanoid::getLocalHumanoidFromContext 005d9bb0 (pending in '
                           'humanoid2008), health / maxHealth +0x1a8 / +0x1ac with no native declaration, unnamed colour '
                           'statics 005d7560 / 00514910 / 005148b0 and the Adorn helper 005ceea0; 00656640 is '
                           'ServiceProvider::find<Visit>(const Instance*) with the donor inline findServiceProvider loop '
                           '(the native v8tree/Service.h declares findServiceProvider out of line)',
    '00657c40..006588a0': 'SafeChat unit (Fonts\\\\safechat.xml at 00657c40, ChatOption dtor 00658200, singleton 00658880): '
                          'SafeChat / ChatOption are declared by GuiHud2008/GuiBuilder2008.h (another owner) with only '
                          'the members GuiBuilder reads',
    '0064f6b0..00650ef0 / 006510a0..00656430': 'ChatOutput / ScoreHud units (owner: hud family, gui/ChatOutput.h, '
                                              'gui/ScoreHud.h); listed as not attempted in hud-family-working.json',
}


LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
SLOTS = []   # (build, own vtable, symbol, original value, where)
HEADER_GAPS = []


def own_vtable(rtti):
    if any(rtti.startswith('.?AV%s@RBX@@' % c) for c in OWN_CLASSES.split('|')):
        return True
    return False


class Build:
    def __init__(self, name, obj, walk_vtables):
        self.name, self.obj, self.walk = name, Path(obj), walk_vtables
        self.raw = self.obj.read_bytes()
        self.sections, self.symbols, self.definitions, self.starts = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}
        self.binding = {}     # symbol -> (address, origin)
        self.rows = {}        # address -> row
        self.vtables = {}
        self.queue = []

    def bind(self, symbol, value, origin):
        prev = self.binding.setdefault(symbol, (value, origin))
        assert prev[0] == value, (self.name, 'inconsistent', symbol, hex(prev[0]), prev[1], hex(value), origin)

    def literal(self, symbol):
        pos, at = self.definitions[symbol]
        table = self.sections[at]
        return self.raw[table[4] + pos:table[4] + table[3]].split(b'\0')[0] + b'\0'

    def classify(self, symbol, value, where):
        if symbol in self.bodies and not LOCAL_EH.match(symbol):
            self.bind(symbol, value, where)
            self.queue.append((value, symbol))
            return 'own row'
        if symbol.startswith('??_E') and '??_G' + symbol[4:] in self.bodies:
            # vector deleting destructor referenced, scalar one compiled: the same body in the original
            self.bind('??_G' + symbol[4:], value, where)
            self.queue.append((value, '??_G' + symbol[4:]))
            return 'own row (??_G)'
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
            return '%s!%s' % hit
        if symbol.startswith('??_C@'):
            lit = self.literal(symbol)
            assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
            return 'literal %r' % lit[:-1].decode()
        if re.match(r'^\?s[A-Z]\w*@RBX@@3QBDB$', symbol):
            lit = self.literal(symbol) if symbol in self.definitions else CLASS_NAMES[symbol[1:symbol.index('@')]] + b'\0'
            assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
            return 'class name %r' % lit[:-1].decode()
        if symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
            return 'RTTI %s' % rtti
        if symbol.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
            if self.walk and symbol in self.definitions:
                self.bind(symbol, value, where)
                self.queue.append((value, symbol))
            return 'vtable RTTI %s offset %#x' % (rtti, at)
        if symbol.startswith('??_8'):
            return 'vbtable (bound by consistency)'
        if symbol in FOLDED:
            assert FOLDED[symbol] == value, (where, symbol, hex(value))
            return 'folded'
        if symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol]))
            return 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
        if symbol in DATA:
            assert DATA[symbol][0] == value and original.data(value, len(DATA[symbol][1])) == DATA[symbol][1], (where, symbol)
            return 'constant %s' % DATA[symbol][1].hex()
        if symbol in CROSS:
            assert CROSS[symbol] == value, (where, symbol, hex(value), hex(CROSS[symbol]))
            return 'own row exact in another main build of this recorder'
        if symbol in UNPROVEN:
            assert UNPROVEN[symbol] == value, (where, symbol, hex(value))
            return 'own function not attempted (bound by the original reference)'
        if norm(names.get(value, '')) == norm(symbol) and symbol not in self.definitions:
            return 'external (evidence name)'
        if (symbol.startswith('__real@') or symbol.startswith('__xmm@')) and symbol in self.definitions:
            # floating-point constants: the original operand must hold the same bytes
            pos, at = self.definitions[symbol]
            table = self.sections[at]
            size = 8 if symbol.startswith('__real@') and len(symbol) == 7 + 16 else 4 if symbol.startswith('__real@') else 16
            data = self.raw[table[4] + pos:table[4] + pos + size]
            assert original.data(value, size) == data, (where, symbol, hex(value), original.data(value, size).hex())
            return 'constant %s' % data.hex()
        if symbol in self.definitions and symbol not in self.bodies:
            # own static data (descriptor objects, local statics, guard flags): bound by consistency across rows
            return 'own static'
        return None

    def vtable(self, symbol, value):
        start, sec = self.definitions[symbol]
        table = self.sections[sec]
        end = min([x for x in self.starts[sec + 1] if x > start] + [table[3]])
        slots = {}
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            if start <= offset < end:
                slots[(offset - start) // 4] = self.symbols[index][0]
        assert slots and max(slots) == len(slots) - 1, (symbol, sorted(slots))
        rtti, at = original.vtable_class(value)
        own = own_vtable(rtti)
        after = d(value + 4 * len(slots))
        longer = TEXT_LO <= after < TEXT_HI
        info = {'address': hex(value), 'rtti': rtti, 'offset': hex(at), 'own_class': own}
        self.vtables[symbol] = info
        if longer:
            # The dword after the compiled length is a code address in the original. For the classes' own
            # most-derived vtables (offset 0) that would be a missing virtual: asserted. Elsewhere it can also be
            # unrelated .rdata that follows the vtable (FactoryProduct<Tool> 00841904 is followed by a boost::function
            # manager table 005fdec0 / 00618cd0): recorded only.
            assert not (own and at == 0 and any(rtti == '.?AV%s@RBX@@' % c for c in OWN_CLASSES.split('|'))), \
                (symbol, hex(value), 'original vtable longer', hex(after))
            info['next_dword_is_code'] = 'slot %d position holds %s in the original' % (len(slots), hex(after))
            if not own:
                info['not_walked'] = 'shared template vtable; length not proven'
                return
        checked = {}
        for slot, sym in sorted(slots.items()):
            orig = d(value + 4 * slot)
            where = '%s slot %d' % (symbol, slot)
            if sym in self.bodies or sym.startswith('??_7') or sym.startswith('??_R'):
                how = self.classify(sym, orig, where)
                if how is None:
                    UNBOUND.append('%s: vtable %s slot %d %s -> %s' % (self.name, symbol, slot, sym, hex(orig)))
                    continue
                self.bind(sym, orig, where)
            else:
                # Inherited external virtual: verified after all builds (evidence name, EXTERNAL map, or the same
                # address at every other place the symbol occurs).
                SLOTS.append((self.name, own, sym, orig, where))
                how = 'external slot'
            checked[slot] = '%s = %s (%s)' % (sym, hex(orig), how)
        info['slots'] = checked

    def row(self, address, name):
        if address in self.rows and self.rows[address]['symbol'] == name:
            return
        body, refs = self.bodies[name]
        split = next(((parent, start) for parent, pieces in EXTENT_SPLITS.items() for start, size in pieces
                      if start == address and size == len(body)), None)
        if split:
            # One evidence extent covers several compiled functions (bounds): compare the piece of the parent extent.
            parent, start = split
            whole, whole_refs, _ = match.target('2008-06', '%08x' % parent)
            off = start - parent
            target = whole[off:off + len(body)]
            target_refs = [x - off for x in whole_refs if off <= x < off + len(body)]
        else:
            try:
                target, target_refs, _ = match.target('2008-06', '%08x' % address)
            except SystemExit as error:
                # the original evidence has no function start here (extent covers it): recorded, never exact
                key = address if address not in self.rows else (address, name)
                self.rows[key] = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': None,
                                  'exact': False, 'counted_class': bool(OWN.search(name)), 'bounds': str(error)}
                return
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact, 'counted_class': bool(OWN.search(name))}
        if split:
            entry['extent_split'] = 'piece %s+%#x of the evidence extent %s (bounds; not counted)' % (
                '%08x' % split[0], split[1] - split[0], '%08x' % split[0])
        key = address if address not in self.rows else (address, name)
        self.rows[key] = entry
        if not exact:
            return
        start, section = self.definitions[name]
        table = self.sections[section]
        code = self.raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = self.symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            how = self.classify(symbol, value, name)
            if how is None:
                UNBOUND.append('%s: %s in %s -> %s' % (self.name, symbol, name, hex(value)))
                continue
            self.bind(symbol, value, name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})

    def run(self, seeds):
        for address, name in seeds:
            assert name in self.bodies, (self.name, name)
            self.bind(name, address, 'seed')
            self.queue.append((address, name))
        while self.queue:
            value, symbol = self.queue.pop(0)
            if symbol.startswith('??_7'):
                if symbol not in self.vtables:
                    self.vtable(symbol, value)
            else:
                self.row(value, symbol)
        return self



CROSS = {}   # symbol -> address of an exact row of an earlier main build
builds = {}
for name in SOURCES:
    builds[name] = Build(name, objs[name], True).run(SEEDS[name])
    for row in builds[name].rows.values():
        if row['exact']:
            CROSS.setdefault(row['symbol'], int(row['address'], 16))
pending_builds = [Build(name + '-pending', objs[name + '-pending'], False).run(PENDING_SEEDS[name])
                  for name in PENDING_UNITS]
main = list(builds.values())
# External vtable slots: one address per symbol across every vtable and relocation binding of the main builds.
occurrences = {}
for build in main:
    for symbol, (value, origin) in build.binding.items():
        occurrences.setdefault(symbol, set()).add((value, build.name + ': ' + origin))
for build, own, symbol, value, where in SLOTS:
    occurrences.setdefault(symbol, set()).add((value, build + ': ' + where))
SLOT_CHECK = {}
for build, own, symbol, value, where in SLOTS:
    values = {v for v, _ in occurrences[symbol]}
    if len(values) > 1:
        assert not own, ('inconsistent external slot in an own vtable', symbol, sorted(occurrences[symbol]))
        HEADER_GAPS.append('%s: %s -> %s, but %s elsewhere (the shared header lacks an override)'
                           % (where, symbol, hex(value), sorted(hex(v) for v in values - {value})))
        continue
    if symbol in EXTERNAL:
        assert EXTERNAL[symbol] == value, (symbol, hex(value))
        how = 'external'
    elif symbol in UNPROVEN:
        assert UNPROVEN[symbol] == value, (symbol, hex(value))
        how = 'own function not compiled here (bound by the original slot)'
    elif norm(names.get(value, '')) == norm(symbol):
        how = 'evidence name'
    elif original.imported(value) is not None and original.imported(value)[1] == nb.plain(symbol):
        how = 'import %s!%s' % original.imported(value)
    elif len({w for _, w in occurrences[symbol]}) > 1:
        how = 'same address at %d places' % len({w for _, w in occurrences[symbol]})
    else:
        UNBOUND.append('%s: unverified external slot %s -> %s (%s)' % (build, symbol, hex(value), where))
        continue
    SLOT_CHECK['%s | %s' % (where, symbol)] = '%s (%s)' % (hex(value), how)
assert not UNBOUND, '\n'.join(sorted(set(UNBOUND)))

# The same symbol compiled in two main units (shared inline / template instances) must bind to the same address.
for a in main:
    for b in main:
        for symbol, (value, _) in a.binding.items():
            if symbol in b.binding:
                assert b.binding[symbol][0] == value, (symbol, hex(value), hex(b.binding[symbol][0]))

pending_rows = []
main_rows = [r for build in main for r in build.rows.values()]
for build in pending_builds:  # noqa: E501
    for row in build.rows.values():
        if any(r['address'] == row['address'] and r['symbol'] == row['symbol'] and r['exact'] for r in main_rows):
            continue   # also exact in a main build: counted there
        row['exact_pending_build_only'] = row['exact']
        row['exact'] = False
        pending_rows.append(dict(row, build=build.name))




# The widget unit ranges this receipt covers: the Button / ChatWidget / MenuItem unit 0064e840..0064f6b0, EquationDisplay
# getLabel 00656940 and the ArrowPanel / ArrowButton unit 00656bf0..00657c00 (record_native_widget.py UNIT_RANGES). The
# template instances 00656c90..00657190 sit inside the ArrowPanel unit and only its bodies call them (00656e00 from
# 00656f60; 00656f60 / 00657000 / 00657190 from init 00657240). A row is counted only when main-build exact, inside a
# range, and not in the top-level exact_function_rows of any other receipt (the shared_count<T*> constructors 00656c90 /
# 00656d20 are counted by creatable-shared-count-working.json; widget-family / hud-family count the other unit rows).
UNIT_RANGES = ((0x64e840, 0x64f6b0), (0x656940, 0x656a50), (0x656bf0, 0x657c00))
counted_elsewhere, receipts_checked = {}, 0
for path in sorted(glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json'))):
    if Path(path).resolve() == RECEIPT.resolve():
        continue
    try:
        other = json.loads(Path(path).read_text())
    except (ValueError, UnicodeDecodeError):
        continue
    if isinstance(other, dict) and isinstance(other.get('exact_function_rows'), list):
        receipts_checked += 1
        for a in other['exact_function_rows']:
            if isinstance(a, str):
                counted_elsewhere.setdefault(a.lower().replace('0x', '').zfill(8), Path(path).name)


def counts(address):
    a = int(address, 16)
    rows = [r for r in main_rows if r['address'] == address]
    if not rows or not all(r['exact'] for r in rows) or any(r.get('extent_split') for r in rows):
        return False
    return any(lo <= a < hi for lo, hi in UNIT_RANGES) and address not in counted_elsewhere


counted = sorted({r['address'] for r in main_rows if counts(r['address'])})
support = sorted({r['address'] for r in main_rows if r['exact'] and not r.get('extent_split')} - set(counted))
inexact = list({(r['address'], r['symbol']): r for r in main_rows if not r['exact']}.values())
sha = nb.sha
paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX::ArrowPanel, ArrowButton, ChatButton, ChatWidget, MenuItem, EquationDisplay (gui widget units, pass 2)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': all_flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in objs.values()},
    'exact_function_rows': counted,
    'exact_support_rows': support,
    'counted_elsewhere_excluded': {k: counted_elsewhere[k] for k in sorted({r['address'] for r in main_rows})
                                   if k in counted_elsewhere},
    'receipts_checked': receipts_checked,
    'exact_extent_split_rows': sorted({r['address'] for r in main_rows if r['exact'] and r.get('extent_split')}),
    'rows': {b.name: list(b.rows.values()) for b in main},
    'not_exact_rows': [{'address': r['address'], 'symbol': r['symbol'], 'size': r['size'],
                        'target_size': r['target_size'], 'bounds': r.get('bounds'),
                        'exact_in_pending_build': any(p['address'] == r['address'] and p['symbol'] == r['symbol']
                                                      and p.get('exact_pending_build_only') for p in pending_rows),
                        'evidence_name': names.get(int(r['address'], 16)) or None} for r in inexact],
    'pending_rows': pending_rows,
    'vtables': {k: v for b in main for k, v in b.vtables.items()},
    'external_slots': SLOT_CHECK,
    'shared_header_gaps': HEADER_GAPS,
    'pending_note': 'pending_rows are exact only against out/native-layouts/gui-widgets2008-pending (gui/ArrowPanel.h '
                    'with ArrowPanel::init; util/Object.h with a five-parameter Creatable::create; util/Rect.h with '
                    'pointInRect(Vector2int16) out of line; v8tree/Instance.h with the inline getRootAncestor family; '
                    'gui/Widget.h with VerbWidget::getVerb inline). Not counted; their vtables are not walked.',
    'not_attempted': NOT_ATTEMPTED,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native gui widgets 2008: %d distinct unit addresses exact (+%d support rows), %d compiled rows not exact, '
      '%d pending-build-only rows not counted; %d vtables walked'
      % (len(counted), len(support), len(inexact), sum(1 for r in pending_rows if r.get('exact_pending_build_only')),
         len(receipt['vtables'])))

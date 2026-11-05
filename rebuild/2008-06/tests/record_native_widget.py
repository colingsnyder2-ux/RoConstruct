"""Verify the inactive native RBX gui widget family recovery (2008-06): Widget, VerbWidget, KeyButton, ImageWidget,
ImageButton, ImageKeyButton, MenuItem, ChatWidget, UnifiedImageWidget, ChatButton, HealthHud, EquationDisplay,
ArrowPanel, ArrowButton.

Builds (document-swap flags, VS2008 RTM 21022, native headers only):
  * tests/NativeWidgetLayout.cpp      layout probes (mov eax, imm32; ret) against allocation sizes and constructor stores;
  * native-classes/Widget.cpp         the original gui/Widget.cpp unit 00641ff0..006426f0;
  * native-classes/WidgetButtons.cpp  the Button unit 0064ef90..0064f6a0 (KeyButton, ImageWidget, ImageButton,
                                      ImageKeyButton);
  * native-classes/WidgetChat.cpp     ChatWidget 0064e8c0.., UnifiedImageWidget / ChatButton constructors 00601c50 / 00601d00;
  * native-classes/WidgetMenuItem.cpp MenuItem 0064ebf0..0064ed90;
  * native-classes/HealthHud.cpp      HealthHud 00656490..00656640;
  * native-classes/EquationDisplay.cpp EquationDisplay 00656a50..00656bf0;
  * native-classes/ArrowPanel.cpp     ArrowPanel::getSize 00656bf0, ArrowButton 006570a0.
Pending builds (NATIVE_WIDGET_PENDING; rows recorded exact=false, pending-build-only, never counted, vtables never
walked) against out/native-layouts/widget-pending, generated copies of three headers owned by others, each with one
declaration changed:
  * util/Rect.h (donor): `bool pointInRect(G3D::Vector2int16 point);` out of line (00573130, called from 00642007);
  * v8tree/Verb.h (native): `const Name& getName() const { return name; }` inline (read at 0064f3c4);
  * gui/Gui.h (native): `MenuState getMenuState() const { return menuState; }` inline (read at 0064e851, 0064e8a0).

Rows are found by closure from seeds (constructors named by the allocating call sites, plus vtable-slot-named leaves):
every REL32/DIR32 relocation of an exact row is bound to the address the original instruction uses. A target defined
in the compiled object becomes a row at that address; a vtable target is checked by original RTTI (class name and
subobject offset) and walked slot by slot, each slot symbol bound to the original slot value (main builds only). Every
other target is verified: imports by DLL export name, string literals by bytes, float constants (__real@) by bytes,
type descriptors by RTTI name, external functions by the evidence name or the EXTERNAL map (call sites read in the
original disassembly), own functions not compiled here by the UNPROVEN map (the original reference). A symbol binds
to one address. Writes work/2008-06/shared-layouts/widget-family-working.json.
"""
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
SOURCES = {name: R / 'native-classes' / (name + '.cpp') for name in ('Widget', 'WidgetButtons', 'WidgetChat', 'WidgetMenuItem',
                                                                    'HealthHud', 'EquationDisplay', 'ArrowPanel')}
HEADERS = [R / 'native-headers/gui' / n for n in ('Widget.h', 'WidgetButtons.h', 'WidgetChat.h', 'WidgetMenuItem.h',
                                                  'HealthHud.h', 'EquationDisplay.h', 'ArrowPanel.h')]
PENDING_UNITS = ('Widget', 'WidgetButtons', 'WidgetChat')
LAYOUT = R / 'tests/NativeWidgetLayout.cpp'

# ---- pending overlay ------------------------------------------------------------------------------------------
pending = OUT / 'widget-pending'
for sub in ('util', 'v8tree', 'gui'):
    (pending / sub).mkdir(parents=True, exist_ok=True)


def overlay(source, relative, old, new):
    text = Path(source).read_text()
    assert text.count(old) == 1, (relative, old)
    (pending / relative).write_text(text.replace(old, new))


overlay(ROOT / 'tools/rbxgs/Client/App/include/util/Rect.h', 'util/Rect.h',
        '\t\tbool pointInRect(G3D::Vector2int16 point)\n\t\t{\n\t\t\treturn pointInRect(point.x, point.y);\n\t\t}\n',
        '\t\tbool pointInRect(G3D::Vector2int16 point);\n')
overlay(R / 'native-headers/v8tree/Verb.h', 'v8tree/Verb.h',
        '    const Name& getName() const;\n', '    const Name& getName() const { return name; }\n')
overlay(R / 'native-headers/gui/Gui.h', 'gui/Gui.h',
        '\t\tMenuState getMenuState() const;\n', '\t\tMenuState getMenuState() const\n\t\t{\n\t\t\treturn menuState;\n\t\t}\n')


def build(name, src, extra=(), post=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + list(post) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


layout_obj, layout_flags = build('NativeWidgetLayout', LAYOUT)
objs, all_flags = {}, {'layout': layout_flags}
for name, src in SOURCES.items():
    objs[name], all_flags[name] = build('NativeWidget_' + name, src)
    if name in PENDING_UNITS:
        objs[name + '-pending'], all_flags[name + '-pending'] = build('NativeWidget_' + name + 'Pending', src,
                                                                      ['/I' + str(pending), '/DNATIVE_WIDGET_PENDING'])

# ---- layout ---------------------------------------------------------------------------------------------------
LAYOUT_VALUES = {
    'nativeWidgetState': 0x144, 'nativeWidgetSize': 0x148, 'nativeVerbWidgetVerb': 0x148, 'nativeVerbWidgetSize': 0x14c,
    'nativeKeyButtonKeyCode': 0x148, 'nativeKeyButtonKeyIsDown': 0x14c, 'nativeKeyButtonSize': 0x150,
    'nativeImageWidgetDraw': 0x148, 'nativeImageWidgetSize': 0x180, 'nativeImageButtonDraw': 0x14c,
    'nativeImageButtonSize': 0x184, 'nativeImageKeyButtonDraw': 0x150, 'nativeImageKeyButtonSize': 0x188,
    'nativeChatWidgetCode': 0x148, 'nativeChatWidgetSize': 0x164, 'nativeUnifiedImageWidgetDraw': 0x148,
    'nativeUnifiedImageWidgetSize': 0x180, 'nativeChatButtonSize': 0x180, 'nativeMenuItemAccelerator': 0x14c,
    'nativeMenuItemSize': 0x168, 'nativeHealthHudVisit': 0x144, 'nativeHealthHudSize': 0x14c,
    'nativeEquationDisplayEquation': 0x188, 'nativeEquationDisplaySize': 0x1a4, 'nativeArrowPanelDataModel': 0x15c,
    'nativeArrowPanelController': 0x160, 'nativeArrowButtonDataModel': 0x188, 'nativeArrowButtonController': 0x18c,
    'nativeArrowButtonSize': 0x190,
}
raw = layout_obj.read_bytes()
for prefix, value in LAYOUT_VALUES.items():
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + prefix + '@@'))
    assert body == b'\xb8' + struct.pack('<I', value) + b'\xc3', (prefix, body.hex())

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
    """Target of the direct call instruction at `site` in the original."""
    assert original.data(site, 1) == b'\xe8', hex(site)
    return (site + 5 + struct.unpack('<i', original.data(site + 1, 4))[0]) & 0xffffffff


# Allocation sizes: each call site pushes the size, calls malloc (operator new), then the constructor.
for factory, size, site, ctor in ((0x656f60, 0x180, 0x656fb4, 0x64f1c0),     # ImageWidget
                                  (0x601f00, 0x184, 0x601f72, 0x64f340),     # ImageButton
                                  (0x602280, 0x180, 0x6022ed, 0x601d00),     # ChatButton
                                  (0x602120, 0x164, 0x602186, 0x64e8c0),     # ChatWidget
                                  (0x601e30, 0x168, 0x601e9d, 0x64ebf0),     # MenuItem
                                  (0x6023d0, 0x14c, 0x602414, 0x656490),     # HealthHud
                                  (0x602550, 0x1a4, 0x6025d8, 0x656a50),     # EquationDisplay
                                  (0x657190, 0x190, 0x6571f3, 0x6570a0)):    # ArrowButton
    body, _, _ = match.target('2008-06', '%08x' % factory)
    at = body.index(b'\x68' + struct.pack('<I', size))
    assert at < site - factory and call_target(site) == ctor, (hex(factory), hex(size), hex(ctor))
# Base-constructor chains read from the constructors (call site -> callee).
for site, callee in ((0x6422b3, 0x5739d0), (0x642373, 0x6422b0), (0x64f12d, 0x6422b0), (0x64f1de, 0x6422b0),
                     (0x64f363, 0x642370), (0x64f528, 0x64f110), (0x64ec12, 0x642370), (0x64e8e6, 0x600540),
                     (0x601c6d, 0x600540), (0x601d0f, 0x601c50), (0x656493, 0x5739d0), (0x656a73, 0x5744a0),
                     (0x6570b4, 0x64f500)):
    assert call_target(site) == callee, (hex(site), hex(callee))


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


PARENT = {'Widget': 'GuiItem', 'VerbWidget': 'Widget', 'KeyButton': 'Widget', 'ImageWidget': 'Widget',
          'ImageButton': 'VerbWidget', 'ImageKeyButton': 'KeyButton', 'MenuItem': 'VerbWidget',
          'ChatWidget': 'UnifiedWidget', 'UnifiedImageWidget': 'UnifiedWidget', 'ChatButton': 'UnifiedImageWidget',
          'HealthHud': 'GuiItem', 'EquationDisplay': 'TextDisplay', 'ArrowPanel': 'TopMenuBar',
          'ArrowButton': 'ImageKeyButton'}
VTABLE = {'Widget': 0x84a6a4, 'VerbWidget': 0x84a7ac, 'KeyButton': 0x84b70c, 'ImageWidget': 0x84b814,
          'ImageButton': 0x84b91c, 'ImageKeyButton': 0x84ba24, 'MenuItem': 0x84b5f4, 'ChatWidget': 0x84b4e4,
          'UnifiedImageWidget': 0x84222c, 'ChatButton': 0x84232c, 'HealthHud': 0x84bdcc, 'EquationDisplay': 0x84becc,
          'ArrowPanel': 0x84c164, 'ArrowButton': 0x84bffc}
assert original.vtable_class(0x82fce4) == ('.?AVTextDisplay@RBX@@', 0) and d(0x82fce4 + 80) == 0x574570 \
    and d(0x82fce4 + 96) == 0x573670
assert original.vtable_class(0x82fbe4) == ('.?AVUnifiedWidget@RBX@@', 0) and d(0x82fbe4 + 112) == 0x574170
for cls, vt in VTABLE.items():
    assert original.vtable_class(vt) == ('.?AV%s@RBX@@' % cls, 0), (hex(vt), cls)
    b = bases(vt)
    assert b['.?AV%s@RBX@@' % PARENT[cls]] == 0 and b['.?AVGuiTarget@RBX@@'] == 0x130, (cls, b)
    # the direct parent is the next class in the hierarchy array
    hierarchy = d(d(vt - 4) + 16)
    assert original.string(d(d(d(hierarchy + 12) + 4)) + 8) == '.?AV%s@RBX@@' % PARENT[cls], cls


# ---- verification maps ----------------------------------------------------------------------------------------
# Externals whose evidence name differs from the compiled symbol (or has none): the address the original call site
# uses, with the site it was read from.
EXTERNAL = {
    '??0GuiItem@RBX@@QAE@XZ': 0x5739d0,                                                      # Widget() 006422b3
    '??1GuiItem@RBX@@UAE@XZ': 0x411540,                                                      # ~VerbWidget 006424f8
    '??0UnifiedWidget@RBX@@QAE@XZ': 0x600540,                                                # ChatWidget() 0064e8e6
    '?getMyRect@GuiItem@RBX@@IBE?AVRect@2@XZ': 0x573310,                                     # render2d 0064f03d
    '?render2d@GuiDrawImage@RBX@@QAEXPAVAdorn@2@_NAAVRect@2@W4WidgetState@Widget@2@@Z': 0x642de0,  # 0064f05b
    '??0GuiDrawImage@RBX@@QAE@PAVAdorn@1@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x6010e0,  # 0064f253
    '??1GuiDrawImage@RBX@@QAE@XZ': 0x5cf360,                                                 # ~ImageWidget 0064f31b
    '?getImageSize@GuiDrawImage@RBX@@QBE?AVVector2@G3D@@XZ': 0x642690,                       # getSize 0064f28c
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,  # 0064f1a7
    '?setMenuState@UnifiedWidget@RBX@@QAEXW4MenuState@12@@Z': 0x5735c0,                      # 0064e8ab
    '?label2d@GuiItem@RBX@@IBEXPAVAdorn@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABVColor4@G3D@@2W4XAlign@12@@Z': 0x573360,  # 0064265d
    '?gray@Color3@G3D@@SAABV12@XZ': 0x514a20,                                                # render2d 006425a8
    '?yellow@Color3@G3D@@SAABV12@XZ': 0x514980,                                              # render2d 0064256c
    '?white@Color3@G3D@@SAABV12@XZ': 0x514a60,                                               # Widget::getFontColor 005cf500
    '?disabledFill@GuiItem@RBX@@SAABVColor4@G3D@@XZ': 0x573190,                              # render2d 00642615
    '?toRect2D@Rect@RBX@@QBE?AVRect2D@G3D@@XZ': 0x4f35d0,                                    # render2d 006425dd (xyxy)
    '?xyxy@Rect2D@G3D@@SA?AV12@ABVVector2@2@0@Z': 0x4f35d0,                                  # render2d 006425dd
    '?getMyRect2D@GuiItem@RBX@@IBE?AVRect2D@G3D@@XZ': 0x573960,                              # render2d 00642599
    '?pointInRect@Rect@RBX@@QAE_NVVector2int16@G3D@@@Z': 0x573130,                           # processMouse 0064200e
    '?zero@Vector2@G3D@@SAABV12@XZ': 0x509ba0,                                               # GuiItem::getChildPosition 00411810
    '??1Instance@RBX@@UAE@XZ': 0x55a540,                                                     # ~GuiItem 00411540
    '?render2dMe@UnifiedWidget@RBX@@MAEXPAVAdorn@2@@Z': 0x574170,                            # UnifiedWidget vtable 0082fbe4 slot 28
    '??0TextDisplay@RBX@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z': 0x5744a0,  # 00656a73
    '??1TextDisplay@RBX@@UAE@XZ': 0x574630,                                                  # ~EquationDisplay 00656bbb
    '?getSize@TopMenuBar@RBX@@UBE?AVVector2@G3D@@XZ': 0x573e30,                              # ArrowPanel::getSize 00656c06
    '?getFontSize@TextDisplay@RBX@@MBEHXZ': 0x574570,                                        # TextDisplay vtable 0082fce4 slot 20
    '?render2d@TextDisplay@RBX@@UAEXPAVAdorn@2@@Z': 0x573670,                                # TextDisplay vtable 0082fce4 slot 24
    '??_E?$SignalDesc': None,
}
EXTERNAL = {k: v for k, v in EXTERNAL.items() if v is not None}
# Own functions that are not compiled in the main builds: bound by the original reference that uses them.
UNPROVEN = {
    '?processMouse@Widget@RBX@@AAE?AVGuiResponse@2@ABVGuiEvent@2@@Z': 0x641ff0,                 # call at 00642241 (pending)
    '?onMenuStateChanged@ChatWidget@RBX@@EAEXXZ': 0x64e8a0,                                      # vtable 0084b4e4 slot 25 (pending)
    '?render2dMe@UnifiedImageWidget@RBX@@UAEXPAVAdorn@2@@Z': 0x64e840,                           # vtable 0084222c slot 28 (pending)
    '?process@ChatWidget@RBX@@EAE?AVGuiResponse@2@ABVGuiEvent@2@@Z': 0x64ead0,                   # vtable 0084b45c slot 0
    '?isVisible@ChatButton@RBX@@EBE_NXZ': 0x64ea90,                                              # vtable 0084232c slot 21
    '?render2d@MenuItem@RBX@@UAEXPAVAdorn@2@@Z': 0x64edb0,                                       # vtable 0084b5f4 slot 24
    '?render2d@HealthHud@RBX@@EAEXPAVAdorn@2@@Z': 0x656690,                                      # vtable 0084bdcc slot 24
    '?getLabel@EquationDisplay@RBX@@MBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x656940,  # 0084becc slot 25
    '?isEnabled@ArrowButton@RBX@@UAE_NXZ': 0x657be0,                                             # vtable 0084bffc slot 30
}
CLASS_NAMES = {'sInstance': b'Instance'}
# Evidence extents that cover more than one compiled function: parent -> [(start, size)]. ~ChatWidget (80 bytes) is
# followed directly by its scalar deleting destructor (31 bytes; the ChatWidget ??_E thunks 0064e9a0.. jump to
# 0064ea70), but the evidence has one 111-byte function at 0064ea20.
EXTENT_SPLITS = {0x64ea20: [(0x64ea20, 80), (0x64ea70, 31)],
                 0x656b80: [(0x656b80, 80), (0x656bd0, 31)]}    # ~EquationDisplay + its deleting destructor
DATA = {}
FOLDED = {}


# Seeds: (address, compiled symbol). Constructors are named by the allocating call sites and constructor chains above;
# leaves that no compiled row references (ImageButton's slots: its vtable is emitted only with the pending constructor)
# are named by the original vtable slot that holds them (checked below).
SEEDS = {
    'Widget': [(0x6422b0, '??0Widget@RBX@@QAE@XZ'), (0x642370, '??0VerbWidget@RBX@@QAE@PAVVerb@1@@Z')],
    'WidgetButtons': [
        (0x64f110, '??0KeyButton@RBX@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4SDLKey@@@Z'),
        (0x64f1c0, '??0ImageWidget@RBX@@QAE@PAVAdorn@1@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
        (0x64f500, '??0ImageKeyButton@RBX@@QAE@PAVAdorn@1@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4SDLKey@@@Z'),
        (0x64f0c0, '?render2d@ImageButton@RBX@@UAEXPAVAdorn@2@@Z'),
        (0x64f410, '?getSize@ImageButton@RBX@@UBE?AVVector2@G3D@@XZ'),
    ],
    'WidgetChat': [
        (0x64e8c0, '??0ChatWidget@RBX@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V23@@Z'),
        (0x601d00, '??0ChatButton@RBX@@QAE@PAVAdorn@1@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
    ],
    'WidgetMenuItem': [(0x64ebf0, '??0MenuItem@RBX@@QAE@PAVVerb@1@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z')],
    'HealthHud': [(0x656490, '??0HealthHud@RBX@@QAE@XZ')],
    'EquationDisplay': [(0x656a50, '??0EquationDisplay@RBX@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z')],
    'ArrowPanel': [(0x6570a0, '??0ArrowButton@RBX@@QAE@PAVAdorn@1@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4SDLKey@@W4ControllerType@Controller@1@PAVDataModel@1@@Z'),
                   (0x656bf0, '?getSize@ArrowPanel@RBX@@UBE?AVVector2@G3D@@XZ')],
}
PENDING_SEEDS = {
    'Widget': [(0x641ff0, '?processMouse@Widget@RBX@@AAE?AVGuiResponse@2@ABVGuiEvent@2@@Z')],
    'WidgetButtons': [(0x64f340, '??0ImageButton@RBX@@QAE@PAVAdorn@1@PAVVerb@1@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z'),
                      (0x64f4b0, '??1ImageButton@RBX@@UAE@XZ'), (0x64f690, '??_GImageButton@RBX@@UAEPAXI@Z')],
    'WidgetChat': [(0x64e840, '?render2dMe@UnifiedImageWidget@RBX@@UAEXPAVAdorn@2@@Z'),
                   (0x64e8a0, '?onMenuStateChanged@ChatWidget@RBX@@EAEXXZ')],
}
# Vtable-slot evidence for seeds that are not constructors.
assert d(0x84b91c + 4 * 24) == 0x64f0c0 and d(0x84b91c + 4 * 23) == 0x64f410
assert d(0x84222c + 4 * 28) == 0x64e840 and d(0x84b4e4 + 4 * 25) == 0x64e8a0
assert d(0x84c164 + 4 * 23) == 0x656bf0     # ArrowPanel::getSize (its constructor is not attempted)
# ImageButton's deleting destructor: the AbstractFactoryProduct vtable 0084b90c slot 0 is the thunk 0064f490
# (sub ecx, 0x10; jmp 0064f690).
assert d(0x84b90c) == 0x64f490 and original.data(0x64f490, 4) == b'\x83\xe9\x10\xe9'
assert (0x64f498 + struct.unpack('<i', original.data(0x64f494, 4))[0]) & 0xffffffff == 0x64f690
OWN_CLASSES = ('Widget|VerbWidget|KeyButton|ImageWidget|ImageButton|ImageKeyButton|MenuItem|ChatWidget|UnifiedImageWidget'
               '|ChatButton|HealthHud|EquationDisplay|ArrowPanel|ArrowButton')
OWN = re.compile(r'(?:^|[^A-Za-z]|\?\?_[EG])(%s)@RBX@@' % OWN_CLASSES)
NOT_ATTEMPTED = {
    '0064ead0': 'ChatWidget::process (local Player lookup 00491d50, chat send 0049cb30)',
    '0064ea90': 'ChatButton::isVisible (local Player lookup 00491d50, 00495e60)',
    '0064edb0': 'MenuItem::render2d (473 bytes; accelerator label, highlight rect)',
    '00642210': 'Widget::process: same instructions, the not-used result stores target (+4) before response (+0) in '
                'the original; every source variant tried stores response first',
    '00656690': 'HealthHud::render2d (678 bytes; Visit lookup 00656640, Humanoid health bar)',
    '00656940': 'EquationDisplay::getLabel (271 bytes)',
    '00656db0/00657240/00657780': 'ArrowPanel::isVisible / init / constructor (DataModel internals)',
    '00657be0': 'ArrowButton::isEnabled (DataModel 004530f0)',
    '0064fb60..00656430': 'ScoreHud / ChatOutput (not attempted: Players / leaderboard / chat history)',
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
        try:
            target, target_refs, _ = match.target('2008-06', '%08x' % address)
            if split and len(target) != len(body):
                # Older evidence may hold only the combined destructor extent; use its proven piece bounds.
                parent, start = split
                whole, whole_refs, _ = match.target('2008-06', '%08x' % parent)
                off = start - parent
                target = whole[off:off + len(body)]
                target_refs = [x - off for x in whole_refs if off <= x < off + len(body)]
            else:
                split = None  # bounds.json now provides the destructor extent directly
        except SystemExit as error:
            if split:
                parent, start = split
                whole, whole_refs, _ = match.target('2008-06', '%08x' % parent)
                off = start - parent
                target = whole[off:off + len(body)]
                target_refs = [x - off for x in whole_refs if off <= x < off + len(body)]
            else:
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



CROSS = {}   # symbol -> address of an exact row of an earlier main build (VerbWidget ctor/dtor used by MenuItem, ...)
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
for cls, vt in VTABLE.items():
    assert any(info['address'] == hex(vt) for build in main for info in build.vtables.values()) or \
        cls in ('ImageButton', 'ArrowPanel'), cls

pending_rows = []
main_rows = [r for build in main for r in build.rows.values()]
for build in pending_builds:  # noqa: E501
    for row in build.rows.values():
        if any(r['address'] == row['address'] and r['symbol'] == row['symbol'] and r['exact'] for r in main_rows):
            continue   # also exact in a main build: counted there
        row['exact_pending_build_only'] = row['exact']
        row['exact'] = False
        pending_rows.append(dict(row, build=build.name))

# Unit ranges of the original Widget, Button/MenuItem/ChatWidget units and the UnifiedImageWidget / ChatButton
# constructors. Rows outside them are exact support rows, not counted: the Widget inline virtuals first emitted in the
# Hopper unit (005cf4e0.. ; 005cf4e0 is also UnifiedWidget::onLoseFocus by ICF), ICF-shared generic bodies (`return
# true` 00565950, empty 0070bdf0), GuiItem rows, the shared deleting destructor 00574150 and its thunks.
UNIT_RANGES = ((0x641ff0, 0x6426f0), (0x64e840, 0x64f6b0), (0x601c50, 0x601db0), (0x656490, 0x656640),
               (0x656a50, 0x657c00))


def counts(address):
    a = int(address, 16)
    rows = [r for r in main_rows if r['address'] == address]
    if not rows or not all(r['exact'] for r in rows) or any(r.get('extent_split') for r in rows):
        return False
    syms = [r['symbol'] for r in rows]
    if any(lo <= a < hi for lo, hi in UNIT_RANGES):
        return any(OWN.search(x) for x in syms)
    return False


counted = sorted({r['address'] for r in main_rows if counts(r['address'])})
support = sorted({r['address'] for r in main_rows if r['exact'] and not r.get('extent_split')} - set(counted))
inexact = list({(r['address'], r['symbol']): r for r in main_rows if not r['exact']}.values())
sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX::Widget, VerbWidget, KeyButton, ImageWidget, ImageButton, ImageKeyButton, MenuItem, ChatWidget, '
             'UnifiedImageWidget, ChatButton',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': all_flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in [layout_obj] + list(objs.values())},
    'layout': {k: hex(v) for k, v in LAYOUT_VALUES.items()},
    'exact_function_rows': counted,
    'exact_support_rows': support,
    'exact_extent_split_rows': sorted({r['address'] for r in main_rows if r['exact'] and r.get('extent_split')}),
    'rows': {b.name: list(b.rows.values()) for b in main},
    'not_exact_rows': [{'address': r['address'], 'symbol': r['symbol'], 'size': r['size'],
                        'target_size': r['target_size'], 'bounds': r.get('bounds'),
                        'evidence_name': names.get(int(r['address'], 16)) or None} for r in inexact],
    'pending_rows': pending_rows,
    'vtables': {k: v for b in main for k, v in b.vtables.items()},
    'external_slots': SLOT_CHECK,
    'shared_header_gaps': HEADER_GAPS,
    'pending_note': 'pending_rows are exact only against out/native-layouts/widget-pending (util/Rect.h with '
                    'pointInRect(Vector2int16) out of line; v8tree/Verb.h with getName inline; gui/Gui.h with '
                    'UnifiedWidget::getMenuState inline). Not counted; their vtables are not walked.',
    'not_attempted': NOT_ATTEMPTED,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/widget-family-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Widget family: %d distinct class addresses exact (+%d support rows), %d compiled rows not exact, '
      '%d pending-build-only rows not counted; %d vtables walked'
      % (len(counted), len(support), len(inexact), sum(1 for r in pending_rows if r.get('exact_pending_build_only')),
         len(receipt['vtables'])))

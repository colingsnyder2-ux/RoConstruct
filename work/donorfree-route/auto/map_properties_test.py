"""Load a place, run a script, and verify several serialized Part properties."""
import sys
import tempfile
from pathlib import Path
from xml.sax.saxutils import escape
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import scripttest

root = Path(__file__).resolve().parents[1]
exe = sys.argv[1] if len(sys.argv) > 1 else str(root / 'run/RobloxQT.exe')
source = '''local p = workspace.Probe
local pass, fail = 0, {}
local function check(n, v) if v then pass = pass + 1 else table.insert(fail, n) end end
check("size", p.Size == Vector3.new(12, 4, 8))
check("position", p.Position == Vector3.new(43, 20, 24))
check("anchored", p.Anchored == true)
check("collide", p.CanCollide == false)
check("surface_" .. tostring(p.TopSurface) .. "_expected_" .. tostring(Enum.SurfaceType.Studs), p.TopSurface == Enum.SurfaceType.Studs)
check("enum_self", Enum.SurfaceType.Studs == Enum.SurfaceType.Studs)
check("property_self", p.TopSurface == p.TopSurface)
check("transparency", math.abs(p.Transparency - 0.5) < 0.01)
check("color", p.BrickColor == BrickColor.new(21))
local v = Instance.new("StringValue") v.Name = "R1 pass=" .. pass .. " fail=" .. table.concat(fail, ",") v.Parent = workspace'''
xml = '''<roblox version="4"><Item class="Workspace"><Properties><string name="Name">Workspace</string></Properties>
<Item class="Part"><Properties><string name="Name">Probe</string><bool name="Anchored">true</bool><bool name="CanCollide">false</bool><token name="FormFactor">2</token><token name="TopSurface">3</token><float name="Transparency">0.5</float><int name="BrickColor">21</int><Vector3 name="size"><X>12</X><Y>4</Y><Z>8</Z></Vector3><CoordinateFrame name="CFrame"><X>43</X><Y>20</Y><Z>24</Z><R00>1</R00><R01>0</R01><R02>0</R02><R10>0</R10><R11>1</R11><R12>0</R12><R20>0</R20><R21>0</R21><R22>1</R22></CoordinateFrame></Properties></Item>
<Item class="Script"><Properties><string name="Name">PropertyCheck</string><bool name="Disabled">false</bool><string name="Source">%s</string></Properties></Item></Item></roblox>''' % escape(source)
scripttest.ieclean.clean = lambda *args: None
with tempfile.TemporaryDirectory(prefix='roc_map_properties_') as folder:
    place = Path(folder) / 'properties.rbxl'
    place.write_text(xml, encoding='utf-8')
    spawn = scripttest.subprocess.Popen
    def open_place(args, **kwargs):
        return spawn([args[0], str(place)], **kwargs)
    scripttest.subprocess.Popen = open_place
    result = scripttest.run(exe, '', wait=35)
    print(result)
    row = result.get('R1', {})
    sys.exit(0 if row.get('pass') == 9 and not row.get('fail') else 1)

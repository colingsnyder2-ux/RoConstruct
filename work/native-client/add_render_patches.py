"""One-off: overlay patches giving the rbxgs engine the 2007 bodies (OpenRBX) its renderer layer calls.
Run once; it refuses to add a patch whose anchor is missing or already patched."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
P = ROOT / 'rebuild/2008-06/patches/rbxgs-client.json'
SRC = ROOT / 'tools/rbxgs/Client'
d = json.loads(P.read_text())


def current(rel):
    t = (SRC / rel).read_text(errors='replace')
    for old, new in d.get(rel, []):
        if not old.startswith('@'):
            t = t.replace(old, new)
    return t


def add(rel, old, new):
    t = current(rel)
    assert t.count(old) == 1, (rel, 'anchor count', t.count(old))
    d.setdefault(rel, []).append([old, new])
    print('patched', rel)


add('App/include/v8tree/Instance.h',
    '\t\ttemplate<typename Function>\n\t\tvoid visitChildren(Function func) const;\n',
    '\t\t// body: Dec 2007 client (OpenRBX v8tree/Instance.h; ROBLOX 0x00479c30 for the PartChunk instantiation)\n'
    '\t\ttemplate<typename Function>\n\t\tvoid visitChildren(Function func) const\n\t\t{\n'
    '\t\t\tif (children)\n\t\t\t{\n'
    '\t\t\t\tboost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> c = children.read();\n'
    '\t\t\t\tstd::vector<boost::shared_ptr<Instance>>::const_iterator end = c->end();\n'
    '\t\t\t\tfor (std::vector<boost::shared_ptr<Instance>>::const_iterator iter = c->begin(); iter != end; ++iter)\n'
    '\t\t\t\t\tfunc(*iter);\n\t\t\t}\n\t\t}\n')

add('App/include/v8datamodel/Decal.h',
    '\t\tconst G3D::Vector2& getStudsPerTile();\n',
    '\t\tconst G3D::Vector2& getStudsPerTile() { return studsPerTile; } // OpenRBX v8datamodel/Decal.h\n')

add('App/include/v8datamodel/Lighting.h',
    '\t\tbool isSkySuppressed() const;\n',
    '\t\tbool isSkySuppressed() const { return !hasSky; } // OpenRBX v8datamodel/Lighting.h\n')

sky_end = '\t\tskyDn = ContentId::fromAssets("Sky\\\\null_plainsky512_dn.jpg");\n\t}\n}'
add('App/v8datamodel/Sky.cpp', sky_end, sky_end[:-1] + r'''
	// Dec 2007 client (OpenRBX v8datamodel/Sky.cpp; ROBLOX 0x005dd020)
	G3D::ReferenceCountedPointer<G3D::Sky> Sky::getG3DSky(Sky* sky)
	{
		if (sky)
		{
			try
			{
				std::string filenames[6];
				{
					filenames[0] = ContentProvider::singleton().getFile(sky->skyFt);
					G3D::GImage image;
					image.load(filenames[0]);
					filenames[1] = testImage(ContentProvider::singleton().getFile(sky->skyBk), image);
					filenames[2] = testImage(ContentProvider::singleton().getFile(sky->skyUp), image);
					filenames[3] = testImage(ContentProvider::singleton().getFile(sky->skyDn), image);
					filenames[4] = testImage(ContentProvider::singleton().getFile(sky->skyRt), image);
					filenames[5] = testImage(ContentProvider::singleton().getFile(sky->skyLf), image);
				}
				std::string directory = ContentProvider::singleton().assetFolder() + "Sky\\";
				G3D::ReferenceCountedPointer<G3D::Sky> g3dSky = G3D::Sky::fromFile(NULL, directory, filenames, sky->drawCelestialBodies, 1.0);
				if (g3dSky.notNull())
					g3dSky->setNumStars(sky->numStars);
				return g3dSky;
			}
			catch (std::exception& e)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, e);
			}
			catch (G3D::GImage::Error& e)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, e.reason.c_str());
			}
		}
		return G3D::Sky::fromFile(NULL, ContentProvider::singleton().assetFolder() + "Sky\\", "null_plainsky512_*.jpg");
	}
}''')

add('App/v8datamodel/Sky.cpp', '#include "v8datamodel/Sky.h"\n',
    '#include "v8datamodel/Sky.h"\n#include "util/ContentProvider.h"\n#include "util/standardout.h"\n')

P.write_text(json.dumps(d, indent=1))

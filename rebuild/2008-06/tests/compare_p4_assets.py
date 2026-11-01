"""Compare bounded P4 asset regions in original UI and rebuilt backbuffer captures."""
import hashlib
import json
from pathlib import Path

import numpy as np
from PIL import Image


def main():
    root = Path(__file__).resolve().parents[3]
    original = root / 'work/2008-06/original-p4-reference'
    player = root / 'work/2008-06/p4-disk-assets-88e67662d4'
    result = {'scope': 'Texture quadrant orientation, tinted fallback, sphere color; not pixel/UI parity.',
              'original_sha256': '2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764',
              'player_revision': '88e67662d4', 'captures': {}, 'checks': {}}

    def read(path):
        result['captures'][str(path.relative_to(root))] = hashlib.sha256(path.read_bytes()).hexdigest()
        return np.array(Image.open(path).convert('RGB'), dtype=np.int32)

    def quadrants(image, bounds):
        left, top, right, bottom = bounds
        values = [image[int(top+(bottom-top)*y), int(left+(right-left)*x)]
                  for y in (.25, .75) for x in (.25, .75)]
        red, green, blue, yellow = values
        assert red[0] > 2*max(red[1:])
        assert green[1] > 2*max(green[0], green[2])
        assert blue[2] > 2*max(blue[:2])
        assert min(yellow[:2]) > 2*yellow[2]
        return [value.tolist() for value in values]

    for name, native_box, player_box in [('panel', [192,287,357,453], [103,63,218,179]),
                                          ('gallery', [151,329,233,411], [74,92,132,150])]:
        native = read(original / f'original-{name}.jpg')
        rebuilt = read(player / name / 'last.png')
        check = {'original_bounds': native_box, 'rebuilt_bounds': player_box,
                 'original_quadrants_rgb': quadrants(native, native_box),
                 'rebuilt_quadrants_rgb': quadrants(rebuilt, player_box)}
        if name == 'gallery':
            native_red, rebuilt_red = native[370,357], rebuilt[120,219]
            assert all(rgb[0] > 2*max(rgb[1:]) for rgb in (native_red, rebuilt_red))
            check['sphere_center_rgb'] = [native_red.tolist(), rebuilt_red.tolist()]
        result['checks'][name] = check
    native = read(original / 'original-missing-texture.jpg')
    rebuilt = read(player / 'missing-texture/last.png')
    values = [native[370,274], rebuilt[120,160]]
    assert all(rgb[1] > 1.4*max(rgb[0], rgb[2]) for rgb in values)
    result['checks']['missing_texture'] = {'green_fallback_rgb': [rgb.tolist() for rgb in values]}
    # Absence of the panel in original-missing-mesh.jpg is a recorded visual
    # observation; sky background prevents reusing the harness magenta-mask oracle.
    read(original / 'original-missing-mesh.jpg')
    result['checks']['missing_mesh'] = {'original': 'visually absent; capture retained',
                                       'rebuilt': 'zero foreground; separate runtime receipt'}
    result['asset_comparison_pass'] = True
    (original / 'asset-comparison.json').write_text(json.dumps(result, indent=2)+'\n')
    print('P4 original asset-region comparison PASS; audio remains open')


if __name__ == '__main__':
    main()

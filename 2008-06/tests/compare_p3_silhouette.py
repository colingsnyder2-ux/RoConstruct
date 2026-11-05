"""Compare camera-aligned original/player silhouettes, retaining a box control."""
import hashlib
import json
from pathlib import Path
import sys

import cv2
import numpy as np
from PIL import Image


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def normalize(mask):
    yy, xx = np.nonzero(mask)
    bounds = [int(xx.min()), int(yy.min()), int(xx.max()), int(yy.max())]
    crop = mask[yy.min():yy.max()+1, xx.min():xx.max()+1]
    return cv2.resize(crop.astype('uint8'), (512, 512), interpolation=cv2.INTER_NEAREST).astype(bool), bounds


def main():
    reference, player, fixture, target = map(Path, sys.argv[1:])
    assert not target.exists()
    native = json.loads(reference.with_name('aligned-reference-receipt.json').read_text())
    assert native['exe_sha256'] == '2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
    assert native['fixture_sha256'] == sha(fixture) and native['capture_sha256'] == sha(reference)
    image = np.array(Image.open(reference).convert('RGB'), dtype=np.int32)
    assert image.shape == (631, 802, 3)
    r, g, b = image[:, :, 0], image[:, :, 1], image[:, :, 2]
    # Observed original viewport, excluding toolbars/Explorer. Keep tint-colored
    # geometry rather than the sky; largest component rejects incidental UI.
    mask = (g > 10) & (g > 1.3*r) & (g > 1.3*b)
    mask[:155] = False
    mask[604:] = False
    mask[:, 547:] = False
    _, labels, stats, _ = cv2.connectedComponentsWithStats(mask.astype('uint8'))
    mask = labels == 1 + np.argmax(stats[1:, cv2.CC_STAT_AREA])
    image = np.array(Image.open(player).convert('RGB'))
    rebuilt = np.any(image != [255, 0, 255], axis=2)
    a, original_bounds = normalize(mask)
    b, player_bounds = normalize(rebuilt)
    iou = float(np.logical_and(a, b).sum()) / np.logical_or(a, b).sum()
    box_control = float(a.mean())
    # Fixed before camera alignment: 2% allows raster/JPEG edge uncertainty at
    # the player's117-pixel diameter. The earlier tilted reference failed it.
    passed = iou >= .98 and box_control < .9
    result = {'pass': passed, 'normalized_iou': iou, 'minimum_iou': .98,
              'manual_box_control_iou': box_control, 'box_control_maximum': .9,
              'original_bounds': original_bounds, 'player_bounds': player_bounds,
              'original_pixels': int(mask.sum()), 'player_pixels': int(rebuilt.sum()),
              'reference': str(reference.resolve()), 'reference_sha256': sha(reference),
              'player': str(player.resolve()), 'player_sha256': sha(player),
              'fixture_sha256': sha(fixture), 'original_receipt_sha256': sha(reference.with_name('aligned-reference-receipt.json')),
              'verifier_sha256': sha(Path(__file__)),
              'scope': 'Shape silhouette under identity camera at(0,0,10); crop/scale normalization compensates viewport/FOV. No RGB/lighting/UI parity claim.',
              'limits': ['Original capture is helper JPEG; rebuilt capture is actual D3D9 backbuffer PNG.',
                         'Full native renderer context and June asset-distribution identity remain separately tracked.']}
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'pass': passed, 'iou': iou, 'box_control_iou': box_control}))
    assert passed


if __name__ == '__main__':
    main()

"""Capture real player frames, verify six sky directions and encode a VP8 spin."""
import hashlib
import argparse
import ctypes
from ctypes import wintypes
from datetime import datetime
import json
import os
from pathlib import Path
import shutil
import subprocess
import time

import cv2
import numpy as np
from PIL import Image
import psutil

root = Path(__file__).resolve().parents[3]
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--output',type=Path,default=root/'work/2008-06'/datetime.now().strftime('sky-demo-%Y%m%d-%H%M%S-%f'))
output=parser.parse_args().output.resolve()
output.mkdir(exist_ok=False)
binary = root / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
content = binary.parent / 'Content'
env = os.environ.copy()
for key in ('ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'):
    env.pop(key, None)


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
           'cleared_environment': ['ROC_BUILD', 'ROC_TEXTURE_STRIP', 'ROC_SKY_SPHERE', 'ROC_TRACE_STAGES'],
           'runs': {}, 'loaded_dlls': {}, 'assets': json.loads((content / 'demo-assets.json').read_text())}


def run(name, args, expected=0):
    folder = output / name
    folder.mkdir()
    with (folder / 'stdout.txt').open('w') as stream:
        process = subprocess.Popen([str(binary), *args], cwd=folder, env=env, stdout=stream, stderr=subprocess.STDOUT)
        observed = psutil.Process(process.pid)
        deadline = time.monotonic() + 60
        while process.poll() is None:
            assert time.monotonic() < deadline, f'Inspect live process {process.pid} before retrying'
            try:
                for memory in observed.memory_maps():
                    path = Path(memory.path)
                    if path.name.lower() in ('rgmain.dll', 'rgdx.dll'):
                        receipt['loaded_dlls'][str(path)] = sha(path)
            except psutil.NoSuchProcess:
                pass
            time.sleep(.01)
    assert process.returncode == expected, (name, process.returncode)
    text = (folder / 'stdout.txt').read_text()
    receipt['runs'][name] = {'args': args, 'cwd': str(folder), 'exit': process.returncode, 'stdout_sha256': sha(folder / 'stdout.txt')}
    return folder, text


frames, text = run('frames', ['--capture-spin', '180'])
assert 'spin captured: frames=180 size=800x600' in text
assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in text
assert 'size=(4,1.2,2)' in text and 'faces=6 distance=2700' in text
paths = sorted(frames.glob('spin_*.png'))
assert len(paths) == 180
hashes = {p.name: sha(p) for p in paths}
assert len(set(hashes.values())) > 90, 'Expected actual rotation'
first = cv2.imread(str(paths[0]))
quarter = cv2.imread(str(paths[45]))
def red(image):
    b, g, r = [image[:, :, i].astype(np.int32) for i in range(3)]
    return (r > 60) & (r > 2*g) & (r > 2*b)
assert int(red(first).sum()) > 5000
assert int(np.count_nonzero(red(first) ^ red(quarter))) > 500
assert not np.any(np.all(first == (255, 0, 255), axis=2)), 'Skybox hole exposes clear color'
image = output / 'red-studded-skybox.png'
shutil.copyfile(paths[0], image)
video = output / 'red-studded-skybox.webm'
writer = cv2.VideoWriter(str(video), cv2.VideoWriter_fourcc(*'VP80'), 30, (800, 600))
assert writer.isOpened()
for path in paths:
    writer.write(cv2.imread(str(path)))
writer.release()
reader = cv2.VideoCapture(str(video))
assert reader.isOpened() and int(reader.get(cv2.CAP_PROP_FRAME_COUNT)) == 180
decoded=0
while reader.read()[0]:decoded+=1
assert decoded==180
reader.release()
receipt['capture'] = {'frame_count': 180, 'fps': 30, 'seconds': 6, 'size': [800, 600],
                      'codec': 'VP8/WebM', 'frame_sha256': hashes, 'video_sha256': sha(video),
                      'picture_sha256': sha(image), 'first_red_pixels': int(red(first).sum()),
                      'quarter_turn_mask_difference': int(np.count_nonzero(red(first) ^ red(quarter))),
                      'fully_decoded_frame_count': decoded, 'encoding_tool_version': cv2.__version__}

views, _ = run('sky-directions', ['--capture-sky'])
expected = {'front': ('bk', 0), 'back': ('ft', 0), 'left': ('lf', 0), 'right': ('rt', 0), 'up': ('up', 1), 'down': ('dn', 3)}
scores = {}
for name, (face, turns) in expected.items():
    actual = np.asarray(Image.open(views / f'sky_{name}.png').convert('RGB').crop((100, 0, 700, 600)), dtype=float)
    original = np.asarray(Image.open(content / f'sky/null_plainsky512_{face}.jpg').convert('RGB').resize((600, 600)), dtype=float)
    mse = float(np.mean((actual - np.rot90(original, turns))**2))
    assert mse < 12, (name, mse)
    scores[name] = {'source': face, 'image_CCW_quarter_turns': turns, 'GPU_RGB_mean_squared_error': mse}
receipt['sky_views'] = scores

bad = output / 'missing-sky-content'
(bad / 'sky').mkdir(parents=True)
(bad / 'textures').mkdir()
for source in content.glob('sky/*.jpg'):
    if not source.name.endswith('_dn.jpg'):
        shutil.copyfile(source, bad / 'sky' / source.name)
shutil.copyfile(content / 'textures/SurfacesStrip.png', bad / 'textures/SurfacesStrip.png')
_, text = run('missing-sky', ['--capture-spin', '1', '--content-root', str(bad)], 8)
assert 'missing sky face: null_plainsky512_dn.jpg' in text
_, text = run('missing-place', ['--frames', '1', str(output / 'does-not-exist.rbxl')], 1)
assert 'could not read place:' in text

# Exercise the actual no-argument default launch and normal WM_CLOSE handling.
folder=output/'default-launch';folder.mkdir()
user32=ctypes.WinDLL('user32',use_last_error=True)
callback_type=ctypes.WINFUNCTYPE(wintypes.BOOL,wintypes.HWND,wintypes.LPARAM)
user32.EnumWindows.argtypes=[callback_type,wintypes.LPARAM]
user32.GetWindowThreadProcessId.argtypes=[wintypes.HWND,ctypes.POINTER(wintypes.DWORD)]
user32.IsWindowVisible.argtypes=[wintypes.HWND]
user32.PostMessageW.argtypes=[wintypes.HWND,wintypes.UINT,wintypes.WPARAM,wintypes.LPARAM]
with (folder/'stdout.txt').open('w') as stream:
    process=subprocess.Popen([str(binary)],cwd=folder,env=env,stdout=stream,stderr=subprocess.STDOUT)
    windows=[]
    @callback_type
    def owned_window(window,parameter):
        owner=wintypes.DWORD();user32.GetWindowThreadProcessId(window,ctypes.byref(owner))
        if owner.value==process.pid and user32.IsWindowVisible(window):windows.append(window)
        return True
    deadline=time.monotonic()+20
    while process.poll() is None and time.monotonic()<deadline:
        windows.clear();user32.EnumWindows(owned_window,0)
        log=folder/'player.log'
        if windows and log.exists() and 'RbxGfx: created light' in log.read_text():break
        time.sleep(.02)
    assert windows and process.poll() is None, f'Inspect default launch process {process.pid}'
    assert user32.PostMessageW(windows[0],0x10,0,0)
    assert process.wait(timeout=10)==0
text=(folder/'stdout.txt').read_text()
assert 'size=(4,1.2,2)' in text and 'faces=6 distance=2700' in text
assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in text
receipt['runs']['default-launch']={'args':[],'cwd':str(folder),'exit':0,'closed_own_window_with_WM_CLOSE':True,'stdout_sha256':sha(folder/'stdout.txt')}
receipt['source_sha256'] = {f'rebuild/2008-06/{name}': sha(root / 'rebuild/2008-06' / name) for name in (
    'tests/PlayerSkybox.cpp', 'tests/PlayerSkybox.h', 'tests/p2-recovered/Player2008.cpp',
    'tests/p2-recovered/PlayerEngine.cpp', 'modules/p2-recovered-player.json', 'tests/stage_demo_content.py','tests/capture_sky_demo.py')}
receipt['limits'] = ['Uses identified period external assets; exact June distribution identity unproven.',
                     'Default local sky path; custom Sky ContentIds/online service integration remain later roadmap work.',
                     'Capture is actual D3D9 backbuffer; video encoding is separate tooling.']
(output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: 6-second actual spin, red block, six sky directions, missing-asset/place errors')
print(image)
print(video)

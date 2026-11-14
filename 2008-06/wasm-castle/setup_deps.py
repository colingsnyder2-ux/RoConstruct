"""Fetch the pinned, hash-verified PNG/JPEG codec headers for the Wasm port."""
from pathlib import Path
from urllib.request import urlopen
import hashlib

ROOT = Path(__file__).resolve().parents[3]
target = ROOT / 'work/wasm-castle/deps/stb'
target.mkdir(parents=True, exist_ok=True)
for name, digest in {
    'stb_image.h': 'deb4f18c9ca21b751a1323019031c94c0bf5ca1d2929ef5913cc56f00aab6e91',
    'stb_image_write.h': 'a8e7f77f0ccfdc9bac09a71268b131931ff81aafca82c393aeb6aaba10d9e7ca'
}.items():
    path = target / name
    if path.exists() and hashlib.sha256(path.read_bytes()).hexdigest() == digest:
        continue
    data = urlopen(f'https://raw.githubusercontent.com/nothings/stb/9600522de53973336fa033a289858a4354cbb04c/{name}').read()
    if hashlib.sha256(data).hexdigest() != digest:
        raise SystemExit('Dependency hash mismatch: ' + name)
    path.write_bytes(data)
    print('Fetched ' + name)

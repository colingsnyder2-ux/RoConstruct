"""Compare one authored looping sound in the original and rebuilt clients.

Capture is limited to aggregate one-second FFT/RMS values; no audio is saved.
The default speaker must be otherwise quiet. Original-client files and the
optional SoundCard dependency are local prerequisites, not distributed.
"""
import ctypes
import hashlib
import importlib.metadata
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'work/2008-06/audio-tools'))
import numpy as np
import soundcard as sc


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def measure(audio):
    mono = audio.mean(axis=1)
    time = np.arange(len(mono)) / 48000
    return {'rms': float(np.sqrt(np.mean(mono * mono))),
            'hz440': float(2 * abs(np.sum(mono * np.exp(-2j * np.pi * 440 * time))) / len(mono))}


def close_owned(process):
    if process.poll() is not None:
        return {'exit': process.returncode, 'forced': False}
    user32 = ctypes.windll.user32
    @ctypes.WINFUNCTYPE(ctypes.c_bool, ctypes.c_void_p, ctypes.c_void_p)
    def close(hwnd, _):
        pid = ctypes.c_ulong()
        user32.GetWindowThreadProcessId(hwnd, ctypes.byref(pid))
        if pid.value == process.pid:
            user32.PostMessageW(hwnd, 0x10, 0, 0)
        return True
    user32.EnumWindows(close, 0)
    try:
        process.wait(timeout=4)
        return {'exit': process.returncode, 'forced': False}
    except subprocess.TimeoutExpired:
        process.terminate()
        process.wait(timeout=5)
        return {'exit': process.returncode, 'forced': True}


def main():
    output = ROOT / 'work/2008-06' / sys.argv[1]
    output.mkdir(exist_ok=False)
    fixture = ROOT / 'rebuild/2008-06/tests/fixtures/sound-autoplay.rbxl'
    original = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
    player = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    tone = ROOT / 'rebuild/2008-06/tests/fixtures/p4-assets/tone.wav'
    for path in (original.parent / 'content/p4/tone.wav', player.parent / 'Content/p4/tone.wav'):
        assert sha(path) == sha(tone), 'fixture differs in client content'
    speaker = sc.default_speaker()
    mic = sc.get_microphone(id=speaker.name, include_loopback=True)
    receipt = {'revision': subprocess.check_output(['git','rev-parse','HEAD'], cwd=ROOT, text=True).strip(),
               'fixture_sha256': sha(fixture), 'tone_sha256': sha(tone),
               'original_sha256': sha(original), 'player_sha256': sha(player),
               'observer_sha256': sha(Path(__file__)), 'sample_rate': 48000,
               'speaker_id_sha256': hashlib.sha256(speaker.name.encode()).hexdigest(),
               'soundcard_version': importlib.metadata.version('soundcard'),
               'runs': {}, 'P4_complete': False,
               'scope': 'One looping 2D authored 440 Hz tone; no raw audio retained.',
               'limitations': ['No human listening claim.', 'No spatial, missing-asset, scripted, or network audio comparison.']}
    for name, exe in [('original', original), ('player', player)]:
        with mic.recorder(samplerate=48000, channels=2) as rec:
            baseline = measure(rec.record(numframes=48000))
            assert baseline['hz440'] < 0.001, 'default output already contains a 440 Hz signal'
            process = subprocess.Popen([str(exe), str(fixture)], cwd=exe.parent,
                                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            try:
                data = rec.record(numframes=384000)
                windows = [measure(data[i:i+48000]) for i in range(0, len(data), 48000)]
                active = [v for v in windows if v['hz440'] > max(.002, baseline['hz440'] * 4)]
                assert len(active) >= 3, '%s failed to sustain tone: %s' % (name, windows)
                assert process.poll() is None, '%s exited before capture completed' % name
            finally:
                cleanup = close_owned(process)
            receipt['runs'][name] = {'baseline': baseline, 'windows': windows, 'active_windows': len(active),
                                     'median_hz440': float(np.median([v['hz440'] for v in active[-3:]])),
                                     'median_rms': float(np.median([v['rms'] for v in active[-3:]])),
                                     'cleanup': cleanup}
    a, b = (receipt['runs'][key] for key in ('original','player'))
    receipt['amplitude_ratio'] = b['median_hz440'] / a['median_hz440']
    receipt['rms_ratio'] = b['median_rms'] / a['median_rms']
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    assert .95 <= receipt['amplitude_ratio'] <= 1.05, receipt
    assert .95 <= receipt['rms_ratio'] <= 1.05, receipt
    print('P4 original/player 2D tone PASS amplitude=%.5f rms=%.5f' % (receipt['amplitude_ratio'], receipt['rms_ratio']))


if __name__ == '__main__':
    main()

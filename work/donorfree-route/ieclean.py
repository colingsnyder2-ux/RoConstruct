"""ieclean.clean(): test-harness IE cleanup for donor-free runs, delegating to work/ie_cleanup.py (iexplore.exe, the
ielowutil.exe IE COM broker, and the Edge windows Windows 11 opens for the client's IE pages). Call it once BEFORE the
launch (records the user's own Edge windows, never touched) and once after."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parents[1]))
import ie_cleanup


def clean(since=0.0):
    return ie_cleanup.close_all_ie(verbose=False)


if __name__ == '__main__':
    clean(); print('ieclean done')

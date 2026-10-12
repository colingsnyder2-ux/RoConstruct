"""Probe real client Network translation units for RakNet/ProfiledRakPeer bodies."""
from pathlib import Path
from benchmarks.claude_continuation import run_sources
from benchmarks.match_campaign import Campaign
from roc import libs

ROOT = Path('work/raknet-2008')


def sources():
    for recipe in ('openrbx-client', 'openrbx-client-dll'):
        spec = libs.RECIPES[recipe]
        folder = libs.fetch(recipe)
        for file in libs.files_of(spec, folder):
            if 'network' not in file.lower():
                continue
            for flags in spec.get('grid', libs.GRID):
                yield libs.source_for(recipe, file, 'cpp', 21022, flags), dict(recipe=recipe, file=file)


if __name__ == '__main__':
    c = Campaign(ROOT, 'http://127.0.0.1:8765')
    try:
        run_sources(c, 'client-network', sources(), 3)
    finally:
        c.api.close()

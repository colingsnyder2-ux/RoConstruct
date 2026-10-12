"""Binary-observed ProfiledRakPeer name experiment; no invented fields."""
import argparse
from pathlib import Path

from benchmarks.claude_continuation import run_sources
from benchmarks.match_campaign import Campaign
from roc import libs

ROOT = Path('work/raknet-2008')
CLIENT = '2008-06'
RECIPE = 'rbxgs-raknet'


def sources():
    folder = libs.fetch(RECIPE)
    for file in ('RakPeer.cpp', 'ReplicaManager.cpp', 'ConsoleServer.cpp'):
        original = folder / file
        wrapper = folder / ('roc_profiled_' + file)
        source = '#define RakPeer ProfiledRakPeer\n#include "' + file + '"\n'
        if wrapper.exists() and wrapper.read_text() != source:
            raise RuntimeError('wrapper conflict')
        wrapper.write_text(source)
        for flags in ('/O2 /GS- /EHsc /MD', '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD', '/O1 /GS- /EHsc /MD'):
            yield libs.source_for(RECIPE, str(wrapper.relative_to(folder)), 'cpp', 21022, flags), \
                dict(file=file, evidence='binary ProfiledRakPeer symbol; token-only alias')


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--server', default='http://127.0.0.1:8765')
    args = parser.parse_args()
    campaign = Campaign(ROOT, args.server)
    try:
        run_sources(campaign, 'profiled-alias', sources(), 2)
    finally:
        campaign.api.close()

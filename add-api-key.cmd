@echo off
setlocal
cd /d "%~dp0"
title RoConstruct API keys
call roc.cmd provider secrets --open
echo.
echo Paste provider keys in the opened JSON file, then save it.
echo Example: {"DEEPSEEK_API_KEY":"...","NVIDIA_API_KEY":"..."}
echo Keys stay in your user AppData folder, outside the repository.
pause

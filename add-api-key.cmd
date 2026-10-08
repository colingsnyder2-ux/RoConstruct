@echo off
setlocal
cd /d "%~dp0"
title RoConstruct API keys
call roc.cmd provider setup
pause

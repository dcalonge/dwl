#!/bin/sh

~/scripts/setup_displays.sh

wl-paste --watch cliphist store &
mako &
swaybg -i ~/Pictures/wallpaper &
swayidle -w before-sleep gtklock &
udiskie &
/usr/libexec/polkit-gnome-authentication-agent-1 &
kill -49 $(pidof dwmblocks) &
kill -44 $(pidof dwmblocks) &

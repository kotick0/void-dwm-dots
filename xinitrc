killall pipewire pipewire-media-session pipewire-pulse picom feh

xrdb ~/.Xresources
feh --bg-fill ~/Images/1.8x.png &
picom &
pipewire &
pipewire-pulse &
exec dwm

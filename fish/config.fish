function fish_prompt
    string join '' -- (set_color df8bb9) '⸍'(prompt_pwd)'⸌' (set_color E2C2FF) ' ⥂ '
end

#Start up scripts
function fish_greeting
     pokemon-colorscripts -r 1-2 --no-title
end

function sudo
     command sudo $argv ;pokemon-colorscripts -n sudowoodo --no-title
end

#ALIASES SECTION
#---------------
#Dwm-suckless aliases:
alias dwm-conf='cd ~/suckless/dwm && nvim config.h && cd -' # --description 'Change DWM config'
alias dwm-backup='cp ~/suckless/dwm/config.h ~/suckless/dwm/config.def.h && cp ~/suckless/dwm/config.def.h ~/suckless/dwm/backup' # --description 'Backup DWM'
alias dwm-upd='cd ~/suckless/dwm && sudo make clean install && cd -' # --description 'Update DWM'

#System maintenance aliases:
alias orphans='sudo xbps-remove -Oo'
alias reconf='sudo xbps-reconfigure -fa'
alias update='sudo xbps-install -Syu'
alias shutdown='sudo shutdown -h now'

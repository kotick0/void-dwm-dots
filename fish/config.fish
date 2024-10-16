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
alias dwm-config='cd ~/suckless/dwm && sudo nvim config.h && cd -'
alias dwm-backup='cp ~/suckless/dwm/config.h ~/suckless/dwm/config.def.h && cp ~/suckless/dwm/config.def.h ~/suckless/dwm/backup'
alias dwm-update='cd ~/suckless/dwm && sudo make clean install && cd -'

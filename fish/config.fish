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

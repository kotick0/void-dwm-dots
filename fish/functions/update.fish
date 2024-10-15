function update --wraps='sudo xbps-install -Syu' --description 'alias update=sudo xbps-install -Syu'
  sudo xbps-install -Syu $argv
        
end

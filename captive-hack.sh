interface="$(route get default | awk '/interface/ {print $2}')"
localip="$(ipconfig getifaddr en0)"
macaddress="$(ifconfig en0 ether | awk '/ether/ {print $2}')"
netmask="$(ipcalc $localip | awk '/Netmask/ {print $4}')"

function check_sudo() {
  if [[ "$EUID" -ne 0 ]]; then
    printf "%b\n" "ERROR This script must be run as root. Use sudo." >&2
    exit 1
  fi
}

function clean_up() {
  rm -rf "$tmp"
  trap 0
  exit
}


function main() {

}

trap clean_up 0 1 2 3 15
check_sudo
main

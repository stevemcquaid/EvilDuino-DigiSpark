# Requirements
* Adafruit pro trinket 5V
* platformio installed

## add to  `platformio.ini`
[platformio]
home_dir = .pio

# Setup avr-gcc+ on Mac OS X
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew tap osx-cross/avr
brew install avr-libc
brew install avrdude --with-usb


# Setup avr-gcc+ on Debian/Ubuntu Linux:
sudo apt-get install gcc-avr binutils-avr gdb-avr avr-libc avrdude
sudo apt-get install gcc-avr binutils avr-libc avrdude

# Install platformio
pio lib search trinket
pio lib install 759

# Usage
pio run -t upload

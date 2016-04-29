# This script automatically downloads and 
# uploads the newest arduino code automatically.

cd /home/storm/arduino

# Removes the old arduino project
rm -rf sketch

# Creates and initializes the new arduino project
mkdir sketch
cd sketch
ino init

# Downloads the latest arduino sketch from github
cd src
curl https://raw.githubusercontent.com/MartinVanBuren/Storm/master/arduino/arduino.ino -o sketch.ino

# Builds the code and uploads it to the arduino
cd ..
ino build
ino upload
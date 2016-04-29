# Setup the flask web server for web control and setup web control autostart on boot
pip install flask
mv web/storm-web-control-startup /etc/init.d/storm-web-control-startup
chmod 755 /etc/init.d/storm-web-control-startup
update-rc.d /etc/init.d/storm-web-control-startup defaults
mkdir /home/storm
mv web /home/storm/

# Modify the MusicBox web control to display as Storm Music
mv web/functionsvars.js /etc/local/lib/python2.7/dist-packages/mopidy_musicbox_webclient/static/js/functionsvars.js

# Remove unneeded files
rm audio/readme

# Move audio files to proper location
mkdir /music/MusicBox/storm
mv audio/* /music/MusicBox/storm/

# Setup software for updating arduino code remotely
apt-get install -y arduino
apt-get install make
apt-get install picocom
pip install ino

# Setting up arduino project directory
mv arduino /home/storm/
mkdir /home/storm/arduino/sketch
cd /home/storm/arduino/sketch
ino init
mv -f /home/storm/arduino/arduino.ino src/sketch.ino

# Finish
reboot
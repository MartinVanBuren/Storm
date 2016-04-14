rm -r storm-audio-analysis
pip install flask
mv web/storm-web-control-startup /etc/init.d/storm-web-control-startup
chmod 755 /etc/init.d/storm-web-control-startup
update-rc.d /etc/init.d/storm-web-control-startup defaults
mv web/functionsvars.js /etc/local/lib/python2.7/dist-packages/mopidy_musicbox_webclient/static/js/functionsvars.js
mkdir /home/storm
mv web /home/storm/

rm audio/readme
mkdir /music/MusicBox/storm
mv audio/* /music/MusicBox/storm/

reboot

ssh 192.168.2.1 'while true; do ifconfig eth1 |grep bytes | cut -f1 -d "(" |tr ":" "\n"|tr " " "\n" |grep [0-9]; sleep 0.5 ; done' > speed.log &

before="0"


exec 3<> /dev/ttyACM0
sleep 1

while true
do

last=`tail -n 1 speed.log`

  speed=`echo "(($last - $before) / 98304)" |bc`
  echo $speed >&3
  before=$last
  sleep 1
done

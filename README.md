# INF280
Entrainement au concour ACM-ICPC

Ligne de commande utilisé par le juges en ligne ACM-ICPC pour compiler:
* g++ -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE file.cpp

Ce que j'utilise:
* g++ -std=c++11 file.cpp && ./a.out < input.txt
* g++ -g -std=c++11 file.cpp && gdb ./a.out

Pour uDebug:
* python3.4 ./genInput.balloon.py && g++ -std=c++11 2474-balloons_in_a_box.cpp && ./a.out < balloons.input > out.txt && gedit balloons.input balloon.output

## Problèmes du contrôle continue

- [X] 7211 Identifying tea
- [X] 4954 Lawn mower
- [X] 4493 That is Your Queue
- [X] 2433 No Change

- [X] 3983 Robotruck
- [ ] 2474 Balloons in a Box
- [ ] 5540 Copying Books

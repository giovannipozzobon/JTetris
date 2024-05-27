
#compile
#/Users/giovanni.pozzobon/Documents/GitHub/llvm-mos-sdk/bin/mos-neo6502-clang -Os -v -fverbose-asm -mcpu=mosw65c02 -D__NEO6502__ -mlto-zp=224 \
#-I /Users/giovanni.pozzobon/Documents/GitHub/llvm-mos-sdk/mos-platform/neo6502/asminc \
#-L /Users/giovanni.pozzobon/Documents/GitHub/llvm-mos-sdk/mos-platform/neo6502/lib \
#-isystem Users/giovanni.pozzobon/Documents/GitHub/llvm-mos-sdk/mos-platform/neo6502/include \
#main.c utility.c api.c quicksort.c sprite.c -o main.neo 
#-v -fverbose-asm


# cleanup
rm -f *.o jtetris.neo jtetris.map {,.temp}

#compile
/Users/giovanni.pozzobon/Documents/GitHub/llvm-mos-sdk/bin/mos-neo6502-clang++ -Os  main.cpp file.cpp graphic.cpp console.cpp util.cpp screen.cpp shape.cpp grid.cpp score.cpp log.cpp -o jtetris.neo

#create exec mappeer and copy in storage 
test -f jtetris.neo && python3 exec.zip jtetris.neo@800 run@800 -o./storage/jtetris.neo

# launch emulator
test -f jtetris.neo && ./neo jtetris.neo@800 cold
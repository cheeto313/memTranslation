CXX = g++
PROGRAM = memTrans
OBJS = TlB.cpp Frame.cpp PageTable.cpp
all: ${PROGRAM}

clean:
	rm -f *.o *.stackdump ${PROGRAM_SEQ} ${PROGRAM_GEN} ${PROGRAM_THREAD}	
	
${PROGRAM}: ${PROGRAM}.o ${OBJS}
	${CXX} -o ${PROGRAM} ${PROGRAM}.o ${OBJS}
	
test:
	./${PROGRAM} data/InputFile.txt > result
	diff -q data/correct.txt result
	
	
test20:
	./${PROGRAM} data/testing/InputFile_20.txt > result
	diff -q data/testing/correct20.txt result
	
test256:
	./${PROGRAM} data/testing/InputFile_256.txt > result
	diff -q data/testing/correct20.txt result

test257:
	./${PROGRAM} data/testing/InputFile_257.txt > result
	diff -q data/testing/correct20.txt result


obj = private.o call.o

main:$(obj)
	gcc -o $@ $(obj)
%.o:%.c
	gcc -c $<

.PHONY:clean
clean:
	rm -f *.o *.exe
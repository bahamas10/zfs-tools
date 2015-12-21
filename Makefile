CFLAGS = -Wall

LIBS = -lzfs \
       -lnvpair

zpool-config: zpool-config.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f zpool-config

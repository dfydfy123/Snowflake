Snowflake: check

	@echo && echo "Some more advanced C++ interop:"
	"$(FLASCC)/usr/bin/g++" $(BASE_CFLAGS) -jvmopt=-Xmx1G src/main.cpp src/game.cpp src/snow.cpp -lAS3++ -lFlash++ -O4 -flto-api=exports.txt -swf-size=550x400 -emit-swf -o bin/Snowflake.swf

include ../Makefile.common

clean:
	rm -f bin/*.swf bin/*.bc bin/*.exe
